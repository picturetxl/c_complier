/*
 * @Author: your name
 * @Date: 2020-03-21 02:53:11
 * @LastEditTime: 2020-03-21 11:59:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /complier/src/main.cpp
 */
#include "ast.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char*argv[])
{
    //! c to python
    //! ./bin/main --translate hello.c -o hello.py
    if (argc!=5)
    {
        fprintf(stderr, "Usage(1):bin/main --translate [source-file.c] -o [dest-file.py]\n");
        fprintf(stderr, "Usage(2):bin/main -S [source-file.c] -o [dest-file.s]\n");
        exit(1);
    }
    std::string in_filename = argv[2];
    std::string out_filename = argv[4];
    std::string mode = argv[1];

    const Node *ast=parseAST(argv[2]);
    
    //! open dest file 
    fstream dest_file;
    dest_file.open(out_filename,ios::out);

    //c to python
    if(mode == "--translate")
    {
        // cout<<"in translate"<<endl;
        TranslateContext context;
        ast->translate(dest_file,context);
        context.outmainfunc(dest_file);
    }

    std::cout<<std::endl;
    //close file
    dest_file.close();
    return 0;
}
