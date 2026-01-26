using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Calculator
{
public partial class Form1 : Form
    {
      
   private double num1 = 0;
      private double num2 = 0;
       private string operation = "";
       private bool isNewNumber = true;
        public Form1()
       {
           InitializeComponent();
       }
      
       private void NumberClick(object sender, EventArgs e)
       {
           Button bnt = (Button)sender;
            if (isNewNumber) 
           {
               txtbox.Text = bnt.Text;
              isNewNumber = false;
            } else {
   
               if (txtbox.Text.Length < 15)
               {
                   txtbox.Text += bnt.Text;
               }
           }
       }
 
       private void Operation_Click(object sender, EventArgs e)
       {
           Button btn = (Button)sender;
            if (!isNewNumber)
           {
               num1 = double.Parse(txtbox.Text);
            }
            operation = btn.Text;
            isNewNumber = true;
}

        private void Form1_Load(object sender, EventArgs e)
        {

        }

       private void btnEqual_Click(object sender, EventArgs e)
     {
            if (!isNewNumber)
            {
                num2 = double.Parse(txtbox.Text);

                try
                {
                    double result = Calculate(num1, num2, operation);
                   txtbox.Text = result.ToString();
               }
                catch (DivideByZeroException)
               {
                   txtbox.Text = "Деление на ноль невозможно";
               }
               catch (Exception)
               {
                    txtbox.Text = "Ошибка знач.";
                }
              isNewNumber = true;
                operation = "";
            }
        }



        private double Calculate(double a, double b, string op)
        {
            switch (op) 
            {
                case "+":
                    return a + b;
                case "-":
                    return a - b;
                case "*":
                    return a * b;
                case "/":
                    if (b == 0) throw new DivideByZeroException();
                    return a / b;
                default:
                   return b;

            }
       }


        private void button1_Click(object sender, EventArgs e)
        {
            if (txtbox.Text.Length > 1)
            {
                txtbox.Text = txtbox.Text.Substring(0, txtbox.Text.Length - 1);
            }
            else
            {
                txtbox.Text = "0";
                isNewNumber = true;
            }
        }


        private void btnClear_Click(object sender, EventArgs e)
        {
            txtbox.Text = "0";
            num1 = 0;
            num2 = 0;
            operation = "0";
            isNewNumber = true;
        
        }

        private void buttondes_Click(object sender, EventArgs e)
        {
            if (isNewNumber)
            {
                txtbox.Text = "0.";
                isNewNumber = false;
            }
            else if (!txtbox.Text.Contains("."))
            {
               txtbox.Text += ".";
            }
        }
    }
}
