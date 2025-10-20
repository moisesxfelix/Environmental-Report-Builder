// Created by Moises Felix on 10/2/2025.

#include "Employee.h"

static int nextEmployeeID = 3000;

int Employee::getEmployeeID() {
    return employeeID;
}

void Employee::setDepartmentName(string deptName) {
    departmentName = deptName;
}
string Employee::getDepartmentName() {
    return departmentName;
}

void Employee::setFirstName(string name) {
    firstName = name;
}
string Employee::getFirstName() {
    return firstName;
}

void Employee::setLastName(string lname) {
    lastName = lname;

}
string Employee::getLastName() {
    return lastName;
}

void Employee::setAddress(string addr) {
    address = addr;
}
string Employee::getAddress() {
    return address;
}

void Employee::setCityState(string city_state) {
    cityState = city_state;
}
string Employee::getCityState() {
    return cityState;
}

void Employee::setZipCode(int zip) {
    zipCode = zip;
}
int Employee::getZipCode() {
    return zipCode;
}

void Employee::setStatus(string stat) {
    status = stat;

}
string Employee::getStatus() {
    return status;
}

void Employee::setSalary(double sal) {
    salary = sal;
}
double Employee::getSalary() {
    return salary;
}

void Employee::printEmployee() {
    cout << "employeeID: " << employeeID
            << " - Name: " << firstName << " " << lastName
            << "\n- departmentName: " << departmentName
            << "\n- address: " << address
            << "\n- cityState: " << cityState
            << "\n- zipCode: " << zipCode
            << "\n- status: " << status
            << "\n- salary: " << salary;
}

Employee::Employee() {
    employeeID = nextEmployeeID++;
    departmentName = "";
    firstName = "";
    lastName = "";
    address = "";
    cityState = "";
    zipCode = 0;
    status = "";
    salary = 0.0;
}

Employee::Employee(string deptName, string name, string lname,
    string addr, string city_state, int zip, string stat, double sal) {
    employeeID = nextEmployeeID++;
    departmentName = deptName;
    firstName = name;
    lastName = lname;
    address = addr;
    cityState = city_state;
    zipCode = zip;
    status = stat;
    salary = sal;
}