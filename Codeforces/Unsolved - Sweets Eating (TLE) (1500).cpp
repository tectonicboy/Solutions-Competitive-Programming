#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

//Random place I chose to calculate how much I'd need to get
//on my Final Year Project & Advanced Databasesin order to get 
//a First Class Honors degree.
//Calculation turned out to be kinda wrong cuz I got a few % less on it
//But still got a First Class Honors. 
//Has nothing to do with the competitive programming problem.

void calculate_average_for_various_DB_grades_and_85_project(void) {
	double functional_prog = 92.8, theory_of_comp = 64.7, DSP = 60, Compilers = 78.6, project = 85, DB = 73, overall = 0, year3 = 0;
	for (int i = 70; i <= 90; ++i) {
		year3 = (functional_prog + theory_of_comp + DSP + Compilers + i + i + i + DB) / 8;
		overall = 23.8 + (0.6 * year3);
		cout << "project grade: " << i << "\t|\toverall: " << overall << "\n";
	}
}

int main() {
	calculate_average_for_various_DB_grades_and_85_project();
	
	//Solution to competitive programming problem starts here.
	
	int sweets = 0, per_day = 0, current_total = 0, counter = 0, z = 0, input_sweetness;
	cin >> sweets >> per_day;
	//Idea: Instead, make a vector of size (maximum initial sweetness) and put sweetness of X in cell X so that it's already sorted, kinda.
	//maybe keep a track of which cells were populated, idk.
	vector<int>origSugars(sweets);
	for (int i = 0; i < sweets; ++i) {
		cin >> origSugars[i];
	}
	sort(origSugars.begin(), origSugars.end());
	cout << "\n";
	vector<int>::const_iterator it;
	for (int x = 1; x <= sweets; ++x) {
		current_total = 0;
		z = 1;
		it = origSugars.begin() + (x-1);
		counter = 0;
		while (counter < x) {
			if ((counter > 0) &&(counter % per_day) == 0) {
				++z;
			}
			current_total += z * (*(it));
			++counter;
			if (it > origSugars.begin()) {
				--it;
			}
		}
		cout << current_total << " ";
	}
	cout << "\n";
	 
	return 0;
}