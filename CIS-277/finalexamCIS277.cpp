#include <iostream>
using namespace std;

struct Node
{
    // int value;
    int data;
    Node *next = nullptr;
};

bool create = false; // Boolean to check if the list has been created or not

struct List
{
    Node *head;
    Node *tail;
    Node *current; // what does this do?
    int itemCount; // This is an example to use certain items for passing in by refrence.
};

void display(List &displayingg)
{
    if (!create)
    {
        cout << "What are you displaying? There is no list.";
    }
    else
    {
        // Node* ptr; //why bother with this when we have list.current?
        // if it's empty, should we bother doing this?
        displayingg.current = displayingg.head;
        if (displayingg.current == nullptr)
        {
            printf("The list is empty my guy");
        }
        else
        {
            printf("Displaying the LL....\n");
            while (displayingg.current != nullptr)
            {
                cout << displayingg.current->data << " ";
                displayingg.current = displayingg.current->next;
            }
        }
        // can we output the item count, regardless?
        cout << endl
             << "The list has: " << displayingg.itemCount << " items" << endl;
        printf("\nDONE!\n");
    }
}

void createList(List &startList)
{
    if (create == true)
    {
        cout << "One list at a time please... the list has already been created.";
    }
    else
    {
        printf("Creating Single Linked List\n");
        startList.head = nullptr;
        startList.tail = nullptr;
        startList.itemCount = 0;
        create = true;
        printf("\nDONE!\n");
    }
};

void remove(List &removing)
{
    Node *ptr = removing.head;
    Node *prev;

    bool find = false; // True if value is found
    if (!create)
    { // Checks if list is created first
        cout << "List? What list? The list does not exist...";
    }
    else if (removing.head == nullptr)
    { // Checks if the list is empty
        cout << "Why are you trying to delete something from an empty list?";
    }
    else
    {
        int val;
        cout << "Please enter the value to remove: ";
        cin >> val;

        do
        {
            if (ptr == removing.tail && removing.itemCount == 1)
            { // Marks find as true if the value is found and there is only one element in the list
                find = true;
            }
            else if (ptr == removing.tail)
            { // The loop has reached the end and the value still has not been found; break and return false
                break;
            }
            else if (ptr->data == val)
            { // Marks find as true as the value is found
                find = true;
            }
            else
            {
                prev = ptr;      // Previous node is made equal to ptr
                ptr = ptr->next; // Ptr is incremented to the next node
                if (ptr->data == val)
                { // Another check is done after ptr is incremented
                    find = true;
                }
            }
        } while (ptr->data != val); // Loops until the data is equal to the value searched for
    }

    if (find == true)
    {
        cout << "\nDeleting " << ptr->data << " now...";
        if (ptr == removing.head)
        { // Value being deleted is the head, so head is removed
            removing.head = ptr->next;
            ptr->next = nullptr;
            delete ptr;
            removing.itemCount -= 1;
            cout << "\nDONE!\n";
        }
        else
        { // Value is not the head (value is anywhere between the beginning and end of the list, or it is the tail)
            prev->next = ptr->next;
            ptr->next = nullptr;
            delete ptr;
            removing.itemCount -= 1;
            cout << "\nDONE!\n";
        }
    }
    else
    {
        if (removing.head == nullptr || !create)
        { // Returns to the menu if the list is empty or if the list has not been created
            return;
        }
        cout << "\nValue does not exist in the list.";
    }
}

void searchList(List &searching, int findMe)
{
    // initialize a value to hold the current index
    int idx = 1;
    bool itemFound = false;
    if (searching.head == nullptr)
    {
        printf("No Bueno - empty list");
    }
    else
    {
        // point the current element of the list to the head
        searching.current = searching.head;
        do
        {
            // check if the thing we are currently pointing at is the thing that we want
            if (searching.current->data == findMe)
            {
                // flag the item as found
                itemFound = true;
                break;
            }
            else
            {
                // increment idx
                idx++;
                // point the current node to the next node
                searching.current = searching.current->next;
            }
        } while (searching.current != nullptr); // until we are currently looking at a NULLPTR
    }
    // tell the user whether you found the thing or not

    if (itemFound == true)
    {
        cout << "Found value " << searching.current->data << ", in " << idx << " try(s)" << endl;
        printf("\nDONE!\n");
    }
    else
    {
        printf("\nItem wasn't there");
    }
}

void modify(List &mod)
{
    bool foundToMod = false; // True if value to modify is found

    if (!create)
    { // Checks if list has been created first
        cout << "Why modify a list that doesn't exist?\n";
    }
    else if (mod.head == nullptr)
    { // Checks if the list is empty
        cout << "Before attempting to modify, make sure you have picked option 2 first.\n";
    }
    else
    {
        int choice;
        cout << "Please enter value to modify: ";
        cin >> choice;
        Node *ptr = mod.head;

        do
        {
            if (ptr == mod.tail && mod.itemCount == 1)
            { // Marks find as true if the value is found and there is only one element in the list
                foundToMod = true;
            }
            else if (ptr == mod.tail)
            { // The loop has reached the end and the value still has not been found; break and return false
                break;
            }
            else if (ptr->data == choice)
            { // Choice has been found; return true
                foundToMod = true;
            }
            else
            { // Choice has not been found; increment ptr and continue searching
                ptr = ptr->next;
                if (ptr->data == choice)
                { // Another check is done after ptr is incremented
                    foundToMod = true;
                }
            }
        } while (ptr->data != choice); // Loop continues until the data is equal to the choice entered

        if (foundToMod == true)
        {
            int replace;
            cout << "Enter the value you want to replace " << ptr->data << " with: ";
            cin >> replace;
            cout << "\nModifying value " << ptr->data << " with " << replace << "...";
            ptr->data = replace; //"replace" replaces data with itself
            cout << "\nDONE!\n";
        }
        else
        {
            cout << "\nValue does not exist in the list.";
        }
    }
}

