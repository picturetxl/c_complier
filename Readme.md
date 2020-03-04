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

+ output: :question:

  > 具体是什么 还没有确定



### 1.5 主要工作

+ 写正则表达式



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





### 语法树

+ 终结符terminal
+ 非终结符 non-terminal

![image-20200304151956247](Readme.assets/image-20200304151956247.png)

### 主要工作

+ 编写产生式







## 3. 代码生成阶段 Code generation

