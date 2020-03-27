
#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include "ast.hpp"
#include <iostream>
#include <string>
using namespace std;

/*
DECLARATION : TYPE_PART T_FH            {$$=new Declaration($1);}
            | TYPE_PART TERMS_LIST T_FH {$$=new Declaration($1,$2);}
*/
class Declaration : public Node
{
    private:
        NodePtr node1;//TYPE_PART
        NodePtr node2;//TERMS_LIST
    public:
        virtual ~Declaration()
        {}
        Declaration(NodePtr arg):node1(arg),node2(nullptr){}
        Declaration(NodePtr arg1,NodePtr arg2):node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Declaration"<<endl;
            node1->print(dst);
            if(node2)
            {
                node2->print(dst);
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in Declaration"<<endl;
            context.indent_output(dst);
            // context.turn_on_in_declaration_flag();
            // context.local=true;
            node1->translate(dst,context);
            if(node2)
            {
                node2->translate(dst,context);
                dst<<endl;
            }
            else
            {
                dst<<endl;
            }
            // context.local=false;
            // context.shutdown_in_declaration_flag();
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
TYPE_PART : STORE_CLASS               {$$=$1;}
          | STORE_CLASS TYPE_PART     {$$ = new TypePart($1, $2);}
          | REGULAR_TYPE              {$$=$1;}
          | REGULAR_TYPE TYPE_PART    {$$ = new TypePart($1, $2);}
          | QUALIFIER_TYPE            {$$=$1;}
          | QUALIFIER_TYPE TYPE_PART  {$$ = new TypePart($1, $2);}
*/
class TypePart : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~TypePart()
        {}
        TypePart(NodePtr arg):node1(arg),node2(nullptr){}
        TypePart(NodePtr arg1,NodePtr arg2):node1(arg1),node2(arg2){}
        
        virtual void print(std::ostream &dst) const
        {
            dst<<"in TypePart"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not support.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
TERMS_LIST : TERM                     {$$=$1;}
           | TERMS_LIST T_DH TERM      {$$ = new TermList($1, $3);}
*/
class TermList : public Node
{
    private:
        NodePtr node1;//TERMS_LIST
        NodePtr node2;//TERM
    public:
        virtual ~TermList()
        {}
        TermList(NodePtr arg):node1(arg),node2(nullptr){}
        TermList(NodePtr arg1,NodePtr arg2):node1(arg1),node2(arg2){}

        
        virtual void print(std::ostream &dst) const
        {
            dst<<"in TermList"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in TermList"<<endl;
            node1->translate(dst,context);
            dst<<",";
            node2->translate(dst,context);
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
TERM : DECLARATOR                     {$$=new Term($1);}
     | DECLARATOR T_ASSIGN INITIALIZER  {$$=new Term($1,$3,"=");}
*/
class Term : public Node
{
    private:
        NodePtr node1;//DECLARATOR
        NodePtr node2;//INITIALIZER
        string type;
    public:
        virtual ~Term()
        {}
        Term(NodePtr arg):node1(arg),node2(nullptr){}
        Term(NodePtr arg1,NodePtr arg2,string arg3)
            :node1(arg1),node2(arg2),type(arg3){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Term"<<endl;
            node1->print(dst);
            if(node2)
            {
                node2->print(dst);
            }
            dst<<type<<endl;
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in Term"<<endl;
            node1->translate(dst,context);
            if(node2)
            {
                node2->translate(dst,context);
            }

            dst<<type;
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
STORE_CLASS : T_K_TYPEDEF {$$=new StoreClass("typedef");}
            | T_K_EXTERN  {$$=new StoreClass("extern");}  
            | T_K_STATIC  {$$=new StoreClass("static");}
*/
class StoreClass : public Node
{
    private:
        string type;
    public:
        virtual ~StoreClass()
        {}
        StoreClass(string arg):type(arg){}
      
        virtual void print(std::ostream &dst) const
        {
            dst<<"in StoreClass"<<endl;
            dst<<type<<endl;
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not support."); 
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
REGULAR_TYPE : T_K_VOID           {$$=new RegularType("void");}
             | T_K_CHAR           {$$=new RegularType("char");}
             | T_K_SHORT          {$$=new RegularType("short");}
             | T_K_INT            {$$=new RegularType("int");}
             | T_K_LONG           {$$=new RegularType("long");}
             | T_K_FLOAT          {$$=new RegularType("float");}
             | T_K_DOUBLE         {$$=new RegularType("double");}
             | T_K_SIGNED         {$$=new RegularType("signed");}
             | T_K_UNSIGNED       {$$=new RegularType("unsigned");}
             | STRUCT_UNION_TYPE  {$$=$1;}
             | SPECIFIER_ENUM     {$$=$1;}
*/
/*
STRUCT_UNION : T_K_STRUCT {$$=new RegularType("struct");}
             | T_K_UNION  {$$=new RegularType("union");}
*/
class RegularType : public Node
{
    private:
        string type;
    public:
        virtual ~RegularType()
        {}
        RegularType(string arg):type(arg){}
      
        virtual void print(std::ostream &dst) const
        {
            dst<<"in RegularType"<<endl;
            dst<<type<<endl;
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in RegularType"<<endl;
            if(context.return_type)
            {
                dst<<"def ";
            }
            dst<<"";
            // if(context.global)
            // {
            //     dst<<"";
            // }

            // if()
            // if(context.is_inside_function())
            // {
            //     cout<<"local:"<<context.local<<endl;
            // }
            // if(context.get_arglist_flag())
            // {
            //     cout<<"arglist:"<<endl;
            // }
            // else
            //     dst<<"def ";
            
           
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
STRUCT_UNION_TYPE : STRUCT_UNION T_ID T_LDKH STRUCT_UNION_LIST T_RDKH {$$=new StructUnionType($1,$2,$4);}
                  | STRUCT_UNION T_LDKH STRUCT_UNION_LIST T_RDKH      {$$=new StructUnionType($1,$3);}
                  | STRUCT_UNION T_ID                                 {$$=new StructUnionType($1,$2);}
*/
class StructUnionType : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
        string* id;
    public:
        virtual ~StructUnionType()
        {}
        StructUnionType(NodePtr arg1,string* arg2,NodePtr arg3)
            :node1(arg1),id(arg2),node2(arg3){}
        StructUnionType(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2),id(nullptr){}
        StructUnionType(NodePtr arg1,string* arg2)
            :node1(arg1),id(arg2),node2(nullptr){}
        
        virtual void print(std::ostream &dst) const
        {
            dst<<"in StructUnionType"<<endl;
            node1->print(dst);
            if(node2)
            {
                node2->print(dst);
            }

            if(id)
            {
                dst<<*id<<endl;
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
STRUCT_UNION_LIST : STRUCT_UNION_DECLARATION                    {$$=$1;}
                  | STRUCT_UNION_LIST STRUCT_UNION_DECLARATION  {$$=new StructUnionList($1,$2);}
*/
class StructUnionList : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~StructUnionList()
        {}
        StructUnionList(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in StructUnionList"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};




/*

STRUCT_UNION_DECLARATION : LIST_SPEC_QUAL LIST_STRUCT_DECLARATOR T_FH {$$=new StructUnionDeclaration($1,$2);}
*/
class StructUnionDeclaration : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~StructUnionDeclaration()
        {}
        StructUnionDeclaration(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in StructUnionDeclaration"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};




/*

LIST_SPEC_QUAL : REGULAR_TYPE LIST_SPEC_QUAL    {$$=new ListSpecQual($1,$2);}
               | REGULAR_TYPE                   {$$=$1;}
               | QUALIFIER_TYPE LIST_SPEC_QUAL  {$$=new ListSpecQual($1,$2);}
               | QUALIFIER_TYPE                 {$$=$1;}
*/
class ListSpecQual : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListSpecQual()
        {}
        ListSpecQual(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListSpecQual"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};



/*
LIST_STRUCT_DECLARATOR : STRUCT_DECLARATOR                              {$$=$1;}
                       | LIST_STRUCT_DECLARATOR T_DH STRUCT_DECLARATOR  {$$=new ListStructDeclaration($1,$3);}
*/
class ListStructDeclaration : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListStructDeclaration()
        {}
        ListStructDeclaration(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListStructDeclaration"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*

STRUCT_DECLARATOR : DECLARATOR                    {$$=$1;}
                  | T_MH REGULAR_EXPR             {$$=new StructDeclaration($2);}
                  | DECLARATOR T_MH REGULAR_EXPR  {$$=new StructDeclaration($1,$3);}
*/
class StructDeclaration : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~StructDeclaration()
        {}
        
        StructDeclaration(NodePtr arg1)
            :node1(arg1),node2(nullptr){}
        
        StructDeclaration(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in StructDeclaration"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
SPECIFIER_ENUM : T_K_ENUM T_LDKH LIST_ENUMERATOR T_RDKH       {$$=new SpecifierEnum($3);}
               | T_K_ENUM T_ID T_LDKH LIST_ENUMERATOR T_RDKH  {$$=new SpecifierEnum($2,$4);}
               | T_K_ENUM T_ID                                {$$=new SpecifierEnum($2);}
*/
class SpecifierEnum : public Node
{
    private:
        NodePtr node1;
        string * id;
    public:
        virtual ~SpecifierEnum()
        {}
        SpecifierEnum(string* arg1)
            :id(arg1),node1(nullptr){}
        
        SpecifierEnum(NodePtr arg1)
            :node1(arg1),id(nullptr){}
        
        SpecifierEnum(string* arg1,NodePtr arg2)
            :id(arg1),node1(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in SpecifierEnum"<<endl;
            if(node1)
            {
                node1->print(dst);
            }
            if(id)
            {
                dst<<*id<<endl;
            }
            
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
             throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
LIST_ENUMERATOR : ENUMERATOR                        {$$=$1;}
                | LIST_ENUMERATOR T_DH ENUMERATOR   {$$=new ListEnumerator($1,$3);}
*/
class ListEnumerator : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListEnumerator()
        {}
        
        ListEnumerator(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListEnumerator"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
ENUMERATOR : T_ID                       {$$=new Enumerator($1);}
           | T_ID T_ASSIGN REGULAR_EXPR   {$$=new Enumerator($1,$3);}
*/
class Enumerator : public Node
{
    private:
        NodePtr node1;
        string * id;
    public:
        virtual ~Enumerator()
        {}
        Enumerator(string* arg1)
            :id(arg1),node1(nullptr){}
        
      
        Enumerator(string* arg1,NodePtr arg2)
            :id(arg1),node1(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in SpecifierEnum"<<endl;
            if(node1)
            {
                node1->print(dst);
            }
            if(id)
            {
                dst<<*id<<endl;
            }
            
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
QUALIFIER_TYPE : T_K_CONST        {$$=new QualifierType("const");}
               | T_K_VOLATILE     {$$=new QualifierType("valatile");}
*/
class QualifierType : public Node
{
    private:
        string  type;
    public:
        virtual ~QualifierType()
        {}
        QualifierType(string arg1)
            :type(arg1){}
     
        virtual void print(std::ostream &dst) const
        {
            dst<<"in SpecifierEnum"<<endl;
            dst<<type;
            
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
DECLARATOR : POINTER DECLARATOR_DIRECT  {$$=new Declarator($1,$2);}
           | DECLARATOR_DIRECT          {$$=$1;}
*/
class Declarator : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~Declarator()
        {}
        
        Declarator(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Declarator"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not implemented.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
DECLARATOR_DIRECT : T_ID                                              {$$=new DeclaratorDirect($1);}
                  | T_LXKH DECLARATOR T_RXKH                          {$$=new DeclaratorDirect($2,"(d)");}
                  | DECLARATOR_DIRECT T_LZKH REGULAR_EXPR T_RZKH      {$$=new DeclaratorDirect($1,$3,"[]");}
                  | DECLARATOR_DIRECT T_LZKH T_RZKH                   {$$=new DeclaratorDirect($1,"[]");}
                  | DECLARATOR_DIRECT T_LXKH LIST_PARAM_TYPE T_RXKH   {$$=new DeclaratorDirect($1,$3,"(p)");}
                  | DECLARATOR_DIRECT T_LXKH LIST_IDENTIFIER T_RXKH   {$$=new DeclaratorDirect($1,$3,"(l)");}
                  | DECLARATOR_DIRECT T_LXKH T_RXKH                   {$$=new DeclaratorDirect($1,"()");}
*/
class DeclaratorDirect : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
        string * id;
        string type;
    public:
        virtual ~DeclaratorDirect()
        {}
        
        DeclaratorDirect(string* arg1)
            :id(arg1),node1(nullptr),node2(nullptr){}

        DeclaratorDirect(NodePtr arg1,string arg2)
            :node1(arg1),node2(nullptr),id(nullptr),type(arg2){}
        
        DeclaratorDirect(NodePtr arg1,NodePtr arg2,string arg3)
            :node1(arg1),node2(arg2),id(nullptr),type(arg3){}

        virtual void print(std::ostream &dst) const
        {
            dst<<"in DeclaratorDirect"<<endl;
            if(node1)
            {
                node1->print(dst);
            }
            if(node2)
            {
                node2->print(dst);
            }
            if(id)
            {
                dst<<*id<<endl;
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in DeclaratorDirect"<<endl;
            if(id)
            {
                if(*id == "main")
                {
                    context.setMain();
                }
                // if(context.global==true)
                // {
                //     context.globalVar.push_back(*id);
                //     cout<<"----get_declaration_flag"<<endl;
                // }
                // else if(context.local)
                // {
                //     dst<<"";
                // }
                // else
                // {
                //     if(context.is_inside_function()==true)
                //     {
                //         dst<<"";
                //     }
                //     else
                //     {
                        
                //         dst<<*id;
                //     }
               
                // }
                if(context.global)
                {
                    context.globalVar.push_back(*id);
                    dst<<*id;
                }
                if(context.arglist)
                {
                    dst<<*id;
                }
                if(context.return_type)
                {
                    dst<<*id;
                }
                if(context.local)
                {
                    dst<<"";
                }
               
              
            }
            if(node1!=nullptr && node2==nullptr)
            {
                if(type == "[]")
                {
                    throw std::runtime_error("python Not supported.");
                }
                if(type =="()")
                {
                    context.increase_indent();
                    context.shutdown_in_arglist_flag();//! 不在参数列表 关闭
                    node1->translate(dst,context);
                    dst<<"():";

                }
            }

            if(node1 && node2)
            {
                if(type == "[]")
                {
                    throw std::runtime_error("python Not supported.");
                }
                else
                {
                    node1->translate(dst,context);
                    dst<<"(";
                    context.turn_on_in_arglist_flag();
                    node2->translate(dst,context);
                    dst<<"):";
                    context.shutdown_in_arglist_flag();
                }
                
            }
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
POINTER : T_MUL                               {$$=new Pointer();}
        | T_MUL LIST_QUALIFIER_TYPE           {$$=new Pointer($2);}
        | T_MUL POINTER                       {$$=new Pointer($2);}
        | T_MUL LIST_QUALIFIER_TYPE POINTER   {$$=new Pointer($2,$3);}
*/
class Pointer : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~Pointer()
        {}
        Pointer()
        {
            cout<<"*"<<endl;
        }
        Pointer(NodePtr arg1)
            :node1(arg1),node2(nullptr){}
        
        Pointer(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Pointer"<<endl;
            if(node1)
            {
                node1->print(dst);
            }
            if(node2)
            {
                node2->print(dst);
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
LIST_QUALIFIER_TYPE : QUALIFIER_TYPE                      {$$=$1;}  
                    | LIST_QUALIFIER_TYPE QUALIFIER_TYPE  {$$=new ListQualifierType($1,$2);}  
*/
class ListQualifierType : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListQualifierType()
        {}
        
      
        ListQualifierType(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Pointer"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
LIST_PARAM_TYPE : LIST_PARAMETER              {$$=$1;}           
                | LIST_PARAMETER T_DH T_XLH   {$$=new ListParamType($1);}
*/
class ListParamType : public Node
{
    private:
        NodePtr node1;
    public:
        virtual ~ListParamType()
        {}
        
      
        ListParamType(NodePtr arg1)
            :node1(arg1){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListParamType"<<endl;
            node1->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext &context) const
        {
            throw std::runtime_error("python Not supported.");
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
IST_PARAMETER : DECLARATION_PARAMETER                        {$$=$1;}
               | LIST_PARAMETER T_DH DECLARATION_PARAMETER    {$$=new ListParameter($1,$3);}
*/
class ListParameter : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListParameter()
        {}
        
      
        ListParameter(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListParameter"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext &context) const
        {
            // cout<<"in ListParameter"<<endl;
            node1->translate(dst,context);
            dst<<",";
            node2->translate(dst,context);
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
DECLARATION_PARAMETER : TYPE_PART DECLARATOR            {$$=new DeclarationParameter($1,$2);}
                      | TYPE_PART DECLARATOR_ABSTRACT   {$$=new DeclarationParameter($1,$2);}
                      | TYPE_PART                       {$$=$1;}
*/
class DeclarationParameter : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~DeclarationParameter()
        {}
        
      
        DeclarationParameter(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in DeclarationParameter"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in DeclarationParameter"<<endl;
            node1->translate(dst,context);
            node2->translate(dst,context);
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
LIST_IDENTIFIER : T_ID                        {$$=new ListIdentifier($1);}
                | LIST_IDENTIFIER T_DH T_ID   {$$=new ListIdentifier($1,$3);}
*/
class ListIdentifier : public Node
{
    private:
        NodePtr node1;
        string* id;
    public:
        virtual ~ListIdentifier()
        {}
        
        ListIdentifier(string* arg2)
            :node1(nullptr),id(arg2){}
        
        ListIdentifier(NodePtr arg1,string* arg2)
            :node1(arg1),id(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListIdentifier"<<endl;
            if(node1)
            {
                node1->print(dst);
            }
            if(id)
            {
                dst<<*id<<endl;
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in ListIdentifier"<<endl;
            if(node1)
            {
                node1->translate(dst,context);
            }
            if(id)
            {
                dst<<",";
                dst<<*id;
            }
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};




/*
TYPE : LIST_SPEC_QUAL                     {$$=$1;}
     | LIST_SPEC_QUAL DECLARATOR_ABSTRACT {$$=new Type($1,$2);}
*/
class Type : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~Type()
        {}
        
      
        Type(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Type"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in Type"<<endl;
            node1->translate(dst,context);
            node2->translate(dst,context);
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};



/*
DECLARATOR_ABSTRACT : POINTER                             {$$=$1;}
                    | DECLARATOR_DIRECT_ABSTRACT          {$$=$1;}
                    | POINTER DECLARATOR_DIRECT_ABSTRACT  {$$=new DeclarationAbstract($1,$2);}
*/
class DeclarationAbstract : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~DeclarationAbstract()
        {}
        
      
        DeclarationAbstract(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in DeclarationAbstract"<<endl;
            node1->print(dst);
            node2->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            throw std::runtime_error("python Not supported."); 
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
DECLARATOR_DIRECT_ABSTRACT : T_LXKH DECLARATOR_ABSTRACT T_RXKH                          {$$=new DeclarationDirectAbstract($2);}
                           | T_LZKH T_RZKH                                              {$$=new DeclarationDirectAbstract();}
                           | T_LZKH REGULAR_EXPR T_RZKH                                 {$$=new DeclarationDirectAbstract($2);}
                           | DECLARATOR_DIRECT_ABSTRACT T_LZKH T_RZKH                   {$$=new DeclarationDirectAbstract($1);}
                           | DECLARATOR_DIRECT_ABSTRACT T_LZKH REGULAR_EXPR T_RZKH      {$$=new DeclarationDirectAbstract($1,$3);}
                           | T_LXKH T_RXKH                                              {$$=new DeclarationDirectAbstract();}
                           | T_LXKH LIST_PARAM_TYPE T_RXKH                              {$$=new DeclarationDirectAbstract($2);}
                           | DECLARATOR_DIRECT_ABSTRACT T_LXKH T_RXKH                   {$$=new DeclarationDirectAbstract($1);}
                           | DECLARATOR_DIRECT_ABSTRACT T_LXKH LIST_PARAM_TYPE T_RXKH   {$$=new DeclarationDirectAbstract($1,$3);}
*/
class DeclarationDirectAbstract : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
        string type;
    public:
        virtual ~DeclarationDirectAbstract()
        {}
        DeclarationDirectAbstract(string arg)
        {
            type = arg;
        }  

        DeclarationDirectAbstract(NodePtr arg1,string arg2)
            :node1(arg1),node2(nullptr),type(arg2){}


        DeclarationDirectAbstract(NodePtr arg1,NodePtr arg2,string arg3)
            :node1(arg1),node2(arg2),type(arg3){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in DeclarationDirectAbstract"<<endl;
            node1->print(dst);
            if(node2)
            {
                node2->print(dst);
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in DeclarationDirectAbstract"<<endl;
            if(type=="[]" || type == "[r]")
            {
                throw std::runtime_error("Python Not supported.");
            }
            if(node1!=nullptr && node2==nullptr)
            {
                if(type == "(k)")
                {
                    dst<<"(";
                    node1->translate(dst,context);
                    dst<<")";
                }

                if(type == "()")
                {
                    node1->translate(dst,context);
                    dst<<"()";
                }
            }

            if(node1 && node2)
            {
                node1->translate(dst,context);
                dst<<"(";
                node2->translate(dst,context);
                dst<<")";
            }
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};


/*
INITIALIZER : ASSIGN_EXPR                           {$$=$1;}
            | T_LXKH LIST_INITIALIZER T_RXKH        {$$=new Initializer($2);}
            | T_LXKH LIST_INITIALIZER T_DH T_RXKH   {$$=new Initializer($2);}
*/
class Initializer : public Node
{
    private:
        NodePtr node;
        string type;
    public:
        virtual ~Initializer()
        {}
        
      
        Initializer(NodePtr arg1,string arg2)
            :node(arg1),type(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in Initializer"<<endl;
            node->print(dst);
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in Initializer"<<endl;
            if(type == "()")
            {
                dst<<"(";
                node->translate(dst,context);
                dst<<")";
            }
            if(type == "(,)")
            {
                dst<<"(";
                node->translate(dst,context);
                dst<<",";
                dst<<")";
            }
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};

/*
LIST_INITIALIZER : INITIALIZER                        {$$=$1;}
                 | LIST_INITIALIZER T_DH INITIALIZER  {$$=new ListInitializer($1,$3);}
*/
class ListInitializer : public Node
{
    private:
        NodePtr node1;
        NodePtr node2;
    public:
        virtual ~ListInitializer()
        {}
       
        ListInitializer(NodePtr arg1,NodePtr arg2)
            :node1(arg1),node2(arg2){}
            
        virtual void print(std::ostream &dst) const
        {
            dst<<"in ListInitializer"<<endl;
            node1->print(dst);
            if(node2)
            {
                node2->print(dst);
            }
        }
        virtual void translate(std::ostream &dst,TranslateContext&context) const
        {
            // cout<<"in ListInitializer"<<endl;
            node1->print(dst);
            if(node2)
            {
                dst<<",";
                node2->translate(dst,context);
            }
        }
        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const
        { throw std::runtime_error("Not implemented."); }
};



#endif