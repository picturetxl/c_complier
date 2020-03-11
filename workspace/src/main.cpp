#include <iostream>
#include <fstream>


#include "../include/ast.hpp"


int main(int argc,char*argv[])
{

    //c to python
    //./bin/main --translate hello.c -o hello.py
    if (argc!=5)
    {
        fprintf(stderr, "Usage(1):bin/main --translate [source-file.c] -o [dest-file.py]\n");
        fprintf(stderr, "Usage(2):bin/main -S [source-file.c] -o [dest-file.s]\n");
        exit(1);
    }
    std::string in_filename = argv[2];
    std::string out_filename = argv[4];
    std::string mode = argv[1];

    //生成解析树
    const Node* ast = parseAST(argv[2]);

    //open dest file 
    // fstream dest_file;
    // dest_file.open(out_filename);

    //c to python
    if(mode == "--translate")
    {
        ast->translate(std::cout);
    }

    //close file
    // dest_file.close();
    return 0;
}

