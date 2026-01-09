# 概述
## 作用
实现命令行应用的推荐库

## 使用前提
- 安装

    如果源码中引用失败, 考虑是否是没有安装的问题

    ```bash
    pip install argparse
    ```

- 源码中引用
    ```python
    import argparse
    ```

## 基本概念
- positional arguments

    占位参数, 直接在对应位置给定参数值, 必选, 相当于普通形参

- flag arguments

    可选参数或选项, 在一般的用法中写在必选参数之前, 一般至少有选项名, 有些选项还有选项值

    选项名还有长短之分, 可以任意给定, 但至少要有一个

# 开发常规用法
1. 构造ArgumentParser

    这里的description会出现在[-h](#查看帮助信息)中

    ```python
    parser = argparse.ArgumentParser()
    parser = argparse.ArgumentParser(description="test parser") # 指定描述内容, 在查看帮助信息时呈现为工具的描述信息
    ```

1. add_argument() 定义参数

    函数原型如下

    ```python
    ArgumentParser.add_argument(name or flags..., *[, action][, nargs][, const][, default][, type][, choices][, required][, help][, metavar][, dest][, deprecated])
    ```

    - name/flags
        - name, 对应positional arguments
            ```python
            parser.add_argument("name")
            ```
        - flags, 对应flag arguments
            ```python
            parser.add_argument("-f")
            parser.add_argument("--flag")
            parser.add_argument("-f", "--flag")
            ```
    
    - action
    - nargs

        > 总的来说, 确切的含义需要结合names/flags, default, const共同决定

        表示选项的参数数量. 默认情况下, 每个选项(positional/flag)有1个参数值与之对应. nargs可以指定选项具有不同数量的参数值.

        不论指定多少个参数值, 都可以在调用时省略, 这样就会使用默认参数值. 默认参数值来自于default/const. 对于flag参数, 还有两种省略状态: 给定选项名但省略参数值, 或者连选项名一同省略

        nargs可用值总结如下, 详情见下方说明

        |可用值|需要的参数值(对于flag, 是给定选项名时需要的参数值)|备注|
        |-|-|-|
        |N|N|
        |?|0/1|
        |*|>=0|参数以列表形式获取|
        |+|>=1|参数以列表形式获取|

        默认参数值来源
        - positional
            
            来自default
        - flag
            1. 当选项名隐藏时, 来自default
            1. 当给定选项名但没指定参数值时, 来自const
        

        可用值有:
        - N

            注意当显式指定N为1时, 和使用默认的1还是有区别的

        - '?'

        - '*'

            所有参数值组成一个列表, 在指定选项名时, 允许的参数值数量>=0
        - '+'

            所有参数值组成一个列表, 在指定选项名时, 允许的参数值数量>=1

    - default

        默认为None, 在指定的情况下, 为命令行参数提供某些条件下的默认值
    - type
        
        参数的解析类型

        一般参数都以字符串类型来解析. 但也可以指定为其他数据类型, 如基本变量类型, 结构体类型

    - metavar



    - help

        参数的帮助信息, 出现在[-h](#查看帮助信息)中

1. parse_args() 解析参数

    使用这个函数, 必须严格保证参数正确:
    - 不能有未知的选项
    - 参数数量不能多, 不能少

    解析得到的参数可以转换为字典进行遍历
    ```python
    args = parser.parse_args()
    args_dict = vars(args)
    for k, v in args_dict.items():
        print(f"{k}: {v}")
    ```

1. 使用参数

    使用以下方式获取参数值
    ```python
    args.name
    ```

    对于不同的参数类型, 变量名name规则如下

    - positional, 自身
    - flag
        - -f, 自身
        - --flag, 自身
        - -f/--flag, flag


# 应用
## 查看帮助信息
```bash
python3 xxx.py -h
```

## 正常传入命令行参数

# 进阶用法
- 允许未知的参数 parse_known_args()