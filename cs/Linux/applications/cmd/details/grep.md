# 句法
```bash
grep [options] pattern [files]
```
- options
    - 正则相关
        - -i/--ignore-case, --no-ignore-case(default): 是否忽略大小写(默认不忽略)
        - -e/--regexp=\<pattern>: 使用正则表达式进行匹配
        
            如果含有转移字符等, 建议使用引号括起

            ```bash
            -e "regexp"
            --regexp="regexp"
            ```
    - 匹配对象
        - -r: 递归查找子目录中的文件
    - 显示内容
        - -h/--no-filename, -H/--with-filename(default): 匹配内容是否显示文件名称(默认显示)
        - -n: 显示匹配的行号
        - -c: 只打印匹配的行数
        - -v/--invert-match: 反向查找
        - -A/--after-context=\<lines>: 同时显示匹配行之后的行数
        - -B/--before-context=\<lines>: 同时显示匹配行之前的行数
        - -C/--context=\<lines>/-\<lines>: 同时显示匹配行前后的行数
            ```bash
            -A 1
            --before-context=1
            -1
            ```

- pattern

    要查找的字符串或正则表达式

- files

    要查找的文件名, 可以同时查找多个文件. 如果省略, 则从stdin中读取

    如果直接使用grep并省略files, 就会进入交互模式, 每输入一行就会做一次grep匹配

# 常见用法
- 在搜索结果中查找特定内容

    使用管道将搜索结果传递给grep