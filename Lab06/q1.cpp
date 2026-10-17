#include <iostream>
#include <string>
using namespace std;

void permutation(string s, int i, int n){
    if(i == n){
        cout << s << endl;
        return;
    }

    for(int j = i; j < n; j++){
        swap(s[i], s[j]);
        permutation(s, i + 1, n);
        swap(s[i], s[j]);
    }
}

int main(){
    string s;
    do{
        cout << "Enter string: ";
        cin >> s;
    }while(s.length() > 26);

    int n = s.length();
    permutation(s, 0, n);
}

