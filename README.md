**任务描述:** 要求开发编写一个按键控制LED灯亮度的程序。使用 ZigBee 模块（黑板），独立新建工程并编写、编译代码，实现以下任务要求。

步骤1、主板一上电，所有LED灯不亮；

步骤2、当第1次按下按键SW1后，所有LED灯微亮（此时亮度不是最亮的状态），串口发送信息“现在LED灯处于微亮状态！”(只发送一次)；

步骤3、当第2次按下按键SW1后，用 ZigBee 模块上的4 盏灯(D4、D3、D6、D5)从左到右分别代表二进制的高位至低位(四字，1 亮，0灭)，通过二进制显示的方式显示0x0\~0xF，每1秒进行加1显示，具有循环效果并且串口发送信息“现在LED灯处于显示数据状态！” (只发送一次)；

步骤4、当第3次按下按键后，所有LED灯不亮，串口发送信息“现在LED灯处于熄灭状态!” (只发送一次)；

步骤5、重复运行步骤2至4；

步骤6、当按键按下1秒后还没有抬起按键，则出现流水灯效果。

**设备列表：**

1.  ZigBee模块（黑板）1块+（电源线）
2.  USB转串口线1条
3.  CC Debugger烧写器1个

**注意事项：**要求微亮和显示数据时的两次状态，两次的亮度要不一样，肉眼要能够明显分辨的出，否则当作微亮失败处理。

**任务要求：**

在工程源码目录“C:\\JoyWork\\01\\work\\”下创建文件夹Task，在IAR中创建工程，工程名字为“Task+准考证号后12位”，保存到“Task” 文件夹中，把考试资源目录下的“4.ZigBee基础开发”文件夹中的“test.c”文件添加到IAR工程中，配置好工程选项参数，确保工程编译成功。（4分）。阅读“test.c”的代码并在合适的位置添加代码（也可以不参考提供的“test.c”而自行实现所有的代码），实现以下功能：

1、ZigBee模块上电后，所有的LED灯不亮。（2分）

2、当按一下按键，所有的LED灯处于微亮状态（使用延时函数，使LED高电平时间较短，低电平时间较长），并串口发送“现在LED灯处于微亮状态！”，使用串口调试工具接收信息并截图保存到“图集.docx”中8.png处。（9分）

3、当再一次按下按键，先让所有的LED灯不亮，使能定时器1中断，使用LED灯实现每1秒加1显示0x0\~0xF，并串口发送“现在LED灯处于显示数据状态！” ，使用串口调试工具接收信息并截图保存到“图集.docx”中9.png处。（8分）

4、第三次按下按键后，键值清零，禁止定时器1中断，串口发送“现在LED灯处于熄灭状态！”，
使用串口调试工具接收信息并截图保存到“图集.docx”中10.png处。（7分）

5、串口通信要求使用串口0的备用位置1: P0_2 (RX), P0_3(TX)，波特率为115200，8位数据位，1位停止位，无校验位，无流控。（4分）

6、使用定时器实现0.5秒的定时时间。定时器1采用32MHz系统时钟、128分频、正计数/倒计数模式、比较值T1CC0为62500，并开启总中断。（4分）

7、实现按键按下不抬起，1秒后出现流水灯效果，即按照D4-\>D3-\>D6-\>D5的顺序,每隔1秒依次点亮一个灯,当D5灯灭掉之后，重新按照D4-\>D3-\>D6-\>D5的顺序依次点亮，后面就是一直按照这样的流程循环进行。（9分）

8、**考试时间截止后，确保“图集.docx”和源码工程文件已保存后， 对work文件夹进行压缩，点击“上传文件”将压缩后的“work.zip”上传至服务器指定目录。**
