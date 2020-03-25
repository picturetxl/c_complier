
#ifndef translate_context_hpp
#define translate_context_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// translate context 
class TranslateContext
{
private:
    vector<string> globalVar;//global value
    int indent;              //缩进
    bool in_arglist;         //如果在参数列表中,那么类型全部为空
    bool function_inside;    //如果在函数里面,类型也为空,且要考虑全局的变量
    bool main_func_exist;   //Whether the main function exists
    bool is_declareation;   //是不是声明 如果是int x; 这种 直接去掉
public:
    //初始化
    TranslateContext()
    {
        this->in_arglist=false;
        this->indent = 0;
        this->main_func_exist = false;
    }
    //获取是否在参数列表中
    bool get_arglist_flag()
    {
        return in_arglist;
    }
    //在参数列表中
    void turn_on_in_arglist_flag()
    {
        in_arglist= true;
    }
    //不在参数列表中
    void shutdown_in_arglist_flag()
    {
        in_arglist = false;
    } 

    //在函数中
    void turn_on_function_flag()
    {
        function_inside= true;
    }

    //不在函数中
    void shutdown_function_flag()
    {
        function_inside = false;
    } 

    //是否在函数中
    bool is_inside_function()
    {
        return function_inside;
    }

    //获取缩进
    int get_indent()
    {
        return this->indent;
    }

    //存在main函数
    void setMain()
    {
        this->main_func_exist = true;
    }
    void clear_indent()
    {
        this->indent=0;
    }
    //增加缩进
    void increase_indent()
    {
        this->indent++;
    }

    //减少缩进
    void decrease_indent()
    {
        this->indent-- ;
    }
    //输出main函数
    void outmainfunc(std::ostream &dst)
    {
        if(this->main_func_exist)
        {
            dst<<endl;
            dst<<"# Boilerplate"<<endl;
            dst<<"if __name__ == \"__main__\":"<<endl;
            dst<<"\timport sys"<<endl;
            dst<<"\tret=main()"<<endl;
            dst<<"\tsys.exit(ret)"<<endl;
        }
    }

    //输出缩进
    void indent_output(std::ostream &dst)
    {
        for(int i=0;i<this->indent;i++)
        {
            dst<<"\t";
        }
    }

};




#endif