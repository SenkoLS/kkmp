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
	//for kvo
	kvo = 0;
	RemarkInfServYes = false;
	RemarkAnamYes = false;
	RemarkFizResYes = false;
	ResearchNotYes = false;
	ResearchToMuchYes = false;
	ResearchLateYes = false;
	ResearchInstrNotYes = false;
	ResearchInstrToMuchYes = false;
	ResearchInstrLateYes = false;
	RemarkKonsultNotYes = false;
	RemarkKonsultLateYes = false;
	RemarkDeseaseVerifYes = false;
	RemarkDeseaseTimeYes = false;
	RemarkDeseaseContentYes = false;
	RemarkTherapyChooseDrYes = false;
	RemarkTherapyTimeAppointmentYes = false;
	RemarkTherapyPolypharmacyYes = false;
	ContinuityChoosePlaceYes = false;
	ContinuityTimeTransferYes = false;
	RemarkStandartMHYes = false;

	//for kkmp
	kkmp = 0;
	VuluntarMedAgreementYes = true;
	AgreementPDNYes = true;
	ComplitListDeseaseYes = true;
	CompitListProfAndStatusYes = true;
	ExistenceFLGYes = true;
	ExistenceInspGinYes = true;
    RationalUseOfResourcesYes = true;
	AbsenceComplaintsOfPatientsYes = true;
	TimelyRegistLNYes = true;
	RefferalToVKYes = true;

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
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFCard::BoolToStr(bool value){
	AnsiString str = "";
	return (value) ? str = "1" : str = "0";
}
//---------------------------------------------------------------------------
void __fastcall TFCard::getKvo(){
    kvo = 0;

	if(RemarkInfServYes) kvo = kvo + 0.05;
	if(RemarkAnamYes) kvo = kvo + 0.05;
	if(RemarkFizResYes) kvo = kvo + 0.05;
	if(ResearchNotYes) kvo = kvo + 0.05;
	if(ResearchToMuchYes) kvo = kvo + 0.05;
	if(ResearchLateYes) kvo = kvo + 0.05;
	if(ResearchInstrNotYes) kvo = kvo + 0.05;
	if(ResearchInstrToMuchYes) kvo = kvo + 0.05;
	if(ResearchInstrLateYes) kvo = kvo + 0.05;
	if(RemarkKonsultNotYes) kvo = kvo + 0.05;
	if(RemarkKonsultLateYes) kvo = kvo + 0.05;
	if(RemarkDeseaseVerifYes) kvo = kvo + 0.05;
	if(RemarkDeseaseTimeYes) kvo = kvo + 0.05;
	if(RemarkDeseaseContentYes) kvo = kvo + 0.05;
	if(RemarkTherapyChooseDrYes) kvo = kvo + 0.05;
	if(RemarkTherapyTimeAppointmentYes) kvo = kvo + 0.05;
	if(RemarkTherapyPolypharmacyYes) kvo = kvo + 0.05;
	if(ContinuityChoosePlaceYes) kvo = kvo + 0.05;
	if(ContinuityTimeTransferYes) kvo = kvo + 0.05;
	if(RemarkStandartMHYes) kvo = kvo + 0.05;

	PKvo->Caption = FloatToStr(kvo);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::getKkmp(){

	//First part:
	kkmp = 0;
	VuluntarMedAgreementYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	AgreementPDNYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	ComplitListDeseaseYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	CompitListProfAndStatusYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	kkmp = kkmp + IntegrityCard;
	kkmp = kkmp + AccuracyHandwriting;
	kkmp = SimpleRoundTo(kkmp/30,-3);

	AnsiString interValue = FloatToStr(kkmp);

	//Second part:
	kkmp = 0;
	ExistenceFLGYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	ExistenceInspGinYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	RationalUseOfResourcesYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	AbsenceComplaintsOfPatientsYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	//TimelyRegistLNYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	//RefferalToVKYes ? kkmp = kkmp + 5 : kkmp = kkmp + 1;
	kkmp = kkmp + QualityProfInsOnko;
	kkmp = kkmp + DispTimelines;
	kkmp = kkmp + QualityCollectAnamsis;
	kkmp = kkmp + QualityCollectComplaint;
	kkmp = kkmp + DescriptObjectStatus;
	kkmp = kkmp + EvaluationResultsOfTreatment;
	kkmp = kkmp + ObservStandartsOfDiagnostics;
	kkmp = kkmp + ObservStandartsOfTreatment;
	//kkmp = kkmp + DeadlinesVN;
    kkmp = SimpleRoundTo(kkmp/60,-3);

	PKKMP->Caption = interValue + " / " + FloatToStr(kkmp);
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkInfServYesClick(TObject *Sender)
{
	PRemarkInfServYes->Color = TColor(0x0064B1FF);
	PRemarkInfServNo->Color = clWhite;
	if(!RemarkInfServYes){
		RemarkInfServYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkInfServNoClick(TObject *Sender)
{
	PRemarkInfServNo->Color = TColor(0x0064B1FF);
	PRemarkInfServYes->Color = clWhite;
	if(RemarkInfServYes){
		RemarkInfServYes = false;
		getKvo();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkAnamYesClick(TObject *Sender)
{
	PRemarkAnamYes->Color = TColor(0x0064B1FF);
	PRemarkAnamNo->Color = clWhite;
	if(!RemarkAnamYes){
		RemarkAnamYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkAnamNoClick(TObject *Sender)
{
	PRemarkAnamNo->Color = TColor(0x0064B1FF);
	PRemarkAnamYes->Color = clWhite;
	if(RemarkAnamYes){
		RemarkAnamYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkFizResYesClick(TObject *Sender)
{
	PRemarkFizResYes->Color = TColor(0x0064B1FF);
	PRemarkFizResNo->Color = clWhite;
	if(!RemarkFizResYes){
		RemarkFizResYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCard::PRemarkFizResNoClick(TObject *Sender)
{
	PRemarkFizResNo->Color = TColor(0x0064B1FF);
	PRemarkFizResYes->Color = clWhite;
	if(RemarkFizResYes){
		RemarkFizResYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchNotYesClick(TObject *Sender)
{
	PResearchNotYes->Color = TColor(0x0064B1FF);
	PResearchNotNo->Color = clWhite;
	if(!ResearchNotYes){
		ResearchNotYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchNotNoClick(TObject *Sender)
{
	PResearchNotNo->Color = TColor(0x0064B1FF);
	PResearchNotYes->Color = clWhite;
	if(ResearchNotYes){
		ResearchNotYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchToMuchYesClick(TObject *Sender)
{
	PResearchToMuchYes->Color = TColor(0x0064B1FF);
	PResearchToMuchNo->Color = clWhite;
	if(!ResearchToMuchYes){
		ResearchToMuchYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchToMuchNoClick(TObject *Sender)
{
	PResearchToMuchNo->Color = TColor(0x0064B1FF);
	PResearchToMuchYes->Color = clWhite;
	if(ResearchToMuchYes){
		ResearchToMuchYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchLateYesClick(TObject *Sender)
{
	PResearchLateYes->Color = TColor(0x0064B1FF);
	PResearchLateNo->Color = clWhite;
	if(!ResearchLateYes){
		ResearchLateYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchLateNoClick(TObject *Sender)
{
	PResearchLateYes->Color = clWhite;
	PResearchLateNo->Color = TColor(0x0064B1FF);
	if(ResearchLateYes){
		ResearchLateYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrNotYesClick(TObject *Sender)
{
	PResearchInstrNotYes->Color = TColor(0x0064B1FF);
	PResearchInstrNotNo->Color = clWhite;
	if(!ResearchInstrNotYes){
		ResearchInstrNotYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrNotNoClick(TObject *Sender)
{
	PResearchInstrNotNo->Color = TColor(0x0064B1FF);
	PResearchInstrNotYes->Color = clWhite;
	if(ResearchInstrNotYes){
		ResearchInstrNotYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrToMuchYesClick(TObject *Sender)
{
	PResearchInstrToMuchYes->Color = TColor(0x0064B1FF);
	PResearchInstrToMuchNo->Color = clWhite;
	if(!ResearchInstrToMuchYes){
		ResearchInstrToMuchYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrToMuchNoClick(TObject *Sender)
{
	PResearchInstrToMuchNo->Color = TColor(0x0064B1FF);
	PResearchInstrToMuchYes->Color = clWhite;
	if(ResearchInstrToMuchYes){
		ResearchInstrToMuchYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrLateYesClick(TObject *Sender)
{
	PResearchInstrLateYes->Color = TColor(0x0064B1FF);
	PResearchInstrLateNo->Color = clWhite;
	if(!ResearchInstrLateYes){
		ResearchInstrLateYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PResearchInstrLateNoClick(TObject *Sender)
{
	PResearchInstrLateNo->Color = TColor(0x0064B1FF);
	PResearchInstrLateYes->Color = clWhite;
	if(ResearchInstrLateYes){
		ResearchInstrLateYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultNotYesClick(TObject *Sender)
{
	PRemarkKonsultNotYes->Color = TColor(0x0064B1FF);
	PRemarkKonsultNotNo->Color = clWhite;
	if(!RemarkKonsultNotYes){
		RemarkKonsultNotYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultNotNoClick(TObject *Sender)
{
	PRemarkKonsultNotNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultNotYes->Color = clWhite;
	if(RemarkKonsultNotYes){
		RemarkKonsultNotYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultLateYesClick(TObject *Sender)
{
	PRemarkKonsultLateYes->Color = TColor(0x0064B1FF);
	PRemarkKonsultLateNo->Color = clWhite;
	if(!RemarkKonsultLateYes){
		RemarkKonsultLateYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkKonsultLateNoClick(TObject *Sender)
{
	PRemarkKonsultLateNo->Color = TColor(0x0064B1FF);
	PRemarkKonsultLateYes->Color = clWhite;
	if(RemarkKonsultLateYes){
		RemarkKonsultLateYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseVerifYesClick(TObject *Sender)
{
	PRemarkDeseaseVerifYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseVerifNo->Color = clWhite;
	if(!RemarkDeseaseVerifYes){
		RemarkDeseaseVerifYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseVerifNoClick(TObject *Sender)
{
	PRemarkDeseaseVerifNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseVerifYes->Color = clWhite;
	if(RemarkDeseaseVerifYes){
		RemarkDeseaseVerifYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseTimeYesClick(TObject *Sender)
{
	PRemarkDeseaseTimeYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseTimeNo->Color = clWhite;
	if(!RemarkDeseaseTimeYes){
		RemarkDeseaseTimeYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseTimeNoClick(TObject *Sender)
{
	PRemarkDeseaseTimeNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseTimeYes->Color = clWhite;
	if(RemarkDeseaseTimeYes){
		RemarkDeseaseTimeYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseContentYesClick(TObject *Sender)
{
	PRemarkDeseaseContentYes->Color = TColor(0x0064B1FF);
	PRemarkDeseaseContentNo->Color = clWhite;
	if(!RemarkDeseaseContentYes){
		RemarkDeseaseContentYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkDeseaseContentNoClick(TObject *Sender)
{
	PRemarkDeseaseContentNo->Color = TColor(0x0064B1FF);
	PRemarkDeseaseContentYes->Color = clWhite;
	if(RemarkDeseaseContentYes){
		RemarkDeseaseContentYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyChooseDrYesClick(TObject *Sender)
{
	PRemarkTherapyChooseDrYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyChooseDrNo->Color = clWhite;
	if(!RemarkTherapyChooseDrYes){
		RemarkTherapyChooseDrYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyChooseDrNoClick(TObject *Sender)
{
	PRemarkTherapyChooseDrNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyChooseDrYes->Color = clWhite;
	if(RemarkTherapyChooseDrYes){
		RemarkTherapyChooseDrYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyTimeAppointmentYesClick(TObject *Sender)
{
	PRemarkTherapyTimeAppointmentYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyTimeAppointmentNo->Color = clWhite;
	if(!RemarkTherapyTimeAppointmentYes){
		RemarkTherapyTimeAppointmentYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyTimeAppointmentNoClick(TObject *Sender)
{
	PRemarkTherapyTimeAppointmentNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyTimeAppointmentYes->Color = clWhite;
	if(RemarkTherapyTimeAppointmentYes){
		RemarkTherapyTimeAppointmentYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyPolypharmacyYesClick(TObject *Sender)
{
	PRemarkTherapyPolypharmacyYes->Color = TColor(0x0064B1FF);
	PRemarkTherapyPolypharmacyNo->Color = clWhite;
	if(!RemarkTherapyPolypharmacyYes){
		RemarkTherapyPolypharmacyYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkTherapyPolypharmacyNoClick(TObject *Sender)
{
	PRemarkTherapyPolypharmacyNo->Color = TColor(0x0064B1FF);
	PRemarkTherapyPolypharmacyYes->Color = clWhite;
	if(RemarkTherapyPolypharmacyYes){
		RemarkTherapyPolypharmacyYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityChoosePlaceYesClick(TObject *Sender)
{
	PContinuityChoosePlaceYes->Color = TColor(0x0064B1FF);
	PContinuityChoosePlaceNo->Color = clWhite;
	if(!ContinuityChoosePlaceYes){
		ContinuityChoosePlaceYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityChoosePlaceNoClick(TObject *Sender)
{
	PContinuityChoosePlaceNo->Color = TColor(0x0064B1FF);
	PContinuityChoosePlaceYes->Color = clWhite;
	if(ContinuityChoosePlaceYes){
		ContinuityChoosePlaceYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityTimeTransferYesClick(TObject *Sender)
{
	PContinuityTimeTransferYes->Color = TColor(0x0064B1FF);
	PContinuityTimeTransferNo->Color = clWhite;
	if(!ContinuityTimeTransferYes){
		ContinuityTimeTransferYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PContinuityTimeTransferNoClick(TObject *Sender)
{
	PContinuityTimeTransferNo->Color = TColor(0x0064B1FF);
	PContinuityTimeTransferYes->Color = clWhite;
	if(ContinuityTimeTransferYes){
		ContinuityTimeTransferYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkStandartMHYesClick(TObject *Sender)
{
	PRemarkStandartMHYes->Color = TColor(0x0064B1FF);
	PRemarkStandartMHNo->Color = clWhite;
	if(!RemarkStandartMHYes){
		RemarkStandartMHYes = true;
		getKvo();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRemarkStandartMHNoClick(TObject *Sender)
{
	PRemarkStandartMHNo->Color = TColor(0x0064B1FF);
	PRemarkStandartMHYes->Color = clWhite;
	if(RemarkStandartMHYes){
		RemarkStandartMHYes = false;
		getKvo();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFCard::PVuluntarMedAgreementYesClick(TObject *Sender)
{
	PVuluntarMedAgreementNo->Color = clWhite;
	PVuluntarMedAgreementYes->Color = TColor(0x0064B1FF);
	if(!VuluntarMedAgreementYes){
		VuluntarMedAgreementYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PVuluntarMedAgreementNoClick(TObject *Sender)
{
	PVuluntarMedAgreementYes->Color = clWhite;
	PVuluntarMedAgreementNo->Color = TColor(0x0064B1FF);
	if(VuluntarMedAgreementYes){
		VuluntarMedAgreementYes = false;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAgreementPDNYesClick(TObject *Sender)
{
	PAgreementPDNYes->Color = TColor(0x0064B1FF);
	PAgreementPDNNo->Color = clWhite;
	if(!AgreementPDNYes){
		AgreementPDNYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAgreementPDNNoClick(TObject *Sender)
{
	PAgreementPDNYes->Color = clWhite;
	PAgreementPDNNo->Color = TColor(0x0064B1FF);
	if(AgreementPDNYes){
		AgreementPDNYes = false;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PComplitListDeseaseYesClick(TObject *Sender)
{
	PComplitListDeseaseYes->Color = TColor(0x0064B1FF);
	PComplitListDeseaseNo->Color = clWhite;
	if(!ComplitListDeseaseYes){
		ComplitListDeseaseYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PComplitListDeseaseNoClick(TObject *Sender)
{
	PComplitListDeseaseYes->Color = clWhite;
	PComplitListDeseaseNo->Color = TColor(0x0064B1FF);
	if(ComplitListDeseaseYes){
		ComplitListDeseaseYes = false;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PCompitListProfAndStatusYesClick(TObject *Sender)
{
	PCompitListProfAndStatusYes->Color = TColor(0x0064B1FF);
	PCompitListProfAndStatusNo->Color = clWhite;
	if(!CompitListProfAndStatusYes){
		CompitListProfAndStatusYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PCompitListProfAndStatusNoClick(TObject *Sender)
{
	PCompitListProfAndStatusYes->Color = clWhite;
	PCompitListProfAndStatusNo->Color = TColor(0x0064B1FF);
	if(CompitListProfAndStatusYes){
		CompitListProfAndStatusYes = false;
		getKkmp();
	}
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

	RemarkInfServYes = false;
	RemarkAnamYes = false;
	RemarkFizResYes = false;
	ResearchNotYes = false;
	ResearchToMuchYes = false;
	ResearchLateYes = false;
	ResearchInstrNotYes = false;
	ResearchInstrToMuchYes = false;
	ResearchInstrLateYes = false;
	RemarkKonsultNotYes = false;
	RemarkKonsultLateYes = false;
	RemarkDeseaseVerifYes = false;
	RemarkDeseaseTimeYes = false;
	RemarkDeseaseContentYes = false;
	RemarkTherapyChooseDrYes = false;
	RemarkTherapyTimeAppointmentYes = false;
	RemarkTherapyPolypharmacyYes = false;
	ContinuityChoosePlaceYes = false;
	ContinuityTimeTransferYes = false;
	RemarkStandartMHYes = false;

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
		SpBAllNoClick(Sender);
		SpBAllNoQualityClick(Sender);
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

	VuluntarMedAgreementYes = true;
	AgreementPDNYes = true;
	ComplitListDeseaseYes = true;
	CompitListProfAndStatusYes = true;
	ExistenceFLGYes = true;
	ExistenceInspGinYes = true;
	RationalUseOfResourcesYes = true;
	AbsenceComplaintsOfPatientsYes = true;
	TimelyRegistLNYes = true;
	RefferalToVKYes = true;

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
	if(!ExistenceFLGYes){
		ExistenceFLGYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceFLGNoClick(TObject *Sender)
{
	PExistenceFLGYes->Color = clWhite;
	PExistenceFLGNo->Color = TColor(0x0064B1FF);
	if(ExistenceFLGYes){
		ExistenceFLGYes = false;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceInspGinYesClick(TObject *Sender)
{
	PExistenceInspGinYes->Color = TColor(0x0064B1FF);
	PExistenceInspGinNo->Color = clWhite;
	if(!ExistenceInspGinYes){
		ExistenceInspGinYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PExistenceInspGinNoClick(TObject *Sender)
{
	PExistenceInspGinYes->Color = clWhite;
	PExistenceInspGinNo->Color = TColor(0x0064B1FF);
	if(ExistenceInspGinYes){
		ExistenceInspGinYes = false;
		getKkmp();
	}
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
	if(!RationalUseOfResourcesYes){
		RationalUseOfResourcesYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PRationalUseOfResourcesNoClick(TObject *Sender)
{
	PRationalUseOfResourcesYes->Color = clWhite;
	PRationalUseOfResourcesNo->Color = TColor(0x0064B1FF);
	if(RationalUseOfResourcesYes){
		RationalUseOfResourcesYes = false;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAbsenceComplaintsOfPatientsYesClick(TObject *Sender)
{
	PAbsenceComplaintsOfPatientsYes->Color = TColor(0x0064B1FF);
	PAbsenceComplaintsOfPatientsNo->Color = clWhite;
	if(!AbsenceComplaintsOfPatientsYes){
		AbsenceComplaintsOfPatientsYes = true;
		getKkmp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFCard::PAbsenceComplaintsOfPatientsNoClick(TObject *Sender)
{
	PAbsenceComplaintsOfPatientsYes->Color = clWhite;
	PAbsenceComplaintsOfPatientsNo->Color = TColor(0x0064B1FF);
	if(AbsenceComplaintsOfPatientsYes){
		AbsenceComplaintsOfPatientsYes = false;
		getKkmp();
	}
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
		MessageBox(0,L"Не указан врач, проводивший осмотр!",L"Ошибка",MB_OK);
		return;
	}

	if(ESurname->Text.IsEmpty()){
		MessageBox(0,L"Не указана фамилия пациента!",L"Ошибка",MB_OK);
		ESurname->SetFocus();
		return;
	}

	if(EName->Text.IsEmpty()){
		MessageBox(0,L"Не указано имя пациента!",L"Ошибка",MB_OK);
		EName->SetFocus();
		return;
	}

	if(EYearOfBirthday->Text.IsEmpty()){
		MessageBox(0,L"Не указан год рождения пациента!",L"Ошибка",MB_OK);
		EYearOfBirthday->SetFocus();
		return;
	}

	if(EArea->Text.IsEmpty()){
		MessageBox(0,L"Не указан участок для пациента!",L"Ошибка",MB_OK);
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
			"`surname` = '"+ESurname->Text+"',"
			"`name` = '"+EName->Text+"',"
			"`patronymic` = '"+EPatronymic->Text+"',"
			"`year_date_birthday` = '"+EYearOfBirthday->Text+"',"
			"`area` = '"+EArea->Text+"',"
			"`id_user` = '"+DBLookupComboBoxListMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString+"',"
			"`RemarkInfServYes` = '"+BoolToStr(RemarkInfServYes)+"',"
			"`RemarkAnamYes` = '"+BoolToStr(RemarkAnamYes)+"',"
			"`RemarkFizResYes` = '"+BoolToStr(RemarkFizResYes)+"',"
			"`ResearchNotYes` = '"+BoolToStr(ResearchNotYes)+"',"
			"`ResearchToMuchYes` = '"+BoolToStr(ResearchToMuchYes)+"',"
			"`ResearchLateYes` = '"+BoolToStr(ResearchLateYes)+"',"
			"`ResearchInstrNotYes` = '"+BoolToStr(ResearchInstrNotYes)+"',"
			"`ResearchInstrToMuchYes` = '"+BoolToStr(ResearchInstrToMuchYes)+"',"
			"`ResearchInstrLateYes` = '"+BoolToStr(ResearchInstrLateYes)+"',"
			"`RemarkKonsultNotYes` = '"+BoolToStr(RemarkKonsultNotYes)+"',"
			"`RemarkKonsultLateYes` = '"+BoolToStr(RemarkKonsultLateYes)+"',"
			"`RemarkDeseaseVerifYes` = '"+BoolToStr(RemarkDeseaseVerifYes)+"',"
			"`RemarkDeseaseTimeYes` = '"+BoolToStr(RemarkDeseaseTimeYes)+"',"
			"`RemarkDeseaseContentYes` = '"+BoolToStr(RemarkDeseaseContentYes)+"',"
			"`RemarkTherapyChooseDrYes` = '"+BoolToStr(RemarkTherapyChooseDrYes)+"',"
			"`RemarkTherapyTimeAppointmentYes` = '"+BoolToStr(RemarkTherapyTimeAppointmentYes)+"',"
			"`RemarkTherapyPolypharmacyYes` = '"+BoolToStr(RemarkTherapyPolypharmacyYes)+"',"
			"`ContinuityChoosePlaceYes` = '"+BoolToStr(ContinuityChoosePlaceYes)+"',"
			"`ContinuityTimeTransferYes` = '"+BoolToStr(ContinuityTimeTransferYes)+"',"
			"`RemarkStandartMHYes` = '"+BoolToStr(RemarkStandartMHYes)+"',"
			"`VuluntarMedAgreementYes` = '"+BoolToStr(VuluntarMedAgreementYes)+"',"
			"`AgreementPDNYes` = '"+BoolToStr(AgreementPDNYes)+"',"
			"`ComplitListDeseaseYes` = '"+BoolToStr(ComplitListDeseaseYes)+"',"
			"`CompitListProfAndStatusYes` = '"+BoolToStr(CompitListProfAndStatusYes)+"',"
			"`ExistenceFLGYes` = '"+BoolToStr(ExistenceFLGYes)+"',"
			"`ExistenceInspGinYes` = '"+BoolToStr(ExistenceInspGinYes)+"',"
			"`RationalUseOfResourcesYes` = '"+BoolToStr(RationalUseOfResourcesYes)+"',"
			"`AbsenceComplaintsOfPatientsYes` = '"+BoolToStr(AbsenceComplaintsOfPatientsYes)+"',"
			"`TimelyRegistLNYes` = '"+BoolToStr(TimelyRegistLNYes)+"',"
			"`RefferalToVKYes` = '"+BoolToStr(RefferalToVKYes)+"',"
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
		"(date_start,date_end,surname,name,patronymic,year_date_birthday,area,id_user,"
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
			"'"+ESurname->Text+"',"
			"'"+EName->Text+"',"
			"'"+EPatronymic->Text+"',"
			"'"+ EYearOfBirthday->Text +"',"
			"'"+EArea->Text+"',"
			"'"+ DBLookupComboBoxListMed->ListSource->DataSet->FieldByName("id_user")->AsAnsiString +"',"
			"'"+ BoolToStr(RemarkInfServYes) +"',"
			"'"+ BoolToStr(RemarkAnamYes) +"',"
			"'"+ BoolToStr(RemarkFizResYes) +"',"
			"'"+ BoolToStr(ResearchNotYes) +"',"
			"'"+ BoolToStr(ResearchToMuchYes) +"',"
			"'"+ BoolToStr(ResearchLateYes) +"',"
			"'"+ BoolToStr(ResearchInstrNotYes) +"',"
			"'"+ BoolToStr(ResearchInstrToMuchYes) +"',"
			"'"+ BoolToStr(ResearchInstrLateYes) +"',"
			"'"+ BoolToStr(RemarkKonsultNotYes) +"',"
			"'"+ BoolToStr(RemarkKonsultLateYes) +"',"
			"'"+ BoolToStr(RemarkDeseaseVerifYes) +"',"
			"'"+ BoolToStr(RemarkDeseaseTimeYes) +"',"
			"'"+ BoolToStr(RemarkDeseaseContentYes) +"',"
			"'"+ BoolToStr(RemarkTherapyChooseDrYes) +"',"
			"'"+ BoolToStr(RemarkTherapyTimeAppointmentYes) +"',"
			"'"+ BoolToStr(RemarkTherapyPolypharmacyYes) +"',"
			"'"+ BoolToStr(ContinuityChoosePlaceYes) +"',"
			"'"+ BoolToStr(ContinuityTimeTransferYes) +"',"
			"'"+ BoolToStr(RemarkStandartMHYes) +"',"
			"'"+ BoolToStr(VuluntarMedAgreementYes) +"',"
			"'"+ BoolToStr(AgreementPDNYes) +"',"
			"'"+ BoolToStr(ComplitListDeseaseYes) +"',"
			"'"+ BoolToStr(CompitListProfAndStatusYes) +"',"
			"'"+ BoolToStr(ExistenceFLGYes) +"',"
			"'"+ BoolToStr(ExistenceInspGinYes) +"',"
			"'"+ BoolToStr(RationalUseOfResourcesYes) +"',"
			"'"+ BoolToStr(AbsenceComplaintsOfPatientsYes) +"',"
			"'"+ BoolToStr(TimelyRegistLNYes) +"',"
			"'"+ BoolToStr(RefferalToVKYes) +"',"
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
			MessageBox(0,L"Запрос вернул \"false\"!\nОбратитесь к разработчику.",L"Ошибка",MB_OK);
		}
	}catch(Exception &e){
		DMAvtoriz->SQLConnectKKMP->Rollback(trans);
		MessageBox(0,e.Message.c_str(),L"Ошибка записи",MB_OK);
	}


	int message = MessageBox(0,L"Карта сохранена.\nОформить новую карту?",L"Сообщение",MB_YESNO);
	if(message == 7){
		FCard->Close();
	}else if(message == 6){
		SpBAllNoClick(Sender);
		SpBAllNoQualityClick(Sender);
		DTPDateStart->Date = Now();
		DTPDateEnd->Date = Now();
		EArea->Text = "";
		ESurname->Text = "";
		EName->Text = "";
		EPatronymic->Text = "";
		EYearOfBirthday->Text = "";
		DBLookupComboBoxListMed->KeyValue = 1;
	}
	id_inspection = NULL; //set editing in false
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
	DMAvtoriz->SQLQInspection->SQL->Text =  "SELECT `id_inspection`,`date_start`,`date_end`,"
											" CONCAT(surname,' ',name,' ',patronymic) as `fio`,"
											"`year_date_birthday`,`id_user`,`kkmp`,`kvo` "
											"FROM `inspection` ORDER BY `id_inspection` DESC";

	DMAvtoriz->SQLQInspection->Open();
	DMAvtoriz->CDSInspection->Close();
	DMAvtoriz->CDSInspection->Open();

	id_inspection = NULL; //set editing in false
}
//---------------------------------------------------------------------------

