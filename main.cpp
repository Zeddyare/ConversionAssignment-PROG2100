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
string regexPhrase = R"(^[a-zA-Z]:\\(?:[\w\s\-\(\)#]+\\)*[\w\s\-\(\)#]+\.(cpp|html)$)";
//String literal (R) so the slashes do not get treated as delimiters
struct errorMsg {
    string message;
};

bool validateFile(string file, string& errorMsgStr) {
    //Validates file passed in with error message pointer
    //changes error message based on error to send back to getFile
    regex filePattern(regexPhrase);

    if (!regex_match(file, filePattern)) {
        errorMsgStr = "File name or path is invalid.";
        return false;
    }

    ifstream in(file);

    if (!in.is_open()) {
        errorMsgStr = "Entered file does not exist or failed to open";
        return false;
    }
    in.close();
    return true;
}

string getFile() {
    //Gets the file from console, outputs mutable error message if invalid
    string fileName;
    string errorMsgStr;
    do {
        getline(cin, fileName);

        if (validateFile(fileName, errorMsgStr)) {
            return fileName;
        }
        else {
            cout << "Error: " + errorMsgStr <<endl;
            cout << "Please try again: " << endl;
        }

    } while (true);
}

void convertFile(const string& inputFile, const string& outputFile) {
    try {
        ifstream inStream(inputFile);
        if (!inStream.is_open()) {
            throw errorMsg{"Failed to open input file."};
        }

        ofstream outStream(outputFile);
        if (!outStream.is_open()) {
            throw errorMsg{"Failed to open output file."};
        }

        outStream << "<PRE>\n";
        string line;
        while (getline(inStream, line)) {
            for (char c : line) {
                if (c == '<') outStream << "&lt;";
                else if (c == '>') outStream << "&gt;";
                else outStream << c;
            }
            outStream << "\n";
        }
        outStream << "</PRE>\n";

        inStream.close();
        outStream.close();
    }
    catch (const ios_base::failure& e) {
        cerr << "Library exception: " << e.what() << endl;
    }
    catch (const errorMsg& e) {
        cerr << "Programmer exception: " << e.message << endl;
    }
    catch (const exception& e) {
        cerr << "Default exception: " << e.what() << endl;
    }
}

int main() {
    cout << "Welcome to the File Converter!\n" << endl;

    cout << "\nEnter file path and name of .cpp file for input:" << endl;
    string cppFile = getFile();
    cout << "\nEnter file path and name of .html file for output: " << endl;
    string htmlFile = getFile();

    convertFile(cppFile, htmlFile);

    cout << "\nProgram executed successfully." << endl;

    return 0;
}//end method

