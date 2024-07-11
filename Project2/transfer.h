#pragma once
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"

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
	/// Summary for transfer
	/// </summary>
	public ref class transfer : public System::Windows::Forms::Form
	{
	public:
		transfer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		transfer(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~transfer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(transfer::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 246);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"TRANSFER";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &transfer::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(181, 168);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(118, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(19, 168);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(115, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(21, 135);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Name of Receiver";
			this->label1->Click += gcnew System::EventHandler(this, &transfer::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(178, 133);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Amount to Transfer";
			this->label2->Click += gcnew System::EventHandler(this, &transfer::label2_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 18);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 25);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &transfer::button2_Click);
			// 
			// transfer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(597, 352);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"transfer";
			this->Text = L"transfer";
			this->Load += gcnew System::EventHandler(this, &transfer::transfer_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void transfer_Load(System::Object^ sender, System::EventArgs^ e) {


	}
		   void performtransfer() {
			   String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";

			   String^ enteredValue = textBox1->Text;
			   double parsedValue;
			   System::Double::TryParse(enteredValue, parsedValue);

			   String^ enteredname = textBox2->Text;

			   // Check if the current user has enough balance
			   User& currentUser = usertList.getElementAt(loggedInUserIndex);
			   double currentBalance = currentUser.getBankAccount().getBalance();

			   if (currentBalance < parsedValue) {
				   MessageBox::Show("Insufficient balance. Transfer cannot be completed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Retrieve the user to transfer funds to from the database
			   SqlConnection^ conn = gcnew SqlConnection(connString);
			   String^ selectUserQuery = "SELECT * FROM Banking WHERE Username = @Username";
			   SqlCommand^ selectUserCmd = gcnew SqlCommand(selectUserQuery, conn);
			   selectUserCmd->Parameters->AddWithValue("@Username", enteredname);

			   try {
				   conn->Open();
				   SqlDataReader^ reader = selectUserCmd->ExecuteReader();

				   if (reader->Read()) {
					   // User found in the database
					   double receiverBalance = System::Convert::ToDouble(reader["Userbalance"]);

					   // Update the balance of the user to transfer funds to
					   double newReceiverBalance = receiverBalance + parsedValue;
					   String^ updateReceiverQuery = "UPDATE Banking SET Userbalance = @NewBalance WHERE Username = @Username";
					   SqlCommand^ updateReceiverCmd = gcnew SqlCommand(updateReceiverQuery, conn);
					   updateReceiverCmd->Parameters->AddWithValue("@NewBalance", newReceiverBalance);
					   updateReceiverCmd->Parameters->AddWithValue("@Username", enteredname);
					   updateReceiverCmd->ExecuteNonQuery();

					   // Update the balance of the current user (subtract the transferred amount)
					   double newSenderBalance = currentBalance - parsedValue;
					   String^ updateSenderQuery = "UPDATE Banking SET Userbalance = @NewBalance WHERE Username = @Username";
					   SqlCommand^ updateSenderCmd = gcnew SqlCommand(updateSenderQuery, conn);
					   updateSenderCmd->Parameters->AddWithValue("@NewBalance", newSenderBalance);
					   updateSenderCmd->Parameters->AddWithValue("@Username", gcnew String(currentUser.getUsername().c_str()));
					   updateSenderCmd->ExecuteNonQuery();

					   // Update balances in memory
					   currentUser.getBankAccount().setBalance(newSenderBalance);
					   MessageBox::Show("Transfer successful!", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

					   // Update the user in the usertList
					   usertList.replaceElementAt(loggedInUserIndex, currentUser);
				   }
				   else {
					   // User not found in the database
					   MessageBox::Show("Recipient not found in database.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   }
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show("Failed to update database: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   finally {
				   conn->Close();
			   }
		   }


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		performtransfer();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
