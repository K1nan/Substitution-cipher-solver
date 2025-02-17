#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

// Function to decrypt the cipher text
string decryptText(const string& cipherText, const unordered_map<char, char>& mapping) {
    string decryptedText;

    for (char ch : cipherText) {
        if (mapping.find(ch) != mapping.end()) {
            decryptedText += mapping.at(ch); // Replace with mapped character
        }
        else if (ch == '_') {
            decryptedText += ' '; // Replace '_' with space
        }
        else if (ch == '#') {
            decryptedText += '\n'; // Replace '#' with newline
        }
        else {
            decryptedText += ch; // Keep unchanged if not in map
        }
    }

    return decryptedText;
}

int main() {
    unordered_map<char, char> mapping = {
        {'U', 'e'}, {'3', 't'}, {'M', 'a'}, {'C', 'o'}, {'K', 's'}, {'H', 'h'}, {'T', 'n'},
        {'0', 'i'}, {'P', 'l'}, {'9', 'd'}, {'S', 'w'}, {'D', 'f'}, {'8', 'm'}, {'O', 'u'},
        {'Y', 'g'}, {'5', 'b'}, {'Q', 'c'}, {'W', 'y'}, {'X', 'p'}, {'4', 'k'}, {'7', 'v'},
        {'K', 's'}, {'G', 'q'}, {'B', 'x'}, {'L', 'r'}, {'F', 'z'},{'J', ' '}
        
    };

    // Open the cipher text file
    ifstream inputFile("ct.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    string cipherText((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    string decryptedText = decryptText(cipherText, mapping);

    ofstream outputFile("dt.txt");
    if (!outputFile) {
        cerr << "Error: Could not open output file.\n";
        return 1;
    }

    outputFile << decryptedText;
    outputFile.close();

    cout << "Decryption complete. Check 'decrypted.txt' for output.\n";
    return 0;
}
