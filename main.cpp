#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
#include "AsbestosReport.h"
#include "Technician.h"
#include "Employee.h"

int main() {

    //Inputs Company Employee List
    //Done for every report
    ifstream myFile;
    string fileName = "EmployeeList.txt";
    myFile.open(fileName);

    if (!myFile.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }

    vector<Employee*> employees;
    while (!myFile.eof()) {
        string departmentName, firstName, lastName, address, cityState, status;
        int zipCode, employeeCount;
        double salary;

        myFile >> departmentName >> employeeCount;
        for (int i = 0; i < employeeCount; i++) {
            myFile >> firstName >> lastName;
            myFile.ignore();
            getline(myFile, address);
            getline(myFile, cityState);
            myFile >> zipCode;
            myFile >> status;
            myFile >> salary;
            if (departmentName == "Technician") {
                string asbLicense, moldLicense, leadLicense;
                myFile >> asbLicense;
                myFile >> moldLicense;
                myFile >> leadLicense;
                employees.push_back(new Technician(departmentName, firstName,lastName,
                    address,cityState,zipCode,status,salary,
                    asbLicense,moldLicense, leadLicense));
            }
            else {
                employees.push_back(new Employee(departmentName, firstName,lastName,
                    address,cityState,zipCode,status,salary));
            }
        }
    }
    myFile.close();

    //Begin Environmental Report Builder User Interaction
    cout << "ENVIRONMENTAL REPORT BUILDER" << endl;
    cout << string(26, '-') << endl;
    bool choiceExists = false;
    do {
        //Select Report Type
        int reportType;
        cout << "Select Type of Report:" << endl;
        cout << "[1] Asbestos" << endl;
        cout << "Enter choice: ";
        cin >> reportType;

        switch (reportType) {
            case 1: {
                AsbestosReport report;
                do {
                    //Allows for manual input or txt file input
                    int inputType;
                    cout << "How would you like to input information?" << endl;
                    cout << "[1] Manually" << endl;
                    cout << "[2] From File" << endl;
                    cout << "Enter choice: ";
                    cin >> inputType;
                    cin.ignore();
                    switch (inputType) {
                        case 1: {
                            choiceExists = true;
                            report.inputManually();
                            break;
                        }
                        case 2: {
                            choiceExists = true;
                            report.inputFromFile();
                            break;
                        }
                        default:
                            cout << "Invalid choice." << endl;
                            break;
                    }
                }while (!choiceExists);

                choiceExists = false;
                //Allows for editing of samples or prints report
                do {
                    int inputType;
                    cout << "What would you like to do: " << endl;
                    cout << "[1] Review and Edit Samples" << endl;
                    cout << "[2] Print Asbestos Report and Quit" << endl;
                    cout << "Enter choice: ";
                    cin >> inputType;
                    cin.ignore();
                    switch (inputType) {
                        case 1: {
                            report.editSamples();
                            break;
                        }
                        case 2: {
                            choiceExists = true;
                            report.printReportInformation();
                            break;
                        }
                        default:
                            cout << "Invalid choice." << endl;
                            break;
                    }
                } while (!choiceExists);
                break;
            }

            // case 2 - case n
            // -> For future implementations of other reports

            default:
                cout << "Invalid choice." << endl;
                break;
        }

    } while (!choiceExists);
    return 0;
}