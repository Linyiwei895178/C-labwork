在下无才，REAME.md是Cline的杰作

# BankAccount 项目使用说明

// 此README由Cline提供，自己手写的项目，但是发现跑不起来，没有成功，实在是没招了，最后选择使用Cline排查Bug，并且生成对应的README.md文件，给CLine夯爆了

## 项目概述
这是一个银行账户管理系统，使用C++和CMake构建工具开发。项目包含账户管理、日期处理、交易记录等功能。

## CMake配置和编译步骤

### 1. 准备工作
确保系统已安装：
- CMake (版本3.10或更高)
- C++编译器 (如Visual Studio编译器或GCC)

### 2. 配置项目
在项目根目录下执行以下命令：

```bash
# 进入项目目录
cd BankAccount

# 创建build目录（用于存放构建文件）
mkdir build

# 进入build目录并配置项目
cd build
cmake ..

# 或者在Windows上使用：
# cmake .. -G "Visual Studio 16 2019"
```

### 3. 编译项目
```bash
# 编译项目
cmake --build .

# 或者在Windows上使用Visual Studio编译器：
# msbuild bank.sln /p:Configuration=Release
```

### 4. 运行程序
编译完成后，可在build目录中找到可执行文件：

```bash
# Windows系统
.\Debug\bank.exe

# Linux/macOS系统
./bank
```

## 项目结构说明

```
BankAccount/
├── CMakeLists.txt     # CMake配置文件
├── date.h/cpp         # 日期类定义和实现
├── account.h/cpp      # 账户类定义和实现
├── accumulator.h      # 累积计算器
├── main.cpp           # 主程序入口
└── build/             # 构建目录（自动生成）
```

## 使用方法

程序启动后会显示命令提示符，支持以下命令：
- `a` - 添加账户 (a s|c id rate|credit rate fee)
- `d` - 存款 (d index amount description)
- `w` - 取款 (w index amount description)
- `s` - 显示所有账户
- `c` - 指定日期 (c day)
- `n` - 下一个月
- `q` - 查询交易记录 (q date1 date2)
- `e` - 退出程序

## 示例命令序列

1. 添加储蓄账户：`a s 123456 0.05`
2. 存款：`d 0 1000 salary`
3. 取款：`w 0 200 shopping`
4. 查询记录：`q 2008-11-01 2008-11-30`