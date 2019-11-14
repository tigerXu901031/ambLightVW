using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace ambLightClient
{
    public partial class Form1 : Form
    {
        usb_device.DEVICE_INFO devInfo = new usb_device.DEVICE_INFO();
        Int32[] devHandles = new Int32[20];
        Int32 devHandle = 0;
        Byte linIdx = 0;
        bool state;
        Int32 devNum, ret;
        bool isDeviceOpen = false;

        Form2 f2 = new Form2();
        public Form1()
        {
            InitializeComponent();
        }

        private void finalizeAmbLightClient()
        {
            /* clear the switch status to all off */
            USB2LIN_EX.LIN_EX_MSG[] msg = new USB2LIN_EX.LIN_EX_MSG[2];
            USB2LIN_EX.LIN_EX_MSG[] echoMsg = new USB2LIN_EX.LIN_EX_MSG[4];

            Byte chksumVal = 0;

            if (isDeviceOpen)
            {
                /* 1st message is break message */
                msg[0] = new USB2LIN_EX.LIN_EX_MSG();
                msg[0].MsgType = USB2LIN_EX.LIN_EX_MSG_TYPE_BK;
                msg[0].Timestamp = 10;

                /* 2nd message is the data message */
                msg[0] = new USB2LIN_EX.LIN_EX_MSG();
                msg[1].MsgType = USB2LIN_EX.LIN_EX_MSG_TYPE_MW;
                msg[1].Data = new Byte[8];
                msg[1].Timestamp = 10;
                msg[1].PID = 0x17;
                msg[1].DataLen = 8;
                msg[1].CheckType = USB2LIN_EX.LIN_EX_CHECK_EXT;

                msg[1].Data[0] = 0x00;
                msg[1].Data[1] = 0x00;
                msg[1].Data[2] = 0x00;
                msg[1].Data[3] = 0x00;
                msg[1].Data[4] = 0x00;
                msg[1].Data[5] = 0x00;
                msg[1].Data[6] = 0x00;
                msg[1].Data[7] = 0x00;

                // checksum calculation
                for (Byte i = 0; i < 8; i++)
                {
                    chksumVal = (Byte)(chksumVal + msg[1].Data[i]);
                }
                chksumVal = (Byte)(255 - (chksumVal + 0x97));
                msg[1].Check = chksumVal;

                // send out the message
                IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(USB2LIN_EX.LIN_EX_MSG)) * echoMsg.Length);

                ret = USB2LIN_EX.LIN_EX_MasterSync(devHandle, linIdx, msg, pt, msg.Length);
                if (ret < USB2LIN_EX.LIN_EX_SUCCESS)
                {
                    f2.richTextBox1.AppendText("Lin message send failed! \n");
                    f2.richTextBox1.AppendText("Error code:" + ret.ToString());
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText("Lin message send success! \n");
                }

                Marshal.FreeHGlobal(pt);
            }
            else
            {

            }
            
        }

        private void ConnectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(isDeviceOpen)
            {

            }
            else
            {
                // search and scan device
                devNum = usb_device.USB_ScanDevice(devHandles);
                if (devNum <= 0)
                {
                    f2.richTextBox1.AppendText("no device connected \n");
                    f2.ShowDialog(this);
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText(string.Format("Have {0} device connected \n", devNum));
                }

                // open device
                devHandle = devHandles[0];
                state = usb_device.USB_OpenDevice(devHandle);
                if (!state)
                {
                    f2.richTextBox1.AppendText("Fail to open device \n");
                    f2.ShowDialog(this);
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText("Open device success \n");
                }

                // get firmware infomation
                StringBuilder funcStr = new StringBuilder(256);
                state = usb_device.DEV_GetDeviceInfo(devHandle, ref devInfo, funcStr);

                if (!state)
                {
                    f2.richTextBox1.AppendText("Get device information failed! \n");
                    f2.ShowDialog(this);
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText("-----------------------------------\n");
                    f2.richTextBox1.AppendText("Firmware Info \n");
                    f2.richTextBox1.AppendText(string.Format("    Name: " + Encoding.Default.GetString(devInfo.FirmwareName) + "\n"));
                    f2.richTextBox1.AppendText(String.Format("    Build Date: " + Encoding.Default.GetString(devInfo.BuildDate) + "\n"));
                    f2.richTextBox1.AppendText(string.Format("    Firmware version: v{0}.{1}.{2}", (((devInfo.FirmwareVersion) >> 24) & 0xff), (((devInfo.FirmwareVersion) >> 16) & 0xff), (devInfo.FirmwareVersion & 0xffff) + "\n"));
                    f2.richTextBox1.AppendText(string.Format("    Hardware version: v{0}.{1}.{2}", (((devInfo.HardwareVersion) >> 24) & 0xff), (((devInfo.HardwareVersion) >> 16) & 0xff), (devInfo.HardwareVersion & 0xffff) + "\n"));
                    f2.richTextBox1.AppendText(string.Format("    Functions: " + devInfo.Functions.ToString("X8") + "\n"));
                    f2.richTextBox1.AppendText(string.Format("    Functions String" + funcStr + '\n'));
                    f2.richTextBox1.AppendText("-----------------------------------\n");
                }

                // initialize and configure LIN
                ret = USB2LIN_EX.LIN_EX_Init(devHandle, linIdx, 19200, 1);
                if (ret != USB2LIN_EX.LIN_EX_SUCCESS)
                {
                    f2.richTextBox1.AppendText("Config LIN failed! \n");
                    f2.richTextBox1.AppendText("Error code: " + ret.ToString() + "\n");
                    f2.ShowDialog(this);
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText("Config LIN success ! \n");
                }
                f2.ShowDialog(this);
                isDeviceOpen = true;
            }
            
        }

        private void OutputToolStripMenuItem_Click(object sender, EventArgs e)
        {
            f2.ShowDialog(this);
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            finalizeAmbLightClient();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Byte brightnessLevel = 0;
            Byte lightMode = 0;
            Byte freeModeL = 0;
            Byte freeModeT = 0;
            Byte freeModeR = 0;
            Byte chksumVal = 0;
            
            // initialize the message object
            USB2LIN_EX.LIN_EX_MSG[] msg = new USB2LIN_EX.LIN_EX_MSG[2];
            USB2LIN_EX.LIN_EX_MSG[] echoMsg = new USB2LIN_EX.LIN_EX_MSG[4];

            if (isDeviceOpen)
            {
                /* 1st message is break message */
                msg[0] = new USB2LIN_EX.LIN_EX_MSG();
                msg[0].MsgType = USB2LIN_EX.LIN_EX_MSG_TYPE_BK;
                msg[0].Timestamp = 10;

                /* 2nd message is the data message */
                msg[0] = new USB2LIN_EX.LIN_EX_MSG();
                msg[1].MsgType = USB2LIN_EX.LIN_EX_MSG_TYPE_MW;
                msg[1].Data = new Byte[8];
                msg[1].Timestamp = 10;
                msg[1].PID = 0x97;
                msg[1].DataLen = 8;
                msg[1].CheckType = USB2LIN_EX.LIN_EX_CHECK_EXT;

                // load and pack the data
                lightMode = (Byte)comboBox1.SelectedIndex;
                if (lightMode < 17)
                {
                    lightMode = (Byte)(lightMode + 2);
                }
                else if (lightMode == 17)
                {
                    lightMode = (Byte)0xff;
                }
                else
                {
                    /* do nothing */
                }
                freeModeL = (byte)(comboBox2.SelectedIndex + 1);
                freeModeT = (byte)(comboBox3.SelectedIndex + 1);
                freeModeR = (byte)(comboBox4.SelectedIndex + 1);

                if (radioButton1.Checked)
                {
                    brightnessLevel = 3;
                }
                else if (radioButton2.Checked)
                {
                    brightnessLevel = 2;
                }
                else if (radioButton3.Checked)
                {
                    brightnessLevel = 1;
                }
                else
                {
                    brightnessLevel = 0;
                }

                msg[1].Data[0] = ((Byte)(brightnessLevel << 4));
                msg[1].Data[0] |= 0x01;
                msg[1].Data[1] = lightMode;
                msg[1].Data[2] = freeModeR;
                msg[1].Data[2] |= (Byte)(freeModeL << 4); 
                msg[1].Data[3] = freeModeT;

                // checksum calculation
                for(Byte i = 0; i < 8; i++)
                {
                    chksumVal = (Byte)(chksumVal + msg[1].Data[i]);
                }
                chksumVal = (Byte)(255 - (chksumVal + 0x97));
                msg[1].Check = chksumVal;

                // send out the message
                IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(USB2LIN_EX.LIN_EX_MSG)) * echoMsg.Length);

                ret = USB2LIN_EX.LIN_EX_MasterSync(devHandle, linIdx, msg, pt, msg.Length);
                if (ret < USB2LIN_EX.LIN_EX_SUCCESS)
                {
                    f2.richTextBox1.AppendText("Lin message send failed! \n");
                    f2.richTextBox1.AppendText("Error code:" + ret.ToString());
                    return;
                }
                else
                {
                    f2.richTextBox1.AppendText("Lin message send success! \n");
                }

                Marshal.FreeHGlobal(pt);
            }
            else
            {

            }
                
        }
    }
    class usb_device
    {
        public struct DEVICE_INFO
        {
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
            public Byte[] FirmwareName;   //固件名称字符串
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
            public Byte[] BuildDate;    //固件编译时间字符串
            public UInt32 HardwareVersion;//硬件版本号
            public UInt32 FirmwareVersion;//固件版本号
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
            public UInt32[] SerialNumber; //适配器序列号
            public UInt32 Functions;      //适配器当前具备的功能
        }




        //方法定义
        /**
          * @brief  初始化USB设备，并扫描设备连接数，必须调用
          * @param  pDevHandle 每个设备的设备号存储地址
          * @retval 扫描到的设备数量
          */
        [DllImport("USB2XXX.dll")]
        public static extern Int32 USB_ScanDevice(Int32[] pDevHandle);
        /**
          * @brief  打开设备，必须调用
          * @param  DevHandle 设备索引号
          * @retval 打开设备的状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool USB_OpenDevice(Int32 DevHandle);
        /**
          * @brief  关闭设备
          * @param  DevHandle 设备索引号
          * @retval 关闭设备的状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool USB_CloseDevice(Int32 DevHandle);
        /**
          * @brief  获取设备信息，比如设备名称，固件版本号，设备序号，设备功能说明字符串等
          * @param  DevHandle 设备索引号
          * @param  pDevInfo 设备信息存储结构体指针
          * @param  pFunctionStr 设备功能说明字符串
          * @retval 获取设备信息的状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool DEV_GetDeviceInfo(Int32 DevHandle, ref DEVICE_INFO pDevInfo, StringBuilder pFunctionStr);
        /**
          * @brief  擦出用户区数据
          * @param  DevHandle 设备索引号
          * @retval 用户区数据擦出状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool DEV_EraseUserData(int DevHandle);

        /**
          * @brief  向用户区域写入用户自定义数据，写入数据之前需要调用擦出函数将数据擦出
          * @param  DevHandle 设备索引号
          * @param  OffsetAddr 数据写入偏移地址，起始地址为0x00，用户区总容量为0x10000字节，也就是64KBye
          * @param  pWriteData 用户数据缓冲区首地址
          * @param  DataLen 待写入的数据字节数
          * @retval 写入用户自定义数据状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool DEV_WriteUserData(int DevHandle, int OffsetAddr, byte[] pWriteData, int DataLen);

        /**
          * @brief  从用户自定义数据区读出数据
          * @param  DevHandle 设备索引号
          * @param  OffsetAddr 数据写入偏移地址，起始地址为0x00，用户区总容量为0x10000字节，也就是64KBye
          * @param  pReadData 用户数据缓冲区首地址
          * @param  DataLen 待读出的数据字节数
          * @retval 读出用户自定义数据的状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool DEV_ReadUserData(int DevHandle, int OffsetAddr, byte[] pReadData, int DataLen);

        /**
          * @brief  设置可变电压输出引脚输出电压值
          * @param  DevHandle 设备索引号
          * @param  PowerLevel 输出电压值，0-1.8V，1-3.3V
          * @retval 设置输出电压状态
          */
        [DllImport("USB2XXX.dll")]
        public static extern bool DEV_SetPowerLevel(int DevHandle, char PowerLevel);
    }

    class USB2LIN_EX
    {
        //定义函数返回错误代码
        public const Int32 LIN_EX_SUCCESS = (0);   //函数执行成功
        public const Int32 LIN_EX_ERR_NOT_SUPPORT = (-1);  //适配器不支持该函数
        public const Int32 LIN_EX_ERR_USB_WRITE_FAIL = (-2);  //USB写数据失败
        public const Int32 LIN_EX_ERR_USB_READ_FAIL = (-3);  //USB读数据失败
        public const Int32 LIN_EX_ERR_CMD_FAIL = (-4);  //命令执行失败
        public const Int32 LIN_EX_ERR_CH_NO_INIT = (-5);  //该通道未初始化
        public const Int32 LIN_EX_ERR_READ_DATA = (-6);  //LIN读数据失败
        //LIN和校验模式
        public const Byte LIN_EX_CHECK_STD = 0;	//标准校验，不含PID
        public const Byte LIN_EX_CHECK_EXT = 1;	//增强校验，包含PID
        public const Byte LIN_EX_CHECK_USER = 2;  //自定义校验类型，需要用户自己计算并传入Check，不进行自动校验
        public const Byte LIN_EX_CHECK_NONE = 3;  //接收数据校验错误
        public const Byte LIN_EX_CHECK_ERROR = 4;  //接收数据校验错误
        //定义主从模式
        public const Byte LIN_EX_MASTER = 1;//主机
        public const Byte LIN_EX_SLAVE = 0;//从机

        public const Byte LIN_EX_MSG_TYPE_UN = 0;  //未知类型
        public const Byte LIN_EX_MSG_TYPE_MW = 1;	//主机向从机发送数据
        public const Byte LIN_EX_MSG_TYPE_MR = 2;	//主机从从机读取数据
        public const Byte LIN_EX_MSG_TYPE_SW = 3;	//从机发送数据
        public const Byte LIN_EX_MSG_TYPE_SR = 4;	//从机接收数据
        public const Byte LIN_EX_MSG_TYPE_BK = 5;	//只发送BREAK信号，若是反馈回来的数据，表明只检测到BREAK信号
        public const Byte LIN_EX_MSG_TYPE_SY = 6;	//表明检测到了BREAK，SYNC信号
        public const Byte LIN_EX_MSG_TYPE_ID = 7;	//表明检测到了BREAK，SYNC，PID信号
        public const Byte LIN_EX_MSG_TYPE_DT = 8;	//表明检测到了BREAK，SYNC，PID,DATA信号
        public const Byte LIN_EX_MSG_TYPE_CK = 9;	//表明检测到了BREAK，SYNC，PID,DATA,CHECK信号

        //LIN数据帧格式定义
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        public struct LIN_EX_MSG
        {
            [MarshalAs(UnmanagedType.U4)]
            public UInt32 Timestamp;    //时间戳
            [MarshalAs(UnmanagedType.U1)]
            public Byte MsgType;	    //帧类型
            [MarshalAs(UnmanagedType.U1)]
            public Byte CheckType;    //校验类型
            [MarshalAs(UnmanagedType.U1)]
            public Byte DataLen;	    //LIN数据段有效数据字节数
            [MarshalAs(UnmanagedType.U1)]
            public Byte Sync;			//固定值，0x55
            [MarshalAs(UnmanagedType.U1)]
            public Byte PID;			//帧ID		
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.U1)]
            public Byte[] Data;	    //数据
            [MarshalAs(UnmanagedType.U1)]
            public Byte Check;		//校验,只有校验数据类型为LIN_EX_CHECK_USER的时候才需要用户传入数据
            [MarshalAs(UnmanagedType.U1)]
            public Byte Reserve0;
            [MarshalAs(UnmanagedType.U1)]
            public Byte Reserve1;
        }
        //USB2LIN相关函数定义
        [DllImport("USB2XXX.dll")]
        public static extern Int32 LIN_EX_Init(Int32 DevHandle, Byte LINIndex, Int32 BaudRate, Byte MasterMode);
        [DllImport("USB2XXX.dll")]
        public static extern Int32 LIN_EX_MasterSync(Int32 DevHandle, Byte LINIndex, LIN_EX_MSG[] pInMsg, IntPtr pOutMsg, Int32 MsgLen);
        [DllImport("USB2XXX.dll")]
        public static extern Int32 LIN_EX_SlaveSetIDMode(Int32 DevHandle, Byte LINIndex, LIN_EX_MSG[] pLINMsg, Int32 MsgLen);
        [DllImport("USB2XXX.dll")]
        public static extern Int32 LIN_EX_SlaveGetData(Int32 DevHandle, Byte LINIndex, IntPtr pLINMsg);

    }
}
