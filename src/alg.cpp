// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include <iostream>
#include <string>
#include <map>

bool isDigit(char sym) {
	return sym >= 48 && sym <= 57;
}

bool isOperator(char sym) {
	return sym == '+' || sym == '-' ||
		sym == '*' || sym == '/' ||
		sym == '(' || sym == ')';
}

uint8_t getPrior(char oper) {
	std::map<char, uint8_t> prior = { 
		{'(', 0}, {')', 1},
		{'+', 2}, {'-', 2},
		{'*', 3}, {'/', 3},
	};

	return prior[oper];
}


std::string infx2pstfx(const std::string& inf) { //(2-1)*(6+2)
	std::string output;
	TStack<char> operations;
	for (char sym : inf) {
		if (isDigit(sym)) {
			output += sym;
		}
		else if (isOperator(sym)) {
			if (sym == '(') operations.push(sym);
			else if (sym == ')') {
				while (!operations.isEmpty() && operations.top() != '(') {
					output += operations.pop();
				}
				operations.pop();
			}
			else if (operations.isEmpty() || sym == '(' ||
				getPrior(sym) > getPrior(operations.top())) {
				operations.push(sym);
			}
			else if (getPrior(sym) <= getPrior(operations.top())) {
				while (!operations.isEmpty() &&
					operations.top() != '(' &&
					getPrior(sym) <= getPrior(operations.top())) {
					output += operations.pop();
				}

				operations.push(sym);
			}

		}
	}

	while (!operations.isEmpty()) {
		output += operations.pop();
	}

	std::cout << output;
	return std::string("");
}

int eval(const std::string& pref) {
  
  return 0;
}


int main() {
	infx2pstfx("(2-1)*(6+2)");

	try {

	}
	catch (const std::runtime_error& e) {
		std::cout << e.what();
	}
}