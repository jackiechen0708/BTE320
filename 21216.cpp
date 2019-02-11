#include <iostream>
#include <sstream>
#include <string>

struct Student
{
	int id;
	std::string grade_option;
	std::string name;
	int * mark;
	double final_socre;
};


std::string trim(std::string& str)
{
	std::string::size_type pos = str.find_first_not_of(' ');
	if (pos == std::string::npos)
	{
		return str;
	}
	std::string::size_type pos2 = str.find_last_not_of(' ');
	if (pos2 != std::string::npos)
	{
		return str.substr(pos, pos2 - pos + 1);
	}
	return str.substr(pos);
}

int main() {
	// read in graded artifacts
	int grade_num;
	std::cin >> grade_num;
	int *points = new int[grade_num];
	int *weights = new int[grade_num];

	for (int i = 0; i < grade_num; i++) {
		std::cin >> points[i];
	}

	for (int i = 0; i < grade_num; i++) {
		std::cin >> weights[i];
	}

	// read in students
	int student_num;
	std::cin >> student_num;
	Student * students = new Student[student_num];
	for (int i = 0; i < student_num; i++) {
		std::cin >> students[i].id;
		std::cin >> students[i].grade_option;
		std::getline(std::cin, students[i].name);
		students[i].name = trim(students[i].name);
		students[i].mark = new int[grade_num];
		for (int j = 0; j < grade_num; j++) {
			students[i].mark[j] = 0;
		}
		students[i].final_socre = 0.0;
	}

	/*for (int i = 0; i < student_num; i++) {
		std::cout << students[i].id << " " << students[i].grade_option << " " << students[i].name << std::endl;
	}*/

	// read in scores
	int score_num;
	std::cin >> score_num;
	int cur_id;
	std::string ignore;
	for (int i = 0; i < score_num; i++) {
		std::cin >> cur_id;
		int j = 0;
		while (j<student_num)
		{
			if (students[j].id == cur_id) {
				break;
			}
			j++;
		}
		if (j < student_num) {
			for (int k = 0; k < grade_num; k++) {
				std::cin >> students[j].mark[k];
			}
		}
		else {
			std::getline(std::cin, ignore);
		}
	}

	
	// read in cutpoint sets
	int cutpoints_num;
	std::cin >> cutpoints_num;
	double **cutpoints = new double*[cutpoints_num];
	for (int i = 0; i < cutpoints_num; i++) {
		cutpoints[i] = new double[4];
		for (int j = 0; j < 4; j++) {
			std::cin >> cutpoints[i][j];
		}
	}

	// calculate score

	for (int i = 0; i < student_num; i++) {
		for (int j = 0; j < grade_num; j++) {
			students[i].final_socre += 1.0*students[i].mark[j] / points[j] * weights[j];
		}
	}

	// cout total score
	std::cout << "TOTAL SCORES" << std::endl;

	for (int i = 0; i < student_num; i++) {
		std::cout << students[i].id << " " << students[i].name << " " << students[i].final_socre << std::endl;
	}

	// get course grades
	std::string GRADE[5] = { "A","B","C","D","F" };
	for (int n = 0; n < cutpoints_num; n++) {
		std::cout << "CUTPOINT SET " << n + 1 << std::endl;
		for (int i = 0; i < student_num; i++) {
			std::cout << students[i].id << " " << students[i].name << " ";
			if (students[i].grade_option == "G") {
				bool flag = true;
				for (int j = 0; j < 4; j++) {
					if (students[i].final_socre >= cutpoints[n][j]) {
						std::cout << GRADE[j];
						flag = false;
						break;
					}
				}
				if (flag)
					std::cout << GRADE[4];
			}
			else if (students[i].grade_option == "P") {
				if (students[i].final_socre >= cutpoints[n][2]) {
					std::cout << "P";
				}
				else {
					std::cout << "NP";
				}
			}
			std::cout << std::endl;
		}
	}


	// free memory
	delete[] points;
	delete[] weights;

	for (int i = 0; i < student_num; i++) {
		delete [] students[i].mark ;
	}

	delete[] students;
	for (int i = 0; i < cutpoints_num; i++)
		delete [] cutpoints[i];
	delete[] cutpoints;
	return 0;
}
