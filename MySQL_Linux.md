MySQL_Linux相关
====
# 1、环境搭建
## 1.1、安装
  
   Linux 平台上安装 ：
   
   sudo apt-get update
   
   sudo apt-get upgrade
   
   sudo apt-get install mysql-server
   
   
   （安装的过程中会出现需要设定boot用户密码）
   
   
   sudo apt-get install mysql-client 
   
   sudo apt-get install libmysqlclient-dev


## 2.2、安装后相关设置：
  
  1、查看是否启动：（ps -ef | grep mysqld）
 
  2、打开和关闭数据库：
  
     cd /usr/bin
  
     打开：  ./mysqld_safe &
     
     关闭：  ./mysqladmin -u root -p shutdown
     
   3、



