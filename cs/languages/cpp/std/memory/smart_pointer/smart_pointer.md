# 概述
智能指针包括:
1. [unique_ptr](#unique_ptr)
1. [shared_ptr](#shared_ptr)
1. [weak_ptr](#weak_ptr)

在后期被遗弃的内容:
1. auto_ptr

# 智能指针通用用法
1. 构造
1. 和常规指针一样使用*进行解引用, 使用->调用成员
1. 离开作用域后自动释放资源
1. 手动释放 release
    手动释放智能指针存储的指针, 返回其值, 然后替换为空指针
    ```cpp
    pointer release() noexcept;
    ```

1. 判定是否为空
    ```cpp
    explicit operator bool() const noexcept;
    ```

1. 


# unique_ptr
独占所有权的智能指针
## 特点

## 用法

# shared_ptr
共享所有权的智能指针, 和unique_ptr的区别是, 对资源做引用计数, 当引用计数为0时, 自动释放资源

## 用法
1. 构造 make_shared
    用于构造T并分配空间, 将args传递给T的构造函数, 返回后的引用计数为1
    ```cpp
    template <class T, class... Args>  shared_ptr<T> make_shared (Args&&... args);
    ```

1. 获取引用计数值 use_count

# weak_ptr
弱引用智能指针, 用于打破shared_ptr的循环引用