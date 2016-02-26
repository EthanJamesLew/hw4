//G03729047 Ethan Lew
#include "main.h"
using namespace std;

string getFileName(ios_base::open_mode);

double volume(double axisA, double axisB, double axisC);

double distance(double corA_x, double corA_y, double corB_x, double corB_y);

double slope(double corA_x, double corA_y, double corB_x, double corB_y);

string transposeString(char charA, char charB, int intA, float floatA);

string combineString(string strA, string strB, string strC, string strD, string strE);

int main(int argc, char *argv[])
{
	//Objects to be loaded from inFile
	float axisA = 0.0;
	float axisB = 0.0;
	float axisC = 0.0;
	float axisD = 0.0;
	float floatA = 0.0;
	int intA = 0;
	char charA = ' ';
	char charB = ' ';
	string strA = " ";
	string strB = " ";
	string strC = " ";
	string strD = " ";
	string strE = " ";
	string strF = " ";

	//File streams
	ifstream inFile;
	ofstream outFile;

	inFile.open(getFileName(ios::in));
	outFile.open(getFileName(ios::out));

	inFile >> axisA >> axisB >> axisC >> axisD;
	inFile >> intA;
	inFile >> charA >> floatA >> charB;
	//Ensure that getline doesn't retrieve empty string
	do
	{
		getline(inFile, strE);
	} while (strE == "");
	inFile >> strA >> strB >> strC >> strD;

	outFile << fixed << "Volume of sphere: " << volume(axisA, axisB, axisC) << '\n';
	outFile << scientific << "Distance between two points: " << distance(axisA, axisD, axisC, axisB) << '\n';
	outFile << fixed << "Slope between two points: " << slope(axisA, axisD, axisC, axisB);
	outFile << transposeString(floatA, charB, intA, charA) << '\n';
	outFile << combineString(strA , strB, strC, strD, strE);

	outFile.close();
	inFile.close();

	return 0;
}

//Determines whether a string is an available file name, depending whether the string reads or writes a file.
string getFileName(ios_base::open_mode mode)
{
	string inString; 

	if (mode == ios::in || mode == ios::app)
	{
		do
		{
			inString = utils::getStrFromUser("Enter an input file: ");
			if (!utils::fileExists(inString))
			{
				cout << "?Invalid file name: file does not exist" << endl;;
			}
		} while (!utils::fileExists(inString));
	}
	else
	{
		do
		{
			inString = utils::getStrFromUser("Enter an output file: ");
			if (utils::fileExists(inString))
			{
				cout << "?Invalid file name: file already exists" << endl;
			}
		} while (utils::fileExists(inString));
	}
	return inString;
}

//Computes the volume of ellipsoid.
double volume(double axisA, double axisB, double axisC)
{
	return (4.0 / 3.0) * axisA * axisB * axisC;
}

//Computes the distance between two points
double distance(double corA_x, double corA_y, double corB_x, double corB_y)
{
	return sqrt(pow(corB_x - corA_x, 2) + pow(corB_y - corA_y, 2));
}

//Computes the slope defined by two points
double slope(double corA_x, double corA_y, double corB_x, double corB_y)
{
	return (corB_y - corA_y) / (corB_x - corA_x);
}

//Transposes an arbitrary sequence chars, ins and floats
string transposeString(char charA, char charB, int intA, float floatA)
{
	string result;
	ostringstream strStream(result);
	strStream << floatA <<" " << charB << " " << intA << " "<< charA;
	return result;
}

//Combines a sequence of five strings and puts a space between them
string combineString(string strA, string strB, string strC, string strD, string strE)
{
	return strD + " " + strA + " " + strC + " " + strB + "\n" + strE;
}

