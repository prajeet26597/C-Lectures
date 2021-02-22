#include <iostream>
#include<cmath>

using namespace std;

const int TWO_REAL = 2;
const int ONE_REAL = 1;
const int NO_REAL = 0;
const int ALL_REAL = 8;
const int NO_SOLN = -1;

void nchoosek();
int factorial(int num);
int Kcombinations(int n, int k);
void analyzingdig();
int calcnumdig(int num, int& sum);
void solnquad();
int quadraticeqn(double a, double b, double c, double& outx1, double& outx2);
int lineareqn(double a, double b, double& outx1);

int main() {
	
	int select;

	
	cout << "####~~~~~~~~~~~~~#Advanced Programming in C++#~~~~~~~~~~~~~~~####" << endl;
	cout << "####~~~~~~~~~~~~~~~~~#Lecture-1 Functions#~~~~~~~~~~~~~~~~~~~####" << endl;
	cout << "              1. K-Combinations Problem" << endl;
	cout << "              2. Analyzing Digits" << endl;
	cout << "              3. Solution to Quadratic Equations" << endl;
	cout << "####~~~~~~~~~~~~~~~~#Select one#~~~~~~~~~~~~~~~~~~####" << endl;

	cin >> select;

	switch (select) {
	case 1: nchoosek();
		break;
	case 2: analyzingdig();
		break;
	case 3: solnquad();
		break;
	default: cout << "Program Exit";
		break;
	}


	return 0;
}
void nchoosek() {
	
	int n, k, k_comb;

	label:
	cout << "Please enter values for n and k (k<=n)" << endl;
	cin >> n >> k;
	if (n >= k) {
		k_comb = Kcombinations(n, k);
	}
	else {
		cout << "Enter n value greater than k" << endl;
		goto label;
	}

	cout << n << " combination " << k << " is: " << k_comb;
}

int Kcombinations(int n, int k) {
	int nFact, kFact, n_kFact;

	nFact = factorial(n);
	kFact = factorial(k);
	n_kFact = factorial(n - k);

	return(nFact / (kFact * n_kFact));

}

int factorial(int num) {

	int numFact = 1;

	for (int i = 1; i <= num; ++i)
		numFact *= i;

	return numFact;
}

void analyzingdig() {

	int num, digsum, numdig;
	cout << "Please enter the number" << endl;
	cin >> num;

	numdig = calcnumdig(num, digsum);

	cout << "  " << numdig << " is the number of digits and " << 
		digsum << " is the sum of the digits" << endl;
}

int calcnumdig(int num, int& digsum) {
	int count = 0, sum = 0;

	while (num > 0) {
		int temp = num % 10;
		count++;
		sum += temp;
		num /= 10;
	}
	digsum = sum;
	return count;
}

void solnquad(){
	double a, b, c, outx1, outx2;

	cout << "Please enter the coefficients of the equation" << endl;
	cin >> a >> b >> c;

	switch (quadraticeqn(a, b, c, outx1, outx2)) {
	case TWO_REAL: cout << "THere are two real solutions and those are " 
		<< outx1 << " and " << outx2 << endl;
		break;
	case ONE_REAL: cout << "There is one real solution to this problem \
		which is " << outx1 << endl;
		break;
	case NO_REAL: cout << " There is no real solution to this problem" 
		<< endl;
		break;
	case ALL_REAL: cout << "All numbers are solutions" << endl;
		break;
	case NO_SOLN: cout << "The equation does not match as " << c << " \
		does not equal zero" << endl;
		break;
	default: cout << "ERROR!" << endl;
		break;
	}
}

int quadraticeqn(double a, double b, double c, double& outx1, double& outx2) {
	double delta, x1, x2;

	if (a != 0.0) {
		delta = b * b - 4 * a * c;
		if (delta > 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			outx1 = x1;
			outx2 = x2;
			return TWO_REAL;
		}
		else if (delta == 0) {
			x1 = -b / (2 * a);
			outx1 = x1;
			return ONE_REAL;
		}
		else {
			return NO_REAL;
		}
	}
	else {
		return lineareqn(b, c, outx1);
	}
}

int lineareqn(double a, double b, double& outx1) {
	double x1;

	if (a != 0) {
		x1 = -b / a;
		outx1 = x1;
		return ONE_REAL;
	}
	else if (a == 0 && b == 0) {
		return ALL_REAL;
	}
	else {
		return NO_SOLN;
	}
}