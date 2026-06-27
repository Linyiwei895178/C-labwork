# BankAccount 项目使用说明

## 项目概述

这是一个银行账户管理系统，使用C++和CMake构建工具开发。项目包含账户管理、日期处理、交易记录等功能。

### 功能特性

- **储蓄账户 (SavingsAccount)**：支持存款、取款、计算利息
- **信用账户 (CreditAccount)**：支持存款、取款、计算利息、信用额度管理
- **日期管理**：支持日期计算、月份切换
- **交易记录**：记录所有账户的交易历史
- **查询功能**：支持按日期范围查询交易记录

---

## CMake 编译教程

### 1. 准备工作

确保系统已安装：

- **CMake** (版本3.10或更高)
- **C++编译器** (Visual Studio 2019/2022 或 GCC)

### 2. 配置项目

```powershell
# 进入项目目录
cd e:\CS\高等程序设计\lab\lab14\BankAccount

# 创建build目录（用于存放构建文件）
mkdir build

# 进入build目录
cd build

# 配置项目（生成构建系统文件）
cmake ..
```

### 3. 编译项目

```powershell
# 编译项目（生成可执行文件）
cmake --build .
```

### 4. 运行程序

```powershell
# 运行程序
.\Debug\bank.exe
```

---

## Makefile 编译教程

### 1. 准备工作

确保系统已安装：

- **make** (通常随MinGW或GCC一起安装)
- **g++** (GNU C++编译器)

### 2. 编译项目

```powershell
# 进入项目目录
cd e:\CS\高等程序设计\lab\lab14\BankAccount

# 使用make编译
make
```

### 3. 运行程序

```powershell
# 运行程序
./bank
```

---

## 项目结构说明

```
BankAccount/
├── CMakeLists.txt       # CMake配置文件
├── Makefile             # Makefile配置文件
├── date.h               # 日期类头文件
├── date.cpp             # 日期类实现文件
├── account.h            # 账户类头文件
├── account.cpp          # 账户类实现文件
├── accumulator.h        # 累积计算器头文件
├── main.cpp             # 主程序入口
├── commands.txt         # 命令记录文件
├── test_savings.txt     # 储蓄账户测试用例
├── test_credit.txt      # 信用账户测试用例
├── test_mixed.txt       # 混合账户测试用例
└── build/               # 构建目录（自动生成）
```

---

## 使用方法

### 命令说明

程序启动后会显示命令提示符，支持以下命令：

| 命令 | 格式 | 说明 |
|------|------|------|
| `a` | `a s id rate` | 添加储蓄账户 (id: 账户ID, rate: 利率) |
| `a` | `a c id credit rate fee` | 添加信用账户 (id: 账户ID, credit: 信用额度, rate: 利率, fee: 手续费) |
| `d` | `d index amount description` | 存款 (index: 账户索引, amount: 金额, description: 描述) |
| `w` | `w index amount description` | 取款 (index: 账户索引, amount: 金额, description: 描述) |
| `s` | `s` | 显示所有账户 |
| `c` | `c day` | 指定日期 (day: 日期，必须大于当前日期) |
| `n` | `n` | 进入下一个月 |
| `q` | `q date1 date2` | 查询交易记录 (date1: 开始日期, date2: 结束日期) |
| `e` | `e` | 退出程序 |

### 示例命令序列

#### 示例1：储蓄账户操作

```
a s 123456 0.05
d 0 1000 salary
w 0 200 shopping
s
n
s
e
```

#### 示例2：信用账户操作

```
a c 987654 10000 0.0001 100
d 0 5000 deposit
w 0 3000 withdraw
s
n
s
e
```

#### 示例3：混合账户操作

```
a s savings 0.05
a c credit 5000 0.0002 200
d 0 10000 savings deposit
d 1 2000 credit deposit
w 0 3000 savings withdraw
s
n
s
e
```

---

## 测试用例

项目提供了三个测试用例文件，可用于快速测试程序功能：

### 1. 储蓄账户测试

```powershell
Get-Content test_savings.txt | .\build\Debug\bank.exe
```

### 2. 信用账户测试

```powershell
Get-Content test_credit.txt | .\build\Debug\bank.exe
```

### 3. 混合账户测试

```powershell
Get-Content test_mixed.txt | .\build\Debug\bank.exe
```

---

## 常见问题

### 1. CMake 配置失败

**问题**：`cmake ..` 命令失败

**解决方案**：
- 确保已安装 CMake
- 检查 CMake 是否添加到系统 PATH
- 尝试使用完整路径运行 CMake

### 2. 编译错误

**问题**：编译时出现错误

**解决方案**：
- 确保所有源文件都在正确的位置
- 检查 C++ 编译器是否正确安装
- 删除 build 目录后重新配置

### 3. 程序运行异常

**问题**：程序运行时出现异常

**解决方案**：
- 检查输入格式是否正确
- 确保日期格式为 "year-month-day"
- 查看 commands.txt 文件中的命令记录

---

## 代码修复记录

### 1. date.h

**问题**：运算符重载声明错误

**修复**：将 `operator<<` 的声明从 `>>` 改为 `<<`

### 2. date.cpp

**问题**：输出流使用错误

**修复**：将 `cout` 改为 `out` 参数

### 3. account.h

**问题**：拼写错误

**修复**：
- `amouint` → `amount`
- `dae` → `date`

### 4. account.cpp

**问题**：多个逻辑错误

**修复**：
- `Account::show`：使用 `out` 参数而不是 `cout`
- `CreditAccount::deposit`：使用 `getBalance()` 而不是 `getDebt()`
- `CreditAccount::settle`：使用 `getBalance()` 而不是 `getDebt()`

### 5. main.cpp

**问题**：多个逻辑错误

**修复**：
- `case 'a'`：使用 `str` 流而不是 `cin`
- `case 'd'`：使用 `str` 流而不是 `cin`
- `case 'w'`：使用 `str` 流而不是 `cin`
- `case 'c'`：添加 `break` 语句
- `case 'n'`：添加 `break` 语句
- 无效命令提示：使用 `default` case

---

## 技术细节

### 类结构

- **Date**：日期类，支持日期计算和格式化输出
- **Account**：账户基类，支持存款、取款、利息计算
- **SavingsAccount**：储蓄账户类，继承自 Account
- **CreditAccount**：信用账户类，继承自 Account
- **Accumulator**：累积计算器，用于计算日均余额

### 日期格式

程序支持以下日期格式：

- 输入格式：`year-month-day` (例如：`2008-11-01`)
- 输出格式：`year-month-day` (例如：`2008-11-1`)

### 交易记录

所有交易都会记录到 `commands.txt` 文件中，方便后续查询和审计。