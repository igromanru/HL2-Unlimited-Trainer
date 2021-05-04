//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "credits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label2Click(TObject *Sender)
{
 ShellExecute(NULL, "open", "http://homeofgamehacking.de/showthread.php?tid=62",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label5Click(TObject *Sender)
{
 ShellExecute(NULL, "open", "http://homeofgamehacking.de/",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label4Click(TObject *Sender)
{
 ShellExecute(NULL, "open", "http://homeofgamehacking.de/showthread.php?tid=62",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

