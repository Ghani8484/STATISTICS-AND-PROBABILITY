#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream> // Include this header for stringstream

using namespace std;

// Structure to store employee data
struct Employee {
    string employeeID;
    string fullName;
    string jobTitle;
    string department;
    string businessUnit;
    string gender;
    string ethnicity;
    int age;
    string hireDate;
    double salary;
    double bonusPercentage;
    string country;
    string city;
    string exitDate;
};

// Function to read employee data from file
vector<Employee> readEmployeeDataFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream file("Employee Data.csv");

    if (file.is_open()) {
        string line;
        getline(file, line); // Skip header line

        while (getline(file, line)) {
            Employee employee;
            stringstream ss(line);

            getline(ss, employee.employeeID, '\t');
            getline(ss, employee.fullName, '\t');
            getline(ss, employee.jobTitle, '\t');
            getline(ss, employee.department, '\t');
            getline(ss, employee.businessUnit, '\t');
            getline(ss, employee.gender, '\t');
            getline(ss, employee.ethnicity, '\t');
            ss >> employee.age;
            ss.ignore();
            getline(ss, employee.hireDate, '\t');
            ss >> employee.salary;
            ss.ignore();
            ss >> employee.bonusPercentage;
            ss.ignore();
            getline(ss, employee.country, '\t');
            getline(ss, employee.city, '\t');
            getline(ss, employee.exitDate, '\t');

            employees.push_back(employee);
        }

        file.close();
    }

    return employees;
}

// Function to draw a random sample of size N from salary column
vector<double> drawRandomSample(const vector<Employee>& employees, int N) {
    vector<double> sample;

    srand(time(0)); // Initialize random seed

    for (int i = 0; i < N; i++) {
        int index = rand() % employees.size();
        sample.push_back(employees[index].salary);
    }

    return sample;
}

int main() {
    // Step 1: Read employee data from file
    vector<Employee> employeeData = readEmployeeDataFromFile("Employee Data.csv");

    // Step 2: Draw a random sample of size N=10 from salary column and apply (repeat 300 times)
    vector<double> zValues;

    for (int i = 0; i < 300; i++) {
        vector<double> sample = drawRandomSample(employeeData, 10);
        
        // Apply your calculations on the sample and store the resultant values of z in the zValues array
        // ...

        // For demonstration purposes, let's print the sample
        cout << "Sample " << i+1 << ": ";
        for (double value : sample) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Step 3: Plot the results or perform any further analysis
    // ...

    // Step 4: Repeat steps 2 and 3 for N=300 and compare with the plot of step 3
    // ...

    return 0;
}
