# 第8章 IO库

## 8.1 IO类

将IO类扩展，有多样性，在多个领域都可以使用

我们的输入除了普通的char外，还有 w_char宽字符

不只是从控制台(console)来，还有可能从文件、内存中的string中来

![image-20230828201049009](/home/username/.config/Typora/typora-user-images/image-20230828201049009.png)

宽字符版本的类型和函数以一个 w 开始 ，例如wcin、wcout、wcerr 分别对应 cin、cout和cerr的宽字符版对象

和普通char 版本的类型定义在同一个头文件中



刚说多个领域，怎么实现？继承机制
我们可以把一个派生类对象当作其基类对象来使用

比如我们isstream有getline,那么fstream和sstream也有，效果一模一样，只不过是输入的来源不同

还有>> 



IO对象无拷贝赋值操作

```cpp
ofstream out1,out2;
out1 = out2;    //错误
ofstream print(ofstream); //错误
out2 = print(out2);  //错误
```

第一个把out2给out1,第二个把ofstream初始化给print,第三个把需要拷贝或者初始化

可能是因为必须是流唯一的

同样的道理，形参意味着要把实参复制给它，等于又多了一份；传返回值的时候也是相当于在return那里拷贝了一下。



流有条件状态，根据其我们可以知道流的状态（这不废话吗）

fail和good是总体判断，eof是具体，表示到末尾