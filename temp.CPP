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
        return stoll(decryptedNumStr); // stoll is string to ll.
    }
};

int main()
{
    ROT13_numeric rot13;
    long long num;

    cout << "Welcome to ROT13 Numeric Encryption/Decryption" << endl;
    cout << "Enter a number to encrypt or decrypt: ";
    cin >> num;

    long long encryptedNum = rot13.encrypt(num);
    cout << "Encrypted number: " << encryptedNum << endl;

    long long decryptedNum = rot13.decrypt(encryptedNum);
    cout << "Decrypted number: " << decryptedNum << endl;

    return 0;
}
