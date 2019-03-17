#include<stdio.h>
struct test1
{
public:
    int a;
};

class test2
{
public:
    void f1(test1 *self)
    {
        printf("%d\n",(*self).a);
    }
    void f2(test1 *self)
    {
        (*self).a=2;
        f1(self);
    }

};



int main(void)
{
    test1 t1;
    test2 t2;
    t1.a=1;
    t2.f2(&t1);
    return 0;
}




/*
可以拆分成一个变量集合（结构）和一个函数集合 共用了一个名字。

调用变量集合的成员，必须使用点。
调用函数集合的成员，必须使用点。

调用函数集合的成员，点的使用还起到了传递参数的作用。

程序编译时从头到脚进行编译的，编译的结果和源代码基本上从上下关系来讲是基本对应的。
程序执行是从中间开始的（main函数），实际上是CPU也是从这个程序的第一行开始执行的，但是前面的启动代码使得CPU跳转到main函数开始执行。

CPU执行代码过程中，变量集合这段代码会被反复执行，进而创建多个变量集合。
CPU执行代码过程中，函数集合这段代码会被反复执行。




变量集合的成员 和 变量集合名字具有相同的scope。
函数集合的成员 和 函数集合名字具有相同的scope.

两处使用::的区别：
    1、void test::func(void) : 
        1、表明func是函数集合test的一部分
        2、或者可以理解为func的定义本来应该写到test{这里}，但是为了配合链接机制，而写到了外面。
    2、void test::func(void) {::func();}



当你明白如何拆分之后，你就会发现这里面的scope问题只有三个：
1、必须要把一个集合的成员函数写到外面的时候，怎么表明这个函数属于这个集合，或者说相当于写到里面。
2、任何一个位置，想要使用全局的名字时候应该怎么办？
3、集合成员和集合具有相同的scope。
*/