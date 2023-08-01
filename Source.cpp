#include <iostream>
#include <cassert>

using namespace std;

const int MAX = 10;

template<typename T>
class Deque
{
    T arr[MAX]{};
    int front = -1;
    int rear = -1;
    int dequeSize = 0;

public:
    Deque() = default;
    void push_front(T item);
    void push_rear(T item);
    void pop_front();
    void pop_rear();
    bool isFull();
    bool isEmpty();
    int getSize();
    T Front();
    T Rear();

    template<typename T>
    friend ostream& operator<<(ostream& print, const Deque<T>& que);
};

template<typename T>
int Deque<T>::getSize() {
    return dequeSize;
}

template<typename T>
void Deque<T>::push_front(T item)
{
    if (isFull())
    {
        cout << "Full!" << endl;
        return;
    }
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    arr[front] = item;
    dequeSize++;
}

template<typename T>
void Deque<T>::push_rear(T item)
{
    if (isFull())
    {
        cout << "Full!" << endl;
        return;
    }
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = item;
    dequeSize++;
}

template<typename T>
void Deque<T>::pop_front()
{
    if (isEmpty())
    {
        cout << "Empty!" << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    dequeSize--;
}

template<typename T>
void Deque<T>::pop_rear()
{
    if (isEmpty())
    {
        cout << "Empty!" << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
    dequeSize--;
}

template<typename T>
bool Deque<T>::isFull()
{
    if (front == 0 && rear == MAX - 1)
        return true;
    if (front == rear + 1)
        return true;
    return false;
}

template<typename T>
bool Deque<T>::isEmpty()
{
    return front == -1;
}

template<typename T>
T Deque<T>::Front()
{
    if (isEmpty())
        assert(!"Empty");
    return arr[front];
}

template<typename T>
T Deque<T>::Rear()
{
    if (isEmpty())
        assert(!"Empty");
    return arr[rear];
}

template<typename T>
ostream& operator<<(ostream& print, const Deque<T>& que)
{
    int i;
    print << "[";
    for ( i = que.front; i != que.rear; i = (i + 1) % MAX) {
        print  << que.arr[i] << ",  ";
    }
    print << que.arr[i] << "]";
    return print;
}

int main()
{
    Deque<int> d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_rear(4);
    d.push_rear(5);
    d.push_rear(6);
    cout << d;

    return 0;
}






