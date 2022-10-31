#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }

    void push(int x);
    int pop();
    void Display();
    int peek(int pos);
    int isEmpty();
    int isFull();
    int StackTop();

};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
        cout << "Stack Empty\n";
    else
    {
        Node *t = new Node;
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *p = top;
    cout << '\n';
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << '\n';
}


int Stack::peek(int pos)
{
    Node *p = top;
    for (int i = 0; p != NULL && i < pos - 1; i++)
        p = p->next;

    if (p != NULL)
        return p->data;
    else
        return -1;
}

int Stack::isEmpty()
{
    return top?0:1;
}

int Stack::isFull()
{
    Node *t=new Node;
    int r=t?0:1;
    delete t;
    return r;
    // if(t==NULL)
        // return 1;
        // return 0;
}

int Stack::StackTop()
{
    if(top)
     return top->data;
     return -1;
}

int main()
{
    system("cls");

    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);

    stk.Display();

    cout<<"\nFull: "<<stk.isFull();
    cout<<"\nStack Top: "<<stk.StackTop();
    cout << "\nDeleted Element: " << stk.pop();
    cout << "\nDeleted Element: " << stk.pop();
    cout << "\nDeleted Element: " << stk.pop();
    
    stk.Display();
    cout<<"\nEmpty: "<<stk.isEmpty();
    cout<<"\nFull: "<<stk.isFull();
    cout<<"\nStack Top: "<<stk.StackTop();
    stk.Display();

    return 0;
}
