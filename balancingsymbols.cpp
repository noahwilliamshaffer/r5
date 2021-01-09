/* an example program for
 *
 * COP 4530
 * Department of Computer Science
 * Florida State University
 */
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
		stackChar.push(oneLine[i]);
	    } else {
		if (!stackChar.empty() && (stackChar.top() == '[' && oneLine[i] == ']' ||
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
	    while (!stackChar.empty())
		stackChar.pop();
	}
    }
}
