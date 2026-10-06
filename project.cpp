/*
 * ====================================================================
 *  PROJECT : Library Management System (C++)
 * ====================================================================
 *  Topics used in this project
 *   1. OOP concepts           -> Library, Book classes (encapsulation)
 *   2. C++ vs C               -> class instead of struct+functions, cin/cout instead of scanf/printf
 *   3. Console I/O            -> cin, cout, getline, setw
 *   4. Variables in C++       -> declared where needed, bool, const, string
 *   5. Reference variables    -> swapValues(), Book &b alias, applyDiscount()
 *   6. Function prototyping   -> all functions declared at top, defined later
 *   7. Function overloading   -> searchBook(int) / searchBook(string)
 *   8. Default arguments      -> addBook(..., price = 250), printLine(ch = '-', n = 60)
 *   9. Inline functions       -> calculateFine(), getters inside the class
 *  10. Classes and objects    -> Library, Book
 *  11. Member functions/data  -> private data + public functions
 *  12. Objects and functions  -> pass object by value / by reference, return object
 *  13. Objects and arrays     -> Book books[MAX_BOOKS]
 *  14. Namespaces             -> Utils, LibraryApp
 *  15. Nested classes         -> Book is nested inside Library
 * ====================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ====================================================================
//  FUNCTION PROTOTYPING  (Topic 6)  +  NAMESPACE (Topic 14)
// ====================================================================
namespace Utils {
    // Default arguments (Topic 8): defaults are given only in the prototype
    void printLine(char ch = '-', int length = 60);
    void printTitle(const string &text);
    // Reference variables (Topic 5): swap without pointers
    void swapValues(int &a, int &b);
}

namespace LibraryApp {

    const int   MAX_BOOKS    = 50;     // Variables: const
    const float FINE_PER_DAY = 2.5f;

    // Inline function (Topic 9): small function, body expanded at call site
    inline float calculateFine(int daysLate) {
        return (daysLate > 0) ? daysLate * FINE_PER_DAY : 0.0f;
    }

    // ================================================================
    //  CLASS (Topics 1, 10, 11)
    // ================================================================
    class Library {
    public:
        // ------------------------------------------------------------
        //  NESTED CLASS (Topic 15): Book lives inside Library
        // ------------------------------------------------------------
        class Book {
        private:                       // member data (Topic 11)
            int    id;
            string title;
            string author;
            float  price;
            bool   issued;

        public:
            Book() : id(0), title(""), author(""), price(0.0f), issued(false) {}

            void setBook(int i, const string &t, const string &a, float p) {
                id = i; title = t; author = a; price = p; issued = false;
            }

            // Inline member functions (defined inside the class)
            int    getId()     const { return id; }
            string getTitle()  const { return title; }
            float  getPrice()  const { return price; }
            bool   isIssued()  const { return issued; }
            void   setPrice(float p) { price = p; }
            void   setIssued(bool s) { issued = s; }

            // Member function defined outside the class (see below)
            void display() const;
        };

    private:
        Book books[MAX_BOOKS];         // OBJECTS AND ARRAYS (Topic 13)
        int  count;

    public:
        Library() : count(0) {}

        // Default argument: price is optional
        bool addBook(const string &title, const string &author, float price = 250.0f);

        // FUNCTION OVERLOADING (Topic 7): same name, different parameters
        int searchBook(int id) const;
        int searchBook(const string &title) const;

        void issueBook(int id);
        void returnBook(int id, int daysLate = 0);
        void displayAll() const;
        Book &getBookAt(int index) { return books[index]; }   // returns a reference
        int  getCount() const { return count; }
    };

} // namespace LibraryApp

// Short alias so the code below stays readable
using LibraryApp::Library;
using Book = LibraryApp::Library::Book;

// Prototypes of ordinary functions
void showMenu();
void conceptsDemo();
Book makeDiscounted(Book b, float percent);        // object passed BY VALUE, returned
void applyDiscount(Book &b, float percent);        // object passed BY REFERENCE
void addBookFromUser(Library &lib);

// ====================================================================
//  main()
// ====================================================================
int main() {
    Library lib;                       // object of class Library

    // Pre-load some books. Third argument omitted -> default price used
    lib.addBook("C++ Primer", "Lippman");
    lib.addBook("Let Us C", "Kanetkar", 350.0f);
    lib.addBook("Data Structures", "Tanenbaum", 420.0f);

    int choice;
    do {
        showMenu();
        cin >> choice;                 // Console input
        cin.ignore();                  // clear newline

        switch (choice) {
            case 1:
                addBookFromUser(lib);
                break;
            case 2:
                lib.displayAll();
                break;
            case 3: {                  // overloaded search by ID
                int id;
                cout << "Enter book ID: ";
                cin >> id;
                int pos = lib.searchBook(id);
                if (pos >= 0) lib.getBookAt(pos).display();
                else cout << "Book not found.\n";
                break;
            }
            case 4: {                  // overloaded search by title
                string t;
                cout << "Enter title (or part of it): ";
                getline(cin, t);
                int pos = lib.searchBook(t);
                if (pos >= 0) lib.getBookAt(pos).display();
                else cout << "Book not found.\n";
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to issue: ";
                cin >> id;
                lib.issueBook(id);
                break;
            }
            case 6: {
                int id, late;
                cout << "Enter book ID to return: ";
                cin >> id;
                cout << "Days late (0 if on time): ";
                cin >> late;
                lib.returnBook(id, late);
                break;
            }
            case 7: {                  // objects and functions
                int id; float percent;
                cout << "Enter book ID: ";
                cin >> id;
                cout << "Discount percent: ";
                cin >> percent;
                int pos = lib.searchBook(id);
                if (pos < 0) { cout << "Book not found.\n"; break; }

                Book &b = lib.getBookAt(pos);          // reference = alias, no copy
                Book preview = makeDiscounted(b, percent); // by value: original unchanged
                cout << "Preview price (original untouched): " << preview.getPrice() << endl;
                applyDiscount(b, percent);             // by reference: original changed
                cout << "New price saved: " << b.getPrice() << endl;
                break;
            }
            case 8:
                conceptsDemo();
                break;
            case 0:
                cout << "Thank you!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

// ====================================================================
//  FUNCTION DEFINITIONS
// ====================================================================

// ---- Namespace Utils ----
void Utils::printLine(char ch, int length) {
    for (int i = 0; i < length; i++) cout << ch;   // variable declared inside for
    cout << endl;
}

void Utils::printTitle(const string &text) {
    printLine('=');
    cout << "  " << text << endl;
    printLine('=');
}

void Utils::swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ---- Class Library member functions (defined outside class using ::) ----
void LibraryApp::Library::Book::display() const {
    cout << left << setw(8) << id
         << setw(22) << title
         << setw(14) << author
         << setw(8)  << price
         << (issued ? "Issued" : "Available") << endl;
}

bool LibraryApp::Library::addBook(const string &title, const string &author, float price) {
    if (count >= LibraryApp::MAX_BOOKS) {
        cout << "Library is full!\n";
        return false;
    }
    books[count].setBook(1001 + count, title, author, price);
    count++;
    return true;
}

int LibraryApp::Library::searchBook(int id) const {
    for (int i = 0; i < count; i++)
        if (books[i].getId() == id) return i;
    return -1;
}

int LibraryApp::Library::searchBook(const string &title) const {
    for (int i = 0; i < count; i++)
        if (books[i].getTitle().find(title) != string::npos) return i;
    return -1;
}

void LibraryApp::Library::issueBook(int id) {
    int pos = searchBook(id);
    if (pos < 0) { cout << "Book not found.\n"; return; }

    Book &b = books[pos];              // reference variable (alias of the array element)
    if (b.isIssued()) cout << "Already issued.\n";
    else { b.setIssued(true); cout << "Book issued successfully.\n"; }
}

void LibraryApp::Library::returnBook(int id, int daysLate) {
    int pos = searchBook(id);
    if (pos < 0) { cout << "Book not found.\n"; return; }

    Book &b = books[pos];
    if (!b.isIssued()) { cout << "This book was not issued.\n"; return; }

    b.setIssued(false);
    float fine = LibraryApp::calculateFine(daysLate);   // inline function call
    cout << "Book returned. Fine = Rs. " << fine << endl;
}

void LibraryApp::Library::displayAll() const {
    Utils::printTitle("ALL BOOKS");
    cout << left << setw(8) << "ID" << setw(22) << "Title"
         << setw(14) << "Author" << setw(8) << "Price" << "Status\n";
    Utils::printLine();
    for (int i = 0; i < count; i++) books[i].display();
    Utils::printLine();
}

// ---- Objects and functions ----
Book makeDiscounted(Book b, float percent) {   // receives a COPY
    b.setPrice(b.getPrice() - b.getPrice() * percent / 100);
    return b;                                  // returns an object
}

void applyDiscount(Book &b, float percent) {   // receives the ORIGINAL
    b.setPrice(b.getPrice() - b.getPrice() * percent / 100);
}

// ---- Console I/O ----
void addBookFromUser(Library &lib) {
    string title, author;
    float price;
    char hasPrice;

    cout << "Title : ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "Do you want to enter price? (y/n): ";
    cin >> hasPrice;

    bool ok;
    if (hasPrice == 'y' || hasPrice == 'Y') {
        cout << "Price : ";
        cin >> price;
        ok = lib.addBook(title, author, price);
    } else {
        ok = lib.addBook(title, author);       // default price used
    }
    if (ok) cout << "Book added.\n";
}

void showMenu() {
    cout << endl;
    Utils::printTitle("LIBRARY MANAGEMENT SYSTEM");
    cout << "1. Add book\n"
         << "2. Display all books\n"
         << "3. Search by ID        (overload 1)\n"
         << "4. Search by title     (overload 2)\n"
         << "5. Issue book\n"
         << "6. Return book (fine)\n"
         << "7. Apply discount      (by value vs by reference)\n"
         << "8. Concepts demo\n"
         << "0. Exit\n"
         << "Enter choice: ";
}

// ---- Small demo of basic concepts, handy for the presentation ----
void conceptsDemo() {
    Utils::printTitle("CONCEPTS DEMO");

    // Variables + reference variable
    int x = 10;
    int &ref = x;                      // ref is another name for x
    ref = 20;
    cout << "Reference: x = " << x << " (changed through ref)\n";

    // Reference used for swapping
    int a = 5, b = 9;
    cout << "Before swap: a=" << a << " b=" << b << endl;
    Utils::swapValues(a, b);
    cout << "After  swap: a=" << a << " b=" << b << endl;

    // Default arguments
    cout << "printLine() with defaults:\n";
    Utils::printLine();
    cout << "printLine('*', 20) with custom values:\n";
    Utils::printLine('*', 20);

    // Inline function
    cout << "Fine for 4 days late = " << LibraryApp::calculateFine(4) << endl;

    // Objects and arrays
    Book demo[2];
    demo[0].setBook(1, "Demo A", "Author A", 100);
    demo[1].setBook(2, "Demo B", "Author B", 200);
    cout << "Array of Book objects:\n";
    for (int i = 0; i < 2; i++) demo[i].display();
}