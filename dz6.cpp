#include <iostream>
#include <algorithm>
using namespace std;


void initMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = rand() % 100;
}

void initMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = (double)(rand() % 100) / 10.0;
}

void initMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 'A' + rand() % 26;
}


void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}


void findMinMaxOnDiagonal(int** matrix, int size) {
    int min = matrix[0][0], max = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
    cout << "Min on diagonal: " << min << ", Max on diagonal: " << max << endl;
}

void findMinMaxOnDiagonal(double** matrix, int size) {
    double min = matrix[0][0], max = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
    cout << "Min on diagonal: " << min << ", Max on diagonal: " << max << endl;
}


void sortRows(int** matrix, int size) {
    for (int i = 0; i < size; ++i)
        sort(matrix[i], matrix[i] + size);
}

void sortRows(double** matrix, int size) {
    for (int i = 0; i < size; ++i)
        sort(matrix[i], matrix[i] + size);
}

int main() {
    int size = 4;


    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i)
        intMatrix[i] = new int[size];
    initMatrix(intMatrix, size);
    printMatrix(intMatrix, size);
    findMinMaxOnDiagonal(intMatrix, size);
    sortRows(intMatrix, size);
    printMatrix(intMatrix, size);


    for (int i = 0; i < size; ++i)
        delete[] intMatrix[i];
    delete[] intMatrix;

    return 0;
}






using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}







#include <sstream>

string intToString(int num) {
    ostringstream ss;
    ss << num;
    return ss.str();
}


string secret = to_string(rand() % 9000 + 1000);
string secret = intToString(rand() % 9000 + 1000);
















#include <iostream>
using namespace std;


bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}


int daysInMonth(int month, int year) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}


int daysFromStartOfYear(int day, int month, int year) {
    int totalDays = 0;
    for (int m = 1; m < month; ++m)
        totalDays += daysInMonth(m, year);
    totalDays += day;
    return totalDays;
}


int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    const int daysInYear = 365;
    int totalDays1 = 0, totalDays2 = 0;


    for (int y = 1; y < year1; ++y) {
        totalDays1 += isLeapYear(y) ? 366 : 365;
    }
    totalDays1 += daysFromStartOfYear(day1, month1, year1);


    for (int y = 1; y < year2; ++y) {
        totalDays2 += isLeapYear(y) ? 366 : 365;
    }
    totalDays2 += daysFromStartOfYear(day2, month2, year2);

    return abs(totalDays2 - totalDays1);
}

int main() {
    int day1, month1, year1, day2, month2, year2;
    cout << "Enter first date (day month year): ";
    cin >> day1 >> month1 >> year1;
    cout << "Enter second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    int diff = dateDifference(day1, month1, year1, day2, month2, year2);
    cout << "Difference in days: " << diff << endl;

    return 0;
}


























#include <iostream>
#include <vector>
using namespace std;

double calculateAverage(const vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];
    return (double)sum / arr.size();
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    double average = calculateAverage(arr);
    cout << "Average: " << average << endl;

    return 0;
}























#include <iostream>
#include <vector>
using namespace std;

void countElements(const vector<int>& arr, int& positives, int& negatives, int& zeros) {
    positives = 0;
    negatives = 0;
    zeros = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0)
            positives++;
        else if (arr[i] < 0)
            negatives++;
        else
            zeros++;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    int positives, negatives, zeros;
    countElements(arr, positives, negatives, zeros);

    cout << "Positives: " << positives << endl;
    cout << "Negatives: " << negatives << endl;
    cout << "Zeros: " << zeros << endl;

    return 0;
}
