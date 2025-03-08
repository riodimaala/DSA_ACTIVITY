#include <iostream>

using namespace std;
typedef struct Node{ 
    string songName;
    Node *link;
}Node; 

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << " My Playlisst" <<endl;
    while (temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
          cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    (head == NULL){}
    Node *newNOde = createNode(data);
    head = newNode;
    cout << " A new node has been inserted at the end \n" << endl; 
    return head;
}
NOde *temp = new Node; 
temp = head;

while(temp->link != NULL){
    temp = temp->link;
}

Node *newNode = createNode(data); 
temp->link = newNode;

cout << "A new node has been inserted at the end \n" << endl;
return head;
}

int main(){
    Node *head = createNode("Sanctuary by Joji");


    return 0;
}
    

