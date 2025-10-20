#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Encapsulates report metadata (company, project #, report/testing dates, insurance info, client/property details, technician)
 * @author Moises Felix
 * @date 10/02/2025
 */
class Report{
private:
    string companyName;
    string projectNum;
    string reportDate;
    string testingDate;
    string insuranceName;
    string insuranceClaimNum;
    string clientName;
    string clientAddress;
    string yearPropertyBuilt;
    string propertyType;
    string techName; ///< name of Technician

public:
    ///Setter
    void setCompanyName(string);
    ///Getter
    string getCompanyName();
    ///Setter
    void setProjectNumber(string);
    ///Getter
    string getProjectNumber();
    ///Setter
    void setReportDate(string);
    ///Getter
    string getReportDate();
    ///Setter
    void setTestingDate(string);
    ///Getter
    string getTestingDate();
    ///Setter
    void setInsuranceName(string);
    ///Getter
    string getInsuranceName();
    ///Setter
    void setInsuranceClaimNumber(string);
    ///Getter
    string getInsuranceClaimNumber();
    ///Setter
    void setClientName(string);
    ///Getter
    string getClientName();
    ///Setter
    void setClientAddress(string);
    ///Getter
    string getClientAddress();
    ///Setter
    void setYearPropertyBuilt(string);
    ///Getter
    string getYearPropertyBuilt();
    ///Setter
    void setPropertyType(string);
    ///Getter
    string getPropertyType();
    ///Setter
    void setTechnicianName(string);
    ///Getter
    string getTechnicianName();

    ///Virtual function
    virtual void printReportInformation() = 0;

    ///Constructor
    Report();
    ///Destructor
    virtual ~Report() = default;

};


#endif //REPORTSNEW_REPORT_H