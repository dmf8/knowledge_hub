# 概述
uv是新一代的Python版本管理工具, 可以替代pip/virtualenv/conda等

# 安装
## 在线安装
```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

## 下载二进制文件
1. 在github上找到最新版
    - https://github.com/astral-sh/uv/releases
1. 下载, 解压出二进制文件
1. Linux添加到环境变量
    ```bash
    mv uv ~/.local/bin
    mv uvx ~/.local/bin
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
    source ~/.bashrc
    ```

## pip安装
(未验证)
```bash
pip install uv
```

# 加速
需要设置两个环境变量(换源)
- UV_DEFAULT_INDEX
    - pip包加速
- UV_PYTHON_INSTALL_MIRROR
    - python install加速
        1. 在~/.bashrc中添加一行
        ```
        export UV_PYTHON_INSTALL_MIRROR="https://gh-proxy.com/https://github.com/indygreg/python-build-standalone/releases/download/"
        ```
        1. `source ~/.bashrc`


# 管理Python版本
## 查看列表
```bash
uv python list
```

## 安装特定版本
```bash
uv python install 3.12
```

## 删除特定版本
```bash
uv python uninstall 3.12
```

## 设置全局默认python版本
- 这条命令会在~/.config/uv/中建立一个.python-version的文件, 在其中记录指定的python版本
- 只对uv venv虚拟环境生效, 不会改变bash中默认的python版本
```bash
uv python pin --global 3.12
```

## 启动虚拟环境
1. 创建虚拟环境
    ```bash
    uv venv # 创建一个.venv的虚拟环境目录(默认)
    uv venv [name] # 指定venv的名字
    ```
1. 激活环境
    ```bash
    # linux
    source <venv_dir>/bin/activate # 这里指定venv的环境目录名, 默认情况下是.venv

    # windows
    .venv\Scripts\activate
    ```

1. 退出环境
    ```bash
    deactivate
    ```

## 包管理
- uv pip install
- uv pip uninstall
- uv pip upgrade

# 项目管理
## 初始化项目
```bash
uv init <dir>
```
- 初始化一个项目文件夹
- 会创建一些内容
    1. .venv目录
    1. .python-version
    1. pyproject.toml
    1. README.md
    1. uv.lock

## 安装项目依赖
```bash
uv sync
```

## 设置vscode解释器
作用是让python按照指定的解释器提供语法补全等功能

1. 手动设置
    1. 调出命令面板, 找到python: select interpreter
    1. 选择路径, 找到项目文件夹中的.venv/bin/pythonX.XX