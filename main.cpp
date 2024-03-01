#include "evaluate.h"

int main()
{
    Stack P;
    string str = "(((((15-10)*4)+100)+1000)/2)";
    int result = evaluate(str);
    cout << endl << str << "=";
    cout << " " << result << endl;
    return 1;
}