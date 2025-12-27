#include <iostream>
#include <string>
using namespace std;

struct Ticket
{

    //associating with algorithm 
    int TicketID;
    string ReportName;
    int Priority;

    //information only
    string Location;
    string Category;
    string Description;
    string CreatedTime;
    string Status;

};

//define node
struct Node
{
    Ticket data;
    Node* next = nullptr;

};


class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;//initialize head ptr empty
    }


    //----------------------------ÉÏÃæ´úÂë¶¼²»Òª¶¯£¬DONT NOT change above code------------------------------


    void TestDataSet()//·½±ã²âÊÔÓÃµÄÊý¾Ý£¬±£Áô£¬  original test dataset, keep
    {
        Ticket t1;
        t1.TicketID = 6;
        t1.ReportName = "Alice";
        t1.Priority = 3;
        t1.Location = "Lab3";
        t1.Category = "Network";
        t1.Description = "Internet connection unstable";
        t1.CreatedTime = "2025-01-01";
        t1.Status = "Open";
        InsertSorted(t1);

        Ticket t2;
        t2.TicketID = 1;
        t2.ReportName = "Bob";
        t2.Priority = 5;
        t2.Location = "Library";
        t2.Category = "Facilities";
        t2.Description = "Air-conditioner not working";
        t2.CreatedTime = "2025-01-02";
        t2.Status = "In Progress";
        InsertSorted(t2);

        Ticket t3;
        t3.TicketID = 7;
        t3.ReportName = "Carol";
        t3.Priority = 2;
        t3.Location = "LectureHall";
        t3.Category = "Equipment";
        t3.Description = "Projector flickering";
        t3.CreatedTime = "2025-01-03";
        t3.Status = "In Progress";
        InsertSorted(t3);

        Ticket t4;
        t4.TicketID = 4;
        t4.ReportName = "David";
        t4.Priority = 4;
        t4.Location = "Office";
        t4.Category = "Network";
        t4.Description = "Cannot access system";
        t4.CreatedTime = "2025-01-04";
        t4.Status = "Resolved";
        InsertSorted(t4);
    }

    //2. For new ticket insertion, insert ticket in sorted order by Ticket ID(ascending).  
    //¸ù¾ÝIDÉýÐòÅÅÐò

    void InsertSorted(Ticket newTicket)//finished , DO NOT modify£¬  ÒÑ¾­Íê³É,·Ç±ØÒª²»ÐÞ¸Ä
    {
        Node* newNode = new Node;
        newNode->data = newTicket;


        //empty head or ID smaller than head ,  use head insert
        // Í·Ö¸ÕëÎª¿Õ »òÕßÐ¡ÓÚnodeÀïµÄÔªËØ
        if (head == nullptr || newTicket.TicketID <= head->data.TicketID)
        {
            newNode->next = head;
            head = newNode;
            return;
        }


        //Ë«Ö¸Õë±È½Ï²åÈë£¬two ptrs insert
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && newTicket.TicketID > curr->data.TicketID)
        {
            prev = curr;
            curr = curr->next;

        }

        //change ptrs
        newNode->next = curr;
        prev->next = newNode;


    }



    // 3. For ticket deletion, remove by Ticket ID
    //¸ù¾ÝIDÀ´É¾³ý
    void Delete(int targetID) //-----------ÒÑ¾­Íê³É,·Ç±ØÒª²»ÒªÐÞ¸Ä
    {

        //head empty
        if (head == nullptr)
        {
            cout << "The linked list is empty.\n" << endl;
            return;
        }


        //if head is to be deleted
        if (targetID == head->data.TicketID)
        {
            Node* temp = head;//temp´æ´¢head
            head = head->next;
            delete temp;

            cout << "Head node is deleted, the deleted Ticket ID is " << targetID << endl;
            return;

        }

        //-------------delete middle node------------

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data.TicketID != targetID)//²»¿Õ£¬²»Í¬Ö±½ÓÍùºóÕÒ
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)//Ã»ÕÒµ½
        {
            cout << "The ticket is not found." << endl;
            return;

        }

        //ÕÒµ½ÁË£¬É¾³ý½Úµã
        prev->next = curr->next;
        delete curr;

        cout << "The deleted ticket ID is " << targetID << endl;
    }


    //Part B:  search by Ticket ID or reporter name
    //Part B:  search by Ticket ID or reporter name
    void SearchByID(int targetID) //sequential search  ÒÑ¾­Íê³É£¬²»ÒªÐÞ¸Ä
    {
        Node* temp = head;

        while (temp != nullptr && temp->data.TicketID != targetID)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "This ticket does not exist.";
            return;
        }

        if (temp->data.TicketID == targetID)
        {
            cout << "The ticket is founded.\n";

            cout << "The Ticket ID is: " << targetID << endl;
            cout << "The reporter name is: " << temp->data.ReportName << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;
            cout << "Status: " << temp->data.Status << endl;
        }

    }


    void SearchByName(string reportName)//sequential search  ÒÑ¾­Íê³É£¬²»ÒªÐÞ¸Ä
    {
        Node* temp = head;


        while (temp != nullptr && temp->data.ReportName != reportName)
        {
            temp = temp->next;

        }


        if (temp == nullptr)
        {
            cout << "This ticket does not exist.";
            return;

        }

        if (temp->data.ReportName == reportName)
        {
            cout << "The ticket is founded.\n";
            cout << "The reporter name is: " << reportName << endl;
            cout << "The Ticket ID is: " << temp->data.TicketID << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;
            cout << "Status: " << temp->data.Status << endl;
        }
    }


    //Part C: 1. Sort tickets by Priority (descending)  Êý×ÖÔ½´óÔ½ÖØÒª   2. Sort tickets by Reporter Name (ascending)
    //Part C: 1. Sort tickets by Priority (descending)  Êý×ÖÔ½´óÔ½ÖØÒª   2. Sort tickets by Reporter Name (ascending)
    void SortByPriority() //Desc     
    {
        if (head == nullptr)
    {
        cout << "No tickets available.\n";
        return;
    }

    // 1. Copy data from linked list to array
    Ticket arr[100];
    int count = 0;

    Node* curr = head;
    while (curr != nullptr)
    {
        arr[count++] = curr->data;
        curr = curr->next;
    }

    // 2. Selection sort by Priority (Descending)
    for (int i = 0; i < count - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j].Priority > arr[maxIndex].Priority)
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            Ticket temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }

    // 3. Display result
    cout << "\n[Report: Sort by Priority (Descending)]\n";
    for (int i = 0; i < count; i++)
    {
        cout << "ID: " << arr[i].TicketID
             << ", Name: " << arr[i].ReportName
             << ", Priority: " << arr[i].Priority
             << endl;
    }


    }


    void SortByName()//Asc
    {
       
         if (head == nullptr)
    {
        cout << "No tickets available.\n";
        return;
    }

    // 1. Copy data from linked list to array
    Ticket arr[100];
    int count = 0;

    Node* curr = head;
    while (curr != nullptr)
    {
        arr[count++] = curr->data;
        curr = curr->next;
    }

    // 2. Selection sort by ReportName (Ascending A-Z)
    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j].ReportName < arr[minIndex].ReportName)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            Ticket temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // 3. Display result
    cout << "\n[Report: Sort by Reporter Name (Ascending)]\n";
    for (int i = 0; i < count; i++)
    {
        cout << "ID: " << arr[i].TicketID
             << ", Name: " << arr[i].ReportName
             << ", Priority: " << arr[i].Priority
             
             << endl;
    }
    }






    //Part D: Undo Feature(Stack)

    //Action type for actions that are undoable
    enum ActionType {
        ADD,
        DELETE,
        UPDATE
    };

    //Action structure with action types and backup ticket
    struct Action {
        ActionType type;
        Ticket ticketBackup;
        int ticketID;
        string oldStatus;
    };

    // Linked List Implementation of STACK
    class StackNode {
    public:
        Action data;
        StackNode* next;
    };

    class ActionStack {
    private:
        StackNode* top;

    public:
        ActionStack() {
            top = nullptr;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        void push(Action a) {
            StackNode* newNode = new StackNode;
            if (newNode == nullptr)
                cout << "Cannot allocate memory.\n";
            else {
                newNode->data = a;
                newNode->next = top;
                top = newNode;
            }
        }

        Action pop() {

            StackNode* temp = top;
            Action a = temp->data;
            top = temp->next;
            delete temp;
            return a;
        }
    };

    ActionStack undoStack; //Undo Stack that stack action objects

    //Add action±»UNDOµÄÊ±ºò, ¾ÍÊÇdelete±»Ìí¼ÓµÄticket
    //ËùÒÔ AddTicketUndo function°ÑÕâ¸öaction type´æ½østack
    //When undo function run, action type = ADD, lead to delete ticket
    void AddTicketUndo(Ticket t) //push add action into undo stack
    {
        InsertSorted(t);

        Action add_act; //create an action object for add action
        add_act.type = ADD;
        add_act.ticketBackup = t;

        undoStack.push(add_act);
    }

    //Delete action ±»UNDOµÄÊ±ºò, ¾ÍÊÇ°ÑÉ¾µôµÄticket¼Ó»ØÈ¥
    //ËùÒÔ DeleteTicketUndo function°ÑÕâ¸öaction type´æ½østack
    //When undo function run, action type = DELETE, lead to add ticket WITH backup ticket data

    bool BackupTicket(int id, Ticket& backup) //±¸·Ýticket data, when undo, copy to add back
    {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.TicketID == id) {
                backup = temp->data;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void DeleteTicketUndo(int id) //push delete action into undo stack
    {
        Ticket backup;
        //backup deleted ticket
        if (!BackupTicket(id, backup)) {
            cout << "Ticket not found. Backup unsuccessful.\n";
            return;
        }

        Delete(id);
        Action d_act;       //create an action object for delete action
        d_act.type = DELETE;
        d_act.ticketBackup = backup; //copy backup data 
        undoStack.push(d_act);
    }

    Node* FindNode(int id)
    {
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->data.TicketID == id)
            return curr;
        curr = curr->next;
    }
    return nullptr;
    }

    void UpdateTicketUndo(int id, string newStatus)
    {
    Node* node = FindNode(id);
    if (node == nullptr)
    {
        cout << "Ticket not found.\n";
        return;
    }

    Action act;
    act.type = UPDATE;
    act.ticketID = id;
    act.oldStatus = node->data.Status;   // save old status

    undoStack.push(act);   // your own stack implementation

    node->data.Status = newStatus;
    cout << "Ticket status updated.\n";
    }

    void Undo() {

        if (undoStack.isEmpty()) {
            cout << "No action to undo.\n";
            return;
        }

        Action last = undoStack.pop();

        if (last.type == ADD)
        {
            Delete(last.ticketBackup.TicketID); // Undo Add Ticket = Delete added Ticket
            cout << "Successfully undo Add action.\n";
        }
        else if (last.type == DELETE)
        {
            InsertSorted(last.ticketBackup);    // Undo Delete Ticket = Add back Ticket
            cout << "Successfully undo Delete action.\n";
        }
        else if (last.type == UPDATE)
        {
            Node* node = FindNode(last.ticketID);
    		if (node != nullptr)
    		{
        	node->data.Status = last.oldStatus;
        	cout << "Successfully undo Update action.\n";
    		}
		}
    }


    void Display()//Finished , DON NOT  modify,Íê³É,¿ÉÄÜºóÐøÒªÐÞ¸Ä
    {

        Node* temp = head;

        cout << "-----------Information---------" << endl;

        if (head == nullptr)
        {
            cout << "There is no information." << endl;
        }

        while (temp != nullptr)//Êä³öIDºÍÃû×Ö
        {
            cout << "Ticket ID: " << temp->data.TicketID << endl;
            cout << "Name: " << temp->data.ReportName << endl;
            cout << "Priority: " << temp->data.Priority << endl;
            cout << "The location is: " << temp->data.Location << endl;
            cout << "The Problem Category is: " << temp->data.Category << endl;
            cout << "Problem Description: " << temp->data.Description << endl;
            cout << "Ticket Created Time: " << temp->data.CreatedTime << endl;
            cout << "Status: " << temp->data.Status << endl;
            temp = temp->next;
            cout << "------------------------------" << endl;

        }

    }


};


