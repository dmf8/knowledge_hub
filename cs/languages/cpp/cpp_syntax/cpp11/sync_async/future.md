# syntax
std::future
```cpp
template <class T>  future;
template <class R&> future<R&>;     // specialization : T is a reference type (R&)
template <> future<void>;   // specialization : T is void
```

# 常用接口
- get
- wait
- wait_for