#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(stack *st)
{
    cout << "Enter size: ";
    cin >> st->size;
    st->top = -1;
    st->s = new int(st->size);
}

void Display(stack st)
{
    int i;
    cout << '\n';
    for (i = st.top; i >= 0; i--)
        cout << st.s[i] << ' ';
    cout << '\n';
}

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow\n";
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int peek(stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
        cout << "Invalid Position\n";
    else
        x = st.s[st.top - pos + 1];

        return x;
}

int isEmpty(stack st)
{
    if(st.top==-1)
      return 1;
      return 0;
}

int isFull(stack st)
{
    return st.top==st.size-1;
}

int stackTop(stack st)
{
    if(!isEmpty(st))
    return st.s[st.top];
    return -1;
}

int main()
{
    system("cls");
    stack st;
    create(&st);
    cout<<"Empty: "<<isEmpty(st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    
    Display(st);
    cout<<"\nFull: "<<isFull(st);
    cout<<"\nStack Top: "<<stackTop(st);
    cout << "\nDeleted Element: " << pop(&st);
    cout << "\nDeleted Element: " << pop(&st);
    cout << "\nDeleted Element: " << pop(&st);
    
    Display(st);

    cout<<"Empty: "<<isEmpty(st);
    cout<<"\nFull: "<<isFull(st);
    cout<<"\nStack Top: "<<stackTop(st);

    return 0;
}