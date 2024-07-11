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
	/// Summary for checkbalance
	/// </summary>
	public ref class checkbalance : public System::Windows::Forms::Form
	{
	public:
		checkbalance(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		checkbalance(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~checkbalance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Label^ label2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(checkbalance::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(75, 202);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(76, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"CHECK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &checkbalance::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(43, 36);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"BALANCE:";
			this->label1->Click += gcnew System::EventHandler(this, &checkbalance::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(80, 96);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 31);
			this->label2->TabIndex = 2;
			// 
			// checkbalance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(418, 325);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"checkbalance";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"checkbalance";
			this->Load += gcnew System::EventHandler(this, &checkbalance::checkbalance_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void performcheckbalance() {
			// Connection string
			String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\user\\Documents\\Banking.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False";

			// Get the currently logged-in user
			User currentUser = usertList.getElementAt(loggedInUserIndex);
			String^ currentUsername = gcnew String(currentUser.getUsername().c_str());

			// Create a connection to the database
			SqlConnection^ conn = gcnew SqlConnection(connString);

			try {
				// Open the connection
				conn->Open();

				// SQL query to get the balance of the currently logged-in user
				String^ query = "SELECT Userbalance FROM Banking WHERE Username = @Username";
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@Username", currentUsername);

				// Execute the query and get the balance
				SqlDataReader^ reader = cmd->ExecuteReader();
				if (reader->Read()) {
					String^ balanceStr = reader["Userbalance"]->ToString();
					double balance;
					if (System::Double::TryParse(balanceStr, balance)) {
						label2->Text = "$" + balance;
					}
					else {
						MessageBox::Show("Failed to parse the balance from the database.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					MessageBox::Show("Failed to retrieve the balance from the database.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				// Close the reader
				reader->Close();
			}
			catch (Exception^ ex) {
				// Handle any errors that may have occurred
				MessageBox::Show("Failed to retrieve balance: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				// Close the connection
				conn->Close();
			}
		}


	private: System::Void checkbalance_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		performcheckbalance();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
