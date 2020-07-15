#include <iostream>
#include <string>
using namespace std;

string getTime(string s) {
    int l = s.length(), i = 0;
    string result;
    char c;

    // Check if Post meridiem (PM), then change hours only. 
    if (s[l - 2] == 'P') {
        // if input: 12:45:54PM
        // then output should be 12:45:54 as it is.
        if (s[0] == '1' && s[1] == '2') {
            result.push_back(s[0]);
            result.push_back(s[1]);
            i= i + 2;
        }
        else {
            // if hours > 12, 
            // then add '1' and '2' in corresponding indices. 
            c = s[i++];
            result.push_back(++c);
            c = s[i++];
            c = (c % 59) + 2;
            result.push_back(c);
        }
    }
    else {
        // Check if 12 a.m,
        // then change hours to 00:MM:SS
        if (s[0] == '1' && s[1] == '2') {
            result.push_back('0');
            result.push_back('0');
            i = i + 2;
        }
    }
    while (i < l - 2) result.push_back(s[i++]);
    return result;
}

int main()
{
    string s;
    cout << "Enter Time in HH:MM:SS[AM/PM] format\n\n"
            "Example:\n\tInput: \t07:45:54PM\n"
            "\tOutput:\t19:45:54\n";

    cout << "\nEnter 12-Hours format time string: ";
    cin >> s;
    cout << "Converted time string is: ";
    cout << getTime(s) << "\n";
 
    return 0;
}
