#include <iostream>
#include <string>


using namespace std;


/*
1) Implements file name & path validation on either the input file (.cpp) or output file (.html)
2) Reads in a C++ source file (.cpp)
3) Converts all < symbols to &lt and all > symbols to &gt;
4) Inserts the <PRE> and </PRE> tags to the front and end of the html file respectively.
5) Outputs the modified file as an html file.
*/

string getFile();
bool validateFile(string, string&);
void outputFile();

int main() {
    cout << "Welcome to the File Converter" << endl;
    cout << "Please enter the full path and name of the file: ";
    string fileLine = getFile();




    for(char i : fileLine)
    {
        string fileChar = string(1,i);
        if(fileChar == "<")
            cout << "write &lt to output file" << endl;
        else
            cout << "write fileChar to output file" << endl;
    }
    cout << "write a carriage return for last line copied" << endl;
    return 0;
}//end method

bool validateFile(string file, string& errorMsg) {
    //Validates file passed in with error message pointer
    //changes error message based on error to send back to getFile



}

string getFile() {
    //Gets the file from console, outputs mutable error message if invalid
    string fileName;
    string errorMsg;
    do {
        cout << "Enter file path and name: " << endl;
        getline(cin, fileName);

        if (validateFile(fileName, errorMsg)) {
            return fileName;
        }
        else {
            cout << "Error: " + errorMsg <<endl;
        }

    } while (true);
}

void outputFile() {
    //Reads the file from getFile if valid and outputs html file with desired formatting


}