#pragma once
#ifndef MYFORM2H_H
#define MYFORM2H_H
#include "BankAccount.h"
#include "User.h"
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#include "MyForm.h"

namespace Project2 {


	LinkedList<User> registered;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm2h
	/// </summary>
	public ref class MyForm2h : public System::Windows::Forms::Form
	{
		// Connection string to the database with encryption disabled
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";

	public:
		MyForm2h(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->textBox4->MaxLength = 11;
			comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;


		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2h()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2h::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(116, 432);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(153, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Register";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2h::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(98, 93);
			this->textBox1->Margin = System::Windows::Forms::Padding(0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(187, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox2->Location = System::Drawing::Point(98, 148);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(187, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(32, 98);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Username:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm2h::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(32, 152);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm2h::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(21, 243);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Account Type:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm2h::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(15, 286);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Phone Number";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(48, 343);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Address";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox4->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox4->Location = System::Drawing::Point(101, 282);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(183, 20);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox5->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox5->Location = System::Drawing::Point(101, 337);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(183, 20);
			this->textBox5->TabIndex = 10;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox5_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(19, 18);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(76, 42);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Back";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2h::button2_Click);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox6->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox6->Location = System::Drawing::Point(101, 385);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(183, 20);
			this->textBox6->TabIndex = 12;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox6_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(21, 390);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Initial Balance";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Savings", L"Personal", L"Company" });
			this->comboBox1->Location = System::Drawing::Point(98, 238);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(186, 21);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2h::comboBox1_SelectedIndexChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(99, 190);
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(185, 20);
			this->textBox3->TabIndex = 16;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox3_TextChanged_1);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(32, 191);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 26);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Confirm\r\nPassword";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label7->Click += gcnew System::EventHandler(this, &MyForm2h::label7_Click);
			// 
			// MyForm2h
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(652, 501);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm2h";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm2h";
			this->Load += gcnew System::EventHandler(this, &MyForm2h::MyForm2h_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ enteredUsername = textBox1->Text;
		String^ enteredPassword = textBox2->Text;
		String^ enteredAccount = comboBox1->Text;
		String^ enteredBalance = textBox6->Text;
		String^ enterednumber = textBox4->Text;
		String^ enteredAddress = textBox5->Text;
		double parsedBalance;
		std::string phoneNumber = msclr::interop::marshal_as<std::string>(enterednumber);
		String^ confirmPass = textBox3->Text;
		System::Double::TryParse(enteredBalance, parsedBalance);


		signin(enteredUsername, enteredPassword, enteredAccount, parsedBalance, enterednumber, enteredAddress, confirmPass);
	}

		   void signin(String^ enteredUsername, String^ enteredPassword, String^ enteredAccount, double enteredBalance, String^ enteredNumber, String^ enteredAddress, String^ confirmPass) {
			   // Check if any of the input fields are empty
			   if (String::IsNullOrEmpty(enteredUsername) || String::IsNullOrEmpty(enteredPassword) || String::IsNullOrEmpty(enteredAccount) ||
				   String::IsNullOrEmpty(enteredNumber) || String::IsNullOrEmpty(enteredAddress)) {
				   MessageBox::Show("Please enter all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   if (enteredPassword != confirmPass) {
				   MessageBox::Show("Password and Confirm Password do not match.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   msclr::interop::marshal_context context;
			   std::string username = context.marshal_as<std::string>(enteredUsername);
			   std::string userPassword = context.marshal_as<std::string>(enteredPassword);
			   std::string account = context.marshal_as<std::string>(enteredAccount);
			   std::string phoneNumber = context.marshal_as<std::string>(enteredNumber);
			   std::string address = context.marshal_as<std::string>(enteredAddress);

			   // Unique ID mechanism 
			   std::string userId = "ID_" + std::to_string(static_cast<long long>(time(0)));

			   BankAccount account2(account, enteredBalance);

			   // Create the connection and command objects
			   SqlConnection^ conn = gcnew SqlConnection(connString);

			   // SQL query to check if the username already exists
			   String^ checkQuery = "SELECT COUNT(*) FROM Banking WHERE Username = @Username";
			   SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, conn);
			   checkCmd->Parameters->AddWithValue("@Username", enteredUsername);

			   try {
				   // Open the connection
				   conn->Open();

				   // Execute the query to check for existing username
				   int userCount = (int)checkCmd->ExecuteScalar();
				   if (userCount > 0) {
					   // Username already exists
					   MessageBox::Show("Username Already Exist", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
					   return;
				   }
			   }
			   catch (Exception^ ex) {
				   // Handle any errors that may have occurred
				   MessageBox::Show("Failed to check username: " + ex->Message);
				   return;
			   }
			   finally {
				   // Close the connection
				   conn->Close();
			   }

			   User newUser(username, userPassword, phoneNumber, address, account2, User::UserRole(User::CUSTOMER));
			   newUser.setUserId(userId);

			   // Find the correct position to insert in a sorted order
			   int index = usertList.getSize();

			   // SQL query to insert user details into the database
			   String^ sqlQuery = "INSERT INTO Banking (Username, Password, AccountType, PhoneNumber, Address, Userbalance) VALUES (@Username, @Password, @AccountType, @PhoneNumber, @Address, @Userbalance)";
			   SqlCommand^ cmd = gcnew SqlCommand(sqlQuery, conn);

			   // Add parameters to the command
			   cmd->Parameters->AddWithValue("@Username", enteredUsername);
			   cmd->Parameters->AddWithValue("@Password", enteredPassword);
			   cmd->Parameters->AddWithValue("@AccountType", enteredAccount);
			   cmd->Parameters->AddWithValue("@PhoneNumber", enteredNumber);
			   cmd->Parameters->AddWithValue("@Address", enteredAddress);
			   cmd->Parameters->AddWithValue("@Userbalance", enteredBalance);

			   try {
				   // Open the connection again
				   conn->Open();

				   // Execute the query
				   cmd->ExecuteNonQuery();

				   // Inform the user
				   MessageBox::Show("User registered successfully!");
			   }
			   catch (Exception^ ex) {
				   // Handle any errors that may have occurred
				   MessageBox::Show("Failed to register user: " + ex->Message);
			   }
			   finally {
				   // Close the connection
				   conn->Close();
			   }

			   // Add the new user to the user list
			   usertList.insert(index, newUser);
			   MessageBox::Show("Registered Successfully");
		   }


#pragma endregion

	private: System::Void MyForm2h_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Allow only control characters (e.g., backspace) and digits
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar)) {
			e->Handled = true;
		}
	}

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
#endif // MYFORM2H_H