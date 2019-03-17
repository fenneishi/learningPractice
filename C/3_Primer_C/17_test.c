#include<stdio.h>

#define ds 14;
#define ds 14;

static int a=14;
static int a=14;

struct a{
    int a;
};

// struct a{
//     int a;
// };

extern void f(void);
extern void f(void);

void ff(int);
void ff(int);

int b=4;
int b;

typedef int I;
typedef int I;

inline static void fff(void);
inline static void fff(void)
{
    printf("hhhh\n");
}

typedef struct kk ker;

struct kk
{
    int lll;
};

int main(void)
{
    struct kk aaaa;
    ker hhh;
    printf("a  =%d\n",a);
    fff();
    return 0;
}






/*
编译器之所以让程序员在函数外面可以重复定义，重复声明，重复函数原型，是为了方便合作
因为有可能通过include引进别人同名定义，声明，原型，你限定的太死，就会导致很多代码不可用。
另外，可能也是为了兼容过去的标准，例如本来不带extern的函数原型或者是函数外部变量(就是定义了）不应该这样子，但是可能过去的哥们就是这么搞的

但是二义性不行
1、为struct带有body所以不行，因为编译器无法确定你不同的结构的body是否一样，因为它只看结构的外面，只能比较外面。
2、同理函数的定义重复不行。
3、同理赋了初值的变量不行。
2、名字相同，类型不同也不行，例如不能一个static 一个不是static


引用式声明应该分为，外部引用（加extern），内部引用，函数和变量都应该如此。
好像感觉两者的界限有时候有没有那么清晰了。


scope 应该有三个维度：

1、代码区域（大括号、文件级别，程序级别）
2、讨论时期（预编译期、编译期、链接期）
3、名字种类（函数名、类型名、结构名、变量名）

代码分成两部分，创建工具语句和代码逻辑语句：
创建工具语句：创建变量、函数、类型
逻辑代码语句：存在于函数中

另一个角度，也可分为两部分：
写给预编译器的：#开头的
写给编译器（包含linker）的：各种引用式声明、定义结构，定义新的数据类型
写给CPU的：出过以上。

区分三个概念：
1、引用式声明：只起到给编译器提供信息的作用，是写给编译器的，不会被翻译成真正的可执行代码
2、定义式声明：只起到给创建物种的作用，有些最终会被翻译成可执行代码（例如函数），有些不会（例如定义变量是写给编译器的）
3、一体化声明：同时起到两种作用。

程序级别变量：必须两种分开写，不同统一用声明替代两者。
文件级别变量：必须用一种声明替代两者。（其实是只有一种形式）
局部变量：必须用一种声明替代两者。（其实是只有一种形式）
函数：必须两种分开写，不同统一用声明替代两者。
结构（肯定是文件级别）：必须用一种声明替代两者。（其实是只有一种形式）
类型（肯定是文件级别）：必须用一种声明替代两者。（其实是只有一种形式）


在头文件中：
程序级别变量：必须写，且写的是引用式声明，起的作用是连接（别人的代码里创建窟窿，然后链接时候再根据定义式声明补窟窿）
文件级别变量：如果要写，只能写一体化声明，起的作用相当于copy代码。
局部变量：不能写
函数：必须写，且写的是引用式声明，起的作用是连接（别人的代码里创建窟窿，然后链接时候再根据定义式声明补窟窿）
结构（肯定是文件级别）：如果要写，只能写一体化声明，起的作用相当于copy代码。
类型（肯定是文件级别）：如果要写，只能写一体化声明，起的作用相当于copy代码。

这五种工具，都会有名字，名字保存的时期是不同的：
程序级别变量：保存到linker时期
文件级别变量：linker之前就会消亡
局部变量：linker之前就会消亡
函数：保存到linker时期
结构：linker之前就会消亡
类型：linker之前就会消亡

所谓的作用域级别：
程序级别变量：程序级别
文件级别变量：文件级别
局部变量：大括号级别
函数：
结构：linker之前就会消亡
类型：linker之前就会消亡


函数内外之分：
函数之外：
    1、不会存在目标代码（最终会被翻译成可执行程序的代码）
    2、所有的代码都是写给编译器的，是给编译器提供信息的。创建变量，其实也不过是在编译器的小本本上多一行。
函数之内：
    1、大部分都是目标代码（最终会被翻译成可执行程序的代码）
    2、部分代码还是写给编译器的。

两个世界：
经过上面这么多，我发现了，必须分成两个世界去研究，一个是函数内部，另一个是函数外部
函数内外是两套体系，两种截然不同的情况境地，两种世界观，两套逻辑。
尽管一个源码中函数有很多，但是各个函数内部的语法逻辑是一样，所以可以当成一个体系。
函数内部：强调是完成一个明确的任务，强调的是逻辑功能，会有少部分编译指令，但是大部分都是程序指令。
函数外部：强调是生态，是分工合作，是组织结构，C++中更加复杂，会出现更复杂的元素组织合作方式。
同时考虑好衔接部分就好：例如全局变量的隐藏等。
总之，是两套逻辑体系，你要分别取研究。


不能拆分成引用式声明和定义式声明的情况：编译单元编译时，必须完整的知道素材的全部内容
1、结构：必须要知道结构的body，才能在函数中准确的定义变量。
2、类型：同理
3、内联函数：必须准确的知道，才能在调用处，完整的替换代码。


函数外部研究：
全局变量：
    1、static修饰：可拆分
    2、无static的：可拆分
函数：
    1、static修饰：可拆分
    2、无static的：可拆分
内联函数：
    1、static修饰：可拆分
    2、无static的：可拆分
结构：可拆分
类型：不可拆分


关键是：用
用的地方不同：
    1、一个本文件内部用
    2、另一个是其他文件用
用的方式不同：
    1、调用：函数和变量：调用地方只需要知道名字和外形（调用检查），不需要知道body
    2、替换：内联函数、新的结构、新的类型：替换地方需要知道名字和body（包含外形了）
再来个static一修饰。

头文件的内容：你的源码中创建的工具，由于别人可能用得着，所以你得把这这些工具使用时候必需的信息放到头文件中
函数和变量：使用地方需要知道名字和外形（调用检查）就够了
内联函数、新的结构、新的类型：使用地方需要知道名字和body（包含外形了）


static起到了一种减小影响力的作用,本质上也是为了方便合作。




*/




