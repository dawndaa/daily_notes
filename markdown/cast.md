---
title: c++强制类型转换
date: 2022-09-18
categories:
- c++_primer
tags:
- c++
---



|   static_cast    |   支持任何不包含底层const的类型转化    |                                                    |
| :--------------: | :------------------------------------: | :------------------------------------------------: |
|   dynamic_cast   |           支持运行时类型识别           |                                                    |
|    const_cast    | 尽支持改变对象的底层const 不能改变类型 | const char* pc; char* p = const_cast<char*> (pc);  |
| reinterpret_cast | 为对象的位模式提供较低层次上的重新解释 | int *ip; char * pc = reinterpret_cast<char*> (ip); |

<!-- more -->

