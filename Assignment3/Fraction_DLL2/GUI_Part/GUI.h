#pragma once
#include "Fraction_DLL2.h"

namespace GUIPart {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
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
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  num1TB;
	private: System::Windows::Forms::TextBox^  denom1TB;
	private: System::Windows::Forms::TextBox^  num2TB;
	private: System::Windows::Forms::TextBox^  denom2TB;
	private: System::Windows::Forms::TextBox^  denomAnsTB;
	protected:

	protected:




	private: System::Windows::Forms::TextBox^  numAnsTB;
	private: System::Windows::Forms::CheckBox^  addCB;
	private: System::Windows::Forms::CheckBox^  subCB;

	private: System::Windows::Forms::CheckBox^  mulCB;
	private: System::Windows::Forms::CheckBox^  divCB;
	private: System::Windows::Forms::Button^  equalsBut;






	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->num1TB = (gcnew System::Windows::Forms::TextBox());
			this->denom1TB = (gcnew System::Windows::Forms::TextBox());
			this->num2TB = (gcnew System::Windows::Forms::TextBox());
			this->denom2TB = (gcnew System::Windows::Forms::TextBox());
			this->denomAnsTB = (gcnew System::Windows::Forms::TextBox());
			this->numAnsTB = (gcnew System::Windows::Forms::TextBox());
			this->addCB = (gcnew System::Windows::Forms::CheckBox());
			this->subCB = (gcnew System::Windows::Forms::CheckBox());
			this->mulCB = (gcnew System::Windows::Forms::CheckBox());
			this->divCB = (gcnew System::Windows::Forms::CheckBox());
			this->equalsBut = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// num1TB
			// 
			this->num1TB->Location = System::Drawing::Point(40, 41);
			this->num1TB->Name = L"num1TB";
			this->num1TB->Size = System::Drawing::Size(72, 20);
			this->num1TB->TabIndex = 0;
			this->num1TB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num1TB->TextChanged += gcnew System::EventHandler(this, &GUI::num1TB_TextChanged);
			// 
			// denom1TB
			// 
			this->denom1TB->Location = System::Drawing::Point(40, 109);
			this->denom1TB->Name = L"denom1TB";
			this->denom1TB->Size = System::Drawing::Size(72, 20);
			this->denom1TB->TabIndex = 1;
			this->denom1TB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->denom1TB->TextChanged += gcnew System::EventHandler(this, &GUI::denom1TB_TextChanged);
			// 
			// num2TB
			// 
			this->num2TB->Location = System::Drawing::Point(166, 41);
			this->num2TB->Name = L"num2TB";
			this->num2TB->Size = System::Drawing::Size(72, 20);
			this->num2TB->TabIndex = 3;
			this->num2TB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num2TB->TextChanged += gcnew System::EventHandler(this, &GUI::num2TB_TextChanged);
			// 
			// denom2TB
			// 
			this->denom2TB->Location = System::Drawing::Point(166, 109);
			this->denom2TB->Name = L"denom2TB";
			this->denom2TB->Size = System::Drawing::Size(72, 20);
			this->denom2TB->TabIndex = 4;
			this->denom2TB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->denom2TB->TextChanged += gcnew System::EventHandler(this, &GUI::denom2TB_TextChanged);
			// 
			// denomAnsTB
			// 
			this->denomAnsTB->Enabled = false;
			this->denomAnsTB->Location = System::Drawing::Point(311, 109);
			this->denomAnsTB->Name = L"denomAnsTB";
			this->denomAnsTB->Size = System::Drawing::Size(72, 20);
			this->denomAnsTB->TabIndex = 4;
			this->denomAnsTB->TabStop = false;
			this->denomAnsTB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// numAnsTB
			// 
			this->numAnsTB->Enabled = false;
			this->numAnsTB->Location = System::Drawing::Point(311, 41);
			this->numAnsTB->Name = L"numAnsTB";
			this->numAnsTB->Size = System::Drawing::Size(72, 20);
			this->numAnsTB->TabIndex = 5;
			this->numAnsTB->TabStop = false;
			this->numAnsTB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// addCB
			// 
			this->addCB->AutoSize = true;
			this->addCB->Location = System::Drawing::Point(128, 43);
			this->addCB->Name = L"addCB";
			this->addCB->Size = System::Drawing::Size(32, 17);
			this->addCB->TabIndex = 2;
			this->addCB->Text = L"+";
			this->addCB->UseVisualStyleBackColor = true;
			this->addCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::addCB_CheckedChanged);
			// 
			// subCB
			// 
			this->subCB->AutoSize = true;
			this->subCB->Location = System::Drawing::Point(128, 66);
			this->subCB->Name = L"subCB";
			this->subCB->Size = System::Drawing::Size(29, 17);
			this->subCB->TabIndex = 4;
			this->subCB->TabStop = false;
			this->subCB->Text = L"-";
			this->subCB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->subCB->UseVisualStyleBackColor = true;
			this->subCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::subCB_CheckedChanged);
			// 
			// mulCB
			// 
			this->mulCB->AutoSize = true;
			this->mulCB->Location = System::Drawing::Point(128, 89);
			this->mulCB->Name = L"mulCB";
			this->mulCB->Size = System::Drawing::Size(31, 17);
			this->mulCB->TabIndex = 5;
			this->mulCB->TabStop = false;
			this->mulCB->Text = L"x";
			this->mulCB->UseVisualStyleBackColor = true;
			this->mulCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::mulCB_CheckedChanged);
			// 
			// divCB
			// 
			this->divCB->AutoSize = true;
			this->divCB->Location = System::Drawing::Point(128, 112);
			this->divCB->Name = L"divCB";
			this->divCB->Size = System::Drawing::Size(31, 17);
			this->divCB->TabIndex = 6;
			this->divCB->TabStop = false;
			this->divCB->Text = L"/";
			this->divCB->UseVisualStyleBackColor = true;
			this->divCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::divCB_CheckedChanged);
			// 
			// equalsBut
			// 
			this->equalsBut->Location = System::Drawing::Point(256, 72);
			this->equalsBut->Name = L"equalsBut";
			this->equalsBut->Size = System::Drawing::Size(37, 23);
			this->equalsBut->TabIndex = 9;
			this->equalsBut->Text = L"=";
			this->equalsBut->UseVisualStyleBackColor = true;
			this->equalsBut->Click += gcnew System::EventHandler(this, &GUI::equalsBut_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"-------------------";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(164, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"-------------------";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(308, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"-------------------";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(37, 144);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Keyboard Shortcuts:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(38, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(125, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Close Application: Alt + C";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(37, 170);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Toggle Addition: Alt + Shift + \"=\"";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(37, 183);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(140, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Toggle Subtraction: Alt + \"-\"";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(38, 196);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(173, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Toggle Multiplication: Alt + Shift + 8";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(38, 209);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(125, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Toggle Division: Alt + \"/\"";
			// 
			// GUI
			// 
			this->AcceptButton = this->equalsBut;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 237);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->equalsBut);
			this->Controls->Add(this->divCB);
			this->Controls->Add(this->mulCB);
			this->Controls->Add(this->subCB);
			this->Controls->Add(this->addCB);
			this->Controls->Add(this->numAnsTB);
			this->Controls->Add(this->denomAnsTB);
			this->Controls->Add(this->denom2TB);
			this->Controls->Add(this->num2TB);
			this->Controls->Add(this->denom1TB);
			this->Controls->Add(this->num1TB);
			this->KeyPreview = true;
			this->Name = L"GUI";
			this->Text = L"Fraction Calculator by Chris Maltais";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::keyDownEvent);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) {
		// Load cursor to start here
		// Disable Textbox for answer
		// Enter key equivalent for equal button
		// Alt Key to close window
		// Close button should close window (close())
		// On Change of textboxes, all values should be wiped
	}

private: System::Void keyDownEvent(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->Alt && e->KeyCode == Keys::C) {
		this->Close();
	}
	if (e->Alt && e->Shift && e->KeyCode == Keys::Oemplus) {
		addCB->Checked = true;
	}
	if (e->Alt && e->KeyCode == Keys::OemMinus) {
		subCB->Checked = true;
	}
	if (e->Alt && e->Shift && e->KeyCode == Keys::D8) {
		mulCB->Checked = true;
	}
	if (e->Alt && e->KeyCode == Keys::OemQuestion) {
		divCB->Checked = true;
	}
	if (e->KeyCode == Keys::Enter) {
		this->Close();
	}
	
}

private: System::Void addCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (addCB->Checked) {
		subCB->Checked = false;
		mulCB->Checked = false;
		divCB->Checked = false;
	}
}

private: System::Void subCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (subCB->Checked) {
		addCB->Checked = false;
		mulCB->Checked = false;
		divCB->Checked = false;
	}
}

