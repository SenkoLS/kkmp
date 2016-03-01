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
	TDBGridEh *DBGridEh1;
	TButton *BGenerateReport;
	void __fastcall ChBoxOfficeClick(TObject *Sender);
	void __fastcall ChBoxExpertClick(TObject *Sender);
	void __fastcall ChBoxMedClick(TObject *Sender);
	void __fastcall BGenerateReportClick(TObject *Sender);
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
		DeadlinesVN;
};
//---------------------------------------------------------------------------
extern PACKAGE TFStatReport *FStatReport;
//---------------------------------------------------------------------------
#endif
