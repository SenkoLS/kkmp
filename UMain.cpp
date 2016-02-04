//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMain.h"
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
TFMain *FMain;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormShow(TObject *Sender)
{
	FAvtoriz->ShowModal();
	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::N3Click(TObject *Sender)
{
	FAbout->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::N4Click(TObject *Sender)
{
	FDictionaryMed->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::NewCardClick(TObject *Sender)
{
	FCard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DBGridEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	switch(Key){
    	case 113: FCard->ShowModal(); break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::N6Click(TObject *Sender)
{
	FCatalogOffices->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->SQLConnectKKMP->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DBGridEh1DblClick(TObject *Sender)
{
	//Set card number for editing in FCard
	FCard->id_inspection = DBGridEh1->DataSource->DataSet->FieldByName("id_inspection")->AsInteger;
	FCard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BDeleteCardClick(TObject *Sender)
{
	if(DMAvtoriz->DSAvtoriz->DataSet->FieldByName("login")->AsAnsiString != "admin"){
		MessageBox(0,L"� ��� ��� ���� �� ������ ��������!\n����������� ������� ������ ��������������.",L"���������",MB_OK);
	}else{
		int mess = MessageBox(0,L"�� ������ ������� ��������� ������?",L"��������������",MB_YESNO);
		if(mess != 6) return;

		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text =
			"DELETE FROM `inspection` WHERE `id_inspection` = '"
			+ DBGridEh1->DataSource->DataSet->FieldByName("id_inspection")->AsAnsiString +"'";
		try{
			DMAvtoriz->SQLConnectKKMP->StartTransaction(trans);
			if(DMAvtoriz->SQLQInspection->ExecSQL()){
				DMAvtoriz->SQLConnectKKMP->Commit(trans);
			}else{
				DMAvtoriz->SQLConnectKKMP->Rollback(trans);
				MessageBox(0,L"������ ������ \"false\"!\n���������� � ������������.",L"������ ��������",MB_OK);
			}
		}catch(Exception &e){
			DMAvtoriz->SQLConnectKKMP->Rollback(trans);
			MessageBox(0,e.Message.c_str(),L"������ ��������",MB_OK);
		}

		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text =
			"SELECT `id_inspection`,`date_start`,`date_end`, "
			"CONCAT(surname,' ',name,' ',patronymic) as `fio`, "
			"`year_date_birthday`,`id_user`,`kkmp`,`kvo` "
			"FROM `inspection` ORDER BY `id_inspection` DESC";
		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BShowCardClick(TObject *Sender)
{
	DBGridEh1DblClick(Sender);
}
//---------------------------------------------------------------------------

