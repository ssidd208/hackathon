#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int maxChocolates(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return 0;
    }

    Node *start = head;
    Node *end = head;
    int n = 5; // if we take inputs from user then we have to pass n as argument to the function.
    int maxSum = INT32_MIN;
  int i,k,sum=0;
  for(i=0;i<n;i++)
  {
    for(k=0;k<(2*n)-i-1;k++)
    {
        end= end->next;
    }
    sum= end->data + start->data;
    if(maxSum<sum)
    {
        maxSum=sum;
    }
    start=start->next;
    end=head;
  }
  cout<<"hello world"<<endl;
    return maxSum;
}
// Function to add a node at the end of the list
void append(Node*& head, int newData) {
    Node* newNode = new Node{ newData, nullptr };

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Adding elements to the linked list
    int data;
    cout << "Enter numbers (-1 to stop): " << endl;
    while (true) {
        cin >> data;
        if (data == -1) {
            break;
        }
        append(head, data);
    }
int result = maxChocolates(head);
    cout << "Maximum chocolates received: " << result << endl;
    // Deallocating memory - free the nodes after use
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

