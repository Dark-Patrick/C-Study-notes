using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace win作业
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = Convert.ToInt32(textBox1.Text);
            int b = Convert.ToInt32(comboBox1.Text);
            int p = 2 * a + b;
            if (checkBox1.Checked == true)
            {
                p +=12;
            }
            if (checkBox2.Checked == true)
            {
                p += 10;
            }
            if (checkBox3.Checked == true)
            {
                p += 8;
            }
            if (p < 20)
                radioButton1.Checked = true;
            else
                radioButton1.Checked = false;
            if (p >= 20&&p<30)
            {
                radioButton2.Checked = true;
                p -= 5;
            }
            else
                radioButton2.Checked = false;
            if (p >= 30)
            {
                radioButton3.Checked = true;
                p -= 10;
            }
            else
                radioButton3.Checked = false;

            string str1 = Convert.ToString(p);
            textBox2.Text = str1;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (textBox3.Text == "")
                button2.Enabled = false;
            else
                button2.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int a = Convert.ToInt32(textBox2.Text);
           
                string str="菜品： ";
                if (checkBox1.Checked == true)
                {
                    str += "宫保鸡丁 ";
                }
                if (checkBox2.Checked == true)
                {
                    str += "鱼香肉丝 ";
                }
                if (checkBox3.Checked == true)
                {
                    str += "地三鲜 ";
                }
                listBox1.Items.Add(str);
                listBox1.Items.Add("主食： 米饭" + textBox1.Text + "碗  馒头" + comboBox1.Text + "个");
                if (radioButton1.Checked == true)
                    listBox1.Items.Add("优惠：无");
                else if(radioButton2.Checked == true)
                    listBox1.Items.Add("优惠："+radioButton2.Text);
                else if (radioButton3.Checked == true)
                    listBox1.Items.Add("优惠：" + radioButton3.Text);

                if (radioButton4.Checked == true)
                    listBox1.Items.Add("就餐地点：堂食");
                else if(radioButton5.Checked==true)
                    listBox1.Items.Add("就餐地点：外带");
                listBox1.Items.Add("桌号：" + textBox3.Text);

                if (radioButton5.Checked == true)
                {
                    string str2 = Convert.ToString(a+5);
                    listBox1.Items.Add("总花费：" + str2 + "元");
                }
                else if (radioButton4.Checked == true)
                {
                    string str2 = Convert.ToString(a );
                    listBox1.Items.Add("总花费：" + str2 + "元");
                }


        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void 开发人员信息ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 a = new Form2();
            a.ShowDialog();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult TS = MessageBox.Show("确定要退出吗？", "提示", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (TS == DialogResult.Yes)
                e.Cancel = false;
            else
                e.Cancel = true;
        }

    }
}
