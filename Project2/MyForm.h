#pragma once
#ifndef MYFORM_H
#define MYFORM_H
#include "MyForm2h.h"

#include "BankAccount.h"
#include "User.h"
#include "depositform.h"
#include "ManagedUser .cpp"

#include "operations.h"

namespace Project2 {

	LinkedList<User> usertList;

	using namespace System;
	using namespace System::Windows::Forms;

	public ref class MyForm : public System::Windows::Forms::Form {

		public:
			Form^ obj;

			MyForm(String^ username, String^ password) {
				InitializeComponent();
				// DisplayUserInformation();
				userinput->Text = username;
				passinput->Text = password;
			}

			MyForm() {
				InitializeComponent();
			}
		protected:
			~MyForm() {
			}

		private: System::Windows::Forms::Label^ labelUsername;
		private: System::Windows::Forms::TextBox^ userinput;
		private: System::Windows::Forms::TextBox^ passinput;
		private: System::Windows::Forms::Button^ login_button;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Label^ labelPassword;

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->userinput = (gcnew System::Windows::Forms::TextBox());
			this->passinput = (gcnew System::Windows::Forms::TextBox());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// labelUsername
			// 
			this->labelUsername->AutoSize = true;
			this->labelUsername->Location = System::Drawing::Point(418, -35);
			this->labelUsername->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(58, 13);
			this->labelUsername->TabIndex = 0;
			this->labelUsername->Text = L"Username:";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->labelPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelPassword->Location = System::Drawing::Point(24, 208);
			this->labelPassword->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(79, 15);
			this->labelPassword->TabIndex = 1;
			this->labelPassword->Text = L"PASSWORD:";
			// 
			// userinput
			// 
			this->userinput->Location = System::Drawing::Point(141, 128);
			this->userinput->Name = L"userinput";
			this->userinput->Size = System::Drawing::Size(100, 20);
			this->userinput->TabIndex = 2;
			// 
			// passinput
			// 
			this->passinput->Location = System::Drawing::Point(141, 208);
			this->passinput->Name = L"passinput";
			this->passinput->PasswordChar = '*';
			this->passinput->Size = System::Drawing::Size(100, 20);
			this->passinput->TabIndex = 3;
			// 
			// login_button
			// 
			this->login_button->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->login_button->ForeColor = System::Drawing::Color::Black;
			this->login_button->Location = System::Drawing::Point(71, 288);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(100, 41);
			this->login_button->TabIndex = 4;
			this->login_button->Text = L"login";
			this->login_button->UseVisualStyleBackColor = false;
			this->login_button->Click += gcnew System::EventHandler(this, &MyForm::loginbutt_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(24, 128);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"USERNAME:";
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(12, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 28);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(71, 373);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(156, 147);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(629, 532);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->passinput);
			this->Controls->Add(this->userinput);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelUsername);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(300, 200);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		   // verification of users username and password 
		int MyForm::validatelogin() {
	
			for (int i = 0; i < usertList.getSize(); i++) {
				   User currentUser = usertList.getElementAt(i);

				   if (userinput->Text->Equals(gcnew String(currentUser.getUsername().c_str()), StringComparison::OrdinalIgnoreCase)
					   && passinput->Text->Equals(gcnew String(currentUser.getPassword().c_str()), StringComparison::OrdinalIgnoreCase)) {

					   MessageBox::Show("User " + userinput->Text + " verified successfully!", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

					   return i;  // Return the index if a match is found
				   }
			   }

			   // If no match is found after the loop
			   MessageBox::Show("User not found.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

			   return -1; // Return -1 if the user is not found
		   }

		   System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			   // Additional code if needed on form load   
		   }

		private: System::Void loginbutt_Click(System::Object^ sender, System::EventArgs^ e) {

			int loggedInUserindex = validatelogin();
			MessageBox::Show(loggedInUserindex.ToString());

			// Check if the user is found
			if (loggedInUserindex != -1) {
				operations^ operationsFormInstance = gcnew operations(loggedInUserindex);

				this->Hide();
				operationsFormInstance->ShowDialog();
				this->Show();

			}
		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
#endif // MYFORM_H