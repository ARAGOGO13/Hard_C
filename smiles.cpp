#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool is_smile(string s) {
	string first_string = s;
	if (s[0] == ';') {
		if (s.rfind(';') != string::npos) {
			for (unsigned int i = s.find(';') + 1; i < s.rfind(';'); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	if (s[0] == ':') {
		if (s.rfind(':') != string::npos) {
			for (unsigned int i = s.find(':') + 1; i < s.rfind(':'); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':' || s[i] == ';') s.erase(i, 1);
	}
	if (s.rfind('-') != string::npos) {
		for (int i = s.find('-') + 1; i < s.rfind('-'); i++) {
			if (s[i - 1] != s[i]) return false;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') s.erase(i, 1);
	}
	if (s[0] == '(') {
		if (s.rfind('(') != string::npos){
			for (int i = s.find('(') + 1; i < s.rfind('('); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	if (s[0] == ')') {
		if (s.rfind(')') != string::npos) {
			for (int i = s.find(')') + 1; i < s.rfind(')'); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	if (s[0] == '[') {
		if (s.rfind('[') != string::npos) {
			for (int i = s.find('[') + 1; i < s.rfind('['); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	if (s[0] == ']') {
		if (s.rfind(']') != string::npos) {
			for (int i = s.find(']') + 1; i < s.rfind(']'); i++) {
				if (s[i - 1] != s[i]) return false;
			}
		}
	}
	if (s.find(')') == string::npos && s.find('(') == string::npos && s.find(']') == string::npos && s.find('[') == string::npos) return false;
	for (int i = 0; i < first_string.size(); i++) {
		if (first_string[i] !=  ';' && first_string[i] != ':' && first_string[i] != '-' && first_string[i] != '(' && first_string[i] != ')' && first_string[i] != ']' && first_string[i] != '[') {
			return false;
		}
	}
	return true;
}

int main()
{
	int count = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':' || s[i] == ';') {
			string new_s;
			for (int j = i; j < s.size(); j++) {
				if (s[j] != '(' && s[j] != ')' && s[j] != ']' && s[j] != '[' && j < s.size()) {
					new_s.push_back(s[j]);
				}
				else {
					new_s.push_back(s[j]);
					break;
				}
			}
			if (is_smile(new_s)) {
				count++;
				i += new_s.size() - 1;
			}
		}
		
	}
	cout << count;
	return 0;
}