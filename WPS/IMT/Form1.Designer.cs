namespace IMT
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.labelResultCaption = new System.Windows.Forms.Label();
            this.textBoxHeight = new System.Windows.Forms.TextBox();
            this.textBoxWeight = new System.Windows.Forms.TextBox();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonCalculate = new System.Windows.Forms.Button();
            this.labelResult = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 77);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Рост";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 130);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Вес";
            // 
            // labelResultCaption
            // 
            this.labelResultCaption.AutoSize = true;
            this.labelResultCaption.Location = new System.Drawing.Point(12, 242);
            this.labelResultCaption.Name = "labelResultCaption";
            this.labelResultCaption.Size = new System.Drawing.Size(62, 13);
            this.labelResultCaption.TabIndex = 2;
            this.labelResultCaption.Text = "Результат:";
            this.labelResultCaption.Click += new System.EventHandler(this.labelResultCaption_Click);
            // 
            // textBoxHeight
            // 
            this.textBoxHeight.Location = new System.Drawing.Point(12, 93);
            this.textBoxHeight.Name = "textBoxHeight";
            this.textBoxHeight.Size = new System.Drawing.Size(100, 20);
            this.textBoxHeight.TabIndex = 3;
            this.textBoxHeight.TextChanged += new System.EventHandler(this.textBoxHeight_TextChanged);
            // 
            // textBoxWeight
            // 
            this.textBoxWeight.Location = new System.Drawing.Point(12, 146);
            this.textBoxWeight.Name = "textBoxWeight";
            this.textBoxWeight.Size = new System.Drawing.Size(100, 20);
            this.textBoxWeight.TabIndex = 4;
            this.textBoxWeight.TextChanged += new System.EventHandler(this.textBoxWeight_TextChanged);
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(132, 189);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(75, 23);
            this.buttonClear.TabIndex = 5;
            this.buttonClear.Text = "Очистить";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Location = new System.Drawing.Point(12, 189);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(114, 23);
            this.buttonCalculate.TabIndex = 6;
            this.buttonCalculate.Text = "Рассчитать ИМТ";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Location = new System.Drawing.Point(91, 242);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(35, 13);
            this.labelResult.TabIndex = 7;
            this.labelResult.Text = "label3";
            this.labelResult.Click += new System.EventHandler(this.labelResult_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(326, 289);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.textBoxWeight);
            this.Controls.Add(this.textBoxHeight);
            this.Controls.Add(this.labelResultCaption);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label labelResultCaption;
        private System.Windows.Forms.TextBox textBoxHeight;
        private System.Windows.Forms.TextBox textBoxWeight;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Button buttonCalculate;
        private System.Windows.Forms.Label labelResult;
    }
}

