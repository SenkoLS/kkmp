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

	int VuluntarMedAgreementYes, AgreementPDNYes,
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
        // counters
		count1,count2,count3,count4,count5,count6,count7,count8,count9,
		count10,count11,count12,count13,count14,count15,count16,count17,count18,
		count19,count20,count21;
};
//---------------------------------------------------------------------------
extern PACKAGE TFStatReport *FStatReport;
//---------------------------------------------------------------------------
#endif
