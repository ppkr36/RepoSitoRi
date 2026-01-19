using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace Tomilov_RPO6_WPS
{
    public partial class Form1 : Form
    {
        string cur_num = "0";
        string operation = "";
        double first_num = 0;
        double second_num = 0;
        bool new_num = true;
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = "0";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Process.Start("https://rutube.ru/video/c6cc4d620b1d4338901770a44b3e82f4/?ysclid=mkb9tkw30442897314");
        }
        

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Button btn1 = (Button)sender;
            
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn1.Text;
            }
            else
            {
                cur_num += btn1.Text;
            }
            textBox1.Text = cur_num;
        }
        private void button10_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(operation))
            {
                return;
            }


            try
            {
                second_num = double.Parse(textBox1.Text);
            }
            catch
            {
                MessageBox.Show("Ошибка");
                return;
            }

            double result = 0;

            if(operation == "+")
            {
                result = first_num + second_num;
            }else if (operation == "-")
            {
                result = second_num - first_num;
            }else if (operation == "*")
            {
                result = first_num * second_num;
            }else if (operation == "/")
            {
                result = first_num / second_num;
            }
            textBox1.Text = result.ToString();
            
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }
        

        private void btn6_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btncomma_Click(object sender, EventArgs e)
        {

        }

        private void btn3_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            if (cur_num == "0" || operation != "")
            {
                cur_num = btn.Text;
            }
            else
            {
                cur_num += btn.Text;
            }
            textBox1.Text = cur_num;
        }

        private void btndel_Click(object sender, EventArgs e)
        {
            first_num = double.Parse(cur_num);
            operation = "/";
            cur_num = "0";
        }

        private void btnum_Click(object sender, EventArgs e)
        {
            first_num = double.Parse(cur_num);
            operation = "*";
            cur_num = "0";
        }

        private void btnmin_Click(object sender, EventArgs e)
        {
            first_num = double.Parse(cur_num);
            operation = "-";
            cur_num = "0";
        }

        private void btnplus_Click(object sender, EventArgs e)
        {
            first_num = double.Parse(cur_num);
            operation = "+";
            cur_num = "0";
        }
    }
}
