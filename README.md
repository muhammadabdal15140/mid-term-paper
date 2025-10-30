# HospitalQU — Doubly-Linked Queue Example (C++)

A small C++ console program demonstrating a doubly-linked list implementation used as a double-ended queue (deque) to manage patient IDs in a hospital queue. This educational example shows insertion at front, insertion at end, insertion at a specific position, removal from front, and traversals in both directions.

## Features
- addEnd(patientId): Add a patient ID to the rear of the queue.
- addFront(patientId): Add a patient ID to the front of the queue.
- addPosition(patientId, position): Insert a patient ID at a 1-based position (positions <= 1 insert at front; if position is past the end it appends to rear).
- removeFront(): Remove the front patient.
- showForward(): Display queue from front to rear.
- showBackward(): Display queue from rear to front.
- frontID() / rearID(): Return the front/rear patient ID or -1 if empty.

## Files
- main.cpp — contains the implementation of the HospitalQU class and a simple demo in main().

## Build

Using g++:

g++ -std=c++17 -Wall -Wextra -O2 -o hospital_queue main.cpp

(Adjust filename if your source file name differs.)

## Run

Execute the compiled program:

./hospital_queue

The provided `main()` runs a short demonstration:

- enqueues 101 at end
- shows forward
- adds 200 at front
- adds 102 at end
- removes front
- inserts 150 at position 2
- adds 300 at end
- prints front and rear IDs

Expected console output (approximate):

Que Front -> Rear: 101 <-> NULL
Que Front -> Rear: 200 <-> 101 <-> NULL
Que Front -> Rear: 200 <-> 101 <-> 102 <-> NULL
Que Front -> Rear: 101 <-> 102 <-> NULL
Que Front -> Rear: 101 <-> 150 <-> 102 <-> NULL
Que Front -> Rear: 101 <-> 150 <-> 102 <-> 300 <-> NULL

Front patient ID IS : 101
Rear patientT ID: 300

## Notes and Behavior
- The queue holds integer patient IDs only.
- addPosition uses 1-based indexing; position <= 1 places the node at the front. If the traversal reaches the end before the requested position, the node is appended to the end.
- removeFront safely deletes the front node and updates pointers.
- The implementation uses raw pointers and manual dynamic allocation (new/delete).

## Suggestions for Improvement
- Add a destructor to free remaining nodes to avoid memory leaks (if you extend the demo or convert to interactive mode).
- Use smart pointers (unique_ptr/shared_ptr) or container adapters (std::list, std::deque) to simplify memory management.
- Add input validation and an interactive menu to let users add/remove by keyboard.
- Allow storing more patient information (name, priority, timestamp) and adding priority-based insertion.
- Implement remove by ID and search functions.
- Add unit tests and boundary-case tests (empty queue, single-node queue, large insertions).

## License
No license file included. Add e.g. MIT license if you plan to publish the code.

## Author
Provided by muhammadabdal15140 as a demo / assignment example.
