#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = NULL;

void push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Stack Underflow\n";
    else
    {
        Node *t = top;
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = top;
    cout << '\n'
         << "Elements in Stack are: ";
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << '\n';
}

int peek(int pos)
{
    Node *p = top;
    for (int i = 0; p != NULL && i < pos - 1; i++)
        p = p->next;

    if (p != NULL)
        return p->data;
    else
        return -1;
}

int isEmpty()
{
    return top?0:1;
}

int isFull()
{
    Node *t=new Node;
    int r=t?0:1;
    delete t;
    return r;
    // if(t==NULL)
        // return 1;
        // return 0;
}

int StackTop()
{
    if(top)
     return top->data;
     return -1;
}
int main()
{
    system("cls");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    Display();

    cout<<"\nFull: "<<isFull();
    cout<<"\nStack Top: "<<StackTop();
    cout << "\nDeleted Element: " << pop();
    cout << "\nDeleted Element: " << pop();
    cout << "\nDeleted Element: " << pop();
    
    Display();
    cout<<"\nEmpty: "<<isEmpty();
    cout<<"\nFull: "<<isFull();
    cout<<"\nStack Top: "<<StackTop();
    Display();

    return 0;
}