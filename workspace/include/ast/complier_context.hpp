
#ifndef complier_context_hpp
#define complier_context_hpp

#include <map>
#include <vector>
#include <fstream>
#include <string>


using namespace std;



class ComplierContext{

private:



public:
    map<string,string> registers;//32个寄存器 (name,value)



    ComplierContext()
    {
        registers.insert({"$zero",""});

        registers.insert({"$at",""});

        //! 函数返回值
        registers.insert({"$v0",""});
        registers.insert({"$v1",""});

        //! 函数参数值
        registers.insert({"$a0",""});
        registers.insert({"$a1",""});
        registers.insert({"$a2",""});
        registers.insert({"$a3",""});
       
        //! temp值
        registers.insert({"$t0",""});
        registers.insert({"$t1",""});
        registers.insert({"$t2",""});
        registers.insert({"$t3",""});
        registers.insert({"$t4",""});
        registers.insert({"$t5",""});
        registers.insert({"$t6",""});
        registers.insert({"$t7",""});
        
        //! saved 
        registers.insert({"$s0",""});
        registers.insert({"$s1",""});
        registers.insert({"$s2",""});
        registers.insert({"$s3",""});
        registers.insert({"$s4",""});
        registers.insert({"$s5",""});
        registers.insert({"$s6",""});
        registers.insert({"$s7",""});

        //! temp
        registers.insert({"$t8",""});
        registers.insert({"$t9",""});
        
        //! kernal: 中断处理
        registers.insert({"$k0",""});
        registers.insert({"$k1",""});

        //! global pointer : static or extern variables
        registers.insert({"$gp",""});
        //! stack pointer
        registers.insert({"$sp",""});
        //! frame pointer
        registers.insert({"$fp",""});
        //! return address for subroutine
        registers.insert({"$ra",""});

    }

    




};




#endif