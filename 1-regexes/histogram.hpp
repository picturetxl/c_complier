#ifndef histogram_hpp
#define histogram_hpp

#include <string>

// tokens <具体的值,类别>
// tokens <value,type> 
enum TokenType{
    Space = 0,      //空白字符
    Int = 1,        //int 关键字
    Main = 2,       //main 关键字
    Void = 3,       //void 关键字
    Return = 4,     //return 关键字
    If = 5,         //if 关键字
    Id = 6,         //标识符
    None
};

//标识符string 或者 具体的数double
union TokenValue{
    double numberValue;
    std::string *wordValue;
};


extern FILE* yyin;//如果不指定,那么flex默认从标准输入读
extern TokenValue yylval;//全局的变量
extern int yylex();



#endif
