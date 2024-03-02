import threading
import time

class SharedBuffer:
    def __init__(self, size):
        self.buffer = []  # The list acting as the shared buffer.
        self.mutex = threading.Lock()  # Lock for mutual exclusion during buffer access.
        self.notEmpty = threading.Semaphore(0)  # Semaphore to signal buffer is not empty.
        self.notFull = threading.Semaphore(size)  # Semaphore to signal buffer is not full, initialized to buffer size.
        self.doneProducing = False  # Flag to indicate when producers have finished producing.

    def add_message(self, message):
        self.notFull.acquire()  # Wait if buffer is full, ensuring no overflow.
        with self.mutex:  # Access buffer exclusively to prevent data corruption.
            self.buffer.append(message)  # Add message to the buffer.
        self.notEmpty.release()  # Signal that buffer now has content, allowing consumers to proceed.

    def read_message(self):
        self.notEmpty.acquire()  # Wait if buffer is empty, ensuring no underflow.
        with self.mutex:  # Access buffer exclusively to ensure data consistency.
            if self.doneProducing and len(self.buffer) == 0:
                self.notFull.release()  # Release to avoid deadlock if a producer is waiting.
                return None  # Indicate no more messages will be produced.
            message = self.buffer.pop(0)  # Retrieve and remove the first message in the buffer.
        self.notFull.release()  # Signal space available in buffer, allowing producers to add more messages.
        return message

    def mark_done_producing(self):
        with self.mutex:  # Exclusive access to update production status.
            self.doneProducing = True
            for _ in range(10):  # Release for each consumer to ensure they all can exit.
                self.notEmpty.release()

def producer(thread_id, buffer):
    for message_number in range(5):  # Produce 5 messages per producer.
        message = f"Producer {thread_id} has produced message number {message_number}."
        buffer.add_message(message)
        print(f"[Producer {thread_id}] Produced message: {message_number}")
        time.sleep(2)  # Simulate time taken to produce a message.

    if thread_id == 3:  # If this is the last producer, indicate end of production.
        print(f"[Producer {thread_id}] Finished producing. Notifying consumers.")
        buffer.mark_done_producing()

def consumer(thread_id, buffer):
    while True:
        message = buffer.read_message()
        if message is None:  # Check for signal indicating no more messages will be produced.
            print(f"[Consumer {thread_id}] No more messages to consume. Exiting.")
            break
        print(f"[Consumer {thread_id}] Consumed message: {message}")
        time.sleep(1)  # Simulate time taken to process a message.

def main():
    bufferSize = 10  # Define the size of the buffer.
    numberOfProducers = 4  # Set the number of producers.
    numberOfConsumers = 10  # Set the number of consumers.
    buffer = SharedBuffer(bufferSize)  # Initialize the shared buffer.

    # Initialize and start producer threads.
    producers = [threading.Thread(target=producer, args=(i, buffer,)) for i in range(numberOfProducers)]
    # Initialize and start consumer threads.
    consumers = [threading.Thread(target=consumer, args=(i, buffer,)) for i in range(numberOfConsumers)]

    # Starting producer threads.
    for p in producers:
        p.start()
        print(f"Started Producer Thread: {p.name}")
    
    # Starting consumer threads.
    for c in consumers:
        c.start()
        print(f"Started Consumer Thread: {c.name}")

    # Wait for all producer threads to complete.
    for p in producers:
        p.join()
        print(f"Producer Thread {p.name} has completed.")

    # Wait for all consumer threads to complete.
    for c in consumers:
        c.join()
        print(f"Consumer Thread {c.name} has completed.")

    print("All producers and consumers have successfully completed their tasks.")

if __name__ == '__main__':
    main()