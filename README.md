# HNUCryptographySystem
密码学加解密综合服务系统课程实验，包括仿射、流密码、DES、RSA、DH协议及其增强设计

Second文件夹是客户端程序的源代码，选择.pro文件后右键打开，之后在Qt中需选择MinGW(32bit or 64bit 可能无所谓，我用的是32bit)；
dh_server文件夹是服务器程序的源代码，选择.pro文件后操作同上；
MyCrypto文件夹是加密算法文件的源码，不包括最终构建生成的MyCrypto.dll；

Client文件夹是打包生成的客户端程序，双击其中的Second.exe即可运行；
Server文件夹是打包生成的服务器端程序，双击其中的dh_server.exe即可运行；

注意：
	1.手动编译源码生成dll和调用dll生成可执行程序时，三个project均需选择release版本而非debug版本；
	2.在调用dll生成客户端可执行程序时，需注意Second.pro文件内部第18行“LIBS += ”后面的路径是否与你本机匹配，建议最好不要有中文路径；
	3.经过上述两步，生成的exe可执行程序并不能双击直接运行，需在开始菜单中找到Qt文件夹，打开对应MinGW版本的命令行工具，
	然后cd进入到第一步编译完成得到的"*MinGW-32bit-Release\release"文件夹下，或者单独拷贝出release(小写的r)文件夹到另一个路径后，再用cd进入release文件夹；
	4.紧接着使用windeployqt Second.exe即可得到最终的可执行程序Second.exe
		（如果打开它出现找不到MyCrypto.dll，建议手动从第一步生成的MyCrypto的Release\release文件夹内拷贝该dll文件到Second.exe的所在目录下）
	5.生成可执行的dh_server.exe与第三四步过程类似,只是不需要第二步的调用dll。
