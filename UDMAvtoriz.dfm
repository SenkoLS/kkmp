object DMAvtoriz: TDMAvtoriz
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 511
  Width = 616
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
      'HostName=localhost'
      'Password=root')
    VendorLib = 'libmysql.dll'
    Connected = True
    Left = 56
    Top = 24
  end
  object SQLQCatalogMed: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQL.Strings = (
      'SELECT `surname`,`name`,`patronymic`,`login` FROM `user`')
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
      
        'SELECT `type_med_help`,`date_start`,`date_end`,CONCAT(surname,'#39' ' +
        #39',name,'#39' '#39',patronymic) as `fio`,'
      '`date_birthday`,`number_card`,`id_med`,`kkmp`,`kvo`'
      'FROM `inspection`')
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
end