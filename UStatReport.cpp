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
		vVarApp.OlePropertySet("SheetsInNewWorkbook",4);
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
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ �������� ������� ����������� ������������ � �������� �������� ����������� ������ ��������� (I ������� ).");
	vVarCell.OlePropertySet("ColumnWidth", 85);
	vVarCell.OlePropertySet("RowHeight",40);

	//2
	AnsiString period = "������: � "+FormatDateTime("dd-mm-yyyy",DTPStartReportPer->DateTime)+" �� "
		+ FormatDateTime("dd-mm-yyyy",DTPEndReportPer->DateTime);

	vVarCell=vVarSheet.OlePropertyGet("Range","A2:D2");
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
	vVarCell.OlePropertySet("Value", "�������:");

	vVarCell=vVarSheet.OlePropertyGet("Range","B4:D4");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbExpert->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbExpert->ListSource->DataSet->FieldByName("fio")->AsAnsiString.c_str());

	//5
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������:");
	vVarCell.OlePropertySet("ColumnWidth", 15);

	vVarCell=vVarSheet.OlePropertyGet("Range","B5:D5");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbOffice->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbOffice->ListSource->DataSet->FieldByName("name_office")->AsAnsiString.c_str());

	//6
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����:");

	vVarCell=vVarSheet.OlePropertyGet("Range","B6:D6");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbMed->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbMed->ListSource->DataSet->FieldByName("fio")->AsAnsiString.c_str());

	//8
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �/�");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������");
	vVarCell.OlePropertySet("ColumnWidth", 50);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ��. ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	//9
	vVarCell=vVarSheet.OlePropertyGet("Range","A9:D9");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������� ����������� ������������");

	//10
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ������������� ������������ ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count1 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", VuluntarMedAgreementYes/count1*1.0);

	//11
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� �������� �������� �� ��������� ������������ ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count2 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AgreementPDNYes/count2*1.0);

	//12
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ���������� ���������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count3 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ComplitListDeseaseYes/count3*1.0);

	//13
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "4");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ��������� � ���������� ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count4 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", CompitListProfAndStatusYes/count4*1.0);

	//14
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "5");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����������� �����");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count11 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", IntegrityCard/count11*1.0);

	//15
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "6");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������, ������������ ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count12 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AccuracyHandwriting/count12*1.0);


	vVarCell=vVarSheet.OlePropertyGet("Range","D10:D15");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(C10:C15)");

	//16
	vVarCell=vVarSheet.OlePropertyGet("Range","A16:D16");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� �������� ����������� ������");

	//17
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "7");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ��� (����������� ��� �����������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count5 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ExistenceFLGYes/count5*1.0);

	vVarCell=vVarSheet.OlePropertyGet("Range","D17:D31");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(C17:C31)");

	//18
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "8");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� �������� ���������� (����������� ��� �����������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count6 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ExistenceInspGinYes/count6*1.0);

	//19
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "9");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ���������� ����. ��������������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count13 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityProfInsOnko/count13*1.0);

	//20
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "10");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� (��������������� � ��������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count14 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DispTimelines/count14*1.0);

	//21
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "11");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ����� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count15 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityCollectAnamsis/count15*1.0);

	//22
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "12");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ����� �����");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count16 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", QualityCollectComplaint/count16*1.0);

	//23
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "13");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������� ������������ �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count17 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DescriptObjectStatus/count17*1.0);

	//24
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "14");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ ����������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count18 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", EvaluationResultsOfTreatment/count18*1.0);

	//25
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "15");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ���������� � �����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count19 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ObservStandartsOfDiagnostics/count19*1.0);

	//26
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "16");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ���������� � �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count20 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", ObservStandartsOfTreatment/count20*1.0);

	//27
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "17");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������������� ������������� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count7 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", RationalUseOfResourcesYes/count7*1.0);

	//28
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "18");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ����� ��������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count8 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", AbsenceComplaintsOfPatientsYes/count8*1.0);

	//29
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "19");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������� ������ �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count21 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", DeadlinesVN/count21*1.0);

	//30
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "20");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� ���������� �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count9 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", TimelyRegistLNYes/count9*1.0);

	//31
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "21");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������������� ����������� �� �� (��� �������)");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	count10 == 0 ? vVarCell.OlePropertySet("Value", "") :
		vVarCell.OlePropertySet("Value", RefferalToVKYes/count10*1.0);

	//32
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,4);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=������(D10;D17)");

	vVarCell=vVarSheet.OlePropertyGet("Range","A32:C32");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�����:");

	//BORDER:
	vVarCell = vVarSheet.OlePropertyGet("Range","A8:D32").OlePropertyGet("Borders");
	vVarCell.OlePropertySet("LineStyle", 1);

	//34
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����� ������������ ����:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", StrToInt(ECountOfVisits->Text));

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "100%");

	//35
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",35,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ���� �� ����������� �������:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",35,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->RecordCount);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",35,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000%");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=C35/C34");

	//37
	vVarCell=vVarSheet.OlePropertyGet("Range","A37:D37");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������ � �����������:");

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
	//40
	vVarCell=vVarSheet.OlePropertyGet("Range","A40:D40");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);
	//41
	vVarCell=vVarSheet.OlePropertyGet("Range","A41:D41");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//43
	vVarCell=vVarSheet.OlePropertyGet("Range","A43:C43");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������� I ������, ���������� ����������:");

	//44
	vVarCell=vVarSheet.OlePropertyGet("Range","A44:C44");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",44,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",4);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);



	//SECOND LIST (Med error)
	vVarSheet=vVarSheets.OlePropertyGet("Item",2);
	vVarSheet.OlePropertySet("Name","������");

	//1
	vVarCell=vVarSheet.OlePropertyGet("Range","A1:D1");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ ��������� ������");

	//2
	vVarCell=vVarSheet.OlePropertyGet("Range","A2:D2");
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
	vVarCell.OlePropertySet("Value", "�������:");

	vVarCell=vVarSheet.OlePropertyGet("Range","B4:D4");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbExpert->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbExpert->ListSource->DataSet->FieldByName("fio")->AsAnsiString.c_str());

	//5
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������:");
	vVarCell.OlePropertySet("ColumnWidth", 15);

	vVarCell=vVarSheet.OlePropertyGet("Range","B5:D5");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbOffice->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbOffice->ListSource->DataSet->FieldByName("name_office")->AsAnsiString.c_str());

	//6
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����:");

	vVarCell=vVarSheet.OlePropertyGet("Range","B6:D6");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	if(!DBLCbMed->ListSource->DataSet->IsEmpty())
		vVarCell.OlePropertySet("Value", DBLCbMed->ListSource->DataSet->FieldByName("fio")->AsAnsiString.c_str());

	//8
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �/�");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������������� ������");
	vVarCell.OlePropertySet("ColumnWidth", 50);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���-��");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� 1 ��.");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	//9
	vVarCell=vVarSheet.OlePropertyGet("Range","A9:D9");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������������� ������. (���������������, ����������������)");

	//10
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ��������������� �����");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkInfServYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C10/C40");

	//11
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ��������������� �������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkAnamYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",11,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C11/C40");

	//12
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ����������� �������������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkFizResYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C12/C40");

	//13
	vVarCell=vVarSheet.OlePropertyGet("Range","A13:C13");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ������������ �����������");

	//14
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ �� ���������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchNotYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C14/C40");

	//15
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ ��������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchToMuchYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",15,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C15/C40");

	//16
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchLateYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C16/C40");

	//17
	vVarCell=vVarSheet.OlePropertyGet("Range","A17:C17");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ���������������� �����������");

	//18
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ �� ���������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchInstrNotYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C18/C40");

	//19
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ ��������� �������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchInstrToMuchYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",19,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C19/C40");

	//20
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ResearchInstrLateYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C20/C40");

	//21
	vVarCell=vVarSheet.OlePropertyGet("Range","A21:C21");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ������������� ������������");

	//22
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ �� ���������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkKonsultNotYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",22,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C22/C40");

	//23
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkKonsultLateYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C23/C40");

	//24
	vVarCell=vVarSheet.OlePropertyGet("Range","A24:C24");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ��������");

	//25
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� �����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkDeseaseVerifYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C25/C40");

	//26
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� ������� ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkDeseaseTimeYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",26,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C26/C40");

	//27
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkDeseaseContentYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C27/C40");

	//28
	vVarCell=vVarSheet.OlePropertyGet("Range","A28:C28");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ������� (��������������)");

	//29
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� ������ ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkTherapyChooseDrYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C29/C40");

	//30
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�� ������� ���������� � ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkTherapyTimeAppointmentYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C30/C40");

	//31
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "3");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkTherapyPolypharmacyYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C31/C40");

	//32
	vVarCell=vVarSheet.OlePropertyGet("Range","A32:C32");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���������������");

	//33
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ������ ����� ���������� ������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ContinuityChoosePlaceYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",33,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C33/C40");

	//34
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "2");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ������� �������� �������� ������� �����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",ContinuityTimeTransferYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C34/C40");

	//35
	vVarCell=vVarSheet.OlePropertyGet("Range","A35:C35");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��������� �� ��������� �������� ��");

	//36
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",36,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "1");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",36,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�������������� ����������");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",36,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value",RemarkStandartMHYes);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",36,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=C36/C40");

	//37
	vVarCell=vVarSheet.OlePropertyGet("Range","A37:B37");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "�����:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",37,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value","=����(C10:C12;C14:C16;C18:C20;C22:C23;C25:C27;C29:C31;C33:C34;C36)");

	//BORDER:
	vVarCell = vVarSheet.OlePropertyGet("Range","A8:D37").OlePropertyGet("Borders");
	vVarCell.OlePropertySet("LineStyle", 1);

	//39
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",39,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����� ������������ ����:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",39,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", StrToInt(ECountOfVisits->Text));

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",39,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "100%");

	//40
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",40,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������� ���� �� ����������� �������:");

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",40,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->RecordCount);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",40,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000%");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "=C40/C39");

	//42
	vVarCell=vVarSheet.OlePropertyGet("Range","A42:D42");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������ � �����������:");

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//43
	vVarCell=vVarSheet.OlePropertyGet("Range","A43:D43");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//44
	vVarCell=vVarSheet.OlePropertyGet("Range","A44:D44");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//45
	vVarCell=vVarSheet.OlePropertyGet("Range","A45:D45");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//46
	vVarCell=vVarSheet.OlePropertyGet("Range","A46:D46");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);

	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);

	//48
	vVarCell=vVarSheet.OlePropertyGet("Range","A48:B48");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	vVarCell.OlePropertySet("Value", "������� I ������, ���������� ����������:");

	//49
	vVarCell=vVarSheet.OlePropertyGet("Range","A49:B49");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("HorizontalAlignment",2);
	//vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_expert")->AsAnsiString.c_str());

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",49,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",4);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell = vVarCell.OlePropertyGet("Borders",9);
	vVarCell.OlePropertySet("LineStyle", 1);


	//THIRD LIST (Med error)
	vVarSheet = vVarSheets.OlePropertyGet("Item",3);
	vVarSheet.OlePropertySet("Name","�����");

	//1
	vVarCell=vVarSheet.OlePropertyGet("Range","A1:G1");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ ������ ������");

	vVarCell=vVarSheet.OlePropertyGet("Range","A3:G3");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", period.c_str());

	//5
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �/�");
	vVarCell.OlePropertySet("ColumnWidth", 8);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��� �����");
	vVarCell.OlePropertySet("ColumnWidth", 40);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���-�� ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����� ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,5);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,6);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,7);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���");
	vVarCell.OlePropertySet("ColumnWidth", 10);



	//------------########    CALCULATION KKMP and KVO  #######--------------
	//Set queries for statistics (get users ids)
	AnsiString typeQuery, nameMed = "";
	typeQuery = "SELECT `id_user` FROM `inspection` "
				"WHERE `date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
				+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"' "
				"GROUP BY `id_user`;";

	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text = typeQuery;
	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();

	//set counter first cycle
	int i = 6;
	//set counter second cycle
	int count = 0;

	//choice of a doctor with his indicators
	while(!DMAvtoriz->DSInspection->DataSet->Eof){
		typeQuery =
			"SELECT CONCAT(`user`.`surname`,' ',`user`.`name`,' ',`user`.`patronymic`) as `fio_med`, "
			"`inspection`.`duration`,`inspection`.`kkmp1`,`inspection`.`kkmp2`,`inspection`.`kvo` "
			"FROM `user` INNER JOIN `inspection` "
			"ON `user`.`id_user` = `inspection`.`id_user` "
			"WHERE `inspection`.`id_user` = '" +DMAvtoriz->DSInspection->DataSet->FieldByName("id_user")->AsAnsiString + "' AND "
			"`inspection`.`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";

		DMAvtoriz->SQLQGetListUserStat->Close();
		DMAvtoriz->SQLQGetListUserStat->SQL->Text = typeQuery;
		DMAvtoriz->SQLQGetListUserStat->Open();
		DMAvtoriz->CDSGetListUserStat->Close();
		DMAvtoriz->CDSGetListUserStat->Open();

        //get name of user in current itteration
		if(nameMed.IsEmpty())
			nameMed = DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("fio_med")->AsAnsiString;

		//write into excel record number
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",i-5);

		//write into excel user name
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",nameMed.c_str());

		//reset kkmp and kvo indicators and count
		kkmp1 = 0;
		kkmp2 = 0;
		kvo = 0;
		count = 0;
		countCards = 0;
		countDays = 0;

		//get indicators of the current user
		while(!DMAvtoriz->DSGetListUserStat->DataSet->Eof){
			kkmp1 += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kkmp1")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			kkmp2 += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kkmp2")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			kvo += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kvo")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			count++;
			countCards++;
			countDays += DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("duration")->AsInteger;
			DMAvtoriz->DSGetListUserStat->DataSet->Next();
		}

		kkmp1 = kkmp1/count;
		kkmp2 = kkmp2/count;
		kvo = kvo/count;

		//write into excel kkmp1,kkmp2,kvo
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",countCards);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,4);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",countDays);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,5);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kkmp1);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,6);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kkmp2);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,7);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kvo);

		//reset the name of the doctor
		nameMed = "";
		//increment "i"
		i++;

		//go to the next iteration (next user)
		DMAvtoriz->DSInspection->DataSet->Next();
	}

	//BORDER:
	AnsiString ran = "A5:G" + IntToStr(i-1);
	vVarCell = vVarSheet.OlePropertyGet("Range",ran.c_str()).OlePropertyGet("Borders");
	vVarCell.OlePropertySet("LineStyle", 1);



	//-----####################  EXPERT INDICATORS (FOURTH LIST)  ##################-------
	//FOURTH LIST (Expert indicators)
	vVarSheet = vVarSheets.OlePropertyGet("Item",4);
	vVarSheet.OlePropertySet("Name","��������");

	//1
	vVarCell=vVarSheet.OlePropertyGet("Range","A1:G1");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "������ ������ ���������");

	vVarCell=vVarSheet.OlePropertyGet("Range","A3:G3");
	vVarCell.OleProcedure("Merge");
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", period.c_str());

	//5
	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,1);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "� �/�");
	vVarCell.OlePropertySet("ColumnWidth", 8);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,2);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "��� ��������");
	vVarCell.OlePropertySet("ColumnWidth", 40);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,3);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���-�� ������-�� ����");
	vVarCell.OlePropertySet("ColumnWidth", 13);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,4);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����� ����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,5);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,6);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "����");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,7);
	vVarCell.OlePropertySet("WrapText", true);
	vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
	vVarCell.OlePropertySet("HorizontalAlignment",-4108);
	vVarCell.OlePropertySet("VerticalAlignment",-4108);
	vVarCell.OlePropertySet("Value", "���");
	vVarCell.OlePropertySet("ColumnWidth", 10);

	//------------########    CALCULATION KKMP and KVO  #######--------------
	//Set queries for statistics (get users ids)
	AnsiString nameExp = "";
	typeQuery = "SELECT `id_expert` FROM `inspection` "
				"WHERE `date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
				+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"' "
				"GROUP BY `id_expert`";

	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text = typeQuery;
	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();

	//set counter first cycle
	i = 6;
	//set counter second cycle
	count = 0;

	//choice of a doctor with his indicators
	while(!DMAvtoriz->DSInspection->DataSet->Eof){
		typeQuery =
			"SELECT CONCAT(`user`.`surname`,' ',`user`.`name`,' ',`user`.`patronymic`) as `fio_expert`, "
			"`inspection`.`duration`,`inspection`.`kkmp1`,`inspection`.`kkmp2`,`inspection`.`kvo` "
			"FROM `user` INNER JOIN `inspection` "
			"ON `user`.`id_user` = `inspection`.`id_expert` "
			"WHERE `inspection`.`id_expert` = '" +DMAvtoriz->DSInspection->DataSet->FieldByName("id_expert")->AsAnsiString + "' AND "
			"`inspection`.`date_end` BETWEEN '" +FormatDateTime("yyyy-mm-dd",DTPStartReportPer->DateTime)+ "' AND '"
			+ FormatDateTime("yyyy-mm-dd",DTPEndReportPer->DateTime) +"'";

		DMAvtoriz->SQLQGetListUserStat->Close();
		DMAvtoriz->SQLQGetListUserStat->SQL->Text = typeQuery;
		DMAvtoriz->SQLQGetListUserStat->Open();
		DMAvtoriz->CDSGetListUserStat->Close();
		DMAvtoriz->CDSGetListUserStat->Open();

        //get name of expert in the current itteration
		if(nameExp.IsEmpty())
			nameExp = DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("fio_expert")->AsAnsiString;

		//write into excel record number
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",i-5);

		//write into excel expert name
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",nameExp.c_str());

		//reset kkmp and kvo indicators and count
		kkmp1 = 0;
		kkmp2 = 0;
		kvo = 0;
		count = 0;
		countCards = 0;
		countDays = 0;

		//get indicators of the current user
		while(!DMAvtoriz->DSGetListUserStat->DataSet->Eof){
			kkmp1 += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kkmp1")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			kkmp2 += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kkmp2")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			kvo += StrToFloat(StringReplace(DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("kvo")->AsAnsiString,".",",",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase));
			count++;
			countCards++;
			countDays += DMAvtoriz->DSGetListUserStat->DataSet->FieldByName("duration")->AsInteger;
			DMAvtoriz->DSGetListUserStat->DataSet->Next();
		}

		kkmp1 = kkmp1/count;
		kkmp2 = kkmp2/count;
		kvo = kvo/count;

		//write into excel kkmp1,kkmp2,kvo
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",countCards);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,4);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",countDays);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,5);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kkmp1);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,6);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kkmp2);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,7);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("NumberFormatLocal", "0,000");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value",kvo);

		//reset the name of the doctor
		nameExp = "";
		//increment "i"
		i++;

		//go to the next iteration (next user)
		DMAvtoriz->DSInspection->DataSet->Next();
	}

	//BORDER:
	ran = "A5:G" + IntToStr(i-1);
	vVarCell = vVarSheet.OlePropertyGet("Range",ran.c_str()).OlePropertyGet("Borders");
	vVarCell.OlePropertySet("LineStyle", 1);

	//------#############  END OF EXPERT BOX  #############--------------------

	DBGridReport->DataSource = NULL;

	MessageBox(0,L"����� ������ ��������!\n",L"���������",MB_OK | MB_ICONINFORMATION);
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
	count19,count20,count21,count31,count32,count33,count34,count35,count36,
	count37,count38,count39,count40,count41,count42,count43,count44,count45,
	count46,count47,count48,count49,count50	 = 0;

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

    RemarkInfServYes,RemarkAnamYes,RemarkFizResYes,ResearchNotYes,
	ResearchToMuchYes,ResearchLateYes,ResearchInstrNotYes,ResearchInstrToMuchYes,
	ResearchInstrLateYes,RemarkKonsultNotYes,RemarkKonsultLateYes,RemarkDeseaseVerifYes,
	RemarkDeseaseTimeYes,RemarkDeseaseContentYes,RemarkTherapyChooseDrYes,
	RemarkTherapyTimeAppointmentYes,RemarkTherapyPolypharmacyYes,
	ContinuityChoosePlaceYes,ContinuityTimeTransferYes,RemarkStandartMHYes = 0;

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

		// error indicators
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkInfServYes")->AsInteger == 1){
			RemarkInfServYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkInfServYes")->AsInteger;
			count31++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkAnamYes")->AsInteger == 1){
			RemarkAnamYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkAnamYes")->AsInteger;
			count32++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkFizResYes")->AsInteger == 1){
			RemarkFizResYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkFizResYes")->AsInteger;
			count33++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchNotYes")->AsInteger == 1){
			ResearchNotYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchNotYes")->AsInteger;
			count34++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchToMuchYes")->AsInteger == 1){
			ResearchToMuchYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchToMuchYes")->AsInteger;
			count35++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchLateYes")->AsInteger == 1){
			ResearchLateYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchLateYes")->AsInteger;
			count36++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrNotYes")->AsInteger == 1){
			ResearchInstrNotYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrNotYes")->AsInteger;
			count37++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrToMuchYes")->AsInteger == 1){
			ResearchInstrToMuchYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrToMuchYes")->AsInteger;
			count38++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrLateYes")->AsInteger == 1){
			ResearchInstrLateYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrLateYes")->AsInteger;
			count39++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultNotYes")->AsInteger == 1){
			RemarkKonsultNotYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultNotYes")->AsInteger;
			count40++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultLateYes")->AsInteger == 1){
			RemarkKonsultLateYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultLateYes")->AsInteger;
			count41++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseVerifYes")->AsInteger == 1){
			RemarkDeseaseVerifYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseVerifYes")->AsInteger;
			count42++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseTimeYes")->AsInteger == 1){
			RemarkDeseaseTimeYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseTimeYes")->AsInteger;
			count43++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseContentYes")->AsInteger == 1){
			RemarkDeseaseContentYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseContentYes")->AsInteger;
			count44++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyChooseDrYes")->AsInteger == 1){
			RemarkTherapyChooseDrYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyChooseDrYes")->AsInteger;
			count45++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyTimeAppointmentYes")->AsInteger == 1){
			RemarkTherapyTimeAppointmentYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyTimeAppointmentYes")->AsInteger;
			count46++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyPolypharmacyYes")->AsInteger == 1){
			RemarkTherapyPolypharmacyYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyPolypharmacyYes")->AsInteger;
			count47++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityChoosePlaceYes")->AsInteger == 1){
			ContinuityChoosePlaceYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityChoosePlaceYes")->AsInteger;
			count48++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityTimeTransferYes")->AsInteger == 1){
			ContinuityTimeTransferYes += DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityTimeTransferYes")->AsInteger;
			count49++;
		}
		if(DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkStandartMHYes")->AsInteger == 1){
			RemarkStandartMHYes += DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkStandartMHYes")->AsInteger;
			count50++;
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

