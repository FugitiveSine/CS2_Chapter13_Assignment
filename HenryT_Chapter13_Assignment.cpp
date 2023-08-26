//============================================================================
// Name        : HenryT_Chapter13_Assignment.cpp
// Author      : Henry Timmons
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "ArcticAnimal.hpp"


int main() {
	bool programRun = true;
		char userInput = 'a';

		ArcticAnimal* tempAnimal = nullptr;
		vector<ArcticAnimal*> vectorArcticAnimals;

		string setFile;
		string inputRecord;
		string stringAvgWeight;
		string stringAvgLength;
		string stringPopulation;
		string stringEndangered;
		string stringName;
		string stringFoodSource;
		ifstream inputFile;
	while(programRun == true){
		cout << "Menu Options" << endl;
		cout << "============" << endl;
		cout << "1) Enter the name of and read the CSV file" << endl;
		cout << "2) Clear the vector and all animals from memory" << endl;
		cout << "3) Print out the vector of animals" << endl;
		cout << "x) Exit the program" << endl;
		cin >> userInput;
		clearCin();
	switch (userInput) {
			case '1':
				cout << "You selected to open and read a file." << endl;
				cout << "What is the name of the file? ";
				getline(cin, setFile);
				inputFile.open(setFile);
				if (inputFile.fail()) {
					cout << "**Error file did not open correctly" << endl;
				} else {
					while (!inputFile.eof()) {
						getline(inputFile, inputRecord);

						tempAnimal = new ArcticAnimal;
						stringstream inputStream(inputRecord);//Input the raw data into a string to push back into a vector
						getline(inputStream, stringName, ',');
						getline(inputStream, stringAvgWeight, ',');
						getline(inputStream, stringAvgLength, ',');
						getline(inputStream, stringPopulation, ',');
						getline(inputStream, stringEndangered, ',');
						getline(inputStream, stringFoodSource, '\n');

						tempAnimal->setName(stringName);//temp animal is a placeholder to transition the contents into the vector
						tempAnimal->setAvgWeight(stoi(stringAvgWeight));
						tempAnimal->setAvgLength(stoi(stringAvgLength));
						tempAnimal->setPopulation(stoi(stringPopulation));
						tempAnimal->setEndangered(stoi(stringEndangered));
						tempAnimal->setFoodSource(stringFoodSource);

						vectorArcticAnimals.push_back(tempAnimal);
						tempAnimal = nullptr;
						delete tempAnimal;

					}

				}
				break;

			case '2':{
				for(unsigned int i = 0; i < vectorArcticAnimals.size(); i++){
					vectorArcticAnimals[i] = nullptr;
					delete vectorArcticAnimals[i];
				}
				vectorArcticAnimals.clear();
				delete tempAnimal;

				break;
			}
			case '3':
			cout << "You selected to print the vector of animals." << endl;
			cout << setw(15) << left << "Animal Name" << setw(18)
					<< "Average Weight" << setw(18) << "Average Length"
					<< setw(14) << "Population" << setw(14) << "Endangered"
					<< setw(14) << "Food Source" << endl;
			cout << setw(15) << left << "===========" << setw(18)
					<< "==============" << setw(18) << "=============="
					<< setw(14) << "==========" << setw(14) << "=========="
					<< setw(14) << "===========" << endl;

			for (unsigned int i = 0; i < vectorArcticAnimals.size(); i++) {
				string YorN;
				if (vectorArcticAnimals[i]->getEndangered() == 1) {
					YorN = "Yes";
				} else if (vectorArcticAnimals[i]->getEndangered() == 0) {
					YorN = "No";
				}
				cout << setw(15) << left << vectorArcticAnimals[i]->getName()
						//prints everything
						<< setw(18) << vectorArcticAnimals[i]->getAvgWeight()
						<< setw(18) << vectorArcticAnimals[i]->getAvgLength()
						<< setw(14) << vectorArcticAnimals[i]->getPopulation()
						<< setw(14) << YorN << setw(14)
						<< vectorArcticAnimals[i]->getFoodSource() << endl;
			}

					break;
			case 'x':
				cout << "Exiting the program" << endl;
				programRun = false;
				break;
			default:
				cout << "**Error, please enter a valid menu entry." << endl;
				break;

			}

		}
	for (unsigned int i = 0; i < vectorArcticAnimals.size(); i++) {
				delete vectorArcticAnimals[i];
				vectorArcticAnimals[i] = nullptr;
			}
			vectorArcticAnimals.clear();
			tempAnimal = nullptr;
	cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
	return 0;
}
