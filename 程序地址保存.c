国网集中器：
驱动地址保存：

make ARCH=arm CROSS_COMPILE=../../host/usr/bin/arm-linux- modules
linux-2.6.39:驱动编译命令

\\10.1.10.194\yif\at91\buildroot\output\build\linux-2.6.39\drivers\char
驱动代码放置目录

\\10.1.10.194\yif\at91\driver
demo
	
\\10.1.10.194\yif\at91\buildroot\output\build\linux-2.6.39 
编译目录，在内核的根目录下编译

\\10.1.10.194\yif\at91\buildroot\output\build\uboot-2016.09.01\drivers 参考







国网集中器：
应用程序地址保存：
\\10.1.10.194\yif\at91\buildroot\package\demo_app 
可执行程序 或.so，编译位置

\\10.1.10.194\yif\at91\buildroot\output\build\demo_app-master
完成后代码程序放置位置

\\10.1.10.194\yif\at91\buildroot\dl  demo_app-master.tar.gz
放置压缩包的位置

yif@yif-H81M-DS2:/home/yifan/at91/buildroot$ make demo_app-rebuild  
编译demo_app，测试程序编写

\\10.1.10.194\yif\at91\buildroot\output\build\demo_app-master 
调试，测试程序





国网集中器：
nfs挂载
mount -t nfs -o nolock 10.1.10.194:/home/yifan/nfs /tmp
mount -t nfs -o nolock 10.1.10.194:/home/luyou/nfs /tmp

将服务器10.1.10.194:/home/yifan/nfs mount到/tmp下


zailing集中器：
代码路径：
svn://10.1.10.194/网关/Linux APP程序/LGW-NPW01A










智能网关：
代码路径
\\10.1.10.194\luyou\openwrt_15.05\openwrtzmz\openwrt

.bin路径：
/build_dir/target-mipsel_24kec+dsp_uClibc-0.9.33.2/jzqapp/debug/bin/myapp
代码路径：
openwrt_15.05\openwrtzmz\openwrt\package\jzqapp

运行代码：
make 
注意事项：
删除home_gateway进程









Ubuntu注意事项：

重装系统：
开机选择  sda/adb				表达是否要格式化U盘分区，不格式化则会出现双启动，双启动很卡，所以格式化
  



























