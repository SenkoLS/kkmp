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
AnsiString __fastcall TFDictionaryMed::getStrValue(AnsiString val){
	if(val.IsEmpty())
		return NULL;
	else
		return "'" + val + "'";
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::setView(){
	BAdd->Enabled = false;
	BEdit->Enabled = false;
	BDelete->Enabled = false;

	EOtch->Color = clWhite;
	EName->Color = clWhite;
	ESurname->Color = clWhite;
	ELogin->Color = clWhite;
	EPassword->Color = clWhite;
	DBLookupComboBoxOffice->Color = clWhite;

	EOtch->Enabled = true;
	EName->Enabled = true;
	ESurname->Enabled = true;
	ELogin->Enabled = true;
	EPassword->Enabled = true;
	DBLookupComboBoxOffice->Enabled = true;
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

	DMAvtoriz->SQLQgetListOffice->Open();
	DMAvtoriz->CDSgetListOffice->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFDictionaryMed::FormClose(TObject *Sender, TCloseAction &Action)
{
	DMAvtoriz->SQLQCatalogMed->Close();
	DMAvtoriz->CDSCatalogMed->Close();
	DMAvtoriz->SQLQgetListOffice->Close();
	DMAvtoriz->CDSgetListOffice->Close();
	BCancelClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFDictionaryMed::BAddClick(TObject *Sender)
{
	chooseSafe = 1;
	setView();
}
//---------------------------------------------------------------------------

void __fastcall TFDictionaryMed::BEditClick(TObject *Sender)
{
    chooseSafe = 2;
	setView();
}
//---------------------------------------------------------------------------

void __fastcall TFDictionaryMed::BCancelClick(TObject *Sender)
{
	BAdd->Enabled = true;
	BEdit->Enabled = true;
	BDelete->Enabled = true;

	EOtch->Color = clBtnFace;
	EName->Color = clBtnFace;
	ESurname->Color = clBtnFace;
	ELogin->Color = clBtnFace;
	EPassword->Color = clBtnFace;
	DBLookupComboBoxOffice->Color = clBtnFace;

	EOtch->Text = "";
	EName->Text = "";
	ESurname->Text = "";
	ELogin->Text = "";
	EPassword->Text = "";

	EOtch->Enabled = false;
	EName->Enabled = false;
	ESurname->Enabled = false;
	ELogin->Enabled = false;
	EPassword->Enabled = false;
	DBLookupComboBoxOffice->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFDictionaryMed::BSafeMedClick(TObject *Sender)
{
	DMAvtoriz->SQLQCatalogMed->Close();
	DMAvtoriz->SQLQCatalogMed->SQL->Text = 	"INSERT INTO `user` (`name`,`surname`,`patronymic`,`login`,`password`,`id_office`) "
											"VALUES('"+ EName->Text +"','"+ EOtch->Text +"','"+ ESurname->Text +"','"+ ELogin->Text +"',"+ getStrValue(FAvtoriz->MD5(EPassword->Text)) +","+ getStrValue(EPassword->Text) +")";
	DMAvtoriz->SQLConnectKKMP->StartTransaction(trans);
	try{
		if(DMAvtoriz->SQLQCatalogMed->ExecSQL()){
			DMAvtoriz->SQLConnectKKMP->Commit(trans);
		}else{
			DMAvtoriz->SQLConnectKKMP->Rollback(trans);
			MessageBox(0,L"������ ������ \"false\"!\n���������� � ������������.",L"������",MB_OK);
		}
	}catch(Exception &e){
		DMAvtoriz->SQLConnectKKMP->Rollback(trans);
		switch(chooseSafe){
			case 1: MessageBox(0,e.Message.c_str(),L"������ ������",MB_OK);
				break;
			case 2: MessageBox(0,e.Message.c_str(),L"������ ��������������",MB_OK);
				break;
		}
	}

	BCancelClick(Sender);

	DMAvtoriz->SQLQCatalogMed->Close();
	DMAvtoriz->SQLQCatalogMed->SQL->Text =  "SELECT `surname`,`name`,`patronymic`,"
											"`login`,`name_office` "
											"FROM `user` INNER JOIN `office` "
											"ON `user`.`id_office` = `office`.`id_office`";
	DMAvtoriz->SQLQCatalogMed->Open();
	DMAvtoriz->CDSCatalogMed->Close();
    DMAvtoriz->CDSCatalogMed->Open();
}
//---------------------------------------------------------------------------

