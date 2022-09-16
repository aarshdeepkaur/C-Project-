#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class CovidTestRecord {
protected:
	string testDate;
	string testResult;
	int randomNumber;
	string covidTestRecordString;

public:
	CovidTestRecord(string& tDate) {
		this->testDate = tDate;
		testResult = to_string(setRandomTestResult()) + "%";
		covidTestRecordString = "test date:- " + testDate + " with positive chance of " + testResult;
	}

	int setRandomTestResult() {
		randomNumber = (5 + (rand() % 100));
		return randomNumber;
	}

};