
# 基于字的中文文本相似度计算
这里基于字的文本相似度计算实现了Jaccard相似度计算和余弦定理相似度计算

#参考页面
（1）http://blog.csdn.net/inrgihc/article/details/52739959
（2）http://blog.csdn.net/inrgihc/article/details/52739935

#编译环境
操作系统：linux
C++版本：gcc/g++ >=4.4
Java版本：JDK >=1.6

#C++版本编译过程
（1）Jacard 算法相似度计算
$cd JaccardSimilarity
$cd cplusplus
$make all
$bin/debug/textsimilarity

(2)余弦定理算法相似度计算
$cd CosineSimilarity
$cd cplusplus
$make all
$bin/debug/textsimilarity

#Java版本编译过程
（1）Jacard 算法相似度计算
$cd JaccardSimilarity
$cd java
$make build
$make run

(2)余弦定理算法相似度计算
$cd CosineSimilarity
$cd java
$make build
$make run

