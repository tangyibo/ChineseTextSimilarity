/*
 * CosineSimilarity.hpp
 *
 *  Created: 2016年10月2日
 *   Author: tang
 */

#ifndef SRC_COSINE_SIMILARITY_HPP_
#define SRC_COSINE_SIMILARITY_HPP_
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include "StringUtil.hpp"

using namespace std;

class CosineSimilarity
{
public:
	CosineSimilarity()
	{
	}

	double CalculateTextSimilarity(string &str1,string &str2)
	{
		vector<uint16_t> words_for_str1;
		vector<uint16_t> words_for_str2;
		vector<uint16_t>::iterator it;

		if(!utf8ToUnicode< vector<uint16_t> >(str1,words_for_str1) || 
			!utf8ToUnicode< vector<uint16_t> >(str2,words_for_str2 ) )
		{
			cout<<"TransCode Error"<<endl;
			return 0.;
		}

		map< uint16_t,pair<int,int> >seq_map;
		map< uint16_t,pair<int,int> >::iterator map_it;
		for(it=words_for_str1.begin();it!=words_for_str1.end();++it)
		{
			if(isHanzi(*it))
			{
				map_it=seq_map.find(*it);
				if(map_it!=seq_map.end())
				{
					map_it->second.first++;
				}
				else
				{
					pair<int,int> seq;
					seq.first=1;
					seq.second=0;
					seq_map[*it]=seq;
				}
			}
		}

		for(it=words_for_str2.begin();it!=words_for_str2.end();++it)
                {
			if(isHanzi(*it))
                        {
                                map_it=seq_map.find(*it);        
                                if(map_it!=seq_map.end())
                                {
                                        map_it->second.second++;
                                }
                                else
                                {
					pair<int,int> seq;
                                        seq.first=0;
                                        seq.second=1;
                                        seq_map[*it]=seq;
                                }
                        }
                }

		double sqdoc1 = 0.;  
        double sqdoc2 = 0.;  
        double denominator = 0.;

		for(map_it=seq_map.begin();map_it!=seq_map.end();++map_it)
		{
			pair<int,int> c=map_it->second;
			denominator +=(c.first * c.second);
			sqdoc1+=(c.first * c.first);
			sqdoc2+=(c.second * c.second);
		} 

		if(0==sqdoc1 * sqdoc2)
			return -1.0;

		return denominator/sqrt(sqdoc1 * sqdoc2);
	}

	bool codeFilter(int code) 
	{
        	if ((code < 0x4e00 || code > 0x9fa5) && 
			!(code >= '0' && code <= '9') && 
			!(code >= 'a' && code <= 'z') && 
			!(code >= 'A' && code <= 'Z'))
           		 return false;
        
        	return true;
	}

	bool isHanzi(uint16_t ch)
	{
		return (ch >= 0x4E00 && ch <= 0x9FA5);
	}
};

#endif /* SRC_COSINE_SIMILARITY_HPP_ */
