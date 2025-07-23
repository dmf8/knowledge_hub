[toc]

# 面向对象的思维模式
## 底层思维和抽象思维
- 底层思维

    向下, 如何把握机器底层, 从微观理解对象构造
    - 语言构造
    - 编译转换
    - 内存模型
    - 运行时机制
- 抽象思维

    向上, 如何将我们的周围世界抽象为程序代码
    - 面向对象
    - 组件封装
    - 设计模式
    - 架构模式

> 设计模式处在面向对象的向上思维模式位置

## 面向对象的理解
- 向下理解面向对象机制
    1. 封装, 隐藏内部实现
    1. 继承, 复用现有代码
    1. 多态, 改写对象行为

- 向上理解其抽象意义, 如何用来表达现实世界

> 复用性就是软件设计和设计模式的目标

# 解决复杂问题的两种思路
这两种思路不局限于软件领域
## 分解
把大问题分解为小问题

面向过程的语言常用, 不能解决所有复杂问题

## 抽象
由于不能掌握全部的复杂对象, 因而忽视其非本质细节, 只处理泛化和理想化的对象模型

# 本课程中设计模式的分类
## 目的分类
- 创建型

    将对象的部分创建工作延迟到子类或者其他对象, 从而应对需求变化为对象创建时具体类型实现带来的冲击

- 结构型

    通过类继承或者对象组合获得更灵活的结构, 从而应对需求变化为对象结构带来的冲击

- 行为型

    通过类继承或者对象组合来划分类与对象间的职责, 从而应对需求变化为多个交互对象带来的冲击

## 作用范围分类
- 类模式处理类与子类的静态关系
- 对象模式处理对象间的动态关系

## 本课程分类 (章节目录)
- [组件协作](<component collaboration/>)
    - [01-Template Method](<component collaboration/01-Template_Method/>)
    - [02-Strategy](<component collaboration/02-Strategy/>)
    - [03-Observer/Event](<component collaboration/03-Observer_Event/>)
- 单一职责
    - [04-Decorator](<single responsibility/04-Decorator/>)
    - [05-Bridge](<single responsibility/05-Bridge/>)
- 对象创建

    对象创建模式绕开new, 避免对象创建过程中导致的紧耦合(依赖具体类), 从而支持对象创建的稳定. 这是接口抽象之后的第一步工作. 

    - [06-Factory Method](<object creation/06-Factory Method/>)
    - [07-Abstract Factory](<object creation/07-Abstract Factory/>)
    - [08-*Prototype](<object creation/08-Prototype/>)
    - [09-*Builder](<object creation/09-Builder/>)

- 对象性能
    - [10-Singleton](<object performance/10-Singleton/>)
    - [11-Flyweight](<object performance/11-Flyweight/>)
- 接口隔离
    - Facade
    - Proxy
    - Adapter
    - Mediator
- 状态变化
    - Memento
    - State
- 数据结构
    - Composite
    - Iterator
    - Chain of Responsibility
- 行为变化
    - Command
    - Visitor
- 领域问题
    - Interpreter

# 设计模式实践建议
## 重构到模式
没有一步到位的设计模式, 在需要的时候重构到模式. 一上来就使用设计模式是对设计模式最大的误用.

现代软件的特征是需求的频繁变化. 设计模式的要点是寻找变化点, 在变化点处应用设计模式, 从而更好地应对需求的变化. 理解何时何地应用设计模式, 比理解设计模式结构本身更为重要. 

## 重构关键技法
- 静态->动态
- 早绑定->晚绑定
- 继承->组合
- 编译时依赖->运行时依赖
- 紧耦合->松耦合

# 面向对象设计原则
## 重新理解面向对象
- 语言层面

    对象封装了代码和数据

- 规格层面

    对象是一系列可以被使用的公共接口

- 概念层面

    对象是拥有责任的抽象

## 面向对象设计原则
1. 依赖倒置原则 DIP

    Dependency Inversion Principle

    这项原则贯穿了整个设计模式课程

    - 高层模块(稳定)不应依赖于低层模块(变化), 二者都应依赖于抽象(稳定)
    - 抽象(稳定)不应依赖于实现细节(变化), 应该反过来

1. 开闭原则 OCP

    Open-Closed Principle

    - 对扩展开放, 对修改封闭
    - 类模块应该可扩展而非可修改

1. 单一职责原则 SRP

    Single Responsibility Principle

    - 一个类应该仅有一个引起它变化的原因
    - 变化的方向隐含着类的责任

1. 里氏替换原则 LSP

    Liskov Substitution Principle

    - 子类必须能够替换它们的基类(IS-A)
    - 继承表达类型抽象

    如果子类在继承了父类后屏蔽了一些方法, 就要考虑子类是否不适合继承该父类. 此时子类无法完整替换父类

1. 接口隔离原则 ISP
1. 优先使用组合而非继承 CRP
1. 封装变化点

# 推荐教材
- 设计模式 可利用面向对象软件的基础

    作者 Gang of Four
    - Erich Gamma
    - Richard Helm
    - Ralph Johnson
    - John Vlissides
- 重构 改善既有代码的设计
    - Martin Fowler
- 重构与模式
    - Joshua Kerievsky
