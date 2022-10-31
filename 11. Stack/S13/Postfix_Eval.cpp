#include <iostream>
#include<cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    public:
    Node *top;
    Stack() { top = NULL; }

    void push(char x);
    char pop();
    void Display();
    int peek(int pos);
    int isEmpty();
    int isFull();
    int StackTop();

}st;

void Stack::push(char x)
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

char Stack::pop()
{
    char x = -1;
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

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            st.push(exp[i]);
        else if (exp[i] == ')')
        {
            if (st.top == NULL)
                return 0;
           st.pop();
        }
    }
    if (st.top == NULL)
        return 1;
    else
        return 0;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
     char *postfix=new char[len+2];
    
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(st.top->data))
                st.push(infix[i++]);
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while (st.top != NULL)
        postfix[j++] = st.pop();
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix)
{
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            st.push(postfix[i]-'0');
        }
        else
        {
            x2=st.pop(); x1=st.pop();
            switch(postfix[i])
            {
                case '+': r=x1+x2; st.push(r); break;
                case '-': r=x1-x2; st.push(r); break;
                case '*': r=x1*x2; st.push(r); break;
                case '/': r=x1/x2; st.push(r); break;
            }
        }
    }
    return st.top->data;
}

int main()
{   system("cls");
    char *postfix="234*+82/-";
    int res=Eval(postfix);
    cout<<"Result: "<<res;
    return 0;
}