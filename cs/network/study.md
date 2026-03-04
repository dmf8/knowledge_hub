# 网络知识学习计划

## 学习目标
建立网络全方面认知，重点掌握运维/调试技能，能够独立排查和解决网络问题。

---

## 阶段一：网络基础（1-2周）

### 1.1 OSI 与 TCP/IP 模型

**重点知识点：**
- 七层模型：物理层→数据链路层→网络层→传输层→会话层→表示层→应用层
- TCP/IP 四层模型：网络接口层→网络层→传输层→应用层
- 每层核心协议：
  - 应用层：HTTP, DNS, FTP, SSH, SMTP
  - 传输层：TCP, UDP
  - 网络层：IP, ICMP, ARP
  - 数据链路层：Ethernet, PPP
- 数据封装过程：应用数据→TCP头→IP头→以太网帧
- 常见端口与协议对应关系

**实践任务：**
- 使用 Wireshark 抓取 HTTP 请求，观察各层数据
- 对比 OSI 和 TCP/IP 模型的对应关系

---

### 1.2 IP 地址与子网

**重点知识点：**
- IPv4 地址结构：32 位二进制，分为 4 个八位组
- IPv4 分类：
  - A 类：1.0.0.0 - 126.255.255.255（/8）
  - B 类：128.0.0.0 - 191.255.255.255（/16）
  - C 类：192.0.0.0 - 223.255.255.255（/24）
  - D 类：224.0.0.0 - 239.255.255.255（多播）
  - E 类：240.0.0.0 - 255.255.255.255（实验）
- 私有 IP 范围：
  - 10.0.0.0/8
  - 172.16.0.0/12
  - 192.168.0.0/16
- 子网掩码作用与计算
- CIDR 无类域间路由表示法
- NAT（网络地址转换）原理：SNAT、DNAT、端口映射
- IPv6 地址结构：128 位，8 组 16 进制

**实践任务：**
- 计算子网：给定 IP 和子网掩码，计算网络地址、广播地址、可用主机范围
- 在虚拟机中配置静态 IP 和 DHCP
- 搭建 NAT 环境进行测试

---

### 1.3 常用命令

**重点知识点：**
- `ip addr` / `ifconfig`：查看网卡 IP、MAC 地址、状态
- `ip route` / `route`：查看路由表，理解每条路由含义
- `ping`：ICMP 协议，连通性测试，延迟测量
- `traceroute` / `tracert`：追踪数据包经过的路由节点
- `mtr`：ping 和 traceroute 的结合，实时显示路由
- `netstat` / `ss`：查看网络连接、监听端口、路由统计
- `nslookup` / `dig` / `host`：DNS 查询

**实践任务：**
```bash
# 查看网卡信息
ip addr show
ip link show

# 查看路由表
ip route show
ip route get 8.8.8.8

# 连通性测试
ping -c 4 8.8.8.8
ping -I eth0 8.8.8.8  # 指定源网卡

# 追踪路由
traceroute -I 8.8.8.8
mtr 8.8.8.8

# 查看端口
ss -tuln
ss -tan state established
netstat -antp

# DNS 查询
dig +trace example.com
nslookup example.com 8.8.8.8
```

---

## 阶段二：路由与交换（2-3周）

### 2.1 路由基础

**重点知识点：**
- 路由表结构：目的网络、下一跳、接口、优先级/度量值
- 静态路由：手动配置，适用于小型网络
- 动态路由协议：RIP、OSPF、BGP
- 路由优先级（管理距离）：直连>静态>OSPF>RIP
- 度量值（Metric）：跳数、带宽、延迟等
- 默认路由（0.0.0.0/0）：匹配所有未知目的地址
- 路由查找过程：最长前缀匹配

**实践任务：**
```bash
# 添加静态路由
ip route add 192.168.100.0/24 via 192.168.1.1 dev eth0

# 删除静态路由
ip route del 192.168.100.0/24

# 查看路由详细信息
ip route show table all

# 路由策略（基于源地址）
ip rule add from 192.168.1.0/24 table lan
```

---

### 2.2 交换机基础

