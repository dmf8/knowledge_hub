# 概述
## 句法
这是一个模板类, 其对象用于管理一个mutex对象, 保持mutex锁定
```c++
template <class Mutex> 
class lock_guard;
```

## 作用
构造时, mutex对象会被调用线程锁定; 析构时, 将mutex解锁. 
lock_guard并不管理mutex本身的生命周期. mutex的生命周期至少需要维持到lock_gurad析构之后. 

## 模板类型
需要是一个basic lockable类型, 比如std::mutex

# 应用场景
1. 锁的上下文自动生命周期管理
    在函数栈上创建lock_guard对象, 就可以在函数调用完成时自动释放锁, 在异常抛出时也会自动释放, 实现RAII的控制逻辑

# 参考资料
https://cplusplus.com/reference/mutex/lock_guard/

