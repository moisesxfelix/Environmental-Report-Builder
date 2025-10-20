// Created by Moises Felix on 10/2/2025.

#include <iostream>
#include <string>
using namespace std;
#include "../include/Report.h"

void Report::setCompanyName(string compName) {
        companyName = compName;
    }
    string Report::getCompanyName() {
        return companyName;
    }

    void Report::setProjectNumber(string project_number){
        projectNum = project_number;
    }
    string Report::getProjectNumber(){
        return projectNum;
    }

    void Report::setReportDate(string report_date){
        reportDate = report_date;
    }
    string Report::getReportDate(){
        return reportDate;
    }

    void Report::setTestingDate(string testing_date){
        testingDate = testing_date;
    }
    string Report::getTestingDate(){
        return testingDate;
    }

    void Report::setInsuranceName(string insurance_name){
        insuranceName = insurance_name;
    }
    string Report::getInsuranceName(){
        return insuranceName;
    }

    void Report::setInsuranceClaimNumber(string insurance_claim_number){
        insuranceClaimNum = insurance_claim_number;
    }
    string Report::getInsuranceClaimNumber(){
        return insuranceClaimNum;
    }

    void Report::setClientName(string client_name){
        clientName = client_name;
    }
    string Report::getClientName(){
        return clientName;
    }

    void Report::setClientAddress(string client_address){
        clientAddress = client_address;
    }
    string Report::getClientAddress(){
        return clientAddress;
    }

    void Report::setYearPropertyBuilt(string year_property_built){
        yearPropertyBuilt = year_property_built;
    }
    string Report::getYearPropertyBuilt(){
        return yearPropertyBuilt;
    }

    void Report::setPropertyType(string property_type){
        propertyType = property_type;
    }
    string Report::getPropertyType(){
        return propertyType;
    }

    void Report::setTechnicianName(string tech_name){
        techName = tech_name;
    }
    string Report::getTechnicianName(){
        return techName;
    }

    Report::Report(){
        companyName = "";
        projectNum = "";
        reportDate = "";
        testingDate = "";
        insuranceName = "";
        insuranceClaimNum = "";
        clientName = "";
        clientAddress = "";
        yearPropertyBuilt = "";
        propertyType = "";
        techName = "";
    }