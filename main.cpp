#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <exception>


using namespace std;


/*
1) Implements file name & path validation on either the input file (.cpp) or output file (.html)
2) Reads in a C++ source file (.cpp)
3) Converts all < symbols to &lt and all > symbols to &gt;
4) Inserts the <PRE> and </PRE> tags to the front and end of the html file respectively.
5) Outputs the modified file as an html file.
*/
//Found this validation example: https://regex101.com/r/9J5JPW/1
//I promoise I can explain it
string regexPhrase = "^([a-z]:)?(?:[\\]?(?:[\w !#()-]+|[.]{1,2})+)*[\\])??:[.]?[\w !#()-]+)+)?[.]?$";
struct errorMsg {
    std::string message;
};

bool validateFile(string file, string& errorMsgStr) {
    //Validates file passed in with error message pointer
    //changes error message based on error to send back to getFile

    ifstream in(file);

    if (!in.is_open()) {
        errorMsgStr = "Entered file does not exist or failed to open";
        return false;
    } else {
        in.close();
        return true;
    }
}

string getFile() {
    //Gets the file from console, outputs mutable error message if invalid
    string fileName;
    string errorMsgStr;
    do {
        cout << "Enter file name with path: " << endl;
        getline(cin, fileName);

        if (validateFile(fileName, errorMsgStr)) {
            return fileName;
        }
        else {
            cout << "Error: " + errorMsgStr <<endl;
        }

    } while (true);
}

void convertFile(const std::string& inputFile, const std::string& outputFile ) {
    //Reads the file from getFile if valid and outputs html file with desired formatting
    try {

    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }
    catch (const errorMsg& e) {
        cerr << "Error: " << e.message << endl;
    }

        for(char i : inputFile)
        {
            string fileChar = string(1,i);
            if(fileChar == "<")
                cout << "write &lt to output file" << endl;
            else
                cout << "write fileChar to output file" << endl;
        }
    cout << "write a carriage return for last line copied" << endl;
}

int main() {
    cout << "Welcome to the File Converter!\n" << endl;

    cout << "\n.cpp file for input:" << endl;
    string cppFile = getFile();
    cout << "\n.html file for output: " << endl;
    string htmlFile = getFile();

    convertFile(cppFile, htmlFile);

    return 0;
}//end method

