//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UAvtoriz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAvtoriz *FAvtoriz;
//---------------------------------------------------------------------------
__fastcall TFAvtoriz::TFAvtoriz(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

String __fastcall MD5(const String Text)
{
  String result;
  TIdHashMessageDigest5 *idmd5 = new TIdHashMessageDigest5();
  try {
    result = idmd5->HashStringAsHex(Text);
  }
  __finally {
    delete idmd5;
  }
  return result.UpperCase();
}

//---------------------------------------------------------------------------
void __fastcall TFAvtoriz::BEnterClick(TObject *Sender)
{
	try{
		AnsiString query_avtoriz = "SELECT `id_user` FROM `user` WHERE `login`='"+ELogin->Text+"' AND `password`='"+MD5(EPassword->Text)+"'";
		DMAvtoriz->SQLQAvtoriz->Close();
		DMAvtoriz->CDSAvtoriz->Close();
		DMAvtoriz->SQLQAvtoriz->SQL->Text = query_avtoriz;
		DMAvtoriz->SQLQAvtoriz->Open();
		DMAvtoriz->CDSAvtoriz->Open();

		if (DMAvtoriz->DSAvtoriz->DataSet->IsEmpty()) {
			MessageBox(0,L"�������� ����� ��� ������!",L"������ �����������",MB_OK);
		}else{
			FAvtoriz->Close();
		}
	}catch(...){
		MessageBox(0,L"������ � ������� �� �����������!\n���������� � ������������.",L"������",MB_OK);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAvtoriz::ELoginKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	switch  (Key){
		case 13: EPassword->SetFocus();
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAvtoriz::EPasswordKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	switch  (Key){
		case 13: BEnterClick(Sender);
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFAvtoriz::BExitClick(TObject *Sender)
{
	FAvtoriz->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
