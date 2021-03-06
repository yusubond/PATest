## 标准库类型vector

标准库类型vector存放的是某种给定类型对象的可变长序列。其所有对象的类型都相同。集合中的每一个对象都有一个与之对应的索引，索引用于访问对象。vector也称为“容器”。

头文件：

`#include<vector>`

### vector操作

```c++
//初始化
vector<T> v               //T为元素的类型
vector<T> v1(n)           //n个重复地执行值初始化的对象
vector<T> v2(n, value)    //n个重复元素，每个值为value
vector<T> v3{a,b,c...}    //包含初始化个数的元素，每个元素被赋予相应的初始值
vector<T> v4(v3)          //v4包含v3的所有副本
                          //注意：圆括号用了构造，花括号用来初始化
//其他操作
push_back()               //向尾部压入数据
v.empty()                 //若不含任何元素，返回真，否则返回假
v.size()                  //元素个数，对象的下标从0开始
v.resize(n)               //改变v的大小
v[n]                      //索引第n个对象，位置从0开始
v.begin()
v.end()
v1 == v2 or v1 != v2      //当且仅当它们的元素数量相同并且对应位置的元素值都相同
<, <=, >, >=              //按字典顺序进行比较
```
