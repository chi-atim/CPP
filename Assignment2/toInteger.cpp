#include<iostream>
using namespace std;

int toInteger(const string& str);
int toInteger(const string& str, int high);
int toIntegerIterative(const string& str);

int main(){
    cout << toInteger("753") << endl;
    cout << toIntegerIterative("005")<< endl;
    return 0;
}

int toInteger(const string& str){
    return toInteger(str, str.size()-1);
}
int toInteger(const string& str, int high){
    if (high==0)
        return str[high]-'0';
	return toInteger(str, high-1) * 10 + (str[high] - '0');

}
int toIntegerIterative(const string& str){
    int result=0;
    for (int i=0; i<str.size(); i++)
        result = result * 10 + (str[i] - '0');
    return result;
}
