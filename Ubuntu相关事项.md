Ubuntu相关事项：

一、重装系统：
U盘插入时：
选择usb开头的文件选择后进行安装
安装时选择  sda/adb 表达是否要格式化U盘分区，不格式化则会出现双启动，双启动很卡，所以格式化

系统安装完成之后：

sudo apt-get install update(开始install之前先update)
sudo apt-get install vim
sudo apt-get install 


源库的路径，及相关更换地址：

http://www.linuxidc.com/Linux/2017-01/139458.htm


github安装文档：

http://www.linuxidc.com/Linux/2016-08/133961.htm







二、无法与PC端共享路径：

1、选择左上角虚拟机->安装VMware Tools（若出现：无法手动启动VMware Tools安装）

2、（参照下文在添加虚拟机时两个DVD都选择linux.iso，如果开始出现失败，重启一到两次）
https://jingyan.baidu.com/article/3c48dd348c4504e10ae35810.html





三、Samba安装
1、安装

#sudo apt-get install samba
#sudo apt-get install smbclient

2、启动或关闭

启动Samba服务器只需执行如下命令：
#sudo /etc/init.d/samba start

关闭Samba服务器：
#sudo /etc/init.d/samba stop

重新启动Samba服务器：
#sudo /etc/init.d/samba restart


3、修改

sudo cp /etc/samba/smb.conf /etc/samba/smb.conf.bak       //修改配置文件之前最好做个备份
#vim /etc/samba/smb.conf   

将文件中的内容做如下相应修改：
#security=user 后面添加：
security=share
在文件结尾添加如下行：
[share]
comment=this is Linux share directory
path=/home/myth/share
public=yes
writable=yes

保存退出，启动Samba服务：
#/etc/init.d/samba start

最后没有完成可以看：http://www.linuxidc.com/Linux/2011-07/38996.htm







四、在Ubuntu16.04中安装nfs并使用
http://blog.csdn.net/csdn_duomaomao/article/details/77822883
























