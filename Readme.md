# C compiler

## 目标

+ 将c语言转成python语言
+ 将c语言转成mips语言



## 1. 词法阶段LA

> 利用flex词法解析器进行词法解析

+ flex

  ![image-20200304130107139](Readme.assets/image-20200304130107139.png)

+ 主要工作

  + 编写RE

    ![image-20200304125922726](Readme.assets/image-20200304125922726.png)

  + 

+ 主要数据结构
  + unorder_map<,> 存储tokens和value

### 核心内容

![image-20200304125801611](Readme.assets/image-20200304125801611.png)

### 与语法解析阶段的交互

![image-20200304123704378](Readme.assets/image-20200304123704378.png)

> flex 通过每次call `yylex()` 函数进行**一个**词法单元的匹配,返回一个`token`,`yylval`这个全局变量保存这value属性值



## 2. 语法解析阶段Parsing





## 3. 代码生成阶段 Code generation

