#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    // setting up the list of alphabet pairs
    vector<string> pairs;
    string a,b;
    for (int i = 0; i < 26; i++) {
        a = 97+i;
        for (int j = 0; j < 26; j++) {
            b = 97 + j;
            string temp = a+b;
            pairs.push_back(temp);
        }
    }

    // doing work on an input
    string word;
	while (getline(cin,word)) {
        if (word.length() < 2)
            continue;
        
        for (int i = 0; i < pairs.size(); i++) {
            int tempsize = pairs.size();
            for (int j = 0; j < word.length() - 1; j++) {
                if (pairs[i][0] == word[j] && pairs[i][1] == word[j+1]) {
                    pairs.erase(pairs.begin()+i);
                    i--;
                    break;
                }
            }
        }
        // cout << pairs.size() << endl;
	}
    
    // cout list of alphabet pairs that do not exist in the alphabet
    for (int i = 0; i < pairs.size(); i++) {
        cout << pairs[i] << endl;
    }
}
