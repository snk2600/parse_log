#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
using namespace boost;
using namespace std;

int main(int argc, char** argv){
	for (int i = 0; i < argc; ++i)
		cout << argv[i] << "\n";
	fstream myfile;
	ofstream file("logmod.html"); 
	string line, abc, searchString, replaceString, filePathString;
	//string path = argv[0], filename = argv[1];
	//ireplace_all(path, "\\Project1.exe", "");
	int lineNumber = 1;
	//filePathString = path + "\\" + filename;
	
	//argv line is for command line argment of filepath, hardcoding for testing
	//myfile.open(argv[1]);
	myfile.open("log");
	//file << "<html><body>" << endl;
	while(getline(myfile,line)){
		searchString = argv[2];
		//cout << searchString;
		replaceString = "<mark>" + searchString + "</mark>";
		if (line.find(searchString) != std::string::npos) {
			ireplace_all(line, searchString, replaceString);
			file << "<b><a class=\"anchor\" id=\"instance" << lineNumber << "\">" << setw(6) << setfill('0') << lineNumber << ":&nbsp&nbsp&nbsp" << line << "</a></b><br>" << endl;
		}
		else {
			//cout << lineNumber << lineNumber << line << endl;
			//cout << setw(6) << setfill('0') << lineNumber << ":   " << line << endl;
			file << setw(6) << setfill('0') << lineNumber << ":&nbsp&nbsp&nbsp" << line << "<br>" << endl;
			//cin >> abc;
		}
		lineNumber += 1;
	}
	//file << "</body></html>" << endl;
	myfile.close();
	return 0;

}