int main()

{
    LinkedList system;

    system.TestDataSet();

    int choice;

    do
    {
        cout << "\n===== Campus Report System =====\n";
        cout << "1. Add ticket\n";
        cout << "2. Delete ticket\n";
        cout << "3. Search ticket\n";
        cout << "4. Update ticket status\n";
        cout << "5. Display all tickets\n";
        cout << "6. Generate report(Sort)\n";
        cout << "7. Undo last action\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
            // ================= ADD =================
        case 1:
        {
            int sub;
            do {
                cout << "\n[Add Ticket]\n";
                cout << "1. Add new ticket\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    Ticket t;
                    cout << "Enter Ticket ID: ";
                    cin >> t.TicketID;
                    cout << "Enter Reporter Name: ";
                    cin >> t.ReportName;
                    cout << "Enter the Prioriry:";
                    cin >> t.Priority;
                    cin.ignore();
                  
                    cout << "Enter the Location: ";
                     getline(cin, t.Location);

                     cout << "Enter the Category: ";
                     getline(cin, t.Category);

                      cout << "Enter the Description: ";
                     getline(cin, t.Description); 

                     cout << "Enter the Time: ";
                      getline(cin, t.CreatedTime);

                       cout << "Enter the Status: ";
                      getline(cin, t.Status);

                    system.AddTicketUndo(t);
                     cout << "\nTicket added successfully!\n";

                    //´ÓInsertSorted()»»³ÉÕâ¸öÒòÎªÒª¼ÇÂ¼add action in undo stack
                    system.AddTicketUndo(t);
                    cout << endl;
                }
                if (sub !=1 && sub !=0)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);
            break;
        }

        // ================= DELETE =================
        case 2:
        {
            int sub;
            do {
                cout << "\n[Delete Ticket]\n";
                cout << "1. Delete by Ticket ID\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    cout << "Enter Ticket ID to delete: ";
                    cin >> id;

                    //´ÓDelete()»»³ÉÕâ¸öÒòÎªÒª¼ÇÂ¼delete action in undo stack & backup ticket data
                    system.DeleteTicketUndo(id);
                    cout << endl;
                }
                if (sub !=1 && sub !=0)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);
            break;
        }

        // ================= SEARCH =================
        case 3:
        {
            int sub;
            do {
                cout << "\n[Search Ticket]\n";
                cout << "1. Search by Ticket ID\n";
                cout << "2. Search by Report Name\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    cout << "Enter Ticket ID to search: ";
                    cin >> id;

                    system.SearchByID(id);

                }

                if (sub == 2) {
                    string name;
                    cout << "Enter Report Name to search: ";
                    cin >> name;

                    system.SearchByName(name);
                }
                if (sub != 1 && sub != 0 && sub != 2)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);
            break;
        }

        // ================= UPDATE STATUS =================
        case 4:
        {
            int sub;
            do {
                cout << "\n[Update Ticket Status]\n";
                cout << "1. Update status by Ticket ID\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    int id;
                    string status;
                    cout << "Enter Ticket ID: ";
                    cin >> id;
                    cout << "Enter new status: ";
                    cin.ignore();
					getline(cin, status);

                   	system.UpdateTicketUndo(id, status);
					cout << endl;
                }
                
                if (sub !=1 && sub !=0)
                   cout << "Please enter a valid choice.";
                cout << endl; 
            } while (sub != 0);
            break;
        }

        // ================= DISPLAY =================
        case 5:
        {
            int sub;
            do {
                cout << "\n[Display Tickets]\n";
                cout << "1. Display all tickets\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    system.Display();
                }
                if (sub !=1 && sub !=0)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);
            break;
        }

        // ================= REPORT =================
        case 6:
        {
            int sub;
            do {
                cout << "\n[Generate Report]\n";
                cout << "1. Sort by Priority (Top urgent tickets)\n";
                cout << "2. Sort by Requester name\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {             //Õâ±ßÒª¼ÓÈëÅÅÐò¹¦ÄÜ
                    // TODO: ¶ÓÓÑÊµÏÖ
                    system.SortByPriority();
                   // system.Display();
                    
                }
                else if (sub == 2) {
                    // TODO: ¶ÓÓÑÊµÏÖ        //Õâ±ßÒª¼ÓÈëÅÅÐò¹¦ÄÜ
                    system.SortByName();
                    //system.Display();
                }
                if (sub !=1 && sub !=0 && sub != 2)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);

            break;
        }


        // ================= UNDO =================
        case 7:
        {
            int sub;
            do {
                cout << "\n[Undo Last Action]\n";
                cout << "1. Undo\n";
                cout << "0. Back to main menu\n";
                cout << "Choose: ";
                cin >> sub;

                if (sub == 1) {
                    system.Undo(); //Undo last action in the stack

                }
                if (sub !=1 && sub !=0)
                   cout << "Please enter a valid choice.";
                cout << endl; 

            } while (sub != 0);
            break;
        }

        case 0:
            cout << "Exit system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}