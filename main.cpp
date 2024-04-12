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

class ROT13_numeric
{
private:
    unordered_map<long long, long long> substitutionCipher;
    unordered_map<long long, long long> reverseCipher;

public:
    // Constructor to initialize the substitution cipher mapping
    ROT13_numeric()
    {
        for (long long i = 0; i < 10; ++i)
        {
            long long encrypted = (i + 13) % 10; // ROT13 shift
            substitutionCipher[i] = encrypted;
            reverseCipher[encrypted] = i;
        }
    }

    // Function to encrypt a number using ROT13 (Numeric) cipher
    long long encrypt(long long num)
    {
        string numStr = to_string(num);
        string encryptedNumStr = "";
        for (char digit : numStr) // Ranged Loop.
        {
            encryptedNumStr += to_string(substitutionCipher[digit - '0']);
        }
        return stoll(encryptedNumStr); // stoll is string to ll.
    }

    // Function to decrypt a number using ROT13 (Numeric) cipher
    long long decrypt(long long num)
    {
        string numStr = to_string(num);
        string decryptedNumStr = "";
        for (char digit : numStr) // Ranged Loop.
        {
            decryptedNumStr += to_string(reverseCipher[digit - '0']);
        }
        return stoll(decryptedNumStr); // stoll is string to long long.
    }
};


class Cipher_numeric 
{
private:
    unordered_map<long long, long long> substitutionCipher;
    unordered_map<long long, long long> reverseCipher; // Reverse mapping

public:
    // Constructor to initialize the substitution cipher mapping
    Cipher_numeric()
    {
        // Default substitution cipher mapping
        substitutionCipher = {
            {0, 7}, {1, 3}, {2, 8}, {3, 1}, {4, 5}, {5, 6}, {6, 0}, {7, 2}, {8, 4}, {9, 9}};

        // Create reverse mapping that will turn the number back to it's original value
        for (const auto &pair : substitutionCipher)
        {
            reverseCipher[pair.second] = pair.first;
        }
    }

    // Function to encrypt a number using substitution cipher
    long long encrypt(long long num)
    {
        long long encryptedNum = 0;
        long long multiplier = 1;
        long long temp = num;
        while (temp > 0)
        {
            long long digit = temp % 10;
            encryptedNum += substitutionCipher[digit] * multiplier;
            multiplier *= 10;
            temp /= 10;
        }
        return encryptedNum;
    }

    // Function to decrypt a number using substitution cipher
    long long decrypt(long long num)
    {
        long long decryptedNum = 0;
        long long multiplier = 1;
        long long temp = num;
        while (temp > 0)
        {
            long long digit = temp % 10;
            decryptedNum += reverseCipher[digit] * multiplier; // Use reverse mapping
            multiplier *= 10;
            temp /= 10;
        }
        return decryptedNum;
    }
};

int main()
{
    Cipher_numeric Cipher_numeric;
    ROT13_numeric rot13;
    long long num;
    int choice;


    do
    {

    cout << "Welcome To  Encryption/decryption: " << endl;
    cout << "*****************************************************************************" << endl;
    cout << "1: Encryption_(Substituion cipher): " << endl;
    cout << "2: decryption_(Substituion cipher): " << endl;
    cout << "3: Encryption_(ROT_13 cipher): "      << endl;
    cout << "4: Decryption_(ROT_13 cipher)"        << endl;
    cout << "5: exit: "                            << endl;


    cout << "Enter the choice " << endl;
    cin >> choice ;

    switch (choice)
    {
    case 1:
    {
        cout << "enter the number:" << endl;
        cin >> num;
        long long encryptedNum = Cipher_numeric.encrypt(num);
        cout << "Encrypted number: " << encryptedNum << endl;
        break;

    }

    case 2:
    {
        cout << "enter the number:" << endl;
        cin >> num;
        long long decryptedNum = Cipher_numeric.decrypt(num);
        cout << "Decrypted number: " << decryptedNum << endl;
        break;
    }

    
    case 3: 
    {
        cout << "Enter the number: " << endl;
        cin >> num;
        long long encryptedNum = rot13.encrypt(num);
        cout << "Encrypted number: " <<  encryptedNum << endl;
        break;
    }

    case 4:
    {
        cout << "enter the number: " << endl;
        cin >> num;
        long long decrytednum = rot13.decrypt(num);
        cout << "Decrypted number: " << decrytednum << endl;
        break;
    }
    case 5:
    {
        cout << "Exiting program..." << endl;
        return 0;

    }

    default:
        cout << "Invalid choice! Exiting program..." << endl;
        return 1;
    }
    } while(choice != 5);




    return 0;
}
