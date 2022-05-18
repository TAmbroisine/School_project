#pragma once
#include <windows.h>
#include <winuser.h>
#include "Pion.h"
#include "Score.h"
#include "Aide.h"
#include "Copyright.h"
#include "SiteWeb.h"

namespace ProjetMASTERMINDLAM_NGUYENAMBROISINE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  pnlJeu;
	protected: 
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Panel^  pnlSolution;
	private: System::Windows::Forms::Panel^  pnlPions;
	private: System::Windows::Forms::PictureBox^  picBleu;
	private: System::Windows::Forms::PictureBox^  picJaune;
	private: System::Windows::Forms::PictureBox^  picRouge;
	private: System::Windows::Forms::PictureBox^  picVert;
	private: System::Windows::Forms::PictureBox^  picGris;
	private: System::Windows::Forms::PictureBox^  picViolet;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  jeuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nouvellePartieToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  scoreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aProposToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyrightToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  liensWEBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortirToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  txt;
	private: System::Windows::Forms::TextBox^  txt1;
	private: System::Windows::Forms::Button^  btnChoix;
	private: System::Windows::Forms::PictureBox^  picSol4;
	private: System::Windows::Forms::PictureBox^  picSol3;
	private: System::Windows::Forms::PictureBox^  picSol2;
	private: System::Windows::Forms::PictureBox^  picSol1;
	private: System::Windows::Forms::Button^  btnSolution;
	private: System::Windows::Forms::PictureBox^  picBlank;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pnlJeu = (gcnew System::Windows::Forms::Panel());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->pnlSolution = (gcnew System::Windows::Forms::Panel());
			this->picBlank = (gcnew System::Windows::Forms::PictureBox());
			this->picSol4 = (gcnew System::Windows::Forms::PictureBox());
			this->picSol3 = (gcnew System::Windows::Forms::PictureBox());
			this->picSol2 = (gcnew System::Windows::Forms::PictureBox());
			this->picSol1 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlPions = (gcnew System::Windows::Forms::Panel());
			this->picBleu = (gcnew System::Windows::Forms::PictureBox());
			this->picJaune = (gcnew System::Windows::Forms::PictureBox());
			this->picRouge = (gcnew System::Windows::Forms::PictureBox());
			this->picVert = (gcnew System::Windows::Forms::PictureBox());
			this->picGris = (gcnew System::Windows::Forms::PictureBox());
			this->picViolet = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->jeuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nouvellePartieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aProposToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyrightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->liensWEBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->txt = (gcnew System::Windows::Forms::TextBox());
			this->txt1 = (gcnew System::Windows::Forms::TextBox());
			this->btnChoix = (gcnew System::Windows::Forms::Button());
			this->btnSolution = (gcnew System::Windows::Forms::Button());
			this->pnlSolution->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBlank))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol1))->BeginInit();
			this->pnlPions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBleu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picJaune))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picRouge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picVert))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picGris))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picViolet))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlJeu
			// 
			this->pnlJeu->AllowDrop = true;
			this->pnlJeu->BackColor = System::Drawing::Color::Transparent;
			this->pnlJeu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pnlJeu.BackgroundImage")));
			this->pnlJeu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlJeu->Location = System::Drawing::Point(400, 36);
			this->pnlJeu->Name = L"pnlJeu";
			this->pnlJeu->Size = System::Drawing::Size(258, 653);
			this->pnlJeu->TabIndex = 0;
			this->pnlJeu->Click += gcnew System::EventHandler(this, &Form1::pnlJeu_Click);
			this->pnlJeu->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::pnlJeu_DragDrop);
			this->pnlJeu->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::pnlJeu_DragEnter);
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(21, 36);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(182, 49);
			this->btnStart->TabIndex = 1;
			this->btnStart->Text = L"Nouveau Jeu";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// pnlSolution
			// 
			this->pnlSolution->BackColor = System::Drawing::Color::Navy;
			this->pnlSolution->Controls->Add(this->picBlank);
			this->pnlSolution->Controls->Add(this->picSol4);
			this->pnlSolution->Controls->Add(this->picSol3);
			this->pnlSolution->Controls->Add(this->picSol2);
			this->pnlSolution->Controls->Add(this->picSol1);
			this->pnlSolution->Location = System::Drawing::Point(18, 282);
			this->pnlSolution->Name = L"pnlSolution";
			this->pnlSolution->Size = System::Drawing::Size(286, 71);
			this->pnlSolution->TabIndex = 2;
			// 
			// picBlank
			// 
			this->picBlank->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picBlank->Location = System::Drawing::Point(273, 3);
			this->picBlank->Name = L"picBlank";
			this->picBlank->Size = System::Drawing::Size(10, 12);
			this->picBlank->TabIndex = 4;
			this->picBlank->TabStop = false;
			// 
			// picSol4
			// 
			this->picSol4->Location = System::Drawing::Point(215, 17);
			this->picSol4->Name = L"picSol4";
			this->picSol4->Size = System::Drawing::Size(47, 40);
			this->picSol4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picSol4->TabIndex = 3;
			this->picSol4->TabStop = false;
			// 
			// picSol3
			// 
			this->picSol3->Location = System::Drawing::Point(147, 17);
			this->picSol3->Name = L"picSol3";
			this->picSol3->Size = System::Drawing::Size(47, 40);
			this->picSol3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picSol3->TabIndex = 2;
			this->picSol3->TabStop = false;
			// 
			// picSol2
			// 
			this->picSol2->Location = System::Drawing::Point(76, 17);
			this->picSol2->Name = L"picSol2";
			this->picSol2->Size = System::Drawing::Size(47, 40);
			this->picSol2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picSol2->TabIndex = 1;
			this->picSol2->TabStop = false;
			// 
			// picSol1
			// 
			this->picSol1->Location = System::Drawing::Point(3, 17);
			this->picSol1->Name = L"picSol1";
			this->picSol1->Size = System::Drawing::Size(47, 40);
			this->picSol1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picSol1->TabIndex = 0;
			this->picSol1->TabStop = false;
			// 
			// pnlPions
			// 
			this->pnlPions->AllowDrop = true;
			this->pnlPions->BackColor = System::Drawing::Color::Navy;
			this->pnlPions->Controls->Add(this->picBleu);
			this->pnlPions->Controls->Add(this->picJaune);
			this->pnlPions->Controls->Add(this->picRouge);
			this->pnlPions->Controls->Add(this->picVert);
			this->pnlPions->Controls->Add(this->picGris);
			this->pnlPions->Controls->Add(this->picViolet);
			this->pnlPions->Location = System::Drawing::Point(18, 155);
			this->pnlPions->Name = L"pnlPions";
			this->pnlPions->Size = System::Drawing::Size(323, 71);
			this->pnlPions->TabIndex = 3;
			// 
			// picBleu
			// 
			this->picBleu->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picBleu.Image")));
			this->picBleu->Location = System::Drawing::Point(3, 14);
			this->picBleu->Name = L"picBleu";
			this->picBleu->Size = System::Drawing::Size(47, 40);
			this->picBleu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBleu->TabIndex = 5;
			this->picBleu->TabStop = false;
			this->picBleu->Tag = L"1";
			this->picBleu->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click_1);
			this->picBleu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picBleu->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picBleu->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picBleu->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picBleu->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// picJaune
			// 
			this->picJaune->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picJaune.Image")));
			this->picJaune->Location = System::Drawing::Point(56, 14);
			this->picJaune->Name = L"picJaune";
			this->picJaune->Size = System::Drawing::Size(47, 40);
			this->picJaune->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picJaune->TabIndex = 4;
			this->picJaune->TabStop = false;
			this->picJaune->Tag = L"2";
			this->picJaune->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click);
			this->picJaune->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picJaune->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picJaune->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picJaune->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picJaune->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// picRouge
			// 
			this->picRouge->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picRouge.Image")));
			this->picRouge->Location = System::Drawing::Point(109, 14);
			this->picRouge->Name = L"picRouge";
			this->picRouge->Size = System::Drawing::Size(47, 40);
			this->picRouge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picRouge->TabIndex = 3;
			this->picRouge->TabStop = false;
			this->picRouge->Tag = L"3";
			this->picRouge->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click);
			this->picRouge->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picRouge->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picRouge->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picRouge->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picRouge->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// picVert
			// 
			this->picVert->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picVert.Image")));
			this->picVert->Location = System::Drawing::Point(162, 14);
			this->picVert->Name = L"picVert";
			this->picVert->Size = System::Drawing::Size(47, 40);
			this->picVert->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picVert->TabIndex = 2;
			this->picVert->TabStop = false;
			this->picVert->Tag = L"4";
			this->picVert->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click);
			this->picVert->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picVert->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picVert->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picVert->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picVert->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// picGris
			// 
			this->picGris->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picGris.Image")));
			this->picGris->Location = System::Drawing::Point(215, 14);
			this->picGris->Name = L"picGris";
			this->picGris->Size = System::Drawing::Size(47, 40);
			this->picGris->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picGris->TabIndex = 1;
			this->picGris->TabStop = false;
			this->picGris->Tag = L"5";
			this->picGris->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click);
			this->picGris->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picGris->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picGris->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picGris->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picGris->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// picViolet
			// 
			this->picViolet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->picViolet->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picViolet.Image")));
			this->picViolet->Location = System::Drawing::Point(268, 14);
			this->picViolet->Name = L"picViolet";
			this->picViolet->Size = System::Drawing::Size(47, 40);
			this->picViolet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picViolet->TabIndex = 0;
			this->picViolet->TabStop = false;
			this->picViolet->Tag = L"6";
			this->picViolet->Click += gcnew System::EventHandler(this, &Form1::picBleu_Click);
			this->picViolet->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseDown);
			this->picViolet->MouseLeave += gcnew System::EventHandler(this, &Form1::picBleu_MouseLeave);
			this->picViolet->MouseHover += gcnew System::EventHandler(this, &Form1::picBleu_MouseHover);
			this->picViolet->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseMove);
			this->picViolet->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picBleu_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->jeuToolStripMenuItem, 
				this->aideToolStripMenuItem, this->aProposToolStripMenuItem, this->sortirToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(844, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// jeuToolStripMenuItem
			// 
			this->jeuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->nouvellePartieToolStripMenuItem, 
				this->scoreToolStripMenuItem});
			this->jeuToolStripMenuItem->Name = L"jeuToolStripMenuItem";
			this->jeuToolStripMenuItem->Size = System::Drawing::Size(36, 20);
			this->jeuToolStripMenuItem->Text = L"Jeu";
			// 
			// nouvellePartieToolStripMenuItem
			// 
			this->nouvellePartieToolStripMenuItem->Name = L"nouvellePartieToolStripMenuItem";
			this->nouvellePartieToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->nouvellePartieToolStripMenuItem->Text = L"Nouvelle partie";
			this->nouvellePartieToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// scoreToolStripMenuItem
			// 
			this->scoreToolStripMenuItem->Name = L"scoreToolStripMenuItem";
			this->scoreToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->scoreToolStripMenuItem->Text = L"Score";
			this->scoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::scoreToolStripMenuItem_Click);
			// 
			// aideToolStripMenuItem
			// 
			this->aideToolStripMenuItem->Name = L"aideToolStripMenuItem";
			this->aideToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->aideToolStripMenuItem->Text = L"Aide";
			this->aideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aideToolStripMenuItem_Click);
			// 
			// aProposToolStripMenuItem
			// 
			this->aProposToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->copyrightToolStripMenuItem, 
				this->liensWEBToolStripMenuItem});
			this->aProposToolStripMenuItem->Name = L"aProposToolStripMenuItem";
			this->aProposToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->aProposToolStripMenuItem->Text = L"A propos";
			// 
			// copyrightToolStripMenuItem
			// 
			this->copyrightToolStripMenuItem->Name = L"copyrightToolStripMenuItem";
			this->copyrightToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copyrightToolStripMenuItem->Text = L"Copyright";
			this->copyrightToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyrightToolStripMenuItem_Click);
			// 
			// liensWEBToolStripMenuItem
			// 
			this->liensWEBToolStripMenuItem->Name = L"liensWEBToolStripMenuItem";
			this->liensWEBToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->liensWEBToolStripMenuItem->Text = L"Liens WEB";
			this->liensWEBToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::liensWEBToolStripMenuItem_Click);
			// 
			// sortirToolStripMenuItem
			// 
			this->sortirToolStripMenuItem->Name = L"sortirToolStripMenuItem";
			this->sortirToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->sortirToolStripMenuItem->Text = L"Sortir";
			this->sortirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sortirToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(844, 674);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(18, 123);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(50, 26);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Pion:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(18, 250);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(72, 26);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"Solution:";
			// 
			// txt
			// 
			this->txt->Location = System::Drawing::Point(689, 101);
			this->txt->Name = L"txt";
			this->txt->ReadOnly = true;
			this->txt->Size = System::Drawing::Size(100, 20);
			this->txt->TabIndex = 8;
			// 
			// txt1
			// 
			this->txt1->Location = System::Drawing::Point(689, 129);
			this->txt1->Name = L"txt1";
			this->txt1->ReadOnly = true;
			this->txt1->Size = System::Drawing::Size(100, 20);
			this->txt1->TabIndex = 9;
			// 
			// btnChoix
			// 
			this->btnChoix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnChoix->Location = System::Drawing::Point(669, 39);
			this->btnChoix->Name = L"btnChoix";
			this->btnChoix->Size = System::Drawing::Size(135, 45);
			this->btnChoix->TabIndex = 10;
			this->btnChoix->Text = L"Confirmer Choix";
			this->btnChoix->UseVisualStyleBackColor = true;
			this->btnChoix->Click += gcnew System::EventHandler(this, &Form1::btnChoix_Click);
			// 
			// btnSolution
			// 
			this->btnSolution->Location = System::Drawing::Point(18, 359);
			this->btnSolution->Name = L"btnSolution";
			this->btnSolution->Size = System::Drawing::Size(123, 40);
			this->btnSolution->TabIndex = 11;
			this->btnSolution->Text = L"Montrer Solution";
			this->btnSolution->UseVisualStyleBackColor = true;
			this->btnSolution->Click += gcnew System::EventHandler(this, &Form1::btnSolution_Click);
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 701);
			this->Controls->Add(this->btnSolution);
			this->Controls->Add(this->btnChoix);
			this->Controls->Add(this->txt1);
			this->Controls->Add(this->txt);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pnlPions);
			this->Controls->Add(this->pnlSolution);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pnlJeu);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"MasterMind";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->pnlSolution->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBlank))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picSol1))->EndInit();
			this->pnlPions->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picBleu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picJaune))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picRouge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picVert))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picGris))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picViolet))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Random ^ NombreAlea;
	int x;
    int y;
	Int32 color;
	private : PictureBox ^pictureBox;
	array <Int32> ^ tabJ;
	array <Int32> ^ tabO;
	array <Int32> ^ tabS;
	array <Int32> ^ tabBN;
	Pion ^pionOBJ;
	array <Image^> ^tabImage;

	private: System::Void pnlJeu_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
					/*POINT pos;
					POINT pospanel;
					HWND hWndForm1 = static_cast<HWND>(this->Handle.ToPointer());
					HWND hWndForm1 = NULL;
					 Handle fenêtre principale


					 Récupère le Handle de fenêtre


					hWndForm1 = (HWND)this->get_Handle().ToInt32();
					GetCursorPos(&pos); 
					ScreenToClient(hWndForm1,&pos);
					this.pictureLocation = this.PointToClient(new Point(e.X, e.Y) );
					pos = this->PointToClient( );*/

			 }
