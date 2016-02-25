//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UStatReport.h"
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
TFStatReport *FStatReport;
//---------------------------------------------------------------------------
__fastcall TFStatReport::TFStatReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFStatReport::ChBoxOfficeClick(TObject *Sender)
{
	if(ChBoxGeneral->Checked == true){
		ChBoxGeneral->Checked = false;
	}else{
		if( ChBoxOffice->Checked == false &&
			ChBoxExpert->Checked == false &&
			ChBoxMed->Checked == false){

			ChBoxGeneral->Checked = true;
		}
	}

	if(ChBoxOffice->Checked){
		DBLCbOffice->Enabled = true;
		DMAvtoriz->SQLQgetListOffice->Close();
		DMAvtoriz->SQLQgetListOffice->Open();
		DMAvtoriz->CDSgetListOffice->Close();
		DMAvtoriz->CDSgetListOffice->Open();
	}else{
		DBLCbOffice->Enabled = false;
		DMAvtoriz->SQLQgetListOffice->Close();
		DMAvtoriz->CDSgetListOffice->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::ChBoxExpertClick(TObject *Sender)
{
	if(ChBoxGeneral->Checked == true){
		ChBoxGeneral->Checked = false;
	}else{
		if( ChBoxOffice->Checked == false &&
			ChBoxExpert->Checked == false &&
			ChBoxMed->Checked == false){

			ChBoxGeneral->Checked = true;
		}
	}

	if(ChBoxExpert->Checked){
		DBLCbExpert->Enabled = true;
		DMAvtoriz->SQLQGetListMed->Close();
		DMAvtoriz->SQLQGetListMed->Open();
		DMAvtoriz->CDSGetListMed->Close();
		DMAvtoriz->CDSGetListMed->Open();
	}else{
		DBLCbExpert->Enabled = false;
		DMAvtoriz->SQLQGetListMed->Close();
		DMAvtoriz->CDSGetListMed->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::ChBoxMedClick(TObject *Sender)
{
	if(ChBoxGeneral->Checked == true){
		ChBoxGeneral->Checked = false;
	}else{
		if( ChBoxOffice->Checked == false &&
			ChBoxExpert->Checked == false &&
			ChBoxMed->Checked == false){

			ChBoxGeneral->Checked = true;
		}
	}

	if(ChBoxMed->Checked){
		DBLCbMed->Enabled = true;
		DMAvtoriz->SQLQGetListMedStat->Close();
		DMAvtoriz->SQLQGetListMedStat->Open();
		DMAvtoriz->CDSGetListMedStat->Close();
		DMAvtoriz->CDSGetListMedStat->Open();
	}else{
		DBLCbMed->Enabled = false;
		DMAvtoriz->SQLQGetListMedStat->Close();
		DMAvtoriz->CDSGetListMedStat->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::BGenerateReportClick(TObject *Sender)
{
	if(ECountOfVisits->Text.IsEmpty()){
		MessageBox(0,L"�� ������� ���������� ���������\n�� �������� ������!",L"������",MB_OK | MB_ICONHAND);
		ECountOfVisits->SetFocus();
		return;
	}

	try{
     	StrToInt(ECountOfVisits->Text);
	}catch(...){
		MessageBox(0,L"���������� ��������� �� �������� ������\n�� �������� ����� ������!\n��������� ��������.",L"������",MB_OK | MB_ICONHAND);
		ECountOfVisits->SetFocus();
		return;
	}


}
//---------------------------------------------------------------------------

