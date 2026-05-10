#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct CompareW {
    bool operator() (const pair<string, int>& a, const pair<string ,int>& b) {
        if(a.second < b.second) {
            return false;
        }
        if(a.second > b.second) {
            return true;
        }
        if(a.first > b.first) {
            return true;
        }
        return false;
    }
};

int main() {
    string text;
    string linie;
    ifstream Propozitie("Sentence.txt");
    if(!Propozitie.is_open()) { cout<<"Nu se poate deschide fisierul.\n"; return 1;}
    while(getline(Propozitie,linie))
    {
        text += linie + " ";
    }
    Propozitie.close();

    for(int i=0;i<text.length();i++) {
        text[i]=tolower(text[i]);
    }
    map<string, int> counter;
    string separatori=" ,?.!";
    size_t start = text.find_first_not_of(separatori);
    while(start!= string::npos)
    {
        size_t end = text.find_first_of(separatori, start);
        string word;
        if(end == string::npos){
            word= text.substr(start);
        } else {
            word = text.substr(start, end-start);
        }
        counter[word]++;
        start = text.find_first_not_of(separatori, end);
    } 

    priority_queue<pair<string,int>, vector<pair<string,int>>, CompareW> pq;
    for(auto it = counter.begin(); it != counter.end(); it++) {
        pq.push(*it);
    }

    while(!pq.empty()) {
        cout<< pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
