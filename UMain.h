//---------------------------------------------------------------------------

#ifndef UMainH
#define UMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UAvtoriz.h"
#include "UDMAvtoriz.h"
#include <Menus.hpp>
#include "UAbout.h"
#include "UDictionaryMed.h"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <ExtCtrls.hpp>
#include "UCard.h"
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *NewCard;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TPanel *Panel1;
	TDBGridEh *DBGridEh1;
	TButton *BShowCard;
	TPanel *Panel2;
	TLabel *LSortList;
	TButton *BSortFio;
	TButton *BSortDateEnd;
	TButton *BSortDuration;
	TButton *BShowAll;
	TButton *BShowAm;
	TButton *BShowSDP;
	TPanel *Panel3;
	TLabel *LFindInList;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EFindFio;
	TEdit *EFindNumCard;
	TEdit *EFindMed;
	TPanel *Panel4;
	TButton *BExportProtocol;
	TButton *BPrintProtocol;
	TButton *BPrintList;
	TButton *BDeleteCard;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall NewCardClick(TObject *Sender);
	void __fastcall DBGridEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TFMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
