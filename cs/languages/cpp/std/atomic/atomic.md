# 概述
用于封装一个值, 使得对该值的访问不会引发数据竞争, 并且可以在多线程之间做内存同步

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
这是一组枚举值, 用于原子操作的某些函数, 指定其他线程的操作应当如何同步

所有的原子操作在多线程使用时都会有序排列, 也就是说在某项原子操作进行时, 之前的原子操作都是完成的状态. 这样就可以避免数据竞争. 

但多线程仍然可以操作内存上原子对象之外的其他值, 这些仍然可能产生竞争. 内存序就是用于定义这些可能的竞争应该如何在多线程之间同步

- memory_order_relaxed
    - 该操作会在某些时刻发生. 这是最宽松的内存序, 对内存的访问不做任何保证

- memory_order_consume
    - 应用于读操作
    - 

- memory_order_acquire
- memory_order_release
- memory_order_acq_rel
- memory_order_seq_cst