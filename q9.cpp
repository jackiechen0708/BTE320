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
#include <sys/resource.h>
//constexpr int N = 1;
//constexpr int N = 2;
//constexpr int N = 3;
//constexpr int N = 5;
//constexpr int N = 10;
//constexpr int N = 20;
//constexpr int N = 30;
//constexpr int N = 50;
constexpr int N = 100;
using namespace std;
struct people
{
	int id;
	string first_name;
	string last_name;
	int birthday;
	string home;

};

constexpr int N1000 = 1000 * N;
people people_array[N1000];
void readData(people people_array[], const int arr_size) {
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
		for (int i = 0; i< arr_size; i++)
		{
			if (input.fail()) break;
			input >> people_array[i].id >> people_array[i].first_name >> people_array[i].last_name >> people_array[i].birthday >> people_array[i].home;

		}
	}
	input.close();
}

void searchPeople(people people_array[], int const arr_size)
{
	cout << "Please input the person name: ";
	string first_name, last_name;
	cin >> first_name >> last_name;
	for (int i = 0; i<arr_size; i++)
	{
		if (first_name == people_array[i].first_name || last_name == people_array[i].last_name)
		{
			cout << people_array[i].id << " " << people_array[i].first_name << " " << people_array[i].last_name << " " << people_array[i].birthday << " " << people_array[i].home << endl;
			break;
		}
	}
}


void selectionSort(people people_array[], int const arr_size) {
	for (int i = 0; i<arr_size; i++) {
		int oldest = i;
		// find the oldest
		for (int j = i + 1; j<arr_size; j++) {
			if (people_array[j].birthday < people_array[oldest].birthday) {
				oldest = j;
			}
		}
		// swap the oldest
		if (oldest != i) {
			people tmp = people_array[i];
			people_array[i] = people_array[oldest];
			people_array[oldest] = tmp;
		}
	}
}

void storeData(people people_array[], const int arr_size) {
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
		for (int i = 0; i<arr_size; i++)
		{
			output << people_array[i].id << " " << people_array[i].first_name << " " << people_array[i].last_name << " ";
			output << people_array[i].birthday << " " << people_array[i].home << endl;
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

int main()
{
	readData(people_array, N1000);
	searchPeople(people_array, N1000);
	double start = get_cpu_time();
	selectionSort(people_array, N1000);
	double end = get_cpu_time();
	cout << N1000 << "  " << start << "  " << end << "  " << end - start << endl;
	storeData(people_array, N1000);


}
