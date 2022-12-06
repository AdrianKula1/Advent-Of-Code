#include <iostream>
#include <string>
#include <thread>

using namespace std;

int main()
{
    string input;
    int overlappingElves = 0;


    while (getline(cin, input)) {
        if (input == "T") {
            break;
        }
        pair<string, string> range1Str, range2Str;
        pair<int, int> range1, range2;


        string firstElf, secondElf;

        firstElf = input.substr(0, input.find(","));
        range1Str.first = firstElf.substr(0, firstElf.find("-"));
        range1Str.second = firstElf.substr(firstElf.find("-")+1, firstElf.length()-1);

        secondElf = input.substr(input.find(",")+1, input.length()-1);
        range2Str.first = secondElf.substr(0, secondElf.find("-"));
        range2Str.second = secondElf.substr(secondElf.find("-")+1, secondElf.length()-1);


        range1.first = stoi(range1Str.first);
        range1.second = stoi(range1Str.second);

        range2.first = stoi(range2Str.first);
        range2.second = stoi(range2Str.second);
        
        //bool firstElfOverlapsSecond = ((range2.first >= range1.first) && (range2.second <= range1.second));
        //bool secondElfOverlapsFirst = ((range1.first >= range2.first) && (range1.second <= range2.second));
        
        bool firstElfOverlapsSecond = (range1.second >= range2.first) && (range1.first <= range2.second);
        bool secondElfOverlapsFirst = (range2.second >= range1.first) && (range2.first <= range1.second);

        if (firstElfOverlapsSecond || secondElfOverlapsFirst) {
            overlappingElves++;
        }
    }

    cout << overlappingElves << endl;
}
