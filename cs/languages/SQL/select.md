# 句法
```sql
SELECT ... FROM ... [WHERE ...] [ORDER BY ...] [GROUP BY ...]
```

# 主句 SELECT FROM
用于在表格或子查询中查询字段

```sql
SELECT result-column[, ...] FROM table-or-subquery;
```

## 在指定表中查询
1. 查询所有列
    ```sql
    SELECT * FROM table_name
    ```
1. 查询指定列(可以指定列的别名)

    这些列名不要加引号
    ```sql
    SELECT 
        column1 AS 别名, --显示的时候, 会把column1命名为别名 
        column2, ... 
    FROM table_name
    ```

1. 查询条件列

    这里可以将WHERE/GROUP BY中的条件也作为查询列, 条件满足时显示的值为1

## 在子查询中查询
```sql
SELECT ... FROM (SELECT ...)
```

## 聚合函数
SELECT后面的查询对象可以是聚合函数, 对一组值进行计算, 并返回单个值(也就是每一组在返回时都会退化为一行)

如果使用了GROUP BY, 就可能会产生多个分组, 否则就只有一个分组

聚合函数会忽略null值(除了COUNT)

常用的聚合函数有:
1. MIN(列名)

    指定的列名中的最小值

1. MAX(列名)

    指定的列名中的最大值

1. COUNT()

    统计每个分组的行数

    ```sql
    COUNT(*) --行数
    COUNT(列名) --?
    ```

1. SUM(列名)
1. AVG(列名)

使用案例
```sql
SELECT 
    COUNT(*) AS 别名 --如果不起别名, 这一项的列名就是COUNT(*)
FROM table_name
GROUP BY column_name
```

# 子句
## WHERE 条件
## ORDER BY 排序
## GROUP BY 分组
可以将查询结果按照条件区分为多个分组. 否则查询结果就是一个统一的分组

可能的分组包括:

1. 列名

    按照列的值进行分组, 相同值合并到同一个分组

1. 列名1, 列名2

    按照多个列进行分组, 需要多个列的值同时相同才能进入同一个分组

    如果列名1的值有n1种可能, 列名2的值有n2种可能, 那么最多可能有n1*n2个分组

1. 条件分组
    
    条件分组可以理解为和WHERE类似, 但WHERE只会保留满足条件的分组, 而条件分组会将满足条件和不满足条件的两组都保留

    ```sql
    SELECT COUNT(*)
    FROM qc_result
    GROUP BY id>8 --会按照id<=8和id>8分为2组
    ```