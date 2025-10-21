# Environmental-Report-Builder
Report generator (C++) for environmental sampling data—supports environmental contaminant reports.
> **Why This Exists:** The purpose of this project is to eliminate the tedious "copy-paste" workflow that
> workers in the Reports department of Environmental Companies experience on a daily basis. This project
> streamlines the process by modeling common report elements in code and produces clean, repeatable text output.

## Features
- **Modeled domain objects** for environmental reporting (e.g., employees, technicians, samples) for clean data handling.
- **Report Types** separated from core logic. The repo includes an example Asbestos Report implementation.
- **Example Inputs** (```reportInput.txt```, ```sampleInput.txt```, ```EmployeeList.txt```) to help users get started.
  - Manual input of project/report information supported.
> **Note:** This project is early-stage; file formats may evolve.

## Design and Extensibility
The code follows a **base class + specializations pattern** so you can add new report types without rewriting the core.
```
Main                # Core Logic

Report (abstract)
├─ AsbestosReport   # Concrete report type implementation
├─ ...              # Add additional reports: LeadReport, MoldReport, etc.

Employee
├─ Technician       
├─ ...              # Add additional departments for employees: Accounting, Reports, etc.

Domain Models
└─ Sample
```
## Usage
**1)** Prepare Inputs: update provided .txt files with project/report details following template guidelines
- Files must be included but can be empty if opting to do manual input

**2)** Build and Run: Follow the program prompt to:
- Select report type
- Select input procedure (manual/file input)
- Review and edit report data

**3)** Print Report: Receive report of selected type in program console

## Input File Formats
This repository includes example txt file inputs to be mirrored for build
### File 1
```EmployeeList.txt``` - personnel and additional info  
- Format:
```
[Department] [# of personnel]       //First department
[Name]                              //First employee
[Addres]
[City, State]
[Zipcode]
[Status]
[Salary]
[Asbestos License/Certification]    //if Technician
[Lead License/Certification]        //if Technician
[Mold License/Certification]        //if Technician
[Name]                              //Second employee
...
[Department [# of personnel]        //Second department
[Name]
...
```
### File 2
```reportInput.txt``` - high-level report metadata
- Format:
```
[Company Name]
[Project Number]
[Report Date]
[Testing Date]
[Insurance Name]
[Insurance Claim Number]
[Client Name]
[Client Address]
[Year Property was Built]
[Property Type]
[Technician Name]
```
### File 3
```sampleInput.txt``` - sample identifiers and results
- Format:
```
[# of Positive Samples]
[Sample Number]         //First positive sample
[Material]
[Sample Location]
[Square Footage]
[Results]
[Condition]
[CAL_OSHA]
[EPA_AQMD]
[Sample Number]         //Second positive sample, if exists
...
[# of Negative Samples]
[Sample Number]         //First negative sample
[Material]
[Sample Location]
[Sample Number]         //Second negative sample, if exists
...
```

## Roadmap
- [ ] CSV input option for file input
    - Adjust parsing from newline separated values to comma separated values
- [ ] Format helpers
    - Utility functions for lists and tables
- [ ] Additional report Type (Oct 2025-Dec 2025)
    - Add new report type (Lead)
- [ ] Adjust Sample object model to include polymorphic behavior
    - Adjust Sample as an abstract parent class
    - Create asbestosSample as child class
- [ ] Optional PDF export
    - Add the ability to write/output to PDF

## Motivation (Original Note)
> The idea and development of this project started when a close friend expressed their tedious task of
> generating environmental reports using inefficient procedures. This project aims to streamline the
> process of generating environmental reports to increase efficiency and productivity.


