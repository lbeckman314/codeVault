#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
//declare variables
	
	int var;
	ifstream diskFile;
	string path;
	diskFile.close();
//prompt for and get the file path
	cout << "enter path of file" << endl;
	cin >> path;

//open the file

	diskFile.open(path.c_str());		//(path/to/file.txt)	//c_str() = portable, works on any c++ compiler

	while(!diskFile.eof())
	{
//read the file
	//cin 	 >> someVar;	ANALOGY
	//input = diskFile.get();

//output the things we read
	cout << (char)diskFile.get();
	}

//close file, pause and exit
	diskFile.close();


	getchar();
	getchar();
	return 0;
}