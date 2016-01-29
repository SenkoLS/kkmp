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
//---------------------------------------------------------------------------
class TFDictionaryMed : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TLabel *LSurname;
	TLabel *LName;
	TLabel *LPatronymic;
	TEdit *ESurname;
	TEdit *EName;
	TEdit *EOtch;
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
	void __fastcall ESurnameExit(TObject *Sender);
	void __fastcall ENameExit(TObject *Sender);
	void __fastcall EOtchExit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFDictionaryMed(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDictionaryMed *FDictionaryMed;
//---------------------------------------------------------------------------
#endif
