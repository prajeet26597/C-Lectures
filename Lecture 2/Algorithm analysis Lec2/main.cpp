// Algorithm analysis 
// Analyse the runtime difference between three versions
// version 1: Check for primality from 1 to the given number
// version 2: Check from 1 to the half of given number
// version 3: Check from 1 to square root of the given number

#include<iostream>
#include<cmath>
#include<chrono>

using namespace std;

bool first_version(int num);
bool second_version(int num);
bool third_version(int num);

int main() {
	int num;
	string opt;

	cout << "          ####~~~~~~~~~~~~~~~~~~PRIMALITY TEST~~~~~~~~~~~~~~~~~~~####" << endl;
	cout << "Please enter a number greater than 2 to check for primality and the program gives" << endl;
	cout << "you the results based on three versions which are:" << endl;
	cout << "First version: Check for primality from 1 to the given number" << endl;
	cout << "Second version: Check from 1 to the half of given number" << endl;
	cout << "Third version: Check from 1 to square root of the given number" << endl;
	
	label1:
	cout << "Enter the number for primality test : ";
	cin >> num;

	if (num < 3){
		cout << "The number entered is not greater than 2, please enter again" << endl;
		goto label1;
	}
	else {


		auto t1_started = chrono::high_resolution_clock::now();
		bool prime_1 = first_version(num);
		auto t1_ended = chrono::high_resolution_clock::now();

		auto t2_started = chrono::high_resolution_clock::now();
		bool prime_2 = second_version(num);
		auto t2_ended = chrono::high_resolution_clock::now();

		auto t3_started = chrono::high_resolution_clock::now();
		bool prime_3 = third_version(num);
		auto t3_ended = chrono::high_resolution_clock::now();

		auto duration_1 = chrono::duration_cast<chrono::nanoseconds> (t1_ended - t1_started).count();
		auto duration_2 = chrono::duration_cast<chrono::nanoseconds> (t2_ended - t2_started).count();
		auto duration_3 = chrono::duration_cast<chrono::nanoseconds> (t3_ended - t3_started).count();

		if (prime_1 == true && prime_2 == true && prime_3 == true) {
			cout << " The number " << num << " is a prime number!" << endl;
			cout << " The duration taken for the first version is: " << duration_1 << " nanoseconds" << endl;
			cout << " The duration taken for the second version is: " << duration_2 << " nanoseconds" << endl;
			cout << " The duration taken for the third version is: " << duration_3 << " nanoseconds" << endl;
		}
		else {
			cout << " The number " << num << " is not a prime number!" << endl;
			cout << " The duration taken for the first version is: " << duration_1 << " nanoseconds" << endl;
			cout << " The duration taken for the second version is: " << duration_2 << " nanoseconds" << endl;
			cout << " The duration taken for the third version is: " << duration_3 << " nanoseconds" << endl;
		}
	}

	cout << "Do you want tot check for another number (Y/N): ";
	cin >> opt;

	if (opt == "Y" || opt == "y")
		goto label1;

}

bool first_version(int num) {
	int countdiv = 0;

	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			countdiv++;
	}

	if (countdiv == 2) 
		return true;
	else
		return false;
}

bool second_version(int num) {
	int countdiv = 0;

	for (int i = 1; i <= num/2; i++) {
		if (num % i == 0)
			countdiv++;
	}

	if (countdiv == 1)
		return true;
	else
		return false;
}

bool third_version(int num) {
	int countdiv = 0;

	for (int i = 1; i <= sqrt(num); i++) {
		if (num % i == 0)
			countdiv++;
	}

	if (countdiv == 1)
		return true;
	else
		return false;
}