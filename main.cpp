#include "ArrayQueue.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // create a queue of 10 integers
    ArrayQueue<int> queueA(10);

    // attempt to display the front and back
    try {
        cout << queueA.front() << " \n";
    } catch (string& e) {
        cout << e << " \n";
    }
    try {
        cout << queueA.back() << " \n";
    } catch (string& e) {
        cout << e << " \n";
    }

    // insert just one element to queue A
    queueA.enqueue(-5);

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " \n";
    cout << "queue A front: "  << queueA.front()     << " \n";
    cout << "queue A back: "   << queueA.back()      << " \n";

    // now remove the single element from queue A
    queueA.dequeue();

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " \n";
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " \n";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " \n";
    }

    // populate queue A by enqueueing random values
    srand(time(0));
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        queueA.enqueue(rand() % 500);
    }

    // ensure that queue A is now full
    if (queueA.isFull()) {
        cout << "queue A is full! \n";
    }
    else {
        cout << "queue A is not full [ERROR] ";
    }

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " \n";
    cout << "queue A front: "  << queueA.front()     << " \n";
    cout << "queue A back: "   << queueA.back()      << " \n";

    // make a copy of queue A
    ArrayQueue<int> queueB = queueA;

    // loop to dequeue and print
    cout << "queue A contains: ";
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " \n";

    // queue A should now be empty
    if (queueA.isEmpty()) {
        cout << "queue A is now empty \n";
    }
    else {
        cout << "queue A is not empty [ERROR] ";
    }

    // display queue B length, front, and back
    cout << "queue B length: " << queueB.getLength() << " \n";
    cout << "queue B front: "  << queueB.front()     << " \n";
    cout << "queue B back: "   << queueB.back()      << " \n";

    // make a copy of queue B
    ArrayQueue<int> queueC;
    queueC = queueB;

    // clear out queue B
    queueB.clear();

    // queue B should now be empty
    if (queueB.isEmpty()) {
        cout << "queue B is now empty \n";
    }
    else {
        cout << "queue B is not empty [ERROR] ";
    }

    // display queue C length, front, and back
    cout << "queue C length: " << queueC.getLength() << " \n";
    cout << "queue C front: "  << queueC.front()     << " \n";
    cout << "queue C back: "   << queueC.back()      << " \n";

    // terminate
    return 0;
}