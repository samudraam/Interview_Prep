// Ramya Samudrala
//
// Coding Prep
//


/*
Doubly Linked Lists 
*/
#include <iostream>
using namespace std;

struct node
{
    /* data */
    string data;
    node* next;
    node* prev;
};

void createNode(string n){
    node* n;
    n->

    cout << "The value is: " << n->data << endl;
}


void addNodesToList(node* n, node* nxt, node* prv){
    n->next = nxt;
    n->prev = prv;
}

int main(int argc, char** argv){

    //create pointers
    node* head;
    node* tail;
    node* n; 


    createNode("first");
    createNode("second");
    addNodesToList(n, head, tail);


    return 0;
}






