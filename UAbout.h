//---------------------------------------------------------------------------

#ifndef UAboutH
#define UAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFAbout : public TForm
{
__published:	// IDE-managed Components
	TLabel *LNameLisence;
	TLabel *LPhoneNum;
	TLabel *LCompany;
	TLabel *LNamePr;
	TLabel *LBuildTime;
private:	// User declarations
public:		// User declarations
	__fastcall TFAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAbout *FAbout;
//---------------------------------------------------------------------------
#endif