private: System::Void mulCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (mulCB->Checked) {
		subCB->Checked = false;
		addCB->Checked = false;
		divCB->Checked = false;
	}
}
private: System::Void divCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (divCB->Checked) {
		subCB->Checked = false;
		mulCB->Checked = false;
		addCB->Checked = false;
	}
}
private: System::Void equalsBut_Click(System::Object^  sender, System::EventArgs^  e) {
	int num1;
	int denom1;
	int num2;
	int denom2;

	// Handles no operator selected
	if (addCB->Checked == false && subCB->Checked == false && mulCB->Checked == false && divCB->Checked == false) {
		MessageBox::Show("Error: Must select an operation!");
		return;
	}

	// Handles empty fraction
	if (num1TB->Text == "" || num2TB->Text == "" || denom1TB->Text == "" || denom2TB->Text == "") {
		MessageBox::Show("Error: Please ensure all text boxes are populated.");
		return;
	}
	
	// This handles non-int for Fraction1 numerator
	try {
		String^ num1str = num1TB->Text;
		num1 = Convert::ToInt32(num1str);
	} catch (...) {
		MessageBox::Show("Please enter a valid integer in the numerator of the first fraction!");
		return;
	}

	// This handles non-int for Fraction2 numerator
	try {
		String^ num2str = num2TB->Text;
		num2 = Convert::ToInt32(num2str);
	}
	catch (...) {
		MessageBox::Show("Please enter a valid integer in the numerator of the second fraction!");
		return;
	}

	// This handles non-int for Fraction1 denominator
	try {
		String^ denom1str = denom1TB->Text;
		denom1 = Convert::ToInt32(denom1str);
	}
	catch (...) {
		MessageBox::Show("Please enter a valid integer in the denominator of the first fraction!");
		return;
	}

	// This handles non-int for Fraction2 denominator
	try {
		String^ denom2str = denom2TB->Text;
		denom2 = Convert::ToInt32(denom2str);
	}
	catch (...) {
		MessageBox::Show("Please enter a valid integer in the denominator of the second fraction!");
		return;
	}

	// This handles 0 for denominator of first fraction
	if (denom1 == 0) {
		MessageBox::Show("Error: Denominator of Fraction 1 cannot be 0!");
		return;
	}

	// This handles 0 for denominator of second fraction
	if (denom2 == 0) {
		MessageBox::Show("Error: Denominator of Fraction 2 cannot be 0!");
		return;
	}

	int* ans;

	if (addCB->Checked) {
		ans = addFrac(num1, denom1, num2, denom2);
		cout << ans[0] << "/" << ans[1] << endl;
	} else if (subCB->Checked) {
		ans = subFrac(num1, denom1, num2, denom2);
	} else if (mulCB->Checked) {
		ans = multFrac(num1, denom1, num2, denom2);
	} else if (divCB->Checked) {
		ans = divFrac(num1, denom1, num2, denom2);
	}

	numAnsTB->Text = Convert::ToString(ans[0]);
	denomAnsTB->Text = Convert::ToString(ans[1]);

	// If result is negative, only numerator negative
}

// On textbox change, wipe answer
private: System::Void denom2TB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	numAnsTB->Text = "";
	denomAnsTB->Text = "";
}
private: System::Void num2TB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	numAnsTB->Text = "";
	denomAnsTB->Text = "";
}
private: System::Void denom1TB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	numAnsTB->Text = "";
	denomAnsTB->Text = "";
}
private: System::Void num1TB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	numAnsTB->Text = "";
	denomAnsTB->Text = "";
}

};
}
