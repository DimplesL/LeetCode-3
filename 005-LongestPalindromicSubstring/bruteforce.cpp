#define DEBUG
//  �����������

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

/*

��򵥵ľ��Ǳ������(Brute Force)

��ÿ��start��endλ�õ��Ӵ����м�⣬

�ж����Ƿ���ġ�

��Ȼ��C(N,2)����ϣ����Ӵ���

���ÿ���Ӵ�����ҪO(N)��ʱ�䣬

���Դ˷�����ʱ�临�Ӷ�ΪO(N3)��

*/
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
   		// ==������==
   		//  ѭ�������Ӵ�
   		//  �жϸ��Ӵ��Ƿ��ظ�
   		std::string subs, maxsubs;
   		int length, maxlength = 0;
   		int maxlen = 0;

	   	for(int start = 0; start < s.size(); start++)
   		{
   			for(int length = 1; length <= s.size() - start; length++)
			{
				subs = s.substr(start, length);
				//std::cout <<subs <<std::endl;
				if(isPalindromicSubstring(subs) == true
				&& maxlen < subs.length())
				{
					maxlen = subs.length();
					maxsubs = subs;
				}
			}
		}

		return maxsubs;
    }

	bool isPalindromicSubstring(std::string s)
	{
		int start = 0;
		int end = s.length() - 1;

		while(start < end
		   && s[start] == s[end])
		{
			start++;
			end--;
		}
		//std::cout <<start <<", " <<end <<std::endl;
		return (start >= end);
	}
};
#ifdef DEBUG

int main(void)
{
	Solution solu;

	//std::cout <<solu.isPalindromicSubstring("abcddcba") <<std::endl;
	std::cout <<solu.longestPalindrome("gatiemeabcdeedcbagatieme") <<std::endl;


	return EXIT_SUCCESS;
}
#endif
