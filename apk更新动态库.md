
此文件已经亲测可成，


一、首先查看apk的相关组成，来了解应该从何处出手：

http://blog.csdn.net/bupt073114/article/details/42298337



二、查看签名文件 META-INF 其文件中对应的内容：

http://www.blogfshare.com/android-apk-sign.html



三、替换的相关操作：（必看）

http://blog.csdn.net/loushuai/article/details/48858483

Android的apk文件实际上就是zip文件。通过解压软件解压后可以看到apk文件内部的内容，并且对其中的文件进行修改或更新。但是如果直接将修改后的


1. apktool官网：

http://ibotpeaches.github.io/Apktool/

下载apktool.jar & apktool.bat (for windows).


2. Windows将其拷贝至C://Windows (不是必须的, 能找到就行), linux拷贝至/usr/local/bin.


3. 解压apk包:

$ apktool d test.apk

解包后会在当前目录生成与apk同名文件夹.


4. 更新解压后的so文件.如果目录下有build文件夹的话，最好将其中的apk目录删掉.


5. 重新打包:

$ apktool b test

打包文件在apk文件夹中的dist目录下.


6.*** 生成签名证书(只需生成一次)
运行：
keytool –genkey –alias android123.keystore –keyalg RSA –validity 20000 –keystore android123.keystore
/*解释：keytool工具是Java JDK自带的证书工具

-genkey参数表示：要生成一个证书（版权、身份识别的安全证书）

-alias参数表示：证书有别名，-alias mine.keystore表示证书别名为:mine

-keyalg RSA表示加密类型，RSA表示需要加密，以防止别人盗取

-validity 20000表示有效时间20000天( K3

-keystore mine123.keystore表示要生成的证书名称为mine123

*/

输入完回车后屏幕显示：: a4 x: O. i5 I

输入keystore密码：[密码不回显]（一般建议使用20位，最好记下来后面还要用）

再次输入新密码：[密码不回显]( o' ^$ _( F( K& I0

您的名字与姓氏是什么？

[Unknown]：lili# E# C/ Z! O) I; K6 r7 M-
您的组织单位名称是什么？

[Unknown]：snoopy' |3 v& I! _/ l
您的组织名称是什么？

[Unknown]：snoopy team
您所在的城市或区域名称是什么？) L# V' |. E0 f; {
[Unknown]：beijing

您所在的州或省份名称是什么？
[Unknown]：beijing

该单位的两字母国家代码是什么
[Unknown]：CN- m. ~1 W. i0

CN=lili, U=snoopy, O=snoopy team, L=beijing, ST=beijing, C=CN正确吗？
[否]：Y

输入< mine.keystore>的主密码
（如果和keystore密码相同，按回车）：

7. 对重新打包后的apk文件进行签名：
jarsigner -verbose -keystore android123.keystore -signedjar new.apk old.apk android123.keystore
/*解释：* ^, {& k1 Z. M* P/ M+ K5 n5 hjarsigner是Java的签名工具# K8 ~% s# Y. @6 P

-verbose参数表示：显示出签名详细信息

-keystore表示使用当前目录中的mine123.keystore签名证书文件。

-new.apk表示签名后生成的APK名称，% v! a7 e2 v4 W# ]; Gold.apk表示未签名的APK Android软件， mine.keystore表示别名

*/



