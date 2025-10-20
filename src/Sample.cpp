// Created by Moises Felix on 10/3/2025.

#include "../include/Sample.h"

void Sample::setSampleNumber(string sampleNum) {
    sampleNumber = sampleNum;
}
string Sample::getSampleNumber() {
    return sampleNumber;
}

void Sample::setMaterial(string mat) {
    material = mat;
}
string Sample::getMaterial() {
    return material;
}

void Sample::setSampleLocation(string loc) {
    sampleLocation = loc;
}
string Sample::getSampleLocation() {
    return sampleLocation;
}

void Sample::setSquareFeet(string sqft) {
    squareFeet = sqft;
}
string Sample::getSquareFeet() {
    return squareFeet;
}

void Sample::setResults(string res) {
    results = res;
}
string Sample::getResults() {
    return results;
}

void Sample::setCondition(char condi) {
    condition = condi;
}
char Sample::getCondition() {
    return condition;
}

void Sample::setCal_Osha(string str) {
    cal_osha = str;
}
string Sample::getCal_Osha() {
    return cal_osha;
}

void Sample::setEpa_Agmd(string str) {
    epa_aqmd = str;
}
string Sample::getEpa_Agmd() {
    return epa_aqmd;
}

void Sample::printPositiveSample() {
    cout << sampleNumber
    << "\n\tMaterial: " << material
    << "\n\tSample Location: " << sampleLocation
    << "\n\tSquare Feet: " << squareFeet
    << "\n\tResults: " << results
    << "\n\tCondition: " << condition
    << "\n\tCAL_OSHA: " << cal_osha
    << "\n\tEPA_AGMD: " << epa_aqmd << endl;
}

void Sample::printNegativeSample() {
    cout << sampleNumber
    << "\n\tMaterial: " << material
    << "\n\tSample Location: " << sampleLocation << endl;
}

Sample::Sample() {
    sampleNumber = "";
    material = "";
    sampleLocation = "";
    squareFeet = "";
    results = "";
    condition = ' ';
    cal_osha = "";
    epa_aqmd = "";
}

Sample::Sample(string sampleNum, string mat, string loc) {
    sampleNumber = sampleNum;
    material = mat;
    sampleLocation = loc;
    squareFeet = "";
    results = "";
    condition = ' ';
    cal_osha = "";
    epa_aqmd = "";
}

Sample::Sample(string sampleNum, string mat, string loc, string sqft, string res, char condi, string cal, string epa) {
    sampleNumber = sampleNum;
    material = mat;
    sampleLocation = loc;
    squareFeet = sqft;
    results = res;
    condition = condi;
    cal_osha = cal;
    epa_aqmd = epa;
}