# 概述
用于封装一个值, 使得对该值的访问不会引发数据竞争

搭配内存序(内存屏障)可以在多线程之间实现内存同步

# syntax
一个atomic对象包含其原始的类型为T的数据
```cpp
template <class T>
struct atomic;
```

# 构造和初始化
## 构造
```cpp
atomic() noexcept = default; //默认构造, 此时atomic为未初始化状态, 需要后续用atomic_init进行初始化
constexpr atomic(T val) noexcept;
atomic(const atomic&) = delete; //atomic不可以做拷贝/搬移构造
```
## 初始化
- atomic_init

    用于将atomic对象obj的值初始化为val. 对已经初始化的atomic对象会发生未定义行为.

    如果atomic对象未初始化, 内部的值会是随机值.

    ```cpp
    template <class T> void atomic_init (volatile atomic<T>* obj, T val) noexcept;
    template <class T> void atomic_init (atomic<T>* obj, T val) noexcept;

    void atomic_init (volatile A* obj, T val) noexcept;
    void atomic_init (A* obj, T val) noexcept;
    ```

# 数据操作
- exchange

    用于原子交换atomic对象的值, 返回旧值

    ```cpp
    T exchange (T val, memory_order sync = memory_order_seq_cst) volatile noexcept;
    T exchange (T val, memory_order sync = memory_order_seq_cst) noexcept;
    ```

# memory_order内存序
## 原子变量内存序
这是一组枚举值, 用于原子操作的某些函数, 指定其他线程的操作应当如何同步. 同一个原子变量的内存序之间存在某种同步约束

所有的原子操作在多线程使用时都会有序排列, 也就是说在某项原子操作进行时, 之前的原子操作都是完成的状态. 这样就可以避免数据竞争. 

但多线程仍然可以操作内存上原子对象之外的其他值, 这些仍然可能产生竞争. 内存序就是用于定义这些可能的竞争应该如何在多线程之间同步

- memory_order_relaxed
    - 该操作会在某些时刻发生. 这是最宽松的内存序, 对内存的访问不做任何保证
    - 只保证当前操作的原子性, 不考虑线程间同步, 其他线程可能读到新值, 也可能读到旧值

- memory_order_consume
    - 后续可能会被acquire替代, 目前在很多编译器上两者就是等价的

- memory_order_acquire
    - 应用于读操作, 对读取施加acquire语义(相当于在之后加入了一个读屏障)
    - 本线程内存序
        - 之后的所有读操作, 不能重排到acquire之前
        - 之前的所有写操作, 不能重排到acquire之后
    - 其他线程内存序
        - 只有使用acquire读, 才能保证对匹配(相同原子变量称为匹配)的release操作之前的所有写入可见

- memory_order_release
    - 应用于写操作, 对写入施加release语义(相当于在之前加入了一个写屏障)
    - 本线程内存序
        - 所有在release之前的写操作不能重排到release之后(不能越过屏障, 包括原子变量之外的其他内存写)
        - 所有在release之后的读操作不能重排到release之前
    - 其他线程内存序
        - 所有匹配的acquire操作, 在读取到这个release的值时, 之前的所有内存都是可见的(能保证屏障之前的变量不是旧值)

- memory_order_acq_rel
    - 应用于读写操作
    - acquire和release的组合, 相当于同时在之后插入了读屏障, 以及在之前插入了写屏障

- memory_order_seq_cst
    - sequentially consistent方式
    - 这是最严格的内存序, 所有可能对其他线程产生visible side effect的操作都会更早发生

## 内存序分类
1. 顺序一致模型
    - seq_cst
1. acquire-release模型
    - acquire
    - consume
    - release
    - acq_rel
1. relax模型
    - relax

## 背景
多线程程序的运行结果是多个线程交织执行的结果. 在某个特定线程内, 由于程序优化, 编译器也会有可能对指令重新排序, 并且CPU可能会乱序执行. 没有约束的指令重排有可能对运行结果产生影响, 这时候就需要作出一定的约束, 也就是定义内存模型.