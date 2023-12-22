//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
char currentPlayerSymbol='x';
char **board;
int player1_wins=0, player2_wins=0, n_moves=0,n_rows=5,n_cols=5;
//void TForm1::UpdateBoard(){
//
//}

bool TForm1:: isWinner(int& m){
	if (n_moves == 24) {
        for (int i = 0; i <= 4; ++i) {
			for (int j = 0; j <= 2; ++j) {// row win
				if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]) {
					if (board[i][j] == 'X') {
						player1_wins++;
					} else {
                        player2_wins++;
                    }
				}
            }
        }

        for (int i = 0; i <= 2; ++i) {// column win
            for (int j = 0; j <= 4; ++j) {
				if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
                    }
                }
            }
        }

        for (int i = 0; i <= 2; ++i) {// diag
            for (int j = 0; j <= 2; ++j) {
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
					}
                }
            }
        }

        for (int i = 0; i <= 2; ++i) {// diag2
            for (int j = 2; j <= 4; ++j) {
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2]) {
					if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
					}
                }
            }
        }
	}

    if (n_moves == 24) {
        if (player1_wins > player2_wins) {
			m = 1;
            return true;
		} else if (player2_wins > player1_wins) {
			m = 0;
			return true;
        } else {
            m = -1; // Indicates a tie
            return true;
		}
    }
    return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	currentPlayerSymbolLabel->Text=currentPlayerSymbol;
	board = new char*[n_rows];
	for (int i = 0; i < n_rows; i++) {
		board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
			board[i][j] = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button01Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[0][0] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button02Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[0][1] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
void __fastcall TForm1::Button03Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[0][2] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button04Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[0][3] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button05Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[0][4] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button06Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[1][0] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button07Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[1][1] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button08Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[1][2] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button09Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[1][3] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[1][4] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[2][0] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[2][1] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[2][2] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[2][3] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[2][4] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[3][0] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[3][1] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[3][2] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[3][3] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[3][4] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[4][0] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[4][1] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[4][2] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[4][3] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
	TButton* Button = dynamic_cast<TButton*>(Sender);
	Button->Text = currentPlayerSymbol;
	board[4][4] = currentPlayerSymbol;
	int m;

	if (isWinner(m)) {
		if (m == 1) {
			winnerLabel->Text="Player X WON!";
		} else if (m == 0) {
			winnerLabel->Text="Player O wins!";
		} else {
			winnerLabel->Text="It's a tie!";
		}
		return;
	} else {
		if (currentPlayerSymbol == 'x') {
			currentPlayerSymbol = '0';
		} else {
			currentPlayerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = currentPlayerSymbol;
	}
}
}
//---------------------------------------------------------------------------
