//---------------------------------------------------------------------------

#ifndef UDMAvtorizH
#define UDMAvtorizH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <SqlExpr.hpp>
#include <IniFiles.hpp>
#include "DbxDevartMySql.hpp"
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <DBXMySQL.hpp>

//---------------------------------------------------------------------------
class TDMAvtoriz : public TDataModule
{
__published:	// IDE-managed Components
	TSQLQuery *SQLQAvtoriz;
	TDataSetProvider *DSPAvtoriz;
	TClientDataSet *CDSAvtoriz;
	TDataSource *DSAvtoriz;
	TSQLConnection *SQLConnectKKMP;
	TSQLQuery *SQLQCatalogMed;
	TDataSetProvider *DSPCatalogMed;
	TClientDataSet *CDSCatalogMed;
	TDataSource *DSCatalogMed;
	TSQLQuery *SQLQInspection;
	TDataSetProvider *DSPInspection;
	TClientDataSet *CDSInspection;
	TDataSource *DSInspection;
	TSQLQuery *SQLQCatalogOffices;
	TDataSetProvider *DSPCatalogOffices;
	TClientDataSet *CDSCatalogOffices;
	TDataSource *DSCatalogOffices;
	TSQLQuery *SQLQgetListOffice;
	TDataSetProvider *DSPgetListOffice;
	TClientDataSet *CDSgetListOffice;
	TDataSource *DSgetListOffice;
	TSQLQuery *SQLQGetListMed;
	TDataSetProvider *DSPGetListMed;
	TClientDataSet *CDSGetListMed;
	TDataSource *DSGetListMed;
	TSQLQuery *SQLQCard;
	TDataSetProvider *DSPCard;
	TClientDataSet *CDSCard;
	TDataSource *DSCard;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMAvtoriz(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMAvtoriz *DMAvtoriz;
//---------------------------------------------------------------------------
#endif
