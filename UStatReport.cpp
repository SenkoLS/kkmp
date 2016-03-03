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
	int mess = MessageBox(0,L"�� ������ ����������� ����� � EXCEL?",L"���������",MB_YESNO | MB_ICONQUESTION);
	if(mess != 6) return;

	if(DBGridReport->DataSource == NULL){
		MessageBox(0,L"�� �� ������������ �����!",L"���������",MB_OK | MB_ICONWARNING);
		return;
	}else{
		if(DBGridReport->DataSource->DataSet->IsEmpty()){
        	MessageBox(0,L"����������� ������ ��� �������� � EXCEL!",L"���������",MB_OK | MB_ICONWARNING);
			return;
		}
	}

	Variant  vVarApp,vVarBooks,vVarBook, vVarSheets,vVarSheet,vVarCell;
	UnicodeString dir_cards;
	AnsiString dir;

	if(SelectDirectory("�������� ����� ��� ���������� ���������:","",dir_cards)){
		dir = dir_cards+"\\";
		dir = dir + "�����.xls";
	}

	try{
		vVarApp=CreateOleObject("Excel.Application");
		vVarApp.OlePropertySet("Visible",true);
		vVarBooks=vVarApp.OlePropertyGet("Workbooks");
		vVarApp.OlePropertySet("SheetsInNewWorkbook",2);
		vVarBooks.OleProcedure("Add");
		vVarBook=vVarBooks.OlePropertyGet("Item",1);
		vVarSheets=vVarBook.OlePropertyGet("Worksheets") ;
	}catch(Exception &e){
		MessageBox(0,e.Message.c_str(),L"������ �������� EXCEL:",MB_OK | MB_ICONERROR);
		return;
	}

	//FIRST LIST (Med quality)
	vVarSheet=vVarSheets.OlePropertyGet("Item",1);
	vVarSheet.OlePropertySet("Name","��������");
	vVarCell=vVarSheet.OlePropertyGet("Range","A1:D1");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ �������� ������� ����������� ������������");

	//2
	vVarCell=vVarSheet.OlePropertyGet("Range","A2:D2");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �������� �������� ����������� ������ ��������� (I ������� ).");

	//3
	AnsiString period = "������: � "+FormatDateTime("dd-mm-yyyy",DTPStartReportPer->DateTime)+" �� "
		+ FormatDateTime("dd-mm-yyyy",DTPEndReportPer->DateTime);

	vVarCell=vVarSheet.OlePropertyGet("Range","A3:D3");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", period.c_str());

	//4
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������:");
	vVarCell.OlePropertySet("ColumnWidth", 15);

	vVarCell=vVarSheet.OlePropertyGet("Range","B4:D4");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbOffice->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbOffice->ListSource->DataSet->FieldByName("name_office")->AsAnsiString.c_str());

	//5
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����:");

	vVarCell=vVarSheet.OlePropertyGet("Range","B5:D5");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbMed->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbMed->ListSource->DataSet->FieldByName("fio")->AsAnsiString.c_str());

	//6
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �/�");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������");
	vVarCell.OlePropertySet("ColumnWidth", 50);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ��. ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	//7
	vVarCell=vVarSheet.OlePropertyGet("Range","A7:D7");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������� ����������� ������������");
	//8
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ������������� ������������ ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count1 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", VuluntarMedAgreementYes/count1*1.0);

	//9
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",9,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",9,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� �������� �������� �� ��������� ������������ ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",9,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count2 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AgreementPDNYes/count2*1.0);

	//10
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ���������� ���������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count3 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ComplitListDeseaseYes/count3*1.0);

	//11
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "4");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ��������� � ���������� ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count4 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", CompitListProfAndStatusYes/count4*1.0);

	//12
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "5");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����������� �����");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count11 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", IntegrityCard/count11*1.0);

	//13
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "6");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������, ������������ ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count12 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AccuracyHandwriting/count12*1.0);


	vVarCell=vVarSheet.OlePropertyGet("Range","D8:D13");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(C8:C13)");

	//14
	vVarCell=vVarSheet.OlePropertyGet("Range","A14:D14");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� �������� ����������� ������");

	//15
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "7");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ��� (����������� ��� �����������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count5 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ExistenceFLGYes/count5*1.0);

	vVarCell=vVarSheet.OlePropertyGet("Range","D15:D29");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(C15:C29)");

	//16
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "8");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� �������� ���������� (����������� ��� �����������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count6 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ExistenceInspGinYes/count6*1.0);

	//17
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "9");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ���������� ����. ��������������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count13 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityProfInsOnko/count13*1.0);

	//18
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "10");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� (��������������� � ��������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count14 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DispTimelines/count14*1.0);

	//19
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "11");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ����� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count15 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityCollectAnamsis/count15*1.0);

	//20
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "12");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ����� �����");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count16 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityCollectComplaint/count16*1.0);

	//21
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "13");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������������ �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count17 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DescriptObjectStatus/count17*1.0);

	//22
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "14");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ ����������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count18 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", EvaluationResultsOfTreatment/count18*1.0);

	//23
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "15");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ���������� � �����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count19 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ObservStandartsOfDiagnostics/count19*1.0);

	//24
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "16");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ���������� � �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count20 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ObservStandartsOfTreatment/count20*1.0);

	//25
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "17");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������������� ������������� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count7 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", RationalUseOfResourcesYes/count7*1.0);

	//26
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "18");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count8 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AbsenceComplaintsOfPatientsYes/count8*1.0);

	//27
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "19");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ������ �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count21 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DeadlinesVN/count21*1.0);

	//28
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "20");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� ���������� �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count9 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", TimelyRegistLNYes/count9*1.0);

	//29
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "21");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� ����������� �� �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count10 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", RefferalToVKYes/count10*1.0);

	//30
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,4);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(D8;D15)");

	vVarCell=vVarSheet.OlePropertyGet("Range","A30:C30");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�����:");

	//BORDER:
	vVarCell = vVarSheet.OlePropertyGet("Range","A6:D30").OlePropertyGet("Borders");
	vVarCell.OlePropertySet("LineStyle", 1);
	ShowMessage("���� ������ ��������!");

	//32
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����� ������������ ����:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", StrToInt(ECountOfVisits->Text));

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "100%");

	//33
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ���� �� ����������� �������:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->RecordCount);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000%");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=C33/C32");

	//35
	vVarCell=vVarSheet.OlePropertyGet("Range","A35:D35");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������ � �����������:");

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
	//36
	vVarCell=vVarSheet.OlePropertyGet("Range","A36:D36");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
	//37
	vVarCell=vVarSheet.OlePropertyGet("Range","A37:D37");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
	//38
	vVarCell=vVarSheet.OlePropertyGet("Range","A38:D38");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
	//39
	vVarCell=vVarSheet.OlePropertyGet("Range","A39:D39");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//41
	vVarCell=vVarSheet.OlePropertyGet("Range","A41:C41");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������� I ������, ���������� ����������:");

	//42
	vVarCell=vVarSheet.OlePropertyGet("Range","A42:C42");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",42,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",4);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::FormShow(TObject *Sender)
{
	DTPStartReportPer->Date = Now();
	DTPEndReportPer->Date = Now();
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::BGenReportClick(TObject *Sender)
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

	//SET DATASOURCE FOR DBGRID:
	DBGridReport->DataSource = DMAvtoriz->DSInspection;

	//----- GET TYPE QUERY -----------------------------------------------------
	AnsiString typeQuery = "";

	if(ChBoxOffice->Checked && ChBoxExpert->Checked && ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` INNER JOIN `user` INNER JOIN `office` "
			"ON `inspection`.`id_user` = `user`.`id_user` AND `user`.`id_office` = `office`.`id_office` "
			"WHERE `office`.`id_office` = '" +DBLCbOffice->ListSource->DataSet->FieldByName("id_office")->AsAnsiString+ "' AND "
			"`inspection`.`id_expert` = '" +DBLCbExpert->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`inspection`.`id_user` = '" +DBLCbMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(ChBoxOffice->Checked && ChBoxExpert->Checked && !ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` INNER JOIN `user` INNER JOIN `office` "
			"ON `inspection`.`id_user` = `user`.`id_user` AND `user`.`id_office` = `office`.`id_office` "
			"WHERE `office`.`id_office` = '" +DBLCbOffice->ListSource->DataSet->FieldByName("id_office")->AsAnsiString+ "' AND "
			"`inspection`.`id_expert` = '" +DBLCbExpert->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(ChBoxOffice->Checked && !ChBoxExpert->Checked && ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` INNER JOIN `user` INNER JOIN `office` "
			"ON `inspection`.`id_user` = `user`.`id_user` AND `user`.`id_office` = `office`.`id_office` "
			"WHERE `office`.`id_office` = '" +DBLCbOffice->ListSource->DataSet->FieldByName("id_office")->AsAnsiString+ "' AND "
			"`inspection`.`id_user` = '" +DBLCbMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(ChBoxOffice->Checked && !ChBoxExpert->Checked && !ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` INNER JOIN `user` INNER JOIN `office` "
			"ON `inspection`.`id_user` = `user`.`id_user` AND `user`.`id_office` = `office`.`id_office` "
			"WHERE `office`.`id_office` = '" +DBLCbOffice->ListSource->DataSet->FieldByName("id_office")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(!ChBoxOffice->Checked && ChBoxExpert->Checked && ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` "
			"WHERE `inspection`.`id_expert` = '" +DBLCbExpert->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`inspection`.`id_user` = '" +DBLCbMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(!ChBoxOffice->Checked && ChBoxExpert->Checked && !ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` "
			"WHERE `inspection`.`id_expert` = '" +DBLCbExpert->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(!ChBoxOffice->Checked && !ChBoxExpert->Checked && ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` "
			"WHERE `inspection`.`id_user` = '" +DBLCbMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+ "' AND "
			"`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	if(!ChBoxOffice->Checked && !ChBoxExpert->Checked && !ChBoxMed->Checked){
		typeQuery =
			"SELECT * FROM `inspection` "
			"WHERE `date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";
	}

	//----- GET DATA THE COUNT CARD---------------------------------------------
		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text = typeQuery;
		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();
	//----------------------------------------------------------------------

	count1,count2,count3,count4,count5,count6,count7,count8,count9,
	count10,count11,count12,count13,count14,count15,count16,count17,count18,
	count19,count20,count21 = 0;

	VuluntarMedAgreementYes, AgreementPDNYes,
	ComplitListDeseaseYes, CompitListProfAndStatusYes,
	ExistenceFLGYes, ExistenceInspGinYes,
	RationalUseOfResourcesYes, AbsenceComplaintsOfPatientsYes,
	TimelyRegistLNYes,RefferalToVKYes,
	IntegrityCard, AccuracyHandwriting,
	QualityProfInsOnko, DispTimelines,
	QualityCollectAnamsis, QualityCollectComplaint,
	DescriptObjectStatus, EvaluationResultsOfTreatment,
	ObservStandartsOfDiagnostics, ObservStandartsOfTreatment,
	DeadlinesVN = 0;

	//GPA
	while(!DMAvtoriz->DSInspection->DataSet->Eof){
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("VuluntarMedAgreementYes")->AsInteger != 0){
			VuluntarMedAgreementYes += DMAvtoriz->DSInspection->DataSet->FieldByName("VuluntarMedAgreementYes")->AsInteger;
			count1++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("AgreementPDNYes")->AsInteger != 0){
			AgreementPDNYes += DMAvtoriz->DSInspection->DataSet->FieldByName("AgreementPDNYes")->AsInteger;
			count2++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ComplitListDeseaseYes")->AsInteger != 0){
			ComplitListDeseaseYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ComplitListDeseaseYes")->AsInteger;
			count3++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("CompitListProfAndStatusYes")->AsInteger != 0){
			CompitListProfAndStatusYes += DMAvtoriz->DSInspection->DataSet->FieldByName("CompitListProfAndStatusYes")->AsInteger;
			count4++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("CompitListProfAndStatusYes")->AsInteger != 0){
			ExistenceFLGYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ExistenceFLGYes")->AsInteger;
			count5++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ExistenceInspGinYes")->AsInteger != 0){
			ExistenceInspGinYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ExistenceInspGinYes")->AsInteger;
			count6++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RationalUseOfResourcesYes")->AsInteger != 0){
			RationalUseOfResourcesYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RationalUseOfResourcesYes")->AsInteger;
			count7++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("AbsenceComplaintsOfPatientsYes")->AsInteger != 0){
			AbsenceComplaintsOfPatientsYes += DMAvtoriz->DSInspection->DataSet->FieldByName("AbsenceComplaintsOfPatientsYes")->AsInteger;
			count8++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("TimelyRegistLNYes")->AsInteger != 0){
			TimelyRegistLNYes += DMAvtoriz->DSInspection->DataSet->FieldByName("TimelyRegistLNYes")->AsInteger;
			count9++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RefferalToVKYes")->AsInteger != 0){
			RefferalToVKYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RefferalToVKYes")->AsInteger;
			count10++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("IntegrityCard")->AsInteger != 0){
			IntegrityCard += DMAvtoriz->DSInspection->DataSet->FieldByName("IntegrityCard")->AsInteger;
			count11++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("AccuracyHandwriting")->AsInteger != 0){
			AccuracyHandwriting += DMAvtoriz->DSInspection->DataSet->FieldByName("AccuracyHandwriting")->AsInteger;
			count12++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("QualityProfInsOnko")->AsInteger != 0){
			QualityProfInsOnko += DMAvtoriz->DSInspection->DataSet->FieldByName("QualityProfInsOnko")->AsInteger;
			count13++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("DispTimelines")->AsInteger != 0){
			DispTimelines += DMAvtoriz->DSInspection->DataSet->FieldByName("DispTimelines")->AsInteger;
			count14++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectAnamsis")->AsInteger != 0){
			QualityCollectAnamsis += DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectAnamsis")->AsInteger;
			count15++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectComplaint")->AsInteger != 0){
			QualityCollectComplaint += DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectComplaint")->AsInteger;
			count16++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("DescriptObjectStatus")->AsInteger != 0){
			DescriptObjectStatus += DMAvtoriz->DSInspection->DataSet->FieldByName("DescriptObjectStatus")->AsInteger;
			count17++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("EvaluationResultsOfTreatment")->AsInteger != 0){
			EvaluationResultsOfTreatment += DMAvtoriz->DSInspection->DataSet->FieldByName("EvaluationResultsOfTreatment")->AsInteger;
			count18++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfDiagnostics")->AsInteger != 0){
			ObservStandartsOfDiagnostics += DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfDiagnostics")->AsInteger;
			count19++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfTreatment")->AsInteger != 0){
			ObservStandartsOfTreatment += DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfTreatment")->AsInteger;
			count20++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("DeadlinesVN")->AsInteger != 0){
			DeadlinesVN += DMAvtoriz->DSInspection->DataSet->FieldByName("DeadlinesVN")->AsInteger;
			count21++;
		}

		DMAvtoriz->DSInspection->DataSet->Next();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStatReport::FormClose(TObject *Sender, TCloseAction &Action)
{
	FMain->BShowAllClick(Sender);
}
//---------------------------------------------------------------------------

