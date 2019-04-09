
/* C++ Implementation of a generic stack data structure using linked list 
 */


#include <iostream>

using namespace std;

template <typename datatype>
class stack
{
    private:
        typedef struct node
        {
           datatype data;
           struct node *next;
        }  Bstnode;

        Bstnode *top = NULL;

    public:
        void push (datatype key);
        int pop  ();
        void peek ();
        bool is_empty ();
};

template <typename datatype>
bool stack <datatype>:: is_empty()
{
    return ((top != NULL) ? false : true );
}

template <typename datatype>
void stack <datatype>:: push (datatype key)
{
    Bstnode *temp = new Bstnode;
    temp -> data  = key;
    temp -> next  = NULL;

    if (top == NULL)
    {
        top = temp;
        return;
    }
    temp -> next = top;
    top = temp;
}

template <typename datatype>
int stack <datatype>:: pop ()
{
    if (!top)
    {
        cout << "Stack is empty \n";
        return 0;
    }

    int data;
    Bstnode *temp = top;
    top = temp -> next;
    delete (temp);

    return data;
}

template <typename datatype>
void stack <datatype>::peek ()
{
    if (!top)
    {
        cout << "Stack is empty !\n";
        return;
    }
    
    cout << "Last Element is " << top -> data << endl;
}

int main ()
{
    stack <float> obj;
    obj.push (3.26);
    obj.push (4.26);
    obj.push (5.23);
    obj.peek ();
    obj.pop  ();
    obj.peek ();
}
