#include <iostream>

class Node{
    public:
        int data;
        Node* next;
};

void insertBeg(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
}

void insert(Node** head, int data, int position){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(position == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;

    for(int i = 0; i < position - 1; i++){
        if(temp == NULL){
            std::cout << "Position not found" << std::endl;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void removeNode(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;

    if(temp == NULL){
        std::cout << "List is empty" << std::endl;
        return;
    }

    if(temp != NULL && temp->data == key){
        std::cout << "Removing Key: " << key << std::endl;
        *head = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        std::cout << "Key not found: " << key << std::endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void get(Node* head, int position){
    Node* temp = head;
    for(int i = 0; i < position; i++){
        if(temp == NULL){
            std::cout << "Position not found" << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Data at position " << position << ": " << temp->data << std::endl;

    if(temp == NULL){
        std::cout << "Position not found" << std::endl;
    }
    
}

void printList(const Node *node){
    if (node == NULL) {
        std::cout << "Linked List not found." << std::endl;
        return;
    }
    while(node != NULL){
        std::cout << node->data << " ";
        node = node->next;
    }
}

void removeList(Node** head){
    Node* current = *head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }

    *head = NULL;
    std::cout << "List deleted." << std::endl;
    free(*head);
}

int main() {
    Node* head = NULL;
    insertBeg(&head, 1);
    insertBeg(&head, 2);
    insertBeg(&head, 3);
    insertEnd(&head, 4);
    printList(head);
    std::cout << std::endl;

    removeNode(&head, 13);
    printList(head);
    std::cout << std::endl;

    insert(&head, 4, 0);
    printList(head);
    std::cout << std::endl;

    get(head, 2);
    std::cout << std::endl;
    
    removeList(&head);
    printList(head);
}