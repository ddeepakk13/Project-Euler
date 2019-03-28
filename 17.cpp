#include <iostream>
using namespace std;

long long get1digitLen(int num);
long long get2digitLen(int num);
long long get3digitLen(int num);

int main()
{
    int digits = 1;
    long long charCount = 0;
    for(int num = 0; num < 1000; num++)
    {
        if(num == 10 || num == 100)
            digits++;

        switch(digits)
        {
            case 1: charCount += get1digitLen(num); break;
            case 2: charCount += get2digitLen(num); break;
            case 3: charCount += get3digitLen(num); break;
        }
    }
    cout << charCount + 11  << endl;
    cout << get3digitLen(105) << endl;
}

long long get1digitLen(int num)
{
    switch(num)
    {
        case 1:
        case 2:
        case 6: return 3;
        case 4:
        case 5:
        case 9: return 4;
        case 3:
        case 7:
        case 8: return 5;
        case 0: return 0;
    }
    cout << "Rogue Function 1digit " << num << endl;
    return 0;
}

long long get2digitLen(int num)
{
    int buf = num;
    int d0 = num % 10;
    num /= 10;
    int d1 = num % 10;
    num /= 10;

    if(d1 == 1)
    {
        switch(d0)
        {
            case 1:
            case 2: return 6;
            case 0: return 3;
            case 5:
            case 6: return 7;
            case 3:
            case 4:
            case 8:
            case 9: return 8;
            case 7: return 9;
        }
    }

    switch(d1)
    {
        case 4:
        case 5:
        case 6: return 5 + get1digitLen(d0);
        case 2:
        case 3:
        case 8:
        case 9: return 6 + get1digitLen(d0);
        case 7: return 7 + get1digitLen(d0);
        case 0: return get1digitLen(d0);
    }
    cout << "Rogue Function 2digit " << buf << endl;
    return 0;
}

long long get3digitLen(int num)
{
    int d0 = num % 10;
    num /= 10;
    int d1 = num % 10;
    num /= 10;
    int d2 = num % 10;
    num /= 10;
    int twoDigitLen = get2digitLen(d1 * 10 + d0);
    if(twoDigitLen == 0)
        return get1digitLen(d2) + 7;
    return get1digitLen(d2) + 10 + twoDigitLen;
}