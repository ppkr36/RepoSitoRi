using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IMT
{
    public partial class Form1 : Form
    {
        double height = 0;
        double weight = 0;
        double result = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBoxHeight_TextChanged(object sender, EventArgs e)
        {
            if (textBoxHeight.Text != "" && double.Parse(textBoxHeight.Text) > 0)
            {
                height = double.Parse(textBoxHeight.Text) / 100;
            }
        }

        private void textBoxWeight_TextChanged(object sender, EventArgs e)
        {   if (textBoxWeight.Text != "" && double.Parse(textBoxWeight.Text) > 0)
            {
                
                weight = double.Parse(textBoxWeight.Text);
            }
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            Math.Round(result = weight / (height * height), 2);
            if (result < 18.5) labelResult.Text = $"{Math.Round(result, 2)} - Недостаточный вес";
            if (result >= 18.5 || result <= 24.9 ) labelResult.Text = $"{Math.Round(result, 2)} - Нормальный вес";
            if (result >= 25 || result <= 29.9) labelResult.Text = $"{Math.Round(result, 2)} - Избыточный вес";
            if (result > 30) labelResult.Text = $"{Math.Round(result, 2)} - Ожирение";
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            height = 0;
            weight = 0;
            result = 0;
            textBoxHeight.Clear();
            textBoxWeight.Clear();
        }

        private void labelResultCaption_Click(object sender, EventArgs e)
        {

        }

        private void labelResult_Click(object sender, EventArgs e)
        {

        }
    }
}
