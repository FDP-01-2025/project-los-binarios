#ifndef juego1casinopt3_h
#define juego1casinopt3_h

#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

struct Block {
    string encodedText;
    string clue;
};

struct EncodedPhrase {
    vector<Block> blocks;
    string realPhrase;
};

// Phrase definitions
vector<EncodedPhrase> phrases = {
    { 
      {{"spara", "31254"}, {"adfnu", "54132"}, {"perme", "34512"}, {"egsui", "53142"},
       {"epory", "21435"}, {"sooym", "21345"}, {"spraa", "25341"}, {"oid", "312"}},
      "pasar funda me persigue pero yo soy mas rapido"
    },
    {
      {{"etgni", "45321"}, {"neagn", "21435"}, {"comos", "34512"}, {"opasi", "51234"},
       {"pnfro", "21543"}, {"ravo", "4123"}},
      "inge tenganos compasion porfavor"
    },
    {
      {{"rgaic", "21354"}, {"olasa", "54321"}, {"bspal", "41521"}, {"asare", "12345"},
       {"afdun", "51423"}},
      "gracias a los lab pasare funda"
    }
};

// Cleans input string (removes spaces, keeps only letters, lowercase)
string clean(const string& s) {
    string res;
    for (char c : s) {
        if (isalpha(c)) res += tolower(c);
    }
    return res;
}

// Show encoded phrase with clues
void showEncodedPhrase(const EncodedPhrase& phrase) {
    for (const auto& b : phrase.blocks) {
        cout << b.encodedText << " (" << b.clue << ")  ";
    }
    cout << "\n";
}

#endif