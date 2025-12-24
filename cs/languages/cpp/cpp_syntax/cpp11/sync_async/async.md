# syntax
- fn

    需要异步调用的函数

- args

    函数参数

- policy

    1. launch::async

        异步调用, 使用一个新线程来调用fn
        
        类似构造了一个调用fn并以args作为参数的thread对象

    1. launch::deferred

        推迟调用, 当返回的future对象的shared state被访问(通过wait或get)时才调用

    1. launch::async|launch::deferred

        这是自动的模式, 取决于系统或库的实现

- return type

    返回一个future对象

    如果在future析构时任务没有完成, 析构位置会阻塞等待任务完成

```cpp
template <class Fn, class... Args>  
future<typename result_of<Fn(Args...)>::type> async (Fn&& fn, Args&&... args);

template <class Fn, class... Args>  
future<typename result_of<Fn(Args...)>::type> async (launch policy, Fn&& fn, Args&&... args);
```

# 概述
- 作用

    调用函数fn, 并且无需等待fn执行完成即返回

# 用法
1. 创建fn
1. 调用async, 并接收其返回的future

    async返回的future是一个临时对象, 如果不接收future, 这个临时对象会立即析构. 如果fn没有完成, 会造成程序阻塞

1. 通过future::get获取fn的返回值