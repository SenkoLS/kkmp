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
	if(DMAvtoriz->DSAvtoriz->DataSet->FieldByName("login")->AsAnsiString != "admin"){
		DMAvtoriz->SQLQCatalogMed->Close();
		DMAvtoriz->SQLQCatalogMed->SQL->Text = "SELECT `surname`,`name`,`patronymic`,`login`,`name_office` "
			"FROM `user` INNER JOIN `office` ON `user`.`id_office` = `office`.`id_office` "
			"WHERE `user`.`id_user` != 1";
	}
	DMAvtoriz->SQLQCatalogMed->Open();
	DMAvtoriz->CDSCatalogMed->Close();
	DMAvtoriz->CDSCatalogMed->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::FormClose(TObject *Sender, TCloseAction &Action)
{
	DMAvtoriz->SQLQCatalogMed->Close();
	DMAvtoriz->CDSCatalogMed->Close();
}
//---------------------------------------------------------------------------

