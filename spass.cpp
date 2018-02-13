#include <iostream>
#include <string>
#include <utility>
#include "hashtable.h"
#include <cctype>

using namespace std;
using namespace cop4530;

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}

int main()
{

    int preferred;
    cout << "Enter preferred hash table capacity: ";
    cin >> preferred;

    HashTable hashTable(preferred);

    while (true) {
        // Display the menu and get the choice from the user
        Menu();
        char choice;
        cin >> choice;

        // Force lower casing
        choice = tolower(choice);

        if (choice == 'x') {
            break;
        }
        else if (choice == 'l') {
            // Load from file
            string fileName;

            cout << "Enter password file name to load from: ";
            cin >> fileName;

            hashTable.loadFile(fileName);
        }
        else if (choice == 'a') {
            // Add User
            string username, password;

            cout << "Enter username: ";
            cin >> username;
            password = getpass("Enter password: ");
            cout << endl;

            pair<string, string> credentials;

            credentials.first = username;
            credentials.second = password;

            if (hashTable.addUser(credentials)) {
                cout << "User " << username << " added." << endl;
            }
            else {
                cout << "*****Error: User already exists. Could not add user." << endl;
            }
        }
        else if (choice == 'r') {
            // Remove User
            string username;

            cout << "Enter username: ";
            cin >> username;

            if(hashTable.remove(username)) {
                cout << "User '" << username << "' deleted";
            }
            else {
                cout << "*****Error: User not found.  Could not delete user" << endl;
            }
        }
        else if (choice == 'c') {
            // Change User Password
            string username, password, newpass;

            cout << "Enter username    : ";
            cin >> username;
            password = getpass("Enter password: ");
            cout << endl << "Enter new password: ";
            cin >> newpass;

            pair<string, string> credentials;

            credentials.first = username;
            credentials.second = password;

            if (hashTable.changePassword(credentials, newpass)) {
                cout << endl << "Password changed for user " << username << endl;
            }

            else {
                cout << "*****Error: User not found.  Could not change user password" << endl;
            }

        }
        else if (choice == 'f') {
            // Find User
            string username, password;
            cout << "Enter username    : ";
            cin >> username;
            password = getpass("Enter password: ");
            cout << endl;

            pair<string, string> credentials;

            credentials.first = username;
            credentials.second = password;

            if (!hashTable.findUser(credentials)) {
                cout << "User '" << username << "' not found.";
            }
            else {
                cout << "User '" << username << "' found.";
            }

        }
        else if (choice == 'd') {
            // Dump HashTable
            hashTable.print();
        }
        else if (choice == 's') {
            // HashTable Size
            cout << "Size of hashtable: " << hashTable.size() << endl;
        }
        else if (choice == 'w') {
            // Write to Password File
            string fileName;
            cout << "Enter password file name to write to: ";
            cin >> fileName;

            hashTable.writeFile(fileName);
        }
        else {
            // Error message
            cout << "*****Error: Invalid entry.  Try again." << endl;
        }

    }

    return 0;
}
