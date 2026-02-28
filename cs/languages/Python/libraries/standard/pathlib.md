# pathlib 概述 [UUID]

面向对象的路径操作库(区别于之前的字符串操作)

## 基础用法

### 模块导入

```python
from pathlib import Path
```

### 创建Path对象

```python
# 相对路径
p = Path("demo.txt")           

# 绝对路径
p = Path("/home/user/demo.txt")  

# 使用 / 连接路径
p = Path(".") / "demo.txt"     
```

## 功能

### 获取特定路径对象 (类方法)

- Path.home()
    - 返回用户家目录的Path对象

- Path.cwd()
    - 返回当前目录的Path对象


### 路径转换和规范化
- 转换
    - .resolve() -> Path
        - 转绝对路径, 同时解析符号链接, 返回新Path对象
    - .absolute() -> Path
        - 转绝对路径, 不解析符号链接, 返回新Path对象

### 路径判断
#### 状态判断
- .exists(*, follow_symlinks=True) -> bool
    - 路径是否存在
    - 返回False的情况
        1. 不可用
        1. 不可访问
        1. 缺失

        这些情况可以用Path.stat()来区分
    - follow_symlinks的含义是, 当遇到符号链接时, 会追溯其目标. 如果为False, 那么只会获取符号链接本身的信息. 需要Python版本3.12. 

- .stat(*, follow_symlinks=True) -> os.stat_result object
    - 返回的对象包含多个成员变量, 记录了目标的各种属性/时间信息. 参考os.stat_result. 
    - 某些情况下, 调用会抛异常
        1. 文件不存在
        1. 符号链接文件, 但链接断开, 并且follow_symlinks, 和上一条本质相同

- is_absolute()
    - 返回True的情况
        1. Path的风格符合当前操作系统, 并且从根目录开始
            - Linux系统从/开始
            - Windows系统从类似C:/开始(单纯的"C:"会判定为False)

            > 也就是说, is_absolute为True时, 路径起始必须要有/

#### 类型判断
有个共性: 当exists()返回False时, 调用类型判断函数也会返回False. 在存在的情况下则按照类型是否匹配进行返回. 
- .is_file(*, follow_symlinks=True) -> bool
    - 返回False的情况
        1. exists()返回False的情况
        1. 不是文件

- .is_dir(*, follow_symlinks=True) -> bool
    - 返回False的情况
        1. exists()返回False的情况
        1. 指向的不是一个目录

- .is_symlink()
    - 即时链接断开, 返回的也会是True
    - 返回False的情况
        1. exists()返回False的情况
        1. 不是一个符号链接

> 关于不存在的路径

不存在的路径可以理解为是文件或者目录. 因为文件也可以不带后缀. 不能用以下特征来区分文件还是目录:
1. 是否有.后缀
1. 尾部是否有/


### 路径组件拆分 (成员变量)
- .parts 路径构成
    - 这是一个元组, 记录了Path对象的路径构成
    - 绝对路径和相对路径的构成会存在区别
    - 一些特殊的路径构成
        1. ".": 元组为空
        1. 以/结尾的目录: 会去掉/, 可以理解成路径不会区分目录还是

- .name 

案例

```python
p = Path("/home/user/project/file.txt")

p.parts          # ('/', 'home', 'user', 'project', 'file.txt')
p.name           # 'file.txt' - 文件名(含扩展名)
p.stem           # 'file' - 文件名(不含扩展名)
p.suffix         # '.txt' - 扩展名
p.parent         # Path('/home/user/project') - 父目录
p.parents        # 可迭代父目录列表
```

### 路径连接

```python
p = Path("/home/user")
p / "project" / "file.txt"  # Path('/home/user/project/file.txt')
```

### 路径匹配

```python
p = Path("demo.txt")
p.match("*.txt")     # True - 支持glob模式匹配
p.match("demo.*")    # True
p.match("*.py")      # False
```

### 路径修改

```python
p = Path("demo.txt")

p.with_name("new.txt")      # 替换文件名: demo.txt -> new.txt
p.with_suffix(".md")        # 替换扩展名: demo.txt -> demo.md
p.with_stem("demo2")        # 替换stem: demo.txt -> demo2.txt
```

## 文件/目录操作 (执行IO)

### 创建

```python
p = Path("demo.txt")
p.touch()                   # 创建空文件
p.mkdir(parents=True)       # 创建目录, parents=True创建父目录
p.mkdir(parents=True, exist_ok=True)  # 目录存在不报错
```

### 读写文件

```python
p = Path("demo.txt")

p.write_text("Hello")       # 写入文本, 返回字节数
p.read_text()              # 读取文本
p.write_bytes(b"Hello")    # 写入字节
p.read_bytes()             # 读取字节

# 也可用 open() 方法
with p.open("r") as f:
    content = f.read()
```

### 删除

```python
p = Path("demo.txt")
p.unlink()                 # 删除文件
p.rmdir()                  # 删除空目录
```

### 重命名/移动

```python
p = Path("demo.txt")
p.rename("new.txt")        # 重命名
p.replace("/path/new.txt") # 移动/替换
```

## 目录遍历

```python
p = Path(".")

p.iterdir()                # 遍历当前目录下的所有文件和目录
p.glob("*.py")             # 遍历匹配的文件(单层)
p.rglob("*.py")            # 递归遍历所有匹配文件
list(p.glob("**/*.py"))    # 递归遍历(需转list)
```

### 案例

- 模块导入

    ```python
    from pathlib import Path
    ```