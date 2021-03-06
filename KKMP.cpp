//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UDictionaryMed.cpp", FDictionaryMed);
USEFORM("UCatalogOffices.cpp", FCatalogOffices);
USEFORM("UMain.cpp", FMain);
USEFORM("UDMAvtoriz.cpp", DMAvtoriz); /* TDataModule: File Type */
USEFORM("UCard.cpp", FCard);
USEFORM("UAvtoriz.cpp", FAvtoriz);
USEFORM("UAbout.cpp", FAbout);
USEFORM("UStatReport.cpp", FStatReport);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "���������� �������� ��";
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->CreateForm(__classid(TFAvtoriz), &FAvtoriz);
		Application->CreateForm(__classid(TDMAvtoriz), &DMAvtoriz);
		Application->CreateForm(__classid(TFAbout), &FAbout);
		Application->CreateForm(__classid(TFDictionaryMed), &FDictionaryMed);
		Application->CreateForm(__classid(TFCard), &FCard);
		Application->CreateForm(__classid(TFCatalogOffices), &FCatalogOffices);
		Application->CreateForm(__classid(TFStatReport), &FStatReport);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
