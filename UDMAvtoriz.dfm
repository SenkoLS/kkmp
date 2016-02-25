object DMAvtoriz: TDMAvtoriz
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 647
  Width = 609
  object SQLQAvtoriz: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      'SELECT * FROM user'
      'where id_user='#39'admin'#39)
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 24
  end
  object DSPAvtoriz: TDataSetProvider
    DataSet = SQLQAvtoriz
    Left = 248
    Top = 24
  end
  object CDSAvtoriz: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPAvtoriz'
    Left = 336
    Top = 24
  end
  object DSAvtoriz: TDataSource
    DataSet = CDSAvtoriz
    Left = 424
    Top = 24
  end
  object SQLConnectKKMP: TSQLConnection
    DriverName = 'DevartMySQL'
    GetDriverFunc = 'getSQLDriverMySQL'
    LibraryName = 'dbexpmda40.dll'
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=DbxDevartMySql'
      
        'DriverAssemblyLoader=Devart.DbxMda.DriverLoader.TCRDynalinkDrive' +
        'rLoader,Devart.DbxMda.DriverLoader,Version=15.0.0.1,Culture=neut' +
        'ral,PublicKeyToken=09af7300eec23701'
      
        'MetaDataAssemblyLoader=Devart.DbxMda.DriverLoader.TDBXDevartMySq' +
        'lMetaDataCommandFactory,Devart.DbxMda.DriverLoader,Version=15.0.' +
        '0.1,Culture=neutral,PublicKeyToken=09af7300eec23701'
      
        'DriverPackageLoader=TDBXDynalinkDriverLoader,DBXCommonDriver150.' +
        'bpl'
      
        'MetaDataPackageLoader=TDBXDevartMySqlMetaDataCommandFactory,DbxD' +
        'evartMySqlDriver150.bpl'
      'ProductName=DevartMySQL'
      'GetDriverFunc=getSQLDriverMySQL'
      'LibraryName=dbexpmda40.dll'
      'VendorLib=libmysql.dll'
      'MaxBlobSize=-1'
      'FetchAll=True'
      'EnableBoolean=False'
      'UseUnicode=True'
      'IPVersion=IPv4'
      'Database=kkmp'
      'User_Name=root'
      'Password=root')
    VendorLib = 'libmysql.dll'
    Left = 56
    Top = 24
  end
  object SQLQCatalogMed: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `user`.`id_user`,`surname`,`name`,`patronymic`,`login`,`n' +
        'ame_office`'
      'FROM `user` INNER JOIN `office`'
      'ON `user`.`id_office` = `office`.`id_office`')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 80
  end
  object DSPCatalogMed: TDataSetProvider
    DataSet = SQLQCatalogMed
    Left = 248
    Top = 80
  end
  object CDSCatalogMed: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPCatalogMed'
    Left = 336
    Top = 80
  end
  object DSCatalogMed: TDataSource
    DataSet = CDSCatalogMed
    Left = 424
    Top = 80
  end
  object SQLQInspection: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `id_inspection`,`date_start`,`date_end`,`duration`,CONCAT' +
        '(`surname`,'#39' '#39',`name`,'#39' '#39',`patronymic`) as `fio`,'
      '`year_date_birthday`,`id_user`,`kkmp`,`kvo`,`id_expert`'
      'FROM `inspection`'
      
        'WHERE `date_start` BETWEEN CONCAT(YEAR(NOW()),'#39'-01-01'#39') AND NOW(' +
        ')'
      'ORDER BY `id_inspection` DESC')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 168
  end
  object DSPInspection: TDataSetProvider
    DataSet = SQLQInspection
    Left = 248
    Top = 168
  end
  object CDSInspection: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPInspection'
    Left = 336
    Top = 168
  end
  object DSInspection: TDataSource
    DataSet = CDSInspection
    Left = 424
    Top = 168
  end
  object SQLQCatalogOffices: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `office`.`id_office`,`office`.`name_office`, CONCAT(`user' +
        '`.`surname`,'#39' '#39',`user`.`name`,'#39' '#39',`user`.`patronymic`) as `fio`'
      'FROM `user` INNER JOIN `office` '
      'ON `office`.`id_user` = user.`id_user`'
      'WHERE `office`.`id_office` !=1')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 232
  end
  object DSPCatalogOffices: TDataSetProvider
    DataSet = SQLQCatalogOffices
    Left = 264
    Top = 232
  end
  object CDSCatalogOffices: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPCatalogOffices'
    Left = 360
    Top = 232
  end
  object DSCatalogOffices: TDataSource
    DataSet = CDSCatalogOffices
    Left = 464
    Top = 232
  end
  object SQLQgetListOffice: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      'SELECT * FROM `office`')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 296
  end
  object DSPgetListOffice: TDataSetProvider
    DataSet = SQLQgetListOffice
    Left = 264
    Top = 296
  end
  object CDSgetListOffice: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPgetListOffice'
    Left = 360
    Top = 296
  end
  object DSgetListOffice: TDataSource
    DataSet = CDSgetListOffice
    Left = 464
    Top = 296
  end
  object SQLQGetListMed: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `id_user`, CONCAT(`surname`,'#39' '#39',`name`,'#39' '#39',`patronymic`) ' +
        'as `fio`'
      'FROM `user`  WHERE `id_user` != 2 AND `id_user` != 1'
      'ORDER BY `fio` ASC')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 368
  end
  object DSPGetListMed: TDataSetProvider
    DataSet = SQLQGetListMed
    Left = 264
    Top = 368
  end
  object CDSGetListMed: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPGetListMed'
    Left = 360
    Top = 368
  end
  object DSGetListMed: TDataSource
    DataSet = CDSGetListMed
    Left = 464
    Top = 368
  end
  object SQLQCard: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `id_user`, CONCAT(`surname`,'#39' '#39',`name`,'#39' '#39',`patronymic`) ' +
        'as `fio` FROM `user` WHERE `id_user` != 1')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 440
  end
  object DSPCard: TDataSetProvider
    DataSet = SQLQCard
    Left = 264
    Top = 440
  end
  object CDSCard: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPCard'
    Left = 360
    Top = 440
  end
  object DSCard: TDataSource
    DataSet = CDSCard
    Left = 464
    Top = 440
  end
  object SQLQGetListMedStat: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      
        'SELECT `id_user`, CONCAT(`surname`,'#39' '#39',`name`,'#39' '#39',`patronymic`) ' +
        'as `fio`'
      'FROM `user`  WHERE `id_user` != 2 AND `id_user` != 1'
      'ORDER BY `fio` ASC')
    SQLConnection = SQLConnectKKMP
    Left = 160
    Top = 520
  end
  object DSPGetListMedStat: TDataSetProvider
    DataSet = SQLQGetListMedStat
    Left = 264
    Top = 520
  end
  object CDSGetListMedStat: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPGetListMedStat'
    Left = 360
    Top = 520
  end
  object DSGetListMedStat: TDataSource
    DataSet = CDSGetListMedStat
    Left = 464
    Top = 520
  end
end
