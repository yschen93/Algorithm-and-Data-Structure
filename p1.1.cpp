#include <iostream>
#include <vector>

using namespace std;


//search two different numbers which appear in odd times
int main()
{
    vector<int> vi = {1,2,3,1,2,3,4,1,2,3,4,5,3,5};  //3个1，3个2，4个3，2个4，2个5
    int eor = 0;
    for (size_t i = 0; i < vi.size(); ++i)
    {
        eor ^= vi[i]; 
        //eor = a ^ b;(a != b)
        //eor != 0;search rightOne
    }

    int rightOne = eor & (~eor+1);

    int eor2 = 0;
    for (size_t i = 0; i < vi.size(); ++i)
    {
        if ((vi[i] & rightOne) == 1)
            eor2 ^= vi[i];
    }

    cout << "The first number is " << eor2 << ", second number is " << (eor2 ^ eor) << endl;
    return 0;
}
