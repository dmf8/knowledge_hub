# pathlib 概述 [UUID]

面向对象的路径操作库(区别于之前的字符串操作)

## 基础用法

### 模块导入

```python
from pathlib import Path
```

### 创建Path对象

```python
p = Path("demo.txt")           # 相对路径
p = Path("/home/user/demo.txt")  # 绝对路径
p = Path(".") / "demo.txt"     # 使用 / 连接路径
```

## 功能

### 获取特定路径对象 (类方法)

- Path.home()

    返回用户家目录的Path对象

- Path.cwd()

    返回当前目录的Path对象

### 路径转换和规范化

- 转换

    - .resolve() -> Path

        转绝对路径, 同时解析符号链接, 返回新Path对象

    - .absolute() -> Path

        转绝对路径, 不解析符号链接, 返回新Path对象

### 路径判断
- .exists() -> bool

    路径是否存在

```python
p.is_file()      # 是否是文件
p.is_dir()       # 是否是目录
p.is_absolute()  # 是否是绝对路径
p.is_symlink()   # 是否是符号链接
p.is_socket()    # 是否是socket文件
p.is_fifo()      # 是否是FIFO管道
```

### 路径组件拆分

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