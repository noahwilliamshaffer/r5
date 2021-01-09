#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;
bool isPalindrome(const string & str, int left, int right);

int main() {
	string line;

	while (getline(cin, line)) {
		transform(line.begin(), line.end(), line.begin(),
					static_cast<int(*)(int)>(tolower));
		cout << line << ": ";
		if (isPalindrome(line, 0, line.length()-1)) {
			cout << "a palindrome" << endl;
		} else {
			cout << "not a palindrome" << endl;
		}

	}
	return(EXIT_SUCCESS);
}

bool isPalindrome(const string & str, int left, int right) {
	if (right - left <= 1) {
		return true;
	} else {
		if (str[right] == str[left]) {
			return isPalindrome(str, ++left, --right);
		} else 
			return false;
	}
}
