#pragma once
#ifndef MYDEPOSIT_H
#define MYDEPOSIT_H
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"


namespace Project2 {
	extern LinkedList<User> usertList;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for depositform
	/// </summary>
	public ref class depositform : public System::Windows::Forms::Form
	{
	public:
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";
		SqlConnection^ conn = gcnew SqlConnection(connString);

		depositform(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~depositform()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(depositform::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 105);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &depositform::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(132, 326);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"DEPOSIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &depositform::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12));
			this->label1->Location = System::Drawing::Point(16, 225);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Your Balance After";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12));
			this->label2->Location = System::Drawing::Point(16, 103);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter Amount:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12));
			this->label3->Location = System::Drawing::Point(16, 172);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Your Balance Before:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(20, 35);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(58, 27);
			this->button2->TabIndex = 5;
			this->button2->Text = L"back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &depositform::button2_Click);
			// 
			// depositform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(652, 463);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"depositform";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"depositform";
			this->Load += gcnew System::EventHandler(this, &depositform::depositform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void depositform_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		double inputValue;

		Double::TryParse(textBox1->Text, inputValue);
		performdeposit(inputValue);

		showlist();
	}



		   void showlist() {
			   String^ userListText = ""; // Initialize an empty string to hold user information

			   User currentUser = usertList.getElementAt(loggedInUserIndex);



			   for (int i = 0; i < usertList.getSize(); i++) {
				   currentUser = usertList.getElementAt(i);

				   // Concatenate user information
				   String^ userInfo = gcnew String((currentUser.getUsername() + " - " + currentUser.getPassword()).c_str());
				   userListText += userInfo + Environment::NewLine; // Add a newline between each user

			   }
		   }

		   void performdeposit(double amount) {

			   String^ dep = textBox1->Text;
			   User currentUser = usertList.getElementAt(loggedInUserIndex);
			   label3->Text = "Balance before deposit: $" + currentUser.getBankAccount().getBalance();

			   // Retrieve the current balance
			   double currentBalance = currentUser.getBankAccount().getBalance();

			   // Update the user's balance
			   currentBalance += amount;

			   // Set the new balance to the user's bank account
			   currentUser.getBankAccount().setBalance(currentBalance);

			   // Update the user in the usertList
			   usertList.replaceElementAt(loggedInUserIndex, currentUser);

			   if (String::IsNullOrEmpty(textBox1->Text)) {
				   MessageBox::Show("Please enter the amount, the field is empty");
			   }
			   else {
				   label1->Text = "Your Balance Now: $" + currentUser.getBankAccount().getBalance();
				   // Call the function to update the balance in the database
				   updateBalanceInDatabase(currentUser.getUsername(), currentBalance);
			   }


		   }
		   void updateBalanceInDatabase(std::string username, double newBalance) {

			   String^ usernameStr = gcnew String(username.c_str());
			   String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";
			   SqlConnection^ connection = gcnew SqlConnection(connString);
			   String^ query = "UPDATE Banking SET Userbalance = @NewBalance WHERE Username = @Username";

			   SqlCommand^ command = gcnew SqlCommand(query, connection);
			   command->Parameters->AddWithValue("@NewBalance", newBalance);
			   command->Parameters->AddWithValue("@Username", usernameStr);

			   try {
				   connection->Open();
				   command->ExecuteNonQuery();
				   MessageBox::Show("Deposit Money successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Error Depositing Money: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   finally {
				   connection->Close();
			   }
		   }


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
	};
}
#endif