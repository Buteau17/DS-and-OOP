#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*.......Linked List for Stack ......*/
struct Node {
    int data;
    struct Node *next;
};

/*.....Linked List for Queue.....*/
struct node {
    int data;
    struct node *next;
};


/*... Class STACK with all the required methods......*/
class STACK
{
public:
    void push(int);
    void pop();
    void print();
};
struct Node* top = NULL;

/*..... Push(int num) function ......*/
void STACK::push(int num) {
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = top;
    top = newnode;
}

/*....pop() function.....*/
void STACK::pop() {
    if(top!=NULL)
        top = top->next;
}

/*.....print() function....*/
void STACK::print() {
    cout<<"The values in the stack: ";
    struct Node* ptr;
    vector<int> ans;
    if(top!=NULL) {
        ptr = top;
        while (ptr != NULL) {
            ans.push_back(ptr->data);
            ptr = ptr->next;
        }
    }
    for(int i = ans.size()-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }
    cout<<endl;
}


/*....class QUEUE .....*/
class QUEUE
{
public:
    void enqueue(int);
    void dequeue();
    void print();
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

/*......enqueue(int num) function.......*/
void QUEUE::enqueue(int num) {
if (rear == NULL) {
rear = (struct node *)malloc(sizeof(struct node));
rear->next = NULL;
rear->data = num;
front = rear;
} else {
temp=(struct node *)malloc(sizeof(struct node));
rear->next = temp;
temp->data = num;
temp->next = NULL;
rear = temp;
}
}

/*.....dequeue() function.....*/
void QUEUE::dequeue() {
temp = front;
if (front != NULL) {

if (temp->next != NULL) {
temp = temp->next;
free(front);
front = temp;
} else {
free(front);
front = NULL;
rear = NULL;
}
}
}

/*......print() function.....*/
void QUEUE::print() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout<<"The values in the queue: "<<endl;
        return;
    }
    vector<int> ans;
    cout<<"The values in the queue: ";
    while (temp != NULL) {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    for(int i = ans.size()-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }
    cout<<endl;
}


int main(){

    STACK stk;//STACK object created
    QUEUE que;//QUEUE object created
    fstream newfile;//file pointer
    char *ptr;
    int x,n;
    newfile.open("input2.txt",ios::in); //File is opened in read mode

    if (newfile.is_open()){ //check whether file is open or not
        int n;
        newfile >> n;
        for(int i = 0; i < n; i++) {
            char cc;
            newfile >> cc;
            string str;
            int a;
            if(cc == 'S') {
                top = NULL;
                int num; newfile >> num;
                for(int j = 0; j < num; j++) {
                    newfile >> str;
                    if(str == "push") {
                        newfile >> a;
                        stk.push(a);
                    }
                    else if(str == "pop")
                        stk.pop();
                    else
                        stk.print();
                }
            }
            else {
                front = NULL;
                rear = NULL;
                int num; newfile >> num;
                for(int j = 0; j < num; j++) {
                    newfile >> str;
                    if(str == "en") {
                        newfile >> a;
                        que.enqueue(a);
                    }
                    else if(str == "de")
                        que.dequeue();
                    else
                        que.print();
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
