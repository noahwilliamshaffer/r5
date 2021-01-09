/************************************
 * An example program to show the use of stack
 * to solve the balanced symbols problem
 *
 * Note that this problem has a run-time error
 * for the purpose of practicing debugging
 *
 * COP 4530
 * Department of Computer Science
 * Florida State University
 * ***********************************/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string oneLine;
    stack<char> stackChar;
    bool flag;

    while (getline(cin, oneLine)) {
	flag = true;
	cout << oneLine << ": ";
	for (int i = 0; i < oneLine.size(); ++i) {
	    if (oneLine[i] ==  '[' || oneLine[i] == '(') {
		stackChar.push(oneLine[i]); // keep left symbols in stack
	    } else { // try to match right symbols with corresponding left symbols
		if ((stackChar.top() == '[' && oneLine[i] == ']' ||
					  stackChar.top() == '(' && oneLine[i] == ')')) 
		    stackChar.pop();
		else {
		    flag = false;
		    break;
		}
	    }
	}
	if (!stackChar.empty())
	    flag = false;

	if (flag)
	    cout << "balanced" << endl;
	else {
	    cout << "unbalanced" << endl;
	    while (!stackChar.empty()) // clear stack for next line
		stackChar.pop();
	}
    }
}
