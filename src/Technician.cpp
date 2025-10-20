// Created by Moises Felix on 10/3/2025.

#include "../include/Technician.h"

void Technician::setAsbestosLicense(string license) {
    asbestosLicense = license;
}
string Technician::getAsbestosLicense() {
    return asbestosLicense;
}

void Technician::setMoldLicense(string license) {
    moldLicense = license;
}
string Technician::getMoldLicense() {
    return moldLicense;
}

void Technician::setLeadLicense(string license) {
    leadLicense = license;
}
string Technician::getLeadLicense() {
    return leadLicense;
}

void Technician::printEmployee() {
    Employee::printEmployee();
    cout << "\n- asbestosLicense: " << asbestosLicense
    << "\n- moldLicense: " << moldLicense
    << "\n- leadLicense: " << leadLicense;

}

Technician::Technician() {
}

Technician::Technician(string deptName, string name, string lname, string addr, string city_state, int zip, string stat, double sal,
    string asbestos, string lead, string mold) : Employee(deptName, name, lname, addr, city_state, zip, stat, sal){
    asbestosLicense = asbestos;
    leadLicense = lead;
    moldLicense = mold;
}
