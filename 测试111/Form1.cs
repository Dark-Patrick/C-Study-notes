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
    public partial class FORM : Form
    {
        public FORM()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
                MessageBox.Show("学号不能为空");
            else if (textBox2.Text == "")
                MessageBox.Show("密码不能为空");
            else if (textBox1.Text != "2019" || textBox2.Text != "2019")
                MessageBox.Show("学号或密码不正确");
            else
            {
                Form2 a = new Form2();
                a.ShowDialog();
            }

            
        }
    }
}
