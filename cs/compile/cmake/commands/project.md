# 作用
设置工程名，存入`PROJECT_NAME`变量
如果是顶层的CMakeLists.txt调用，还会将工程名存入`CMAKE_PROJECT_NAME`
同时还会设置一些路径变量。常用的受影响的变量列表如下
|变量|影响|
|-|-|
|PROJECT_NAME|工程名|
|CMAKE_PROJECT_NAME|工程名|
|PROJECT_SOURCE_DIR|工程所在的绝对路径|
|<PROJECT_NAME>_SOURCE_DIR|工程所在的绝对路径|
|PROJECT_BINARY_DIR|工程的构建路径|
|<PROJECT_NAME>_BINARY_DIR|工程的构建路径|
参见[案例](#案例)

# 句法
简单用法
```
project(<PROJECT-NAME> [<language-name>...])
```

复杂用法
```
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [COMPAT_VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>...])
```

# 案例
```
project(hello_cmake)
message(${PROJECT_NAME}) # hello_cmake
message(${CMAKE_PROJECT_NAME}) # hello_cmake
message(${PROJECT_SOURCE_DIR})
message(${hello_cmake_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})
message(${hello_cmake_BINARY_DIR})
```