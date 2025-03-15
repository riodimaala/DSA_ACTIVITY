#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

Node *createNode(string data) {
        Node *newNode = new Node;
        newNode->songName = data;
        newNode->link = NULL;
        
    return newNode;
}

void Traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL" << endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" <<endl;

    return head;
} 

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if (temp == NULL){
            return "No such song exist, please try again later.";
        }
        
        temp = temp->link;

    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return"An new node has been added after " + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }

    if(head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }

    Node *temp = new Node;
    temp = head;

    while(temp->link->link != NULL){
        temp = temp->link;
    }

    temp->link = NULL;

     return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" <<endl;
        return NULL;
    }

    if(head->link == NULL){
        delete head;
    }

    head = head->link;

    cout <<"A node has been delete from the beginning \n" << endl;

    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" << endl;
        return NULL;
    }
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + " has been deleted. \n" << endl;
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }

    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head; 
}

int main(){
    
    Node *head = createNode("Songs");
    head = insertAtEnd("Isa lang by Arthur Nerry", head);
    head = insertAtEnd("Mundo by IV of Spades", head);
    head = insertAtEnd("Bulong by December Avenue", head);
    head = insertAtBeginning("Shouldn't by luke chiang", head);
    head = insertAtBeginning("Lazy Song by Bruno Mars", head);
    head = insertAtBeginning("24k Magic by Bruno Mars", head);
    head = insertAtBeginning("This is what autumn feels like by JVKE", head);
   
string result = insertAfter("Lazy Song by Bruno Mars", "Pasilyo by SunKissed Lola", head);
cout<<result;
string result1 = insertAfter("24k Magic by Bruno Mars", "Leaves By Ben&Ben", head);
cout<<result1;
string result2 = insertAfter("This is what autumn feels like by JVKE", "Umaasa by calein", head);
cout<<result2;

string END = deleteAtEnd(head);
cout << END << endl;
head = deleteFromBeginning(head);
head = deleteFromGivenNode("24k Magic by Bruno Mars", head);


    Traverse(head);




    










    return 0;
}