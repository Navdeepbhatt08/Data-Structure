#include <iostream>
using namespace std;

struct slist
{
    int data;
    slist *next;
};

// Insert at beginning
slist *insert(slist *ptr)
{
    int x;
    slist *p = new slist();

    if (p == NULL)
    {
        cout << "Memory Allocation failed";
        return ptr;
    }

    cout << "Enter Data: ";
    cin >> x;

    p->data = x;
    p->next = ptr;
    return p;
}

// Insert at end
slist *insertEnd(slist *ptr)
{
    int x;
    slist *p = new slist();
    slist *temp;

    if (p == NULL)
    {
        cout << "Memory Allocation failed";
        return ptr;
    }

    cout << "Enter Data: ";
    cin >> x;

    p->data = x;
    p->next = NULL;

    if (ptr == NULL)
        return p;

    temp = ptr;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
    return ptr;
}

// Display
void display(slist *node)
{
    if (node == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL\n";
}

// Find max
void findMax(slist *node)
{
    if (node == NULL)
    {
        cout << "Empty List\n";
        return;
    }

    int max = node->data;

    while (node != NULL)
    {
        if (node->data > max)
            max = node->data;
        node = node->next;
    }

    cout << "Max element is " << max << endl;
}

// Find min
void findMin(slist *node)
{
    if (node == NULL)
    {
        cout << "Empty List\n";
        return;
    }

    int min = node->data;

    while (node != NULL)
    {
        if (node->data < min)
            min = node->data;
        node = node->next;
    }

    cout << "Min element is " << min << endl;
}

// Print alternate nodes
void findAlternate(slist *node)
{
    if (node == NULL)
    {
        cout << "Empty\n";
        return;
    }

    while (node != NULL)
    {
        cout << node->data << "->";
        if (node->next != NULL)
            node = node->next->next;
        else
            break;
    }
    cout << "NULL\n";
}

// Delete alternate nodes
slist *deleteAlternate(slist *node)
{
    slist *head = node;

    while (node != NULL && node->next != NULL)
    {
        slist *temp = node->next;
        node->next = temp->next;
        delete temp;
        node = node->next;
    }

    cout << "Alternate Deleted\n";
    return head;
}

// Delete first node
slist *deleteFirst(slist *ptr)
{
    if (ptr == NULL)
    {
        cout << "List is Empty\n";
        return NULL;
    }

    slist *temp = ptr;
    ptr = ptr->next;
    delete temp;

    cout << "First Element Deleted\n";
    return ptr;
}

// Delete last node
slist *deleteLast(slist *ptr)
{
    if (ptr == NULL)
        return NULL;

    if (ptr->next == NULL)
    {
        delete ptr;
        return NULL;
    }

    slist *p = ptr;
    slist *q = NULL;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    delete p;

    cout << "Last Element Deleted\n";
    return ptr;
}

// Search
void search(slist *ptr)
{
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            cout << "Element Found\n";
            return;
        }
        ptr = ptr->next;
    }

    cout << "Element Not Found\n";
}

// Reverse list
slist *reverseList(slist *ptr)
{
    slist *prev = NULL;
    slist *curr = ptr;
    slist *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    cout << "Reversed List:\n";
    display(prev);

    return prev;
}




void findDuplicate(slist *head)
{
    slist *i,*j;
    for(i=head;i!=NULL && i->next !=NULL; i=i->next )
    {
        for(j=i->next;j!=NULL; j=j->next )
        {
            if(i->data == j->data)
            {
                cout<< i->data <<"->";
                break;
            }
        }
    }
    cout<<endl;
}
// MAIN
int main()
{
    int ch;
    slist *head = NULL;

    do
    {
        cout << "\n1. Insert At Left";
        cout << "\n2. Insert At Right";
        cout << "\n3. Display";
        cout << "\n4. Find Max";
        cout << "\n5. Find Min";
        cout << "\n6. Find Alternate";
        cout << "\n7. Delete Alternate";
        cout << "\n8. Delete First";
        cout << "\n9. Delete Last";
        cout << "\n10. Search";
        cout << "\n11. Reverse";
        cout << "\n12. Find Duplicate";
        cout << "\nChoice: ";

        cin >> ch;

        switch (ch)
        {
        case 1:
            head = insert(head);
            break;
        case 2:
            head = insertEnd(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            findMax(head);
            break;
        case 5:
            findMin(head);
            break;
        case 6:
            findAlternate(head);
            break;
        case 7:
            head = deleteAlternate(head);
            break;
        case 8:
            head = deleteFirst(head);
            break;
        case 9:
            head = deleteLast(head);
            break;
        case 10:
            search(head);
            break;
        case 11:
            head = reverseList(head);
            break;
        case 12:
            findDuplicate(head);
            break;
        }

    } while (ch < 100);

    return 0;
}