/*
N1000 start end time
1000  0  0.004  0.004
2000  0  0.008  0.008
3000  0  0.02  0.02
5000  0  0.056  0.056
10000  0.004  0.22  0.216
20000  0.008  0.864  0.856
30000  0.012  1.932  1.92
50000  0.024  5.56  5.536
100000  0.048  21.576  21.528


I find that time grows in square
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <sys/resource.h>
#include <list>
//constexpr int N = 1;
//constexpr int N = 2;
//constexpr int N = 3;
//constexpr int N = 5;
//constexpr int N = 10;
//constexpr int N = 20;
//constexpr int N = 30;
//constexpr int N = 50;
constexpr int N = 1;
constexpr int N1000 = 1000 * N;
using namespace std;
struct people
{
	int id;
	string first_name;
	string last_name;
	int birthday;
	string home;
	list<people> friends;

};

vector<people> people_vector;

int random_in_range(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first) {
		srand((int)time(NULL)); //seeding for the first time only!
		first = false;
	}
	return min + rand() % (max - min);
}

void readData(vector<people>& people_vector) {
	stringstream convert;
	convert << "people" << N << ".txt";
	string file;
	convert >> file;

	ifstream input(file);
	if (input.fail())
	{
		cout << " open failed" << endl;
	}
	else
	{
		for (int i = 0;; i++)
		{
			if (input.fail()) break;
			people tmp;
			input >> tmp.id >> tmp.first_name >> tmp.last_name >> tmp.birthday >> tmp.home;
			people_vector.push_back(tmp);

		}
	}
	input.close();
}

void searchPeople(const vector<people>& people_vector)
{
	cout << "Please input the person name: ";
	string first_name, last_name;
	cin >> first_name >> last_name;
	for (int i = 0; i<people_vector.size(); i++)
	{
		if (first_name == people_vector[i].first_name || last_name == people_vector[i].last_name)
		{
			cout << people_vector[i].id << " " << people_vector[i].first_name << " " << people_vector[i].last_name << " " << people_vector[i].birthday << " " << people_vector[i].home << endl;
			break;
		}
	}
}


void selectionSort(vector<people>& people_vector) {
	for (int i = 0; i<people_vector.size(); i++) {
		int oldest = i;
		// find the oldest
		for (int j = i + 1; j<people_vector.size(); j++) {
			if (people_vector[j].birthday < people_vector[oldest].birthday) {
				oldest = j;
			}
		}
		// swap the oldest
		if (oldest != i) {
			people tmp = people_vector[i];
			people_vector[i] = people_vector[oldest];
			people_vector[oldest] = tmp;
		}
	}
}

void storeData(const vector<people>& people_vector) {
	stringstream convert;
	convert << "People" << N << "_result.txt";
	string file;
	convert >> file;
	ofstream output(file);
	if (!output)
	{
		cout << "failed" << endl;
	}
	else
	{
		for (int i = 0; i<people_vector.size(); i++)
		{
			output << people_vector[i].id << " " << people_vector[i].first_name << " " << people_vector[i].last_name << " ";
			output << people_vector[i].birthday << " " << people_vector[i].home << endl;
		}
		output.close();
	}
}

double get_cpu_time()
{
	struct rusage ruse;
	getrusage(RUSAGE_SELF, &ruse);
	return ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.0 + ruse.ru_stime.tv_sec + ruse.ru_stime.tv_usec / 1000000.0;
}

void addFriends(vector<people>& people_vector) {
	for (int i = 0; i < people_vector.size(); i++) {
		int num_of_friends = random_in_range(0, N1000 / 200);
		for (int j = 0; j < num_of_friends; j++) {
			people_vector[i].friends.push_back(people_vector[random_in_range(0, N1000 - 1)]);
		}
	}
}

void selectionSortByFriends(vector<people>& people_vector){
	for (int i = 0; i<people_vector.size(); i++) {
		int oldest = i;
		// find the oldest
		for (int j = i + 1; j<people_vector.size(); j++) {
			if (people_vector[j].friends.size() > people_vector[oldest].friends.size()) {
				oldest = j;
			}
		}
		// swap the oldest
		if (oldest != i) {
			people tmp = people_vector[i];
			people_vector[i] = people_vector[oldest];
			people_vector[oldest] = tmp;
		}
	}
}

void findCommonFriends(const vector<people>& people_vector) {
	for (int i = 0; i < people_vector.size(); i++) {
		for (int j = 0; j < people_vector.size(); j++) {
			if (i != j) {
				for (auto iter1 = people_vector[i].friends.begin(); iter1 != people_vector[i].friends.end(); iter1++) {
					for (auto iter2 = people_vector[j].friends.begin(); iter2 != people_vector[j].friends.end(); iter2++) {
						if (iter1->id == iter2->id) {
							cout << people_vector[i].first_name << " " << people_vector[j].first_name << " common friends : ";
							cout << iter1->first_name << endl;
						}
					}
				}
			}
		}
	}
}


void findFriends(const vector<people>& people_vector) {
	for (int i = 0; i < people_vector.size(); i++) {
		cout << people_vector[i].first_name << ":";
		for (int j = 0; j < people_vector.size(); j++) {
			if (i != j) {
				for (auto iter2 = people_vector[j].friends.begin(); iter2 != people_vector[j].friends.end(); iter2++) {
					if (people_vector[i].id == iter2->id) {
						cout << people_vector[j].first_name << ",";
						break;
					}
				}
				
			}
		}
		cout << endl;
	}
}

void unFriends(vector<people> & people_vector) {
	for (int i = 0; i < people_vector.size(); i++) {
		int num_of_friends = random_in_range(0, people_vector[i].friends.size()/2);
		for (int j = 0; j < num_of_friends; j++) {
			people_vector[i].friends.pop_back();
		}
	}
}

int main()
{
	readData(people_vector);
	//searchPeople(people_vector);
	//double start = get_cpu_time();
	//selectionSort(people_vector);
	//double end = get_cpu_time();
	//cout << N1000 << "  " << start << "  " << end << "  " << end - start << endl;
	addFriends(people_vector);
	double start = get_cpu_time();
	selectionSortByFriends(people_vector);
	double end = get_cpu_time();
	cout << N1000 << "  " << start << "  " << end << "  " << end - start << endl;
	findCommonFriends(people_vector);
	findFriends(people_vector);
	storeData(people_vector);


	start = get_cpu_time();
	selectionSortByFriends(people_vector);
	end = get_cpu_time();
	cout << N1000 << "  " << start << "  " << end << "  " << end - start << endl;


}
