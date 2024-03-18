/*THIS MINI_PROJECT IS ADDRESSED AS "ADDRESS BOOK"
THE CODE IS WRITTEN BY
23CS032_DHAIRYA KANABAR.
23CS037_PRINCE LAD.
23CS039_SHREY LAKHTARIA.

THE FUNCTION OF THE PROJECT IS TO SORT A LIST INTO ALPHABETICAL ORDER AND SEARCH FOR
THE CONTACT USER WANT TO FIND.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>

using namespace std;
struct Contact
{
    string name;
    string contact_number;
};

// function to compare upper_case and Lower_case

bool compareContact(const Contact &a, const Contact &b)
{
    return a.name < b.name;
}

int main()
{

    vector<Contact> AddressBook;
    int choice;

    do
    {
        cout << "Address Book Menu:" << endl;
        cout << "1. Open contact list" << endl;
        cout << "2. Search for a contact" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
    {
        case 1:
        {
            // cout << "The contact list is " << endl;
            // // HERE we WILL add FILE stream TO open A file :)
            // // then we will sort it using
            // // sort(addressBook.begin(), addressBook.end(), compareContacts);
            // // cout << "Contact List:" << endl;
            // // for (const auto &contact : addressBook)
            // // {
            // //     cout << contact.name << ": " << contact.phoneNumber << endl;
            // // }
            // // break;
        }
    }
    }
    
}
