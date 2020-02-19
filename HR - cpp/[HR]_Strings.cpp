#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;

    cin >> s1 >> s2;

    cout << s1.length() << " " << s2.length() <<endl;
    cout << s1+s2 << endl;

    char s1_char = s1[0];
    char s2_char = s2[0];
    s1[0] = s2_char;
    s2[0] = s1_char;

    cout << s1 << " " << s2 << endl;
  
    return 0;
}

