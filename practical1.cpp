#include <iostream> 
#include <string> 
using namespace std; 
 
// Class to represent a Book object 
class Book { 
public: 
    int bookID; 
    string title;
    string author; 
    int copies;       // number of copies available 
 
    // Default Constructor 
    Book() { 
        bookID = 0; 
        title = ""; 
        author = ""; 
        copies = 0; 
    } 
 
    // Parameterized Constructor 
    Book(int id, string t, string a, int c) { 
        bookID = id; 
        title = t; 
        author = a; 
        copies = c; 
    } 
}; 
 
// Class to manage the Library database with array 
class LibraryManagement { 
private: 
    Book books[100];  // Fixed size array to hold books (max 100) 
    int bookCount;    // Number of books currently stored 
 
public: 
    // Constructor initializes book count to zero 
    LibraryManagement() { 
        bookCount = 0; 
    } 
 
    // Helper function to check if Book ID already exists 
    bool isBookIDExist(int id) { 
        for (int i = 0; i < bookCount; i++) { 
            if (books[i].bookID == id) { 
                return true; 
            } 
        } 
        return false; 
    } 
 
    // Function to insert a new book into the array 
    void insertBook() { 
        if (bookCount >= 100) { 
            cout << "Library database is full. Cannot add more books.\n"; 
            return; 
        } 
 
        int id, c; 
        string t, a; 
 
        cout << "Enter Book ID: "; 
        cin >> id; 
 
        // Check if ID is unique 
        if (isBookIDExist(id)) { 
            cout << "Book ID already exists! Please use a unique ID.\n"; 
            return; 
        } 
 
        cin.ignore(); // Clear newline character left in input buffer 
 
        cout << "Enter Book Title: "; 
        getline(cin, t); 
        cout << "Enter Book Author: "; 
        getline(cin, a); 
        cout << "Enter Number of Copies: "; 
        cin >> c; 
 
        // Insert the new book into the array and increment count 
        books[bookCount] = Book(id, t, a, c); 
        bookCount++; 
 
        cout << "Book added successfully!\n"; 
    } 
 
    // Function to display all books 
    void displayBooks() { 
        if (bookCount == 0) { 
            cout << "No books available to display.\n"; 
            return; 
        } 
 
        cout << "\n--- List of Books ---\n"; 
        for (int i = 0; i < bookCount; i++) { 
            cout << "Book ID: " << books[i].bookID << "\n"; 
            cout << "Title: " << books[i].title << "\n"; 
            cout << "Author: " << books[i].author << "\n"; 
            cout << "Copies Available: " << books[i].copies << 
"\n"; 
            cout << "-------------------------\n"; 
        } 
    } 
 
    // Function to find (read) a book by ID 
    void findBookByID() { 
        int id; 
        cout << "Enter Book ID to search: "; 
        cin >> id; 
 
        bool found = false; 
 
        for (int i = 0; i < bookCount; i++) { 
            if (books[i].bookID == id) { 
                found = true; 
                cout << "\n--- Book Details ---\n"; 
                cout << "Book ID: " << books[i].bookID << "\n"; 
                cout << "Title: " << books[i].title << "\n"; 
                cout << "Author: " << books[i].author << "\n"; 
                cout << "Copies Available: " << books[i].copies 
<< "\n"; 
                cout << "---------------------\n"; 
                break; 
            } 
        } 
 
        if (!found) { 
            cout << "Book with ID " << id << " not found.\n"; 
        } 
    } 
 
    // Function to update a book's details by ID 
    void updateBook() { 
        int id; 
        cout << "Enter Book ID to update: "; 
        cin >> id; 
 
        bool found = false; 
 
        for (int i = 0; i < bookCount; i++) { 
            if (books[i].bookID == id) { 
                found = true; 
 
                string newTitle, newAuthor; 
                int newCopies; 
                cin.ignore(); // Clear input buffer 
 
                cout << "Enter new Book Title: "; 
                getline(cin, newTitle); 
 
                cout << "Enter new Book Author: "; 
                getline(cin, newAuthor); 
 
                cout << "Enter new Number of Copies: "; 
                cin >> newCopies; 
 
                // Update book details 
                books[i].title = newTitle; 
                books[i].author = newAuthor; 
                books[i].copies = newCopies; 
 
                cout << "Book updated successfully!\n"; 
                break; 
            } 
        } 
 
        if (!found) { 
            cout << "Book with ID " << id << " not found.\n"; 
        } 
    } 
 
    // Function to delete a book by ID 
    void deleteBook() { 
        int id; 
        cout << "Enter Book ID to delete: "; 
        cin >> id; 
 
        bool found = false; 
 
        for (int i = 0; i < bookCount; i++) { 
            if (books[i].bookID == id) { 
                found = true; 
 
                // Shift all books after deleted one to the left 
                for (int j = i; j < bookCount - 1; j++) { 
                    books[j] = books[j + 1]; 
                } 
 
                bookCount--; // Reduce the count by one 
                cout << "Book deleted successfully!\n"; 
                break; 
            } 
        } 
 
        if (!found) { 
            cout << "Book with ID " << id << " not found.\n"; 
        } 
    } 
 
    // Function to show the menu and see user choices 
    void showMenu() { 
        int choice; 
 
        do { 
            cout << "\n--- Library Management System ---\n"; 
            cout << "1. Insert Book\n"; 
            cout << "2. Display All Books\n"; 
            cout << "3. Find Book by ID\n"; 
            cout << "4. Update Book\n"; 
            cout << "5. Delete Book\n"; 
            cout << "6. Exit\n"; 
            cout << "Enter your choice: "; 
            cin >> choice; 
 
            switch (choice) { 
                case 1: 
                    insertBook(); 
                    break; 
                case 2: 
                    displayBooks(); 
                    break; 
                case 3: 
                    findBookByID(); 
                    break; 
                case 4: 
                    updateBook(); 
                    break; 
                case 5: 
                    deleteBook(); 
                    break; 
                case 6: 
                    cout << "Exiting the system...\n"; 
                    break; 
                default: 
                    cout << "Invalid choice! Please try again.\n"; 
            } 
        } while (choice != 6); 
    } 
}; 
 
// Main function to include the objects created for the libray program
int main() { 
    LibraryManagement lm;  // Create LibraryManagement object 
    lm.showMenu();         // Start the menu-driven program 
    return 0; 
}