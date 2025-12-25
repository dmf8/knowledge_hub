# 概述
这是一个自旋锁, 本质上是一个bool类型的原子变量, 提供test-and-set和clear方法

# 构造和初始化
## 构造
只能用默认构造, 构造之后是未初始化状态(set或clear不定)

```cpp
atomic_flag() noexcept = default;
atomic_flag (const atomic_flag&T) = delete;
```

## 初始化
固定写法是在构造的同时进行初始化. 如果构造和初始化赋值分两行会报错.

```cpp
std::atomic_flag f = ATOMIC_FLAG_INIT;
```

# 设置
- test_and_set

    尝试设置flag, 并且返回在调用前瞬间的设置状态. 获取成功时返回false(之前没上锁)

    整个读/写操作是原子的(类似于atomic的exchange)

    ```cpp
    bool test_and_set (memory_order sync = memory_order_seq_cst) volatile noexcept;
    bool test_and_set (memory_order sync = memory_order_seq_cst) noexcept;
    ```

- clear

    将自旋锁恢复为false状态

    ```cpp
    void clear (memory_order sync = memory_order_seq_cst) volatile noexcept;
    void clear (memory_order sync = memory_order_seq_cst) noexcept;
    ```