# 概述
智能指针包括:
1. [unique_ptr](#unique_ptr)
1. [shared_ptr](#shared_ptr)
1. [weak_ptr](#weak_ptr)

在后期被遗弃的内容:
1. auto_ptr

# 使用场景
1. 简化内存释放, 防止悬空指针/双重释放等
1. 明确所有权, 谁拥有资源谁释放
1. 可以自定义deleter管理文件/socket/互斥锁等非内存资源
1. pimpl

# 智能指针通用
1. 构造
1. 和常规指针一样使用*进行解引用, 使用->调用成员
1. 离开作用域后自动释放资源
1. 判定是否为空
    ```cpp
    explicit operator bool() const noexcept;
    ```

    调用方法:
    1. 作为判断条件隐式调用
    1. 使用`p.operator bool()`调用



# unique_ptr
独占所有权的智能指针
## 特点

## 用法
1. 释放指针 release
    释放并返回智能指针存储的指针, 然后替换为空指针. 不会销毁管理的指针
    ```cpp
    pointer release() noexcept;
    ```

1. 释放空间并重新赋值 reset
    将智能指针内部管理的指针delete, 然后重新设置为p, 默认p为空指针
    ```cpp
    void reset (pointer p = pointer()) noexcept;
    ```

# shared_ptr
共享所有权的智能指针, 和unique_ptr的区别是, 对资源做引用计数, 当引用计数为0时, 自动释放资源

## 用法
1. 构造 make_shared
    用于构造T并分配空间, 将args传递给T的构造函数, 返回后的引用计数为1
    ```cpp
    template <class T, class... Args>  shared_ptr<T> make_shared (Args&&... args);
    ```

1. 获取引用计数值 use_count

1. 释放空间并重新赋值 reset
    将智能指针内部管理的指针delete, 然后重新设置为p, p在此之前不能由其他智能指针管理. 设置后的引用计数为1

    reset之后, use_count的值可能不准确, 因为将某一个shared_ptr进行reset时, 同时可能有其他相同对象的shared_ptr存在
    ```cpp
    void reset() noexcept; //只析构
    template <class U> void reset (U* p); //U*应当可以隐式转换为T*
    template <class U, class D> void reset (U* p, D del);
    template <class U, class D, class Alloc> void reset (U* p, D del, Alloc alloc);
    ```

# weak_ptr
弱引用智能指针, 用于打破shared_ptr的循环引用