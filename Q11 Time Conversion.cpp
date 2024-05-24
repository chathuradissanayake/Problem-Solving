#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string period = s.substr(8, 2); // Extract AM/PM part
    string hour = s.substr(0, 2);   // Extract hour part
    int h = stoi(hour);

    if (period == "PM") {
        if (h != 12) {
            h += 12;
        }
    } else { // AM case
        if (h == 12) {
            h = 0;
        }
    }

    stringstream new_s;
    new_s << setw(2) << setfill('0') << h << s.substr(2, 6); // Format hour and append rest of the time

    return new_s.str();

}


//There have a one failed test case
// string timeConversion(string s) {      
//     string new_s;
//     if (s.find("PM") != string::npos){
//         string hour = s.substr(0, 2);
//         int h = stoi(hour);
//         h+= 12;
//         string h2 = to_string(h);
//         s.replace(0, 2, h2);
//         new_s = s.substr(0,8);
//     }
//     else if(s.find("AM") != string::npos && s.substr(0,2)=="12"){
//         s.replace(0, 2, "00");
//         new_s = s.substr(0,8);
//     }

//     else {
//         new_s = s.substr(0,8);

// }
//     return new_s;

// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
