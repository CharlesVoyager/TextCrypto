using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextCrypto
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Encode_Click(object sender, EventArgs e)
        {
            /*
Base64:
The ratio of output bytes to input bytes is 4:3 (33% overhead). Specifically, given an input of n bytes, the output will be 4 [ 1/3 * n ] bytes long, including padding characters.

Example:
Source: "true" (4 bytes) -> PKCS#5 padding "true4444" (8 bytes) -> des cbc encode (8 bytes) -> Base64 encode (12 bytes)
Source: "abcdefgh" (8 bytes) -> PKCS#5 padding "abcdefgh88888888" (16 bytes) -> des cbc encode (16 bytes) -> Base64 encode (24 bytes)
Source: "..." (21 bytes) -> PKCS#5 padding "...333" (24 bytes) -> des cbc encode (24 bytes) -> Base64 encode (32 bytes)
Source: "..." (64 bytes) -> PKCS#5 padding "...88888888" (72 bytes) -> des cbc encode (72 bytes) -> Base64 encode (96 bytes)
*/
            int maxLength = ((textBoxPlaintext.Text.Length + 8 + 3) / 3) * 4; // Plaintext ---> PKCS#5 padding ---> DES CBC Encode ---> Base64 encode
            StringBuilder result = new StringBuilder(maxLength);
            desEncrypt(textBoxPlaintext.Text, result, maxLength, null, null);
            textBoxCiphertext.Text = result.ToString();
            labelPlaintext.Text = "Plaintext: (" + textBoxPlaintext.Text.Length.ToString() + " characters)";
            labelCiphertext.Text = "Ciphertext: (" + textBoxCiphertext.Text.Length.ToString() + " characters)";
        }

        private void Decode_Click(object sender, EventArgs e)
        {
            int maxLength = textBoxCiphertext.Text.Length;
            StringBuilder result = new StringBuilder(maxLength);    // Allocate the buffer for storing the decoded text. It is enough to create the deocde buffer size the same as the size of cipher text.
            desDecrypt(textBoxCiphertext.Text, result, maxLength, null, null);
            textBoxPlaintext.Text = result.ToString();
            labelPlaintext.Text = "Plaintext: (" + textBoxPlaintext.Text.Length.ToString() + " characters)";
            labelCiphertext.Text = "Ciphertext: (" + textBoxCiphertext.Text.Length.ToString() + " characters)";
        }
    }
}
