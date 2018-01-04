一、新建openwrt 及 应用程序

1、拿到openwrt先进行make -j4 V=s（-j4是通过四个线程编译）

2、编译通过后再make menuconfig 进行对需要的内容进行选择

3、在/openwrt/package路径下添加所需要的应用程序

4、/openwrt/package/test的应用程序中由（src）(Makefile)组成，src中还有相关的Makefile文件

5、Makefile中不能有多余的空格，line后不能有空格，命令需要顶格，非命令则需要加一个tab or 四个space

6、test/Makefile中的库的路径尽量使用动态库的路径，test/src/makefile则可以使用静态库和动态库，要确保库能够被调用

7、在编译非MIPS文件时可在test文件中make查看文件本身是否存在问题（file test 命令可查看是否为MIPS）

8、编译之前，删除之前可能产生的相关.o文件（重点~）
