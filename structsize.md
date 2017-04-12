## 结构体字节对齐

### 1.基本数据类型所占字节数**

不同位数的编译器对应的基本数据类型所占字节数是不同的。**指针类型直接由系统位数决定**。32位系统的寻址空间是2^32，即32bit，也就是4个字节。64位系统的寻址空间是2^64，即64bit，也就是8个字节。**unsigned x类型与x类型具有同样的字节数，只是数据范围不同**。

除16系统(int为2个字节)外，int类型一律为4个字节。

long类型至少为4个字节，或与系统最大位数相同。

long long类型为8个字节，float类型为4个字节，double类型为8个字节。

|基本数据类型|16系统字节数|32系统字节数|64系统字节数|
|:---|:---:|:---:|:---:|
|bool|1|1|1|
|char|1|1|1|
|char*|2|4|8|
|short int|2|2|2|
|int|2|4|4|
|unsigned int|2|4|4|
|long|4|4|8|
|unsigned long|4|4|8|
|long long|8|8|8|
|float|4|4|4|
|double|8|8|8|

### 2.字节对齐

特定类型的变量只能从特定的地址开始访问，因此各个变量在系统的地址空间上需要按一定的规则排列，这就是内存对齐问题。

结构体字节对齐的原则：

1）结构体变量的首地址能够被占据最大字节数的数据类型成员的大小整除。  
2）结构体每个成员相对结构体首地址的偏移量都是每个成员本身大小的整数倍，如有需要可填充字节。  
3）结构体变量所占空间的大小，必定是所占字节数最大的数据类型(作为对齐基准)的整数倍。

注意：  
**变量的声明的顺序影响结构体变量字节的大小**。原因是，内存按照变量的声明顺序依次存储数据，需要满足内存对齐。  
**静态数据成员的存放在静态数据区，与结构体实例的存放无关**。sizeof计算结构体中静态数据成员。  
**以占据最大字节数的数据类型成员作为字节对齐基准**。结构体变量所占空间的大小，是基准的整数倍。

空结构体在C++中占1个字节，C中占0个字节。

另外，int a:2;可以限定变量占据的bit数。