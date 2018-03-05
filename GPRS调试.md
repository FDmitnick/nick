GPRS调试
====

【13 版的AT指令集】： https://wenku.baidu.com/view/cebc5a11195f312b3069a56d.html


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
6、AT$MYCCID     获取SIM卡序列号

## 4、LinkSimCheck

7、AT+CREG?    网络注册状态查询，可能问题有SIM卡欠费问题等
8、AT+COPS?    查询运营商

## 5、LinkInitSMS

9、AT+CSQ    获取信号强度

## 6、LinkPPPConnect

10、先 AT 命令一次，如若回答有效开始下一步命令

    AT+CSQ ：查看信号一波
    

    如果有apn，将写入 ： AT$MYNETCON=1,\"APN\",\"%s\"\r + apn 给GPRS模块
    
    如若没有则：        AT$MYNETCON=1,\"APN\",\"%s\"\r", "CMNET"

    网络连接前各种参数设置：
    
    APN：字符串类型
    
    USERPWD：“user,passwd”   用户名和密码

    CFGT:2  传输时间设置

11、GprsPPPConnect （1）（开始执行连接了）

    GprsPPPConnect写一遍用户名和密码
    
    如果是    CDMA 用户名和密码为：card card
    
             GPRS 用户名和密码为：test test
    
    sprintf((char *)buf, "AT$MYNETCON=1,\"USERPWD\",\"%s,%s\"\r", pppuser, ppppass);

12、GprsPPPConnect (2) 当传输模式为CHANNEL_DATA_MODE则

#define CHANNEL_DATA_MODE	0	//透明数据传输
#define CHANNEL_CHAR_MODE	1	//非透明数据传输

   发送：

"AT$MYNETCON=1,\"CFGT\",100\r"

"AT$MYNETCON=1,\"CFGP\",1460\r"

"AT$MYNETCON=1,\"AUTH\",1\r"

"AT$MYNETURC=1\r"

   模块 型号为 M590 时就发送：

"AT$MYNETACT=1,0\r"

"AT$MYNETACT=1,1\r"

13、GprsPPPConnect （3） ，GprsWaitPPPConnect -> GprsReadLocalIP

GprsReadLocalIP：

发送     ： "AT$MYNETACT?\r"

等待回应 ： "$MYNETACT:"

## 7、LinkConnect  开始关键的连接














# 3、 















