#include <iostream>
#include <string>
using namespace std;

// function prototypes
double calcPartTimeSalary(double hours);
double calcPermanentSalary(double basic);

int main() {
    const int MAX = 10; // maximum workers
    string name[MAX], status[MAX];
    double basicSalary[MAX], netSalary[MAX];
    int totalWorker;
    
    cout << "\n---|| Net salary Calculator for Part-time & Permanent Workers ||---\n"<< endl;
    cout << "Enter total number of workers: ";
    cin >> totalWorker;
    
    for (int i = 0; i < totalWorker; i++) {
        cout << "\n------ Worker " << i + 1 << " ------\n";
        cout << "Enter name: ";
        cin >> ws; // clear whitespace
        getline(cin, name[i]);
        
        cout << "Enter status (part-time/permanent): ";
        cin >> status[i];
        
        // check worker type
        if (status[i] == "parttime" || status[i] == "part-time") {
            double hours;
            cout << "Enter total working hours: ";
            cin >> hours;
            
            basicSalary[i] = hours * 45.50;
            netSalary[i] = calcPartTimeSalary(hours);
            
        } else if (status[i] == "permanent" || status[i] == "Permanent") {
            cout << "Enter basic salary (must be > RM3000): RM ";
            cin >> basicSalary[i];
            
            if (basicSalary[i] < 3000) {
                cout << "Invalid! Basic salary must be above RM3000.\n";
                basicSalary[i] = 3000; // set minimum value
            }
            
            netSalary[i] = calcPermanentSalary(basicSalary[i]);
        } else {
            cout << "Invalid status entered! Try again.\n";
            basicSalary[i] = 0;
            netSalary[i] = 0;
        }
    }
    
    // display worker information one by one
    cout << "\n==============================\n";
    cout << "Worker Details\n";
    cout << "==============================\n";
    
    for (int i = 0; i < totalWorker; i++) {
        cout << "\nWorker " << i + 1 << " Details:\n";
        cout << "Name          : " << name[i] << endl;
        cout << "Status        : " << status[i] << endl;
        cout << "Basic Salary  : RM " << basicSalary[i] << endl;
        cout << "Net Salary    : RM " << netSalary[i] << endl;
        cout << "------------------------------\n";
    }

    return 0;
}

// function to calculate net salary for part time
double calcPartTimeSalary(double hours) {
    double basic = hours * 45.50;
    double allowance = 0.10 * basic;
    double net = basic + allowance;
	return net;
}

// function to calculate net salary for permanent worker
double calcPermanentSalary(double basic) {
    double allowance = 0.30 * basic;
    double epf = 0.15 * basic;
    double net = basic + allowance - epf;
	return net;
}