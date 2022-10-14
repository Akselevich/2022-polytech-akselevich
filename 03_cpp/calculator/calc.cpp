#include <iostream>
#include <cmath>
using namespace std;
void in() {
   long double a = 0, b = 0;
    char sign = ' ';
    cin >> a >> sign >> b;
    if (!(sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^')) {
        cout << "error\n";
      }
    else {

        switch (sign) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '/':
            if (b != 0)
                cout << a / b;
            else {
                cout << "err";
            }
            break;
        case '*':
            cout << a * b;
            break;
        case '^':
            cout << pow(a,b);
        }
           
    }
    cout << "\n";
}
int main()
{ 
    while (1) {
       cout << "enter equation" << "\n";
       in();   
    }
    return 0;
}
