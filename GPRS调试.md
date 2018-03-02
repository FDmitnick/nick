GPRS调试
====

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
    如果有apn，将写入 ： AT$MYNETCON=1,\"APN\",\"%s\"\r + apn 给GPRS模块
    如若没有则：        AT$MYNETCON=1,\"APN\",\"%s\"\r", "CMNET"



# 3、 
