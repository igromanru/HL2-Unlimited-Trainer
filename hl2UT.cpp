//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <stdlib.h>
#include <Tlhelp32.h>
#pragma hdrstop

#include "hl2UT.h"
#include "credits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define PLAYERBASE_OFFSET       0x29D

TUnlimitedForm *UnlimitedForm;

int way=1;
int wayloop=1;
HWND act = NULL;
DWORD prozessor;
int getwi = 1;
HANDLE handleact;
DWORD puffer = 0;
BYTE ammo[2] = {0x90, 0x90};
BYTE ammoback[2] = {0x8B, 0x03};
BYTE ammosec[2] = {0x8B, 0x11};
BYTE aux[2] = {0xD9, 0x1F};
BYTE health[2] = {0xEB, 0x019};
BYTE healthback[2] = {0x74, 0x019};
BYTE nore[2] = {0xEB, 0x34};
BYTE noreback[2] = {0x74, 0x34};
BYTE onehitback[2] = {0x8B, 0xC7};
DWORD Baser;
DWORD AddressAmmo;
DWORD AddressNoRe;
DWORD AddressSec;
DWORD AddressAir;
DWORD AddressAux;
DWORD AddressHP;
DWORD AddressShild;
DWORD Address1hit;




//---------------------------------------------------------------------------
__fastcall TUnlimitedForm::TUnlimitedForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUnlimitedForm::Timer1Timer(TObject *Sender)
{
 if(wayloop==1)
 {
 if(way==1)
 {
  Label1->Left=(Label1->Left)+1;
   if(Label1->Left>=350)
   {
	 way=0;
   }
  }
   else
   {
	Label1->Left=(Label1->Left)-1;
	if(Label1->Left<=1)
	{
		way=1;
    }
   }
  }
}
//---------------------------------------------------------------------------
bool SetDebugPrivileges()
{
        HANDLE hToken;

        TOKEN_PRIVILEGES tokenPriv;

		tokenPriv.PrivilegeCount = 1;

		if(!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
                return false;

        if(!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tokenPriv.Privileges[0].Luid))

                return false;

        tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;



        if(!AdjustTokenPrivileges(hToken, false, &tokenPriv, sizeof(TOKEN_PRIVILEGES), NULL, NULL))

                return false;

		return true;
}
//---------------------------------------------------------------------------
	  DWORD GetModuleBase(LPSTR lpModuleName, DWORD dwProcessId)
		 {
	  MODULEENTRY32 lpModuleEntry = {0};

      HANDLE hSnapShot = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwProcessId );

      if(!hSnapShot)

      return NULL;

      lpModuleEntry.dwSize = sizeof(lpModuleEntry);

      BOOL bModule = Module32First( hSnapShot, &lpModuleEntry );

	  while(bModule)
	  {
	  if(!strcmp( lpModuleEntry.szModule, lpModuleName ) )
	  {
      CloseHandle( hSnapShot );

	  return (DWORD)lpModuleEntry.modBaseAddr;
	  }
	  bModule = Module32Next( hSnapShot, &lpModuleEntry );
	  }
	  CloseHandle( hSnapShot );

      return NULL;
	  }
