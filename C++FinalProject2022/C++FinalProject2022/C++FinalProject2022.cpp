// C++FinalProject.cpp : Defines the entry point for the application.
//


#include <nana/gui.hpp>
#include <nana/gui/detail/general_events.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <textbox.hpp>
#include "Patient.h"
#include "CovidTestRecord.h"
#include <iostream>
#include <array>
#include <string>
#include <algorithm>


int main()
{
    using namespace std;
    using namespace nana;
    combox* listOfPatients;
    combox* listOfTestRecords;
    vector<Patient> allPatients;
    Patient* selectedPatient = nullptr;
    CovidTestRecord* selectedCovidTestRecord = nullptr;

    form fm(rectangle(30, 30, 1600, 600));
    form addingPatient;
    form removingPatient;
    form addingCovidTestRecord;
    form removingCovidTestRecord;

    textbox dayNumberShow{ fm };
    cout << "I am all good!!!" << endl;
    // The GUI of the adding patients

    label firstName{ addingPatient, "<bold blue size=16>First Name: </>" };
    textbox firstField{ addingPatient };
    label lastName{ addingPatient, "<bold blue size=16>Last Name: </>" };
    textbox lastNameField{ addingPatient };
    label postalCode{ addingPatient, "<bold blue size=16>Postal Code: </>" };
    textbox postalCodeField{ addingPatient };
    label dateOfBirth{ addingPatient, "<bold blue size=16>Date of Birth: </>" };
    textbox dateOfBirthField{ addingPatient };
    button* addingPatientButton;
    button cancelPatientButton{ addingPatient, "Cancel Patient" };
    firstName.format(true);
    lastName.format(true);
    postalCode.format(true);
    dateOfBirth.format(true);
    addingPatient.div("vert <><<><weight=25% text01><>><><<><weight=25% text02><>><><<><weight=25% text03><>><><<><weight=25% text04><>><><<><weight=25% text05><>><><<><weight=25% text06><>><><<><weight=25% text07><>><><<><weight=25% text08><>><><<><weight=40% button01><><weight=40% button02><>><>");
    addingPatient["text01"] << firstName;
    addingPatient["text02"] << firstField;
    addingPatient["text03"] << lastName;
    addingPatient["text04"] << lastNameField;

    addingPatient["text05"] << postalCode;
    addingPatient["text06"] << postalCodeField;
    addingPatient["text07"] << dateOfBirth;
    addingPatient["text08"] << dateOfBirthField;
    addingPatient["button01"] << *(addingPatientButton = new button(addingPatient, "Add Patient"));
    addingPatient["button02"] << cancelPatientButton;


    //Define a label and display a text.
    label lab{ fm, "<bold blue size=16>COVID RECORDS</>" };
    button addPatient{ fm, "Add Patient" };
    button removePatient{ fm, "Remove Patient" };

    lab.format(true);


    //Layout management
    fm.div("vert <><<><weight=30% text><>><><<><weight=20% patientaddbutton><>><><<><weight=20% patientremovebutton><>><><<><weight=20% comboxPatients><>><>>");

    fm["text"] << lab;
    fm["patientaddbutton"] << addPatient;
    fm["patientremovebutton"] << removePatient;
    fm["comboxPatients"] << *(listOfPatients = new combox(fm));

    //adding the patient to the UI
    addPatient.events().click([&] {
        string afirstNameText;
        string alastNameText;
        string apostalCodeText;
        string adateOfBirthText;
        addingPatient.collocate();
        addingPatient.show();
        addPatient.events().click([&] {
            firstField.getline(0, afirstNameText);
            lastNameField.getline(0, alastNameText);
            postalCodeField.getline(0, apostalCodeText);
            dateOfBirthField.getline(0, adateOfBirthText);

            std::cout << "firstNameText = " + afirstNameText << endl;
            allPatients.push_back(Patient(afirstNameText, alastNameText, apostalCodeText, adateOfBirthText));
            listOfPatients->push_back(allPatients.back().toString());
            std::cout << "Patient added \n " << endl;

            });
        removePatient.events().click([&] {
            addingPatient.close();
            std::cout << "Patient not added \n" << endl;
            });
        exec();
        //API::modal_window(addingPatient);
        });



    listOfPatients->events().selected([&] {
        auto txt = listOfPatients->text(listOfPatients->option());
        //auto custFilter = [&](auto cust) { return cust.toString().compare(txt) == 0; };
        for (auto& cust : allPatients)
        {
            if (cust.toString().compare(txt) == 0) {
                selectedPatient = &cust; //store the pointer to the chosen patient;
                std::cout << "Selected Patient = " << txt << endl;
                std::cout << "Selected Patient:- " << selectedPatient << endl;


            }
        }
        });


    removePatient.events().click([&] {
        cout << selectedPatient << endl;
        listOfPatients->erase(listOfPatients->option());

        });
    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
    delete listOfPatients;
    delete selectedPatient;
};

   

