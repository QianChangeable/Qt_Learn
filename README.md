# Qt_Learn

Qt 5 Widgets 学习练习：窗口、布局、信号与槽。

## 环境

- Windows
- Qt 5.15.2（MinGW）
- CMake + Ninja

## 已练习内容

- `QWidget` / `QPushButton` / `QLineEdit`
- 嵌套 layout 与 stretch（1:2:1 居中）
- `MainWindow` 拆分（`.h` / `.cpp`）与 `Q_OBJECT`
- 信号与槽：无参、带参、自定义 `signals` + `emit`

## 构建

```powershell
cmake -B build -G Ninja -DCMAKE_PREFIX_PATH=E:/Qt/5.15.2/mingw81_64
cmake --build build
```

（按本机 Qt 安装路径修改 `CMAKE_PREFIX_PATH`。）

运行生成的 `build/HelloQt.exe`（需能加载对应 Qt DLL）。

## 说明

个人学习笔记配套代码，结构从简，便于对照博客逐步改。
