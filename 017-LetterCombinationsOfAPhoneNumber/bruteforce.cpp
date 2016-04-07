#include <iostream>
#include <vector>
using namespace std;

#define __tmain main

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits == "")
        {
            return res;
        }


        vector<string> dict(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";

        res.push_back("");

        //  ����2, ���ɽ�ռ�a, b, c
        //  ����3, ��ȡ��ԭ���Ľ⣬�ټ��ϵ�ǰ��
        for(int i = 0; i < digits.size(); i++)      //  ѭ�������ÿ���ַ�
        {
            int size = res.size( );
            for(int j = 0; j < size; j++)     //  ����ԭ���Ľ�ռ�
            {
                string cur = res[0];
                //std::cout <<"ȡ��" <<cur <<endl;
                res.erase(res.begin());
                //std::cout <<"��ȡ" <<dict[digits[i] - '0'] <<endl;
                for(int k = 0; k < dict[digits[i] - '0'].size(); k++)
                {
                    res.push_back(cur + dict[digits[i] - '0'][k]);
                    //std::cout <<"���" <<dict[digits[i] - '0'][k] <<endl;

                }
            }
        }

        return res;
    }
};

int __tmain(void)
{

    string digits = "23";
    Solution solu;
    vector<string> res = solu.letterCombinations(digits);
    for(int i = 0; i < res.size( ); i++)
    {
        std::cout <<res[i] <<endl;
    }
    return 0;
}
