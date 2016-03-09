//---------------------------------------------------------------------------

#ifndef UStatReportH
#define UStatReportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <DBCtrls.hpp>
#include "UDMAvtoriz.h"
#include <FileCtrl.hpp>
#include <ComObj.hpp>
#include "UMain.h"
//---------------------------------------------------------------------------
class TFStatReport : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDateTimePicker *DTPStartReportPer;
	TDateTimePicker *DTPEndReportPer;
	TLabel *Label1;
	TLabel *Label2;
	TCheckBox *ChBoxOffice;
	TCheckBox *ChBoxMed;
	TCheckBox *ChBoxExpert;
	TCheckBox *ChBoxGeneral;
	TDBLookupComboBox *DBLCbOffice;
	TDBLookupComboBox *DBLCbMed;
	TDBLookupComboBox *DBLCbExpert;
	TEdit *ECountOfVisits;
	TLabel *Label3;
	TDBGridEh *DBGridReport;
	TButton *BGenerateReport;
	TButton *BGenReport;
	void __fastcall ChBoxOfficeClick(TObject *Sender);
	void __fastcall ChBoxExpertClick(TObject *Sender);
	void __fastcall ChBoxMedClick(TObject *Sender);
	void __fastcall BGenerateReportClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BGenReportClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFStatReport(TComponent* Owner);

	int //quality indicators
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
		DeadlinesVN,
		// counters of quality indicators
		count1,count2,count3,count4,count5,count6,count7,count8,count9,
		count10,count11,count12,count13,count14,count15,count16,count17,count18,
		count19,count20,count21,
		// counters of error indicators
		count31,count32,count33,count34,count35,count36,count37,count38,count39,
		count40,count41,count42,count43,count44,count45,count46,count47,count48,
		count49,count50,
		// error indicators
		RemarkInfServYes,RemarkAnamYes,RemarkFizResYes,ResearchNotYes,
		ResearchToMuchYes,ResearchLateYes,ResearchInstrNotYes,ResearchInstrToMuchYes,
		ResearchInstrLateYes,RemarkKonsultNotYes,RemarkKonsultLateYes,RemarkDeseaseVerifYes,
		RemarkDeseaseTimeYes,RemarkDeseaseContentYes,RemarkTherapyChooseDrYes,
		RemarkTherapyTimeAppointmentYes,RemarkTherapyPolypharmacyYes,
		ContinuityChoosePlaceYes,ContinuityTimeTransferYes,RemarkStandartMHYes;
};
//---------------------------------------------------------------------------
extern PACKAGE TFStatReport *FStatReport;
//---------------------------------------------------------------------------
#endif
