//---------------------------------------------------------------------------

#ifndef creditsH
#define creditsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-verwaltete Komponenten
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label5;
	void __fastcall Label2Click(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall Label4Click(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
