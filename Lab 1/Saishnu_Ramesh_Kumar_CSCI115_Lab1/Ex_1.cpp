//Exercise 1 - Creating a Stack Data Structure using arrays

#include <iostream>

using namespace std;

//Stack class
class Stack
{

public:
    int top;
    int a[10]; //Array only holds up to 10 elements

    Stack()
    {
        top = -1;
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        void print();
    }

    //Push Function
    bool push(int x)
    {
        //Checks if it's a stack overflow
        if (top >= (10 - 1))
        {
            cout << "Stack Overflow" << endl;
            return false;
        }

        //Otherwise proceeds with the insertion
        else
        {
            a[++top] = x;

            cout << "\n"
                 << x << " has been pushed into the stack.\n";
            return true;
        }
    }

    //Pop Function
    int pop()
    {

        //Checks if it's a stack underflow
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }

        //Otherwise proceeds with the deletion
        else
        {
            int x = a[top--];
            return x;
        }
    }

    //Peek Function
    int peek()
    {

        //Checks if it's a stack underflow
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }

        //Otherwise proceeds with peak
        else
        {
            int x = a[top];
            return x;
        }
    }

    //isEmpty Function
    bool isEmpty()
    {

        //Return if top is less than 0
        return (top < 0);
    }

    //Print Function
    void print()
    {

        //Prints all elements located within the stack
        int size = top;
        cout << "Items in the stack: " << endl;
        while (size >= 0)
        {
            cout << a[size--] << " ";
        }
        cout << endl;
    }
};

//Main Function
int main()
{

    class Stack s;
    //Pushing all items into the stack
    s.push(20);
    s.push(40);
    s.push(60);
    cout<<endl;

    s.print();

    cout << "\nPopped item: " << s.pop() << endl; //Shows popped item

    cout << "\nPeeked item: " << s.peek() << endl; //Shows peeked item

    cout << "\n";
    s.print(); //Prints the stack

    return 0;
    
}