private: System::Void picBleu_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			/*// l'objet sender, qui est le radiobutton dont la sélection 
			 // a changé, est converti en référence de radiobutton
			 PictureBox ^picSender = safe_cast <PictureBox ^>  (sender);
			 // l'indice du radiobutton sélectionné est récupéré à partir
			 // du groupbox et de sa collection de contrôles. 
			 // Les indices sont affectés dans le groupbox par ordre 
			 // inverse de dépôt des composants dans le groupbox.
			 // dernier posé = indice 0.
			 color= pnlPions->Controls->IndexOf(picSender);
			 txt->Text="test";//color.ToString();*/


		 }
private: System::Void picBleu_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {

			 if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				x = e->X;
				y = e->Y;
			}
			DoDragDrop(sender, DragDropEffects::Move);
			/*// l'objet sender, qui est le radiobutton dont la sélection 
			 // a changé, est converti en référence de radiobutton
			 PictureBox ^picSender = safe_cast <PictureBox ^>  (sender);
			 // l'indice du radiobutton sélectionné est récupéré à partir
			 // du groupbox et de sa collection de contrôles. 
			 // Les indices sont affectés dans le groupbox par ordre 
			 // inverse de dépôt des composants dans le groupbox.
			 // dernier posé = indice 0.
			 color= pnlPions->Controls->IndexOf(picSender);*/
			 
			
		 }
