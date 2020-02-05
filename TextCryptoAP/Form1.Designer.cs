namespace TextCrypto
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
            this.labelCiphertext = new System.Windows.Forms.Label();
            this.labelPlaintext = new System.Windows.Forms.Label();
            this.textBoxCiphertext = new System.Windows.Forms.TextBox();
            this.textBoxPlaintext = new System.Windows.Forms.TextBox();
            this.Decode = new System.Windows.Forms.Button();
            this.Encode = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelCiphertext
            // 
            this.labelCiphertext.AutoSize = true;
            this.labelCiphertext.Location = new System.Drawing.Point(12, 327);
            this.labelCiphertext.Name = "labelCiphertext";
            this.labelCiphertext.Size = new System.Drawing.Size(75, 17);
            this.labelCiphertext.TabIndex = 11;
            this.labelCiphertext.Text = "Ciphertext:";
            // 
            // labelPlaintext
            // 
            this.labelPlaintext.AutoSize = true;
            this.labelPlaintext.Location = new System.Drawing.Point(12, 9);
            this.labelPlaintext.Name = "labelPlaintext";
            this.labelPlaintext.Size = new System.Drawing.Size(65, 17);
            this.labelPlaintext.TabIndex = 10;
            this.labelPlaintext.Text = "Plaintext:";
            // 
            // textBoxCiphertext
            // 
            this.textBoxCiphertext.Location = new System.Drawing.Point(12, 349);
            this.textBoxCiphertext.Multiline = true;
            this.textBoxCiphertext.Name = "textBoxCiphertext";
            this.textBoxCiphertext.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxCiphertext.Size = new System.Drawing.Size(837, 350);
            this.textBoxCiphertext.TabIndex = 9;
            // 
            // textBoxPlaintext
            // 
            this.textBoxPlaintext.Location = new System.Drawing.Point(12, 30);
            this.textBoxPlaintext.Multiline = true;
            this.textBoxPlaintext.Name = "textBoxPlaintext";
            this.textBoxPlaintext.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxPlaintext.Size = new System.Drawing.Size(837, 271);
            this.textBoxPlaintext.TabIndex = 8;
            // 
            // Decode
            // 
            this.Decode.Location = new System.Drawing.Point(435, 307);
            this.Decode.Name = "Decode";
            this.Decode.Size = new System.Drawing.Size(80, 37);
            this.Decode.TabIndex = 7;
            this.Decode.Text = "Deocde";
            this.Decode.UseVisualStyleBackColor = true;
            this.Decode.Click += new System.EventHandler(this.Decode_Click);
            // 
            // Encode
            // 
            this.Encode.Location = new System.Drawing.Point(264, 307);
            this.Encode.Name = "Encode";
            this.Encode.Size = new System.Drawing.Size(74, 37);
            this.Encode.TabIndex = 6;
            this.Encode.Text = "Encode";
            this.Encode.UseVisualStyleBackColor = true;
            this.Encode.Click += new System.EventHandler(this.Encode_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(865, 706);
            this.Controls.Add(this.labelCiphertext);
            this.Controls.Add(this.labelPlaintext);
            this.Controls.Add(this.textBoxCiphertext);
            this.Controls.Add(this.textBoxPlaintext);
            this.Controls.Add(this.Decode);
            this.Controls.Add(this.Encode);
            this.Name = "Form1";
            this.Text = "Text Encryption and Decryption V1.0 (Feb.5, 2020)";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelCiphertext;
        private System.Windows.Forms.Label labelPlaintext;
        private System.Windows.Forms.TextBox textBoxCiphertext;
        private System.Windows.Forms.TextBox textBoxPlaintext;
        private System.Windows.Forms.Button Decode;
        private System.Windows.Forms.Button Encode;
    }
}

