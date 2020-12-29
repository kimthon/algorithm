#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool comp(string s1, string s2) {
	if(s1.length() == s2.length()) return s1 < s2;
	else return s1.length() < s2.length();
}

bool solution(vector<string> phone_book) {
	int size = 0;
	unordered_multiset<string> us;
	sort(phone_book.begin(), phone_book.end(), comp);
	for(auto i = phone_book.begin(); i != phone_book.end(); ++i) {
		if(size != (int)i->length()) {
			size = i->length();
			us.clear();

			for(auto j = i + 1; j != phone_book.end(); ++j) {
				string tmp = j->substr(0, size);

				cout << tmp << ' ';
				if(us.find(tmp) == us.end()) us.insert(tmp);
				else return false;
			}
			cout << endl;
		}else us.erase(*i);

		cout << *i << endl;
		if(us.find(*i) != us.end()) return false;
	}

	return true;
}

int main() {
	vector<string> pb = {"123", "456", "789"};
	cout << solution(pb) << endl;
	return 0;
}
