#include <iostream>
using namespace std;
class node {
public:
    int info;
    string name;
    node *next;
    node(int val = 0, string n = "", node *ptr = 0)
    {
        info = val;
        name = n;
        next = ptr;
    }
};


class Sll {
public:
    node *head, *tail;

    Sll() {
        head = 0;
        tail = 0;
    }
    void add(int v, string name)
    {
        if (head == 0 || v < head->info)
            inserathead(v, name);
        else if (v > tail->info)
        {
            insertattail(v, name);
        }
        else
            insertinbw(v, name);
    }
    void insertinbw(int v, string name)
    {
        node *newnode = new node(v, name);
        node *current;
        /* Locate the node before the point of insertion */
        current = head;
        while (current->next != 0 && current->next->info < newnode->info)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }

    void inserathead(int v, string name)
    {
        node *newNode;
        newNode = new node(v, name);
        newNode->next = head;
        head = newNode;
        if (tail == 0)
            tail = head;
    }
    void insertattail(int v, string name)
    {
        if (tail == 0)
            cout << "\nEmpty list\n";
        else
        {
            tail->next = new node(v, name);
            tail = tail->next;
        }
    }

    void search(char c)
    {
        int f = 0, id;
        string n;
        if (c == 'i')
        {
            cout << "\nEnter the id to be searched: ";
            cin >> id;
            node *curr = head;
            while (curr)
            {
                if (id == curr->info)
                {
                    cout << "\nID " << id << " is present\n";
                    f = 1;
                }
                curr = curr->next;
            }
            if (f == 0)
                cout << "\nNot present\n";
        }
        else if (c == 'n')
        {
            cout << "\nEnter the name to be searched: ";
            cin >> n;
            node *curr = head;
            while (curr)
            {
                if (n == curr->name)
                {
                    cout << "\nName " << n << " is present\n";
                    f = 1;
                }
                curr = curr->next;
            }
            if (f == 0)
                cout << "\nNot present\n";
        }
    }

    void modify(char c){
        int f = 0, id, id1;
        string n, n1;
        if (c == 'i')
        {
            cout << "Enter the is to be modified: ";
            cin >> id;
            node *curr = head;
            while (curr){
                if (id == curr->info)
                {
                    cout << "\nEnter the new id: ";
                    cin >> id1;
                    curr->info = id1;
                    f = 1;
                }
                curr = curr->next;
            }
            if (f == 0)
                cout << "\nNot present\n";
        }
        else if (c == 'n'){
            cout << "Enter the name to be modified: ";
            cin >> n;
            node *curr = head;
            while (curr){
                if (n == curr->name)
                {
                    cout << "\nEnter the new name: ";
                    cin >> n1;
                    curr->name = n1;
                    f = 1;
                }
                curr = curr->next;
            }
            if (f == 0)
                cout << "\nNot present\n";
        }
    }

    void display(){
        if (head == 0)
            return;
        node *curr = head;
        cout << "\nThe linked list contains: ";
        while (curr)
        {
            cout << "ID:" << curr->info << "-->";
            curr = curr->next;
        }
    }

    int deletes(int v){
        if (v == head->info)
        {
            return delathead();
        }
        if (v == tail->info)
        {
            return delattail();
        }
        else
        {
            return del(v);
        }
    }
    int delathead(){
        if (head)
        {
            node *curr = head;
            int v = curr->info;
            if (head == tail)
                tail = 0;
            head = head->next;
            delete curr;
            return v;
        }
        return -1;
    }

    int delattail()
    {
        if (head)
        {
            int val = tail->info;
            if (head == tail)
            {
                delete tail;
                head = tail = 0;
            }
            else
            {
                node *curr = head;
                for (; curr->next != tail; curr = curr->next)
                    ;
                tail = curr;
                delete curr->next;
                tail->next = 0;
            }
            return val;
        }
        return -1;
    }

    int del(int v)
    {
        int c;
        if (head)
        {
            if (head->info == v && head == tail)
            {
                c = head->info;
                delete head;
                head = tail = 0;
                return c;
            }
            else if (head->info == v)
            {
                node *curr = head;
                head = head->next;
                c = curr->info;
                delete curr;
                return c;
            }
            else
            {
                node *prev, *curr;
                for (prev = head, curr = head->next; curr != 0 && curr->info != v; prev = prev->next, curr = curr->next)
                    ;
                if (curr)
                {
                    if (curr == tail)
                        tail = prev;
                    prev->next = curr->next;
                    c = curr->info;
                    delete curr;
                    return c;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int c, v, m;
    char ch, ans, id;
    string name, name1;
    Sll s;
    do
    {
        cout << "\n1. Create";
        cout << "\n2. Add";
        cout << "\n3. Delete";
        cout << "\n4. Display";
        cout << "\n5. Modify";
        cout << "\n6. Search";
        cout << "\nOption: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "\nList Created\n";
            break;
        case 2:
            cout << "\nEnter the element: ";
            cin >> v;
            cout << "Enter the name: ";
            cin >> name;
            s.add(v, name);
            break;
        case 3:
            int i;
            cout << "Please enter the ID of the person: ";
            cin >> i;
            m = s.deletes(i);
            if (m == -1)
                cout << "\nElement not present\n";
            else
                cout << "\nDeleted " << m;
            break;
        case 4:
            s.display();
            break;
        case 5:
            char c;
            cout << "\nModify by?(n for name and i for id): ";
            cin >> c;
            s.modify(c);
            break;
        case 6:
            char q;
            cout << "\nSearch by?(n for name and i for id): ";
            cin >> q;
            s.search(q);
            break;
        deafult:
            cout << "\nInvalid choice";
            break;
        }
        cout << "\n\nDo you want to continue(y/n): ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}