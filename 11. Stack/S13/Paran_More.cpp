#include <iostream>
#include <cstring>
using namespace std;

struct stack
{
    int size;
    int top;
    char *s;
};
void create(stack *st)
{
    cout << "Enter size: ";
    cin >> st->size;
    st->top = -1;
    st->s = new char(st->size);
}
void Display(stack st)
{
    int i;
    cout << '\n';
    for (i = st.top; i >= 0; i--)
        cout << st.s[i] << ' ';
    cout << '\n';
}
void push(stack *st, char x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow\n";
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
char pop(stack *st)
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
char peek(stack st, char pos)
{
    char x = '-1';
    if (st.top - pos + 1 < 0)
        cout << "Invalid Position\n";
    else
        x = st.s[st.top - pos + 1];

    return x;
}
int isEmpty(stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(stack st)
{
    return st.top == st.size - 1;
}
char stackTop(stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int isBalance(char *exp)
{
    stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = new char(st.size);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i]=='{' || exp[i]=='[')
            push(&st, exp[i]);
        else if (exp[i] == ')' || exp[i]=='}' || exp[i]==']')
        {
            if (isEmpty(st))
                return false;
            char x= pop(&st);

            if(x+1==exp[i] && x==40);
            else if(x+2==exp[i] && (x==91 || x==123 ));
            else return false;
            
        }
    }

    if (isEmpty(st))
        return true;
    else
        return false;
}

int main()
{    system("cls");
    char exp[100] ;
    cin>>exp;
    cout << isBalance(exp);
    return 0;
}






