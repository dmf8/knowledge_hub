# 作用
用于打印消息，在调试时很有用，可以查看各种状态、变量的值等

# 句法
1. 通用消息
    这里实测发现，消息加不加引号效果相同
    ```
    message([<mode>] "message text" ...)
    ```
    mode可选，具体有哪些mode参见官方文档 https://cmake.org/cmake/help/latest/command/message.html#command:message
    
1. 查看变量
    ```
    message(${VARIABLE})
    ```