#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    double price;
    int stock;
};

const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int bookCount = 0;

// functions
void addBook();
void displayBooks();
void searchBook();
void buyBook();
void showSummary();
int findBookByISBN(string isbn);
int findBookByTitle(string title);

int main() {
    int choice;
    do {
        cout << "\n===== BOOKSTORE INVENTORY & SALES SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Buy Book\n";
        cout << "5. Sales Summary\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline in input buffer

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: buyBook(); break;
            case 5: showSummary(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

// adding new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Inventory full!\n";
        return;
    }

    Book b;
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter Price: RM";
    cin >> b.price;
    cout << "Enter Stock Quantity: ";
    cin >> b.stock;
    cin.ignore();

    books[bookCount++] = b;
    cout << "Book added successfully!\n";
}

// displaying the books
void displayBooks() {
    if (bookCount == 0) {
        cout << "No books in inventory.\n";
        return;
    }

    cout << left << setw(15) << "ISBN"
         << setw(30) << "Title"
         << setw(20) << "Author"
         << setw(10) << "Price"
         << setw(10) << "Stock" << endl;
    cout << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << left << setw(15) << books[i].isbn
             << setw(30) << books[i].title
             << setw(20) << books[i].author
             << setw(10) << books[i].price
             << setw(10) << books[i].stock << endl;
    }
}

// search for book
void searchBook() {
    int choice;
    cout << "Search by:\n1. ISBN\n2. Title\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string isbn;
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        int index = findBookByISBN(isbn);
        if (index != -1)
            cout << "Found: " << books[index].title << " by " << books[index].author << " (RM" << books[index].price << ")\n";
        else
            cout << "Book not found.\n";
    } else if (choice == 2) {
        string title;
        cout << "Enter Title: ";
        getline(cin, title);
        int index = findBookByTitle(title);
        if (index != -1)
            cout << "Found: " << books[index].title << " by " << books[index].author << " (RM" << books[index].price << ")\n";
        else
            cout << "Book not found.\n";
    } else {
        cout << "Invalid option.\n";
    }
}

// buying book
void buyBook() {
    string isbn;
    cout << "Enter ISBN of the book to buy: ";
    cin.ignore();
    getline(cin, isbn);

    int index = findBookByISBN(isbn);
    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity > books[index].stock) {
        cout << "Insufficient stock! Only " << books[index].stock << " left.\n";
        return;
    }

    double total = books[index].price * quantity;
    books[index].stock -= quantity;

    cout << "\nTransaction successful!\n";
    cout << "Book: " << books[index].title << "\nQuantity: " << quantity
         << "\nTotal Price: RM" << total << "\n";
}

// summary
void showSummary() {
    cout << "\n===== INVENTORY SUMMARY =====\n";
    for (int i = 0; i < bookCount; i++) {
        cout << books[i].title << " | Stock left: " << books[i].stock << endl;
    }
}

// Helper functions
int findBookByISBN(string isbn) {
    for (int i = 0; i < bookCount; i++)
        if (books[i].isbn == isbn)
            return i;
    return -1;
}

int findBookByTitle(string title) {
    for (int i = 0; i < bookCount; i++)
        if (books[i].title == title)
            return i;
    return -1;
}
