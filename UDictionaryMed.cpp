//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDictionaryMed.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "GridsEh"
#pragma link "ToolCtrlsEh"
#pragma resource "*.dfm"
TFDictionaryMed *FDictionaryMed;
//---------------------------------------------------------------------------
__fastcall TFDictionaryMed::TFDictionaryMed(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::ESurnameExit(TObject *Sender)
{
	ESurname->Text = ESurname->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::ENameExit(TObject *Sender)
{
	EName->Text = EName->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::EOtchExit(TObject *Sender)
{
	EOtch->Text = EOtch->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::FormShow(TObject *Sender)
{
	DMAvtoriz->SQLQCatalogMed->Open();
	DMAvtoriz->CDSCatalogMed->Open();
}
//---------------------------------------------------------------------------