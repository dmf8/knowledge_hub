# -Wl,-rpath 知识详解

## 1. 概述

`-Wl,-rpath` 是 GCC/Clang 的一个链接器选项，用于在编译时设置可执行文件或共享库的 **RPATH**（运行时库搜索路径）。

### 1.1 语法解释

```
-Wl,-rpath,<path>
```

- `-Wl` : 告诉 GCC 将后面的参数传递给链接器 `ld`
- `-rpath,<path>` : 链接器选项，设置运行时搜索路径

等价写法：
```bash
-Wl,-rpath,.           # 方式1: 使用逗号分隔
-Wl,-rpath -Wl,.       # 方式2: 多次 -Wl
```

### 1.2 与 -L 的区别

| 选项 | 作用时机 | 说明 |
|------|----------|------|
| `-L<dir>` | 链接时 | 告诉编译器在哪里查找要链接的库文件 |
| `-Wl,-rpath,<dir>` | 运行时 | 告诉动态链接器在哪里查找共享库 |

`-L` 只在编译时生效，`-rpath` 会嵌入到 ELF 文件中，运行时仍然有效。

---

## 2. RPATH vs RUNPATH

### 2.1 区别

- **RPATH** (`DT_RPATH`): 旧版机制，会被 `LD_LIBRARY_PATH` 覆盖，依赖项会继承父 binary 的 rpath
- **RUNPATH** (`DT_RUNPATH`): 新版机制，优先级低于 `LD_LIBRARY_PATH`，依赖项不会继承

### 2.2 启用 RUNPATH

```bash
gcc -o app app.c -Wl,-rpath,/path/to/lib,--enable-new-dtags
```

`--enable-new-dtags` 会将 `DT_RPATH` 替换为 `DT_RUNPATH`。

---

## 3. $ORIGIN 特殊变量

`$ORIGIN` 表示当前 ELF 文件所在的目录，使路径相对于可执行文件或库本身，而非工作目录。

### 3.1 常用写法

```bash
# 相对可执行文件目录的 lib 文件夹
-Wl,-rpath,'$ORIGIN/lib'

# 相对可执行文件的上级目录的 lib 文件夹
-Wl,-rpath,'$ORIGIN/../lib'

# 相对可执行文件的 ../libs 子目录
-Wl,-rpath,'$ORIGIN/../libs'
```

### 3.2 在 Makefile 中使用

Makefile 中 `$` 需要转义：

```makefile
LDFLAGS = -Wl,-rpath,'$$ORIGIN/../lib'
```

---

## 4. 实战示例

### 4.1 基本用法

```bash
# 编译时指定 rpath
gcc -o myapp main.c -L./lib -lfoo -Wl,-rpath,./lib
```

### 4.2 多目录 rpath

```bash
gcc -o myapp main.c \
    -Wl,-rpath,/opt/lib1:/opt/lib2
```

### 4.3 完整示例

项目结构：
```
project/
├── bin/
│   └── myapp
└── lib/
    └── libfoo.so
```

编译命令：
```bash
gcc -o bin/myapp src/main.c \
    -L./lib -lfoo \
    -Wl,-rpath,'$ORIGIN/../lib'
```

---

## 5. 查看和修改 RPATH

### 5.1 查看 RPATH/RUNPATH

```bash
# 方法1: readelf
readelf -d myapp | grep -E 'RPATH|RUNPATH'

# 方法2: objdump
objdump -p myapp | grep -E 'RPATH|RUNPATH'

# 方法3: chrpath
chrpath -l myapp

# 方法4: patchelf (推荐)
patchelf --print-rpath myapp
```

### 5.2 修改 RPATH

```bash
# 使用 patchelf 修改
patchelf --set-rpath '$ORIGIN/lib' myapp

# 使用 chrpath 修改
chrpath -r '$ORIGIN/lib' myapp
```

### 5.3 移除 RPATH

```bash
patchelf --remove-rpath myapp
chrpath -d myapp
```

---

## 6. 动态链接器搜索顺序

Linux 动态链接器 (`ld.so`) 搜索共享库的顺序：

1. `DT_RPATH` (如果 `DT_RUNPATH` 不存在)
2. `DT_RUNPATH`
3. 环境变量 `LD_LIBRARY_PATH`
4. `/etc/ld.so.cache` 中的路径
5. 默认路径 `/lib`, `/usr/lib`

> 注意：`RUNPATH` 不会像旧版 `RPATH` 那样被 `LD_LIBRARY_PATH` 覆盖。

---

## 7. -rpath-link vs -rpath

| 选项 | 作用 |
|------|------|
| `-Wl,-rpath-link,<dir>` | 链接时解析符号使用，不嵌入二进制 |
| `-Wl,-rpath,<dir>` | 嵌入二进制，运行时使用 |

`-rpath-link` 用于解决链接时的循环依赖问题。

---

## 8. 最佳实践

1. **优先使用 RUNPATH**（加 `--enable-new-dtags`），兼容性更好
2. **使用 `$ORIGIN`** 而非绝对路径，提高可移植性
3. **避免硬编码路径**，便于程序在不同环境部署
4. **生产环境检查**，确保 rpath 正确

```bash
# 推荐写法
gcc -o myapp main.c \
    -L./lib -lfoo \
    -Wl,-rpath,'$$ORIGIN/lib' \
    --enable-new-dtags
```

---

## 9. 常用命令速查

```bash
# 编译带 rpath
gcc -o app app.c -L./lib -lfoo -Wl,-rpath,'$ORIGIN/lib'

# 查看依赖
ldd app

# 查看 RPATH
readelf -d app | grep RPATH

# 修改 RPATH
patchelf --set-rpath '$ORIGIN/lib' app

# 移除 RPATH
patchelf --remove-rpath app
```

---

## 10. 参考资料

- `man ld.so` - 动态链接器文档
- `man ld` - 链接器文档
- `man gcc` - GCC 链接器选项