private: System::Void picBleu_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{

				picBleu->Left += (e->X - x);
				picBleu->Top += (e->Y - y);
				picBleu->BringToFront() ;
			}
		 }
private: System::Void pnlJeu_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
		 {
			 //if (e->Data->GetDataPresent("System.Drawing.Bitmap"))
			//{
				e->Effect = DragDropEffects::Copy;
				e->Effect = DragDropEffects::Move;
			//}
			/*else
			{
				e->Effect = DragDropEffects::None;
			}*/
		 }
private: System::Void picBleu_MouseHover(System::Object^  sender, System::EventArgs^  e) 
		 {
			Point mouseLocation = Point(0, 0);
			mouseLocation = this->PointToClient(Cursor->Position);
		 }
private: System::Void picBleu_MouseLeave(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void picBleu_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 //pictureBox->Location = Point(3, 14);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i=0;
			 pionOBJ= gcnew Pion();
			 tabJ= gcnew array <Int32>{-1,-1,-1,-1,0};
			 tabS= gcnew array <Int32>{0,0,0,0};
			 tabO= gcnew array <Int32>{0,0,0,0};
			 tabBN= gcnew array <Int32>{0,0};
			 tabImage= gcnew array <Image^> {picBleu->Image,picJaune->Image,picRouge->Image,picVert->Image,picGris->Image,picViolet->Image};
			 NombreAlea = gcnew Random();
			 pionOBJ->GenererSolution(tabS,NombreAlea);
		 }
