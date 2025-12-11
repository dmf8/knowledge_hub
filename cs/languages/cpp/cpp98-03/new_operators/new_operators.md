# 新增运算符一览
和C语言相比, 新增了下列运算符
- ::
- .*, ->*
- new, delete
- new[], delete[]
- typeid
- dynamic_cast<>()
- static_cast<>()
- reinterpret_cast<>()
- const_cast<>()
- throw
- catch

# ::
用法如下:
1. 指定命名空间
1. 指定类
1. ::前没有内容, 引用全局作用域
    ```cpp
    int a = 0;
    void test()
    {
        int a = 1;
        cout << a << endl; //1
        cout << ::a << endl; //0
    }
    ```