#include <iostream>

// Only for lowercase
std::string cipher(const std::string& text, const int& flag, const int& key)
{
    std::string result;

    if (flag == 0) {
        for (int x = 0; x < text.length(); ++x) { // Prefix is less expensive then post fix so we prefer it in scenarios where using pre/post doesnt matter.
            char letter = text[x];

            if (letter >= 'a' && letter <= 'z') {
                letter = letter + key;
                if (letter > 'z') {
                    letter = letter - 'z' + 'a' - 1;
                }
                result += letter;
            }
        
        }
    }
    else if (flag == 1) {
        for (int x = 0; x < text.length(); ++x) {
            char letter = text[x];

            if (letter >= 'a' && letter <= 'z') {
                letter = letter - key; // swap for decryption
                if (letter < 'a') { // we check for less then a as we are decrypting
                    letter = letter + 'z' - 'a' + 1;
                }
                result += letter;
            }

        }
    }

    return result;
};

int main()
{
    std::string text;
    int flag, key;

    std::cout << "== Welcome to the Ceaser Cipher == \n> The first parameter is the text you need to encrypt or decrypt.\n> The second parameter is an"
        "integer value(i.e.the encryption flag), which is either 0 or 1. Encrypt the text if this"
        "value is 0, or decrypt the text if this value is 1.\n> The third"
        "parameter is a positive integer value, which will be used as the key for the encryption algorithm" << std::endl;

    try {
        std::cin >> text >> flag >> key;

        if (isdigit(flag) == false || isdigit(key) == false) {
            throw std::invalid_argument("> invalid arguments, try again.");
        }

        std::cout << cipher(text, flag, key) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }

    return 0;
}

