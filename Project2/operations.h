#pragma once
#ifndef MYFORMop_H
#define MYFORMop_H
#include "depositform.h"
#include "withdrawform.h"
#include "checkbalance.h"
#include "transfer.h"
#include "accountdetails.h"
#include "changepass.h"

namespace Project2 {
	extern LinkedList<User> usertList;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for operations
	/// </summary>
	public ref class operations : public System::Windows::Forms::Form
	{

		public:
			operations(void) {
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

			operations(int userIndex) {
				// Initialize the form
				InitializeComponent();
				// Use 'user' as needed
				loggedInUserIndex = userIndex;
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~operations() {

				if (components) {
					delete components;
				}
			}

		private: System::Windows::Forms::Button^ deposit;
		private: int loggedInUserIndex;
		private: System::Windows::Forms::Button^ withdraw;


		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::Button^ button4;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button5;

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
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(operations::typeid));
			this->deposit = (gcnew System::Windows::Forms::Button());
			this->withdraw = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// deposit
			// 
			this->deposit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->deposit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deposit.Image")));
			this->deposit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->deposit->Location = System::Drawing::Point(23, 142);
			this->deposit->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->deposit->Name = L"deposit";
			this->deposit->Size = System::Drawing::Size(140, 53);
			this->deposit->TabIndex = 0;
			this->deposit->Text = L"Deposit";
			this->deposit->UseVisualStyleBackColor = true;
			this->deposit->Click += gcnew System::EventHandler(this, &operations::deposit_Click);
			// 
			// withdraw
			// 
			this->withdraw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->withdraw->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"withdraw.Image")));
			this->withdraw->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->withdraw->Location = System::Drawing::Point(191, 142);
			this->withdraw->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->withdraw->Name = L"withdraw";
			this->withdraw->Size = System::Drawing::Size(136, 53);
			this->withdraw->TabIndex = 1;
			this->withdraw->Text = L"Withdraw";
			this->withdraw->UseVisualStyleBackColor = true;
			this->withdraw->Click += gcnew System::EventHandler(this, &operations::withdraw_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(23, 252);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 53);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Check Balance";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &operations::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(191, 252);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(136, 53);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Transfer";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &operations::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(23, 373);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 53);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Account Info";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &operations::button4_Click_1);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(191, 373);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 53);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Change Password";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &operations::button2_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(22, 27);
			this->button5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(58, 31);
			this->button5->TabIndex = 6;
			this->button5->Text = L"BACK";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &operations::button5_Click);
			// 
			// operations
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(652, 463);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->withdraw);
			this->Controls->Add(this->deposit);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"operations";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"operations";
			this->Load += gcnew System::EventHandler(this, &operations::operations_Load);
			this->ResumeLayout(false);
		}

		// ---------------------functions---------------------

		#pragma endregion
		private: System::Void operations_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void withdraw_Click(System::Object^ sender, System::EventArgs^ e) {

			withdrawform^ withdrawFormInstance = gcnew withdrawform(loggedInUserIndex);

			this->Hide();

			withdrawFormInstance->ShowDialog();

			this->Show();

		}

		private: System::Void deposit_Click(System::Object^ sender, System::EventArgs^ e) {

			// Assuming 'loggedInUserIndex' is a variable that exists and is accessible in this scope
			depositform^ checkFormInstance = gcnew depositform(loggedInUserIndex);

			this->Hide();  // Hide the current form

			checkFormInstance->ShowDialog();  // Show the check balance form as a modal dialog

			this->Show();  // Show the current form again after the dialog is closed
		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			checkbalance^ checkFormInstance = gcnew checkbalance(loggedInUserIndex);

			this->Hide();

			checkFormInstance->ShowDialog();

			this->Show();
		}

		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {

			accountdetails^ checkFormInstance = gcnew accountdetails(loggedInUserIndex);

			this->Hide();

			checkFormInstance->ShowDialog();

			this->Show();
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

			transfer^ transferFormInstance = gcnew transfer(loggedInUserIndex);

			this->Hide();

			transferFormInstance->ShowDialog();

			this->Show();
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			changepass^ transferFormInstance = gcnew changepass(loggedInUserIndex);

			this->Hide();

			transferFormInstance->ShowDialog();

			this->Show();
		}

		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

			this->Close();
		}		
	}; /* end of class */
} /* end of namespace */

#endif // MYFORMop_H