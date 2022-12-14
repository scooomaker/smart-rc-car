# smart-rc-car: 一个简单的遥控车项目

### 已于2019年结束更新
>本项目使用双nrf24l01进行遥控，自行diy小车开发板(Atmega2560芯片)和遥控器PCB，减少体积，可作为Arduino Mega2560 平替。
>Expansion-board为开发板扩展板，（未完成）。集成所有电机驱动模块，nrf24l01收发，蓝牙，wifi，超声波，显示屏，SD卡等方便后期使用。

![Keyshot](/3.Keyshot/Mega2560-NEW-E.10.jpg)

##### 实现功能
基本超声波避障，nrf24l01收发遥控，电机调速，液晶屏显示，数据记录，麦克纳姆轮全向行驶等。

##### 关于遥控器
2层PCB，使用alitum。集成arduino nano，电位器，摇杆，oled屏幕，滑杆开关，以及N个按钮。
高自由度，所有功能均可以二次开发，已实现的功能是oled显示小车行驶数据。还可以作为其他应用的遥控器，如遥控船。遥控器背板没有电池安放位(可以用胶粘在背板上...)。
##### 关于开发板
4层PCB，对Arduino Mega2560 进行了简单升级，把成本降到最低，改造的电源管理，最大支持18V输入电压。布局紧凑可以搭配扩展板使用，扩展板集成了所有电机驱动模块，nrf24l01收发，蓝牙，wifi，超声波，显示屏，SD卡等（未完成）。
![Keyshot](3.Keyshot/Mega2560PCB.6.png)
##### 内部文件说明：
1. Hardware
   -  Atmega2560-16PU 开发板
   -  Atmega2560-16PU 扩展板(未完成，已停止维护)
   -  RemoteControl 开发板
2. Code
   - 小车代码
   - 遥控器代码
3. Keyshot
   - 渲染图
4. Docs
   - 一些常用文档及说明
5. 3D-Model
   - 目前仅限遥控器背板stl文件