**重点知识点：**
- 二层转发：基于 MAC 地址表
- MAC 地址表学习与老化
- VLAN 原理：逻辑分割广播域
- VLAN ID：1-4094
- Trunk 链路：802.1Q 协议，打标签
- STP 生成树协议：防止环路，选举根桥
- 端口类型：Access、Trunk、Hybrid
- 交换机安全：端口安全、MAC 地址绑定、DHCP Snooping

**实践任务：**
```bash
# 创建 VLAN
ip link add link eth0 name eth0.100 type vlan id 100
ip addr add 192.168.100.1/24 dev eth0.100

# 网桥配置
ip link add br0 type bridge
ip link set eth0 master br0
ip link set eth1 master br0

# 查看 MAC 地址表
bridge fdb show

# 查看 VLAN
ip link show
```

---

### 2.3 常用命令

**重点知识点：**
- `ip link`：网卡 UP/DOWN、MAC 地址修改
- `ip addr`：IP 地址添加/删除
- `ip route`：路由添加/删除/修改
- `bridge`：网桥创建、端口添加
- `vconfig`：VLAN 配置（旧版）

**实践任务：**
- 搭建双网卡网桥环境
- 配置 VLAN 间路由

---

## 阶段三：端口与服务（1-2周）

### 3.1 端口概念

**重点知识点：**
- 端口号范围：0-65535
- 知名端口（0-1023）：HTTP(80), HTTPS(443), SSH(22), FTP(21), Telnet(23), SMTP(25), DNS(53)
- 注册端口（1024-49151）：MySQL(3306), PostgreSQL(5432), Redis(6379), MongoDB(27017)
- 动态端口（49152-65535）：客户端随机端口
- TCP vs UDP：面向连接 vs 无连接，可靠传输 vs 快速交付
- 三次握手：SYN→SYN-ACK→ACK
- 四次挥手：FIN→ACK→FIN→ACK
- 常见服务端口汇总

**实践任务：**
```bash
# 查看所有监听端口
ss -tuln
netstat -tuln

# 查看端口被哪个进程占用
lsof -i :80
ss -tlnp | grep :80

# 端口扫描
nmap -sV -p 1-1000 192.168.1.1
nmap -sT -p- 192.168.1.1  # 全端口扫描

# TCP 连接状态
ss -tan state established
```

---

### 3.2 防火墙基础

**重点知识点：**
- iptables 四表五链：
  - 表：filter（默认）、nat、mangle、raw
  - 链：PREROUTING、INPUT、FORWARD、OUTPUT、POSTROUTING
- 规则匹配条件：协议、源/目的 IP、源/目的端口、接口、状态
- 动作：ACCEPT、DROP、REJECT、LOG、SNAT、DNAT、MASQUERADE
- 连接状态：NEW、ESTABLISHED、RELATED、INVALID
- 常用场景：
  - 允许 SSH（22）
  - 允许 HTTP/HTTPS（80/443）
  - 允许已建立连接
  - 禁止ping
  - 端口转发
- nftables：新版防火墙，语法更简洁

**实践任务：**
```bash
# 查看规则
iptables -L -n -v
iptables -t nat -L -n -v
iptables -L INPUT -n --line-numbers

# 基本规则
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -A INPUT -p icmp --icmp-type echo-request -j DROP
iptables -A INPUT -j DROP

# NAT/端口转发
iptables -t nat -A PREROUTING -p tcp --dport 8080 -j DNAT --to-destination 192.168.1.10:80
iptables -t nat -A POSTROUTING -s 192.168.1.0/24 -j MASQUERADE

# 保存与恢复
iptables-save > /etc/iptables.rules
iptables-restore < /etc/iptables.rules
```

---

### 3.3 常用命令

**重点知识点：**
- `iptables` / `nft`：防火墙管理
- `ss -tuln`：查看监听端口
- `lsof -i`：查看进程占用端口
- `nmap`：端口扫描、操作系统

检测**实践任务：**
- 配置一个安全的防火墙规则
- 实现端口转发
- 使用 nmap 扫描本机开放端口

---

## 阶段四：组网技术（2-3周）

### 4.1 VPN 与隧道

