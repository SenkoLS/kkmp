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
	//AnsiString strYear = FormatDateTime("yyyy",Now().CurrentDateTime());
	DateTimePickerStart->Date = Now(); //StrToDate(strcat("01.01.",strYear.c_str()));
	DateTimePickerEnd->Date = Now();
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
	FCard->id_expert = DBGridEh1->DataSource->DataSet->FieldByName("id_expert")->AsInteger;
	if(FCard->id_inspection == 0) return;
	FCard->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BDeleteCardClick(TObject *Sender)
{
	if(DBGridEh1->DataSource->DataSet->FieldByName("id_inspection")->AsInteger == 0) return;

	if(DMAvtoriz->DSAvtoriz->DataSet->FieldByName("login")->AsAnsiString != "admin"){
		if(	DBGridEh1->DataSource->DataSet->FieldByName("id_expert")->AsInteger
		!= DMAvtoriz->DSAvtoriz->DataSet->FieldByName("id_user")->AsInteger){

			MessageBox(0,L"�� �� �������� ��� �����!\n� ��� ��� ���� �� ������ ��������!",L"���������",MB_OK | MB_ICONWARNING);
			return;
		}
	}

	int mess = MessageBox(0,L"�� ������ ������� ��������� ������?",L"��������������",MB_YESNO | MB_ICONQUESTION);
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
			MessageBox(0,L"������ ������ \"false\"!\n���������� � ������������.",L"������ ��������",MB_OK | MB_ICONSTOP);
		}
	}catch(Exception &e){
		DMAvtoriz->SQLConnectKKMP->Rollback(trans);
		MessageBox(0,e.Message.c_str(),L"������ ��������",MB_OK);
	}

	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `id_inspection` DESC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BShowCardClick(TObject *Sender)
{
	DBGridEh1DblClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BShowAllClick(TObject *Sender)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `id_inspection` DESC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BSortFioClick(TObject *Sender)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `fio` ASC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BSortDurationClick(TObject *Sender)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `duration` ASC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::BSortDateEndClick(TObject *Sender)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `date_end` ASC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFMain::DateTimePickerStartChange(TObject *Sender)
{
	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN '"+ FormatDateTime("yyyy-mm-dd",DateTimePickerStart->DateTime) +"' AND '"+ FormatDateTime("yyyy-mm-dd",DateTimePickerEnd->DateTime) +"' "
		"ORDER BY `id_inspection` DESC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DateTimePickerEndChange(TObject *Sender)
{
 	DateTimePickerStartChange(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DBLCBoxFindMedEnter(TObject *Sender)
{
	DMAvtoriz->SQLQGetListMed->Open();
	DMAvtoriz->CDSGetListMed->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DBLCBoxFindExpertEnter(TObject *Sender)
{
	DMAvtoriz->SQLQGetListMed->Open();
	DMAvtoriz->CDSGetListMed->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::DBLCBoxFindOfficeEnter(TObject *Sender)
{
	DMAvtoriz->SQLQgetListOffice->Open();
	DMAvtoriz->CDSgetListOffice->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::BPrintProtocolClick(TObject *Sender)
{
	int mess = MessageBox(0,L"�� ������ ����������� �������� � EXCEL?",L"���������",MB_YESNO | MB_ICONQUESTION);
	if(mess != 6) return;

	Variant  vVarApp,vVarBooks,vVarBook, vVarSheets,vVarSheet,vVarCell;
	UnicodeString dir_cards;
	AnsiString dir;

	if(SelectDirectory("�������� ����� ��� ���������� ���������:","",dir_cards)){
		dir = dir_cards+"\\";
		dir = dir + "�������� �����.xls";
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

		//----- GET ID_INSPECTION AND FIO_EXPERT -------------------------------
		AnsiString id_inspection = DBGridEh1->DataSource->DataSet->FieldByName("id_inspection")->AsAnsiString;
		AnsiString fio_expert;

		//----- GET DATA THE CURRENT CARD---------------------------------------
		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text =
			"SELECT `inspection`.`id_inspection`,`inspection`.`date_start`,"
			"`inspection`.`date_end`,`inspection`.`duration`,"
			"CONCAT(`inspection`.`surname`,' ',`inspection`.`name`,' ',`inspection`.`patronymic`) as `fio_pac`,"
			"`inspection`.`year_date_birthday`,"
			"`inspection`.`area`,`inspection`.`id_user`,"
			"`inspection`.`RemarkInfServYes`,`inspection`.`RemarkAnamYes`,"
			"`inspection`.`RemarkFizResYes`,`inspection`.`ResearchNotYes`,"
			"`inspection`.`ResearchToMuchYes`,`inspection`.`ResearchLateYes`,"
			"`inspection`.`ResearchInstrNotYes`,`inspection`.`ResearchInstrToMuchYes`,"
			"`inspection`.`ResearchInstrLateYes`,`inspection`.`RemarkKonsultNotYes`,"
			"`inspection`.`RemarkKonsultLateYes`,`inspection`.`RemarkDeseaseVerifYes`,"
			"`inspection`.`RemarkDeseaseTimeYes`,`inspection`.`RemarkDeseaseContentYes`,"
			"`inspection`.`RemarkTherapyChooseDrYes`,`inspection`.`RemarkTherapyTimeAppointmentYes`,"
			"`inspection`.`RemarkTherapyPolypharmacyYes`,`inspection`.`ContinuityChoosePlaceYes`,"
			"`inspection`.`ContinuityTimeTransferYes`,`inspection`.`RemarkStandartMHYes`,"
			"`inspection`.`VuluntarMedAgreementYes`,`inspection`.`AgreementPDNYes`,"
			"`inspection`.`ComplitListDeseaseYes`,`inspection`.`CompitListProfAndStatusYes`,"
			"`inspection`.`ExistenceFLGYes`,`inspection`.`ExistenceInspGinYes`,"
			"`inspection`.`RationalUseOfResourcesYes`,`inspection`.`AbsenceComplaintsOfPatientsYes`,"
			"`inspection`.`TimelyRegistLNYes`,`inspection`.`RefferalToVKYes`,"
			"`inspection`.`IntegrityCard`,`inspection`.`AccuracyHandwriting`,"
			"`inspection`.`QualityProfInsOnko`,`inspection`.`DispTimelines`,"
			"`inspection`.`QualityCollectAnamsis`,`inspection`.`QualityCollectComplaint`,"
			"`inspection`.`DescriptObjectStatus`,`inspection`.`EvaluationResultsOfTreatment`,"
			"`inspection`.`ObservStandartsOfDiagnostics`,`inspection`.`ObservStandartsOfTreatment`,"
			"`inspection`.`DeadlinesVN`,`inspection`.`kkmp`,`inspection`.`kkmp1`,`inspection`.`kkmp2`,"
			"`inspection`.`kvo`,`inspection`.`id_expert`,"
			"`user`.`id_user` as `id_user_expert`,`user`.`login`,"
			"CONCAT(`user`.`surname`,' ',`user`.`name`,' ',`user`.`patronymic`) as `fio_expert`,"
			"`user`.`id_office` "
		"FROM `inspection` INNER JOIN `user` "
		"ON `inspection`.`id_expert` = `user`.`id_user` "
		"WHERE `id_inspection` = '" + id_inspection + "'";

		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();
		//----------------------------------------------------------------------

		//FIRST LIST (KKMP)
		vVarSheet=vVarSheets.OlePropertyGet("Item",1);
		vVarSheet.OlePropertySet("Name","KKMP");
		vVarCell=vVarSheet.OlePropertyGet("Range","A1:D1");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�������� ������ �������� �������� ����������� ������ ��������(��)  I �������.");
		//3
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",3,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "����:");
		vVarCell.OlePropertySet("ColumnWidth", 15);
		//4
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��� ��������:");

        vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,2);
		vVarCell.OlePropertySet("ColumnWidth", 50);

		vVarCell=vVarSheet.OlePropertyGet("Range","B4:D4");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_pac")->AsAnsiString.c_str());
        vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//5

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

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������");
		vVarCell.OlePropertySet("ColumnWidth", 15);

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,4);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�����");
		vVarCell.OlePropertySet("ColumnWidth", 15);
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("VuluntarMedAgreementYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("AgreementPDNYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("ComplitListDeseaseYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("CompitListProfAndStatusYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("IntegrityCard")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("AccuracyHandwriting")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("ExistenceFLGYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("ExistenceInspGinYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("QualityProfInsOnko")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("DispTimelines")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("QualityCollectAnamsis")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("QualityCollectComplaint")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("DescriptObjectStatus")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("EvaluationResultsOfTreatment")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("ObservStandartsOfDiagnostics")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("ObservStandartsOfTreatment")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("RationalUseOfResourcesYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("AbsenceComplaintsOfPatientsYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("DeadlinesVN")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("TimelyRegistLNYes")->AsAnsiString.c_str());
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
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("RefferalToVKYes")->AsAnsiString.c_str());

		//-----IN TOTAL---------------------------------------------------------

		//FOR 8-13
		vVarCell=vVarSheet.OlePropertyGet("Range","D8:D13");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("kkmp1")->AsAnsiString.c_str());

		//FOR 15-29
		//FOR 8-13
		vVarCell=vVarSheet.OlePropertyGet("Range","D15:D29");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("kkmp2")->AsAnsiString.c_str());

        //30
		vVarCell=vVarSheet.OlePropertyGet("Range","A30:C30");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�����:");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",30,4);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "=D8&\" / \"&D15");

		//-----END OF IN TOTAL--------------------------------------------------

		//BORDER:
		vVarCell = vVarSheet.OlePropertyGet("Range","A6:D30").OlePropertyGet("Borders");
		vVarCell.OlePropertySet("LineStyle", 1);

		//33
		vVarCell=vVarSheet.OlePropertyGet("Range","A33:D33");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", "������ � �����������:");

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//34
		vVarCell=vVarSheet.OlePropertyGet("Range","A34:D34");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//35
		vVarCell=vVarSheet.OlePropertyGet("Range","A35:D35");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

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

		//39
		vVarCell=vVarSheet.OlePropertyGet("Range","A39:C39");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", "������� I ������, ���������� ����������:");

		//40
        vVarCell=vVarSheet.OlePropertyGet("Range","A40:C40");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_expert")->AsAnsiString.c_str());

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",40,4);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",4);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
        vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);

		//----- SECOND LIST (KVO) ----------------------------------------------
		vVarSheet=vVarSheets.OlePropertyGet("Item",2);
		vVarSheet.OlePropertySet("Name","KVO");
		vVarCell=vVarSheet.OlePropertyGet("Range","A1:C1");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�������� ������ ��������� ������ ��� �������� �� ��������(��)  I �������.");
		//3
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",3,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "����:");
		vVarCell.OlePropertySet("ColumnWidth", 15);
		//4
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��� ��������:");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,2);
		vVarCell.OlePropertySet("ColumnWidth", 50);

		vVarCell=vVarSheet.OlePropertyGet("Range","B4:C4");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_pac")->AsAnsiString.c_str());
		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//5

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

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������");
		vVarCell.OlePropertySet("ColumnWidth", 15);
		//7
		vVarCell=vVarSheet.OlePropertyGet("Range","A7:C7");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "���������������� ������. (���������������, ����������������)");
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
		vVarCell.OlePropertySet("Value", "��������� �� ��������������� �����");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkInfServYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
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
		vVarCell.OlePropertySet("Value", "��������� �� ��������������� �������� �������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",9,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkAnamYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
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
		vVarCell.OlePropertySet("Value", "��������� �� ����������� �������������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",10,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkFizResYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//11
		vVarCell=vVarSheet.OlePropertyGet("Range","A11:C11");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ������������ �����������");
		//12
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ �� ���������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",12,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchNotYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//13
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ ��������� �������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",13,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchToMuchYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//14
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "3");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",14,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchLateYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//15
		vVarCell=vVarSheet.OlePropertyGet("Range","A15:C15");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ���������������� �����������");
		//16
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ �� ���������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",16,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchInstrNotYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//17
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ ��������� �������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",17,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchInstrToMuchYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//18
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "3");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",18,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ResearchInstrLateYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//19
		vVarCell=vVarSheet.OlePropertyGet("Range","A19:C19");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ������������� ������������");
		//20
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ �� ���������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",20,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkKonsultNotYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//21
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "������������ ��������� ��������������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",21,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkKonsultLateYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//22
        vVarCell=vVarSheet.OlePropertyGet("Range","A22:C22");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ��������");
		//23
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�� �����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",23,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkDeseaseVerifYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//24
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�� ������� ����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",24,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkDeseaseTimeYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//25
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "3");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�� ����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",25,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkDeseaseContentYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//26
		vVarCell=vVarSheet.OlePropertyGet("Range","A26:C26");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ������� (��������������)");
		//27
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�� ������ ����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",27,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkTherapyChooseDrYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//28
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�� ������� ���������� � ������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",28,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkTherapyTimeAppointmentYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//29
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "3");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�������������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",29,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkTherapyPolypharmacyYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//30
		vVarCell=vVarSheet.OlePropertyGet("Range","A30:C30");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "���������������");
		//31
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ������ ����� ���������� ������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",31,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ContinuityChoosePlaceYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//32
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "2");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ������� �������� �������� ������� �����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",32,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("ContinuityTimeTransferYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}
		//33
		vVarCell=vVarSheet.OlePropertyGet("Range","A33:C33");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertyGet("Interior").OlePropertySet("Color",0xF0F8FF);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "��������� �� ��������� �������� ��");
		//34
		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,1);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "1");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,2);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�������������� ����������");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",34,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		switch(DMAvtoriz->DSPInspection->DataSet->FieldByName("RemarkStandartMHYes")->AsInteger){
			case 1:	vVarCell.OlePropertySet("Value", "��"); break;
			case 2: vVarCell.OlePropertySet("Value", "���"); break;
			default: vVarCell.OlePropertySet("Value", "");
		}

		//35
		vVarCell=vVarSheet.OlePropertyGet("Range","A35:B35");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", "�����:");

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",35,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSPInspection->DataSet->FieldByName("kvo")->AsAnsiString.c_str());

		//BORDER:
		vVarCell = vVarSheet.OlePropertyGet("Range","A6:C35").OlePropertyGet("Borders");
		vVarCell.OlePropertySet("LineStyle", 1);

		//39
		vVarCell=vVarSheet.OlePropertyGet("Range","A39:C39");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", "������ � �����������:");

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//40
		vVarCell=vVarSheet.OlePropertyGet("Range","A40:C40");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//41
		vVarCell=vVarSheet.OlePropertyGet("Range","A41:C41");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//42
		vVarCell=vVarSheet.OlePropertyGet("Range","A42:C42");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);
		//43
		vVarCell=vVarSheet.OlePropertyGet("Range","A43:C43");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);

		vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);

		//45
		vVarCell=vVarSheet.OlePropertyGet("Range","A45:B45");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", "������� I ������, ���������� ����������:");

		//46
        vVarCell=vVarSheet.OlePropertyGet("Range","A46:B46");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",2);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_expert")->AsAnsiString.c_str());

		vVarCell = vVarSheet.OlePropertyGet("Cells").OlePropertyGet("Item",46,3);
		vVarCell.OlePropertySet("WrapText", true);
		vVarCell.OlePropertySet("HorizontalAlignment",4);
		vVarCell.OlePropertySet("VerticalAlignment",-4108);
        vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);

		//GET MED FOR EXCEL:
		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text =
			"SELECT CONCAT(`user`.`surname`,' ',`user`.`name`,' ',`user`.`patronymic`) as `fio_med` FROM `inspection` INNER JOIN `user` "
			"ON `inspection`.`id_user` = `user`.`id_user` "
			"WHERE `id_inspection` = '" + id_inspection + "'";
		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();

		vVarCell=vVarSheet.OlePropertyGet("Range","B3:C3");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_med")->AsAnsiString.c_str());
        vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);

		//SET MED INTO LIST 1
		vVarSheet=vVarSheets.OlePropertyGet("Item",1);
		vVarCell=vVarSheet.OlePropertyGet("Range","B3:D3");
		vVarCell.OleProcedure("Merge");
		vVarCell.OlePropertySet("HorizontalAlignment",-4108);
		vVarCell.OlePropertySet("Value", DMAvtoriz->DSInspection->DataSet->FieldByName("fio_med")->AsAnsiString.c_str());
        vVarCell = vVarCell.OlePropertyGet("Borders",9);
		vVarCell.OlePropertySet("LineStyle", 1);

        //save into catalog:
		vVarApp.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",dir.c_str());
		//vVarApp.OleProcedure("Quit");

		//COME BACK GREED
		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text =
			"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
			"`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert` "
			"FROM `inspection` "
			"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
			"ORDER BY `id_inspection` DESC";

		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();

		MessageBox(0, L"�������� ��������� ����� ���������.", L"���������", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::N2Click(TObject *Sender)
{
	FStatReport->ShowModal();
}
//---------------------------------------------------------------------------

