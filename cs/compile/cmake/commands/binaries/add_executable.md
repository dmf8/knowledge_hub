# 作用
用指定的源文件为工程添加可执行程序

可以添加的可执行程序的种类有:
- 常规可执行程序
- 导入可执行程序
- 可执行程序别名

# 句法
## 常规可执行程序
```
add_executable(<name> <options>... <sources>...)
```
- name
    可执行文件名。一般会取工程名，即`${PROJECT_NAME}`。实际的可执行文件名可能因不同平台变成<name.exe>或<name>
- options
    见官方文档
- sources
    源文件列表，用空格分隔，顺序任意

    对于>=3.11版本的cmake，可以忽略该参数，在之后通过target_sources来设置（未验证）

# 案例
```
add_executable(${PROJECT_NAME} src/Hello.cpp src/main.cpp) # 添加多个源文件
```