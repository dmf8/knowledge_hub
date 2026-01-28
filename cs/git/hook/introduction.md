# 概念
在执行某个事件之前或之后进行的一些额外操作

git的很多事件前后也可以称为hook

# 实现方式
通过脚本实现, 位于.git/hooks/中

可以使用多种类型的脚本
- bash
- python

在.git/hooks/中, 有多个以.sample结尾的示例文件, 默认不生效. 实际生效的文件需要去掉.sample后缀, 并且需要具有可执行权限

# 常用钩子
|git hook|调用时机|说明|
|-|-|-|
|pre-commit|git commit执行前|-|
|commit-msg|git commit执行前|-|
|post-commit|git commit执行后|-|

# 钩子配置
通常, .git目录下的文件只存在于本地, 不会上传到git

要使hook对团队生效, 就需要进行配置

可以使用git的原生方式, 或借助第三方工具

## .githooks/ (原生方式)
1. 在git根目录下创建.githooks目录, 需要将该目录上传到git
1. 把hooks脚本放进该目录, 会覆盖.git/hooks中的同名配置
1. 配置git

    ```bash
    git config core.hooksPath .githooks
    ```

    恢复默认的方法

    ```bash
    git config --unset core.hooksPath
    ```

## Husky


## pre-commit

# 其他
- pre-commit框架