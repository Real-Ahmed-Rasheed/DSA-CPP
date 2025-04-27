#include <iostream>
using namespace std;

class Queue
{
private:
  int *arr;
  int front;
  int back;
  int size;
  int elements;

public:
  Queue(int size)
  {
    this->size = size;
    arr = new int[size];
    front = -1;
    back = -1;
    elements = 0;
  }
  void push(int n)
  {
    if ((back + 1) % size == front)
    {
      cout << "Queue overflow" << endl;
      return;
    }
    else
    {
      if (front == -1)
      {
        front++;
      }
      back = (back + 1) % size;
      arr[back] = n;
      elements++;
    }
  }
  void pop()
  {
    if (elements == 0)
    {
      cout << "Queue underflow" << endl;
    }
    else
    {
      if (elements == 1)
      {
        front = back = -1;
      }
      else
      {
        front = (front + 1) % size;
        elements--;
      }
    }
  }
  void peek()
  {
    if (elements == 0)
    {
      cout << "Queue is empty" << endl;
    }
    else
    {
      cout << "Top at: " << arr[front] << endl; // Show the front element
    }
  }
  void print()
  {
    for (int i = front; i <= back; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  void Size() { cout << "elements are: " << elements << endl; }
};

int main()
{
  Queue q(5);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.Size();
  q.peek();
  q.pop();
  q.peek();
  q.Size();
  q.Size();

  return 1;
}
