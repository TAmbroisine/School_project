#pragma once

namespace ProjetMASTERMINDLAM_NGUYENAMBROISINE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Score
	/// </summary>
	public ref class Score : public System::Windows::Forms::Form
	{
	public:
		Score(array <Int32> ^tabScore)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			txtScore1->Text= tabScore[0].ToString()+" tentatives";
			txtScore2->Text= tabScore[1].ToString()+" tentatives";
			txtScore3->Text= tabScore[2].ToString()+" tentatives";
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Score()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtScore1;
	private: System::Windows::Forms::TextBox^  txtScore2;
	private: System::Windows::Forms::TextBox^  txtScore3;



	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtScore1 = (gcnew System::Windows::Forms::TextBox());
			this->txtScore2 = (gcnew System::Windows::Forms::TextBox());
			this->txtScore3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Score 1";
			this->label1->Click += gcnew System::EventHandler(this, &Score::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(46, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// txtScore1
			// 
			this->txtScore1->Location = System::Drawing::Point(138, 29);
			this->txtScore1->Name = L"txtScore1";
			this->txtScore1->ReadOnly = true;
			this->txtScore1->Size = System::Drawing::Size(107, 20);
			this->txtScore1->TabIndex = 3;
			// 
			// txtScore2
			// 
			this->txtScore2->Location = System::Drawing::Point(138, 112);
			this->txtScore2->Name = L"txtScore2";
			this->txtScore2->ReadOnly = true;
			this->txtScore2->Size = System::Drawing::Size(107, 20);
			this->txtScore2->TabIndex = 4;
			// 
			// txtScore3
			// 
			this->txtScore3->Location = System::Drawing::Point(138, 186);
			this->txtScore3->Name = L"txtScore3";
			this->txtScore3->ReadOnly = true;
			this->txtScore3->Size = System::Drawing::Size(107, 20);
			this->txtScore3->TabIndex = 5;
			// 
			// Score
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->txtScore3);
			this->Controls->Add(this->txtScore2);
			this->Controls->Add(this->txtScore1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Score";
			this->Text = L"Score";
			this->Load += gcnew System::EventHandler(this, &Score::Score_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Score_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
