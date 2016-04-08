#include <iostream>
#include <vector>

using namespace std;


#define __tmain main


class Solution
{
public :
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        generateParenthesis(v, "", n, n);

        return v;
    }

    void generateParenthesis(vector<string> &v, string s, int l, int r) // l��r��¼ʣ���������ŵ�����
    {
        // ���ҽ�����������������Ϊ0ʱ����������
        if(l == 0 && r == 0)
        {
            v.push_back(s);
        }

        //  ����Ҫ��ƥ�䣬����Ӧ��ѹ�������ţ���ѹ��������
        if(l > 0)
        {
            generateParenthesis(v, s + "(", l - 1, r);
        }
        //  ѹ��������ʱ�򣬱��뱣֤���������࣬�����������ڽ⼯��
        if(r > 0 && l < r) // ʣ��������������������Ŷ�ʱ�������������
        {
            generateParenthesis(v, s + ")", l, r - 1);
        }
    }
};

int __tmain( )
{
    Solution solu;
    vector<string> res = solu.generateParenthesis(3);

    for(int i = 0; i <res.size(); i++)
    {
        cout <<res[i] <<endl;
    }
}
