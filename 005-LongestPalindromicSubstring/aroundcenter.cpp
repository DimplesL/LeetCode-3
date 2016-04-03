#define DEBUG
//  �����������

#include <iostream>
#include <string>
// http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Par-I.html
#include <cstdio>
#include <cstdlib>

/*

�������һ��O(N2)ʱ��O(1)�ռ���㷨��

���ĵ��ص㣬�������ĶԳơ�

������N���ַ����ַ���S��ֻ��2N-1�����ġ�

Ϊ����2N-1����Ϊ�����ַ�֮��Ŀյ�Ҳ������һ�����ġ����硱abba��������b�м����һ�����ġ�

Χ��һ�����ļ�������ҪO(N)ʱ�䣬�����ܵ�ʱ�临�Ӷ���O(N2)��

*/
class Solution
{
public:
	std::string expandAroundCenter(std::string s, int left, int right)
	{
  		int len = s.length();
  	
  		while (left >= 0 
  			&& right <= len - 1 
  			&& s[left] == s[right])
  		{
    		left--;
    		right++;
  		}
  		
  		return s.substr(left + 1, right - left - 1);
	}
 
	std::string longestPalindrome(std::string s)
	{
  		int n = s.length( );
  		if (n == 0)
  		{
  			return "";
  		}
  		
  		std::string longest = s.substr(0, 1);  // a single char itself is a palindrome
  		for (int center = 0; center < n - 1; center++)		//  ѭ��ÿ������
  		{
  			//  ��centerwΪ���ĵ�����Ĵ�
    		std::string p1 = expandAroundCenter(s, center, center);
    		if (p1.length() > longest.length())
    		{
      			longest = p1;
			}
			
			//  ��center��center + 1Ϊ���ĵ�����Ĵ�
    		std::string p2 = expandAroundCenter(s, center, center + 1);
    		if (p2.length() > longest.length())
    		{
      			longest = p2;
  			}
  		}
  		
  		return longest;
	}
};


#ifdef DEBUG

int main(void)
{
	Solution solu;

	std::cout <<solu.expandAroundCenter("aabcddcbac", 4, 5) <<std::endl;
	std::cout <<solu.longestPalindrome("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode") <<std::endl;


	return EXIT_SUCCESS;
}
#endif
