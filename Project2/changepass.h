#pragma once
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"
#include <string>  
#include <msclr/marshal_cppstd.h>
namespace Project2 {
	extern   LinkedList<User> usertList;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for changepass
	/// </summary>
	public ref class changepass : public System::Windows::Forms::Form
	{
	public:
		changepass(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		changepass(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~changepass()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ c;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(changepass::typeid));
			this->c = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// c
			// 
			this->c->Location = System::Drawing::Point(136, 362);
			this->c->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->c->Name = L"c";
			this->c->Size = System::Drawing::Size(120, 52);
			this->c->TabIndex = 0;
			this->c->Text = L"CHANGE";
			this->c->UseVisualStyleBackColor = true;
			this->c->Click += gcnew System::EventHandler(this, &changepass::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(14, 207);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(193, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 132);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(195, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label1->Location = System::Drawing::Point(9, 96);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter old password:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label2->Location = System::Drawing::Point(11, 172);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Enter new password:";
			// 
			// changepass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(652, 463);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->c);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"changepass";
			this->Text = L"changepass";
			this->Load += gcnew System::EventHandler(this, &changepass::changepass_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void changepass_Load(System::Object^ sender, System::EventArgs^ e) {

	}

		   void performchangepass() {
			   User currentUser = usertList.getElementAt(loggedInUserIndex);

			   String^ enteredpass = textBox2->Text;
			   String^ newpass = textBox1->Text;
			   bool passwordMatch = false;
			   bool newPasswordExists = false;


			   // Find the user to change the password
			   for (int i = 0; i < usertList.getSize(); i++) {
				   User& current = usertList.getElementAt(i);

				   if (enteredpass->Equals(gcnew String(current.getPassword().c_str()), StringComparison::OrdinalIgnoreCase)) {
					   // Entered password matches the current password
					   if (!newPasswordExists) {
						   // Update the password locally
						   currentUser.setPassword(msclr::interop::marshal_as<std::string>(newpass));
						   passwordMatch = true;

						   // Update the password in the database
						   String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";
						   SqlConnection^ conn = gcnew SqlConnection(connString);

						   try {
							   // Open the connection
							   conn->Open();

							   // SQL query to update the password
							   String^ updateQuery = "UPDATE Banking SET Password = @Password WHERE Username = @Username";
							   SqlCommand^ cmd = gcnew SqlCommand(updateQuery, conn);
							   cmd->Parameters->AddWithValue("@Password", gcnew String(currentUser.getPassword().c_str()));
							   cmd->Parameters->AddWithValue("@Username", gcnew String(currentUser.getUsername().c_str()));
							   cmd->ExecuteNonQuery();

							   MessageBox::Show("Password changed successfully!", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
						   }
						   catch (Exception^ ex) {
							   // Handle any errors that may have occurred
							   MessageBox::Show("Failed to update password: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   }
						   finally {
							   // Close the connection
							   conn->Close();
						   }
					   }
					   else {
						   MessageBox::Show("The new password already exists for another user.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					   }
					   break;
				   }
			   }

			   // Display appropriate message 
			   if (passwordMatch) {
				   // Update the user in the usertList
				   usertList.replaceElementAt(loggedInUserIndex, currentUser);
			   }
			   else {
				   MessageBox::Show("The entered password is incorrect.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
		   }


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		performchangepass();
	}
	};
}
