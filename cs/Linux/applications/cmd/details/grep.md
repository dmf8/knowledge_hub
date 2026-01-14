# 句法
```bash
grep [options] pattern [files]
```
- options
    - -i/--ignore-case, --no-ignore-case(default): 是否忽略大小写(默认不忽略)
    - -v/--invert-match: 反向查找
    - -n: 显示匹配的行号
    - -r: 递归查找子目录中的文件
    - -h/--no-filename, -H/--with-filename(default): 匹配内容是否显示文件名称(默认显示)
    - -c: 只打印匹配的行数
    - -e/--regexp=\<pattern>: 使用正则表达式进行匹配
    
        如果含有转移字符等, 建议使用引号括起

        ```bash
        -e "regexp"
        --regexp="regexp"
        ```

- pattern

    要查找的字符串或正则表达式

- files

    要查找的文件名, 可以同时查找多个文件. 如果省略, 则从stdin中读取

    如果直接使用grep并省略files, 就会进入交互模式, 每输入一行就会做一次grep匹配

# 常见用法
- 在搜索结果中查找特定内容

    使用管道将搜索结果传递给grep