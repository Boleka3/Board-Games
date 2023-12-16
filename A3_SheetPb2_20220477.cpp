// File name:A3_SheetPb2_20220477.cpp
// Purpose: check similarity between 2 strings or files and test some functions
// Author(s): Mohamed Osama Khaled Mohamed
// ID(s):20220477
// Section:s23
// Date:9/12/2023
// TA: Eng. Mohammed Talaat

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <sstream>

using namespace std;

class StringSet {
private:
    vector<string> words;

public:
    // Default constructor
    StringSet() = default;


    // Constructor for files
    StringSet(string& filename)  {
        ifstream file(filename);
        while (!file.is_open()) {
            cout << "Cannot open file: " << filename << endl;
            cout << "Do you want to enter another file?\n";
            cout << "Enter 1 for yes and 0 for no\n";
            int answer;
            cin >> answer;

            while (answer != 1 && answer != 0) {
                cout << "Invalid answer. Please enter 1 for yes or 0 for no: ";
                cin >> answer;
            }

            if (answer == 1) {
                cout << "Enter the name of the file: ";
                cin >> filename;
                file.open(filename);
            } else if (answer == 0) {
                cout << "Exiting program." << endl;
                exit(0);
            }
        }
        // Read words from the file and store them in the vector
        string word;
        while (file >> word) {
            // Remove punctuation and convert to lowercase
            string clean_word = "";
            for (char c : word) {
                if (!ispunct(c)) {
                    clean_word += tolower(c);
                }
            }

            if (!clean_word.empty()) {
                words.push_back(clean_word);
            }
        }
        // Sort the vector and remove duplicates
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        file.close();
    }


    // Constructor for string
    StringSet(const char* text)  {
        string word;
        istringstream iss(text); // Create a string stream from the input text
        while (iss >> word) {
            // Remove punctuation and convert to lowercase

            string clean_word = "";
            for (char c : word) {
                if (!ispunct(c)) {
                    clean_word += tolower(c);
                }
            }
            // Add the cleaned word to the vector if not empty
            if (!clean_word.empty()) {
                words.push_back(clean_word);
            }
        }

        // Sort the vector and remove duplicates
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
    }


    StringSet operator +(StringSet set2){
        StringSet result = *this; // Create a copy of the current set
        // Concatenate the vectors of the current set and set2
        for(auto word : set2.words) {
            result.words.push_back(word);
        }
        // Sort and remove duplicates from the concatenated vector
        sort(result.words.begin(), result.words.end());
        result.words.erase(unique(result.words.begin(), result.words.end()), result.words.end());
        return result;
    }

    StringSet operator *(StringSet set2){
        StringSet result;
        // Find common elements between the vectors of the current set and set2
        for (auto word: words){
            if(find(set2.words.begin(),set2.words.end(),word) != set2.words.end() ){
                result.words.push_back(word);
            }
        }

        return result;


    }

    // Calculate similarity between two sets using the Jaccard similarity coefficient
    double calculateSimilarity(StringSet set2){
        vector<string> result; // Vector to store common elements
        vector<string> SortedSet1 = words; // Copy of words vector
        vector<string> SortedSet2 = set2.words; // Copy of set2.words vector

        // Sort the vectors to facilitate intersection calculation
        sort(SortedSet1.begin(), SortedSet1.end());
        sort(SortedSet2.begin(), SortedSet2.end());

        // Iterate through the sorted vectors to find common elements
        for (auto word1 : SortedSet1){
            for (auto word2 : SortedSet2){
                if (word1 == word2){
                    result.push_back(word1);
                }
            }
        }

        // Calculate Jaccard similarity coefficient
        double SqrtOfSet1Size = sqrt(SortedSet1.size());
        double SqrtOfSet2Size = sqrt(SortedSet2.size());
        double Similarity = static_cast<double>(result.size()) / (SqrtOfSet1Size * SqrtOfSet2Size);

        // Ensure similarity value is between 0 and 1
        return max(0.0, min(1.0, Similarity));
    }





    void add(const string& str) {
        string clean_str = "";
        for (char c : str) {
            if (!ispunct(c)) {
                clean_str += tolower(c);
            }
        }
        if (!clean_str.empty()) {
            words.push_back(clean_str);
        }
    }

    void remove(const string& str) {
        auto it = find(words.begin(), words.end(), str);
        if (it != words.end()) {
            words.erase(it);
            cout << "String removed from the set." << endl;
        } else {
            cout << "String not found in the set!" << endl;
        }
    }

    void clear() {
        words.clear();
    }

    int size() const {
        return words.size();
    }

    void output() const {
        for (const auto& str : words) {
            cout << str << " ";
        }
        cout << endl;
    }
};

int main() {
    string input;
    cout << "Enter a string or the name of a file for Set 1: ";
    getline(cin, input);

    StringSet set1;

    if (input.size() > 4 && input.substr(input.size() - 4) == ".txt") {
        // If the input is a file, deal with the file constructor
        set1 = StringSet(input);
        cout << "StringSet created from file." << endl;
    } else {
        // If the input is a string, create a StringSet from the string
        set1 = StringSet(input.c_str());
        cout << "StringSet created from input string." << endl;
    }

    cout << "Set 1: ";
    set1.output();

    // Interactively add and remove elements from Set 1
    string elementToAdd, elementToRemove;
    cout << "Enter a string to add to Set 1: ";
    cin >> elementToAdd;
    set1.add(elementToAdd);
    cout << "After adding '" << elementToAdd << "': ";
    set1.output();

    cout << "Enter a string to remove from Set 1: ";
    cin >> elementToRemove;

// Save the size of the set before removal
    int setSizeBefore = set1.size();

// Remove the element from the set
    set1.remove(elementToRemove);

// Check if the size has changed after removal
    if (setSizeBefore != set1.size()) {
        cout << "After removing '" << elementToRemove << "': ";
        set1.output();
    }


    // Test + and * operators
    cout << "\nEnter a string or the name of a file for Set 2: ";
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, input);

    StringSet set2;

    if (input.size() > 4 && input.substr(input.size() - 4) == ".txt") {
        set2 = StringSet(input);
        cout << "StringSet created from file." << endl;
    } else {
        set2 = StringSet(input.c_str());
        cout << "StringSet created from input string." << endl;
    }

    cout << "Set 2: ";
    set2.output();

    StringSet set3 = set1 + set2;
    cout << "Set 3 (Union of Set 1 and Set 2): ";
    set3.output();

    StringSet set4 = set1 * set2;
    cout << "Set 4 (Intersection of Set 1 and Set 2): ";
    set4.output();

    // Test calculateSimilarity function
    double similarity = set1.calculateSimilarity(set2);
    cout << "\nSimilarity between Set 1 and Set 2: " << similarity << endl;


    return 0;
}