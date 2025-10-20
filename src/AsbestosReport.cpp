#include "../include/AsbestosReport.h"
#include <fstream>


/**
 * Center output provided a given width
 * @param input string to be centered
 * @param lineLength overall width of output
 */
void Center(string input, int lineLength) {
    int spaces = 0;
    spaces = (lineLength - input.size())/2;
    if (spaces > 0) {
        cout << string(spaces, ' ');
    }
    cout << input;
    if (spaces > 0) {
        cout << string(spaces, ' ');
    }
}
/**
 * Prints Table Header for Results Table 1
 */
void PrintResultsTable1() {
    Center("Results Table 1",98);
    cout << endl;
    //lines 1-3
    cout << string(100, '-') << endl;
    cout << '|';
    Center("Summary of Asbestos Containing Material(s)",98);
    cout << '|' << endl;
    cout << string(100, '-') << endl;
    /*
    //line 4
    cout << '|';
    cout << string(10, ' ')<< '|';
    cout << string(14, ' ')<< '|';
    cout << string(10, ' ')<< '|';
    cout << string(11, ' ')<< '|';
    cout << string(12, ' ')<< '|';
    cout << string(11, ' ')<< '|';
    Center("Regulatory",24);
    cout << '|' << endl;
    //line 5
    cout << '|';
    Center("Sample", 10);
    cout << '|';
    Center("Material", 14);
    cout << '|';
    Center("Sample", 10);
    cout << '|';
    Center("Approx.", 11);
    cout << '|';
    Center("Asbestos", 13);
    cout << '|';
    Center("Condition", 11);
    cout << '|';
    Center("Assessment",24);
    cout << '|' << endl;
    //line 6
    cout << '|';
    Center("No. ", 10);
    cout << '|';
    Center("  ", 14);
    cout << '|';
    Center("Location", 10);
    cout << '|';
    Center("SF ", 11);
    cout << '|';
    Center("Results ", 12);
    cout << '|';
    Center(" ", 11);
    cout << '|' << string(24, '-') << '|'<< endl;
    //line 7
    cout << '|';
    cout << string(10, ' ')<< '|';
    cout << string(14, ' ')<< '|';
    cout << string(10, ' ')<< '|';
    cout << string(11, ' ')<< '|';
    cout << string(12, ' ')<< '|';
    cout << string(11, ' ')<< '|';
    Center("CAL OSHA", 11);
    cout << "| ";
    Center("EPA/AQMD", 12);
    cout << '|' << endl;
    //line 8
    cout << string(100, '-') << endl;
    */
}
/**
 * Prints Table Header for Results Table 2
 */
void PrintResultsTable2() {
    Center("Results Table 2",98);
    cout << endl;
    //lines 1-3
    cout << string(100, '-') << endl;
    cout << '|';
    Center(" Summary of Non-Detect Material(s)",98);
    cout << '|' << endl;
    cout << string(100, '-') << endl;
}

