# C compiler





## 目标

+ 将c语言转成python语言
+ 将c语言转成mips语言



## 1. 词法阶段LA

> 利用flex词法解析器进行词法解析

### 1.1 工具

1. flex
2. re

#### 1.1.1 flex

+ flex

+ https://www.ibm.com/developerworks/cn/linux/sdk/lex/ 

  ![image-20200304130107139](Readme.assets/image-20200304130107139.png)



#### 1.1.2. Regular Expressions



![image-20200304125922726](Readme.assets/image-20200304125922726.png)



### 1.2 核心内容

+ Thompson's algorithem
+ Subset construction
+ Brzozowski algebraic method

![image-20200304125801611](Readme.assets/image-20200304125801611.png)

### 1.3 与语法解析阶段的交互

![image-20200304123704378](Readme.assets/image-20200304123704378.png)

> flex 通过每次call `yylex()` 函数进行**一个**词法单元的匹配,返回一个`token`,`yylval`这个全局变量保存这value属性值,`yytext`保存了匹配的词



### 1.4 input ＆ output

+ input: 源程序

+ output: :question: :ballot_box_with_check:

  > 具体是什么 还没有确定
  >
  > 解决: token<class,string>,eg:<Id,"foo">,<Op,"=">



### 1.5 主要工作

+ 写正则表达式



##### 开始

> 使用正则表达式测试工具编写RE 
>
>  https://www.sojson.com/regex/ 

##### c语言-class type

1. 标识符 `[_a-zA-Z][_a-zA-Z0-9]*`
2. 关键字 
3. 括号
4. 操作符
   1. 计算
      1. `+` 
      2. `-`
      3. `*`
      4. `/`
      5. `%`
      6. `++`
      7. `--`
   2. 比较
      1. `==`
      2. `>=`
      3. `<=`
      4. `>`
      5. `<`
   3. 连带
      1. `+=`
      2. `-=`
      3. `/=`
      4. `*=`
5. 注释 `/\*.*\*/`
6. 整数 `[-]?[1-9][0-9]*`
   1. 带后缀的 `[-]?[1-9][0-9]*[lLuU]*`
7. 浮点数 `[-]?[1-9]+[0-9]*\.[0-9]+`
   1. 带后缀的 `[-]?[1-9]+[0-9]*\.[0-9]+[f]?`
8. 字符 `['][.]+[']`
9. 字符串字面量 `".*"`
10. 按位操作
    1. `|`
    2. `&`
    3. `^`
    4. `~`
    5. `<<`
    6. `>>`
11. 特殊字符
    1. `->`
    2. `?`
    3. `;`
    4. `.`
    5. `,`
    6. `:`

> **表达式的产生式的由来**

![image-20200325131221977](Readme.assets/image-20200325131221977.png)







#### 1.6 工作流

##### 匹配阶段

```mermaid
graph LR
	1(正则匹配) -.-> 2(将匹配到的字符串给到yytext)
	2 -.-> 3(将yytext的值给到yylval)
	3 -.-> 4(返回匹配到的类型)
	style 1 fill:white,stroke:black,stroke-width:2px
	style 2 fill:white,stroke:black,stroke-width:2px
	style 3 fill:white,stroke:black,stroke-width:2px
	style 4 fill:white,stroke:black,stroke-width:2px
```

##### 处理阶段

```mermaid
graph LR
	1(yylex返回的类型) -.-> 2(判断是哪类)
	2 -.-> 3(存储)
	style 1 fill:white,stroke:black,stroke-width:2px
	style 2 fill:white,stroke:black,stroke-width:2px
	style 3 fill:white,stroke:black,stroke-width:2px
```



![image-20200304161415618](Readme.assets/image-20200304161415618.png)

## 2. 语法解析阶段Parsing

### 工具

#### Yacc

+  https://www.ibm.com/developerworks/cn/linux/sdk/lex/ 



### 语法树

+ 终结符terminal
+ 非终结符 non-terminal

![image-20200304151956247](Readme.assets/image-20200304151956247.png)

### 主要工作

+ 编写产生式







## 3. 代码生成阶段 Code generation









## MIPS



> mips 主要被分成五个部分:
>
> 1. Load and Store
> 2. ALU
> 3. Jump and Branch
> 4. Miscellaneous
> 5. Coprocessor



### 寄存器Register

> 函数中的临时变量s和t 
>
> 

![image-20200326093208402](Readme.assets/image-20200326093208402.png)



![image-20200326093230174](Readme.assets/image-20200326093230174.png)



### Load and Store



![image-20200326092436959](Readme.assets/image-20200326092436959.png)



![image-20200326092533308](Readme.assets/image-20200326092533308.png)



![image-20200326092613008](Readme.assets/image-20200326092613008.png)



![image-20200326092623539](Readme.assets/image-20200326092623539.png)



![image-20200326092628653](Readme.assets/image-20200326092628653.png)











### ALU



![image-20200326092646877](Readme.assets/image-20200326092646877.png)



![image-20200326092654466](Readme.assets/image-20200326092654466.png)





![image-20200326092703307](Readme.assets/image-20200326092703307.png)





![image-20200326092711898](Readme.assets/image-20200326092711898.png)





### Jump and Branch



![image-20200326092741849](Readme.assets/image-20200326092741849.png)



![image-20200326092746882](Readme.assets/image-20200326092746882.png)



![image-20200326092751456](Readme.assets/image-20200326092751456.png)



![image-20200326092759262](Readme.assets/image-20200326092759262.png)







### Miscellaneous

![image-20200326092812612](Readme.assets/image-20200326092812612.png)





![image-20200326092817995](Readme.assets/image-20200326092817995.png)





![image-20200326092824530](Readme.assets/image-20200326092824530.png)





![image-20200326092832871](Readme.assets/image-20200326092832871.png)



![image-20200326092841411](Readme.assets/image-20200326092841411.png)





![image-20200326092848837](Readme.assets/image-20200326092848837.png)



![image-20200326092855089](Readme.assets/image-20200326092855089.png)





### Coprocessor

