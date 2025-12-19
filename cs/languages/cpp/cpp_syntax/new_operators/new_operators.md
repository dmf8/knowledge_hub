# 新增运算符一览
和C语言相比, 新增了一些运算符. 主要的列举如下
- ::
- .*, ->*
- new, delete
- new[], delete[]
- typeid
- dynamic_cast<>()
- static_cast<>()
- reinterpret_cast<>()
- const_cast<>()

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

# new/delete
- new

    相比malloc, 整合了堆空间分配/分配结果判断/初始化等操作

    1. 分配单个对象

        推荐的调用方式
        ```cpp
        Class* p = new Class;
        Class* p = new Class{};
        Class* p2 = new Class{1};
        Class* p3 = new Class{*p};
        int *p4 = new int{2};
        ```

    1. 分配数组(不推荐直接调用)

        c++11之前只能用于默认构造函数, 之后可以使用初始化列表进行初始化

        可以用于分配多维数组, 需要用delete[]销毁
        ```cpp
        int *p_arr = new int[5]{1, 2, 3, 4}; // 未给出初始化值的尾部元素的初始值为0
        for (int i = 0; i < 5; ++i)
            cout << p_arr[i] << endl;
        delete[] p_arr;
        ```

        推荐的方式是使用智能指针
        ```cpp
        vector<unique_ptr<int>> vec;
        vec.push_back(make_unique<int>(60));
        for (int i = 0; i < vec.size(); ++i)
            cout << *vec[i] << endl;
        ```

- delete