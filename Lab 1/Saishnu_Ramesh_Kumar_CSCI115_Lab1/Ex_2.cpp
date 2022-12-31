//Exercise 2 - Creating a Linked List for a list of items

#include <iostream>

using namespace std;

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

class LinkedList
{

public:
    node_t *head;

    LinkedList()
    {
        head = NULL;
        void insert(int value);
        void deleteFront();
        void deleteEnd();
        void print();
    }

    //Insert function
    void insert(int value)
    {
        //If linked list is empty, then initialise head with value
        if (head == NULL)
        {
            head = new node_t();
            head->data = value;
            head->next = NULL;
            return;
        }

        //Insert at head of the list
        node_t *newNode = new node_t();
        newNode->data = value; // Assign node data to value
        newNode->next = head;  // Point node to first position, so next node becomes second place
        head = newNode;        // Make itself the first position
    }

    //Print Function
    void print()
    {
        node_t *temp = head;
        if (head == NULL)
        {
            cout << "List is Empty!" << std::endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << " -> ";
            }
            else
            {
                cout << std::endl;
            }
            temp = temp->next;
        }
    }

    //Delete Front Function
    void deleteFront()
    {

        node_t *temp = head;

        if (head == NULL)
        {
            return;
        }

        head = head->next;

        delete temp;
    }

    //Delete End Function
    void deleteEnd()
    {

        if (head == NULL){
            return;
        }

        if(head->next == NULL){
            delete head;
            return;
        }

        node_t *secondNode = head;
        while(secondNode->next->next != NULL){
            secondNode = secondNode->next;
        }

        delete (secondNode->next);

        secondNode->next = NULL;

    }
};

//Main Function
int main()
{
    LinkedList linkedList;

    //Inserting all items into linked list
    linkedList.insert(60);
    linkedList.insert(40);
    linkedList.insert(20);
    cout << "Items in Linked List: " << endl;
    linkedList.print();
    cout<<endl;

    // Delete 20  (40 -> 60)
    linkedList.deleteFront();
    cout << "Items in Linked List after deleting the first element: " << endl;
    linkedList.print();
    cout<<endl;

    // Delete 60 (40)
    linkedList.deleteEnd();
    cout << "Items in Linked List after deleting the last element: " << endl;
    linkedList.print();

    return 0;
}
