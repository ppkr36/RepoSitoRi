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
        // Переменные для хранения данных калькулятора
   private double firstNumber = 0;
      private double secondNumber = 0;
       private string operation = "";
       private bool isNewNumber = true;
        public Form1()
       {
           InitializeComponent();
       }
        //Object sender объект который обрабатывает значение при нажатии ( действии )
       // EventArgs хранит в себе значение элемента который был в действии.
       private void NumberClick(object sender, EventArgs e)
       {
           Button bnt = (Button)sender;
            if (isNewNumber) 
           {
               txtbox.Text = bnt.Text;
              isNewNumber = false;
            } else {
               // Проверка на максимальную длину
               if (txtbox.Text.Length < 15)
               {
                   txtbox.Text += bnt.Text;
               }
           }
       }
        // Обработчик операций
       private void Operation_Click(object sender, EventArgs e)
       {
           Button btn = (Button)sender;
            if (!isNewNumber)
           {
               firstNumber = double.Parse(txtbox.Text);
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
                secondNumber = double.Parse(txtbox.Text);

                try
                {
                    double result = Calculate(firstNumber, secondNumber, operation);
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

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtbox.Text = "0";
            firstNumber = 0;
            secondNumber = 0;
            operation = "0";
            isNewNumber = true;
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
