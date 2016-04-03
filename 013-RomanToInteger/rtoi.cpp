#include <iostream>

using namespace std;

/**

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

string one[11] = {"", "I","II","III","IV","V","VI","VII","VIII","IX"};          ///  ��λ
string ten[11] = {"", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};         ///  ʮλ
string hundred[11] = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};      ///  ��λ
string thousand[4] = {"", "M", "MM","MMM"};                                     ///  ǧλ


*/

class Solution {
public:
    int romanToInt(string s)
    {
        int result = 0;
        const char* p = s.c_str( );
        int count = 0;

        //ǧλ
        while(*p!='\0'&&*p=='M')
        {
            p++;        //ǧλѭ��������pָ���λ��
            count++;
        }
        result += 1000 * count;
        count=0;

        //��λ
        if(*p == 'C')
        {
            while(*p!='\0'&&*p=='C')
            {
                p++;
                count++;
            }
            if(count==1&&*p=='M')
            {
                p++;
                count=9;
            }
            else if(count==1&&*p=='D')
            {
                p++;
                count=4;
            }
        }else if(*p=='D')
        {
            p++;
            count=5;
            while(*p!='\0'&&*p=='C')
            {

                p++;
                count++;
            }

        }
        else
        {
            count=0;
        }
        result+=count*100;
        count=0;


        //ʮλ
        if(*p=='X')
            {
            while(*p!='\0'&&*p=='X')
            {
                p++;
                count++;
            }
            if(count==1&&*p=='C')
            {
                p++;
                count=9;
            }
            else if(count==1&&*p=='L')
            {
                p++;
                count=4;
            }
        }else if(*p=='L') {
            p++;
            count=5;
            while(*p!='\0'&&*p=='X')
            {
                p++;
                count++;
            }

        }else{
            count=0;
        }
        result+=count*10;
        count=0;


        //��λ
        if(*p=='I')
            {
            while(*p!='\0'&&*p=='I')
            {
                p++;
                count++;
            }
            if(count==1&&*p=='X')
            {
                p++;
                count=9;
            }
            else if(count==1&&*p=='V')
            {
                p++;
                count=4;
            }
        }
        else if(*p=='V')
        {
            p++;
            count=5;
            while(*p!='\0'&&*p=='I')
            {
                p++;
                count++;
            }

        }
        else
        {
            count=0;
        }
        result+=count;

        return result;
    }
};


int main(void)
{

}
