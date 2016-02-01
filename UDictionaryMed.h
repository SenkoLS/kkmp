//---------------------------------------------------------------------------

#ifndef UDictionaryMedH
#define UDictionaryMedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <ExtCtrls.hpp>
#include "UDMAvtoriz.h"
#include <DBCtrls.hpp>
#include "UAvtoriz.h"
//---------------------------------------------------------------------------
class TFDictionaryMed : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TLabel *LSurname;
	TLabel *LName;
	TLabel *LPatronymic;
	TEdit *EOtch;
	TEdit *EName;
	TEdit *ESurname;
	TButton *BAdd;
	TButton *BEdit;
	TButton *BDelete;
	TDBGridEh *DBGrCatalogMed;
	TLabel *LLogin;
	TLabel *LPassword;
	TLabel *LOffice;
	TEdit *ELogin;
	TEdit *EPassword;
	TDBLookupComboBox *DBLookupComboBoxOffice;
	TButton *BSafeMed;
	TButton *BCancel;
	void __fastcall EOtchExit(TObject *Sender);
	void __fastcall ENameExit(TObject *Sender);
	void __fastcall ESurnameExit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BAddClick(TObject *Sender);
	void __fastcall BEditClick(TObject *Sender);
	void __fastcall BCancelClick(TObject *Sender);
	void __fastcall BSafeMedClick(TObject *Sender);
	void __fastcall BDeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFDictionaryMed(TComponent* Owner);
	void __fastcall TFDictionaryMed::setView();

	TTransactionDesc trans;
	int chooseSafe;  //It's for choose method update or insert
	AnsiString __fastcall TFDictionaryMed::getStrValue(AnsiString val);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDictionaryMed *FDictionaryMed;
//---------------------------------------------------------------------------
#endif