**重点知识点：**
- VPN 类型与原理：
  - PPTP：基于 GRE 隧道，MPPE 加密（已淘汰）
  - L2TP/IPSec：Layer 2 Tunneling Protocol
  - OpenVPN：基于 SSL/TLS，开源跨平台
  - WireGuard：现代高性能 VPN，内核级实现
  - IPSec：IKEv1/IKEv2，隧道模式/传输模式
- 隧道技术：GRE、IPIP、Sit隧道
- 常见组网方案：站点到站点、远程访问

**实践任务：**
```bash
# WireGuard 快速配置（服务端）
wg genkey > privatekey
wg pubkey < privatekey > publickey

# 创建 WireGuard 接口
ip link add wg0 type wireguard
ip addr add 10.0.0.1/24 dev wg0
wg setconf wg0 /path/to/wg0.conf
ip link set wg0 up

# GRE 隧道
ip tunnel add gre1 mode gre remote 203.0.113.2 local 198.51.100.1
ip addr add 10.1.0.1 dev gre1
ip link set gre1 up
```

---

### 4.2 DNS 原理

**重点知识点：**
- DNS 层次结构：根域→顶级域→二级域→子域
- 记录类型：
  - A：域名指向 IPv4
  - AAAA：域名指向 IPv6
  - CNAME：别名
  - MX：邮件服务器
  - TXT：文本记录
  - NS：域名服务器
  - SOA：授权起始
  - PTR：反向解析
- 解析流程：本地缓存→根服务器→顶级域服务器→权威服务器
- 递归查询 vs 迭代查询
- DNS 缓存与 TTL
- DNS 污染与劫持
- Dnsmasq / CoreDNS / Bind

**实践任务：**
```bash
# DNS 查询
dig A example.com
dig AAAA example.com
dig CNAME www.example.com
dig MX example.com
dig TXT example.com
dig +trace example.com  # 全追踪
dig @8.8.8.8 example.com  # 指定 DNS 服务器

# 反向解析
dig -x 93.184.216.34

# 查看 DNS 缓存
systemd-resolve --flush-caches  # systemd-resolved
```

---

### 4.3 DHCP 原理

**重点知识点：**
- DHCP 工作流程（DORA）：
  - Discover：客户端广播发现
  - Offer：服务器响应提供 IP
  - Request：客户端请求使用
  - Ack：服务器确认
- IP 地址租约：默认租期、续租
- DHCP 中继（Relay Agent）：跨网段 DHCP
- DHCP 选项：网关、DNS、租期
- dnsmasq：DHCP + DNS 组合服务

**实践任务：**
```bash
# 查看 DHCP 信息
dhclient -v eth0  # 重新获取 IP
dhclient -r eth0  # 释放 IP

# 查看租约
cat /var/lib/dhcp/dhclient.leases

# dnsmasq 配置示例
# /etc/dnsmasq.conf
# dhcp-range=192.168.1.100,192.168.1.200,12h
# dhcp-option=option:router,192.168.1.1
# dhcp-option=option:dns-server,8.8.8.8
```

---

## 阶段五：网络安全（2-3周）

### 5.1 网络攻击类型

**重点知识点：**
- DDoS 攻击：
  - SYN Flood：半开连接耗尽
  - UDP Flood：流量放大
  - HTTP Flood：应用层攻击
- ARP 欺骗：伪造 MAC 地址
- DNS 劫持：篡改 DNS 响应
- 中间人攻击（MITM）：SSL Stripping
- ARP 防护：静态 ARP 表、ARP 检测
- DDoS 防护：流量清洗、限速、CDN

**实践任务：**
- 使用 nmap 进行漏洞扫描
- 使用 tcpdump 分析异常流量

---

### 5.2 安全防御

**重点知识点：**
- 防火墙最佳实践：
  - 默认拒绝所有
  - 最小化开放端口
  - 限制来源 IP
  - 记录日志
- IDS/IPS：Snort、Suricata
- TLS/SSL：证书、私钥、公钥、CA
- 证书管理：Let's Encrypt、openssl
- fail2ban：自动封禁暴力破解

**实践任务：**
```bash
# TLS 证书生成
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout server.key -out server.crt

# fail2ban 配置
# /etc/fail2ban/jail.local
# [sshd]
# enabled = true
# port = ssh
# filter = sshd
# logpath = /var/log/auth.log
# maxretry = 3
# bantime = 3600
```

