# 作用
提供一个可供用户选择的布尔类型选项

# 句法
```
option(<variable> "<help_text>" [value])
```

- variable
选项变量名

- help_text
选项提示文字（不知道在哪显示？）

- value
选项默认值，默认为OFF

# 使用
- cmake时设置选项值
    使用-D接选项名，并赋值。-D的含义是定义缓存变量。
    ```
    cmake -D<variable>=ON|OFF <path>
    ```
    
    可以通过查看缓存变量的方式查看变量值，查看方式为
    ```
    cmake -L -N <path>
    ```
    查看的结果是上一次执行cmake的变量值。如果没有执行过则查询不到。

- 使用建议
    - 建议将所有选项放在每个cmake文件的最上面，这些选项属于外部参数，这样做可以方便查看