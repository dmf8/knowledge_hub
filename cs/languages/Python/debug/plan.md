# Python 打印调试知识大纲

## 📌 基础打印技巧

### print() 函数核心参数
- `sep`: 分隔多个打印值
- `end`: 自定义结束字符
- `file`: 输出目标（stdout/stderr/file）
- `flush`: 强制刷新缓冲区

### f-string 调试技巧 (3.8+)
- `f"{variable=}"` 同时输出变量名和值
- 表达式直接求值显示
- 格式说明符：`:.2f`, `:>10`, `:x` 等

---

## 🔍 美化输出

### pprint 模块
- 格式化复杂数据结构
- `pprint.pprint()` vs `print()`
- 自定义深度和宽度

### pretty printing 库
- `rich` 库：彩色输出、表格、进度条
- `icecream` 库：增强调试打印

---

## 📝 日志系统

### logging 模块
- **级别**: DEBUG < INFO < WARNING < ERROR < CRITICAL
- `logging.basicConfig()` 快速配置
- `logging.getLogger()` 命名日志器
- Formatter: 自定义输出格式
- Handlers: 输出到文件、控制台、syslog

### 日志最佳实践
- 配置日志级别
- 使用结构化日志
- 避免生产环境 print

---

## 🐛 断点调试

### breakpoint() (Python 3.7+)
- 默认调用 pdb
- 可自定义调试器：`PYTHONBREAKPOINT=ipdb.set_trace`

### pdb 命令行调试
- `pdb.set_trace()` 断点
- 常用命令：`n`, `s`, `p`, `l`, `c`, `w`

### 第三方调试器
- `ipdb`：IPython 集成调试器
- `pdb++`：增强版 pdb
- IDE 调试器：VSCode、PyCharm

---

## 📊 追踪与回溯

### traceback 模块
- `traceback.print_exc()` 打印异常信息
- `traceback.format_exc()` 获取格式化的异常字符串
- 自定义异常处理

### sys 模块
- `sys.stderr.write()` 错误输出
- `sys.stdout` / `sys.stderr` 重定向

---

## 🛠️ 调试技巧

### 条件断点
- 基于条件的 `print()` 或 `breakpoint()`

### 上下文管理器调试
- 使用 `contextlib` 追踪代码块执行

### 装饰器调试
- 打印函数调用信息
- 计时和性能分析

---

## 📦 实用工具

### icecream 库
- `ic()` 替代 print
- 自动显示变量名和值
- 条件启用/禁用

### devtools 库
- 美化 Python 调试输出

### 日志配置模板
- 常见项目日志配置示例
