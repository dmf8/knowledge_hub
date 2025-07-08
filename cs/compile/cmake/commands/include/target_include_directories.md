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
    头文件目录的可见性
    - PRIVATE
        指定的头文件目录只对当前目标可见，用于当前目标编译依赖但不想暴露的头文件
    - INTERFACE
        指定的头文件目录只对依赖于当前目标的其他目标可见，用于当前目标编译不依赖但使用者依赖的接口头文件
    - PUBLIC
        PRIVATE和INTERFACE的结合，指定的头文件目录同时对当前目标和传递目标可见