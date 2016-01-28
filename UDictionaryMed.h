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
//---------------------------------------------------------------------------
class TFDictionaryMed : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TDBGridEh *DBGridEh1;
	TLabel *LSurname;
	TLabel *LName;
	TLabel *LOtch;
	TEdit *ESurname;
	TEdit *EName;
	TEdit *EOtch;
	TButton *BAdd;
	TButton *BEdit;
	TButton *BDelete;
	void __fastcall ESurnameExit(TObject *Sender);
	void __fastcall ENameExit(TObject *Sender);
	void __fastcall EOtchExit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFDictionaryMed(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDictionaryMed *FDictionaryMed;
//---------------------------------------------------------------------------
#endif
