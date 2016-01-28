//---------------------------------------------------------------------------

#ifndef UCardH
#define UCardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDMAvtoriz.h"
#include <ExtCtrls.hpp>
#include "TeCanvas.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include "Math.hpp"
//---------------------------------------------------------------------------
class TFCard : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *PRemarkInfServ;
	TPanel *PRemarkInfServYes;
	TPanel *PRemarkInfServNo;
	TLabel *Label3;
	TPanel *PRemarkAnam;
	TPanel *PRemarkAnamYes;
	TPanel *PRemarkAnamNo;
	TPanel *PRemarkFizRes;
	TPanel *PRemarkFizResYes;
	TPanel *PRemarkFizResNo;
	TLabel *Label4;
	TPanel *PResearchNot;
	TPanel *PResearchToMuch;
	TPanel *PResearchToMuchNo;
	TPanel *PResearchNotNo;
	TPanel *PResearchNotYes;
	TPanel *PResearchToMuchYes;
	TPanel *PResearchLate;
	TPanel *PResearchLateYes;
	TPanel *PResearchLateNo;
	TPanel *PResearchInstrNot;
	TPanel *PResearchInstrNotYes;
	TPanel *PResearchInstrNotNo;
	TPanel *PResearchInstrToMuch;
	TPanel *PResearchInstrLate;
	TPanel *PResearchInstrToMuchYes;
	TPanel *PResearchInstrToMuchNo;
	TPanel *PResearchInstrLateYes;
	TPanel *PResearchInstrLateNo;
	TLabel *Label5;
	TLabel *Label6;
	TPanel *PRemarkKonsultNot;
	TPanel *PRemarkKonsultLate;
	TPanel *PRemarkKonsultNotYes;
	TPanel *PRemarkKonsultLateYes;
	TPanel *PRemarkKonsultNotNo;
	TPanel *PRemarkKonsultLateNo;
	TLabel *Label7;
	TPanel *PRemarkDeseaseVerif;
	TPanel *PRemarkDeseaseTime;
	TPanel *PRemarkDeseaseContent;
	TPanel *PRemarkDeseaseVerifYes;
	TPanel *PRemarkDeseaseTimeYes;
	TPanel *PRemarkDeseaseContentYes;
	TPanel *PRemarkDeseaseVerifNo;
	TPanel *PRemarkDeseaseTimeNo;
	TPanel *PRemarkDeseaseContentNo;
	TLabel *Label8;
	TPanel *PRemarkTherapyPolypharmacyNo;
	TPanel *PRemarkTherapyTimeAppointmentNo;
	TPanel *PRemarkTherapyChooseDrNo;
	TPanel *PRemarkTherapyPolypharmacyYes;
	TPanel *PRemarkTherapyTimeAppointmentYes;
	TPanel *PRemarkTherapyChooseDrYes;
	TPanel *PRemarkTherapyPolypharmacy;
	TPanel *PRemarkTherapyTimeAppointment;
	TPanel *PRemarkTherapyChooseDr;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TPanel *PKvo;
	TPanel *PContinuityChoosePlace;
	TPanel *PContinuityChoosePlaceNo;
	TPanel *PContinuityChoosePlaceYes;
	TPanel *PContinuityTimeTransferNo;
	TPanel *PContinuityTimeTransfer;
	TPanel *PContinuityTimeTransferYes;
	TPanel *PRemarkStandartMH;
	TPanel *PRemarkStandartMHYes;
	TPanel *PRemarkStandartMHNo;
	TSpeedButton *SpBAllNo;
	TSpeedButton *SpBAllNoQuality;
	TLabel *Label12;
	TDateTimePicker *DTPDateStart;
	TLabel *Label13;
	TDateTimePicker *DTPDateEnd;
	TPanel *PAmountOfDays;
	TLabel *Label14;
	TEdit *Edit1;
	TLabel *Label15;
	TEdit *Edit2;
	TLabel *Label16;
	TEdit *Edit3;
	TLabel *Label17;
	TDBLookupComboBox *DBLookupComboBox1;
	TPanel *PVuluntarMedAgreement;
	TPanel *PAgreementPDN;
	TPanel *PComplitListDesease;
	TPanel *PCompitListProfAndStatus;
	TPanel *PIntegrityCard;
	TPanel *PAccuracyHandwriting;
	TPanel *PExistenceFLG;
	TPanel *PExistenceInspGin;
	TPanel *PQualityProfInsOnko;
	TPanel *PDispTimelines;
	TPanel *PQualityCollectAnamsis;
	TPanel *PQualityCollectComplaint;
	TPanel *PVuluntarMedAgreementNo;
	TPanel *PVuluntarMedAgreementYes;
	TPanel *PAgreementPDNNo;
	TPanel *PComplitListDeseaseNo;
	TPanel *PCompitListProfAndStatusNo;
	TPanel *PIntegrityCard1;
	TPanel *PAccuracyHandwriting1;
	TPanel *PIntegrityCard3;
	TPanel *PIntegrityCard5;
	TPanel *PAccuracyHandwriting4;
	TPanel *PExistenceFLGNo;
	TPanel *PExistenceInspGinNo;
	TPanel *PQualityProfInsOnko1;
	TPanel *PAgreementPDNYes;
	TPanel *PComplitListDeseaseYes;
	TPanel *PCompitListProfAndStatusYes;
	TPanel *PIntegrityCard2;
	TPanel *PAccuracyHandwriting2;
	TPanel *PIntegrityCard4;
	TPanel *PAccuracyHandwriting3;
	TPanel *PAccuracyHandwriting5;
	TPanel *PExistenceFLGYes;
	TPanel *PExistenceInspGinYes;
	TPanel *PQualityProfInsOnko2;
	TLabel *Label18;
	TPanel *PDescriptObjectStatus;
	TPanel *PEvaluationResultsOfTreatment;
	TPanel *PObservStandartsOfDiagnostics;
	TPanel *PObservStandartsOfTreatment;
	TPanel *PDispTimelines5;
	TPanel *PDispTimelines2;
	TPanel *PDispTimelines3;
	TPanel *PDispTimelines1;
	TPanel *PQualityProfInsOnko3;
	TPanel *PQualityProfInsOnko4;
	TPanel *PDispTimelines4;
	TPanel *PQualityProfInsOnko5;
	TPanel *PQualityCollectComplaint3;
	TPanel *PQualityCollectComplaint5;
	TPanel *PDescriptObjectStatus1;
	TPanel *PQualityCollectComplaint4;
	TPanel *PQualityCollectComplaint2;
	TPanel *PDescriptObjectStatus2;
	TPanel *PQualityCollectAnamsis1;
	TPanel *PQualityCollectAnamsis2;
	TPanel *PQualityCollectAnamsis3;
	TPanel *PQualityCollectAnamsis4;
	TPanel *PQualityCollectComplaint1;
	TPanel *PDescriptObjectStatus3;
	TPanel *PQualityCollectAnamsis5;
	TPanel *PDescriptObjectStatus4;
	TPanel *PDescriptObjectStatus5;
	TPanel *PEvaluationResultsOfTreatment1;
	TPanel *PEvaluationResultsOfTreatment5;
	TPanel *PEvaluationResultsOfTreatment2;
	TPanel *PObservStandartsOfDiagnostics1;
	TPanel *PObservStandartsOfDiagnostics2;
	TPanel *PObservStandartsOfDiagnostics4;
	TPanel *PObservStandartsOfDiagnostics3;
	TPanel *PEvaluationResultsOfTreatment3;
	TPanel *PEvaluationResultsOfTreatment4;
	TPanel *PObservStandartsOfDiagnostics5;
	TPanel *PObservStandartsOfTreatment1;
	TPanel *PAbsenceComplaintsOfPatients;
	TPanel *PRationalUseOfResourcesNo;
	TPanel *PObservStandartsOfTreatment4;
	TPanel *PObservStandartsOfTreatment5;
	TPanel *PRationalUseOfResources;
	TPanel *PObservStandartsOfTreatment2;
	TPanel *PObservStandartsOfTreatment3;
	TPanel *PRationalUseOfResourcesYes;
	TPanel *PAbsenceComplaintsOfPatientsYes;
	TPanel *PDeadlinesVN;
	TPanel *PAbsenceComplaintsOfPatientsNo;
	TPanel *PDeadlinesVN3;
	TPanel *PDeadlinesVN2;
	TPanel *PDeadlinesVN1;
	TPanel *PRefferalToVK;
	TPanel *PTimelyRegistLN;
	TPanel *PTimelyRegistLNNo;
	TPanel *PDeadlinesVN5;
	TPanel *PRefferalToVKNo;
	TPanel *PTimelyRegistLNYes;
	TPanel *PDeadlinesVN4;
	TPanel *PRefferalToVKYes;
	TPanel *PKKMP;
	void __fastcall PRemarkInfServYesClick(TObject *Sender);
	void __fastcall PRemarkInfServNoClick(TObject *Sender);
	void __fastcall PRemarkAnamYesClick(TObject *Sender);
	void __fastcall PRemarkAnamNoClick(TObject *Sender);
	void __fastcall PRemarkFizResYesClick(TObject *Sender);
	void __fastcall PRemarkFizResNoClick(TObject *Sender);
	void __fastcall PResearchNotYesClick(TObject *Sender);
	void __fastcall PResearchNotNoClick(TObject *Sender);
	void __fastcall PResearchToMuchYesClick(TObject *Sender);
	void __fastcall PResearchToMuchNoClick(TObject *Sender);
	void __fastcall PResearchLateYesClick(TObject *Sender);
	void __fastcall PResearchLateNoClick(TObject *Sender);
	void __fastcall PResearchInstrNotYesClick(TObject *Sender);
	void __fastcall PResearchInstrNotNoClick(TObject *Sender);
	void __fastcall PResearchInstrToMuchYesClick(TObject *Sender);
	void __fastcall PResearchInstrToMuchNoClick(TObject *Sender);
	void __fastcall PResearchInstrLateYesClick(TObject *Sender);
	void __fastcall PResearchInstrLateNoClick(TObject *Sender);
	void __fastcall PRemarkKonsultNotYesClick(TObject *Sender);
	void __fastcall PRemarkKonsultNotNoClick(TObject *Sender);
	void __fastcall PRemarkKonsultLateYesClick(TObject *Sender);
	void __fastcall PRemarkKonsultLateNoClick(TObject *Sender);
	void __fastcall PRemarkDeseaseVerifYesClick(TObject *Sender);
	void __fastcall PRemarkDeseaseVerifNoClick(TObject *Sender);
	void __fastcall PRemarkDeseaseTimeYesClick(TObject *Sender);
	void __fastcall PRemarkDeseaseTimeNoClick(TObject *Sender);
	void __fastcall PRemarkDeseaseContentYesClick(TObject *Sender);
	void __fastcall PRemarkDeseaseContentNoClick(TObject *Sender);
	void __fastcall PRemarkTherapyChooseDrYesClick(TObject *Sender);
	void __fastcall PRemarkTherapyChooseDrNoClick(TObject *Sender);
	void __fastcall PRemarkTherapyTimeAppointmentYesClick(TObject *Sender);
	void __fastcall PRemarkTherapyTimeAppointmentNoClick(TObject *Sender);
	void __fastcall PRemarkTherapyPolypharmacyYesClick(TObject *Sender);
	void __fastcall PRemarkTherapyPolypharmacyNoClick(TObject *Sender);
	void __fastcall PContinuityChoosePlaceYesClick(TObject *Sender);
	void __fastcall PContinuityChoosePlaceNoClick(TObject *Sender);
	void __fastcall PContinuityTimeTransferYesClick(TObject *Sender);
	void __fastcall PContinuityTimeTransferNoClick(TObject *Sender);
	void __fastcall PRemarkStandartMHYesClick(TObject *Sender);
	void __fastcall PRemarkStandartMHNoClick(TObject *Sender);
	void __fastcall PVuluntarMedAgreementYesClick(TObject *Sender);
	void __fastcall PVuluntarMedAgreementNoClick(TObject *Sender);
	void __fastcall PAgreementPDNYesClick(TObject *Sender);
	void __fastcall PAgreementPDNNoClick(TObject *Sender);
	void __fastcall PComplitListDeseaseYesClick(TObject *Sender);
	void __fastcall PComplitListDeseaseNoClick(TObject *Sender);
	void __fastcall PCompitListProfAndStatusYesClick(TObject *Sender);
	void __fastcall PCompitListProfAndStatusNoClick(TObject *Sender);
	void __fastcall PIntegrityCard1Click(TObject *Sender);
	void __fastcall PIntegrityCard2Click(TObject *Sender);
	void __fastcall PIntegrityCard3Click(TObject *Sender);
	void __fastcall PIntegrityCard4Click(TObject *Sender);
	void __fastcall PIntegrityCard5Click(TObject *Sender);
	void __fastcall SpBAllNoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PAccuracyHandwriting1Click(TObject *Sender);
	void __fastcall PAccuracyHandwriting2Click(TObject *Sender);
	void __fastcall PAccuracyHandwriting3Click(TObject *Sender);
	void __fastcall PAccuracyHandwriting4Click(TObject *Sender);
	void __fastcall PAccuracyHandwriting5Click(TObject *Sender);
	void __fastcall SpBAllNoQualityClick(TObject *Sender);
	void __fastcall PExistenceFLGYesClick(TObject *Sender);
	void __fastcall PExistenceFLGNoClick(TObject *Sender);
	void __fastcall PExistenceInspGinYesClick(TObject *Sender);
	void __fastcall PExistenceInspGinNoClick(TObject *Sender);
	void __fastcall PQualityProfInsOnko5Click(TObject *Sender);
	void __fastcall PQualityProfInsOnko4Click(TObject *Sender);
	void __fastcall PQualityProfInsOnko3Click(TObject *Sender);
	void __fastcall PQualityProfInsOnko2Click(TObject *Sender);
	void __fastcall PQualityProfInsOnko1Click(TObject *Sender);
	void __fastcall PDispTimelines5Click(TObject *Sender);
	void __fastcall PDispTimelines4Click(TObject *Sender);
	void __fastcall PDispTimelines3Click(TObject *Sender);
	void __fastcall PDispTimelines2Click(TObject *Sender);
	void __fastcall PDispTimelines1Click(TObject *Sender);
	void __fastcall PQualityCollectAnamsis5Click(TObject *Sender);
	void __fastcall PQualityCollectAnamsis4Click(TObject *Sender);
	void __fastcall PQualityCollectAnamsis3Click(TObject *Sender);
	void __fastcall PQualityCollectAnamsis2Click(TObject *Sender);
	void __fastcall PQualityCollectAnamsis1Click(TObject *Sender);
	void __fastcall PQualityCollectComplaint5Click(TObject *Sender);
	void __fastcall PQualityCollectComplaint4Click(TObject *Sender);
	void __fastcall PQualityCollectComplaint3Click(TObject *Sender);
	void __fastcall PQualityCollectComplaint2Click(TObject *Sender);
	void __fastcall PQualityCollectComplaint1Click(TObject *Sender);
	void __fastcall PDescriptObjectStatus5Click(TObject *Sender);
	void __fastcall PDescriptObjectStatus4Click(TObject *Sender);
	void __fastcall PDescriptObjectStatus3Click(TObject *Sender);
	void __fastcall PDescriptObjectStatus2Click(TObject *Sender);
	void __fastcall PDescriptObjectStatus1Click(TObject *Sender);
	void __fastcall PEvaluationResultsOfTreatment5Click(TObject *Sender);
	void __fastcall PEvaluationResultsOfTreatment4Click(TObject *Sender);
	void __fastcall PEvaluationResultsOfTreatment3Click(TObject *Sender);
	void __fastcall PEvaluationResultsOfTreatment2Click(TObject *Sender);
	void __fastcall PEvaluationResultsOfTreatment1Click(TObject *Sender);
	void __fastcall PObservStandartsOfDiagnostics5Click(TObject *Sender);
	void __fastcall PObservStandartsOfDiagnostics4Click(TObject *Sender);
	void __fastcall PObservStandartsOfDiagnostics3Click(TObject *Sender);
	void __fastcall PObservStandartsOfDiagnostics2Click(TObject *Sender);
	void __fastcall PObservStandartsOfDiagnostics1Click(TObject *Sender);
	void __fastcall PObservStandartsOfTreatment5Click(TObject *Sender);
	void __fastcall PObservStandartsOfTreatment4Click(TObject *Sender);
	void __fastcall PObservStandartsOfTreatment3Click(TObject *Sender);
	void __fastcall PObservStandartsOfTreatment2Click(TObject *Sender);
	void __fastcall PObservStandartsOfTreatment1Click(TObject *Sender);
	void __fastcall PRationalUseOfResourcesYesClick(TObject *Sender);
	void __fastcall PRationalUseOfResourcesNoClick(TObject *Sender);
	void __fastcall PAbsenceComplaintsOfPatientsYesClick(TObject *Sender);
	void __fastcall PAbsenceComplaintsOfPatientsNoClick(TObject *Sender);
	void __fastcall DTPDateStartCloseUp(TObject *Sender);
	void __fastcall DTPDateEndCloseUp(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFCard(TComponent* Owner);
	double 	kvo,kkmp;
	bool	RemarkInfServYes,
			RemarkAnamYes,
			RemarkFizResYes,
			ResearchNotYes,
			ResearchToMuchYes,
			ResearchLateYes,
			ResearchInstrNotYes,
			ResearchInstrToMuchYes,
			ResearchInstrLateYes,
			RemarkKonsultNotYes,
			RemarkKonsultLateYes,
			RemarkDeseaseVerifYes,
			RemarkDeseaseTimeYes,
			RemarkDeseaseContentYes,
			RemarkTherapyChooseDrYes,
			RemarkTherapyTimeAppointmentYes,
			RemarkTherapyPolypharmacyYes,
			ContinuityChoosePlaceYes,
			ContinuityTimeTransferYes,
			RemarkStandartMHYes;

	bool 	VuluntarMedAgreementYes, AgreementPDNYes,
			ComplitListDeseaseYes, CompitListProfAndStatusYes,
			ExistenceFLGYes, ExistenceInspGinYes,
			RationalUseOfResourcesYes, AbsenceComplaintsOfPatientsYes,
			TimelyRegistLNYes,RefferalToVKYes;

	int 	IntegrityCard, AccuracyHandwriting,
			QualityProfInsOnko, DispTimelines,
			QualityCollectAnamsis, QualityCollectComplaint,
			DescriptObjectStatus, EvaluationResultsOfTreatment,
			ObservStandartsOfDiagnostics, ObservStandartsOfTreatment,
			DeadlinesVN;

	void __fastcall TFCard::getKvo();
	void __fastcall TFCard::getKkmp();
};
//---------------------------------------------------------------------------
extern PACKAGE TFCard *FCard;
//---------------------------------------------------------------------------
#endif