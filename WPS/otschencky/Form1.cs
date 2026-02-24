using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace otschencky
{
    public partial class Form1 : Form
    {
        List<string> subject = new List<string>();
        List<List<int>> allGrades = new List<List<int>>();
        public Form1()
        {
            InitializeComponent();
            subject.Add("Математика");
            subject.Add("Русский язык");
            allGrades.Add(new List<int>());
            allGrades.Add(new List<int>());
            listBox1.Items.Clear();
            foreach(string s  in subject)
            {
                listBox1.Items.Add(s);         
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string newSub = textBox1.Text.Trim();
            if(newSub != "")
            {
                label1.Text = newSub;
            }
        }
    }
}
