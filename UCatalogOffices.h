//---------------------------------------------------------------------------

#ifndef UCatalogOfficesH
#define UCatalogOfficesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDMAvtoriz.h"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <DBCtrls.hpp>
#include "UDictionaryMed.h"
//---------------------------------------------------------------------------
class TFCatalogOffices : public TForm
{
__published:	// IDE-managed Components
	TDBGridEh *DBGrCatalogOffices;
	TLabel *LNameOffice;
	TLabel *LAddMed;
	TEdit *ENameOffice;
	TButton *NAddOffice;
	TButton *BEditNameOffice;
	TButton *BDeleteOffice;
	TDBLookupComboBox *DBLookupComboBoxChief;
	TButton *BAddMed;
	TButton *BSafeRecord;
	TButton *BCancel;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BAddMedClick(TObject *Sender);
	void __fastcall NAddOfficeClick(TObject *Sender);
	void __fastcall BSafeRecordClick(TObject *Sender);
	void __fastcall BEditNameOfficeClick(TObject *Sender);
	void __fastcall BDeleteOfficeClick(TObject *Sender);
	void __fastcall BCancelClick(TObject *Sender);
	void __fastcall DBLookupComboBoxChiefEnter(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFCatalogOffices(TComponent* Owner);
	TTransactionDesc trans;
	int chooseSafe;  //It's for choose method update or insert
};
//---------------------------------------------------------------------------
extern PACKAGE TFCatalogOffices *FCatalogOffices;
//---------------------------------------------------------------------------
#endif
