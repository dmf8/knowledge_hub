# 作用
指定cmake要求的最小版本
cmake一直在发展，每个版本都会引入新的语法。整个工程中用到的最新版本引入的语法，这个语法对应的版本就应该是cmake要求的最小版本。
如果运行的cmake版本小于要求的版本，会直接报错。

# 句法
```
cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])
```

# 案例
这句话一般用在顶层CMakeLists.txt的第一行。
```
cmake_minimum_required(VERSION 3.5)
```