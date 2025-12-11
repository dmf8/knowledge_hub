# 新增关键字
有很多, 列举一些主要的
## namespace
用于定义命名空间, 末尾不需要加分号
```cpp
namespace test_namespace
{
} 
```

命名空间有如下特点:
- 命名空间内可以有这些内容
    - 函数
    - 变量
    - 结构体/类
    - 枚举类型
- 命名空间必须定义在全局作用域下
- 命名空间可以嵌套
- 命名空间是开放的, 可以随时打开并向内部添加内容

    也可以理解成命名空间是不连续的, 分散在代码的多个位置
- 存在匿名命名空间, 有如下特点:
    1. 定义命名空间时没有名字
    1. 作用域为本文件, 其他文件无法引用, 类似static
    1. 使用时不需要加命名空间限定(也无法添加), 注意和全局命名空间的区别
- 存在全局命名空间

    如果一个对象没有定义在命名空间中, 则其位于全局命名空间, 可以用::<标识符>的方式来引用

- 命名空间可以起别名
    ```cpp
    namespace <new_name> = <old_name>;
    ```



相关概念
- 限定名qualified和非限定名unqualified

    限定名有两类: 
    1. cv-qualified, 指用const/volatile限定的标识符
    1. scope-qualified, 指用作用域限定的标识符

    除此之外, 都是非限定名

## using
作用: 
1. 指定范围限定名的别名

    ```cpp
    using std::cout;
    ```
    
    如此使用之后, 就可以在代码中直接使用cout, 不需要写成std::cout了. 
    但如果在全局命名空间中也有cout, 直接写cout就引用不到了, 需要写成::cout

1. 引入命名空间

    ```cpp
    using namespace std;
    ```

1. 指定类别名

    ```cpp
    using <new_name> = <old_class_name>;
    ```

## volatile
常和const相提并论
