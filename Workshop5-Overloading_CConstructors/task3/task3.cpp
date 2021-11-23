#include <iostream>
using namespace std;

// For this workshop for practicality I wont use headers files for the classes
// and just make them in main.cpp, refer to previous workshop to see how header files work

class Tool 
{
	protected:
		int strength;
		char type;

	public:
		void setStrength(const int& strength) {this->strength = strength;};
		char getType() const {return type;};
		int getStrength() const {return strength;};

};

class Scissors : public Tool 
{
	public:
		Scissors(const int& strength) {
			setStrength(strength);
			type = 's';
		}

		void fight(Tool tool) {
			if (tool.getType() == 's') {
				cout << "Scissors vs Scissors: Draw" << endl;
			} else if (tool.getType() == 'p') {
				cout << "Scissors vs Paper: Scissors wins" << endl;
			} else if (tool.getType() == 'r') {
				int rockTemp = tool.getStrength() * 2;

				if (rockTemp <= this -> strength) {
					cout << "Scissors vs Rock: Scissors wins" << endl;
				} else {
					cout << "Scissors vs Rock: Rock wins" << endl;
				}
			}
		}
};

class Paper : public Tool 
{
	public:
		Paper(const int& strength) {
			setStrength(strength);
			type = 'p';
		}

		void fight(Tool tool) {
			if (tool.getType() == 's') {
				int scissorsTemp = tool.getStrength() * 2;

				if (scissorsTemp <= this -> strength) {
					cout << "Paper vs Scissors: Paper wins" << endl;
				} else {
					cout << "Paper vs Scissors: Scissors wins" << endl;
				}
			} else if (tool.getType() == 'p') {
				cout << "Paper vs Paper: Draw" << endl;
			} else if (tool.getType() == 'r') {
				int rockTemp = tool.getStrength() / 2;

				if (rockTemp <= this -> strength) {
					cout << "Paper vs Rock: Paper wins" << endl;
				} else {
					cout << "Paper vs Rock: Rock wins" << endl;
				}
			}
		}
};

class Rock : public Tool 
{
	public:
		Rock(const int& strength) {
			setStrength(strength);
			type = 'r';
		}

		void fight(Tool tool) {
			if (tool.getType() == 's') {
				int scissorsTemp = tool.getStrength() * 2;

				if (scissorsTemp < this -> strength) {
					cout << "Rock vs Scissors: Rock wins" << endl;
				} else {
					cout << "Rock vs Scissors: Scissors wins" << endl;
				}
			} else if (tool.getType() == 'p') {
				int paperTemp = tool.getStrength() / 2;

				if (paperTemp <= this -> strength) {
					cout << "Rock vs Paper: Rock wins" << endl;
				} else {
					cout << "Rock vs Paper: Paper wins" << endl;
				}
			} else if (tool.getType() == 'r') {
				cout << "Rock vs Rock: Draw" << endl;
			}
		}
};

int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	s1.fight(p1);
	p1.fight(s1);
	p1.fight(r1);
	r1.fight(p1);
	r1.fight(s1);
	s1.fight(r1);

};