#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Database
{
private:
    string name, div, add, rno;
    fstream f;

public:
    Database()
    {
        f.open("StudentsDatabase.txt", fstream::app);
        if (!f.is_open())
        {
            cout << "Error Occurred while creating file" << endl;
        }
        f.close();
    }

    void insertRecord()
    {
        f.open("StudentsDatabase.txt", fstream::app);
        cout << "Enter Student's Name = ";
        getline(cin, name);
        getline(cin, name);
        cout << "Enter Student's Roll No = ";
        getline(cin, rno);
        cout << "Enter Student's Division = ";
        getline(cin, div);
        cout << "Enter Student's Address = ";
        getline(cin, add);

        f << rno + "," + name + "," + div + "," + add + "\n";
        f.close();

        cout << "\nStudent Record inserted Successfully !!!" << endl;
    }

    void searchRecord()
    {
        f.open("StudentsDatabase.txt", fstream::in);
        string key, rec;
        int flag = 0;
        string r[4];
        cout << "--------------[ Search Record ]--------------" << endl;
        cout << "\nEnter Student's Roll No to Search = ";
        cin >> key;
        while (getline(f, rec))
        {
            string nrec = "";
            for (int i = 0; i < rec.length(); i++)
            {
                if (rec[i] == ',')
                {
                    for (int o = 0; o < i; o++)
                    {
                        nrec += rec[o];
                    }
                    break;
                }
            }
            if (nrec == key)
            {
                cout << "\nStudent Record Found : " << rec << "\n"
                     << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\nStudent Record not found !!!\n"
                 << endl;
        }
        f.close();
    }

    void deleteRecord()
    {
        string key, rec;
        int flag = 0, c = 0;
        cout << "Enter Student Roll No to delete Record = ";
        cin >> key;

        f.open("StudentsDatabase.txt", fstream::in);
        fstream nf("temp.txt", fstream::out);

        while (getline(f, rec))
        {
            string nrec = "";
            for (int i = 0; i < rec.length(); i++)
            {
                if (rec[i] == ',')
                {
                    for (int o = 0; o < i; o++)
                    {
                        nrec += rec[o];
                    }
                    if (nrec == key)
                    {
                        flag = 1;
                        cout << "\nRecord Deleted Successfully !!!" << endl;
                    }
                    else
                    {
                        nf << rec + "\n";
                    }
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << "\nStudent Record Not Found !!!" << endl;
        }
        nf.close();
        f.close();

        f.open("StudentsDatabase.txt", fstream::out);
        fstream nf1("temp.txt", fstream::in);
        while (getline(nf1, rec))
        {
            f << rec + "\n";
        }
        f.close();
        nf1.close();
    }

    void displayRecords()
    {
        f.open("StudentsDatabase.txt", fstream::in);
        string rec;
        int i = 1;
        cout << "--------------[ Student Records ]--------------" << endl;
        while (getline(f, rec))
        {
            cout << "\nStudent " << i << " Records : " << rec << endl;
            i++;
        }
        f.close();
    }
};

int main()
{
    int ch;
    Database d;
MENU:
    cout << "--------------[ Student Management ]--------------" << endl;
    cout << "\n0.Exit\n1.Insert Record\n2.Search Record\n3.Delete Record\n4.Display All Records\n\nEnter Your Choice = ";
    cin >> ch;
    switch (ch)
    {
    case 0:
        break;
    case 1:
        d.insertRecord();
        goto MENU;
    case 2:
        d.searchRecord();
        goto MENU;
    case 3:
        d.deleteRecord();
        goto MENU;
    case 4:
        d.displayRecords();
        goto MENU;
    default:
        cout << "Invalid Input !!!" << endl;
        goto MENU;
    }
}