//---------------------------------------------------------------------------
void __fastcall TUnlimitedForm::founder01Timer(TObject *Sender)
{
  act = FindWindow(NULL, "HALF-LIFE 2");
  if(act!=NULL)
   {
   GetWindowThreadProcessId(act, &prozessor);
   Baser = GetModuleBase("server.dll", prozessor);
	if(Baser!=NULL)
	{
   if(getwi==1)
   {
	 handleact = OpenProcess(PROCESS_ALL_ACCESS, FALSE, prozessor);
	 SetDebugPrivileges();

	 AddressAmmo = Baser + 0x3110D;
	 AddressNoRe = Baser + 0xCF44D;
	 AddressSec  = Baser + 0xC1AFC;
	 AddressAir  = Baser + 0x3A173D;
	 AddressAux  = Baser + 0x12DDDB;
	 AddressHP  = Baser + 0x289BC;
	 AddressShild  = Baser + 0x1B95FC;
	 Address1hit = Baser + 0x289D7;

	 getwi = 0;

	 wayloop = 0;
	 Label1->Caption="Game found";
	 Label1->Font->Color=clLime;
	 Label1->Left=160;
	 CheckBox1->Enabled=true;
	 CheckBox2->Enabled=true;
	 CheckBox3->Enabled=true;
	 CheckBox4->Enabled=true;
	 CheckBox5->Enabled=true;
	 CheckBox6->Enabled=true;
   }
    }
   }
   else
   {
	 Label1->Caption="Waiting";
	 Label1->Font->Color=clWindow;
	 getwi = 1;
	 wayloop = 1;
	 CheckBox1->Enabled=false;
	 CheckBox2->Enabled=false;
	 CheckBox3->Enabled=false;
	 CheckBox4->Enabled=false;
	 CheckBox5->Enabled=false;
	 CheckBox6->Enabled=false;
	 CheckBox1->Checked=false;
	 CheckBox2->Checked=false;
	 CheckBox3->Checked=false;
	 CheckBox4->Checked=false;
	 CheckBox5->Checked=false;
	 CheckBox6->Checked=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TUnlimitedForm::CheckBox1Click(TObject *Sender)
{

  if(CheckBox1->Checked==true)
   {

	 WriteProcessMemory(handleact,(void*)(AddressAmmo),&ammo,sizeof(ammo),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressNoRe),&nore,sizeof(nore),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressAmmo),&ammoback,sizeof(ammoback),&puffer);
	   WriteProcessMemory(handleact,(void*)(AddressNoRe),&noreback,sizeof(noreback),&puffer);
   }

}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::CheckBox2Click(TObject *Sender)
{
  if(CheckBox2->Checked==true)
   {
	  WriteProcessMemory(handleact,(void*)(AddressSec),&ammo,sizeof(ammo),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressSec),&ammosec,sizeof(ammosec),&puffer);
   }
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::CheckBox3Click(TObject *Sender)
{
  if(CheckBox3->Checked==true)
   {
	  WriteProcessMemory(handleact,(void*)(AddressAir),&ammo,sizeof(ammo),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressAir),&ammoback,sizeof(ammoback),&puffer);
   }
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::CheckBox4Click(TObject *Sender)
{
   if(CheckBox4->Checked==true)
   {
	  WriteProcessMemory(handleact,(void*)(AddressAux),&ammo,sizeof(ammo),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressAux),&aux,sizeof(aux),&puffer);
   }
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::CheckBox5Click(TObject *Sender)
{
 if(CheckBox5->Checked==true)
   {
	  WriteProcessMemory(handleact,(void*)(AddressHP),&health,sizeof(health),&puffer);
	  WriteProcessMemory(handleact,(void*)(Address1hit),&ammo,sizeof(health),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressHP),&healthback,sizeof(healthback),&puffer);
	   WriteProcessMemory(handleact,(void*)(Address1hit),&onehitback,sizeof(onehitback),&puffer);
   }
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::CheckBox6Click(TObject *Sender)
{
   if(CheckBox6->Checked==true)
   {
	  WriteProcessMemory(handleact,(void*)(AddressShild),&health,sizeof(health),&puffer);
   }
   else
   {
	   WriteProcessMemory(handleact,(void*)(AddressShild),&healthback,sizeof(healthback),&puffer);
   }
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::FormClose(TObject *Sender, TCloseAction &Action)
{
 CloseHandle(handleact);
}
//---------------------------------------------------------------------------

void __fastcall TUnlimitedForm::Label4Click(TObject *Sender)
{
 Form1 = new TForm1(Application);
 Form1->ShowModal();
 delete Form1;
}
//---------------------------------------------------------------------------

