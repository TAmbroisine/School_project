#include "StdAfx.h"
#include "Pion.h"




Pion::Pion(void)
{
	iHighScores= 0;
	// création et initialisation tableaux des highScores
	tabHighScores= gcnew array <Int32>{0,0,0};
}
void Pion::GenererPion(PictureBox ^picPion,PictureBox ^picNew, array <Int32> ^ tabJ,Point ^mouseLocation,Int32 color)
{
		Int32 y;
		//Paramètrage du pion
		picNew->Image = picPion->Image;
		picNew->SizeMode = picPion->SizeMode;
		picNew->Top = 20; 
		picNew->Width = 47;
		picNew->Height = 40;
		picNew->Left = 10;

		//Varitation du Y du pions en fonction de la ligne donnée par TabJ[4]
		if (tabJ[4]<=6)
		{
			y=51;
		}
		else if (tabJ[4]<=9 )
		{
			y=45+tabJ[4];
		}
		else
		{
			y=54;
		}
		//Varitation du X du pions en fonction de la position de la souris et attribution de la couleur à la case tabJ[i] correspondante
		if (mouseLocation->X<=434)
		{
			picNew->Location = Point(3, tabJ[4]*y+9);
			tabJ[0]=color;
		}
		else if (mouseLocation->X>434 && mouseLocation->X<=499)
		{
			picNew->Location = Point(66, tabJ[4]*y+9);
			tabJ[1]=color;
		}
		else if (mouseLocation->X>499 && mouseLocation->X<=561)
		{
			picNew->Location = Point(132, tabJ[4]*y+9);
			tabJ[2]=color;
		}
		else if (mouseLocation->X>561)
		{
			picNew->Location = Point(190, tabJ[4]*y+9);
			tabJ[3]=color;
		}
		picNew->AllowDrop = true;
}
void Pion::GenererSolution(array <Int32> ^ tabS,Random ^ nbAlea)
{
		int i=0;
	for (i=0;i<4;i=i+1)
	{
		tabS[i]=nbAlea->Next(6);
	}
}
void Pion::Comparaison(array <Int32> ^ tabJ,array <Int32> ^ tabS,array <Int32> ^ tabO,array <Int32> ^ tabBN)
{
	int i=0;
	int j=0;
	for (i=0;i<4;i=i+1)
	{
		tabO[i]=tabS[i];
	}
	//-----Comparaison(NOIR)-----//
	for (i=0;i<4;i=i+1)
	{
		if (tabJ[i]==tabO[i])
		{
			tabBN[0]=tabBN[0]+1;
			tabO[i]=9;
		}
		if (tabBN[0]==4)
		{
			MessageBox::Show("Vous avez gagné en "+(tabJ[4]+1)+" essai(s).\n\tFélicitations !!!");
			SauverScore(tabJ);
		}
	}
	//-----Comparaison(BLANC)-----//
	for (i=0;i<4;i=i+1)
	{
		for (j=0;j<4;j=j+1)
		{
			if (tabJ[i]==tabO[j])
			{
				tabBN[1]=tabBN[1]+1;
				tabO[j]=9;
			}
		}
	}
	tabJ[4]=tabJ[4]+1;
}
void Pion::GenererSolution(array <Int32> ^ tabS,array <System::Drawing::Image^> ^ tabI,Int32 i,PictureBox ^picSol)
{
	picSol->Image= tabI[tabS[i]];
}
void Pion::SauverScore(array <Int32> ^ tabJ)
{
	tabHighScores[iHighScores]= tabJ[4]+1;
	iHighScores++;
	if (iHighScores==3)
		iHighScores= 0;
}