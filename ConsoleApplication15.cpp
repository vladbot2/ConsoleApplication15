#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void updateBook(Book& book) {
    cout << "Enter new title: ";
    getline(cin, book.title);
    cout << "Enter new author: ";
    getline(cin, book.author);
    cout << "Enter new publisher: ";
    getline(cin, book.publisher);
    cout << "Enter new genre: ";
    getline(cin, book.genre);
}

void displayBooks(const Book books[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Book " << i + 1 << ": "
            << "Title: " << books[i].title
            << ", Author: " << books[i].author
            << ", Publisher: " << books[i].publisher
            << ", Genre: " << books[i].genre << endl;
    }
}

void findByAuthor(const Book books[], int count, const string& author) {
    for (int i = 0; i < count; ++i) {
        if (books[i].author == author) {
            cout << "Title: " << books[i].title
                << ", Author: " << books[i].author
                << ", Publisher: " << books[i].publisher
                << ", Genre: " << books[i].genre << endl;
        }
    }
}

void findByTitle(const Book books[], int count, const string& title) {
    for (int i = 0; i < count; ++i) {
        if (books[i].title == title) {
            cout << "Title: " << books[i].title
                << " Author: " << books[i].author
                << " Publisher: " << books[i].publisher
                << " Genre: " << books[i].genre << endl;
        }
    }
}

void showMenu() {
    cout << "\nLibrary Menu:\n";
    cout << "1. Edit a book\n";
    cout << "2. Display all books\n";
    cout << "3. Search for a book by author\n";
    cout << "4. Search for a book by title\n";
}

int main() {
    Book library[5] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Novel"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"}
    };

    int choice = 0;
    while (choice != 5) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int index;
            cout << "Enter book number 1-5: ";
            cin >> index;
            cin.ignore();
            if (index >= 1 && index <= 5) {
                updateBook(library[index - 1]);
            }
            else {
                cout << "Invalid book number.\n";
            }
        }

        if (choice == 2) {
            displayBooks(library, 5);
        }

        if (choice == 3) {
            string author;
            cout << "Enter author to search: ";
            getline(cin, author);
            findByAuthor(library, 5, author);
        }

        if (choice == 4) {
            string title;
            cout << "Enter title to search: ";
            getline(cin, title);
            findByTitle(library, 5, title);
        }

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
