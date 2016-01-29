//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UDictionaryMed.cpp", FDictionaryMed);
USEFORM("UDMAvtoriz.cpp", DMAvtoriz); /* TDataModule: File Type */
USEFORM("UMain.cpp", FMain);
USEFORM("UAvtoriz.cpp", FAvtoriz);
USEFORM("UAbout.cpp", FAbout);
USEFORM("UCard.cpp", FCard);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Управление качество МП";
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->CreateForm(__classid(TFAvtoriz), &FAvtoriz);
		Application->CreateForm(__classid(TDMAvtoriz), &DMAvtoriz);
		Application->CreateForm(__classid(TFAbout), &FAbout);
		Application->CreateForm(__classid(TFDictionaryMed), &FDictionaryMed);
		Application->CreateForm(__classid(TFCard), &FCard);
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
