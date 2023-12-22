//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

class TForm1:public TForm{
__published:	// IDE-managed Components
	TLabel *currentPlayerSymbolLabel;
	TLabel *winnerLabel;
	TButton *Button01;
	TButton *Button02;
	TButton *Button03;
	TButton *Button04;
	TButton *Button05;
	TButton *Button06;
	TButton *Button07;
	TButton *Button08;
	TButton *Button09;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;

	void __fastcall Button03Click(TObject *Sender);
	void __fastcall Button02Click(TObject *Sender);
	void __fastcall Button01Click(TObject *Sender);
	void __fastcall Button04Click(TObject *Sender);
	void __fastcall Button05Click(TObject *Sender);
	void __fastcall Button06Click(TObject *Sender);
	void __fastcall Button07Click(TObject *Sender);
	void __fastcall Button08Click(TObject *Sender);
	void __fastcall Button09Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
private:	// User declarations
public:
	bool TForm1::isWinner(int& m);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
