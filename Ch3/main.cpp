//
#include<iostream>
#include<string>
#include<list>

using namespace std;


int determinePriority(char item) {

	if (islower(item)) {
		return int(item) - 96;
	}
	else {
		return int(item) - 65 + 27;
	}



	return 0;
}

int sumPriorities(list<int>& priorities) {
	int sum = 0;
	for (int i : priorities) {
		sum += i;
	}
	return sum;
}

bool allLettersMatch(char letter1, char letter2, char letter3) {
	if (letter1 == letter2) {
		if (letter2 == letter3) {
			return true;
		}
	}
	return false;
}

int main() {
	int elf = 0;
	string rucksacks[3];
	string leftCompartment, rightCompartment;
	list<int> priorities;

	while (getline(cin, rucksacks[elf])) {

		char item = ' ';

		if (rucksacks[0] == "T") {
			break;
		}

		if (elf == 2) {
			for (int i = 0; i < rucksacks[0].length(); i++) {
				for (int j = 0; j < rucksacks[1].length(); j++) {
					for (int k = 0; k < rucksacks[2].length(); k++) {
						if (allLettersMatch(rucksacks[0][i], rucksacks[1][j], rucksacks[2][k])) {
							item = rucksacks[0][i];
							priorities.push_back(determinePriority(item));
							break;
						}
					}
					if (item != ' ') {
						break;
					}
				}
				if (item != ' ') {
					break;
				}
			}
		}
		elf++;
		elf %= 3;
	}

	cout << sumPriorities(priorities) << endl;

}