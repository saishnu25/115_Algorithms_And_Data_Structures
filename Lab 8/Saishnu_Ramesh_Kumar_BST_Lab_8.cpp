/* 
*       This program deals with the Binary Search Tree
*       Done By: Saishnu Ramesh Kumar
*       Student ID: 300758706
*
 */
#include <iostream>

// Node Class
class Node{
    public:
        Node(int data){
        this->data = data;
        this->LeftChild = NULL;
        this->RightChild = NULL;
    };
    int data;
    Node *LeftChild;
    Node *RightChild;
};

// BST Class
class BST{

    private:
        Node *root;

    public:

        // Constructor
        BST(){
            root = NULL;
        }

        Node *getRoot() { return this->root; };

        // Print Tree Function
        void printTree(Node *root){
            if(root == NULL){
                return; // If the root is NULL, just return
            }
            printTree(root->LeftChild); // Recursively call towards left child
            printTree(root->RightChild); // Recursively call towards right child
            std::cout << root->data <<" ";
        }

        // Insert Node Function
        void InsertNode(Node *node, int data){
            if(node-> data > data){ // If the left node is NOT empty, recursively call to move to the left subtree
                if(node->LeftChild != NULL){
                    InsertNode(node->LeftChild, data);
                }
                else{
                    node->LeftChild = new Node(data);
                }
            }

            else{ //If the right not is NOT empty, recursively call to move to the right subtree
                if(node->RightChild != NULL){
                    InsertNode(node->RightChild, data);
                }
                else{
                    node->RightChild = new Node(data);
                }
            }
        }

        // Find Node Function
        bool FindNode(Node *node, int data){
            if(node == NULL){
                return false;
            }
            else if(data == node->data){
                return true;
            }
            else if(data <= node->data){
                return FindNode(node->LeftChild, data);
            }
            else{
                return FindNode(node->RightChild, data);
            }
        }

        // Largest Function
        int Largest(Node *node){
            while(node->RightChild != NULL){
                node = node->RightChild; //Largest is always on the right side
            }

            return node->data;
        }

        // Print Function
        void printList(){
            printTree(root);
            std::cout<<std::endl;
        }

        // Insertion Function
        void insertion(int key){
            if(root == NULL){
                root = new Node(key);
            }
            else{
                InsertNode(root, key);
            }
        }

        // Find Largest Function
        void findLargest(){
            std::cout << Largest(root) << std::endl;
        }

        // Search Node Function
        void searchNode(int data){
            int temp = FindNode(root, data);
            if(temp == true){
                std::cout << data <<" is found in the BST!"<< std::endl;
            }
           
            else if(temp == false){
                std::cout << data << " can not be found in the BST!" <<std::endl;
            }

            else{
                std::cout <<"Error!"<<std::endl;
            }
        }
};

// Main Function
int main(){

    BST bst;
    //Insertion of all the elements into the tree
    bst.insertion(10);
    bst.insertion(1);
    bst.insertion(15);
    bst.insertion(33);
    bst.insertion(7);
    bst.insertion(12);
    bst.insertion(24);
    bst.insertion(56);
    bst.insertion(84);
    bst.insertion(2);

    std::cout<< "Post-order: " <<std::endl;
    bst.printList(); // Calling printList Function

    std::cout<< "Largest element in the list is: " <<std::endl;
    bst.findLargest(); // Calling findLargest Function

    bst.searchNode(56); // Calling searchNode Function
    bst.searchNode(25); // Calling searchNode Function

    std::cout<< "End of program..."<<std::endl;

    return 0;
}