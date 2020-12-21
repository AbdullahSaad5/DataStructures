#include <iostream>
using namespace std;

class LinkedList
{
public:
    struct subject
    {
        int marks = 0;
        int id = 0;
        subject *next = nullptr;
    };
    subject *firstsub = nullptr;
    subject *lastsub = nullptr;

    struct stu
    {
        int id = 0;
        int age = 0;
        float avgmarks = 0;
        stu *next = nullptr;
        subject *link = nullptr;
    };
    stu *first = nullptr;
    stu *last = nullptr;

    void addStudent(stu *object)
    {
        if (first == nullptr)
        {
            first = last = object;
        }
        else
        {
            last->next = object;
            last = object;
        }
    }

    LinkedList mergeListsInAscending(LinkedList object)
    {
        LinkedList merged;
        merged = this->mergeLists(object);
        merged.ascending();
        return merged;
    }

    LinkedList mergeLists(LinkedList object)
    {
        LinkedList merge;
        merge.first = this->first;
        merge.last = this->last;
        merge.last->next = object.first;
        merge.last = object.last;
        return merge;
    }

    void ascending()
    {
        LinkedList temp;
        stu *p = this->first;
        while (p != nullptr)
        {
            stu *q = p->next;
            while (q != nullptr)
            {
                if (p->id > q->id)
                {
                    swap(p, q);
                }
                q = q->next;
            }
            p = p->next;
        }
    }

    void swap(stu *p, stu *q)
    {
        stu *temp = new stu;
        //saving values of p
        temp->id = p->id;
        temp->avgmarks = p->avgmarks;
        temp->age = p->age;

        //replacing p with q
        p->id = q->id;
        p->avgmarks = q->avgmarks;
        p->age = q->age;

        //replacing q with
        q->id = temp->id;
        q->avgmarks = temp->avgmarks;
        q->age = temp->age;
    }

    void display()
    {
        stu *p = first;
        int count = 1;
        while (p != nullptr)
        {
            cout << count << ". Id: " << p->id << " Age: " << p->age << " Marks: " << p->avgmarks << endl;
            subject *q = p->link;
            while (q != nullptr)
            {
                cout << count << ". Id: " << q->id << " Marks: " << q->marks << endl;
                q = q->next;
            }
            p = p->next;
            count++;
        }
    }

    void addSubject(subject *object)
    {
        if (firstsub == nullptr)
        {
            firstsub = lastsub = object;
        }
        else
        {
            lastsub->next = object;
            lastsub = object;
        }
    }

    stu *findMax()
    {
        stu *p = first, *q = p;
        int max = p->avgmarks;
        while (p != nullptr)
        {
            if (max < p->avgmarks)
            {
                max = p->avgmarks;
                q = p;
            }
            p = p->next;
        }
        return q;
    }

    int calculateAverage()
    {
        subject *p = firstsub;
        int sum = 0, count = 0;
        while (p != nullptr)
        {
            sum += p->marks;
            count++;
            p = p->next;
        }
        int average = sum / count;
        return average;
    }
};

int main()
{
    LinkedList BSCS_A, BSCS_B, BSCS_C, l1;
    bool infinite_loop = true;
    while (infinite_loop)
    {
        cout << "\nStudent Menu\n"
             << "1. Add Student to BSCS_A\n"
             << "2. Display BSCS_A\n"
             << "3. Add Student to BSCS_B\n"
             << "4. Display BSCS_B\n"
             << "5. Merge Both Classes\n"
             << "6. Display Merged Classes\n"
             << "0. Exit Program\n"
             << "Choice: ";
        int choice;
        int confirm;
        cin >> choice;

        LinkedList::stu *curr;
        LinkedList::subject *subject;
        switch (choice)
        {
        case 1:
            curr = new LinkedList::stu;
            cout << "Add Id: ";
            cin >> curr->id;
            cout << "Add Age: ";
            cin >> curr->age;

            cout << "Do you want to add subject to the student? 1(Yes)/0(No)" << endl;
            cout << "Confirm: ";
            cin >> confirm;
            while (confirm == 1)
            {
                subject = new LinkedList::subject;
                cout << "Subject Id: ";
                cin >> subject->id;
                cout << "Subject Marks: ";
                cin >> subject->marks;
                l1.addSubject(subject);
                curr->link = l1.firstsub;
                cout << "Do you want to continue?" << endl;
                cout << "Confirm: ";
                cin >> confirm;
            }
            curr->avgmarks = l1.calculateAverage();
            BSCS_A.addStudent(curr);
            break;

        case 2:
            BSCS_A.display();
            break;

        case 3:
            curr = new LinkedList::stu;
            cout << "Add Id: ";
            cin >> curr->id;
            cout << "Add Age: ";
            cin >> curr->age;

            cout << "Do you want to add subject to the student? 1(Yes)/0(No)" << endl;
            cout << "Confirm: ";
            cin >> confirm;
            while (confirm == 1)
            {
                subject = new LinkedList::subject;
                cout << "Subject Id: ";
                cin >> subject->id;
                cout << "Subject Marks: ";
                cin >> subject->marks;
                l1.addSubject(subject);
                curr->link = l1.firstsub;
                cout << "Do you want to continue?" << endl;
                cout << "Confirm: ";
                cin >> confirm;
            }
            curr->avgmarks = l1.calculateAverage();

            BSCS_B.addStudent(curr);
            break;

        case 4:
            BSCS_B.display();
            break;

        case 5:
            BSCS_C = BSCS_A.mergeListsInAscending(BSCS_B);
            break;

        case 6:
            BSCS_C.display();
            break;

        case 7:
            curr = BSCS_C.findMax();
            cout << "ID:  " << curr->id << endl;
            cout << "Age: " << curr->age << endl;
            cout << "Highest Marks: " << curr->avgmarks << endl;
        case 0:
            infinite_loop = false;
            break;
        }
    }
}