private: System::Void pnlJeu_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) 
		 {
			 /*
			 1er case=403;9
			 2e case=466;9
			 3e case=532;9
			 4e case=590;9
			 */
			 //-----------Détermination de la couleur du pion-----------//

			 // l'objet sender, qui est le radiobutton dont la sélection 
			 // a changé, est converti en référence de radiobutton
			 PictureBox ^picSource = safe_cast <PictureBox ^>  (e->Data->GetData("System.Windows.Forms.PictureBox"));
			 // l'indice du radiobutton sélectionné est récupéré à partir
			 // du groupbox et de sa collection de contrôles. 
			 // Les indices sont affectés dans le groupbox par ordre 
			 // inverse de dépôt des composants dans le groupbox.
			 // dernier posé = indice 0.
			 color= pnlPions->Controls->IndexOf(picSource);

			 //---------------------------------------------------------//
			 Point mouseLocation = Point(0, 0);
			 //-----------Placement du pion-----------//
			 mouseLocation = this->PointToClient(Cursor->Position);
			pictureBox = gcnew PictureBox();
			pionOBJ->GenererPion(safe_cast <PictureBox ^>  (e->Data->GetData("System.Windows.Forms.PictureBox")), pictureBox ,tabJ,mouseLocation,color);
			 pnlJeu->Controls->Add(pictureBox);
			 pictureBox->BringToFront();
			 //---------------------------------------//
		 }
