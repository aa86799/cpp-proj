- istream
- ostream
- cin wcin(操作宽字符 wchar_t类型的数据)
- cout wcout
- cerr wcerr
- <<  从 ostream 中写入输出数据
- \>> 从 istream 中读取输入数据
- getline() 从给定 istream 中读取一行

头文件
- \<iostream> 操作 char
> istream wistream   
> ostream wostream  
> iostream wiostream 读写流 
- \<fstream> 操作文件
> ifstream wifstream  
> ofstream wofstream  
> fstream wfstream
- \<sstream>  操作string
> istringstream wistringstream 从 string 读取  
> ostringstream wostringstream 向 string 写入  
> stringstream wstringstream 读写 string

w 开头的，就是操作 wchar_t 的数据的。

不能对 IO 对象赋值
```cpp
ofstream o1, o2;
o1 = o2; // 错误
o2 = func(o1); // 错误，不能拷贝IO对象
```
由于不能拷贝IO 对象，所以流类型就不能用作函数形参。
通常以引用方式传递。
读写流会改变其状态，因此引用不能是 const 的。

条件状态
strm 是一种 io 类型。
strm::iostate
strm::badbit 流崩溃
strm::failbit 操作失败
strm::eofbit 到达文件末
strm::goodbit 正常
s.eof() 到达文件末，返回 true
s.fail() 
s.bad()
s.good()
s.clear() 将流的所有状态复位
s.clear(iostate-flags) 将对应状态复位
s.setstate(iostate-flags) 设置对应状态
s.rdstate() 返回流的当前条件状态

刷新写入输出流缓冲区
- endl  向缓冲区插入一个换行符，再刷新
- flush 刷新缓冲区，但不输出额外字符
- ends  向缓冲区插入一个空字符，再刷新
- unitbuf 在每次写操作后，都刷新(flush)。
- nounitbuf 重置
```cpp
cout << unitbuf;
cout << nounitbuf; // 重置，回到默认的正常缓冲刷新方式
```

文件流  
特有函数：  
- fstream fs; 创建未绑定的文件流  
- fstream fs(s); 打开名为s (s 可以是 string 或 c 风格的字符串指针) 文件
- fstream fs(s, mode); 按指定 mode 打开。  
  mode: in, out, app(定位到文件末尾后追加), ate(打开文件立即定位到文件末尾), trunc(截断文件), binary(二进制).  
  限制：  
  out 被设定时，才能设定为 trunc。
  app 隐含了 out。不能和 trunc 同用。
  out 隐含了 trunc，若想保留原内容，就用 app追加。
  ate 和 binary 可以和其它任何模式组合。
- fs.open(s); // 隐含 mode 为 out | trunc
- fs.close();
- fs.is_open(); 是否成功打开且还未关闭

string 流
- stringtream st;
- stringtream  st(s); 保存一个 string s 拷贝
- st.str(); 返回 string的拷贝
- st.str(s); 将 string s 拷贝到 st
