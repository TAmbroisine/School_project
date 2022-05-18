using namespace System;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;
#pragma once


ref class Pion
{
public:
	Pion(void);
	void GenererPion(PictureBox ^picPion,PictureBox ^, array <Int32> ^ ,Point ^,Int32 );
	void Pion::GenererSolution(array <Int32> ^,Random ^);
	void Pion::Comparaison(array <Int32> ^ ,array <Int32> ^ ,array <Int32> ^ ,array <Int32> ^ );
	void Pion::GenererSolution(array <Int32> ^ ,array <System::Drawing::Image ^> ^,Int32 ,PictureBox ^);
	// tableau des highScores
	array <Int32> ^tabHighScores;
	// indice courant du tableau des highScores où le nouveau score sera stocké
	Int32 iHighScores;
	void Pion::SauverScore(array <Int32> ^);
};
