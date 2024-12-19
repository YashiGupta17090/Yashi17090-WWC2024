//Print your whole academic bio data,Name ,UId,section,area of interest(tech),Last yera GGPA,DOB,home town

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define variables to hold the bio data
    string name = "Yashi Gupta";      
    string uid = "22BCS17090";        
    string section = "630-A";         
    string areaOfInterest = "Data Science"; 
    float lastYearGPA = 6.9;        
    string dob = "01-09-2004";       
    string homeTown = "Bahraich,UP";   

    // Print the bio data
    cout << "===== Academic Bio Data =====" << endl;
    cout << "Name: " << name << endl;
    cout << "UID: " << uid << endl;
    cout << "Section: " << section << endl;
    cout << "Area of Interest (Tech): " << areaOfInterest << endl;
    cout << "Last Year GPA: " << lastYearGPA << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Home Town: " << homeTown << endl;

    return 0;
}
