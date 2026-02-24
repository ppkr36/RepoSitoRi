using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _090226
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            listBox1.Items.Add("Москва");
            listBox1.Items.Add("Санкт-Питербург");
            listBox1.Items.Add("Казань");

            comboBox1.Items.Add("Россия");
            comboBox1.Items.Add("США");
            comboBox1.Items.Add("Германия");
            comboBox1.SelectedIndex = 0;

            checkedListBox1.Items.Add("C#");
            checkedListBox1.Items.Add("C++");
            checkedListBox1.Items.Add("java");
            checkedListBox1.Items.Add("python");

            label1.Text = "Введите город";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string newCity = textBox1.Text;
            if(textBox1.Text != "")
            {
                listBox1.Items.Add(newCity);
                textBox1.Clear();
                label1.Text = "Город добавлен";
            }
            else
            {
                label1.Text = "Введите город";
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex != -1)
            {
                string select = listBox1.SelectedItem.ToString();
                label1.Text = $"В ListBox Выбрано: {select}";
            }
            else
            {
                label1.Text = "Пустота";
            }

            if(comboBox1.SelectedIndex != -1)
            {
                string country = comboBox1.SelectedItem.ToString();
                label1.Text = $"В ListBox Выбрано: {country}";
            }
          
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string result = "\nотмечено: ";
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                if (checkedListBox1.GetItemChecked(i))
                {
                    result += checkedListBox1.Items[i].ToString() + "\n";
                }
            }
            label1.Text = result;
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button_marks_click(object sender, EventArgs e)
        {
            string result = "Отмечено: \n";
            for(int i = 0;i < Items.Count;i++) {
        }
        private void ComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex != -1)
            {
                label1.Text = "Выбрана страна: " + listBox1.SelectedItem.ToString();
            }
        }
    }
}
