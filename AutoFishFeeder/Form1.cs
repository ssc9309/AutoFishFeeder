using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace AutoFishFeeder
{
    public partial class Form1 : Form
    {
        //private SerialPort arduinoPort = new SerialPort("COM5", 9600);
        private SerialPort arduinoPort = new SerialPort();


        public Form1()
        {
            InitializeComponent();


            arduinoPort.PortName = "COM5";
            arduinoPort.BaudRate = 9600;

            arduinoPort.Parity = Parity.None;
            arduinoPort.DataBits = 8;
            arduinoPort.StopBits = StopBits.One;

            arduinoPort.DtrEnable = true;

            arduinoPort.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (arduinoPort.IsOpen)
            {
                arduinoPort.Open();
                arduinoPort.Write("hello");
                arduinoPort.Close();
            }
            else
            {
                MessageBox.Show("Not open");
            }
        }
    }
}