---

### 5.3 常用命令

**重点知识点：**
- `tcpdump`：Linux 原生抓包
- `wireshark`：GUI 协议分析器
- `nmap`：安全扫描
- `fail2ban`：入侵检测

**实践任务：**
```bash
# tcpdump 基础
tcpdump -i eth0
tcpdump -i eth0 port 80
tcpdump -i eth0 host 192.168.1.1
tcpdump -i eth0 tcp and port 443
tcpdump -i eth0 -w capture.pcap  # 保存到文件

# 读取 pcap 文件
tcpdump -r capture.pcap
# Wireshark 读取
wireshark capture.pcap

# nmap 扫描
nmap -sS 192.168.1.1  # SYN 扫描
nmap -sV 192.168.1.1  # 版本检测
nmap -O 192.168.1.1  # 操作系统检测
nmap -A 192.168.1.1  # 全面扫描
nmap -p- 192.168.1.1  # 全端口
```

---

## 阶段六：实战与调试（持续）

### 6.1 排查流程

**标准排查步骤：**
1. **物理层**：检查网线、光纤、网卡灯状态
2. **数据链路层**：检查 MAC 地址、交换机端口
3. **网络层**：检查 IP 配置、路由表
4. **传输层**：检查端口状态、服务进程
5. **应用层**：检查服务日志、应用状态
6. **抓包分析**：使用 tcpdump/Wireshark

**常见故障排查：**
- 无法上网：先 ping 网关，再 ping DNS
- 无法访问特定网站：traceroute + DNS 检查
- 连接被拒绝：检查服务是否启动 + 防火墙规则
- 连接超时：检查路由 + 防火墙 + 服务状态

---

### 6.2 调试命令汇总

```bash
# === 网络配置 ===
ip addr show                           # 查看网卡 IP 信息
ip link show                           # 查看网卡状态
ip route show                          # 查看路由表
ip route get 8.8.8.8                   # 查看到目标地址的路由路径
ip neigh show                          # 查看 ARP 表

# === 连通性测试 ===
ping -c 4 8.8.8.8                      # ping 测试
ping -I eth0 8.8.8.8                   # 指定源网卡
traceroute -I 8.8.8.8                   # 路由追踪
mtr 8.8.8.8                            # 实时路由追踪
ping -M do -s 1472 8.8.8.8             # MTU 测试

# === 端口与服务 ===
ss -tuln                               # 查看监听端口
ss -tan state established              # 查看已建立连接
lsof -i :80                            # 查看端口被哪个进程占用
lsof -i tcp                            # 查看所有 TCP 连接
netstat -antp                          # 查看所有连接（进程名）

# === DNS ===
dig +trace example.com                 # DNS 全追踪
nslookup example.com 8.8.8.8          # DNS 查询
host -a example.com                   # 详细 DNS 信息
getent hosts example.com               # 系统 DNS 缓存

# === 防火墙 ===
iptables -L -n -v                      # 查看 iptables 规则
iptables -t nat -L -n -v               # 查看 NAT 规则
iptables -L INPUT --line-numbers      # 带行号查看
ss -tlnp | grep 80                     # 查看 80 端口被谁监听

# === 抓包 ===
tcpdump -i eth0                        # 抓取所有包
tcpdump -i eth0 port 80                # 抓取 HTTP
tcpdump -i eth0 host 192.168.1.1       # 抓取特定主机
tcpdump -i eth0 -w /tmp/capture.pcap   # 保存到文件
tcpdump -r /tmp/capture.pcap           # 读取 pcap 文件

# === 网卡/路由操作 ===
ip link set eth0 up/down               # 启用/禁用网卡
ip addr add 192.168.1.100/24 dev eth0 # 添加 IP
ip route add default via 192.168.1.1  # 添加默认路由
ip neigh add 192.168.1.100 lladdr aa:bb:cc:dd:ee:ff dev eth0  # 静态 ARP
```

---

### 6.3 实践项目

**初级项目：**
- [ ] 搭建私有 VPN（WireGuard/OpenVPN）
- [ ] 配置 iptables 防火墙规则
- [ ] 排查一次网络故障
- [ ] 使用 tcpdump 进行抓包分析

