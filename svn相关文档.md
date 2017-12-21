为了学习SVN服务器是怎么搭建的，我在Ubuntu虚拟机上搭建了一个SVN服务器，可以作为项目开发的版本，记录下来防止自己遗忘，同时可以帮助更多的人。

一：搭建环境
查看Ubuntu系统的版本信息：
      可用cat /proc/version命令、
          uname -a命令与sb_release -a命令。
      Ubuntu：14.04 64位
      SVN：通过apt-get 安装
 
二：搭建步骤
1.卸载svn
利用以下命令查看自己的系统是否已经安装了svn：
svn

上面显示为未安装，如果显示一下信息说明已安装，可以使用以下命令进行卸载：
sudo apt-get remove --purge subversion
(–purge 选项表示彻底删除改软件和相关文件)

2.安装svn
安装前建议更新一下z，再进行安装：
sudo apt-get update
sudo apt-get install subversion

上图显示安装成功。
可以验证一下，通过如下命令：
svn help            //--svn帮助
svn --version       //--svn版本
svnserve --version  //--svn server版本

3.创建SVN版本库
a：创建项目目录和svn仓库：
sudo mkdir  /home/svn
sudo mkdir  /home/svn/repository
sudo chmod -R 777 /home/svn/repository
sudo svnadmin create /home/svn/repository
执行命令后，会在repository下生成以下文件：

对db进行权限设置：
sudo chmod -R 777 db
注：
如果不执行上述命令，会报如下错误：

这是因为我们用的都是sudo权限做的操作，默认只有root用户对文件夹才有写权限，因为root的umask是0022，别的用户没有写权限。
b：设置访问权限：
修改配置文件conf/svnserve.conf
sudo vim /home/svn/repository/conf/svnserve.conf

注：
1.所有的行都必须顶格，否则报错。
c：添加访问用户：
sudo vim /home/svn/repository/conf/passwd 

d：设置用户权限：
sudo vim /home/svn/repository/conf/authz

对以上进行解释：
admin = wang //用户王属于admin权限组
@admin = rw //admin权限组的权限是读和写
* = r 所有的组都具有读权限
 
三：测试SVN服务器
A：启动服务器
svnserve -d -r /home/svn [--listen-host 192.168.1.16]
注：
-d：表示在后台运行
-r：指定服务器的根目录
这样访问服务器时就可以直接用”svn://服务器ip/repository”来访问了。
如果服务器有多ip的话–listen-host来指定监听的ip地址.
我们可以在svn客户端中通过svn://192.168.1.16来访问svn服务器
可以用如下命令查看svnserve是否已经运行：
ps aux | grep svnserve

可以看到svn服务器已经在后台运行了。
B：停止服务器
killall svnserve
ps aux | grep svnserve

可以看到svn服务器已经关了。
 
四：访问SVN服务器
可以通过TortoiseSVN客户端访问SVN服务器：
在本地新建一个文件夹，进入文件夹，使用TortoeseSVN访问之前创建的SVN服务器仓库。

进入svn仓库后，可以试着提交一个文件夹：
svn://192.168.2.106/repository

点击确定或者OK后会提示你输入svn的用户名和密码：


到此就完成了。
 
Ubuntu 14.04 下搭建SVN服务器 SVN://  http://www.linuxidc.com/Linux/2015-01/111956.htm

CentOS 6.2 SVN搭建 (YUM安装) http://www.linuxidc.com/Linux/2013-10/91903.htm

CentOS 6.5部署Apache+SVN  http://www.linuxidc.com/Linux/2013-12/94315.htm

Apache+SVN搭建SVN服务器 http://www.linuxidc.com/Linux/2013-03/81379.htm

Windows下SVN服务器搭建和使用 + 客户端重新设置密码 http://www.linuxidc.com/Linux/2013-05/85189p5.htm

Ubuntu Server 12.04 安装 SVN 并迁移 Virtual SVN数据 http://www.linuxidc.com/Linux/2013-05/84695.htm

Ubuntu Server搭建SVN服务以及迁移方法 http://www.linuxidc.com/Linux/2013-05/84693.htm

Subversion (SVN) 的详细介绍：请点这里
Subversion (SVN) 的下载地址：请点这里

更多Ubuntu相关信息见Ubuntu 专题页面 http://www.linuxidc.com/topicnews.aspx?tid=2

本文永久更新链接地址：http://www.linuxidc.com/Linux/2016-08/133961.htm
