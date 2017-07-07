#include <iostream>
#include <fstream>

//this define can avoid some logs which you don't need to care about.
#define LOGGER_LEVEL LL_WARN 

#include "simhash/Simhasher.hpp"
using namespace simhash;

int test_simhash()
{
    Simhasher simhasher("./dict/jieba.dict.utf8", "./dict/hmm_model.utf8", "./dict/idf.utf8", "./dict/stop_words.utf8");
    string s("我是蓝翔技工拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上总经理，出任CEO，走上人生巅峰。");
    size_t topN = 5;
    uint64_t u64 = 0;
    vector<pair<string ,double> > res;
    simhasher.extract(s, res, topN);
    simhasher.make(s, topN, u64);
    cout<< "文本：\"" << s << "\"" << endl;
    cout << "关键词序列是: " << res << endl;
    string ret;
    simhasher.toBinaryString(u64,ret);
    cout<< "simhash值是: " << ret<<endl;


    const char * bin1 = "100010110110";
    const char * bin2 = "110001110011";
    uint64_t u1, u2;
    u1 = Simhasher::binaryStringToUint64(bin1); 
    u2 = Simhasher::binaryStringToUint64(bin2); 
    
    cout<< bin1 << "和" << bin2 << " simhash值的相等判断如下："<<endl;
    cout<< "海明距离阈值默认设置为3，则isEqual结果为：" << (Simhasher::isEqual(u1, u2)) << endl; 
    cout<< "海明距离阈值默认设置为5，则isEqual结果为：" << (Simhasher::isEqual(u1, u2, 5)) << endl; 

   return EXIT_SUCCESS;
}

int test_similarity()
{
	string s1="【环球网综合报道】中国证监会指定信息披露网站(巨潮资讯网)7月6日发布有关乐视公告。 公告中称，贾跃亭先生将辞去乐视网董事长一职，同时辞去董事会提名委员会委员、审计委员会委员、战略委员会主任委员、薪酬与考核委员会委员相关职务，退出董事会，辞职後将不再在乐视网担任任何职务。";
	string s2="凤凰财经讯 7月7日乐视资金链危机有了最新进展，乐视创始人贾跃亭辞去乐视所有职务，有消息人士确认，贾跃亭在加州时间周二晚上抵达美国洛杉矶，次日会见了乐视汽车和Faraday Future团队，将继续推进乐视汽车相关事务。 另外7月17日乐视网将举行临时股东大会，将选举新董事长，分析称孙宏斌很有可能上";
	
	Simhasher simhasher("./dict/jieba.dict.utf8", "./dict/hmm_model.utf8", "./dict/idf.utf8", "./dict/stop_words.utf8");

   	size_t topN = 5;
    	uint64_t u64_1 = 0 ,u64_2=0;
    	vector<pair<string ,double> > res1,res2;
    	simhasher.extract(s1, res1, topN);
	cout << "s1关键词序列是: " << res1 << endl;
	simhasher.extract(s2, res2, topN);	
	cout << "s2关键词序列是: " << res2 << endl;
	simhasher.make(s1, topN, u64_1);
	simhasher.make(s2, topN, u64_2);
	
	cout<<"相似结果为："<<Simhasher::isEqual(u64_1, u64_2, 5)<<endl;

	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    return test_similarity();
}
