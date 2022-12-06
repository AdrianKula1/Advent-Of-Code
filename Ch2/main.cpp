#include <iostream>
#include <string>

using namespace std;

int pointsForPick(char pick) {
	switch (pick) {
	case 'X':
		return 1;
	case 'Y':
		return 2;
	case 'Z':
		return 3;
	}
}



char manipulateOutcome(char opponent, char me) {

	switch (opponent) {
	case 'A'://rock
		switch (me) {
		case 'X'://lose
			return 'Z';//scissors
			break;
		case 'Y'://draw
			return 'X';//rock
			break;
		case 'Z'://win
			return 'Y';//paper
			break;
		}
		break;
	case 'B'://paper
		switch (me) {
		case 'X'://lose
			return 'X';//rock
			break;
		case 'Y'://draw
			return 'Y';//paper
			break;
		case 'Z'://Win
			return 'Z';//scissors
			break;
		}
		break;
	case 'C'://scissors
		switch (me) {
		case 'X'://lose
			return 'Y';//paper
			break;
		case 'Y'://draw
			return 'Z';//scissors
			break;
		case 'Z'://win
			return 'X';//rock
			break;
		}
		break;
	}
}

int round(char opponent, char me){
	int result = 0;
	me = manipulateOutcome(opponent, me);
	switch (opponent) {
		case 'A':
			switch (me) {
			case 'X':
				result = 3;
				break;
			case 'Y':
				result = 6;
				break;
 			case 'Z':
				result = 0;
				break;
			}
		break;
		case 'B':
			switch (me) {
			case 'X':
				result = 0;
				break;
			case 'Y':
				result = 3;
				break;
			case 'Z':
				result = 6;
				break;
			}
		break;
		case 'C':
			switch (me) {
			case 'X':
				result = 6;
			break;
			case 'Y':
				result = 0;
			break;
			case 'Z':
				result = 3;
			break;
			}
		break;
	}

	return result + pointsForPick(me);
}


int main() {
	string input;
	int result = 0;
	while (getline(cin, input)) {
		if (input[0] == 'T') {
			break;
		}
		result += round(input[0], input[2]);		
	}

	std::cout  << "Result: " << result << endl;
}
