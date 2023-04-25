#include <variant>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    variant<string, int> v;
    v = "Hello";
    cout << get<string>(v) << endl;
    v = 5;
    cout << get<int>(v) << endl;
    vector<variant<string, int>> vec;
    vec.push_back("Hello");
    vec.push_back(5);
    cout << get<string>(vec[0]) << endl;
    cout << get<int>(vec[1]) << endl;
    return 0;
}