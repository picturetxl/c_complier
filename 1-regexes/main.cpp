//测试
#include "histogram.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


typedef std::unordered_map<std::string,unsigned> histogram_type;
TokenValue yylval;//要声明

int main(int argc,char*argv[])
{
    // cout<<argc<<endl;//2
    // cout<<argv[0]<<endl;//./histogram
    // cout<<argv[1]<<endl;//hello.cpp
    //要求输入一个源文件进行测试
    if(argc==1){
        cerr<<"need two arg"<<endl;
        cout<<"main hello.c"<<endl;
        exit(-1);
    }
    //读取源文件
    yyin = fopen(argv[1],"r");
    if(!yyin)
    {
        cout<<"yyin is null"<<endl;
    }
    histogram_type histogram;
    //词法分析
    //问题:yylval 存在问题 yylval.wordValue 好像是空指针 没有分配内存 但不知道在哪里分配内存
    while (true)
    {
        TokenType type=(TokenType)yylex();
        if (type == Space)
        {
            continue;
        }
        else if(type == Int)
        {
            string num = to_string(yylval.numberValue);
            histogram.insert({num,Int});
        }
        else if(type == Main)
        {
            histogram.insert({*yylval.wordValue,Main});
        }
        else if(type == Void)
        {
            histogram.insert({*yylval.wordValue,Void});
        }
        else if(type == Return)
        {
            histogram.insert({*yylval.wordValue,Return});
            break;
        }
        else if(type == If)
        {
            cout<<yylval.wordValue<<endl;
            histogram.insert({*yylval.wordValue,If});
        }
        else if(type == Id)
        {
            histogram.insert({*yylval.wordValue,Id});
        }
        else if(type == None)
        {
            cout<<"nothing"<<endl;
            //do nothing
            break;
        }
        
        
    }//end of while
    
    
    // 打印出词法分析之后的tokens 
    for(auto p:histogram)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}


