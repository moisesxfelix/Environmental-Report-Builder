#ifndef REPORTSNEW_ASBESTOSREPORT_H
#define REPORTSNEW_ASBESTOSREPORT_H

#include <vector>
#include "Report.h"
#include "Sample.h"
using namespace std;


/**
* @brief Loads report metadata and sample data (from files or interactive prompts), manages positive/negative samples, and supports edit/add/remove operations.
* Outputs a formatted “Limited Asbestos Inspection Report” to stdout with summaries, methodology, results tables, and recommendations.
* @author Moises Felix
* @date 10/13/2025
*/
class AsbestosReport : public Report{
private:

    ///List of positive samples, if any.
    vector<Sample> positiveSamples;
    ///List of negative samples, if any.
    vector<Sample> negativeSamples;
public:
    /**
     * Inputs asbestos report information from 2 files.
     * 1 - name: reportInput.txt, contains: general information about the report.
     * 2 - name: sampleInput.txt, contains: results pertaining to the samples collected from project site.
     * @return -1 if file not found, 0 if file read successfully.
     */
    int inputFromFile();
    /**
     * Allows the user to manually input Project information and Sample results.
     * @return 0 if information inputted successfully.
     */
    int inputManually();
    /**
     * Retrieves the vector containing the positive sample results.
     * @return a vector containing objects of the Sample class.
     */
    vector<Sample> getPositiveSamples();
    /**
     * Retrieves the vector containing the negative sample results.
     * @return a vector containing objects of the Sample class.
     */
    vector<Sample> getNegativeSamples();
    /**
     * Adds a Sample object into the vector of positive samples.
     * @param Sample object with every attribute defined.
     */
    void addPositiveSample(Sample);
    /**
     * Adds a Sample object into the vector of negative samples.
     * @param Sample object with at least the first three attributes defined.
     */
    void addNegativeSample(Sample);
    /**
     * Allows the Editing, Addition, and Deletion of samples in both
     * the positive and negative list of samples.
     */
    void editSamples();
    /**
     * Prints the list of all positive samples in the vector.
     * Outputs all the information pertaining to the Sample
     * in the order added to the vector of Sample objects.
     */
    void printPositiveSamples();
    /**
     * Prints the list of all negative samples in the vector.
     * Outputs the first three attributes pertaining to the Sample
     * in the order added to the vector of Sample objects.
     */
    void printNegativeSamples();
    /**
     * Prints all the information and sections pertaining to the  Asbestos Report.
     * Include Summary, Walk-Through and Visual Survey, Sample Methodology,
     * Results, Results Tables, Sample Analysis, Recommendations, Limitations,
     * and Definitions.
     */
    void printReportInformation() override;

    ///Constructor
    AsbestosReport();
};


#endif //REPORTSNEW_ASBESTOSREPORT_H