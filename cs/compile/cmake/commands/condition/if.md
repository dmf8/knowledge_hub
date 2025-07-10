# 作用
条件性地执行一段cmake命令

# 句法
```bash
if(<condition>)
  <commands>
elseif(<condition>) # optional block, can be repeated
  <commands>
else()              # optional block
  <commands>
endif()
```

- condition
    直接使用变量名即可，不需要${}