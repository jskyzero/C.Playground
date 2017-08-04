---
layout:     post
title:      "C_Code"
date:       2017-02-01
tags:
    - Code
    - Algorithm
    - C
    - Todo
categories:
    - Code
---

一些常用的算法，C描述
# C_Code

```C
#include<stdio.h>



int com(int m,int n)//m中取n个
{
    int i,j,sum=1;
    for (i=m,j=0;j<n;j++,i--)
    {
        sum=sum*i/(j+1);
    }
    return sum;
}
int main()
{
    int i;
    i=com(5,3);
    printf("%d",i);
    return 0;
}

```

```c
int GCD(int a, int b) { return (0 == b) ? a :GCD(b,a%b);}
```

```C
int getSum(int a, int b) { return !(a)?b:getSum((a&b)<<1,a^b);}
```

