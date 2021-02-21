using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 测试111
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            int t;
            t = Convert.ToInt32(textBox1.Text);
            string str = "租金", str1 = "元";
            string str2 = Convert.ToString(t * 100);
            label4.Text = str + str2 + str1;
            //convert转换

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                if (comboBox1.Text == "A1")
                    listBox1.Items.Add("A1 到B1停车场提车");
                else if (comboBox1.Text == "A2")
                    listBox1.Items.Add("A2 到B1停车场停车");
                else if(comboBox1.SelectedIndex==2)
                    listBox1.Items.Add("A3 到B1停车场停车");
                else if (comboBox1.SelectedIndex == 3)
                    listBox1.Items.Add("A4 到B1停车场停车");
            }
            if (radioButton2.Checked == true)
            {
                if (comboBox1.Text == "A1")
                    listBox1.Items.Add("A1 到B2停车场提车");
                else if (comboBox1.Text == "A2")
                    listBox1.Items.Add("A2 到B2停车场停车");
                else if (comboBox1.SelectedIndex == 2)
                    listBox1.Items.Add("A3 到B2停车场停车");
                else if (comboBox1.SelectedIndex == 3)
                    listBox1.Items.Add("A4 到B2停车场停车");
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
                button1.Enabled = true;
            else
                button1.Enabled = false;

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(listBox1.Text+" "+label4.Text+"\n"+"还车成功");
            listBox1.Items.Remove(listBox1.Text);
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
