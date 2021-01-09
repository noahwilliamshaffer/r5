/* Example program for 
 * COP 4530
 * Department of Computer Science
 * Florida State University
 */

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

main() {
	int first, last, remaining, cur, cur1;
	stack<int> stk;
	int steps;

	while (cin >> first >> last) {
		remaining = last - first;
		steps = 2;

		while (!stk.empty()) {
			stk.pop();
		}

		stk.push(1);
		cur = 1;
		remaining -= 2; // first and last steps should be 1

		while (1) {
			if (remaining == 0 && (cur == 2 || cur == 1)) {
				break; // done
			} else if (remaining <= 0) { 
				cur = stk.top();
				stk.pop();
				--steps;
				remaining += cur;
				cur1 = stk.top();

				while (cur == (cur1-1)) {
					// smallest choice. need to remove next in stack
					cur = stk.top();
					stk.pop();
					--steps;
					remaining += cur;
					cur1 = stk.top();
				}

				--cur;
				stk.push(cur);
				++steps;
				remaining -= cur;

			} else {
				// remaining > 0;
				++cur;

				stk.push(cur);
				++steps;
				remaining -= cur;

			}
		}
		cout << steps << endl;
	}
}
