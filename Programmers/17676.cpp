#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class timee {
	private:
		int hour = 0;
		int minute = 0;
		double second = 0;

	public:
		timee(const timee &t) : hour(t.hour), minute(t.minute), second(t.second) {}
		timee(string s_time) {
			vector<string> time(3);

			istringstream ss(s_time);
			getline(ss, time[0], ':');
			getline(ss, time[1], ':');
			getline(ss, time[2], ':');

			hour = stoi(time[0]);
			minute = stoi(time[1]);
			second = stod(time[2]);
		}


		void print() { cout << hour << ':' << minute << ':' << second; }

		friend ostream& operator << (ostream& os, timee t) {
			os << t.hour << ':' << t.minute << ':' << t.second;
			return os;
		}

		friend bool operator < (const timee &a, const timee &b) {
			if(a.hour != b.hour) return a.hour < b.hour;
			if(a.minute != b.minute) return a.minute < b.minute;
			return a.second < b.second;
		}

		timee operator - (const double &s) {
			timee rt(*this);
			rt.second -= s;
			if(rt.second < 0) {
				--rt.minute;
				rt.second += 60;
			}
			if(rt.minute < 0) {
				--rt.hour;
				rt.minute += 60;
			}

			return rt;
		}
};

int solution(vector<string> lines) {
	int max = 0;
	vector<pair<timee, char>> v;
	for(string s : lines) {
		//마지막 s 제거
		istringstream ss(s.substr(0, s.size() - 1));
		// day는 더미
		string day, time;
		double rate;
		ss >> day >> time >> rate;

		timee t(time);
		v.push_back(pair<timee, char>(t, 'O'));
		v.push_back(pair<timee, char>(t - rate, 'I'));
	}

	sort(v.begin(), v.end());
	int count = 0;
	for(auto i : v) {
		i.first.print();
		if(i.second == 'I') {
			cout << " Input " << endl;
			if(++count > max) max = count;
		}else {
			cout << " Output " << endl;
			--count;
		}

		cout << "C : " << count << " M : " << max << endl;
	}

	return max;
}

int main() {
	vector<string> lines = {
		"2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s"
	};

	cout << solution(lines) << endl;

	return 0;
}
