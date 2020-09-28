#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int countSubstring(const string& str, const string& sub) {
    if (sub.length() == 0) return 0;
    int count = 0;
    for (int offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length()))
        ++count;
    return count;
}

int totalNumbers(const string& in) {
    stringstream cI { in };
    int ints {};
    string e;
    while (cI >> e)
        ints += static_cast<stringstream>(e) >> ints ? 0 : 1;
    return ints;
}

int totalWords(const string& in) {
    return std::count(in.begin(), in.end(), ' ') + 1 - totalNumbers(in);
}

int totalSentences(const string& in) {
    return count(in.begin(), in.end(), '.');
}

double averageWords(const string& in) {
    return 1.0 * totalWords(in) / totalSentences(in);
}

int uniqueWords(const string& in) {
    set<string> uniques;
    string word;
    stringstream words { in };
    while (getline(words, word, ' '))
        uniques.insert(word);
    return uniques.size() - totalNumbers(in);
}

double lexicalDensity(const string& in) {
    return 100.0 * uniqueWords(in) / totalWords(in);
}

int main() {
    string in {"I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. "
                  "I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. "
                  "I saw miles and miles of Texas 1000 stars up in the sky. "
                  "I saw miles and miles of Texas gonna live here till I die."
    };

    string substring { "is" };

    cout << "The given string contains \"" << substring << "\" " << countSubstring(in, substring) << " times, has ";
    cout << totalWords(in) << " words, ";
    cout << totalSentences(in) << " sentences, ";
    cout << uniqueWords(in) << " unique words, ";
    cout << averageWords(in) << " average words, ";
    cout << "and has a lexical density of " << lexicalDensity(in) << "%.";

}
