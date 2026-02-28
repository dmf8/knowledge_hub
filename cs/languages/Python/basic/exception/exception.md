# 捕获语法
## 简单捕获 try-except
### 捕获任意错误
```python
try:
        # 尝试执行的代码
# 1. 忽视错误类型
except:

# 2. 捕获Exception及其子类对象, 可以接任意未知类型的异常
except Exception as e:
        str(e) # 异常详细信息
        type(e).__name__ # 错误类型, 也就是下面一种方式需要的参数
```

### 捕获特定错误
错误类型是抛出异常的最后一行报错信息的冒号之前的内容, 也就是`type(e).__name__`的内容
```python
# 有两种形式
except 错误类型:
except (错误类型1, 错误类型2):
```

## 完整捕获 try-except-else-finally
- else 没有异常时执行的代码块
- finally 最终都会执行的代码块
        - 一般用于资源清理, 无论执行结果如何, 都需要清理资源
- 完整语法案例
        ```python
        try:
                # 尝试运行的代码
        except 错误类型:
                # 捕获指定错误
        except Exception as e:
                # 通用捕获未知错误
        else:
                # 没有抛异常时执行
        finally:
                # 最终统一执行
        ```

# 自定义异常
## 自定义异常对象
### 主流实现方式
1. 自定义异常类, 继承于Exception, 可以多级继承
1. 根据需要定义

## 抛异常 raise


---

下面是AI生成的内容

---

# Python 异常学习笔记

## 目录

1. [异常基础概念](#1-异常基础概念)
2. [Python内置异常层次结构](#2-python内置异常层次结构)
5. [捕获异常对象](#5-捕获异常对象)
6. [多个except语句](#6-多个except语句)
7. [raise抛出异常](#7-raise抛出异常)
8. [自定义异常类](#8-自定义异常类)
9. [异常传播机制](#9-异常传播机制)
10. [异常链与上下文](#10-异常链与上下文)
11. [assert断言](#11-assert断言)
12. [traceback模块](#12-traceback模块)
13. [异常最佳实践](#13-异常最佳实践)

---

## 1. 异常基础概念

- 什么是异常
- 异常与错误的区别
- 异常的作用
- 常见的异常场景


## 2. Python内置异常层次结构

- BaseException
    > 不用于直接继承, 相关成员
    > - args

    - Exception
        > 用于
        - StopIteration
        - StopAsyncIteration
        - ArithmeticError
            - FloatingPointError
            - OverflowError
            - ZeroDivisionError
        - LookupError
            - IndexError
            - KeyError
        - OSError
            - FileNotFoundError
            - PermissionError
            - TimeoutError
        - TypeError
        - ValueError
        - RuntimeError
        - ...
    - KeyboardInterrupt
    - SystemExit
    - GeneratorExit

## 5. 捕获异常对象
- 获取异常信息
- 异常的args属性

## 6. 多个except语句

- 按顺序匹配
- 异常子类在前，父类在后

## 7. raise抛出异常

- `raise` 语句
- `raise ExceptionType()`
- `raise ExceptionType(message)`
- 重新抛出异常 `raise`

## 8. 自定义异常类

- 继承自 Exception
- 命名约定（以Error结尾）
- 添加自定义属性和方法

## 9. 异常传播机制

- 异常向上传播
- 调用栈
- 最顶层未捕获则程序终止

## 10. 异常链与上下文

- `raise ... from ...`
- `__cause__` 属性
- `__context__` 属性
- `__suppress_context__`

## 11. assert断言

- `assert condition`
- `assert condition, message`
- `__debug__`
- 使用场景

## 12. traceback模块

- `traceback.print_exc()`
- `traceback.format_exc()`
- 获取详细堆栈信息

## 13. 异常最佳实践

- 精确捕获异常
- 避免裸 except
- 异常不应代替流程控制
- 记录异常日志
- 资源清理使用 finally 或上下文管理器
- 异常信息要有意义

---

> 学习来源：Python官方文档、《Python编程：从入门到实践》等