int AsbestosReport::inputFromFile() {
    ifstream myFile;
    string fileName;
    fileName = "reportInput.txt";
    myFile.open(fileName);
        if (!myFile.is_open()) {
            cout << "Error opening file " << fileName << endl;
            return -1;
        }

        //inputs report information
        while (!myFile.eof()) {
            string line;
            //Company Name
            getline(myFile, line);
            setCompanyName(line);
            //Project Number
            getline(myFile, line);
            setProjectNumber(line);
            //Report Date
            getline(myFile, line);
            setReportDate(line);
            //Testing Date
            getline(myFile, line);
            setTestingDate(line);
            //Insurance Name
            getline(myFile, line);
            setInsuranceName(line);
            //Insurance Claim Number
            getline(myFile, line);
            setInsuranceClaimNumber(line);
            //Client Name
            getline(myFile, line);
            setClientName(line);
            //Client Address
            getline(myFile, line);
            setClientAddress(line);
            //Year Property Was Built
            getline(myFile, line);
            setYearPropertyBuilt(line);
            //Property Type
            getline(myFile, line);
            setPropertyType(line);
            //Technician Name
            getline(myFile, line);
            setTechnicianName(line);
        }
        myFile.close();

    fileName = "sampleInput.txt";
    myFile.open(fileName);
    if (!myFile.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return -1;
    }

    //inputs sample information
    while (!myFile.eof()) {
        string sampleNum, material, location, squareft,
            results, cal_osha, epa_aqmd;
        char condition;
        int sampleCount;
        string line;


        //Number of Positive Samples
        myFile >> sampleCount;
        myFile.ignore();

        for (int i = 0 ; i < sampleCount ; i++) {
            //Sample Identifier
            getline(myFile, sampleNum);
            //Material
            getline(myFile, material);
            //Location
            getline(myFile, location);
            //Size in Square Feet
            getline(myFile, squareft);
            //Results
            getline(myFile, results);
            //Condition
            myFile >> condition;
            myFile.ignore();
            //CAL OSHA
            getline(myFile, cal_osha);
            //EPA AQMD
            getline(myFile, epa_aqmd);

            addPositiveSample(Sample(sampleNum, material, location, squareft, results, condition, cal_osha, epa_aqmd));
        }

        //Number of Negative Samples
        myFile >> sampleCount;
        myFile.ignore();

        for (int i = 0 ; i < sampleCount ; i++) {
            //Sample Identifier
            getline(myFile, sampleNum);
            //Material
            getline(myFile, material);
            //Location
            getline(myFile, location);

            addNegativeSample(Sample(sampleNum, material, location));
        }
    }
    myFile.close();
    return 0;
}

int AsbestosReport::inputManually() {
    string line;
    cout << "Enter Company Name: ";
    getline(cin, line);
    setCompanyName(line);

    cout << "Enter Project Number: ";
    getline(cin, line);
    setProjectNumber(line);

    cout << "Enter Report Date: ";
    getline(cin, line);
    setReportDate(line);

    cout << "Enter Testing Date: ";
    getline(cin, line);
    setTestingDate(line);

    cout << "Enter Insurance Name: ";
    getline(cin, line);
    setInsuranceName(line);

    cout << "Enter Insurance Claim Number: ";
    getline(cin, line);
    setInsuranceClaimNumber(line);

    cout << "Enter Client Name: ";
    getline(cin, line);
    setClientName(line);

    cout << "Enter Client Address: ";
    getline(cin, line);
    setClientAddress(line);

    cout << "Enter Year Property Built: ";
    getline(cin, line);
    setYearPropertyBuilt(line);

    cout << "Enter Property Type: ";
    getline(cin, line);
    setPropertyType(line);

    cout << "Enter Name of Technician: ";
    getline(cin, line);
    setTechnicianName(line);


    string sampleNum, material, location, squareft,
            results, cal_osha, epa_aqmd;
    char condition;
    int sampleCount;

    //Input Sample Information
    cout << "How many positive samples: ";
    cin >> sampleCount;
    cin.ignore();

    for (int i = 0 ; i < sampleCount ; i++) {
        cout << "Enter sample number: ";
        getline(cin, sampleNum);

        cout << "Enter material: ";
        getline(cin, material);

        cout << "Enter location: ";
        getline(cin, location);

        cout << "Enter squareft: ";
        getline(cin, squareft);

        cout << "Enter results: ";
        getline(cin, results);

        cout << "Enter condition: ";
        cin >> condition;
        cin.ignore();

        cout << "Enter CAL_OSHA: ";
        getline(cin, cal_osha);

        cout << "Enter EPA_AQMD: ";
        getline(cin, epa_aqmd);

        addPositiveSample(Sample(sampleNum, material, location, squareft, results, condition, cal_osha, epa_aqmd));
    }

    cout << "How many negative samples: ";
    cin >> sampleCount;
    cin.ignore();

    for (int i = 0 ; i < sampleCount ; i++) {
        cout << "Enter sample number: ";
        getline(cin, sampleNum);

        cout << "Enter material: ";
        getline(cin, material);

        cout << "Enter location: ";
        getline(cin, location);

        addNegativeSample(Sample(sampleNum, material, location));
    }
    return 0;
}

