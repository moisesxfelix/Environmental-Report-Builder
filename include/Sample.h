#ifndef REPORTSNEW_SAMPLE_H
#define REPORTSNEW_SAMPLE_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Represents a sample record (sample #, material, location, square feet, results, condition, CAL_OSHA, EPA_AGMD)
 * @author Moises Felix
 * @date 10/03/2025
 */
class Sample {
    string sampleNumber;
    string material;
    string sampleLocation;
    string squareFeet;
    string results;
    char condition;
    string cal_osha;
    string epa_aqmd;

public:
    ///Setter
    void setSampleNumber(string);
    ///Getter
    string getSampleNumber();
    ///Setter
    void setMaterial(string);
    ///Getter
    string getMaterial();
    ///Setter
    void setSampleLocation(string);
    ///Getter
    string getSampleLocation();
    ///Setter
    void setSquareFeet(string);
    ///Getter
    string getSquareFeet();
    ///Setter
    void setResults(string);
    ///Getter
    string getResults();
    ///Setter
    void setCondition(char);
    ///Getter
    char getCondition();
    ///Setter
    void setCal_Osha(string);
    ///Getter
    string getCal_Osha();
    ///Setter
    void setEpa_Agmd(string);
    ///Getter
    string getEpa_Agmd();


    /**
     * Prints all attributes pertaining to a positive Sample
     */
    void printPositiveSample();
    /**
     * Prints only relevant information of a negative Sample:
     * sample number, material, and sample location
     */
    void printNegativeSample();

    ///Constructor
    Sample();
    ///Constructor - Negative Sample
    Sample(string, string, string);
    ///Constructor - Positive Sample
    Sample(string, string, string, string, string, char, string, string);
};


#endif //REPORTSNEW_SAMPLE_H