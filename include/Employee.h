#ifndef REPORTSNEW_EMPLOYEE_H
#define REPORTSNEW_EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

/**
* @brief Encapsulates an employee record (ID, department, name, address, city/state, zip, status, salary)
* @author Moises Felix
* @date 10/2/2025
*/
class Employee {
private:
    int employeeID; ///< Unique identifier.
    string departmentName; ///< Department of which the person works in.
    string firstName;
    string lastName;
    string address;
    string cityState;
    int zipCode;
    string status; ///< Whether Full-time, Part-time, Contract, etc.
    double salary;

public:
    ///Getter
    int getEmployeeID();
    ///Setter
    void setDepartmentName(string);
    ///Getter
    string getDepartmentName();
    ///Setter
    void setFirstName(string);
    ///Getter
    string getFirstName();
    ///Setter
    void setLastName(string);
    ///Getter
    string getLastName();
    ///Setter
    void setAddress(string);
    ///Getter
    string getAddress();
    ///Setter
    void setCityState(string);
    ///Getter
    string getCityState();
    ///Setter
    void setZipCode(int);
    ///Getter
    int getZipCode();
    ///Setter
    void setStatus(string);
    ///Getter
    string getStatus();
    ///Setter
    void setSalary(double);
    ///Getter
    double getSalary();

    /**
     * Prints every attribute pertaining to the employee.
     */
    virtual void printEmployee();

    ///Constructor
    Employee();
    ///Constructor
    Employee(string, string, string, string, string, int, string, double);
};


#endif //REPORTSNEW_EMPLOYEE_H