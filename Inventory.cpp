#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// will hold the type of data
enum typeOfData { regular, warning, error};
// will hold the string values for typeOfData
const char* strings[] = {"regular", "warning", "error"};
  
// function to store the data to a file or console
void storeData(typeOfData typ, string desc, string file)
{
    ifstream inf(file.c_str()); // will be used to check if path exists

    // if file path is not valid, output to console
    if (!inf)
    {
            cout << strings[typ] << ": " << desc << endl;
            inf.close();
            return;
    }
    
    // if file path is valid
    ofstream outf(file.c_str());
    outf << strings[typ] << ": " << desc << endl;
    outf.close();
}
int main()
{
    storeData(warning, "item x has been moved to position y.", "console");
    storeData(regular, "item x has been moved to position y.", "./nips.txt");
    return 0;
}
