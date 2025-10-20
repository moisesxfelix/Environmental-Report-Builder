# Environmental-Report-Builder
Report generator (C++) for environmental sampling data—supports environmental contaminant reports.
> **Why This Exists:** The purpose of this project is to eliminate the tedious "copy-paste" workflow that
> workers in the Reports department of Environmental Companies experience on a daily basis. This project
> streamlines the process by modeling common report elements in code and produces clean, repeatable text output.

## Features
- **Modeled domain objects** for environmental reporting (e.g., employees, technicians, samples) for clean data handling.
- **Report Types** separated from core logic. The repo includes an example Asbestos report implementation.
- **Example Inputs** (```reportInput.txt```, ```sampleInput.txt```, ```EmployeeList.txt```) to help users get started.
> **Note:** This project is early-stage; file formats may evolve.

## Design and Extensibility
The code follows a **base class + specializations pattern** so you can add new report types without rewriting the core.
```
Report (abstract)
├─ AsbestosReport   # Example concrete implementation
├─ ...              # Add additional reports: LeadReport, MoldReport, etc.

Employee
├─ Technician       
├─ ...              # Add additional departments for employees: Accounting, Reports, etc.

Domain Models
└─ Sample
```

## Roadmap
- [ ] CSV input option for file input
    - Adjust parsing from newline separated values to comma separated values
- [ ] Formatting helpers
    - Utility functions for lists and tables
- [ ] Additional report Type (Oct 2025-Dec 2025)
    - Add new report type (Lead)
- [ ] Adjust Sample object model to include polymorphic behavior
    - Adjust Sample as a parent class
    - Create asbestosSample as child class
- [ ] Optional PDF export
    - Add the ability to write/output to PDF

## Motivation (Original Note)
>I started my project to help a friend create environmental reports more efficiently. 
> They would copy and paste information into PDF templates, and I thought I could create a 
> program that makes the generation of these reports more efficient.


