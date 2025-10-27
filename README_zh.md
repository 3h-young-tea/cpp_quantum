# 在 C++ 里使用量子计算

一个极简的 C++ 量子比特模拟器, 适用于 1 和 2 个量子比特.
专为实验和竞赛设计，包括 Microsoft Q# 风格的挑战.

## 初衷

我恨 .net 和 C#.

## 特性

- 单量子比特门: Hadamard、X、Y、Z
- 双量子比特门: Hadamard、X、CNOT
- 量子比特坍缩 (测量)
- 以人类可读的格式 (`std::ostream` 或 `FILE*`) 打印状态

## 快速开始

包含头文件:

```cpp
#include "quantum.hpp"
```

## 编译

```sh
g++ -o main main.cpp -std=c++14 -O2
```

## 许可证

本项目遵循 **GNU Affero 通用公共许可证 v3.0 (AGPLv3)**.
有关完整详情，请参阅[许可证](LICENSE).
