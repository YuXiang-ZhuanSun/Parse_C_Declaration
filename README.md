# 项目描述

本项目用于解析复杂的c/c++定义声明。

* 目前支持数组，指针，无参数的函数的组合



# 例子

输入：

```
int *foo[3];
```

输出：

```
Variable foo is an array of 3 points to a int.
```



输入：

```
int (*(*vtable)[])();
```

输出：

```
Variable vtable is a point to an array of points to a function that returns a int.
```



输入：

```
int *(*f[3])();
```

输出：

```
Variable f is an array of 3 points to a function that returns a point to a int.
```



# 参考文献

* [c语言如何判断一个声明到底是函数还是指针还是数组还是什么东西？-邱昊宇的回答-知乎](https://www.zhihu.com/question/439224121/answer/1676599824)
* [在线c/c++定义解析器](https://cdecl.org/)

