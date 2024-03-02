Each producer, identified by a unique thread ID, generates a series of messages (labeled 0 through 4) and adds them to a 
shared buffer. Correspondingly, consumer threads, each also identified by unique thread IDs, retrieve and process these messages from the buffer. Upon the completion of message production by all producer threads, the system correctly signals the consumer threads that no more messages will be produced. This is evident from the logs indicating that the last producer thread notifies consumers and subsequently, consumer threads exit the processing loop upon realizing there are no more messages to consume.

[Producer 0] Produced message: 0
Started Producer Thread: Thread-1
[Producer 1] Produced message: 0
Started Producer Thread: Thread-2
[Producer 2] Produced message: 0
Started Producer Thread: Thread-3
[Producer 3] Produced message: 0
Started Producer Thread: Thread-4
[Consumer 0] Consumed message: Producer 0 has produced message number 0.
Started Consumer Thread: Thread-5
[Consumer 1] Consumed message: Producer 1 has produced message number 0.
Started Consumer Thread: Thread-6
[Consumer 2] Consumed message: Producer 2 has produced message number 0.
Started Consumer Thread: Thread-7
[Consumer 3] Consumed message: Producer 3 has produced message number 0.
Started Consumer Thread: Thread-8
Started Consumer Thread: Thread-9
Started Consumer Thread: Thread-10
Started Consumer Thread: Thread-11
Started Consumer Thread: Thread-12
Started Consumer Thread: Thread-13
Started Consumer Thread: Thread-14
[Producer 0] Produced message: 1
[Consumer 4] Consumed message: Producer 0 has produced message number 1.
[Producer 1] Produced message: 1
[Consumer 5] Consumed message: Producer 1 has produced message number 1.
[Producer 3] Produced message: 1
[Producer 2] Produced message: 1
[Consumer 6] Consumed message: Producer 3 has produced message number 1.
[Consumer 7] Consumed message: Producer 2 has produced message number 1.
[Producer 0] Produced message: 2
[Consumer 8] Consumed message: Producer 0 has produced message number 2.
[Producer 1] Produced message: 2
[Consumer 9] Consumed message: Producer 1 has produced message number 2.
[Producer 2] Produced message: 2
[Consumer 0] Consumed message: Producer 2 has produced message number 2.
[Producer 3] Produced message: 2
[Consumer 2] Consumed message: Producer 3 has produced message number 2.
[Producer 0] Produced message: 3
[Consumer 1] Consumed message: Producer 0 has produced message number 3.
[Producer 1] Produced message: 3
[Consumer 3] Consumed message: Producer 1 has produced message number 3.
[Producer 3] Produced message: 3
[Consumer 4] Consumed message: Producer 3 has produced message number 3.
[Producer 2] Produced message: 3
[Consumer 5] Consumed message: Producer 2 has produced message number 3.
[Producer 0] Produced message: 4
[Consumer 7] Consumed message: Producer 0 has produced message number 4.
[Producer 1] Produced message: 4
[Consumer 6] Consumed message: Producer 1 has produced message number 4.
[Producer 3] Produced message: 4
[Consumer 8] Consumed message: Producer 3 has produced message number 4.
[Producer 2] Produced message: 4
[Consumer 9] Consumed message: Producer 2 has produced message number 4.
Producer Thread Thread-1 has completed.
Producer Thread Thread-2 has completed.
[Producer 3] Finished producing. Notifying consumers.
[Consumer 0] No more messages to consume. Exiting.
[Consumer 3] No more messages to consume. Exiting.
[Consumer 2] No more messages to consume. Exiting.
[Consumer 5] No more messages to consume. Exiting.
[Consumer 1] No more messages to consume. Exiting.
[Consumer 7] No more messages to consume. Exiting.
[Consumer 6] No more messages to consume. Exiting.
[Consumer 4] No more messages to consume. Exiting.
[Consumer 8] No more messages to consume. Exiting.
[Consumer 9] No more messages to consume. Exiting.
Producer Thread Thread-3 has completed.
Producer Thread Thread-4 has completed.
Consumer Thread Thread-5 has completed.
Consumer Thread Thread-6 has completed.
Consumer Thread Thread-7 has completed.
Consumer Thread Thread-8 has completed.
Consumer Thread Thread-9 has completed.
Consumer Thread Thread-10 has completed.
Consumer Thread Thread-11 has completed.
Consumer Thread Thread-12 has completed.
Consumer Thread Thread-13 has completed.
Consumer Thread Thread-14 has completed.
All producers and consumers have successfully completed their tasks.







BONUS QUESTION: 
Handling priority based consumption in this producer-consumer problem can be done. All it takes is making a multi-level feedback queue being the data structure that holds consumers by priority dynamically. The only thing this changes is what consumer consumes data units from the buffer first. The reason for a multi-level feedback queue instead of a regular multi-level queue is because there often is more consumers than the buffer size, so some consumers with lower priority will be starved. 