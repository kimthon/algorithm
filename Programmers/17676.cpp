#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

double stodTime(string s_time) {
	double time = 0;
	vector<string> v_time(3);

	istringstream ss(s_time);
	getline(ss, v_time[0], ':');
	getline(ss, v_time[1], ':');
	getline(ss, v_time[2], ':');

	time += stod(v_time[0])*60.0*60;
	time += stod(v_time[1])*60;
	time += stod(v_time[2]);

	return time;
}

int solution(vector<string> lines) {
	int max = 0;
	vector<pair<double, double>> v;
	for(string s : lines) {
		//마지막 s 제거
		istringstream ss(s.substr(0, s.size() - 1));

		// day는 더미
		string day, time; double rate;
		ss >> day >> time >> rate;

		double d_time = stodTime(time);
		v.push_back({d_time - rate + 0.001, d_time});
	}

	for(int i = 0; i < (int)v.size(); ++i) {
		int count = 1;
		double end = v[i].second + 1;
		for(int j = i + 1; j < (int)v.size(); ++j) {
			double start = v[j].first;
			if(start < end) ++count;
		}
		if(max < count) max = count;
	}

	return max;
}

int main() {
	vector<string> lines = {
		"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"
	};

	cout << solution(lines) << endl;

	return 0;
}
