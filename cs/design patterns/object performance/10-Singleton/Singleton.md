# 动机
- 在软件系统中, 经常有这样一些特殊的类, 必须保证它们在系统中只存在一个实例, 才能确保它们的逻辑正确性, 以及良好的效率.
- 如何绕过常规的构造器, 提供一种机制来保证一个类只有一个实例? 这应该是类设计者的责任, 而不是使用者的责任.

# 代码案例
## 要点
- 必须私有化构造函数和拷贝构造函数
- 构造时机可以有多种选择, 在程序初始化时([eager](singleton_eager.cpp)), 或第一次调用时([lazy](singleton_lazy.cpp))

## 懒汉模式的线程安全问题
### 问题
当多线程同时首次调用getInstance函数, 就有可能发生两次初始化

### 解决方式
- 使用eager模式, 会略微牺牲内存
- 初始化加锁
    在每次调用getInstance时都上锁, 也就是每次判断是否存在实例也会上锁
    加锁可以解决问题, 但高并发时会有性能影响

- 双检查锁
    1. 先判断实例是否存在
    1. 在不存在的情况下才上锁, 构造单例
    1. 在上锁后仍然需要判断(双检查), 防止极端情况两个线程在首次判断时都没找到实例, 然后都进入单例构造过程

    双检查锁可能会由于指令reorder而出现问题, 可以阻止编译器对相关代码重排以解决

# 定义
保证一个类仅有一个实例, 并提供一个该实例的全局访问点. 

# 要点总结
- 实例构造器可以设置为protected, 以允许子类派生
- 单例模式一般不要支持拷贝构造函数和clone接口, 以防多个实例的情况