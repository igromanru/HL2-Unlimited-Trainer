//---------------------------------------------------------------------------

#ifndef hl2UTH
#define hl2UTH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TUnlimitedForm : public TForm
{
__published:	// IDE-verwaltete Komponenten
	TImage *Image1;
	TLabel *Label1;
	TTimer *Timer1;
	TTimer *founder01;
	TLabel *Label2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall founder01Timer(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall CheckBox6Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Label4Click(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TUnlimitedForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUnlimitedForm *UnlimitedForm;
//---------------------------------------------------------------------------
#endif
