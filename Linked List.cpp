#include <iostream>
using namespace std;
class Node {

    int data;
    Node* head;
    Node* next;
    Node* curr;
    Node* prev;
public:
    Node(int value):data(value) {
        this->head = NULL;
        this->next = NULL;
        this->curr = NULL;
        this->prev = NULL;
    }
    Node() {
        data = 0;
        head = NULL;
        next = NULL;
        curr = NULL;
        prev = NULL;

  }
    
    void createLL(int);
    void display();
    Node* search(int);
    void sort();
    void update(int);
    void insertData(int);
    void deleteData(int);
    float calculateAvg();
};
float Node::calculateAvg() {
    Node* temp = head;
    float avg = 0;
    int sum = 0;
    int counter = 0;
    while (temp != NULL) {
    sum += temp->data;
       temp = temp->next;
       counter++;
    }
    avg = static_cast<float>(sum) / counter;
    return avg;
}

void Node::sort() {
    int counter = 0;
    Node* temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    temp = head;
    int* arr = new int[counter];
    for (int i = 0; i < counter; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < counter-1; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    temp = head;
    for (int i = 0; i < counter; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }
}
void Node::insertData(int value) {
    if (head == NULL) {
        cout << "data not found" << endl;
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp->next!= NULL) {
        if (temp->data <= value && temp->next->data > value) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
        curr->next = newNode;
        curr = curr->next;
    
}
void Node::deleteData(int value) {
    Node* toDelete = search(value);
    Node* temp = head;
    if (search(value) != NULL) {
        if (temp->data == value) {
            head = head->next;
            delete toDelete;
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->data == value) {
                temp->next = temp->next->next;
                delete toDelete;
                return;
           }
            temp = temp->next;
        }
    }
    else {
        cout << endl;
        cout << "data not found" << endl;
    }
}
void Node::update(int value) {
    Node* toUpdate = search(value);
    if (toUpdate != NULL) {
        int number;
        cout << "enter the value you want to update" << endl;
        cin >> number;
        toUpdate->data =number;
    }
    else {
        cout << "data not found" << endl;
    }
}
Node * Node::search(int value) {
    if (head== NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void Node::display() {
    if (head == NULL) {
        cout << "no data present" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void Node::createLL(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        curr = head;
        return;
    }
    prev = curr;
    curr->next = newNode;
    curr = curr->next;
}
void menu() {
    cout << "1.Create List" << endl;
    cout << "2.Display  List" << endl;
    cout << "3.Search Data" << endl;
    cout << "4.Sort  List" << endl;
    cout << "5.Update Data" << endl;
    cout << "6.Insert Data" << endl;
    cout << "7.Delete Data" << endl;
    cout << "8.Calculate Average" << endl;
    cout << "9.Exit" << endl;
}
int main()
{
    Node LL;
    char option;
    int data,n,total=0;
    do {
        menu();
        cout << "                       chose your option" << endl;
        cin >> option;
        switch (option) {
        case '1':
            cout << "how many data you want to enter " << endl;
            cin >> n;
            for (int i = 0; i < n; i++) {
                total++;
                cout << "data # " << total<<" :- ";
                cin >> data;
                LL.createLL(data);
           }
            break;
        case '2':
            LL.display();
            break;
        case '3':
            cout << "enter the data you want to search" << endl;
            cin >> data;
            { 
            Node* toSearch = LL.search(data);
            if (toSearch != NULL) 
                cout << "data is present" << endl;
            
            else 
                cout << "data not found" << endl;  
            }
            break;
        case '4':
            LL.sort();
            break;
        case '5':
            cout << "enter the data you want to update with" << endl;
            cin >> data;
            LL.update(data);
            break;
        case '6':
            cout << "enter the data you want to insert" << endl;
            cin >> data;
            LL.insertData(data);
            break;
        case '7':
            cout << "enter the data you want to delete" << endl;
            cin >> data;
            LL.deleteData(data);
            break;
        case '8':
        { float average = LL.calculateAvg();
        cout << "Average is :- " << average << endl;
        }
        break;
        
        case '9':
            exit(0);
        default:
            cout << "chose the correct option" << endl;
        }
    } while (true);
    
}

