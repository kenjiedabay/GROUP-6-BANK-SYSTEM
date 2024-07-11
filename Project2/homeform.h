#pragma once
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H
#include "MyForm2h.h"
#include <fstream>
#include "vector"

namespace Project2 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for homeform
    /// </summary>
    public ref class homeform : public System::Windows::Forms::Form
    {
    public:
        homeform(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~homeform()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(homeform::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(219, 332);
            this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(76, 41);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Login";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &homeform::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(37, 332);
            this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(72, 41);
            this->button2->TabIndex = 1;
            this->button2->Text = L"Register";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &homeform::button2_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(73, 75);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(198, 197);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 2;
            this->pictureBox1->TabStop = false;
            // 
            // homeform
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(652, 463);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->MinimumSize = System::Drawing::Size(229, 170);
            this->Name = L"homeform";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"homeform";
            this->Load += gcnew System::EventHandler(this, &homeform::homeform_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }




        // Function to perform XOR encryption/decryption
        std::string xorEncryptDecrypt(const std::string& input, const std::string& key) {
            std::string output;
            for (size_t i = 0; i < input.length(); ++i) {
                output += input[i] ^ key[i % key.length()];
            }
            return output;
        }

        std::vector<std::string> splitString(const std::string& input, const std::string& delimiter) {
            std::vector<std::string> tokens;
            size_t start = 0, end = 0;
            while ((end = input.find(delimiter, start)) != std::string::npos) {
                tokens.push_back(input.substr(start, end - start));
                start = end + delimiter.length();
            }
            tokens.push_back(input.substr(start));
            return tokens;
        }

#pragma endregion
    private: System::Void homeform_Load(System::Object^ sender, System::EventArgs^ e) {



        // Create a linked list of BankAccount objects with transactions
      //  vector<BankAccount> accounts;
       // vector<User> userss;




        // Your encryption key (make sure it's a strong key in a real scenario)
        std::string encryptionKey = "SecretKey";



        // Open the file for reading
        std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);


        if (inFile.is_open()) {
            std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);

            // Read the content of the file into a single string
            std::stringstream buffer;
            buffer << inFile.rdbuf();
            std::string fileContent = buffer.str();

            // Split the content into lines based on the terminator "/012210/"
            std::vector<std::string> lines = splitString(fileContent, "/012210/");
            for (std::string& s : lines) {
                std::cout << s << std::endl;
            }

            // Decrypt each string and deserialize
            LinkedList<User> decryptedAccounts;
            for (const auto& encryptedString : lines) {
                std::string decryptedString = xorEncryptDecrypt(encryptedString, encryptionKey);
                User decryptedAccount = User::deserialize(decryptedString);
                decryptedAccounts.append(decryptedAccount);
            }
            decryptedAccounts.erase(decryptedAccounts.getSize() - 1);

            // Print decrypted bank accounts
            std::cout << "Decrypted Bank Accounts: " << std::endl;
            for (int i = 0; i < decryptedAccounts.getSize(); i++) {
                cout << decryptedAccounts.getElementAt(i) << endl;
            }


            usertList = decryptedAccounts;
            // Close the file
            inFile.close();
        }
        else {
            std::cerr << "Unable to open the file for reading." << std::endl;
        }


        this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &homeform::homeform_FormClosing);

    }


    private: System::Void homeform_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {




        // Your encryption key (make sure it's a strong key in a real scenario)
        std::string encryptionKey = "SecretKey";

        // Serialize each object in the linked list and encrypt
        LinkedList<std::string> encryptedStrings;

        for (int i = 0; i < usertList.getSize(); i++) {

            std::string serializedObject = usertList.getElementAt(i).serialize();
            std::string encryptedString = xorEncryptDecrypt(serializedObject, encryptionKey);
            encryptedStrings.append(encryptedString);
        }



        // Open a binary file for writing
        std::ofstream outFile("encrypted_bank_accounts.bin", std::ios::binary);

        if (outFile.is_open()) {
            // Write the encrypted strings to the file, separated by a newline character
            for (int i = 0; i < encryptedStrings.getSize(); i++) {
                outFile << encryptedStrings.getElementAt(i) << "/012210/";
            }

            // Close the file
            outFile.close();

            std::cout << "Bank accounts encrypted and stored in 'encrypted_bank_accounts.bin'" << std::endl;
        }
        else {
            std::cerr << "Unable to open the file for writing." << std::endl;
        }



    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm^ loginForm = gcnew MyForm;
        this->Hide();  // Hide the current form
        loginForm->ShowDialog();
        this->Show();
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm2h^ signupForm = gcnew MyForm2h;
        this->Hide();  // Hide the current form
        signupForm->ShowDialog();
        this->Show();
    }
    };
}
#endif // HEADER_FILE_NAME_H

