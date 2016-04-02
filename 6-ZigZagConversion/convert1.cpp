#include <iostream>
#include <string>


#define DEBUG
//http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Part-II.html

/*
����nRows��char���飬��s����0,1,2,...,nRows-2,nRows-1,nRows-2,...,2,1,0��˳��

��s��ÿ���ַ�װ�����顣

������˵�������±��ȵ�����ֱ��nRows-1������ֱ��0���ٷ��򣬡���ֱ��s�ַ�ȫ��װ�������

���������0~nRows-1�����顣
*/

class Solution {
public:
    std::string convert(std::string s, int nRows)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::string result;

        if (nRows < 2) return s;

        for (int i = 0;i < nRows; ++i)
        {
            for (int j = i; j < s.length(); j += 2 * (nRows - 1))
            {
                result.push_back(s[j]);

                if (i > 0 && i < nRows - 1)
                {
                    if (j + 2 * (nRows - i - 1) < s.length())
                    {
                        result.push_back(s[j + 2 * (nRows - i - 1)]);
                    }
                }
            }
        }

        return result;
    }
};


#ifdef DEBUG

int main(void)
{
    Solution solu;

    std::cout <<solu.convert("PAYPALISHIRING", 3) <<std::endl;

    return 0;
}

#endif
