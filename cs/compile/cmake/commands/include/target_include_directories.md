# 作用
为target添加包含目录

# 句法
```
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```
- target
    必须之前用add_executable或add_library命令指定过，并且不能是target别名。也就是说，这句话总是出现在add_executable或add_library之后。
- INTERFACE|PUBLIC|PRIVATE
    头文件目录的可见性，有以下3种：
    - PRIVATE
        指定的头文件目录只对当前目标可见，用于当前目标编译依赖但不想暴露的头文件
    - INTERFACE
        指定的头文件目录只对依赖于当前目标的其他目标可见，用于当前目标编译不依赖但使用者依赖的接口头文件
    - PUBLIC
        PRIVATE和INTERFACE的结合，指定的头文件目录同时对当前目标和传递目标可见

    设置包含目录的可见性，本质上是在给不同的属性赋值（追加赋值）。
    相关受影响的属性有
    - INCLUDE_DIRECTORIES，表示当前目标的包含路径
    - INTERFACE_INCLUDE_DIRECTORIES，表示当前目标的接口路径，目标本身不引用该路径

    不同可见性对属性的赋值影响具体见下表
    |作用域|INCLUDE_DIRECTORIES|INTERFACE_INCLUDE_DIRECTORIES|
    |-|-|-|
    |PRIVATE|Y|N|
    |INTERFACE|N|Y|
    |PUBLIC|Y|Y|