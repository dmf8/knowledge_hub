# 作用
构造一个闭包, 这是一个能够捕获作用域内变量的未命名函数对象

# 语法
- 完整的lambda表达式格式如下
    ```cpp
    [capture](args) mutable throw -> <return type>
    {
        <body>
    }
    ```

- 各部分解释
    1. [capture列表](#capture)
    1. [args函数参数(optional)](#args)
    1. [mutable规范(optional)](#mutable)
    1. [异常规范](#throw)
    1. [返回类型](#return-type)
    1. [lambda体](#body)

## capture
定义lambda如何捕获外部变量, 有以下常见写法
- []
    
    不捕获任何变量
- [=]

    值捕获所有外部变量
- [&]

    引用捕获所有外部变量
- [x, &y, &z]

    值捕获x, 引用捕获y, z
- [=, &y]

    默认值捕获, 除了y按引用捕获
- [&, x]

    默认引用捕获, 除了x按值捕获
- [this]

    捕获this指针

## args
和普通函数的参数列表相同

如果要省略(), 需要有以下条件
- 无参数
- 无mutable
- 无return type

## mutable
只有当捕获列表是值捕获时才有意义([=]或具体值[x])

作用是取消默认的const修饰, 使捕获的值副本可以被修改. 默认的值捕获变量是const的, 在这种情况下修改是会报错的.

## return type
显式指定返回类型

省略时可以由编译器自动根据body推导返回类型. 但如果body有多个return语句, 或者返回类型复杂时, 建议显式指定

## body
和普通函数的函数体相同

## throw
异常规范, 和普通函数的throw后缀相同

这个用法在C++11中已经不推荐使用了, 在C++17之后被彻底弃用.