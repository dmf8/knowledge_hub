# 网络知识学习计划

## 学习目标
建立网络全方面认知，重点掌握运维/调试技能，能够独立排查和解决网络问题。

---

## 阶段一：网络基础（1-2周）

### 1.1 OSI 与 TCP/IP 模型
- 七层模型 vs 四层模型
- 每层职责和常见协议
- 数据封装/解封装过程

### 1.2 IP 地址与子网
- IPv4 地址分类（A/B/C/D/E）
- 子网掩码与 CIDR 表示法
- 公有 IP vs 私有 IP
- NAT 原理
- IPv6 基础

### 1.3 常用命令
- `ip addr` / `ifconfig` - 查看网卡信息
- `ip route` / `route` - 查看路由表
- `ping` - 连通性测试
- `traceroute` / `tracert` - 追踪路由
- `netstat` / `ss` - 查看端口和连接
- `nslookup` / `dig` / `host` - DNS 查询

---

## 阶段二：路由与交换（2-3周）

### 2.1 路由基础
- 静态路由 vs 动态路由
- 路由优先级与度量值
- 默认网关
- 路由表解读

### 2.2 交换机基础
- VLAN 原理与配置
- Trunk 链路
- STP 生成树协议
- 交换机安全（端口安全、MAC 地址绑定）

### 2.3 常用命令
- `ip link` - 网卡操作
- `ip route` - 路由操作
- `bridge` - 网桥配置
- `vconfig` - VLAN 配置

---

## 阶段三：端口与服务（1-2周）

### 3.1 端口概念
- 端口号分类（知名端口、注册端口、动态端口）
- 常见服务端口（22/SSH, 80/HTTP, 443/HTTPS, 3306/MySQL 等）
- 端口扫描工具（nmap）

### 3.2 防火墙基础
- iptables/nftables 基础
- 规则链（INPUT/OUTPUT/FORWARD）
- 允许/拒绝策略
- 状态跟踪（ESTABLISHED, NEW, RELATED）

### 3.3 常用命令
- `iptables` / `nft` - 防火墙管理
- `ss -tuln` - 查看监听端口
- `lsof -i` - 查看进程占用端口
- `nmap` - 端口扫描

---

## 阶段四：组网技术（2-3周）

### 4.1 VPN 与隧道
- VPN 类型（PPTP, L2TP, OpenVPN, WireGuard, IPSec）
- 隧道原理
- 常见组网方案

### 4.2 DNS 原理
- DNS 记录类型（A, AAAA, CNAME, MX, TXT 等）
- DNS 解析流程
- DNS 缓存与 TTL
- 常用工具（dig, nslookup）

### 4.3 DHCP 原理
- DHCP 工作流程
- IP 地址分配
- DHCP 中继

---

## 阶段五：网络安全（2-3周）

### 5.1 网络攻击类型
- DDoS 攻击
- ARP 欺骗
- DNS 劫持
- 中间人攻击
- SQL 注入、XSS（Web 层）

### 5.2 安全防御
- 防火墙规则最佳实践
- IDS/IPS 基础
- 加密通信（TLS/SSL）
- 证书管理

### 5.3 常用命令
- `tcpdump` - 抓包分析
- `wireshark` - 协议分析
- `nmap` - 安全扫描
- `fail2ban` - 入侵防御

---

## 阶段六：实战与调试（持续）

### 6.1 排查流程
1. 检查物理连接
2. 检查 IP 配置
3. 检查路由表
4. 检查防火墙规则
5. 检查服务状态
6. 抓包分析

### 6.2 调试命令汇总
```bash
# 网络配置
ip addr show
ip route show
ip link set eth0 up/down

# 连通性测试
ping -c 4 8.8.8.8
traceroute -I 8.8.8.8
mtr 8.8.8.8

# 端口与服务
ss -tuln
lsof -i :80
netstat -antp

# DNS
dig example.com
nslookup example.com
host -a example.com

# 防火墙
iptables -L -n -v
iptables -A INPUT -p tcp --dport 22 -j DROP

# 抓包
tcpdump -i eth0 port 80
tcpdump -i eth0 host 192.168.1.1
```

### 6.3 实践项目
- 搭建私有 VPN
- 配置防火墙规则
- 排查一次网络故障
- 搭建 DNS 服务器
- 使用 tcpdump 进行抓包分析

---

## 学习资源

### 书籍
- 《计算机网络：自顶向下方法》
- 《TCP/IP 详解》
- 《Linux 高性能服务器编程》

### 在线资源
- Cisco NetAcad
- RHEL/CentOS 官方文档
- Arch Wiki 网络篇

### 工具
- GNS3 / Cisco Packet Tracer - 网络模拟器
- Wireshark - 协议分析
- nmap - 端口扫描
- tcpdump - 抓包

---

## 建议

1. **边学边实践**：每学一个知识点，在虚拟机或本地环境动手操作
2. **建立知识图谱**：将各知识点串联，形成整体认知
3. **记录笔记**：使用本目录记录学习笔记和实践心得
4. **定期复盘**：每周回顾所学内容，查漏补缺
