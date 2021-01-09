/***********************************
 * a simple program to illustrate the use of 
 * stack and queues to solve the palindrome problem
 *
 * COP 4530
 * Department of Computer Science
 * Florida State University
 * *********************************/
#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

int main() {
	char c;
	queue<char> q;
	stack<char> s;

	while (cin.get(c)) {
		if (c != '\n') { // read one line
			q.push(tolower(c));
			s.push(tolower(c));
			cout.put(c);
		} else {
			cout.put(':');

			while (!q.empty()) { // compare forward and backward
				if (q.front() != s.top()) {
					cout << " not a palindrome" << endl;
					break;
				} else {
					q.pop();
					s.pop();
				}
			}
			if (q.empty()) { // we have compared all characters
				cout << " a palindrome" << endl;
			} else { // we break from while loop.
				while (!q.empty()) {
					q.pop();
					s.pop();
				}
			}
		}
	}
}