vector<Sample> AsbestosReport::getPositiveSamples() {
    return positiveSamples;
}

vector<Sample> AsbestosReport::getNegativeSamples() {
    return negativeSamples;
}

void AsbestosReport::addPositiveSample(Sample sample) {
    positiveSamples.push_back(sample);
}

void AsbestosReport::addNegativeSample(Sample sample) {
    negativeSamples.push_back(sample);
}

void AsbestosReport::editSamples() {
    bool choiceExists = false;
    do {
        int inputNum = 0;
        cout << "What would you like to do:" << endl;
        cout << "[1] Edit Positive Sample"  << endl;
        cout << "[2] Edit Negative Sample"  << endl;
        cout << "[3] Add Positive Sample" << endl;
        cout << "[4] Add Negative Sample" << endl;
        cout << "[5] Remove Positive Sample" << endl;
        cout << "[6] Remove Negative Sample" << endl;
        cout << "[7] Return" << endl;
        cout << "Enter Choice: ";
        cin >> inputNum;
        cin.ignore();
        switch (inputNum) {
            //Edits an attribute in Positive Samples
            case 1: {
                int sampleIndex;
                cout << "Select sample to edit: " << endl;
                printPositiveSamples();
                cout << "Enter choice: ";
                cin >> sampleIndex;
                cin.ignore();

                if (sampleIndex <= positiveSamples.size() and sampleIndex > 0) {
                    int attributeChoice;
                    cout << "What attribute would you like to edit?" << endl;
                    cout << "[1] Material"  << endl;
                    cout << "[2] Sample Location"  << endl;
                    cout << "[3] Square Feet"  << endl;
                    cout << "[4] Results"  << endl;
                    cout << "[5] Condition"  << endl;
                    cout << "[6] CAL_OSHA"  << endl;
                    cout << "[7] EPA_AGMD" << endl;
                    cout << "Enter Choice: ";
                    cin >> attributeChoice;
                    cin.ignore();

                    if (attributeChoice > 0 and attributeChoice < 8 ) {
                        string edit;
                        switch (attributeChoice) {
                            case 1:
                                cout << "Enter new value for Material: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setMaterial(edit);
                                break;
                            case 2:
                                cout << "Enter new value for Sample Location: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setSampleLocation(edit);
                                break;
                            case 3:
                                cout << "Enter new value for Square Feet: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setSquareFeet(edit);
                                break;
                            case 4:
                                cout << "Enter new value for Results: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setResults(edit);
                                break;
                            case 5:
                                cout << "Enter new value for Condition: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setCondition(edit[0]);
                                break;
                            case 6:
                                cout << "Enter new value for CAL_OSHA: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setCal_Osha(edit);
                                break;
                            case 7:
                                cout << "Enter new value for EPA_AGMD: ";
                                getline(cin, edit);
                                positiveSamples[sampleIndex-1].setEpa_Agmd(edit);
                                break;
                        }
                        cout << "Edit completed." << endl;
                    }
                    else {
                        cout << "Invalid choice." << endl;
                    }

                }
                else {
                    cout << "Invalid choice." << endl;;
                }
                break;
            }
            //Edits an attribute in Negative Samples
            case 2: {
                int sampleIndex;
                cout << "Select sample to edit: " << endl;
                printNegativeSamples();
                cout << "Enter choice: ";
                cin >> sampleIndex;
                cin.ignore();

                if (sampleIndex <= negativeSamples.size() and sampleIndex > 0) {
                    int attributeChoice;
                    cout << "What attribute would you like to edit?" << endl;
                    cout << "[1] Material"  << endl;
                    cout << "[2] Sample Location"  << endl;
                    cout << "Enter Choice: ";
                    cin >> attributeChoice;
                    cin.ignore();

                    if (attributeChoice > 0 and attributeChoice < 3 ) {
                        string edit;
                        switch (attributeChoice) {
                            case 1:
                                cout << "Enter new value for Material: ";
                                getline(cin, edit);
                                negativeSamples[sampleIndex-1].setMaterial(edit);
                                break;
                            case 2:
                                cout << "Enter new value for Sample Location: ";
                                getline(cin, edit);
                                negativeSamples[sampleIndex-1].setSampleLocation(edit);
                                break;
                        }
                        cout << "Edit completed." << endl;
                    }
                    else {
                        cout << "Invalid choice." << endl;
                    }

                }
                break;
            }
            //Adds a positive sample to the list of Positive Samples
            case 3: {
                string sampleNum, material, location, squareft,
                    results, cal_osha, epa_aqmd;
                char condition;

                cout << "Enter sample number: ";
                getline(cin, sampleNum);

                cout << "Enter material: ";
                getline(cin, material);

                cout << "Enter location: ";
                getline(cin, location);

                cout << "Enter squareft: ";
                getline(cin, squareft);

                cout << "Enter results: ";
                getline(cin, results);

                cout << "Enter condition: ";
                cin >> condition;
                cin.ignore();

                cout << "Enter CAL_OSHA: ";
                getline(cin, cal_osha);

                cout << "Enter EPA_AQMD: ";
                getline(cin, epa_aqmd);

                addPositiveSample(Sample(sampleNum, material, location, squareft, results, condition, cal_osha, epa_aqmd));
                cout << "Addition completed." << endl;
                break;
            }
            //Adds a negative sample to the list of Negative Samples
            case 4: {
                string sampleNum, material, location;

                cout << "Enter sample number: ";
                getline(cin, sampleNum);

                cout << "Enter material: ";
                getline(cin, material);

                cout << "Enter location: ";
                getline(cin, location);

                addNegativeSample(Sample(sampleNum, material, location));
                cout << "Addition completed." << endl;

                break;
            }
            //Removes a positive sample from list of Positive Samples
            case 5: {
                int sampleIndex;
                cout << "Select sample to remove: " << endl;
                printPositiveSamples();
                cout << "Enter choice: ";
                cin >> sampleIndex;
                cin.ignore();
                if (sampleIndex <= positiveSamples.size() and sampleIndex > 0) {
                    positiveSamples.erase(positiveSamples.begin() + (sampleIndex-1));
                    cout << "Removal completed."<< endl;
                }
                else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            //Removes a negative sample from list of Negative Samples
            case 6: {
                int sampleIndex;
                cout << "Select sample to remove: " << endl;
                printNegativeSamples();
                cout << "Enter choice: ";
                cin >> sampleIndex;
                cin.ignore();
                if (sampleIndex <= negativeSamples.size() and sampleIndex > 0) {
                    negativeSamples.erase(negativeSamples.begin() + (sampleIndex-1));
                    cout << "Removal completed."<< endl;
                }
                else {
                    cout << "Invalid choice." << endl;
                }
                break;
            }
            //Returns to previous Menu
            case 7:{
                choiceExists = true;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (!choiceExists);
}

void AsbestosReport::printPositiveSamples() {
    int i = 0;
    for (Sample s : getPositiveSamples()) {
        cout << "[" << i +1 << "] ";
        s.printPositiveSample();
        i++;
    }
}

void AsbestosReport::printNegativeSamples() {
    int i = 0;
    for (Sample s : getNegativeSamples()) {
        cout << "[" << i +1 << "] ";
        s.printNegativeSample();
        i++;
    }
}

void AsbestosReport::printReportInformation() {
    cout << string(30, '-') << "\nLimited Asbestos Inspection Report\n" << string(30, '-') << endl;
    cout << "Company Name: " << getCompanyName() << endl;
    cout << "Project Number: " << getProjectNumber() << endl;
    cout << "Report Date: " << getReportDate() << endl;
    cout << "Testing Date: " << getTestingDate() << endl;
    cout << "Insurance Name: " << getInsuranceName() << endl;
    cout << "Insurance Claim Number: " << getInsuranceClaimNumber() << endl;
    cout << "Client Name: " << getClientName() << endl;
    cout << "Client Address: " << getClientAddress() << endl;
    cout << "Year Property Built: " << getYearPropertyBuilt() << endl;
    cout << "Property Type: (Residential/Commercial): " << getPropertyType() << endl;
    cout << "Name of Technician: " << getTechnicianName() << endl;

    //Summary
    cout << string(30, '-') << "\nSummary\n" << string(30, '-') << endl
        << getCompanyName() <<" was appointed to conduct a limited asbestos inspection for the property located at "
        << getClientAddress() << ". The asbestos inspection was performed by " << getTechnicianName() << ", a Certified Asbestos Consultant "
        << "(add certification here), under the direct supervision of (add Supervisor here), a Certified Asbestos Consultant (add certification here)."
        << "\nOn " << getTestingDate() << ", " << getTechnicianName() << " performed a visual inspection and collected samples of potential asbestos "
        << "containing material. A total of " << getPositiveSamples().size() + getNegativeSamples().size() <<" samples were collected at the inspected "
        << "property for Polarized Light Microscopy (PLM) analysis. Materials identified during this inspection include: "
        << "(insert materials here.)"<< endl;

    //Walk-Through and Visual Survey
    cout << string(30,'-') << "\nWalk-Through and Visual Survey\n" << string(30,'-') << endl
        << getTechnicianName() << " performed an onsite walk-through and visual survey of the building materials on "
        << getReportDate() << ".\nThe " << getPropertyType() << "Property located at "
        << getClientAddress() << " was built in " << getYearPropertyBuilt() << '.' << endl;
    cout << "-Structural Damage: (Y/N)";
    cout << "\n-Fire Damage: (Y/N)";
    cout << "\n-Property Occupied: (Y/N)";
    cout << "\n-Contents Present: (Y/N)" << endl;


    //Sample Methodology
    cout << string(30,'-') << "\nSample Methodology\n" << string(30,'-') << endl;
    cout << "Samples were collected following the Environmental Protection Agency (EPA) in 40 CFR Part 763.86 procedures "
    << "for sampling material. The samples were sent to (Enter Environmental Lab Name) located at (Enter Environmental Lab Address) "
    << "for PLM analysis.\nPLM analysis is the most common method for determining the presence of asbestos fibers in building "
    << "material. The PLM method utilized a polarized light microscope to test the optical properties of the sample. "
    << "The fibrous components are provided, and the percentage of asbestos fibers can then be established. "<< endl;

    //Results
    cout << string(30,'-') << "\nResults\n" << string(30,'-') << endl;

    cout << "On " << getTestingDate() << ", a total of " << getPositiveSamples().size() << " sample(s) were identified as "
    << "positive for Asbestos Containing Material (ACM), which are regulated materials, and a total of " << getNegativeSamples().size()
    << " with layers were identified as non-detect for ACM. The results for asbestos samples collected at "<< getClientAddress()
    << " on " << getTestingDate() << ", are listed in:"<< endl;
    if (!getPositiveSamples().empty()) {
        cout << "Results Table 1" << endl;
    }
    if (!getNegativeSamples().empty()) {
        cout << "Results Table 2" << endl;
    }

    //Results Table 1
    PrintResultsTable1();
    if (!getPositiveSamples().empty()) {
        printPositiveSamples();
    }
    else {
        cout << "No asbestos was detected in the samples submitted. "
        <<"Please review the attached laboratory results for complete details on materials sampled." << endl;
    }

    //Results Table 2
    PrintResultsTable2();
    printNegativeSamples();

    //Results Cont'd
    cout << string(30,'-') << "\nResults (Cont'd)\n" << string(30,'-')
        << "\nWhen samples analyzed by Polarized Light Microscopy contain asbestos in amounts of less than ten percent (<10%), "
        << "a more exact method of analysis called point counting may be performed at the client’s request.  The EPA point count "
        << "method (400-point or 1000-point) allows a sample in which asbestos was visually detected, but which is visually "
        << "estimated to have 10% or less asbestos to be more accurately quantified.  EPA requires at a minimum a 400-point "
        << "count analysis for sample results of <1% asbestos.  If not point counted, a sample in which asbestos was visually "
        << "detected and estimated (including trace to <=1%) must be assumed to be greater than 1% and treated as ACM. "
        << "\nLimited destructive sampling was conducted at the subject property. The survey included inspection of accessible "
        << "materials. " << getCompanyName() << " did not inspect or sample inaccessible areas such as behind walls, "
        << "behind permanently fixed items or within duct work and did not dismantle any part of the structure to survey "
        << "inaccessible areas. Inaccessible is defined as areas of the building that could not be tested (sampled) without "
        << "destruction of the structure or a portion of the structure. If during the demolition and/or renovation activities, "
        << "unforeseen suspected ACM materials are uncovered they shall be presumed positive until additional "
        << "sampling is performed." << endl;

    //Sample Analysis
    cout << string(30,'-') << "\nSample Analysis\n" << string(30,'-')
        << "\nMaterials found to contain greater than 1% of asbestos substance are considered ACM. ACM must be removed and disposed "
        << "of according to the regulations listed by the California Occupational Safety & Health Administration, EPA, and the "
        << "South Coast Air Quality Management District (SCAQMD).\nThe PLM method of analysis states that each layer of material "
        << "is analyzed for the presence of asbestos fibers. For each homogeneous material the client may request a "
        << "\"positive stop.\" A positive stop will stop analysis once asbestos is first identified in concentrations "
        << "greater than 1% per each homogeneous material. A homogeneous material is defined as \"an area of surfacing material, "
        << "thermal system insulation material, or miscellaneous material that is uniform in color and texture\" per 40 CFR 763.83." << endl;

    //Recommendations
    cout << string(30,'-') << "\nRecommendations\n" << string(30,'-');
    if (!getPositiveSamples().empty()) {
        cout << "\nAsbestos containing materials were detected during " << getCompanyName() << "'s inspection performed for "
        << getClientName() << " located at "<< getClientAddress() << ", and a certified abatement contractor is required for the removal/disposal"
        << " of materials tested within the inspected areas at the time of this report. These materials are subject to regulation as it is "
        << "enforced by the South Coast Air Quality Management District (SCAQMD) Rule 1403." << endl;
    }
    else {
        cout << "\nNo asbestos containing materials were detected during " << getCompanyName() << "'s inspection performed for" << getClientName()
        << " located at " << getClientAddress() << ", and a certified abatement contractor is not required for removal/disposal of "
        << "materials tested within the inspected areas at the time of this report. If additional suspected asbestos containing materials "
        << "were not sampled and may be disturbed, additional sampling may be required. " << endl;
    }

    //Limitations
    cout << string(30,'-') << "\nLimitations\n" << string(30,'-');
    cout << "\nThis report was prepared specifically for the client and is not intended for use by outside parties or entities. All findings "
    << "and recommendations are based on conditions existing within the inspected areas at the specified date and location indicated in this "
    << "report. This report does not detail all the potential hazards, or that hazards do not exist within the inspected areas. "
    << getCompanyName() << " is not responsible for changes in environmental conditions, conditions or practices performed "
    << "after this inspection." << endl;
    cout << "During this inspection, "<< getCompanyName() << " has provided professional services and has adhered to standards and "
    << "regulations previously stated in this report. All information provided is limited to the scope of services, previously "
    << "listed methods, and the conditions present at the time of inspection. It should be noted that quantities are estimated onsite "
    << "and are not to be considered as actual measurements.\nIf you have any question or concerns, please contact us at 555-555-5555." << endl;

    cout << "Thank you,\n" << getCompanyName() << endl;
}

AsbestosReport::AsbestosReport() {
    positiveSamples = {};
    negativeSamples = {};
}