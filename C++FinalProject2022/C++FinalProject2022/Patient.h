//the patient class
#pragma once
#include <ostream>
#include <iostream>
#include <string>
using namespace std;
class Patient {

protected:
	string firstName;
	string lastName;
	string postalCode;
	string dateOfBirth;
	string patientString;//DD/MM/YYYY
	int patientAge;
public:
	Patient(string& a, string& b, string& c, string& d) {
		this->firstName = a;
		this->lastName = b;
		this->postalCode = c;
		this->dateOfBirth = d;
		patientAge = setPatientAge(dateOfBirth);
		patientString = "name:" + this->firstName + " " + this->lastName + +" postal code:- " + this->postalCode + " dateOfBirth:" + dateOfBirth;

	}

	int setPatientAge(string dob) {
		int patientAge = 0;
		patientAge = 2022 - stoi(dob.substr(6, 4));
		return patientAge;
	}
	string toString() {
		return patientString;
	}
	string getDateOfBirth() {
		return dateOfBirth;
	}
};