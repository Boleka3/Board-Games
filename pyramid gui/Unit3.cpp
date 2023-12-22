//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;

char currentPlayerSymbol = 'X';

bool TForm3:: checkisWinner(){

  if (!Button1->Text.IsEmpty() && Button1->Text == Button4->Text && Button1->Text == Button9->Text) {
	   return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button5->Text) {
	   return true;
  }
  if (!Button1->Text.IsEmpty() && Button1->Text == Button3->Text && Button1->Text == Button7->Text) {
	   return true;
  }
  if (!Button2->Text.IsEmpty() && Button2->Text == Button3->Text && Button2->Text == Button4->Text) {
	   return true;
  }
 if (!Button5->Text.IsEmpty() && Button5->Text == Button6->Text && Button5->Text == Button7->Text) {
	   return true;
  }
  if (!Button6->Text.IsEmpty() && Button6->Text == Button7->Text && Button6->Text == Button8->Text) {
	   return true;
  }
  if (!Button7->Text.IsEmpty() && Button7->Text == Button8->Text && Button7->Text == Button9->Text) {
	   return true;
  }
  return false;
}
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	   currentPlayerSymbolLabel->Text= currentPlayerSymbol ;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::ButtonClick(TObject *Sender)
{
		TButton* clickedButton= dynamic_cast<TButton*>(Sender);
		clickedButton->Text=currentPlayerSymbol;

		if (checkisWinner()){
			winnerLabel->Text = "YOU HAVE WON !!!!!!!(YA 7LW YA GAMEEL)";
			return;
		}

		if (currentPlayerSymbol=='X') {
			currentPlayerSymbol='O';
			}
		else {
			currentPlayerSymbol='X';
			}
		currentPlayerSymbolLabel->Text= currentPlayerSymbol ;


}
//---------------------------------------------------------------------------


