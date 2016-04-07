#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        bool res = true;
        if(s == "")
        {
            return true;
        }

        for(int i = 0; i < s.length( ); i++)
        {
            // ���������ž���ջ
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {   //  ���������žͳ�ջ

                //  ��ջʱ��, ���ջΪ��, ��϶���ƥ��
                if(st.empty( ) == true)
                {
                    res = false;
                    break;
                }

                //  ����ջ��Ԫ�ؿ��Ƿ�ƥ��
                char temp = st.top();
                st.pop( );
                if(s[i] == ')' && temp != '(')
                {
                    res = false;
                    break;
                }
                else if(s[i] == ']' && temp != '[')
                {
                    res = false;
                    break;
                }
                else if(s[i] == '}' && temp != '{')
                {
                    res = false;
                    break;
                }
            }
        }

        // ������Ϣ�������Ժ������ջ��Ϊ��, ˵���϶���ƥ��
        if(st.empty() != true)
        {
            res = false;
        }


        return res;
    }
};


int main()
{

    Solution solu;
    std::cout <<solu.isValid("]") <<std::endl;

    return 0;
}
