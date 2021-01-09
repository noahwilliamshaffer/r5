#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cstdlib>

using namespace std;

#include "sequential_search.cpp"

int main() {
    static const int cnt = 10;
    int val, idx;
    vector<int> vint;
    vector<string> vstr;
    
    srand(9999);

    // pushing in 10 numbers
    for (int i = 0; i < cnt; ++i) {
	vint.push_back(rand());
    }

    // print out the content of the vector
    copy(vint.begin(), vint.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "test integer" << endl;
    idx = sequential_search(vint, vint[5]);
    if (idx < 0) {
	cout << "ERROR: did not find an element in the vector" << endl;
    } else {
	cout << "Found at posision " << idx << endl;
    }

    int tmp = -vint[5];
    if (sequential_search(vint, tmp) >= 0) {
	cout << "ERROR: Found element not in the vector" << endl;
    }

    cout << "testing string" << endl;
    vstr.push_back("test1");
    vstr.push_back("test2");
    idx = sequential_search(vstr, vstr[1]);
    if (idx < 0) {
	cout << "ERROR: did not find an element in the vector" << endl;
    } else {
	cout << "Found at posision " << idx << endl;
    }

    string str("test3");
    if (sequential_search(vstr, str) >= 0) {
	cout << "ERROR: Found element not in the vector" << endl;
    }

    cout << "SUCCESS: All tests passed" << endl;
    
    return(0);
}
