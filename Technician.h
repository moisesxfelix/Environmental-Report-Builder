#ifndef REPORTSNEW_TECHNICIAN_H
#define REPORTSNEW_TECHNICIAN_H

#include "Employee.h"

/**
 * @brief Extends Employee class with asbestos, mold, and lead license fields
 * @author Moises Felix
 * @date 10/03/2025
 */
class Technician : public Employee {
private:
    string asbestosLicense;
    string moldLicense;
    string leadLicense;
public:
    ///Setter
    void setAsbestosLicense(string);
    ///Getter
    string getAsbestosLicense();
    ///Setter
    void setMoldLicense(string);
    ///Getter
    string getMoldLicense();
    ///Setter
    void setLeadLicense(string);
    ///Getter
    string getLeadLicense();

    /**
     * Prints every attribute of employee plus all relevant certifications/licenses
     */
    void printEmployee() override;

    ///Constructor
    Technician();
    ///Constructor
    Technician(string, string, string, string, string, int, string, double,
        string, string, string);
};


#endif //REPORTSNEW_TECHNICIAN_H