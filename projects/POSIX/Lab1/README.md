# 实验1 进程和进程通信
> DDL: 2017/04/10 24:00

## 进程的创建实验
1. 编译运行如下程序并解释现象
```C
#include <stdio.h>
#include <unistd.h>

int main() {
  int pid_1 = fork();
  printf("**1**\n");

  int pid_2 = fork();
  printf("**2**\n");

  if (pid_1 == 0) {
    int pid_3 = fork();
    printf("**3**\n");
  } else {
    printf("**4**\n");
  }
  return 0;
}
```
现象：能看到2个1，4个2，2个4，4个3，如下
解释：程序一共有3次fork()，正常将产生6个子进程，第一次fork()，两个进程都将会输出1，第二次fork()，四个进程都将会输出2，第三次fork()仅对第一次的子进程（经过第二次fork()有两个），产生四个进程，输出四个3，余下两个将会输出4。
```
**1**
**1**
**2**
**4**
**2**
**4**
**2**
bash-3.2$ **2**
**3**
**3**
**3**
**3**
```

2. 编写一段程序，使用系统调用fork()创建两个子进程。当此程序运行时，在系统中有一个父进程和两个子进程活动。让每一个进程在屏幕上显示一个字符；父进程显示字符“a”；子进程分别显示字符“b”和字符“c”。试观察记录屏幕上的显示结果，并分析原因。

```C
#include <stdio.h>
#include <unistd.h>

int main() {
  int pid_1 = fork();
  if (pid_1 != 0) {
    int pid_2 = fork();
    if (pid_2 != 0) {
      puts("a");
    } else {
      puts("c");  // second sub process print "c"
    }
  } else {
    puts("b");  // first sub process print "b"
  }
}
```
输出如下：
原因：第一次fork()，通过返回值判断，父进程将继续fork()，子进程就会输出`b\n`，同理通过又一次fork()，父进程和第二个子进程分别输出`a\n`和`c\n`。
```
b
a
c
```

3. 下面程序将在屏幕上输出的字符‘X’、数字“1” 和“0”各多少个？为什么？
```C
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int i, a = 0;
  pid_t pid;
  if ((pid = fork())) a = 1;
  for (i = 0; i < 2; i++) {
    printf("X");
  }
  if (pid == 0) printf("%d\n", a);
  return 0;
}
// XXXX0
```
输出：`XXXX0`
解释：一次fork()，两个进程，两个都会循环输出两个X，共计四个X，父进程a被置1，但是仅当检测到为子进程的时候才会输出，于是只有一次a的初始值0.

4. 如果将上面main函数修改如下，则屏幕上输出的字符‘X’、数字“1”和“0”各多少个？为什么？
```C
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int i, a = 0;
  pid_t pid[2];
  for (i = 0; i < 2; i++) {
    if ((pid[i] = fork())) a = 1;
    // fork();
    printf("X");
  }
  if (pid[0] == 0) printf("%d\n", a);
  if (pid[1] == 0) printf("%d\n", a);
  return 0;
} 
```
输出：
```
XXXX1
XX1
bash-3.2$ XX0
0
```
原因：最开始分析的时候我认为是六个，如果我们修改输出`X`为`X\n`看到的就是只有6个，8个是因为复制的时候连输出缓存一起复制了，下面解释6个原因。
循环内部第一次fork()，输出两个X，父进程的a置1，对于这两个进程有(pid[0],pid[1], a)={(+, ?, 1), (0, ? , 0)}
第二次fork()，变为四个进程，输出四个X，原来的两个进程的a置1，共计六个X，
对于现在这四个进程有(pid[0],pid[1], a)={{(+, +, 1), (+, 0, 1)}, {(0, 1 , 1), (0, 0, 0)}}
对于输出a，我们可以发现只要一个pid为0就会输出一次，共计四次，两个1两个0.

## 信号处理实验
(a) 参考2.1.c
(b) 参考2.2.c
执行结果：
`Ctrl-\`和`Ctrl-C`键入不再有效
分析原因：
加了忽略这俩信号的语句。

注1：最开始我没有看到给的例子程序，整个程序都是自己手动写的，所以语句加入的位置和老师希望考察的不一样。
注2：据wikipedia，Ctrl-C发送INT信号（SIGINT），Ctrl-\发送QUIT信号（SIGQUIT），这与实验指导上的描述不符。

## 进程间共享内存实验
> 完成课本第三章的练习3.10的程序

参考3.1.c

## 实现shell的要求
> 完成课本上第三章的项目：实现shell。除此之外满足下面要求：在shell下，按ctrl+C时不会终止shell；

参考4.1.c

注1：编写环境为macOS，以下为gcc -v输出，由于在bash on windows上连编译都会报错（关于头文件和写法警告）所以思考了一下还是把环境贴出来。
```shell
~/workspace/Study/C-Study$ gcc -v
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-inc
lude-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.0.0 (clang-800.0.42.1)
Target: x86_64-apple-darwin16.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctool
chain/usr/bin
```