#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <typename T>
class Queue
{
private:
    int front{};
    int rear{};
    T *q_data{};
    T recent_dequeue{};
    int q_size{};
    int q_capacity{};

public:
    Queue() = default; // defualt constructor
    Queue(int capacity) : q_capacity{capacity}
    {
        assert(capacity >= 0);
        if (capacity > 0)
        {
            q_data = new T[capacity]{};
            front = q_size = 0;
            rear = q_capacity - 1;
        }
    }

    // Checks whether queue is empty or not.
    // Returns "true" if empty otherwise "false".
    bool isEmpty() const
    {
        return (q_size == 0);
    }

    // Checks whether queue is full or not.
    // Returns "true" if full otherwise "false".
    bool isFull() const
    {
        return (q_size == q_capacity);
    }

    // Returns the first element of the queue data structure.
    T returnFront() const
    {
        if (isEmpty())
            cout << "Queue empty!!\n";

        return q_data[front];
    }

    // Returns the last element of the queue data structure.
    T returnRear() const
    {
        if (isEmpty())
            cout << "Queue empty!!\n";
        return q_data[rear];
    }

    // Returns the current size of the queue data structure.
    int returnSize()
    {
        return q_size;
    }

    // Inserts passed value to the rear of the queue data structure.
    void enqueue(T data)
    {
        if (isFull())
            return;
        rear = (rear + 1) % q_capacity;
        q_data[rear] = data;
        q_size++;
    }

    // Deletes the front of the queue data structure.
    void dequeue()
    {
        if (isEmpty())
            return;
        recent_dequeue = q_data[front];
        front = (front + 1) % q_capacity;
        q_size--;
    }

    // Returns the most recently dequeued item.
    T returnDequeue()
    {
        return recent_dequeue;
    }

    void setZero()
    {
        for (int i = 0; i < q_size; i++)
        {
            q_data[i] = 0;
        }
    }
};