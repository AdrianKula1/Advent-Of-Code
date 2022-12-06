#include<iostream>
#include<list>
#include<string>

using namespace std;

int getLowestElf(int *elves, int size) {
	int lowestElf = elves[0], lowestElfIndex = 0;
	for (int i = 1; i < size; i++) {
		if (elves[i] < lowestElf) {
			lowestElfIndex = i;
		}
	}
	return lowestElfIndex;
}


int main() {
	string input;

	int highestElfs[3] = {0, 0, 0};
	int currentElf = 0;

	while (getline(cin, input)) {
		if (input == "T") {
			break;
		}
		if (input.length() == 0) {
			if (currentElf > highestElfs[getLowestElf(highestElfs, 3)]) {
				highestElfs[getLowestElf(highestElfs, 3)] = currentElf;
			}

			currentElf = 0;

		}
		else {
			int number = stoi(input);
			currentElf += number;
			
		}
	}

	cout << "sum of highest elves: " << highestElfs[0] + highestElfs[1] + highestElfs[2]<< endl;
	return 0;
}