#include<iostream>
using namespace std;

// 🔹 Base Class (Encapsulation)
class Student
{
protected:
    int id;
    string name;
    int marks;
    string course;

public:
    // Setter (Encapsulation)
    void setData()
    {
        cout<<"Enter ID: ";
        cin>>id;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Marks: ";
        cin>>marks;

        cout<<"Enter Course: ";
        cin>>course;
    }

    // Getter / Display
    void display()
    {
        cout<<id<<" "<<name<<" "<<marks<<" "<<course<<endl;
    }

    int getID()
    {
        return id;
    }

    int getMarks()
    {
        return marks;
    }
};



// 🔹 Derived Class (Inheritance)
class StudentSystem : public Student
{
private:
    Student s[10];
    int n = 0;

    // Stack for Undo
    Student stack[10];
    int top = -1;

public:

    // Add Student
    void addStudent()
    {
        s[n].setData();
        n++;
        cout<<"Student Added\n";
    }

    // Display
    void displayStudent()
    {
        cout<<"\nID Name Marks Course\n";
        for(int i=0;i<n;i++)
        {
            s[i].display();
        }
    }

    // Search
    void searchStudent()
    {
        int x;
        cout<<"Enter ID: ";
        cin>>x;

        bool found = false;

        for(int i=0;i<n;i++)
        {
            if(s[i].getID() == x)
            {
                s[i].display();
                found = true;
            }
        }

        if(!found)
        cout<<"Not Found\n";
    }

    // Delete
    void deleteStudent()
    {
        int x;
        cout<<"Enter ID to delete: ";
        cin>>x;

        for(int i=0;i<n;i++)
        {
            if(s[i].getID() == x)
            {
                // push to stack
                top++;
                stack[top] = s[i];

                for(int j=i;j<n-1;j++)
                {
                    s[j] = s[j+1];
                }

                n--;
                cout<<"Deleted\n";
                return;
            }
        }
        cout<<"Not Found\n";
    }

    // Undo Delete
    void undoDelete()
    {
        if(top==-1)
        {
            cout<<"Nothing to Undo\n";
        }
        else
        {
            s[n] = stack[top];
            n++;
            top--;

            cout<<"Undo Done\n";
        }
    }

    // 🔹 Polymorphism (Function Overloading)
    void sortStudent()
    {
        // default descending
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(s[j].getMarks() < s[j+1].getMarks())
                {
                    swap(s[j], s[j+1]);
                }
            }
        }
        cout<<"Sorted Descending\n";
    }

    void sortStudent(bool ascending)
    {
        if(ascending)
        {
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if(s[j].getMarks() > s[j+1].getMarks())
                    {
                        swap(s[j], s[j+1]);
                    }
                }
            }
            cout<<"Sorted Ascending\n";
        }
        else
        {
            sortStudent(); // call default
        }
    }
};



// 🔹 Main Function
int main()
{
    StudentSystem obj;
    int choice;

    do
    {
        cout<<"\n--- Student System ---\n";
        cout<<"1 Add\n2 Display\n3 Search\n4 Delete\n5 Undo\n6 Sort\n7 Exit\n";

        cin>>choice;

        if(choice==1) obj.addStudent();
        else if(choice==2) obj.displayStudent();
        else if(choice==3) obj.searchStudent();
        else if(choice==4) obj.deleteStudent();
        else if(choice==5) obj.undoDelete();
        else if(choice==6)
        {
            int ch;
            cout<<"1 Ascending 2 Descending: ";
            cin>>ch;

            if(ch==1) obj.sortStudent(true);
            else obj.sortStudent();
        }

    }while(choice!=7);

    return 0;
}