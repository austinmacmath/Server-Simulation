#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

int getStart(char str[]) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ':') {
            return i + 1;
        }
    }
    return -1;
}

int getNum(char str[]) {
    string num = "";
    for(int i = getStart(str); i < strlen(str); i++) {
        num += str[i];
    }
    return stoi(num);
}

string getServer(char str[]) {
    string server = "";
    for(int i = 0; i < getStart(str) - 1; i++) {
        server += str[i];
    }
    return server;
}

int main(int argc, char* argv[]) {

    int cumulative = 0;
    vector<pair<string, int> > prob;

    for(int i = 1; i < argc; i++) {
        cumulative += getNum(argv[i]);
        prob.push_back(pair<string, int>(getServer(argv[i]), cumulative));
    }

    random_device rd;
    uniform_int_distribution<int> dist(1, cumulative);
    int rand = dist(rd);

    for(int i = 0; i < prob.size(); i++) {
        if(rand <= prob[i].second) {
            cout << prob[i].first << endl;
            break;
        }
    }

}