//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeCanvas"
#pragma resource "*.dfm"
TFCard *FCard;
//---------------------------------------------------------------------------
__fastcall TFCard::TFCard(TComponent* Owner)
	: TForm(Owner)
{
	clearForm(Owner);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::clearForm(TObject *Sender){
	amountRightPanels = 0;
	amountLeftPanels = 0;

	//for kvo
	kvo = 0;
	RemarkInfServYes = 0;
	RemarkAnamYes = 0;
	RemarkFizResYes = 0;
	ResearchNotYes = 0;
	ResearchToMuchYes = 0;
	ResearchLateYes = 0;
	ResearchInstrNotYes = 0;
	ResearchInstrToMuchYes = 0;
	ResearchInstrLateYes = 0;
	RemarkKonsultNotYes = 0;
	RemarkKonsultLateYes = 0;
	RemarkDeseaseVerifYes = 0;
	RemarkDeseaseTimeYes = 0;
	RemarkDeseaseContentYes = 0;
	RemarkTherapyChooseDrYes = 0;
	RemarkTherapyTimeAppointmentYes = 0;
	RemarkTherapyPolypharmacyYes = 0;
	ContinuityChoosePlaceYes = 0;
	ContinuityTimeTransferYes = 0;
	RemarkStandartMHYes = 0;

	//for kkmp
	kkmp = 0;
	VuluntarMedAgreementYes = 0;
	AgreementPDNYes = 0;
	ComplitListDeseaseYes = 0;
	CompitListProfAndStatusYes = 0;
	ExistenceFLGYes = 0;
	ExistenceInspGinYes = 0;
	RationalUseOfResourcesYes = 0;
	AbsenceComplaintsOfPatientsYes = 0;
	TimelyRegistLNYes = 0;
	RefferalToVKYes = 0;

	IntegrityCard = 0;
	AccuracyHandwriting = 0;
	QualityProfInsOnko = 0;
	DispTimelines = 0;
	QualityCollectAnamsis = 0;
	QualityCollectComplaint = 0;
	DescriptObjectStatus = 0;
	EvaluationResultsOfTreatment = 0;
	ObservStandartsOfDiagnostics = 0;
	ObservStandartsOfTreatment = 0;
	DeadlinesVN = 0;

	//set fields of form
    DTPDateStart->Date = Now();
	DTPDateEnd->Date = Now();
	EArea->Text = "";
	ESurname->Text = "";
	EName->Text = "";
	EPatronymic->Text = "";
	EYearOfBirthday->Text = "";
	DBLookupComboBoxListMed->KeyValue = 1;
	id_inspection = NULL; //set editing in false

	//left panel
	PVuluntarMedAgreementClick(Sender);
	PAgreementPDNClick(Sender);
	PComplitListDeseaseClick(Sender);
	PCompitListProfAndStatusClick(Sender);
	PIntegrityCardClick(Sender);
	PAccuracyHandwritingClick(Sender);
	PExistenceFLGClick(Sender);
	PExistenceInspGinClick(Sender);
	PQualityProfInsOnkoClick(Sender);
	PDispTimelinesClick(Sender);
	PQualityCollectAnamsisClick(Sender);
	PQualityCollectComplaintClick(Sender);
	PDescriptObjectStatusClick(Sender);
	PEvaluationResultsOfTreatmentClick(Sender);
	PObservStandartsOfDiagnosticsClick(Sender);
	PObservStandartsOfTreatmentClick(Sender);
	PRationalUseOfResourcesClick(Sender);
	PAbsenceComplaintsOfPatientsClick(Sender);
	PDeadlinesVNClick(Sender);
	PTimelyRegistLNClick(Sender);
	PRefferalToVKClick(Sender);

	//right panel
    PRemarkInfServClick(Sender);
	PRemarkAnamClick(Sender);
	PRemarkFizResClick(Sender);
	PResearchNotClick(Sender);
	PResearchToMuchClick(Sender);
	PResearchLateClick(Sender);
	PResearchInstrNotClick(Sender);
	PResearchInstrToMuchClick(Sender);
	PResearchInstrLateClick(Sender);
	PRemarkKonsultNotClick(Sender);
	PRemarkKonsultLateClick(Sender);
	PRemarkDeseaseVerifClick(Sender);
	PRemarkDeseaseTimeClick(Sender);
	PRemarkDeseaseContentClick(Sender);
	PRemarkTherapyChooseDrClick(Sender);
	PRemarkTherapyTimeAppointmentClick(Sender);
	PRemarkTherapyPolypharmacyClick(Sender);
	PContinuityChoosePlaceClick(Sender);
	PContinuityTimeTransferClick(Sender);
	PRemarkStandartMHClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::getKvo(){
	kvo = 0;
	amountRightPanels = 0;
	if(RemarkInfServYes != 0){
		if(RemarkInfServYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkAnamYes != 0){
		if(RemarkAnamYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkFizResYes != 0){
		if(RemarkFizResYes == 1) kvo++;
		amountRightPanels++;
	}

	if(ResearchNotYes != 0){
		if(ResearchNotYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ResearchToMuchYes != 0){
		if(ResearchToMuchYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ResearchLateYes != 0){
		if(ResearchLateYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ResearchInstrNotYes != 0){
		if(ResearchInstrNotYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ResearchInstrToMuchYes != 0){
		if(ResearchInstrToMuchYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ResearchInstrLateYes != 0){
		if(ResearchInstrLateYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkKonsultNotYes != 0){
		if(RemarkKonsultNotYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkKonsultLateYes != 0){
		if(RemarkKonsultLateYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkDeseaseVerifYes != 0){
		if(RemarkDeseaseVerifYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkDeseaseTimeYes != 0){
		if(RemarkDeseaseTimeYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkDeseaseContentYes != 0){
		if(RemarkDeseaseContentYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkTherapyChooseDrYes != 0){
		if(RemarkTherapyChooseDrYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkTherapyTimeAppointmentYes != 0){
		if(RemarkTherapyTimeAppointmentYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkTherapyPolypharmacyYes != 0){
		if(RemarkTherapyPolypharmacyYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ContinuityChoosePlaceYes != 0){
		if(ContinuityChoosePlaceYes == 1) kvo++;
		amountRightPanels++;
	}
	if(ContinuityTimeTransferYes != 0){
		if(ContinuityTimeTransferYes == 1) kvo++;
		amountRightPanels++;
	}
	if(RemarkStandartMHYes != 0){
		if(RemarkStandartMHYes == 1) kvo++;
		amountRightPanels++;
	}

	if(amountRightPanels != 0)
		kvo = (kvo/amountRightPanels);
	else
		kvo = 0;

	PKvo->Caption = FloatToStr(SimpleRoundTo(kvo,-3));
}
//---------------------------------------------------------------------------
void __fastcall TFCard::getKkmp(){

	//First part:
	kkmp = 0;
	amountLeftPanels = 0;

	if(VuluntarMedAgreementYes != 0){
		kkmp = kkmp + VuluntarMedAgreementYes;
		amountLeftPanels++;
	}
	if(AgreementPDNYes != 0){
		kkmp = kkmp + AgreementPDNYes;
		amountLeftPanels++;
	}
	if(ComplitListDeseaseYes != 0){
		kkmp = kkmp + ComplitListDeseaseYes;
		amountLeftPanels++;
	}
	if(CompitListProfAndStatusYes != 0){
		kkmp = kkmp + CompitListProfAndStatusYes;
		amountLeftPanels++;
	}
	if(IntegrityCard != 0){
		kkmp = kkmp + IntegrityCard;
		amountLeftPanels++;
	}
	if(AccuracyHandwriting != 0){
		kkmp = kkmp + AccuracyHandwriting;
		amountLeftPanels++;
	}
	if(amountLeftPanels != 0)
		kkmp = SimpleRoundTo(kkmp/(amountLeftPanels*5),-3);
	else
		kkmp = 1;

	AnsiString interValue = FloatToStr(kkmp);

	//Second part:
	kkmp = 0;
	amountLeftPanels = 0;

	if(ExistenceFLGYes != 0){
		kkmp = kkmp + ExistenceFLGYes;
		amountLeftPanels++;
	}
	if(ExistenceInspGinYes != 0){
		kkmp = kkmp + ExistenceInspGinYes;
		amountLeftPanels++;
	}
	if(RationalUseOfResourcesYes != 0){
		kkmp = kkmp + RationalUseOfResourcesYes;
		amountLeftPanels++;
	}
	if(AbsenceComplaintsOfPatientsYes != 0){
		kkmp = kkmp + AbsenceComplaintsOfPatientsYes;
		amountLeftPanels++;
	}
	if(TimelyRegistLNYes != 0){
		kkmp = kkmp + TimelyRegistLNYes;
		amountLeftPanels++;
	}
	if(RefferalToVKYes != 0){
		kkmp = kkmp + RefferalToVKYes;
		amountLeftPanels++;
	}
	if(QualityProfInsOnko != 0){
		kkmp = kkmp + QualityProfInsOnko;
		amountLeftPanels++;
	}
	if(DispTimelines != 0){
		kkmp = kkmp + DispTimelines;
		amountLeftPanels++;
	}
	if(QualityCollectAnamsis != 0){
		kkmp = kkmp + QualityCollectAnamsis;
		amountLeftPanels++;
	}
	if(QualityCollectComplaint != 0){
		kkmp = kkmp + QualityCollectComplaint;
		amountLeftPanels++;
	}
	if(DescriptObjectStatus != 0){
		kkmp = kkmp + DescriptObjectStatus;
		amountLeftPanels++;
	}
	if(EvaluationResultsOfTreatment != 0){
		kkmp = kkmp + EvaluationResultsOfTreatment;
		amountLeftPanels++;
	}
	if(ObservStandartsOfDiagnostics != 0){
		kkmp = kkmp + ObservStandartsOfDiagnostics;
		amountLeftPanels++;
	}
	if(ObservStandartsOfTreatment != 0){
		kkmp = kkmp + ObservStandartsOfTreatment;
		amountLeftPanels++;
	}
	if(DeadlinesVN != 0){
		kkmp = kkmp + DeadlinesVN;
		amountLeftPanels++;
	}

    if(amountLeftPanels != 0)
		kkmp = SimpleRoundTo(kkmp/(amountLeftPanels*5),-3);
	else
		kkmp = 1;

	PKKMP->Caption = interValue + " / " + FloatToStr(kkmp);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkInfServYesClick(TObject *Sender)
{
	PRemarkInfServYes->Color = TColor(0x0064B1FF);
	PRemarkInfServNo->Color = clWhite;
	RemarkInfServYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkInfServNoClick(TObject *Sender)
{
	PRemarkInfServNo->Color = TColor(0x0064B1FF);
	PRemarkInfServYes->Color = clWhite;
	RemarkInfServYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkAnamYesClick(TObject *Sender)
{
	PRemarkAnamYes->Color = TColor(0x0064B1FF);
	PRemarkAnamNo->Color = clWhite;
	RemarkAnamYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkAnamNoClick(TObject *Sender)
{
	PRemarkAnamNo->Color = TColor(0x0064B1FF);
	PRemarkAnamYes->Color = clWhite;
	RemarkAnamYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkFizResYesClick(TObject *Sender)
{
	PRemarkFizResYes->Color = TColor(0x0064B1FF);
	PRemarkFizResNo->Color = clWhite;
	RemarkFizResYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkFizResNoClick(TObject *Sender)
{
	PRemarkFizResNo->Color = TColor(0x0064B1FF);
	PRemarkFizResYes->Color = clWhite;
	RemarkFizResYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchNotYesClick(TObject *Sender)
{
	PResearchNotYes->Color = TColor(0x0064B1FF);
	PResearchNotNo->Color = clWhite;
	ResearchNotYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchNotNoClick(TObject *Sender)
{
	PResearchNotNo->Color = TColor(0x0064B1FF);
	PResearchNotYes->Color = clWhite;
	ResearchNotYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchToMuchYesClick(TObject *Sender)
{
	PResearchToMuchYes->Color = TColor(0x0064B1FF);
	PResearchToMuchNo->Color = clWhite;
	ResearchToMuchYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchToMuchNoClick(TObject *Sender)
{
	PResearchToMuchNo->Color = TColor(0x0064B1FF);
	PResearchToMuchYes->Color = clWhite;
	ResearchToMuchYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchLateYesClick(TObject *Sender)
{
	PResearchLateYes->Color = TColor(0x0064B1FF);
	PResearchLateNo->Color = clWhite;
	ResearchLateYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchLateNoClick(TObject *Sender)
{
	PResearchLateYes->Color = clWhite;
	PResearchLateNo->Color = TColor(0x0064B1FF);
	ResearchLateYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrNotYesClick(TObject *Sender)
{
	PResearchInstrNotYes->Color = TColor(0x0064B1FF);
	PResearchInstrNotNo->Color = clWhite;
	ResearchInstrNotYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrNotNoClick(TObject *Sender)
{
	PResearchInstrNotNo->Color = TColor(0x0064B1FF);
	PResearchInstrNotYes->Color = clWhite;
	ResearchInstrNotYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrToMuchYesClick(TObject *Sender)
{
	PResearchInstrToMuchYes->Color = TColor(0x0064B1FF);
	PResearchInstrToMuchNo->Color = clWhite;
	ResearchInstrToMuchYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrToMuchNoClick(TObject *Sender)
{
	PResearchInstrToMuchNo->Color = TColor(0x0064B1FF);
	PResearchInstrToMuchYes->Color = clWhite;
	ResearchInstrToMuchYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrLateYesClick(TObject *Sender)
{
	PResearchInstrLateYes->Color = TColor(0x0064B1FF);
	PResearchInstrLateNo->Color = clWhite;
	ResearchInstrLateYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrLateNoClick(TObject *Sender)
{
	PResearchInstrLateNo->Color = TColor(0x0064B1FF);
	PResearchInstrLateYes->Color = clWhite;
	ResearchInstrLateYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultNotYesClick(TObject *Sender)
{
	PRemarkKonsultNotYes->Color = TColor(0x0064B1FF);
	PRemarkKonsultNotNo->Color = clWhite;
	RemarkKonsultNotYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultNotNoClick(TObject *Sender)
{
	PRemarkKonsultNotNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultNotYes->Color = clWhite;
	RemarkKonsultNotYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultLateYesClick(TObject *Sender)
{
	PRemarkKonsultLateYes->Color = TColor(0x0064B1FF);
	PRemarkKonsultLateNo->Color = clWhite;
	RemarkKonsultLateYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultLateNoClick(TObject *Sender)
{
	PRemarkKonsultLateNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultLateYes->Color = clWhite;
	RemarkKonsultLateYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseVerifYesClick(TObject *Sender)
{
	PRemarkDeseaseVerifYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseVerifNo->Color = clWhite;
	RemarkDeseaseVerifYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseVerifNoClick(TObject *Sender)
{
	PRemarkDeseaseVerifNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseVerifYes->Color = clWhite;
	RemarkDeseaseVerifYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseTimeYesClick(TObject *Sender)
{
	PRemarkDeseaseTimeYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseTimeNo->Color = clWhite;
	RemarkDeseaseTimeYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseTimeNoClick(TObject *Sender)
{
	PRemarkDeseaseTimeNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseTimeYes->Color = clWhite;
	RemarkDeseaseTimeYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseContentYesClick(TObject *Sender)
{
	PRemarkDeseaseContentYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseContentNo->Color = clWhite;
	RemarkDeseaseContentYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseContentNoClick(TObject *Sender)
{
	PRemarkDeseaseContentNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseContentYes->Color = clWhite;
	RemarkDeseaseContentYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyChooseDrYesClick(TObject *Sender)
{
	PRemarkTherapyChooseDrYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyChooseDrNo->Color = clWhite;
	RemarkTherapyChooseDrYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyChooseDrNoClick(TObject *Sender)
{
	PRemarkTherapyChooseDrNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyChooseDrYes->Color = clWhite;
	RemarkTherapyChooseDrYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyTimeAppointmentYesClick(TObject *Sender)
{
	PRemarkTherapyTimeAppointmentYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyTimeAppointmentNo->Color = clWhite;
	RemarkTherapyTimeAppointmentYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkTherapyTimeAppointmentNoClick(TObject *Sender)
{
	PRemarkTherapyTimeAppointmentNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyTimeAppointmentYes->Color = clWhite;
	RemarkTherapyTimeAppointmentYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkTherapyPolypharmacyYesClick(TObject *Sender)
{
	PRemarkTherapyPolypharmacyYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyPolypharmacyNo->Color = clWhite;
	RemarkTherapyPolypharmacyYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyPolypharmacyNoClick(TObject *Sender)
{
	PRemarkTherapyPolypharmacyNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyPolypharmacyYes->Color = clWhite;
	RemarkTherapyPolypharmacyYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityChoosePlaceYesClick(TObject *Sender)
{
	PContinuityChoosePlaceYes->Color = TColor(0x0064B1FF);
	PContinuityChoosePlaceNo->Color = clWhite;
	ContinuityChoosePlaceYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityChoosePlaceNoClick(TObject *Sender)
{
	PContinuityChoosePlaceNo->Color = TColor(0x0064B1FF);
	PContinuityChoosePlaceYes->Color = clWhite;
	ContinuityChoosePlaceYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityTimeTransferYesClick(TObject *Sender)
{
	PContinuityTimeTransferYes->Color = TColor(0x0064B1FF);
	PContinuityTimeTransferNo->Color = clWhite;
	ContinuityTimeTransferYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityTimeTransferNoClick(TObject *Sender)
{
	PContinuityTimeTransferNo->Color = TColor(0x0064B1FF);
	PContinuityTimeTransferYes->Color = clWhite;
	ContinuityTimeTransferYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkStandartMHYesClick(TObject *Sender)
{
	PRemarkStandartMHYes->Color = TColor(0x0064B1FF);
	PRemarkStandartMHNo->Color = clWhite;
	RemarkStandartMHYes = 1;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkStandartMHNoClick(TObject *Sender)
{
	PRemarkStandartMHNo->Color = TColor(0x0064B1FF);
	PRemarkStandartMHYes->Color = clWhite;
	RemarkStandartMHYes = 2;
	getKvo();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PVuluntarMedAgreementYesClick(TObject *Sender)
{
	PVuluntarMedAgreementNo->Color = clWhite;
	PVuluntarMedAgreementYes->Color = TColor(0x0064B1FF);
	VuluntarMedAgreementYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PVuluntarMedAgreementNoClick(TObject *Sender)
{
	PVuluntarMedAgreementYes->Color = clWhite;
	PVuluntarMedAgreementNo->Color = TColor(0x0064B1FF);
	VuluntarMedAgreementYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAgreementPDNYesClick(TObject *Sender)
{
	PAgreementPDNYes->Color = TColor(0x0064B1FF);
	PAgreementPDNNo->Color = clWhite;
	AgreementPDNYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAgreementPDNNoClick(TObject *Sender)
{
	PAgreementPDNYes->Color = clWhite;
	PAgreementPDNNo->Color = TColor(0x0064B1FF);
	AgreementPDNYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PComplitListDeseaseYesClick(TObject *Sender)
{
	PComplitListDeseaseYes->Color = TColor(0x0064B1FF);
	PComplitListDeseaseNo->Color = clWhite;
	ComplitListDeseaseYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PComplitListDeseaseNoClick(TObject *Sender)
{
	PComplitListDeseaseYes->Color = clWhite;
	PComplitListDeseaseNo->Color = TColor(0x0064B1FF);
	ComplitListDeseaseYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PCompitListProfAndStatusYesClick(TObject *Sender)
{
	PCompitListProfAndStatusYes->Color = TColor(0x0064B1FF);
	PCompitListProfAndStatusNo->Color = clWhite;
	CompitListProfAndStatusYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PCompitListProfAndStatusNoClick(TObject *Sender)
{
	PCompitListProfAndStatusYes->Color = clWhite;
	PCompitListProfAndStatusNo->Color = TColor(0x0064B1FF);
	CompitListProfAndStatusYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCard1Click(TObject *Sender)
{
	PIntegrityCard1->Color = TColor(0x0064B1FF);
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard4->Color = clWhite;
	PIntegrityCard5->Color = clWhite;
	IntegrityCard = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCard2Click(TObject *Sender)
{
	PIntegrityCard1->Color = clWhite;
	PIntegrityCard2->Color = TColor(0x0064B1FF);
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard4->Color = clWhite;
	PIntegrityCard5->Color = clWhite;
	IntegrityCard = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCard3Click(TObject *Sender)
{
	PIntegrityCard1->Color = clWhite;
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard3->Color = TColor(0x0064B1FF);
	PIntegrityCard4->Color = clWhite;
	PIntegrityCard5->Color = clWhite;
	IntegrityCard = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCard4Click(TObject *Sender)
{
	PIntegrityCard1->Color = clWhite;
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard4->Color = TColor(0x0064B1FF);
	PIntegrityCard5->Color = clWhite;
	IntegrityCard = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCard5Click(TObject *Sender)
{
	PIntegrityCard1->Color = clWhite;
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard4->Color = clWhite;
	PIntegrityCard5->Color = TColor(0x0064B1FF);
	IntegrityCard = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::SpBAllNoClick(TObject *Sender)
{
	PRemarkInfServNo->Color = TColor(0x0064B1FF);
	PRemarkAnamNo->Color = TColor(0x0064B1FF);
	PRemarkFizResNo->Color = TColor(0x0064B1FF);
	PResearchNotNo->Color = TColor(0x0064B1FF);
	PResearchToMuchNo->Color = TColor(0x0064B1FF);
	PResearchLateNo->Color = TColor(0x0064B1FF);
	PResearchInstrNotNo->Color = TColor(0x0064B1FF);
	PResearchInstrToMuchNo->Color = TColor(0x0064B1FF);
	PResearchInstrLateNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultNotNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultLateNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseVerifNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseTimeNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseContentNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyChooseDrNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyTimeAppointmentNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyPolypharmacyNo->Color = TColor(0x0064B1FF);
	PContinuityChoosePlaceNo->Color = TColor(0x0064B1FF);
	PContinuityTimeTransferNo->Color = TColor(0x0064B1FF);
	PRemarkStandartMHNo->Color = TColor(0x0064B1FF);

	PRemarkInfServYes->Color = clWhite;
	PRemarkAnamYes->Color = clWhite;
	PRemarkFizResYes->Color = clWhite;
	PResearchNotYes->Color = clWhite;
	PResearchToMuchYes->Color = clWhite;
	PResearchLateYes->Color = clWhite;
	PResearchInstrNotYes->Color = clWhite;
	PResearchInstrToMuchYes->Color = clWhite;
	PResearchInstrLateYes->Color = clWhite;
	PRemarkKonsultNotYes->Color = clWhite;
	PRemarkKonsultLateYes->Color = clWhite;
	PRemarkDeseaseVerifYes->Color = clWhite;
	PRemarkDeseaseTimeYes->Color = clWhite;
	PRemarkDeseaseContentYes->Color = clWhite;
	PRemarkTherapyChooseDrYes->Color = clWhite;
	PRemarkTherapyTimeAppointmentYes->Color = clWhite;
	PRemarkTherapyPolypharmacyYes->Color = clWhite;
	PContinuityChoosePlaceYes->Color = clWhite;
	PContinuityTimeTransferYes->Color = clWhite;
	PRemarkStandartMHYes->Color = clWhite;

	RemarkInfServYes = 2;
	RemarkAnamYes = 2;
	RemarkFizResYes = 2;
	ResearchNotYes = 2;
	ResearchToMuchYes = 2;
	ResearchLateYes = 2;
	ResearchInstrNotYes = 2;
	ResearchInstrToMuchYes = 2;
	ResearchInstrLateYes = 2;
	RemarkKonsultNotYes = 2;
	RemarkKonsultLateYes = 2;
	RemarkDeseaseVerifYes = 2;
	RemarkDeseaseTimeYes = 2;
	RemarkDeseaseContentYes = 2;
	RemarkTherapyChooseDrYes = 2;
	RemarkTherapyTimeAppointmentYes = 2;
	RemarkTherapyPolypharmacyYes = 2;
	ContinuityChoosePlaceYes = 2;
	ContinuityTimeTransferYes = 2;
	RemarkStandartMHYes = 2;

	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::FormShow(TObject *Sender)
{
	if(id_inspection != NULL){      //check on the editing mode
        //download data card for editing
		DMAvtoriz->SQLQInspection->Close();
		DMAvtoriz->SQLQInspection->SQL->Text = "SELECT * FROM `inspection` WHERE `id_inspection` = " + IntToStr(id_inspection);
		DMAvtoriz->SQLQInspection->Open();
		DMAvtoriz->CDSInspection->Close();
		DMAvtoriz->CDSInspection->Open();
		DTPDateStart->Date = DMAvtoriz->DSInspection->DataSet->FieldByName("date_start")->AsDateTime;
		DTPDateEnd->Date = DMAvtoriz->DSInspection->DataSet->FieldByName("date_end")->AsDateTime;
		DBLookupComboBoxListMed->KeyValue = DMAvtoriz->DSInspection->DataSet->FieldByName("id_user")->AsInteger;
		ESurname->Text = DMAvtoriz->DSInspection->DataSet->FieldByName("surname")->AsAnsiString;
		EName->Text = DMAvtoriz->DSInspection->DataSet->FieldByName("name")->AsAnsiString;
		EPatronymic->Text = DMAvtoriz->DSInspection->DataSet->FieldByName("patronymic")->AsAnsiString;
		EYearOfBirthday->Text = DMAvtoriz->DSInspection->DataSet->FieldByName("year_date_birthday")->AsAnsiString;
		EArea->Text = DMAvtoriz->DSInspection->DataSet->FieldByName("area")->AsAnsiString;

		//--------------------
		if(RemarkInfServYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkInfServYes")->AsInteger){
			PRemarkInfServYes->Color = TColor(0x0064B1FF);
			PRemarkInfServNo->Color = clWhite;
		}else{
			PRemarkInfServYes->Color = clWhite;
			PRemarkInfServNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkAnamYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkAnamYes")->AsInteger){
			PRemarkAnamYes->Color = TColor(0x0064B1FF);
			PRemarkAnamNo->Color = clWhite;
		}else{
			PRemarkAnamYes->Color = clWhite;
			PRemarkAnamNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkFizResYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkFizResYes")->AsInteger){
			PRemarkFizResYes->Color = TColor(0x0064B1FF);
			PRemarkFizResNo->Color = clWhite;
		}else{
			PRemarkFizResYes->Color = clWhite;
			PRemarkFizResNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchNotYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchNotYes")->AsInteger){
			PResearchNotYes->Color = TColor(0x0064B1FF);
			PResearchNotNo->Color = clWhite;
		}else{
			PResearchNotYes->Color = clWhite;
			PResearchNotNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchToMuchYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchToMuchYes")->AsInteger){
			PResearchToMuchYes->Color = TColor(0x0064B1FF);
			PResearchToMuchNo->Color = clWhite;
		}else{
			PResearchToMuchYes->Color = clWhite;
			PResearchToMuchNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchLateYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchLateYes")->AsInteger){
			PResearchLateYes->Color = TColor(0x0064B1FF);
			PResearchLateNo->Color = clWhite;
		}else{
			PResearchLateYes->Color = clWhite;
			PResearchLateNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchInstrNotYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrNotYes")->AsInteger){
			PResearchInstrNotYes->Color = TColor(0x0064B1FF);
			PResearchInstrNotNo->Color = clWhite;
		}else{
			PResearchInstrNotYes->Color = clWhite;
			PResearchInstrNotNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchInstrToMuchYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrToMuchYes")->AsInteger){
			PResearchInstrToMuchYes->Color = TColor(0x0064B1FF);
			PResearchInstrToMuchNo->Color = clWhite;
		}else{
			PResearchInstrToMuchYes->Color = clWhite;
			PResearchInstrToMuchNo->Color = TColor(0x0064B1FF);
		}

		if(ResearchInstrLateYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ResearchInstrLateYes")->AsInteger){
			PResearchInstrLateYes->Color = TColor(0x0064B1FF);
			PResearchInstrLateNo->Color = clWhite;
		}else{
			PResearchInstrLateYes->Color = clWhite;
			PResearchInstrLateNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkKonsultNotYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultNotYes")->AsInteger){
			PRemarkKonsultNotYes->Color = TColor(0x0064B1FF);
			PRemarkKonsultNotNo->Color = clWhite;
		}else{
			PRemarkKonsultNotYes->Color = clWhite;
			PRemarkKonsultNotNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkKonsultLateYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkKonsultLateYes")->AsInteger){
			PRemarkKonsultLateYes->Color = TColor(0x0064B1FF);
			PRemarkKonsultLateNo->Color = clWhite;
		}else{
			PRemarkKonsultLateYes->Color = clWhite;
			PRemarkKonsultLateNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkDeseaseVerifYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseVerifYes")->AsInteger){
			PRemarkDeseaseVerifYes->Color = TColor(0x0064B1FF);
			PRemarkDeseaseVerifNo->Color = clWhite;
		}else{
			PRemarkDeseaseVerifYes->Color = clWhite;
			PRemarkDeseaseVerifNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkDeseaseTimeYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseTimeYes")->AsInteger){
			PRemarkDeseaseTimeYes->Color = TColor(0x0064B1FF);
			PRemarkDeseaseTimeNo->Color = clWhite;
		}else{
			PRemarkDeseaseTimeYes->Color = clWhite;
			PRemarkDeseaseTimeNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkDeseaseContentYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkDeseaseContentYes")->AsInteger){
			PRemarkDeseaseContentYes->Color = TColor(0x0064B1FF);
			PRemarkDeseaseContentNo->Color = clWhite;
		}else{
			PRemarkDeseaseContentYes->Color = clWhite;
			PRemarkDeseaseContentNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkTherapyChooseDrYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyChooseDrYes")->AsInteger){
			PRemarkTherapyChooseDrYes->Color = TColor(0x0064B1FF);
			PRemarkTherapyChooseDrNo->Color = clWhite;
		}else{
			PRemarkTherapyChooseDrYes->Color = clWhite;
			PRemarkTherapyChooseDrNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkTherapyTimeAppointmentYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyTimeAppointmentYes")->AsInteger){
			PRemarkTherapyTimeAppointmentYes->Color = TColor(0x0064B1FF);
			PRemarkTherapyTimeAppointmentNo->Color = clWhite;
		}else{
			PRemarkTherapyTimeAppointmentYes->Color = clWhite;
			PRemarkTherapyTimeAppointmentNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkTherapyPolypharmacyYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkTherapyPolypharmacyYes")->AsInteger){
			PRemarkTherapyPolypharmacyYes->Color = TColor(0x0064B1FF);
			PRemarkTherapyPolypharmacyNo->Color = clWhite;
		}else{
			PRemarkTherapyPolypharmacyYes->Color = clWhite;
			PRemarkTherapyPolypharmacyNo->Color = TColor(0x0064B1FF);
		}

		if(ContinuityChoosePlaceYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityChoosePlaceYes")->AsInteger){
			PContinuityChoosePlaceYes->Color = TColor(0x0064B1FF);
			PContinuityChoosePlaceNo->Color = clWhite;
		}else{
			PContinuityChoosePlaceYes->Color = clWhite;
			PContinuityChoosePlaceNo->Color = TColor(0x0064B1FF);
		}

		if(ContinuityTimeTransferYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ContinuityTimeTransferYes")->AsInteger){
			PContinuityTimeTransferYes->Color = TColor(0x0064B1FF);
			PContinuityTimeTransferNo->Color = clWhite;
		}else{
			PContinuityTimeTransferYes->Color = clWhite;
			PContinuityTimeTransferNo->Color = TColor(0x0064B1FF);
		}

		if(RemarkStandartMHYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RemarkStandartMHYes")->AsInteger){
			PRemarkStandartMHYes->Color = TColor(0x0064B1FF);
			PRemarkStandartMHNo->Color = clWhite;
		}else{
			PRemarkStandartMHYes->Color = clWhite;
			PRemarkStandartMHNo->Color = TColor(0x0064B1FF);
		}

		//for kkmp
		if(VuluntarMedAgreementYes = DMAvtoriz->DSInspection->DataSet->FieldByName("VuluntarMedAgreementYes")->AsInteger){
			PVuluntarMedAgreementYes->Color = TColor(0x0064B1FF);
			PVuluntarMedAgreementNo->Color = clWhite;
		}else{
			PVuluntarMedAgreementYes->Color = clWhite;
			PVuluntarMedAgreementNo->Color = TColor(0x0064B1FF);
		}

		if(AgreementPDNYes = DMAvtoriz->DSInspection->DataSet->FieldByName("AgreementPDNYes")->AsInteger){
			PAgreementPDNYes->Color = TColor(0x0064B1FF);
			PAgreementPDNNo->Color = clWhite;
		}else{
			PAgreementPDNYes->Color = clWhite;
			PAgreementPDNNo->Color = TColor(0x0064B1FF);
		}

		if(ComplitListDeseaseYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ComplitListDeseaseYes")->AsInteger){
			PComplitListDeseaseYes->Color = TColor(0x0064B1FF);
			PComplitListDeseaseNo->Color = clWhite;
		}else{
			PComplitListDeseaseYes->Color = clWhite;
			PComplitListDeseaseNo->Color = TColor(0x0064B1FF);
		}

		if(CompitListProfAndStatusYes = DMAvtoriz->DSInspection->DataSet->FieldByName("CompitListProfAndStatusYes")->AsInteger){
			PCompitListProfAndStatusYes->Color = TColor(0x0064B1FF);
			PCompitListProfAndStatusNo->Color = clWhite;
		}else{
			PCompitListProfAndStatusYes->Color = clWhite;
			PCompitListProfAndStatusNo->Color = TColor(0x0064B1FF);
		}

		if(ExistenceFLGYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ExistenceFLGYes")->AsInteger){
			PExistenceFLGYes->Color = TColor(0x0064B1FF);
			PExistenceFLGNo->Color = clWhite;
		}else{
			PExistenceFLGYes->Color = clWhite;
			PExistenceFLGNo->Color = TColor(0x0064B1FF);
		}

		if(ExistenceInspGinYes = DMAvtoriz->DSInspection->DataSet->FieldByName("ExistenceInspGinYes")->AsInteger){
			PExistenceInspGinYes->Color = TColor(0x0064B1FF);
			PExistenceInspGinNo->Color = clWhite;
		}else{
			PExistenceInspGinYes->Color = clWhite;
			PExistenceInspGinNo->Color = TColor(0x0064B1FF);
		}

		if(RationalUseOfResourcesYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RationalUseOfResourcesYes")->AsInteger){
			PRationalUseOfResourcesYes->Color = TColor(0x0064B1FF);
			PRationalUseOfResourcesNo->Color = clWhite;
		}else{
			PRationalUseOfResourcesYes->Color = clWhite;
			PRationalUseOfResourcesNo->Color = TColor(0x0064B1FF);
		}

		if(AbsenceComplaintsOfPatientsYes = DMAvtoriz->DSInspection->DataSet->FieldByName("AbsenceComplaintsOfPatientsYes")->AsInteger){
			PAbsenceComplaintsOfPatientsYes->Color = TColor(0x0064B1FF);
			PAbsenceComplaintsOfPatientsNo->Color = clWhite;
		}else{
			PAbsenceComplaintsOfPatientsYes->Color = clWhite;
			PAbsenceComplaintsOfPatientsNo->Color = TColor(0x0064B1FF);
		}

		if(TimelyRegistLNYes = DMAvtoriz->DSInspection->DataSet->FieldByName("TimelyRegistLNYes")->AsInteger){
			PTimelyRegistLNYes->Color = TColor(0x0064B1FF);
			PTimelyRegistLNNo->Color = clWhite;
		}else{
			PTimelyRegistLNYes->Color = clWhite;
			PTimelyRegistLNNo->Color = TColor(0x0064B1FF);
		}

		if(RefferalToVKYes = DMAvtoriz->DSInspection->DataSet->FieldByName("RefferalToVKYes")->AsInteger){
			PRefferalToVKYes->Color = TColor(0x0064B1FF);
			PRefferalToVKNo->Color = clWhite;
		}else{
			PRefferalToVKYes->Color = clWhite;
			PRefferalToVKNo->Color = TColor(0x0064B1FF);
		}

		switch(IntegrityCard = DMAvtoriz->DSInspection->DataSet->FieldByName("IntegrityCard")->AsInteger){
			case 1:
				PIntegrityCard1->Color = TColor(0x0064B1FF);
				PIntegrityCard2->Color = clWhite;
				PIntegrityCard3->Color = clWhite;
				PIntegrityCard4->Color = clWhite;
				PIntegrityCard5->Color = clWhite;
				break;
			case 2:
				PIntegrityCard1->Color = clWhite;
				PIntegrityCard2->Color = TColor(0x0064B1FF);
				PIntegrityCard3->Color = clWhite;
				PIntegrityCard4->Color = clWhite;
				PIntegrityCard5->Color = clWhite;
				break;
			case 3:
				PIntegrityCard1->Color = clWhite;
				PIntegrityCard2->Color = clWhite;
				PIntegrityCard3->Color = TColor(0x0064B1FF);
				PIntegrityCard4->Color = clWhite;
				PIntegrityCard5->Color = clWhite;
				break;
			case 4:
				PIntegrityCard1->Color = clWhite;
				PIntegrityCard2->Color = clWhite;
				PIntegrityCard3->Color = clWhite;
				PIntegrityCard4->Color = TColor(0x0064B1FF);
				PIntegrityCard5->Color = clWhite;
				break;
			case 5:
				PIntegrityCard1->Color = clWhite;
				PIntegrityCard2->Color = clWhite;
				PIntegrityCard3->Color = clWhite;
				PIntegrityCard4->Color = clWhite;
				PIntegrityCard5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(AccuracyHandwriting = DMAvtoriz->DSInspection->DataSet->FieldByName("AccuracyHandwriting")->AsInteger){
			case 1:
				PAccuracyHandwriting1->Color = TColor(0x0064B1FF);
				PAccuracyHandwriting2->Color = clWhite;
				PAccuracyHandwriting3->Color = clWhite;
				PAccuracyHandwriting4->Color = clWhite;
				PAccuracyHandwriting5->Color = clWhite;
				break;
			case 2:
				PAccuracyHandwriting1->Color = clWhite;
				PAccuracyHandwriting2->Color = TColor(0x0064B1FF);
				PAccuracyHandwriting3->Color = clWhite;
				PAccuracyHandwriting4->Color = clWhite;
				PAccuracyHandwriting5->Color = clWhite;
				break;
			case 3:
				PAccuracyHandwriting1->Color = clWhite;
				PAccuracyHandwriting2->Color = clWhite;
				PAccuracyHandwriting3->Color = TColor(0x0064B1FF);
				PAccuracyHandwriting4->Color = clWhite;
				PAccuracyHandwriting5->Color = clWhite;
				break;
			case 4:
				PAccuracyHandwriting1->Color = clWhite;
				PAccuracyHandwriting2->Color = clWhite;
				PAccuracyHandwriting3->Color = clWhite;
				PAccuracyHandwriting4->Color = TColor(0x0064B1FF);
				PAccuracyHandwriting5->Color = clWhite;
				break;
			case 5:
				PAccuracyHandwriting1->Color = clWhite;
				PAccuracyHandwriting2->Color = clWhite;
				PAccuracyHandwriting3->Color = clWhite;
				PAccuracyHandwriting4->Color = clWhite;
				PAccuracyHandwriting5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(QualityProfInsOnko = DMAvtoriz->DSInspection->DataSet->FieldByName("QualityProfInsOnko")->AsInteger){
			case 1:
				PQualityProfInsOnko1->Color = TColor(0x0064B1FF);
				PQualityProfInsOnko2->Color = clWhite;
				PQualityProfInsOnko3->Color = clWhite;
				PQualityProfInsOnko4->Color = clWhite;
				PQualityProfInsOnko5->Color = clWhite;
				break;
			case 2:
				PQualityProfInsOnko1->Color = clWhite;
				PQualityProfInsOnko2->Color = TColor(0x0064B1FF);
				PQualityProfInsOnko3->Color = clWhite;
				PQualityProfInsOnko4->Color = clWhite;
				PQualityProfInsOnko5->Color = clWhite;
				break;
			case 3:
				PQualityProfInsOnko1->Color = clWhite;
				PQualityProfInsOnko2->Color = clWhite;
				PQualityProfInsOnko3->Color = TColor(0x0064B1FF);
				PQualityProfInsOnko4->Color = clWhite;
				PQualityProfInsOnko5->Color = clWhite;
				break;
			case 4:
				PQualityProfInsOnko1->Color = clWhite;
				PQualityProfInsOnko2->Color = clWhite;
				PQualityProfInsOnko3->Color = clWhite;
				PQualityProfInsOnko4->Color = TColor(0x0064B1FF);
				PQualityProfInsOnko5->Color = clWhite;
				break;
			case 5:
				PQualityProfInsOnko1->Color = clWhite;
				PQualityProfInsOnko2->Color = clWhite;
				PQualityProfInsOnko3->Color = clWhite;
				PQualityProfInsOnko4->Color = clWhite;
				PQualityProfInsOnko5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(DispTimelines = DMAvtoriz->DSInspection->DataSet->FieldByName("DispTimelines")->AsInteger){
			case 1:
				PDispTimelines1->Color = TColor(0x0064B1FF);
				PDispTimelines2->Color = clWhite;
				PDispTimelines3->Color = clWhite;
				PDispTimelines4->Color = clWhite;
				PDispTimelines5->Color = clWhite;
				break;
			case 2:
				PDispTimelines1->Color = clWhite;
				PDispTimelines2->Color = TColor(0x0064B1FF);
				PDispTimelines3->Color = clWhite;
				PDispTimelines4->Color = clWhite;
				PDispTimelines5->Color = clWhite;
				break;
			case 3:
				PDispTimelines1->Color = clWhite;
				PDispTimelines2->Color = clWhite;
				PDispTimelines3->Color = TColor(0x0064B1FF);
				PDispTimelines4->Color = clWhite;
				PDispTimelines5->Color = clWhite;
				break;
			case 4:
				PDispTimelines1->Color = clWhite;
				PDispTimelines2->Color = clWhite;
				PDispTimelines3->Color = clWhite;
				PDispTimelines4->Color = TColor(0x0064B1FF);
				PDispTimelines5->Color = clWhite;
				break;
			case 5:
				PDispTimelines1->Color = clWhite;
				PDispTimelines2->Color = clWhite;
				PDispTimelines3->Color = clWhite;
				PDispTimelines4->Color = clWhite;
				PDispTimelines5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(QualityCollectAnamsis = DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectAnamsis")->AsInteger){
			case 1:
				PQualityCollectAnamsis1->Color = TColor(0x0064B1FF);
				PQualityCollectAnamsis2->Color = clWhite;
				PQualityCollectAnamsis3->Color = clWhite;
				PQualityCollectAnamsis4->Color = clWhite;
				PQualityCollectAnamsis5->Color = clWhite;
				break;
			case 2:
				PQualityCollectAnamsis1->Color = clWhite;
				PQualityCollectAnamsis2->Color = TColor(0x0064B1FF);
				PQualityCollectAnamsis3->Color = clWhite;
				PQualityCollectAnamsis4->Color = clWhite;
				PQualityCollectAnamsis5->Color = clWhite;
				break;
			case 3:
				PQualityCollectAnamsis1->Color = clWhite;
				PQualityCollectAnamsis2->Color = clWhite;
				PQualityCollectAnamsis3->Color = TColor(0x0064B1FF);
				PQualityCollectAnamsis4->Color = clWhite;
				PQualityCollectAnamsis5->Color = clWhite;
				break;
			case 4:
				PQualityCollectAnamsis1->Color = clWhite;
				PQualityCollectAnamsis2->Color = clWhite;
				PQualityCollectAnamsis3->Color = clWhite;
				PQualityCollectAnamsis4->Color = TColor(0x0064B1FF);
				PQualityCollectAnamsis5->Color = clWhite;
				break;
			case 5:
				PQualityCollectAnamsis1->Color = clWhite;
				PQualityCollectAnamsis2->Color = clWhite;
				PQualityCollectAnamsis3->Color = clWhite;
				PQualityCollectAnamsis4->Color = clWhite;
				PQualityCollectAnamsis5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(QualityCollectComplaint = DMAvtoriz->DSInspection->DataSet->FieldByName("QualityCollectComplaint")->AsInteger){
			case 1:
				PQualityCollectComplaint1->Color = TColor(0x0064B1FF);
				PQualityCollectComplaint2->Color = clWhite;
				PQualityCollectComplaint3->Color = clWhite;
				PQualityCollectComplaint4->Color = clWhite;
				PQualityCollectComplaint5->Color = clWhite;
				break;
			case 2:
				PQualityCollectComplaint1->Color = clWhite;
				PQualityCollectComplaint2->Color = TColor(0x0064B1FF);
				PQualityCollectComplaint3->Color = clWhite;
				PQualityCollectComplaint4->Color = clWhite;
				PQualityCollectComplaint5->Color = clWhite;
				break;
			case 3:
				PQualityCollectComplaint1->Color = clWhite;
				PQualityCollectComplaint2->Color = clWhite;
				PQualityCollectComplaint3->Color = TColor(0x0064B1FF);
				PQualityCollectComplaint4->Color = clWhite;
				PQualityCollectComplaint5->Color = clWhite;
				break;
			case 4:
				PQualityCollectComplaint1->Color = clWhite;
				PQualityCollectComplaint2->Color = clWhite;
				PQualityCollectComplaint3->Color = clWhite;
				PQualityCollectComplaint4->Color = TColor(0x0064B1FF);
				PQualityCollectComplaint5->Color = clWhite;
				break;
			case 5:
				PQualityCollectComplaint1->Color = clWhite;
				PQualityCollectComplaint2->Color = clWhite;
				PQualityCollectComplaint3->Color = clWhite;
				PQualityCollectComplaint4->Color = clWhite;
				PQualityCollectComplaint5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(DescriptObjectStatus = DMAvtoriz->DSInspection->DataSet->FieldByName("DescriptObjectStatus")->AsInteger){
			case 1:
				PDescriptObjectStatus1->Color = TColor(0x0064B1FF);
				PDescriptObjectStatus2->Color = clWhite;
				PDescriptObjectStatus3->Color = clWhite;
				PDescriptObjectStatus4->Color = clWhite;
				PDescriptObjectStatus5->Color = clWhite;
				break;
			case 2:
				PDescriptObjectStatus1->Color = clWhite;
				PDescriptObjectStatus2->Color = TColor(0x0064B1FF);
				PDescriptObjectStatus3->Color = clWhite;
				PDescriptObjectStatus4->Color = clWhite;
				PDescriptObjectStatus5->Color = clWhite;
				break;
			case 3:
				PDescriptObjectStatus1->Color = clWhite;
				PDescriptObjectStatus2->Color = clWhite;
				PDescriptObjectStatus3->Color = TColor(0x0064B1FF);
				PDescriptObjectStatus4->Color = clWhite;
				PDescriptObjectStatus5->Color = clWhite;
				break;
			case 4:
				PDescriptObjectStatus1->Color = clWhite;
				PDescriptObjectStatus2->Color = clWhite;
				PDescriptObjectStatus3->Color = clWhite;
				PDescriptObjectStatus4->Color = TColor(0x0064B1FF);
				PDescriptObjectStatus5->Color = clWhite;
				break;
			case 5:
				PDescriptObjectStatus1->Color = clWhite;
				PDescriptObjectStatus2->Color = clWhite;
				PDescriptObjectStatus3->Color = clWhite;
				PDescriptObjectStatus4->Color = clWhite;
				PDescriptObjectStatus5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(EvaluationResultsOfTreatment = DMAvtoriz->DSInspection->DataSet->FieldByName("EvaluationResultsOfTreatment")->AsInteger){
			case 1:
				PEvaluationResultsOfTreatment1->Color = TColor(0x0064B1FF);
				PEvaluationResultsOfTreatment2->Color = clWhite;
				PEvaluationResultsOfTreatment3->Color = clWhite;
				PEvaluationResultsOfTreatment4->Color = clWhite;
				PEvaluationResultsOfTreatment5->Color = clWhite;
				break;
			case 2:
				PEvaluationResultsOfTreatment1->Color = clWhite;
				PEvaluationResultsOfTreatment2->Color = TColor(0x0064B1FF);
				PEvaluationResultsOfTreatment3->Color = clWhite;
				PEvaluationResultsOfTreatment4->Color = clWhite;
				PEvaluationResultsOfTreatment5->Color = clWhite;
				break;
			case 3:
				PEvaluationResultsOfTreatment1->Color = clWhite;
				PEvaluationResultsOfTreatment2->Color = clWhite;
				PEvaluationResultsOfTreatment3->Color = TColor(0x0064B1FF);
				PEvaluationResultsOfTreatment4->Color = clWhite;
				PEvaluationResultsOfTreatment5->Color = clWhite;
				break;
			case 4:
				PEvaluationResultsOfTreatment1->Color = clWhite;
				PEvaluationResultsOfTreatment2->Color = clWhite;
				PEvaluationResultsOfTreatment3->Color = clWhite;
				PEvaluationResultsOfTreatment4->Color = TColor(0x0064B1FF);
				PEvaluationResultsOfTreatment5->Color = clWhite;
				break;
			case 5:
				PEvaluationResultsOfTreatment1->Color = clWhite;
				PEvaluationResultsOfTreatment2->Color = clWhite;
				PEvaluationResultsOfTreatment3->Color = clWhite;
				PEvaluationResultsOfTreatment4->Color = clWhite;
				PEvaluationResultsOfTreatment5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(ObservStandartsOfDiagnostics = DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfDiagnostics")->AsInteger){
			case 1:
				PObservStandartsOfDiagnostics1->Color = TColor(0x0064B1FF);
				PObservStandartsOfDiagnostics2->Color = clWhite;
				PObservStandartsOfDiagnostics3->Color = clWhite;
				PObservStandartsOfDiagnostics4->Color = clWhite;
				PObservStandartsOfDiagnostics5->Color = clWhite;
				break;
			case 2:
				PObservStandartsOfDiagnostics1->Color = clWhite;
				PObservStandartsOfDiagnostics2->Color = TColor(0x0064B1FF);
				PObservStandartsOfDiagnostics3->Color = clWhite;
				PObservStandartsOfDiagnostics4->Color = clWhite;
				PObservStandartsOfDiagnostics5->Color = clWhite;
				break;
			case 3:
				PObservStandartsOfDiagnostics1->Color = clWhite;
				PObservStandartsOfDiagnostics2->Color = clWhite;
				PObservStandartsOfDiagnostics3->Color = TColor(0x0064B1FF);
				PObservStandartsOfDiagnostics4->Color = clWhite;
				PObservStandartsOfDiagnostics5->Color = clWhite;
				break;
			case 4:
				PObservStandartsOfDiagnostics1->Color = clWhite;
				PObservStandartsOfDiagnostics2->Color = clWhite;
				PObservStandartsOfDiagnostics3->Color = clWhite;
				PObservStandartsOfDiagnostics4->Color = TColor(0x0064B1FF);
				PObservStandartsOfDiagnostics5->Color = clWhite;
				break;
			case 5:
				PObservStandartsOfDiagnostics1->Color = clWhite;
				PObservStandartsOfDiagnostics2->Color = clWhite;
				PObservStandartsOfDiagnostics3->Color = clWhite;
				PObservStandartsOfDiagnostics4->Color = clWhite;
				PObservStandartsOfDiagnostics5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(ObservStandartsOfTreatment = DMAvtoriz->DSInspection->DataSet->FieldByName("ObservStandartsOfTreatment")->AsInteger){
			case 1:
				PObservStandartsOfTreatment1->Color = TColor(0x0064B1FF);
				PObservStandartsOfTreatment2->Color = clWhite;
				PObservStandartsOfTreatment3->Color = clWhite;
				PObservStandartsOfTreatment4->Color = clWhite;
				PObservStandartsOfTreatment5->Color = clWhite;
				break;
			case 2:
				PObservStandartsOfTreatment1->Color = clWhite;
				PObservStandartsOfTreatment2->Color = TColor(0x0064B1FF);
				PObservStandartsOfTreatment3->Color = clWhite;
				PObservStandartsOfTreatment4->Color = clWhite;
				PObservStandartsOfTreatment5->Color = clWhite;
				break;
			case 3:
				PObservStandartsOfTreatment1->Color = clWhite;
				PObservStandartsOfTreatment2->Color = clWhite;
				PObservStandartsOfTreatment3->Color = TColor(0x0064B1FF);
				PObservStandartsOfTreatment4->Color = clWhite;
				PObservStandartsOfTreatment5->Color = clWhite;
				break;
			case 4:
				PObservStandartsOfTreatment1->Color = clWhite;
				PObservStandartsOfTreatment2->Color = clWhite;
				PObservStandartsOfTreatment3->Color = clWhite;
				PObservStandartsOfTreatment4->Color = TColor(0x0064B1FF);
				PObservStandartsOfTreatment5->Color = clWhite;
				break;
			case 5:
				PObservStandartsOfTreatment1->Color = clWhite;
				PObservStandartsOfTreatment2->Color = clWhite;
				PObservStandartsOfTreatment3->Color = clWhite;
				PObservStandartsOfTreatment4->Color = clWhite;
				PObservStandartsOfTreatment5->Color = TColor(0x0064B1FF);
				break;
		}

		switch(DeadlinesVN = DMAvtoriz->DSInspection->DataSet->FieldByName("DeadlinesVN")->AsInteger){
        	case 1:
				PDeadlinesVN1->Color = TColor(0x0064B1FF);
				PDeadlinesVN2->Color = clWhite;
				PDeadlinesVN3->Color = clWhite;
				PDeadlinesVN4->Color = clWhite;
				PDeadlinesVN5->Color = clWhite;
				break;
			case 2:
				PDeadlinesVN1->Color = clWhite;
				PDeadlinesVN2->Color = TColor(0x0064B1FF);
				PDeadlinesVN3->Color = clWhite;
				PDeadlinesVN4->Color = clWhite;
				PDeadlinesVN5->Color = clWhite;
				break;
			case 3:
				PDeadlinesVN1->Color = clWhite;
				PDeadlinesVN2->Color = clWhite;
				PDeadlinesVN3->Color = TColor(0x0064B1FF);
				PDeadlinesVN4->Color = clWhite;
				PDeadlinesVN5->Color = clWhite;
				break;
			case 4:
				PDeadlinesVN1->Color = clWhite;
				PDeadlinesVN2->Color = clWhite;
				PDeadlinesVN3->Color = clWhite;
				PDeadlinesVN4->Color = TColor(0x0064B1FF);
				PDeadlinesVN5->Color = clWhite;
				break;
			case 5:
				PDeadlinesVN1->Color = clWhite;
				PDeadlinesVN2->Color = clWhite;
				PDeadlinesVN3->Color = clWhite;
				PDeadlinesVN4->Color = clWhite;
				PDeadlinesVN5->Color = TColor(0x0064B1FF);
				break;
		}
		getKvo();
		getKkmp();
	}else{
		DTPDateStart->Date = Now();
		DTPDateEnd->Date = Now();
		DBLookupComboBoxListMed->KeyValue = 1;
		//SpBAllNoClick(Sender);
		getKvo();
		getKkmp();
		//SpBAllNoQualityClick(Sender);
	}

	PAmountOfDays->Caption = IntToStr((DTPDateEnd->DateTime - DTPDateStart->DateTime) + 1);
	DMAvtoriz->SQLQGetListMed->Open();
	DMAvtoriz->CDSGetListMed->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwriting1Click(TObject *Sender)
{
	PAccuracyHandwriting1->Color = TColor(0x0064B1FF);
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting4->Color = clWhite;
	PAccuracyHandwriting5->Color = clWhite;
	AccuracyHandwriting = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwriting2Click(TObject *Sender)
{
	PAccuracyHandwriting1->Color = clWhite;
	PAccuracyHandwriting2->Color = TColor(0x0064B1FF);
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting4->Color = clWhite;
	PAccuracyHandwriting5->Color = clWhite;
	AccuracyHandwriting = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwriting3Click(TObject *Sender)
{
	PAccuracyHandwriting1->Color = clWhite;
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting3->Color = TColor(0x0064B1FF);
	PAccuracyHandwriting4->Color = clWhite;
	PAccuracyHandwriting5->Color = clWhite;
	AccuracyHandwriting = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwriting4Click(TObject *Sender)
{
	PAccuracyHandwriting1->Color = clWhite;
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting4->Color = TColor(0x0064B1FF);
	PAccuracyHandwriting5->Color = clWhite;
	AccuracyHandwriting = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwriting5Click(TObject *Sender)
{
	PAccuracyHandwriting1->Color = clWhite;
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting4->Color = clWhite;
	PAccuracyHandwriting5->Color = TColor(0x0064B1FF);
	AccuracyHandwriting = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::SpBAllNoQualityClick(TObject *Sender)
{
	PVuluntarMedAgreementYes->Color = TColor(0x0064B1FF);
	PAgreementPDNYes->Color = TColor(0x0064B1FF);
	PComplitListDeseaseYes->Color = TColor(0x0064B1FF);
	PCompitListProfAndStatusYes->Color = TColor(0x0064B1FF);
	PIntegrityCard5->Color = TColor(0x0064B1FF);
	PAccuracyHandwriting5->Color = TColor(0x0064B1FF);
	PExistenceFLGYes->Color = TColor(0x0064B1FF);
	PExistenceInspGinYes->Color = TColor(0x0064B1FF);
	PQualityProfInsOnko5->Color = TColor(0x0064B1FF);
	PDispTimelines5->Color = TColor(0x0064B1FF);
	PQualityCollectAnamsis5->Color = TColor(0x0064B1FF);
	PQualityCollectComplaint5->Color = TColor(0x0064B1FF);
	PDescriptObjectStatus5->Color = TColor(0x0064B1FF);
	PEvaluationResultsOfTreatment5->Color = TColor(0x0064B1FF);
	PObservStandartsOfDiagnostics5->Color = TColor(0x0064B1FF);
	PObservStandartsOfTreatment5->Color = TColor(0x0064B1FF);
	PRationalUseOfResourcesYes->Color = TColor(0x0064B1FF);
	PAbsenceComplaintsOfPatientsYes->Color = TColor(0x0064B1FF);
	PDeadlinesVN5->Color = TColor(0x0064B1FF);
	PTimelyRegistLNYes->Color = TColor(0x0064B1FF);
	PRefferalToVKYes->Color = TColor(0x0064B1FF);


	PVuluntarMedAgreementNo->Color = clWhite;
	PAgreementPDNNo->Color = clWhite;
	PComplitListDeseaseNo->Color = clWhite;
	PCompitListProfAndStatusNo->Color = clWhite;
	PIntegrityCard1->Color = clWhite;
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard4->Color = clWhite;
	PAccuracyHandwriting1->Color = clWhite;
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting4->Color = clWhite;
	PExistenceFLGNo->Color = clWhite;
	PExistenceInspGinNo->Color = clWhite;
	PQualityProfInsOnko1->Color = clWhite;
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko4->Color = clWhite;
	PDispTimelines1->Color = clWhite;
	PDispTimelines2->Color = clWhite;
	PDispTimelines3->Color = clWhite;
	PDispTimelines4->Color = clWhite;
	PQualityCollectAnamsis1->Color = clWhite;
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectComplaint1->Color = clWhite;
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint4->Color = clWhite;
	PDescriptObjectStatus1->Color = clWhite;
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus4->Color = clWhite;
	PEvaluationResultsOfTreatment1->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PObservStandartsOfDiagnostics1->Color = clWhite;
	PObservStandartsOfDiagnostics2->Color = clWhite;
	PObservStandartsOfDiagnostics3->Color = clWhite;
	PObservStandartsOfDiagnostics4->Color = clWhite;
	PObservStandartsOfTreatment1->Color = clWhite;
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment4->Color = clWhite;
	PRationalUseOfResourcesNo->Color = clWhite;
	PAbsenceComplaintsOfPatientsNo->Color = clWhite;
	PDeadlinesVN1->Color = clWhite;
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN4->Color = clWhite;
	PTimelyRegistLNNo->Color = clWhite;
	PRefferalToVKNo->Color = clWhite;

	VuluntarMedAgreementYes = 5;
	AgreementPDNYes = 5;
	ComplitListDeseaseYes = 5;
	CompitListProfAndStatusYes = 5;
	ExistenceFLGYes = 5;
	ExistenceInspGinYes = 5;
	RationalUseOfResourcesYes = 5;
	AbsenceComplaintsOfPatientsYes = 5;
	TimelyRegistLNYes = 5;
	RefferalToVKYes = 5;

    IntegrityCard = 5;
	AccuracyHandwriting = 5;
	QualityProfInsOnko = 5;
	DispTimelines = 5;
	QualityCollectAnamsis = 5;
	QualityCollectComplaint = 5;
	DescriptObjectStatus = 5;
	EvaluationResultsOfTreatment = 5;
	ObservStandartsOfDiagnostics = 5;
	ObservStandartsOfTreatment = 5;
	DeadlinesVN = 5;

	getKkmp();
}
//---------------------------------------------------------------------------



void __fastcall TFCard::PExistenceFLGYesClick(TObject *Sender)
{
	PExistenceFLGYes->Color = TColor(0x0064B1FF);
	PExistenceFLGNo->Color = clWhite;
	ExistenceFLGYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceFLGNoClick(TObject *Sender)
{
	PExistenceFLGYes->Color = clWhite;
	PExistenceFLGNo->Color = TColor(0x0064B1FF);
	ExistenceFLGYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceInspGinYesClick(TObject *Sender)
{
	PExistenceInspGinYes->Color = TColor(0x0064B1FF);
	PExistenceInspGinNo->Color = clWhite;
	ExistenceInspGinYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceInspGinNoClick(TObject *Sender)
{
	PExistenceInspGinYes->Color = clWhite;
	PExistenceInspGinNo->Color = TColor(0x0064B1FF);
	ExistenceInspGinYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnko5Click(TObject *Sender)
{
	PQualityProfInsOnko1->Color = clWhite;
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko4->Color = clWhite;
	PQualityProfInsOnko5->Color = TColor(0x0064B1FF);
	QualityProfInsOnko = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnko4Click(TObject *Sender)
{
	PQualityProfInsOnko1->Color = clWhite;
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko4->Color = TColor(0x0064B1FF);
	PQualityProfInsOnko5->Color = clWhite;
	QualityProfInsOnko = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnko3Click(TObject *Sender)
{
	PQualityProfInsOnko1->Color = clWhite;
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko3->Color = TColor(0x0064B1FF);
	PQualityProfInsOnko4->Color = clWhite;
	PQualityProfInsOnko5->Color = clWhite;
	QualityProfInsOnko = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnko2Click(TObject *Sender)
{
	PQualityProfInsOnko1->Color = clWhite;
	PQualityProfInsOnko2->Color = TColor(0x0064B1FF);
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko4->Color = clWhite;
	PQualityProfInsOnko5->Color = clWhite;
	QualityProfInsOnko = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnko1Click(TObject *Sender)
{
	PQualityProfInsOnko1->Color = TColor(0x0064B1FF);
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko4->Color = clWhite;
	PQualityProfInsOnko5->Color = clWhite;
	QualityProfInsOnko = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelines5Click(TObject *Sender)
{
	PDispTimelines1->Color = clWhite;
	PDispTimelines2->Color = clWhite;
	PDispTimelines3->Color = clWhite;
	PDispTimelines4->Color = clWhite;
	PDispTimelines5->Color = TColor(0x0064B1FF);
	DispTimelines = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelines4Click(TObject *Sender)
{
	PDispTimelines1->Color = clWhite;
	PDispTimelines2->Color = clWhite;
	PDispTimelines3->Color = clWhite;
	PDispTimelines4->Color = TColor(0x0064B1FF);
	PDispTimelines5->Color = clWhite;
	DispTimelines = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelines3Click(TObject *Sender)
{
	PDispTimelines1->Color = clWhite;
	PDispTimelines2->Color = clWhite;
	PDispTimelines3->Color = TColor(0x0064B1FF);
	PDispTimelines4->Color = clWhite;
	PDispTimelines5->Color = clWhite;
	DispTimelines = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelines2Click(TObject *Sender)
{
	PDispTimelines1->Color = clWhite;
	PDispTimelines2->Color = TColor(0x0064B1FF);
	PDispTimelines3->Color = clWhite;
	PDispTimelines4->Color = clWhite;
	PDispTimelines5->Color = clWhite;
	DispTimelines = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelines1Click(TObject *Sender)
{
	PDispTimelines1->Color = TColor(0x0064B1FF);
	PDispTimelines2->Color = clWhite;
	PDispTimelines3->Color = clWhite;
	PDispTimelines4->Color = clWhite;
	PDispTimelines5->Color = clWhite;
	DispTimelines = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsis5Click(TObject *Sender)
{
	PQualityCollectAnamsis1->Color = clWhite;
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectAnamsis5->Color = TColor(0x0064B1FF);
	QualityCollectAnamsis = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsis4Click(TObject *Sender)
{
	PQualityCollectAnamsis1->Color = clWhite;
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis4->Color = TColor(0x0064B1FF);
	PQualityCollectAnamsis5->Color = clWhite;
	QualityCollectAnamsis = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsis3Click(TObject *Sender)
{
	PQualityCollectAnamsis1->Color = clWhite;
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis3->Color = TColor(0x0064B1FF);
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectAnamsis5->Color = clWhite;
	QualityCollectAnamsis = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsis2Click(TObject *Sender)
{
	PQualityCollectAnamsis1->Color = clWhite;
	PQualityCollectAnamsis2->Color = TColor(0x0064B1FF);
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectAnamsis5->Color = clWhite;
	QualityCollectAnamsis = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsis1Click(TObject *Sender)
{
	PQualityCollectAnamsis1->Color = TColor(0x0064B1FF);
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectAnamsis5->Color = clWhite;
	QualityCollectAnamsis = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaint5Click(TObject *Sender)
{
	PQualityCollectComplaint1->Color = clWhite;
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint4->Color = clWhite;
	PQualityCollectComplaint5->Color = TColor(0x0064B1FF);
	QualityCollectComplaint = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaint4Click(TObject *Sender)
{
	PQualityCollectComplaint1->Color = clWhite;
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint4->Color = TColor(0x0064B1FF);
	PQualityCollectComplaint5->Color = clWhite;
	QualityCollectComplaint = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaint3Click(TObject *Sender)
{
	PQualityCollectComplaint1->Color = clWhite;
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint3->Color = TColor(0x0064B1FF);
	PQualityCollectComplaint4->Color = clWhite;
	PQualityCollectComplaint5->Color = clWhite;
	QualityCollectComplaint = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaint2Click(TObject *Sender)
{
	PQualityCollectComplaint1->Color = clWhite;
	PQualityCollectComplaint2->Color = TColor(0x0064B1FF);
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint4->Color = clWhite;
	PQualityCollectComplaint5->Color = clWhite;
	QualityCollectComplaint = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaint1Click(TObject *Sender)
{
	PQualityCollectComplaint1->Color = TColor(0x0064B1FF);
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint4->Color = clWhite;
	PQualityCollectComplaint5->Color = clWhite;
	QualityCollectComplaint = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatus5Click(TObject *Sender)
{
	PDescriptObjectStatus1->Color = clWhite;
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus4->Color = clWhite;
	PDescriptObjectStatus5->Color = TColor(0x0064B1FF);
	DescriptObjectStatus = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatus4Click(TObject *Sender)
{
	PDescriptObjectStatus1->Color = clWhite;
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus4->Color = TColor(0x0064B1FF);
	PDescriptObjectStatus5->Color = clWhite;
	DescriptObjectStatus = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatus3Click(TObject *Sender)
{
	PDescriptObjectStatus1->Color = clWhite;
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus3->Color = TColor(0x0064B1FF);
	PDescriptObjectStatus4->Color = clWhite;
	PDescriptObjectStatus5->Color = clWhite;
	DescriptObjectStatus = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatus2Click(TObject *Sender)
{
	PDescriptObjectStatus1->Color = clWhite;
	PDescriptObjectStatus2->Color = TColor(0x0064B1FF);
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus4->Color = clWhite;
	PDescriptObjectStatus5->Color = clWhite;
	DescriptObjectStatus = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatus1Click(TObject *Sender)
{
	PDescriptObjectStatus1->Color = TColor(0x0064B1FF);
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus4->Color = clWhite;
	PDescriptObjectStatus5->Color = clWhite;
	DescriptObjectStatus = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatment5Click(TObject *Sender)
{
	PEvaluationResultsOfTreatment1->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PEvaluationResultsOfTreatment5->Color = TColor(0x0064B1FF);
	EvaluationResultsOfTreatment = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatment4Click(TObject *Sender)
{
  	PEvaluationResultsOfTreatment1->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = TColor(0x0064B1FF);
	PEvaluationResultsOfTreatment5->Color = clWhite;
	EvaluationResultsOfTreatment = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatment3Click(TObject *Sender)
{
	PEvaluationResultsOfTreatment1->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = TColor(0x0064B1FF);
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PEvaluationResultsOfTreatment5->Color = clWhite;
	EvaluationResultsOfTreatment = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatment2Click(TObject *Sender)
{
	PEvaluationResultsOfTreatment1->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = TColor(0x0064B1FF);
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PEvaluationResultsOfTreatment5->Color = clWhite;
	EvaluationResultsOfTreatment = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatment1Click(TObject *Sender)
{
	PEvaluationResultsOfTreatment1->Color = TColor(0x0064B1FF);
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PEvaluationResultsOfTreatment5->Color = clWhite;
	EvaluationResultsOfTreatment = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnostics5Click(TObject *Sender)
{
	PObservStandartsOfDiagnostics1->Color = clWhite;
	PObservStandartsOfDiagnostics2->Color = clWhite;
	PObservStandartsOfDiagnostics3->Color = clWhite;
	PObservStandartsOfDiagnostics4->Color = clWhite;
	PObservStandartsOfDiagnostics5->Color = TColor(0x0064B1FF);
	ObservStandartsOfDiagnostics = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnostics4Click(TObject *Sender)
{
	PObservStandartsOfDiagnostics1->Color = clWhite;
	PObservStandartsOfDiagnostics2->Color = clWhite;
	PObservStandartsOfDiagnostics3->Color = clWhite;
	PObservStandartsOfDiagnostics4->Color = TColor(0x0064B1FF);
	PObservStandartsOfDiagnostics5->Color = clWhite;
	ObservStandartsOfDiagnostics = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnostics3Click(TObject *Sender)
{
	PObservStandartsOfDiagnostics1->Color = clWhite;
	PObservStandartsOfDiagnostics2->Color = clWhite;
	PObservStandartsOfDiagnostics3->Color = TColor(0x0064B1FF);
	PObservStandartsOfDiagnostics4->Color = clWhite;
	PObservStandartsOfDiagnostics5->Color = clWhite;
	ObservStandartsOfDiagnostics = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnostics2Click(TObject *Sender)
{
	PObservStandartsOfDiagnostics1->Color = clWhite;
	PObservStandartsOfDiagnostics2->Color = TColor(0x0064B1FF);
	PObservStandartsOfDiagnostics3->Color = clWhite;
	PObservStandartsOfDiagnostics4->Color = clWhite;
	PObservStandartsOfDiagnostics5->Color = clWhite;
	ObservStandartsOfDiagnostics = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnostics1Click(TObject *Sender)
{
	PObservStandartsOfDiagnostics1->Color = TColor(0x0064B1FF);
	PObservStandartsOfDiagnostics2->Color = clWhite;
	PObservStandartsOfDiagnostics3->Color = clWhite;
	PObservStandartsOfDiagnostics4->Color = clWhite;
	PObservStandartsOfDiagnostics5->Color = clWhite;
	ObservStandartsOfDiagnostics = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatment5Click(TObject *Sender)
{
	PObservStandartsOfTreatment1->Color = clWhite;
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment4->Color = clWhite;
	PObservStandartsOfTreatment5->Color = TColor(0x0064B1FF);
	ObservStandartsOfTreatment = 5;
	getKkmp();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PDeadlinesVN5Click(TObject *Sender)
{
	PDeadlinesVN1->Color = clWhite;
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN4->Color = clWhite;
	PDeadlinesVN5->Color = TColor(0x0064B1FF);
	DeadlinesVN = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDeadlinesVN4Click(TObject *Sender)
{
	PDeadlinesVN1->Color = clWhite;
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN4->Color = TColor(0x0064B1FF);
	PDeadlinesVN5->Color = clWhite;
	DeadlinesVN = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDeadlinesVN3Click(TObject *Sender)
{
	PDeadlinesVN1->Color = clWhite;
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN3->Color = TColor(0x0064B1FF);
	PDeadlinesVN4->Color = clWhite;
	PDeadlinesVN5->Color = clWhite;
	DeadlinesVN = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDeadlinesVN2Click(TObject *Sender)
{
	PDeadlinesVN1->Color = clWhite;
	PDeadlinesVN2->Color = TColor(0x0064B1FF);
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN4->Color = clWhite;
	PDeadlinesVN5->Color = clWhite;
	DeadlinesVN = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDeadlinesVN1Click(TObject *Sender)
{
	PDeadlinesVN1->Color = TColor(0x0064B1FF);
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN4->Color = clWhite;
	PDeadlinesVN5->Color = clWhite;
	DeadlinesVN = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatment4Click(TObject *Sender)
{
	PObservStandartsOfTreatment1->Color = clWhite;
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment4->Color = TColor(0x0064B1FF);
	PObservStandartsOfTreatment5->Color = clWhite;
	ObservStandartsOfTreatment = 4;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatment3Click(TObject *Sender)
{
	PObservStandartsOfTreatment1->Color = clWhite;
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment3->Color = TColor(0x0064B1FF);
	PObservStandartsOfTreatment4->Color = clWhite;
	PObservStandartsOfTreatment5->Color = clWhite;
	ObservStandartsOfTreatment = 3;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatment2Click(TObject *Sender)
{
	PObservStandartsOfTreatment1->Color = clWhite;
	PObservStandartsOfTreatment2->Color = TColor(0x0064B1FF);
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment4->Color = clWhite;
	PObservStandartsOfTreatment5->Color = clWhite;
	ObservStandartsOfTreatment = 2;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatment1Click(TObject *Sender)
{
	PObservStandartsOfTreatment1->Color = TColor(0x0064B1FF);
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment4->Color = clWhite;
	PObservStandartsOfTreatment5->Color = clWhite;
	ObservStandartsOfTreatment = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRationalUseOfResourcesYesClick(TObject *Sender)
{
	PRationalUseOfResourcesYes->Color = TColor(0x0064B1FF);
	PRationalUseOfResourcesNo->Color = clWhite;
	RationalUseOfResourcesYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRationalUseOfResourcesNoClick(TObject *Sender)
{
	PRationalUseOfResourcesYes->Color = clWhite;
	PRationalUseOfResourcesNo->Color = TColor(0x0064B1FF);
	RationalUseOfResourcesYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAbsenceComplaintsOfPatientsYesClick(TObject *Sender)
{
	PAbsenceComplaintsOfPatientsYes->Color = TColor(0x0064B1FF);
	PAbsenceComplaintsOfPatientsNo->Color = clWhite;
	AbsenceComplaintsOfPatientsYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAbsenceComplaintsOfPatientsNoClick(TObject *Sender)
{
	PAbsenceComplaintsOfPatientsYes->Color = clWhite;
	PAbsenceComplaintsOfPatientsNo->Color = TColor(0x0064B1FF);
	AbsenceComplaintsOfPatientsYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::DTPDateStartCloseUp(TObject *Sender)
{
	PAmountOfDays->Caption = IntToStr((DTPDateEnd->DateTime - DTPDateStart->DateTime) + 1);
}
//---------------------------------------------------------------------------

void __fastcall TFCard::DTPDateEndCloseUp(TObject *Sender)
{
	PAmountOfDays->Caption = IntToStr((DTPDateEnd->DateTime - DTPDateStart->DateTime) + 1);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::Button1Click(TObject *Sender)
{
	if(DBLookupComboBoxListMed->KeyValue < 2){
		MessageBox(0,L"�� ������ ����, ����������� ������!",L"������",MB_OK);
		return;
	}

	if(ESurname->Text.IsEmpty()){
		MessageBox(0,L"�� ������� ������� ��������!",L"������",MB_OK);
		ESurname->SetFocus();
		return;
	}

	if(EName->Text.IsEmpty()){
		MessageBox(0,L"�� ������� ��� ��������!",L"������",MB_OK);
		EName->SetFocus();
		return;
	}

	if(EYearOfBirthday->Text.IsEmpty()){
		MessageBox(0,L"�� ������ ��� �������� ��������!",L"������",MB_OK);
		EYearOfBirthday->SetFocus();
		return;
	}

	if(EArea->Text.IsEmpty()){
		MessageBox(0,L"�� ������ ������� ��� ��������!",L"������",MB_OK);
		EArea->SetFocus();
		return;
	}

	DMAvtoriz->SQLQCard->Close();

	if(id_inspection != NULL){
		//UPDATE
		DMAvtoriz->SQLQCard->SQL->Text =
			"UPDATE `inspection` SET "
			"`date_start` = '"+FormatDateTime("yyyy-mm-dd",DTPDateStart->Date)+"',"
			"`date_end` = '"+FormatDateTime("yyyy-mm-dd",DTPDateEnd->Date)+"',"
			"`duration` = '"+PAmountOfDays->Caption+"',"
			"`surname` = '"+ESurname->Text+"',"
			"`name` = '"+EName->Text+"',"
			"`patronymic` = '"+EPatronymic->Text+"',"
			"`year_date_birthday` = '"+EYearOfBirthday->Text+"',"
			"`area` = '"+EArea->Text+"',"
			"`id_user` = '"+DBLookupComboBoxListMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+"',"
			"`RemarkInfServYes` = '"+IntToStr(RemarkInfServYes)+"',"
			"`RemarkAnamYes` = '"+IntToStr(RemarkAnamYes)+"',"
			"`RemarkFizResYes` = '"+IntToStr(RemarkFizResYes)+"',"
			"`ResearchNotYes` = '"+IntToStr(ResearchNotYes)+"',"
			"`ResearchToMuchYes` = '"+IntToStr(ResearchToMuchYes)+"',"
			"`ResearchLateYes` = '"+IntToStr(ResearchLateYes)+"',"
			"`ResearchInstrNotYes` = '"+IntToStr(ResearchInstrNotYes)+"',"
			"`ResearchInstrToMuchYes` = '"+IntToStr(ResearchInstrToMuchYes)+"',"
			"`ResearchInstrLateYes` = '"+IntToStr(ResearchInstrLateYes)+"',"
			"`RemarkKonsultNotYes` = '"+IntToStr(RemarkKonsultNotYes)+"',"
			"`RemarkKonsultLateYes` = '"+IntToStr(RemarkKonsultLateYes)+"',"
			"`RemarkDeseaseVerifYes` = '"+IntToStr(RemarkDeseaseVerifYes)+"',"
			"`RemarkDeseaseTimeYes` = '"+IntToStr(RemarkDeseaseTimeYes)+"',"
			"`RemarkDeseaseContentYes` = '"+IntToStr(RemarkDeseaseContentYes)+"',"
			"`RemarkTherapyChooseDrYes` = '"+IntToStr(RemarkTherapyChooseDrYes)+"',"
			"`RemarkTherapyTimeAppointmentYes` = '"+IntToStr(RemarkTherapyTimeAppointmentYes)+"',"
			"`RemarkTherapyPolypharmacyYes` = '"+IntToStr(RemarkTherapyPolypharmacyYes)+"',"
			"`ContinuityChoosePlaceYes` = '"+IntToStr(ContinuityChoosePlaceYes)+"',"
			"`ContinuityTimeTransferYes` = '"+IntToStr(ContinuityTimeTransferYes)+"',"
			"`RemarkStandartMHYes` = '"+IntToStr(RemarkStandartMHYes)+"',"
			"`VuluntarMedAgreementYes` = '"+IntToStr(VuluntarMedAgreementYes)+"',"
			"`AgreementPDNYes` = '"+IntToStr(AgreementPDNYes)+"',"
			"`ComplitListDeseaseYes` = '"+IntToStr(ComplitListDeseaseYes)+"',"
			"`CompitListProfAndStatusYes` = '"+IntToStr(CompitListProfAndStatusYes)+"',"
			"`ExistenceFLGYes` = '"+IntToStr(ExistenceFLGYes)+"',"
			"`ExistenceInspGinYes` = '"+IntToStr(ExistenceInspGinYes)+"',"
			"`RationalUseOfResourcesYes` = '"+IntToStr(RationalUseOfResourcesYes)+"',"
			"`AbsenceComplaintsOfPatientsYes` = '"+IntToStr(AbsenceComplaintsOfPatientsYes)+"',"
			"`TimelyRegistLNYes` = '"+IntToStr(TimelyRegistLNYes)+"',"
			"`RefferalToVKYes` = '"+IntToStr(RefferalToVKYes)+"',"
			"`IntegrityCard` = '"+IntToStr(IntegrityCard)+"',"
			"`AccuracyHandwriting` = '"+IntToStr(AccuracyHandwriting)+"',"
			"`QualityProfInsOnko` = '"+IntToStr(QualityProfInsOnko)+"',"
			"`DispTimelines` = '"+IntToStr(DispTimelines)+"',"
			"`QualityCollectAnamsis` = '"+IntToStr(QualityCollectAnamsis)+"',"
			"`QualityCollectComplaint` = '"+IntToStr(QualityCollectComplaint)+"',"
			"`DescriptObjectStatus` = '"+IntToStr(DescriptObjectStatus)+"',"
			"`EvaluationResultsOfTreatment` = '"+IntToStr(EvaluationResultsOfTreatment)+"',"
			"`ObservStandartsOfDiagnostics` = '"+IntToStr(ObservStandartsOfDiagnostics)+"',"
			"`ObservStandartsOfTreatment` = '"+IntToStr(ObservStandartsOfTreatment)+"',"
			"`DeadlinesVN` = '"+IntToStr(DeadlinesVN)+"',"
			"`kkmp` = '"+PKKMP->Caption+"',"
			"`kvo` = '"+FloatToStr(kvo)+"' "
			"WHERE `id_inspection` = " + IntToStr(id_inspection);
	}else{
		//INSERT
		DMAvtoriz->SQLQCard->SQL->Text = "INSERT INTO `inspection` "
		"(date_start,date_end,duration,surname,name,patronymic,year_date_birthday,area,id_user,"
		"RemarkInfServYes,RemarkAnamYes,RemarkFizResYes,ResearchNotYes,ResearchToMuchYes,"
		"ResearchLateYes,ResearchInstrNotYes,ResearchInstrToMuchYes,ResearchInstrLateYes,"
		"RemarkKonsultNotYes,RemarkKonsultLateYes,RemarkDeseaseVerifYes,RemarkDeseaseTimeYes,"
		"RemarkDeseaseContentYes,RemarkTherapyChooseDrYes,RemarkTherapyTimeAppointmentYes,"
		"RemarkTherapyPolypharmacyYes,ContinuityChoosePlaceYes,ContinuityTimeTransferYes,"
		"RemarkStandartMHYes,VuluntarMedAgreementYes,AgreementPDNYes,ComplitListDeseaseYes,"
		"CompitListProfAndStatusYes,ExistenceFLGYes,ExistenceInspGinYes,RationalUseOfResourcesYes,"
		"AbsenceComplaintsOfPatientsYes,TimelyRegistLNYes,RefferalToVKYes,IntegrityCard,"
		"AccuracyHandwriting,QualityProfInsOnko,DispTimelines,QualityCollectAnamsis,QualityCollectComplaint,"
		"DescriptObjectStatus,EvaluationResultsOfTreatment,ObservStandartsOfDiagnostics,"
		"ObservStandartsOfTreatment,DeadlinesVN,kkmp,kvo) VALUES("
			"'"+FormatDateTime("yyyy-mm-dd",DTPDateStart->Date)+"',"
			"'"+FormatDateTime("yyyy-mm-dd",DTPDateEnd->Date)+"',"
			"'"+PAmountOfDays->Caption+"',"
			"'"+ESurname->Text+"',"
			"'"+EName->Text+"',"
			"'"+EPatronymic->Text+"',"
			"'"+ EYearOfBirthday->Text +"',"
			"'"+EArea->Text+"',"
			"'"+ DBLookupComboBoxListMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString +"',"
			"'"+ IntToStr(RemarkInfServYes) +"',"
			"'"+ IntToStr(RemarkAnamYes) +"',"
			"'"+ IntToStr(RemarkFizResYes) +"',"
			"'"+ IntToStr(ResearchNotYes) +"',"
			"'"+ IntToStr(ResearchToMuchYes) +"',"
			"'"+ IntToStr(ResearchLateYes) +"',"
			"'"+ IntToStr(ResearchInstrNotYes) +"',"
			"'"+ IntToStr(ResearchInstrToMuchYes) +"',"
			"'"+ IntToStr(ResearchInstrLateYes) +"',"
			"'"+ IntToStr(RemarkKonsultNotYes) +"',"
			"'"+ IntToStr(RemarkKonsultLateYes) +"',"
			"'"+ IntToStr(RemarkDeseaseVerifYes) +"',"
			"'"+ IntToStr(RemarkDeseaseTimeYes) +"',"
			"'"+ IntToStr(RemarkDeseaseContentYes) +"',"
			"'"+ IntToStr(RemarkTherapyChooseDrYes) +"',"
			"'"+ IntToStr(RemarkTherapyTimeAppointmentYes) +"',"
			"'"+ IntToStr(RemarkTherapyPolypharmacyYes) +"',"
			"'"+ IntToStr(ContinuityChoosePlaceYes) +"',"
			"'"+ IntToStr(ContinuityTimeTransferYes) +"',"
			"'"+ IntToStr(RemarkStandartMHYes) +"',"
			"'"+ IntToStr(VuluntarMedAgreementYes) +"',"
			"'"+ IntToStr(AgreementPDNYes) +"',"
			"'"+ IntToStr(ComplitListDeseaseYes) +"',"
			"'"+ IntToStr(CompitListProfAndStatusYes) +"',"
			"'"+ IntToStr(ExistenceFLGYes) +"',"
			"'"+ IntToStr(ExistenceInspGinYes) +"',"
			"'"+ IntToStr(RationalUseOfResourcesYes) +"',"
			"'"+ IntToStr(AbsenceComplaintsOfPatientsYes) +"',"
			"'"+ IntToStr(TimelyRegistLNYes) +"',"
			"'"+ IntToStr(RefferalToVKYes) +"',"
			"'"+ IntToStr(IntegrityCard) +"',"
			"'"+ IntToStr(AccuracyHandwriting) +"',"
			"'"+ IntToStr(QualityProfInsOnko) +"',"
			"'"+ IntToStr(DispTimelines) +"',"
			"'"+ IntToStr(QualityCollectAnamsis) +"',"
			"'"+ IntToStr(QualityCollectComplaint) +"',"
			"'"+ IntToStr(DescriptObjectStatus) +"',"
			"'"+ IntToStr(EvaluationResultsOfTreatment) +"',"
			"'"+ IntToStr(ObservStandartsOfDiagnostics) +"',"
			"'"+ IntToStr(ObservStandartsOfTreatment) +"',"
			"'"+ IntToStr(DeadlinesVN) +"',"
			"'"+ PKKMP->Caption +"',"
			"'"+ FloatToStr(kvo) +"'"
			")";
	}

	try{
		DMAvtoriz->SQLConnectKKMP->StartTransaction(trans);
		if(DMAvtoriz->SQLQCard->ExecSQL()){
			DMAvtoriz->SQLConnectKKMP->Commit(trans);
		}else{
			DMAvtoriz->SQLConnectKKMP->Rollback(trans);
			MessageBox(0,L"������ ������ \"false\"!\n���������� � ������������.",L"������",MB_OK);
		}
	}catch(Exception &e){
		DMAvtoriz->SQLConnectKKMP->Rollback(trans);
		MessageBox(0,e.Message.c_str(),L"������ ������",MB_OK);
	}


	int message = MessageBox(0,L"����� ���������.\n�������� ����� �����?",L"���������",MB_YESNO);
	if(message == 7){
		FCard->Close();
	}else if(message == 6){
		clearForm(Sender);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCard::ESurnameExit(TObject *Sender)
{
	ESurname->Text = ESurname->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::ENameExit(TObject *Sender)
{
	EName->Text = EName->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::EPatronymicExit(TObject *Sender)
{
	EPatronymic->Text = EPatronymic->Text.UpperCase();
}
//---------------------------------------------------------------------------
void __fastcall TFCard::FormClose(TObject *Sender, TCloseAction &Action)
{
	DMAvtoriz->SQLQGetListMed->Close();
	DMAvtoriz->CDSGetListMed->Close();

	DMAvtoriz->SQLQInspection->Close();
	DMAvtoriz->SQLQInspection->SQL->Text =
		"SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT(`surname`,' ',`name`,' ',`patronymic`) as `fio`,"
		"`year_date_birthday`,`id_user`,`kkmp`,`kvo` "
		"FROM `inspection` "
		"WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'-01-01') AND NOW() "
		"ORDER BY `id_inspection` DESC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();

	clearForm(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkInfServClick(TObject *Sender)
{
	RemarkInfServYes = 0;
	PRemarkInfServYes->Color = clWhite;
	PRemarkInfServNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkAnamClick(TObject *Sender)
{
	RemarkAnamYes = 0;
	PRemarkAnamYes->Color = clWhite;
	PRemarkAnamNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkFizResClick(TObject *Sender)
{
	RemarkFizResYes = 0;
	PRemarkFizResYes->Color = clWhite;
	PRemarkFizResNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchNotClick(TObject *Sender)
{
	ResearchNotYes = 0;
	PResearchNotYes->Color = clWhite;
	PResearchNotNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchToMuchClick(TObject *Sender)
{
	ResearchToMuchYes = 0;
	PResearchToMuchYes->Color = clWhite;
	PResearchToMuchNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchLateClick(TObject *Sender)
{
	ResearchLateYes = 0;
	PResearchLateYes->Color = clWhite;
	PResearchLateNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrNotClick(TObject *Sender)
{
	ResearchInstrNotYes = 0;
	PResearchInstrNotYes->Color = clWhite;
	PResearchInstrNotNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrToMuchClick(TObject *Sender)
{
	ResearchInstrToMuchYes = 0;
	PResearchInstrToMuchYes->Color = clWhite;
	PResearchInstrToMuchNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrLateClick(TObject *Sender)
{
	ResearchInstrLateYes = 0;
	PResearchInstrLateYes->Color = clWhite;
	PResearchInstrLateNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultNotClick(TObject *Sender)
{
	RemarkKonsultNotYes = 0;
	PRemarkKonsultNotYes->Color = clWhite;
	PRemarkKonsultNotNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultLateClick(TObject *Sender)
{
	RemarkKonsultLateYes = 0;
	PRemarkKonsultLateYes->Color = clWhite;
	PRemarkKonsultLateNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseVerifClick(TObject *Sender)
{
	RemarkDeseaseVerifYes = 0;
	PRemarkDeseaseVerifYes->Color = clWhite;
	PRemarkDeseaseVerifNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseTimeClick(TObject *Sender)
{
	RemarkDeseaseTimeYes = 0;
	PRemarkDeseaseTimeYes->Color = clWhite;
	PRemarkDeseaseTimeNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseContentClick(TObject *Sender)
{
	RemarkDeseaseContentYes = 0;
	PRemarkDeseaseContentYes->Color = clWhite;
	PRemarkDeseaseContentNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyChooseDrClick(TObject *Sender)
{
	RemarkTherapyChooseDrYes = 0;
	PRemarkTherapyChooseDrYes->Color = clWhite;
	PRemarkTherapyChooseDrNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyTimeAppointmentClick(TObject *Sender)
{
	RemarkTherapyTimeAppointmentYes = 0;
	PRemarkTherapyTimeAppointmentYes->Color = clWhite;
	PRemarkTherapyTimeAppointmentNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyPolypharmacyClick(TObject *Sender)
{
	RemarkTherapyPolypharmacyYes = 0;
	PRemarkTherapyPolypharmacyYes->Color = clWhite;
	PRemarkTherapyPolypharmacyNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityChoosePlaceClick(TObject *Sender)
{
	ContinuityChoosePlaceYes = 0;
	PContinuityChoosePlaceYes->Color = clWhite;
	PContinuityChoosePlaceNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityTimeTransferClick(TObject *Sender)
{
	ContinuityTimeTransferYes = 0;
	PContinuityTimeTransferYes->Color = clWhite;
	PContinuityTimeTransferNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkStandartMHClick(TObject *Sender)
{
	RemarkStandartMHYes = 0;
	PRemarkStandartMHYes->Color = clWhite;
	PRemarkStandartMHNo->Color = clWhite;
	getKvo();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PVuluntarMedAgreementClick(TObject *Sender)
{
	VuluntarMedAgreementYes = 0;
	PVuluntarMedAgreementYes->Color = clWhite;
	PVuluntarMedAgreementNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAgreementPDNClick(TObject *Sender)
{
	AgreementPDNYes = 0;
	PAgreementPDNYes->Color = clWhite;
	PAgreementPDNNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PComplitListDeseaseClick(TObject *Sender)
{
	ComplitListDeseaseYes = 0;
	PComplitListDeseaseYes->Color = clWhite;
	PComplitListDeseaseNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PCompitListProfAndStatusClick(TObject *Sender)
{
	CompitListProfAndStatusYes = 0;
	PCompitListProfAndStatusYes->Color = clWhite;
	PCompitListProfAndStatusNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PIntegrityCardClick(TObject *Sender)
{
	IntegrityCard = 0;
	PIntegrityCard5->Color = clWhite;
	PIntegrityCard4->Color = clWhite;
	PIntegrityCard3->Color = clWhite;
	PIntegrityCard2->Color = clWhite;
	PIntegrityCard1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAccuracyHandwritingClick(TObject *Sender)
{
	AccuracyHandwriting = 0;
	PAccuracyHandwriting5->Color = clWhite;
	PAccuracyHandwriting4->Color = clWhite;
	PAccuracyHandwriting3->Color = clWhite;
	PAccuracyHandwriting2->Color = clWhite;
	PAccuracyHandwriting1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceFLGClick(TObject *Sender)
{
	ExistenceFLGYes = 0;
	PExistenceFLGYes->Color = clWhite;
	PExistenceFLGNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceInspGinClick(TObject *Sender)
{
	ExistenceInspGinYes = 0;
	PExistenceInspGinYes->Color = clWhite;
	PExistenceInspGinNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityProfInsOnkoClick(TObject *Sender)
{
	QualityProfInsOnko = 0;
	PQualityProfInsOnko5->Color = clWhite;
	PQualityProfInsOnko4->Color = clWhite;
	PQualityProfInsOnko3->Color = clWhite;
	PQualityProfInsOnko2->Color = clWhite;
	PQualityProfInsOnko1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDispTimelinesClick(TObject *Sender)
{
	DispTimelines = 0;
	PDispTimelines5->Color = clWhite;
	PDispTimelines4->Color = clWhite;
	PDispTimelines3->Color = clWhite;
	PDispTimelines2->Color = clWhite;
	PDispTimelines1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectAnamsisClick(TObject *Sender)
{
	QualityCollectAnamsis = 0 ;
	PQualityCollectAnamsis5->Color = clWhite;
	PQualityCollectAnamsis4->Color = clWhite;
	PQualityCollectAnamsis3->Color = clWhite;
	PQualityCollectAnamsis2->Color = clWhite;
	PQualityCollectAnamsis1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PQualityCollectComplaintClick(TObject *Sender)
{
	QualityCollectComplaint = 0;
	PQualityCollectComplaint5->Color = clWhite;
	PQualityCollectComplaint4->Color = clWhite;
	PQualityCollectComplaint3->Color = clWhite;
	PQualityCollectComplaint2->Color = clWhite;
	PQualityCollectComplaint1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDescriptObjectStatusClick(TObject *Sender)
{
	DescriptObjectStatus = 0;
	PDescriptObjectStatus5->Color = clWhite;
	PDescriptObjectStatus4->Color = clWhite;
	PDescriptObjectStatus3->Color = clWhite;
	PDescriptObjectStatus2->Color = clWhite;
	PDescriptObjectStatus1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PEvaluationResultsOfTreatmentClick(TObject *Sender)
{
	EvaluationResultsOfTreatment = 0;
	PEvaluationResultsOfTreatment5->Color = clWhite;
	PEvaluationResultsOfTreatment4->Color = clWhite;
	PEvaluationResultsOfTreatment3->Color = clWhite;
	PEvaluationResultsOfTreatment2->Color = clWhite;
	PEvaluationResultsOfTreatment1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfDiagnosticsClick(TObject *Sender)
{
	ObservStandartsOfDiagnostics = 0;
	PObservStandartsOfDiagnostics5->Color =clWhite;
	PObservStandartsOfDiagnostics4->Color =clWhite;
	PObservStandartsOfDiagnostics3->Color =clWhite;
	PObservStandartsOfDiagnostics2->Color =clWhite;
	PObservStandartsOfDiagnostics1->Color =clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PObservStandartsOfTreatmentClick(TObject *Sender)
{
	ObservStandartsOfTreatment = 0;
	PObservStandartsOfTreatment5->Color = clWhite;
	PObservStandartsOfTreatment4->Color = clWhite;
	PObservStandartsOfTreatment3->Color = clWhite;
	PObservStandartsOfTreatment2->Color = clWhite;
	PObservStandartsOfTreatment1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRationalUseOfResourcesClick(TObject *Sender)
{
	RationalUseOfResourcesYes = 0;
	PRationalUseOfResourcesYes->Color = clWhite;
	PRationalUseOfResourcesNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAbsenceComplaintsOfPatientsClick(TObject *Sender)
{
	AbsenceComplaintsOfPatientsYes = 0;
	PAbsenceComplaintsOfPatientsYes->Color = clWhite;
	PAbsenceComplaintsOfPatientsNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PDeadlinesVNClick(TObject *Sender)
{
	DeadlinesVN = 0;
	PDeadlinesVN5->Color = clWhite;
	PDeadlinesVN4->Color = clWhite;
	PDeadlinesVN3->Color = clWhite;
	PDeadlinesVN2->Color = clWhite;
	PDeadlinesVN1->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PTimelyRegistLNClick(TObject *Sender)
{
	TimelyRegistLNYes = 0;
	PTimelyRegistLNYes->Color = clWhite;
	PTimelyRegistLNNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRefferalToVKClick(TObject *Sender)
{
	RefferalToVKYes = 0;
	PRefferalToVKYes->Color = clWhite;
	PRefferalToVKNo->Color = clWhite;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PTimelyRegistLNYesClick(TObject *Sender)
{
	PTimelyRegistLNYes->Color = TColor(0x0064B1FF);
	PTimelyRegistLNNo->Color = clWhite;
	TimelyRegistLNYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRefferalToVKYesClick(TObject *Sender)
{
	PRefferalToVKYes->Color = TColor(0x0064B1FF);
	PRefferalToVKNo->Color = clWhite;
	RefferalToVKYes = 5;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PTimelyRegistLNNoClick(TObject *Sender)
{
	PTimelyRegistLNYes->Color = clWhite;
	PTimelyRegistLNNo->Color = TColor(0x0064B1FF);
	TimelyRegistLNYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRefferalToVKNoClick(TObject *Sender)
{
	PRefferalToVKYes->Color = clWhite;
	PRefferalToVKNo->Color = TColor(0x0064B1FF);
	RefferalToVKYes = 1;
	getKkmp();
}
//---------------------------------------------------------------------------

