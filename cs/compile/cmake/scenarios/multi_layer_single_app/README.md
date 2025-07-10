# 情景描述
这是一种简单的情况，工程构建时没有引用其他库，工程内存在多个层级的头文件和源文件，但最终都编译进了一个单一app。文件分层摆放的目的可能只是为了分类。
为了描述更一般的情况，这里演示了源文件嵌套两层的案例。

# cmake构建要点
1. 添加头文件路径
1. 将所有源文件添加到目标
    这一步又可以分为不同的实现方式
    - 在顶层CMakeLists.txt中写出所有的源文件引用路径
    - 使用cmake片段文件，在每一层中将所包含的源文件添加到片段文件，然后引用片段文件
        具体操作为
        1. 在顶层的CMakeLists.txt中，创建两个变量，用于存放头文件引用目录列表和源文件列表
        1. 每个子目录中创建一个.cmake文件，用于向变量写入自身包含的源文件和头文件目录
            - 文件和目录的引用需要使用当前片段文件作为引用起点。如果只给出相对于子目录的路径，对调用者而言会找不到该路径
            - 可以通过遍历函数来找到所有源文件，这样可以让片段文件更加通用
            ```
            foreach(file ${UTILS_FILES})
                list(APPEND GLOBAL_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
            endforeach()
            ```

# 等效g++命令
以build文件夹为起点，生成可执行目标文件test
```
g++ -I ../sub1/include/ -I ../sub1/sub2/include/ -o test ../main.cpp ../sub1/src/test_class1.cpp ../sub1/sub2/src/test_class2.cpp
```

