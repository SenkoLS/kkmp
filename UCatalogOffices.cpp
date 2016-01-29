//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCatalogOffices.h"
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
TFCatalogOffices *FCatalogOffices;
//---------------------------------------------------------------------------
__fastcall TFCatalogOffices::TFCatalogOffices(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::FormShow(TObject *Sender)
{
	ENameOffice->Text = "";

	NAddOffice->Enabled = true;
	BEditNameOffice->Enabled = true;
	BDeleteOffice->Enabled = true;

	ENameOffice->Color = clBtnFace;
	ENameOffice->Enabled = false;

	DBLookupComboBoxChief->Color = clBtnFace;
	DBLookupComboBoxChief->Enabled = false;

	DMAvtoriz->SQLQCatalogOffices->Open();
	DMAvtoriz->CDSCatalogOffices->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::FormClose(TObject *Sender, TCloseAction &Action)

{
	DMAvtoriz->SQLQCatalogOffices->Close();
	DMAvtoriz->CDSCatalogOffices->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::BAddMedClick(TObject *Sender)
{
	FDictionaryMed->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::NAddOfficeClick(TObject *Sender)
{
	chooseSafe = 1;    //whrite office
	NAddOffice->Enabled = false;
	BEditNameOffice->Enabled = false;
	BDeleteOffice->Enabled = false;

	ENameOffice->Color = clWhite;
	ENameOffice->Enabled = true;

	DBLookupComboBoxChief->Color = clWhite;
	DBLookupComboBoxChief->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFCatalogOffices::BSafeRecordClick(TObject *Sender)
{
    NAddOffice->Enabled = true;
	BEditNameOffice->Enabled = true;
	BDeleteOffice->Enabled = true;
	NAddOffice->Enabled = true;

	ENameOffice->Color = clBtnFace;
	ENameOffice->Enabled = false;

	DBLookupComboBoxChief->Color = clBtnFace;
	DBLookupComboBoxChief->Enabled = false;

	DMAvtoriz->SQLQCatalogOffices->Close();

	switch(chooseSafe){
		case 1: DMAvtoriz->SQLQCatalogOffices->SQL->Text = "INSERT INTO `office` (`name_office`) VALUES('"+ ENameOffice->Text +"')";
			break;
		case 2: DMAvtoriz->SQLQCatalogOffices->SQL->Text =  "UPDATE `office` SET `name_office` ="
			"'"+ ENameOffice->Text +"' "
			"WHERE `id_office` = '"+DBGrCatalogOffices->DataSource->DataSet->FieldByName("id_office")->AsAnsiString+"'";
			break;
	}


	DMAvtoriz->SQLConnectKKMP->StartTransaction(trans);
	if(DMAvtoriz->SQLQCatalogOffices->ExecSQL()){
		DMAvtoriz->SQLConnectKKMP->Commit(trans);
	}else{
		DMAvtoriz->SQLConnectKKMP->Rollback(trans);
		switch(chooseSafe){
			case 1: MessageBox(0,L"������ ������ � ��!\n���������� � ������������.",L"������",MB_OK);
				break;
			case 2: MessageBox(0,L"������ �������������� � ��!\n���������� � ������������.",L"������",MB_OK);
				break;
		}
	}

	DMAvtoriz->SQLQCatalogOffices->Close();
	DMAvtoriz->SQLQCatalogOffices->SQL->Text = "SELECT * FROM `office` WHERE `id_office` !=1";
	DMAvtoriz->SQLQCatalogOffices->Open();
	DMAvtoriz->CDSCatalogOffices->Close();
	DMAvtoriz->CDSCatalogOffices->Open();

	ENameOffice->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::BEditNameOfficeClick(TObject *Sender)
{
    chooseSafe = 2; //edit office
	BEditNameOffice->Enabled = false;
	NAddOffice->Enabled = false;
	BDeleteOffice->Enabled = false;

	ENameOffice->Color = clWhite;
	ENameOffice->Enabled = true;

	DBLookupComboBoxChief->Color = clWhite;
	DBLookupComboBoxChief->Enabled = true;

    DMAvtoriz->SQLQCatalogOffices->Close();
	DMAvtoriz->SQLQCatalogOffices->SQL->Text = "SELECT * FROM `office` WHERE `id_office` = "
			"'"+DBGrCatalogOffices->DataSource->DataSet->FieldByName("id_office")->AsAnsiString+"'";
	DMAvtoriz->SQLQCatalogOffices->Open();
	DMAvtoriz->CDSCatalogOffices->Close();
	DMAvtoriz->CDSCatalogOffices->Open();
	//get name office
	ENameOffice->Text = DMAvtoriz->DSCatalogOffices->DataSet->FieldByName("name_office")->AsAnsiString;
    //show offices
	DMAvtoriz->SQLQCatalogOffices->Close();
	DMAvtoriz->SQLQCatalogOffices->SQL->Text = "SELECT * FROM `office` WHERE `id_office` !=1";
	DMAvtoriz->SQLQCatalogOffices->Open();
	DMAvtoriz->CDSCatalogOffices->Close();
	DMAvtoriz->CDSCatalogOffices->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::BDeleteOfficeClick(TObject *Sender)
{
	if(DBGrCatalogOffices->DataSource->DataSet->FieldByName("id_office")->AsInteger <2){
		MessageBox(0,L"�� ������� ���������!",L"���������",MB_OK);
		return;
	}

	int mess = MessageBox(0,L"�� ������ ������� ��������� ���������?",L"��������������",MB_YESNO);
	if(mess == 6){
		DMAvtoriz->SQLQCatalogOffices->Close();
		DMAvtoriz->SQLQCatalogOffices->SQL->Text = "DELETE FROM `office` WHERE `id_office` = '"+DBGrCatalogOffices->DataSource->DataSet->FieldByName("id_office")->AsAnsiString+"'";

		DMAvtoriz->SQLConnectKKMP->StartTransaction(trans);
		if(DMAvtoriz->SQLQCatalogOffices->ExecSQL()){
			DMAvtoriz->SQLConnectKKMP->Commit(trans);
		}else{
			DMAvtoriz->SQLConnectKKMP->Rollback(trans);
			MessageBox(0,L"������ �������� �� ��!\n���������� � ������������.",L"������",MB_OK);
		}

		DMAvtoriz->SQLQCatalogOffices->Close();
		DMAvtoriz->SQLQCatalogOffices->SQL->Text = "SELECT * FROM `office` WHERE `id_office` !=1";
		DMAvtoriz->SQLQCatalogOffices->Open();
		DMAvtoriz->CDSCatalogOffices->Close();
		DMAvtoriz->CDSCatalogOffices->Open();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCatalogOffices::BCancelClick(TObject *Sender)
{
	ENameOffice->Text = "";

	NAddOffice->Enabled = true;
	BEditNameOffice->Enabled = true;
	BDeleteOffice->Enabled = true;

	ENameOffice->Color = clBtnFace;
	ENameOffice->Enabled = false;

	DBLookupComboBoxChief->Color = clBtnFace;
	DBLookupComboBoxChief->Enabled = false;

	DMAvtoriz->SQLQCatalogOffices->Open();
	DMAvtoriz->CDSCatalogOffices->Open();
}
//---------------------------------------------------------------------------