**中级项目：**
- [ ] 搭建 DNS 服务器（Bind/dnsmasq）
- [ ] 搭建 DHCP 服务器
- [ ] 配置 VLAN 间路由
- [ ] 搭建私有 CA，签发 TLS 证书

**高级项目：**
- [ ] 搭建高可用负载均衡（Keepalived + HAProxy）
- [ ] 搭建 CDN 节点
- [ ] 搭建网络监控（Zabbix/Prometheus）
- [ ] 自动化网络配置（Ansible）

---

## 学习资源

### 书籍推荐

**入门级：**
- 《计算机网络：自顶向下方法》（James F. Kurose, Keith W. Ross）- 适合零基础，系统全面
- 《网络是怎么连接的》（户根勤）- 图解形式，易于理解

**进阶级：**
- 《TCP/IP 详解 卷1：协议》（W. Richard Stevens）- 网络协议圣经
- 《TCP/IP 详解 卷2：实现》
- 《TCP/IP 详解 卷3：事务》
- 《Unix 网络编程》（W. Richard Stevens）- 编程方向，但深度够

**运维实战：**
- 《Linux 高性能服务器编程》
- 《高性能网络通信》（廖杰）
- 《CCN/CCIE 路由交换学习指南》

**安全方向：**
- 《Web 安全攻防：渗透测试实战指南》
- 《Kali Linux 渗透测试的艺术》
- 《The Practice of Network Security Monitoring》

---

### 在线学习网站

**视频课程：**
- [Bilibili - 谷粒商城](https://www.bilibili.com/) - 搜索"网络基础"
- [网易云课堂](https://study.163.com/) - 计算机网络课程
- [Coursera - Stanford CS144](https://www.coursera.org/) - 计算机网络

**文档与教程：**
- [Arch Wiki - Network configuration](https://wiki.archlinux.org/) - Linux 网络配置权威
- [Red Hat Enterprise Linux - Networking Guide](https://access.redhat.com/documentation/) - 企业级网络
- [Cisco Networking Academy](https://www.netacad.com/) - 思科认证课程

**工具文档：**
- [iptables 详解](https://www.frozentux.net/iptables-tutorial/)
- [Wireshark User's Guide](https://www.wireshark.org/docs/)
- [nmap Documentation](https://nmap.org/docs.html)

**社区与论坛：**
- [SegmentFault](https://segmentfault.com/) - 技术问答
- [V2EX](https://www.v2ex.com/) - 程序员社区
- [Stack Overflow](https://stackoverflow.com/) - 英文技术问答
- [Server Fault](https://serverfault.com/) - 服务器运维问答

---

### 工具资源

**网络模拟器：**
- [GNS3](https://www.gns3.com/) - 强大的网络模拟器
- [Cisco Packet Tracer](https://www.packettracer.network/) - 思科官方模拟器
- [EVE-NG](https://www.eve-ng.net/) - 网络仿真平台

**在线工具：**
- [Visual Subnet Calculator](https://www.dnswatch.info/) - 子网计算器
- [Wireshark Labs](https://www.wireshark.org/labs/) - Wireshark 实验
- [Speedtest](https://www.speedtest.net/) - 测速

**渗透测试：**
- [Kali Linux](https://www.kali.org/) - 渗透测试发行版
- [Metasploit](https://www.metasploit.com/) - 渗透测试框架
- [OWASP](https://owasp.org/) - Web 安全

---

### 推荐学习顺序

1. **第一周**：网络基础 + 常用命令（阶段一）
2. **第二周**：路由与交换（阶段二）
3. **第三周**：端口与服务 + 防火墙（阶段三）
4. **第四周**：组网技术（阶段四）
5. **第五-六周**：网络安全（阶段五）
6. **持续**：实战调试（阶段六）

---

## 建议

1. **边学边实践**：每学一个知识点，在虚拟机或本地环境动手操作
2. **建立知识图谱**：将各知识点串联，形成整体认知
3. **记录笔记**：使用本目录记录学习笔记和实践心得
4. **定期复盘**：每周回顾所学内容，查漏补缺
5. **看源码**：有余力可以阅读 Linux 内核网络栈源码
6. **参与社区**：在技术社区提问和回答问题，加深理解
