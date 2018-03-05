GPRS调试
====
## 13 版的AT指令集
[13 版的AT指令集（参考）]：（https://wenku.baidu.com/view/cebc5a11195f312b3069a56d.html）


# 1、硬件
1、内核设置好IO串口的驱动，然后通过open打开串口

# 2、软件启动流程

## 1、LinkPowerOff

1、确定好针对GPRS的复位脚，在不能进行对GPRS操作时进行复位

## 2、LinkAtCheck

2、发送AT指令，   告诉GPRS模块需要开始工作
3、发送ATE0，    GPRS 回显开启

## 3、LinkSimCheck

4、AT$MYGMR，    获取通信模块版本信息
5、AT+CPIN?     检测手机SIM卡是否安装好
6、AT$MYCCID     获取SIM卡序列号ccid号

## 4、LinkSimCheck

7、AT+CREG?    网络注册状态查询，可能问题有SIM卡欠费问题等
8、AT+COPS?    查询运营商

## 5、LinkInitSMS

9、AT+CSQ    获取信号强度

## 6、LinkPPPConnect

10、先 AT 命令一次，如若回答有效开始下一步命令

  *  AT+CSQ ：查看信号一波
    
  *  ***（AT$MYNETCON）设置网络连接初始化参数。***

  *  如果有apn，将写入 ： AT$MYNETCON=1,\"APN\",\"%s\"\r + apn 给GPRS模块
    
  *  如若没有则：        AT$MYNETCON=1,\"APN\",\"%s\"\r", "CMNET"

  *  网络连接前各种参数设置：
    
  *  APN：字符串类型
    
  *  USERPWD：“user,passwd”   用户名和密码

  *  CFGT:2  传输时间设置

11、GprsPPPConnect （1）（开始执行连接了）

    GprsPPPConnect写一遍用户名和密码
    
    
    如果是    CDMA 用户名和密码为：card card
    
             GPRS 用户名和密码为：test test
             
    
    sprintf((char *)buf, "AT$MYNETCON=1,\"USERPWD\",\"%s,%s\"\r", pppuser, ppppass);

12、GprsPPPConnect (2) 当传输模式为CHANNEL_DATA_MODE则

#define CHANNEL_DATA_MODE	0	//透明数据传输
#define CHANNEL_CHAR_MODE	1	//非透明数据传输

   发送：

**"AT$MYNETCON=1,\"CFGT\",100\r"

**"AT$MYNETCON=1,\"CFGP\",1460\r"

**"AT$MYNETCON=1,\"AUTH\",1\r"

**"AT$MYNETURC=1\r"

   模块 型号为 M590 时就发送：

**"AT$MYNETACT=1,0\r"   激活网络连接

**"AT$MYNETACT=1,1\r"

13、GprsPPPConnect （3） ，GprsWaitPPPConnect -> GprsReadLocalIP

GprsReadLocalIP：

**发送     ： "AT$MYNETACT?\r" 在网络已激活的情况下，显示本机获取的LOCAL IP

**等待回应 ： "$MYNETACT:"     回应值应为相应的本设备IP

## 7、LinkConnect  开始关键的连接服务器

#define CHANNEL_DATA_MODE	0	//透明数据传输
#define CHANNEL_CHAR_MODE	1	//非透明数据传输

### 7.1 TCP通信时：（AT$MYNETCREATE 为IP访问控制，连接服务器）

   *如果为 DATA_MODE 则传输（"AT$MYNETCREATE=1,0,1,\"%u.%u.%u.%u\",%u\r",IP.ip[0], IP.ip[1], IP.ip[2], IP.ip[3], IP.port）

  *如果为 CHAR_MODE 则传输 （"AT$MYNETSRV=1,1,0,0,\"%u.%u.%u.%u:%u\"\r",IP.ip[0], IP.ip[1], IP.ip[2], IP.ip[3], IP.port)	

### 7.2 UDP通信时：（AT$MYNETSRV 为IP访问控制，连接服务器）

**DATA_MODE：**

  * "AT$MYNETCREATE=1,2,1,\"%u.%u.%u.%u\",%u\r",IP.ip[0], IP.ip[1], IP.ip[2], IP.ip[3], IP.port)*
   
**CHAR_MODE：**

   *"AT$MYNETSRV=1,1,2,0,\"%u.%u.%u.%u:%u\"\r", IP.ip[0], IP.ip[1], IP.ip[2], IP.ip[3], IP.port)*

返回“CONNECT”则为成功

### 7.3 

发送 ： "AT$MYNETCLOSE=1\r" 先关闭连接

循环三次 ： "AT$MYNETOPEN=1\r" 开启服务 回复 "$MYNETOPEN: 1"，则成功推出循环

## LinkLogin

//68 32 00 32 00 68 C9 00 10 02 00 00 02 70 00 00 01 00 4E 16
写入此一长串数据，传输给GPRS










# 3、 















