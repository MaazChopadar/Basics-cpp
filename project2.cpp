/*
 * PROJECT: Student Report Card System (C++)
 * Topics: OOP, C++ vs C, Console I/O, Variables, Reference variables,
 *         Function prototyping, Overloading, Default arguments, Inline
 *         functions, Classes & objects, Member functions/data,
 *         Objects & functions, Objects & arrays, Namespaces, Nested classes
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ---------- Namespace + Function prototypes + Default arguments ----------
namespace Utils {
    void printLine(char ch = '-', int n = 45);   // defaults only in prototype
    void swapValues(int &a, int &b);             // reference variables
}

namespace School {
    const int MAX = 20;                          // const variable

    // Inline functions: tiny, expanded at the call site
    inline float average(int total, int subjects = 3) { return (float)total / subjects; }
    inline char grade(float p) { return p >= 75 ? 'A' : p >= 50 ? 'B' : p >= 35 ? 'C' : 'F'; }

    // ---------- Class (OOP: data + functions together) ----------
    class Classroom {
    public:
        // ---------- Nested class ----------
        class Student {
        private:                                 // member data
            int roll;
            string name;
            int marks[3];
        public:
            Student() : roll(0), name("") { for (int i = 0; i < 3; i++) marks[i] = 0; }

            void set(int r, const string &n, int m1, int m2, int m3) {
                roll = r; name = n; marks[0] = m1; marks[1] = m2; marks[2] = m3;
            }
            int    getRoll() const { return roll; }          // inline member functions
            string getName() const { return name; }
            int    total()   const { return marks[0] + marks[1] + marks[2]; }
            void   addGrace(int g) {
                for (int i = 0; i < 3; i++) marks[i] = (marks[i] + g > 100) ? 100 : marks[i] + g;
            }
            void display() const;                        // defined outside the class
        };

    private:
        Student list[MAX];                               // Objects and arrays
        int count;

    public:
        Classroom() : count(0) {}
        void addStudent(const string &name, int m1, int m2, int m3);
        int  find(int roll) const;                       // Function overloading
        int  find(const string &name) const;
        Student &at(int i) { return list[i]; }
        int  size() const { return count; }
        void showAll() const;
    };
}

using Student = School::Classroom::Student;

// ---------- Prototypes of normal functions ----------
Student better(Student a, Student b);              // objects passed by value
void giveGrace(Student &s, int grace = 5);         // object passed by reference + default arg
void addFromUser(School::Classroom &c);

// ---------- main ----------
int main() {
    School::Classroom room;
    room.addStudent("Asha", 80, 70, 90);
    room.addStudent("Ravi", 45, 60, 30);

    int choice;
    do {
        Utils::printLine('=');
        cout << "1.Add  2.Show all  3.Find by roll  4.Find by name\n"
             << "5.Grace marks  6.Topper  7.Swap demo  0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) addFromUser(room);
        else if (choice == 2) room.showAll();
        else if (choice == 3) {
            int r; cout << "Roll: "; cin >> r;
            int p = room.find(r);                      // calls find(int)
            if (p >= 0) room.at(p).display(); else cout << "Not found\n";
        }
        else if (choice == 4) {
            string n; cout << "Name: "; getline(cin, n);
            int p = room.find(n);                      // calls find(string)
            if (p >= 0) room.at(p).display(); else cout << "Not found\n";
        }
        else if (choice == 5) {
            int r; cout << "Roll: "; cin >> r;
            int p = room.find(r);
            if (p >= 0) { giveGrace(room.at(p)); room.at(p).display(); }  // default grace = 5
            else cout << "Not found\n";
        }
        else if (choice == 6 && room.size() > 0) {
            Student top = room.at(0);
            for (int i = 1; i < room.size(); i++) top = better(top, room.at(i));
            cout << "Topper: "; top.display();
        }
        else if (choice == 7) {
            int a = 10, b = 20;
            cout << "Before: " << a << " " << b << endl;
            Utils::swapValues(a, b);
            cout << "After : " << a << " " << b << endl;
        }
    } while (choice != 0);
    return 0;
}

// ---------- Definitions ----------
void Utils::printLine(char ch, int n) { for (int i = 0; i < n; i++) cout << ch; cout << endl; }

void Utils::swapValues(int &a, int &b) { int t = a; a = b; b = t; }

void School::Classroom::Student::display() const {
    float avg = School::average(total());              // inline + default argument
    cout << setw(4) << roll << setw(10) << name << setw(6) << total()
         << setw(8) << fixed << setprecision(1) << avg << "  Grade " << School::grade(avg) << endl;
}

void School::Classroom::addStudent(const string &name, int m1, int m2, int m3) {
    if (count < MAX) { list[count].set(count + 1, name, m1, m2, m3); count++; }
    else cout << "Class full\n";
}

int School::Classroom::find(int roll) const {
    for (int i = 0; i < count; i++) if (list[i].getRoll() == roll) return i;
    return -1;
}

int School::Classroom::find(const string &name) const {
    for (int i = 0; i < count; i++) if (list[i].getName() == name) return i;
    return -1;
}

void School::Classroom::showAll() const {
    Utils::printLine();
    for (int i = 0; i < count; i++) list[i].display();
    Utils::printLine();
}

Student better(Student a, Student b) { return (a.total() >= b.total()) ? a : b; }

void giveGrace(Student &s, int grace) { s.addGrace(grace); }

void addFromUser(School::Classroom &c) {
    string name; int m1, m2, m3;
    cout << "Name: "; getline(cin, name);
    cout << "Marks in 3 subjects: "; cin >> m1 >> m2 >> m3;
    c.addStudent(name, m1, m2, m3);
}