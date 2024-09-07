#include <iostream>
#include <string>
#include <fstream>

void quest(int a) {
	std::ifstream questions;
	std::string question;

	questions.open("E:\\questions.txt");

	for (int i = 0; i < a; i++) {
		getline(questions, question);
	}
	std::cout << question << "\n";
}

std::string ans(int a) {
	std::ifstream answers;
	std::string answer;

	answers.open("E:\\answers.txt");

	for (int i = 0; i < a; i++) {
		getline(answers, answer);
	}
	return answer;
}


int main()
{
	std::ifstream questions;
	std::ifstream answers;

	int countPlayers = 0;
	int countAudience = 0;
	int volchek = 1;
	int offset = 0;

	int game[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int countPlayer = 0;

	std::string answerPlayer;

	questions.open("E:\\questions.txt");
	answers.open("E:\\answers.txt");

	while ((countPlayers < 6) && (countAudience < 6)) {

		bool res = true;

		while (res != false) {

			std::cout << "Enter number: " << "\n";
			std::cin >> offset;
			volchek += offset;

			if (volchek > 13) {
				volchek = volchek - 13;
			}

			std::cout << "Position volchek:" << volchek << "\n";

			for (int i = 0; i < countPlayer+1; i++) {
				if (game[i] == volchek) {
					res = true;
					std::cout << "This sector has already played\n";
					break;
				}
				else {
					res = false;
				}
			}
		}

		game[countPlayer] = volchek;

		quest(volchek);

		std::cout << "Answer: ";
		std::cin >> answerPlayer;

		if (ans(volchek) == answerPlayer) {
			countPlayers++;
		}
		else {
			countAudience++;
		}

		countPlayer++;

		std::cout << "Audience: " << countAudience << "\n";
		std::cout << "Players: " << countPlayers << "\n";
	}

	if (countPlayers == 6) {
		std::cout << "Plaers win!" << "\n";
	}
	else {
		std::cout << "Adience win!" << "\n";
	}

	questions.close();
	answers.close();
}