private: System::Void picBleu_Click_1(System::Object^  sender, System::EventArgs^  e)
		 {
			 
		 }
private: System::Void btnChoix_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i=0;
			 int j=0;
			 int compt=0;
			 for (i=0;i<4;i=i+1)
			 {
				 //Vérification pour s'assurer que la ligne a corrigé est remplie
				 if (tabJ[i]!=-1)
				 {
					 compt=compt+1;
				 }
			 }
			 if (compt==4)
			 {
				//comparaison avec la solution
				pionOBJ->Comparaison(tabJ,tabS,tabO,tabBN);
				//affichage du nombre de pions blancs et noirs
				 txt->Text=(tabBN[0].ToString()+" Noir(s)");
				 txt1->Text=(tabBN[1].ToString()+" Blanc(s)");
				 //Remise a zero du nombre de pions blancs et noirs 
				 tabBN[0]=0;
				 tabBN[1]=0;
				 for (i=0;i<4;i++)
				 {
					 tabJ[i]=-1;
				 }

			 }
			 else
			 {
				 MessageBox::Show("Placez les billes dans les 4 cases de la lignes" );
			 }
		 }
private: System::Void btnSolution_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 //Affichage de la solution
			 pionOBJ->GenererSolution(tabS,tabImage,0,picSol1);
			 pionOBJ->GenererSolution(tabS,tabImage,1,picSol2);
			 pionOBJ->GenererSolution(tabS,tabImage,2,picSol3);
			 pionOBJ->GenererSolution(tabS,tabImage,3,picSol4);
		 }
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i;
			 int j;
			 //suppression des pions situés sur la grille
			 for (j=0;j<7;j++)
			 {
				 for (i=0;i<pnlJeu->Controls->Count;i++)
				 {
					pnlJeu->Controls->Remove(pnlJeu->Controls[i]);
				 }
			 }
			 txt->Text=" ";
			 txt1->Text=" ";
			 tabJ[4]=0;
			 //Reset des PictureBox de la solution
			 picSol1->Image=picBlank->Image;
			 picSol2->Image=picBlank->Image;
			 picSol3->Image=picBlank->Image;
			 picSol4->Image=picBlank->Image;
			 //Génération d'une nouvelle solution
			 pionOBJ->GenererSolution(tabS,NombreAlea);
		 }
private: System::Void scoreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Déclaration et création d'une fenêtre de la classe HighScores
			Score^ frmScore= gcnew Score(pionOBJ->tabHighScores);
			// ouverture modale de la Form créée (elle restera en premier plan tant qu'elle ne sera pas fermée : elle bloque l'application)
			frmScore->ShowDialog();
		 }
private: System::Void aideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Déclaration et création d'une FormModale
			Aide ^ frmAide= gcnew Aide();
			// ouverture non modale de la Form créée (elle ne bloque pas la fenêtre principale)
			frmAide->Show();
		 }

private: System::Void sortirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 // quitter l’application
			 Close();
		 }
private: System::Void copyrightToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Déclaration et création d'une FormModale
			Copyright ^ frmCopyright= gcnew Copyright();
			// ouverture non modale de la Form créée (elle ne bloque pas la fenêtre principale)
			frmCopyright->Show();
		 }
private: System::Void liensWEBToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 // Déclaration et création d'une FormModale
			SiteWeb ^ frmSiteWeb= gcnew SiteWeb();
			// ouverture non modale de la Form créée (elle ne bloque pas la fenêtre principale)
			frmSiteWeb->Show();
		 }
};
}

