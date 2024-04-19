/*This project was created by  Dhariya Kanabar_23CS032 , Prince Lad_23CS037, Shrey Lakhataria_23CS039*/

/*

=--------------------------------------------------------= PROJECT DESCRIPTION =--------------------------------------------------------=

                                                          Encryption/decryption

                                               1. User chooses either encyption or decryption.
                                               2.`User enters the information.
                                               3. Encryption or decryption is carried out.
                                               4. Output is showed.

*/
 
#include <iostream>
#include <unordered_map>

using namespace std;

class keyEncrypt {
    unordered_map<long long, long long> substitutionCipher;
    unordered_map<long long, long long> reverseCipher;

public:
    // Constructor to initialize the substitution cipher mapping
    keyEncrypt(string key) {
        
        for (long long i = 0; i < 10; ++i) {
            
            long long encrypted = (i + stoi(key)) % 10; // ROT13 shift
            substitutionCipher[i] = encrypted;
            reverseCipher[encrypted] = i;

        }
        
    }

    // Function to encrypt a number using ROT13 (Numeric) cipher
    long long encrypt(long long num) {
        
        string numStr = to_string(num);
        string encryptedNumStr = "";
        
        for (char digit : numStr) {// Ranged Loop.

            encryptedNumStr += to_string(substitutionCipher[digit - '0']);
        }

        return stoll(encryptedNumStr); // stoll is string to ll.
    }

    // Function to decrypt a number using ROT13 (Numeric) cipher
    long long decrypt(long long num) {
        
        string numStr = to_string(num);
        string decryptedNumStr = "";
        
        for (char digit : numStr) {// Ranged Loop.
        
            decryptedNumStr += to_string(reverseCipher[digit - '0']);
        }
        
        return stoll(decryptedNumStr); // stoll is string to long long.

    }

};


class Cipher_numeric {
    unordered_map<long long, long long> substitutionCipher;
    unordered_map<long long, long long> reverseCipher; // Reverse mapping

public:
    // Constructor to initialize the substitution cipher mapping
    Cipher_numeric() {
        // Default substitution cipher mapping
        substitutionCipher = {
            {0, 7}, {1, 3}, {2, 8}, {3, 1}, {4, 5}, {5, 6}, {6, 0}, {7, 2}, {8, 4}, {9, 9} };

        // Create reverse mapping that will turn the number back to it's original value
        for (const auto &pair : substitutionCipher) {
            reverseCipher[pair.second] = pair.first;
        }

    }

    // Function to encrypt a number using substitution cipher
    long long encrypt(long long num) {
        
        long long encryptedNum = 0;
        long long multiplier = 1;
        long long temp = num;
        
        while (temp > 0) {
            
            long long digit = temp % 10;
            encryptedNum += substitutionCipher[digit] * multiplier;
            multiplier *= 10;
            temp /= 10;

        }

        return encryptedNum;

    }

    // Function to decrypt a number using substitution cipher
    long long decrypt(long long num) {
        
        long long decryptedNum = 0;
        long long multiplier = 1;
        long long temp = num;
        
        while (temp > 0) {
            long long digit = temp % 10;
            decryptedNum += reverseCipher[digit] * multiplier; // Use reverse mapping
            multiplier *= 10;
            temp /= 10;
        }

        return decryptedNum;

    }

};

int mainMenu() {

    int choice;
    cout << "------------------------------------------------------------------------------------------------"<<endl;
    cout << "------------------------------Welcome To  Encryption/decryption: -------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "1: Encryption_(Substituion cipher): " << endl;
    cout << "2: Decryption_(Substituion cipher): " << endl;
    cout << "3: Encryption_(Key cipher):" << endl;
    cout << "4: Decryption_(Key cipher):" << endl;
    cout << "5: exit: " << endl;
    //A substitution cipher replaces any plain text character from a given fixed set of characters with another character from the same set based on a key.
    //Key cipher locks (encrypts) data so that only someone with the right key can unlock (decrypt) it. The original data is known as the plaintext, and the data after the key encrypts it is known as the ciphertext.
    cout << ":::::::::::::::::::::::::::::::::" << endl;
    cout << "::::::::Enter the choice:::::::::" << endl;
    cout << ":::::::::::::::::::::::::::::::::" << endl;
    cin >> choice ;

    if(choice >= 1 && choice <= 5) {

        return choice;

    }
    else {

        cout << "Enter proper choice.";

        mainMenu();

    }

    return 0;
   
}

int main() {

    long long num;
    string key;
    
    do {

        switch (mainMenu())
        {
            
            case 0: {

                cout << "Error in mainmenu." << endl;

                exit(1);

            }
            
            case 1: {

                Cipher_numeric *temp;

                temp = new Cipher_numeric();
                
                cout << "Enter the number:" << endl;
                cin >> num;

                num = temp -> encrypt (num);

                cout << "Encrypted number: " << num << endl;

                delete temp;

                break;

            }

            case 2: {

                Cipher_numeric *temp;

                temp = new Cipher_numeric();
                
                cout << "Enter the number:" << endl;
                cin >> num;

                num = temp -> decrypt(num);

                cout << "Decrypted number: " << num << endl;

                break;

            }


            case 3: {

                cout << "Enter the number: " << endl;
                cin >> num;

                cout << "Enter the key:" << endl;
                cin >> key;

                keyEncrypt *temp;

                temp = new keyEncrypt(key);

                num = temp -> encrypt(num);

                cout << "Encrypted number: " <<  num << endl;

                break;

            }

            case 4: {

                cout << "Enter the number: " << endl;
                cin >> num;

                cout << "Enter the key:" << endl;
                cin >> key;

                keyEncrypt *temp;

                temp = new keyEncrypt(key);

                num = temp -> decrypt(num);

                cout << "Decrypted number: " << num << endl;

                break;

            }

            case 5: {

                cout << "Exiting program..." << endl;

                return 0;

            }

        }

        cout << "Do you want to continue encrypting/decrypting? (Y)es or (N)o." << endl;
        cin >> key;

        if(key == "N" || key == "n") {

            cout << "Exiting program..." << endl;

            return 0; 

        }

    } while(true);

}
