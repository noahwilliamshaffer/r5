/* an example program for
 *
 * COP 4530
 * Department of Computer Science
 * Florida State University
 * */
#include <iostream>

using namespace std;

void totalSteps(int cur, int remaining, int steps, int& total) {
    // cout << cur << " " << remaining << " " << steps << " " << total << endl;
    if (remaining == 0) {
	if (cur == 2 || cur == 1) {
	    // found one 
	    if (total < 0 || steps < total) {
		total = steps;
	    }
	}
	// cout << "total =" << total << endl;
	return;
    } else if (remaining < 0 || (total > 0 && steps > total)) 
	return;

    // otherwise, continue searching
    // three possible ways

    // cur + 1
    totalSteps(cur + 1, remaining - cur - 1, steps + 1, total);
    
    // cur
    totalSteps(cur, remaining - cur, steps + 1, total);
    
    // cur -1 
    if (cur > 1) {
	totalSteps(cur - 1, remaining - cur + 1, steps + 1, total);
    }
}

main() {
    int numline, first, last, distance;
    int steps, total;

    while (cin >> first >> last) {
	distance = last - first;
	steps = 2;
	total = -1;
	totalSteps(1, distance - 2, steps, total);
	cout << total << endl;
    }
}
