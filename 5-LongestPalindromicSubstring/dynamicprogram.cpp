#define DEBUG
//  �����������

#include <iostream>
#include <string>
// http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Par-I.html
#include <cstdio>
#include <cstdlib>

/*

���ǿ����ö�̬�滮(Dynamic Programming��DP)���Ա�����ٷ����иĽ���

��ס�����Ͼ��Ǳ����ظ����㣨���ظ����ͬһ�Ӵ�����

����������ӡ�ababa����

��������Ѿ�������bab���ǻ��ģ�

��ôֻ���ж�һ�������ҵ������ַ���������a���Ƿ���ͬ

�����ж���ababa���Ƿ�����ˡ�

�ܽ��������ǣ�

�����ά����P[i,j]

���Ա�ʾSi��Sj�ǻ��ģ�true�����ǻ��ģ�false��

��ô��֪P[i,j] = (P[i + 1, j - 1] && Si ==Sj)

��ʼ�����ǣ�P[i, i]=true��P[i, i + 1] = (Si == Si+1)

���DP����˼·���ǣ����ȿ���֪�������ַ������������ַ��Ƿ���ģ�Ȼ�������������ַ��Ƿ���ģ�Ȼ���ĸ�������

���㷨ʱ�临�Ӷ�O(N2)���ռ临�Ӷ�O(N2)��α�������¡�

*/
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
		int n = s.length();

  		int longestBegin = 0;
  		int maxLen = 1;

  		bool P[1000][1000] = {false};

  		/*for(int i = 0; i < 1000; i++)
  		{
  			for(int j = 0; j < 1000; j++)
  			{
  				std::cout <<P[i][j];
  			}
  		}*/

  		//  ==��ʼ��==
  		//  P[i, i] = true
  		//  P[i, i + 1] = (Si == Si+1)

  		//  ���ȳ�ʼ��P[i, i] = true
  		for (int i = 0; i < n; i++)
  		{
    		P[i][i] = true;
  		}

  		//  Ȼ���ʼ�� P[i, i + 1] = (Si == Si+1)
  		for (int i = 0; i < n - 1; i++)
  		{
    		if (s[i] == s[i+1])
    		{
      			P[i][i+1] = true;
      			longestBegin = i;
      			maxLen = 2;
    		}
  		}

  		//  ��ʼ��̬�滮
  		//  P[i,j] = (P[i + 1, j - 1] && Si == Sj)
  		for (int len = 3; len <= n; len++)  //  ѭ�����г���
  		{
    		for (int start = 0; start < n - len + 1; start++)   //  ѭ�����Ĵ�����ʼλ��
    		{
      			int end = start + len - 1;

      			if (s[start] == s[end]
                 && P[start + 1][end - 1])
      			{
        			P[start][end] = true;

                    longestBegin = start;
        			maxLen = len;
      			}
    		}
  		}
  		return s.substr(longestBegin, maxLen);
	}
};
#ifdef DEBUG

int main(void)
{
	Solution solu;

	//std::cout <<solu.isPalindromicSubstring("abcddcba") <<std::endl;
	std::cout <<solu.longestPalindrome("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode") <<std::endl;


	return EXIT_SUCCESS;
}
#endif