void purge(List &deletingg)
{
    if (!create)
    {
        cout << "Purge what?? The list does not exist!";
    }
    else if (deletingg.head == nullptr)
    {
        cout << "You're attempting to purge an empty list. Fill it up first!";
    }
    else
    {
        printf("Purging the LL....\n");
        //  Node* current; //create a pointer to keep track of the current node
        Node *deleteMe; // create a temporary pointer to keep track of which node to delete
        // Node* next; //create a pointer to keep track off the rest of the nodes inside the ll
        deletingg.current = deletingg.head; // set the current pointer to the head of the ll
        // next = current -> next;//make the next pointer point to the node after the current one
        while (deletingg.current != nullptr) // while we aren't looking at NOTHING,
        {
            cout << "Deleting " << deletingg.current->data << "...\n"; // display the current data
            // mark the current node to be deleted (point the deleteMe pointer at it)
            deleteMe = deletingg.current;
            // move the current pointer to the next position
            deletingg.current = deletingg.current->next;

            // move the next pointer down
            // next = current->next;

            free(deleteMe); // free the deletable node
            // decrement the item counter in the list
            deletingg.itemCount--;
        }
        // now the list is technically empty, but the head and tail and current are still pointing to whatever
        deletingg.head = nullptr;
        deletingg.tail = nullptr;
        deletingg.current = nullptr;
        printf("DONE!\n");
    }
}

void add(List &addingValue)
{
    Node *temp;
    if (!create)
    {
        cout << "Looks like you're trying to add to a list that does not exist";
    }
    else
    {
        printf("Adding a value to the LL....\n");
        int value;
        Node *current;
        cout << "Enter a value to add to the list: ";
        cin >> value;

        Node *check = addingValue.head;
        bool same = false; // Boolean to check if the value already exists
        while (check != nullptr)
        {
            if (value == check->data)
            {
                same = true;
            }
            check = check->next;
        }

        if (same == true)
        { // returns to the menu if the value already exists, else it adds the value to the list
            cout << "\nValue " << value << " already exists in the list!\n";
            return;
        }
        else
        {
            if (addingValue.head == nullptr)
            { // If the list is empty, the value becomes the head & tail OR if the value is greater than the head of the list
                temp = new Node;
                temp->data = value;
                temp->next = addingValue.head;
                addingValue.head = temp;
                addingValue.itemCount++;
                addingValue.tail = addingValue.head;
            }
            else if (value < addingValue.head->data)
            { // If the value is less than the head, it becomes the following node
                temp = new Node;
                temp->data = value;
                temp->next = addingValue.head;
                addingValue.head = temp;
                addingValue.itemCount++;
            }
            else if (value > addingValue.tail->data)
            { // If the value is greater than the tail of the list, the value becomes the tail
                // addTail(addingValue, value);
                temp = new Node;      // grab some memory for the new node
                temp->data = value;   // assign a value to the new node
                temp->next = nullptr; // anticipate that this new node will be the tail
                // take the current tail, and make its next pointer point to the new node
                addingValue.tail->next = temp;
                // set the new node as the current tail
                addingValue.tail = temp;
                addingValue.itemCount++;
            }
            else
            {
                bool foundBetween = false;
                temp = new Node;
                temp->data = value;
                Node *prev = addingValue.head;
                Node *ptr = addingValue.head->next;

                do
                {
                    if (value > prev->data && value < ptr->data)
                    {
                        prev->next = temp;
                        temp->next = ptr;
                        foundBetween = true;
                    }
                    else
                    {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                } while (foundBetween != true);
                addingValue.itemCount++;
            }
            cout << "Head: " << addingValue.head->data << endl;
            cout << "Tail: " << addingValue.tail->data << endl;
            printf("\nDONE!\n");
        }
    }
}

void searching(List &lookingForTheNode)
{
    if (!create)
    {
        cout << "What are you searching for? There is no list.";
    }
    else if (lookingForTheNode.head == nullptr)
    {
        cout << "Searching an empty list? You won't find anything";
    }
    else
    {
        printf("Searching a value to the LL....\n");
        int value;
        cout << "Tell me the value you are looking for: ";
        cin >> value;

        searchList(lookingForTheNode, value);
    }
}

int main()
{
    int select;
    List SLL;

    while (select != 8)
    {
        cout << "\n\tMenu\n -------------------"
             << "\n 1.) Create"
             << "\n 2.) Add"
             << "\n 3.) Delete"
             << "\n 4.) Search"
             << "\n 5.) Display"
             << "\n 6.) Modify"
             << "\n 7.) Purge"
             << "\n 8.) Exit\n ";
        cin >> select;

        switch (select)
        {
        case 1:
            createList(SLL);
            break;
        case 2:
            add(SLL);
            break;
        case 3:
            remove(SLL);
            break;
        case 4:
            searching(SLL);
            break;
        case 5:
            display(SLL);
            break;
        case 6:
            modify(SLL);
            break;
        case 7:
            purge(SLL);
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "\nPlease enter a valid choice from the menu.\n";
        }
    }
}