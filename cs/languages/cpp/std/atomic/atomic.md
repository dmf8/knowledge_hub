# 作用
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

    ```cpp
    template <class T> void atomic_init (volatile atomic<T>* obj, T val) noexcept;
    template <class T> void atomic_init (atomic<T>* obj, T val) noexcept;

    void atomic_init (volatile A* obj, T val) noexcept;
    void atomic_init (A* obj, T val) noexcept;
    ```