object FCard: TFCard
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 
    #1069#1082#1089#1087#1077#1088#1090#1085#1072#1103' '#1086#1094#1077#1085#1082#1072' '#1082#1072#1095#1077#1089#1090#1074#1072' '#1074#1077#1076#1077#1085#1080#1103' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1081' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1094#1080#1080' '#1080' '#1082#1072 +
    #1095#1077#1089#1090#1074#1072' '#1086#1082#1072#1079#1072#1085#1080#1103' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1081' '#1087#1086#1084#1086#1097#1080' (1 '#1091#1088#1086#1074#1077#1085#1100')'
  ClientHeight = 726
  ClientWidth = 1013
  Color = clBtnFace
  Constraints.MaxHeight = 755
  Constraints.MaxWidth = 1019
  Constraints.MinHeight = 755
  Constraints.MinWidth = 1019
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1013
    Height = 74
    Align = alTop
    BorderStyle = bsSingle
    TabOrder = 0
    object Label12: TLabel
      Left = 8
      Top = 13
      Width = 93
      Height = 17
      Caption = #1053#1072#1073#1083#1102#1076#1077#1085#1080#1077' c:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 210
      Top = 13
      Width = 14
      Height = 17
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 871
      Top = 44
      Width = 57
      Height = 17
      Caption = #1059#1095#1072#1089#1090#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 8
      Top = 44
      Width = 56
      Height = 17
      Caption = #1055#1072#1094#1080#1077#1085#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsUnderline]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 778
      Top = 44
      Width = 25
      Height = 17
      Caption = #1043'.'#1088'.:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 535
      Top = 12
      Width = 34
      Height = 17
      Caption = #1042#1088#1072#1095':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 365
      Top = 13
      Width = 109
      Height = 17
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1085#1077#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LSurname: TLabel
      Left = 76
      Top = 44
      Width = 59
      Height = 17
      Caption = #1060#1072#1084#1080#1083#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LName: TLabel
      Left = 323
      Top = 44
      Width = 31
      Height = 17
      Caption = #1048#1084#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LPatronymic: TLabel
      Left = 504
      Top = 44
      Width = 64
      Height = 17
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object DTPDateStart: TDateTimePicker
      Left = 102
      Top = 10
      Width = 99
      Height = 23
      Date = 42395.380680243070000000
      Time = 42395.380680243070000000
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnCloseUp = DTPDateStartCloseUp
    end
    object DTPDateEnd: TDateTimePicker
      Left = 232
      Top = 10
      Width = 126
      Height = 23
      Date = 42395.381305312500000000
      Time = 42395.381305312500000000
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnCloseUp = DTPDateEndCloseUp
    end
    object PAmountOfDays: TPanel
      Left = 480
      Top = 10
      Width = 49
      Height = 22
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
    end
    object EArea: TEdit
      Left = 934
      Top = 40
      Width = 63
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object ESurname: TEdit
      Left = 141
      Top = 40
      Width = 176
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnExit = ESurnameExit
    end
    object EYearOfBirthday: TEdit
      Left = 809
      Top = 40
      Width = 56
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object DBLookupComboBoxListMed: TDBLookupComboBox
      Left = 575
      Top = 10
      Width = 422
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = []
      KeyField = 'id_user'
      ListField = 'fio'
      ListSource = DMAvtoriz.DSGetListMed
      ParentFont = False
      TabOrder = 3
    end
    object EName: TEdit
      Left = 360
      Top = 40
      Width = 138
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnExit = ENameExit
    end
    object EPatronymic: TEdit
      Left = 574
      Top = 40
      Width = 198
      Height = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnExit = EPatronymicExit
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 74
    Width = 553
    Height = 611
    Align = alLeft
    BorderStyle = bsSingle
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 4
      Width = 292
      Height = 17
      Caption = #1050#1072#1095#1077#1089#1090#1074#1086' '#1074#1077#1076#1077#1085#1080#1103' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1081' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1094#1080#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object SpBAllNoQuality: TSpeedButton
      Left = 505
      Top = 4
      Width = 33
      Height = 25
      Glyph.Data = {
        6A080000424D6A0800000000000036000000280000001C000000190000000100
        1800000000003408000000000000000000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFC9ECD858C386D4F0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4ECD60DAC4E009B33009A38DDF1
        E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFF7FDFA12B25400A6400DAC56009C3A1EA657D9F1E5FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF37C27000A43837BD71
        F5FBF828B26500912F38AC67EDF8F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF43C97E00AC3D25B760FAFEFCFFFFFFFFFFFF04A14A008B2A
        40AD6CF5FAF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF68D79A00B03D07
        B24CEBF8F2FFFFFFFFFFFFFFFFFFF2FAF614A25300862452B27AFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF78DDA500B64206B84FB7E9CDFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFCCEAD9149B4B0080217CC29AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFABEBC900B9
        4200B84899E2B9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB7E1C800
        872E00853292CDACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFB6EFD000C45100BC4984DFACFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4DFC8007A1E00812C9ED2B5FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEF5E0
        17CD6300BE406FDA9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF80C69F007D29007A2BAED6C1FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FCF927D47100C14046D483FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF66B78A00792800792CD3EADFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF1DD76F00C5443DD47AF3FCF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF44A56F0072202387
        49E1F0EAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3CDF8600CC4A2CD36FE3F9EEFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF249456006C1D398C55EFF7F4FFFFFFFFFF
        FFFFFFFF5CE79900D25324D770E2FAEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF1B894900671A4C9664FFFFFFFFFFFF90EEB800D75B00D6603BDC
        8293E7B47CE1A37BDFA37BDBA17BDAA17CD8A07CD6A07CD29E7CD19C7CCE9B7C
        CC9A7CC8997CC7987CC5977CC2957BBF947BBE927BBA928AC09C66AE83007530
        00621A77B291F9FEFC42E08200D24200D35300CB4800C33B00C14200C34E00BB
        4C00B53D00AA2F00A72E009E2B009B2900962700922300892100861F00811C00
        7F1F00873300822F00731E00660E00661400691E00621900611AFFFFFFE8FBEF
        AAF1C9A1F0C4A3EDC5BAF1D282E4AE09C85F00BD4E51D18BAEE7C7A3E4BFA4E2
        C0A4E0BEA4DFBDA2DDBDA4DCBCA3DABCADDDC176C49B007D24008A3D76BE97B7
        DBC6A2CFB6A3CDB596C5AAE9F3EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6FAEE
        2AD27100BE435ED794FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF74C095007D27008239C9E5D6FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FDFB31D67800C14037D179FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF5CB282007826007B2FDEEFE7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF2EDA7A00C54434D274EFFBF4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFDFC3DA2690072202B8C
        50E6F3EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF53E39400CB491ED066D7F6E5FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0D8945006D1F499563F9FDFCFFFFFFFFFF
        FFFFFFFF64E89E00D2531CD56ADAF8E8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF0B803B006618569C6CFFFFFFFFFFFF97EFBD00D85C00D65F44DD
        88A9ECC390E5B18FE4B18FE1B08FE0AF8FDEAE90DBAE90D8AC90D7AB90D5AA90
        D3A990D0A890CFA790CDA78FCBA48FC8A58FC8A38EC5A29FCBAE74B58F00742E
        00601785BA9CF9FEFC44E08300D24300D45500CB4800C33B00BF3900BB3700B3
        3400B03100AA2F00A62D009D2A009A2800952600912200882000851D00811B00
        7B18007515007113006B1100650C006615006A2000631B00621CFFFFFFE2F9EC
        ACF1C9A5F1C6A7EEC7A7EDC6A8ECC5A7E9C5A7E9C4A7E7C4A7E6C2A7E5C2A7E2
        C1A7E2C1A7DFC0A7DEBFA7DDBFA7DCBDA7D9BDA6D9BCA6D6BCA6D5BBA6D4BAA6
        D2BAA6D1B8A7CEB89CC7AEDFECE5}
      OnClick = SpBAllNoQualityClick
    end
    object Label18: TLabel
      Left = 8
      Top = 156
      Width = 258
      Height = 17
      Caption = #1050#1072#1095#1077#1089#1090#1074#1086' '#1086#1082#1072#1079#1072#1085#1080#1103' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1081' '#1087#1086#1084#1086#1097#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object PVuluntarMedAgreement: TPanel
      Left = 8
      Top = 35
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1053#1072#1083#1080#1095#1080#1077' '#1076#1086#1073#1088#1086#1074#1086#1083#1100#1085#1086#1075#1086' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1075#1086' '#1089#1086#1075#1083#1072#1089#1080#1103
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
    end
    object PAgreementPDN: TPanel
      Left = 8
      Top = 54
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1053#1072#1083#1080#1095#1080#1077' '#1089#1086#1075#1083#1072#1089#1080#1103' '#1087#1072#1094#1080#1077#1085#1090#1072' '#1085#1072' '#1086#1073#1088#1072#1073#1086#1090#1082#1091' '#1087#1077#1088#1089#1086#1085#1072#1083#1100#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
    object PComplitListDesease: TPanel
      Left = 8
      Top = 73
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1087#1086#1083#1085#1077#1085#1080#1077' '#1083#1080#1089#1090#1072' '#1091#1090#1086#1095#1085#1077#1085#1085#1099#1093' '#1076#1080#1072#1075#1085#1086#1079#1086#1074
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
    end
    object PCompitListProfAndStatus: TPanel
      Left = 8
      Top = 92
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1087#1086#1083#1085#1077#1085#1080#1077' '#1075#1088#1072#1092#1099' '#1087#1088#1086#1092#1077#1089#1089#1080#1103' '#1080' '#1089#1086#1094#1080#1072#1083#1100#1085#1099#1081' '#1089#1090#1072#1090#1091#1089
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
    end
    object PIntegrityCard: TPanel
      Left = 8
      Top = 111
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1062#1077#1083#1086#1089#1090#1085#1086#1089#1090#1100' '#1082#1072#1088#1090#1099
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 4
    end
    object PAccuracyHandwriting: TPanel
      Left = 8
      Top = 130
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1055#1086#1095#1077#1088#1082', '#1072#1082#1082#1091#1088#1072#1090#1085#1086#1089#1090#1100' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1103
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 5
    end
    object PExistenceFLG: TPanel
      Left = 8
      Top = 179
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1053#1072#1083#1080#1095#1080#1077' '#1060#1051#1043' ('#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1080#1083#1080' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 6
    end
    object PExistenceInspGin: TPanel
      Left = 8
      Top = 202
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1053#1072#1083#1080#1095#1080#1077' '#1086#1089#1084#1086#1090#1088#1086#1074' '#1075#1080#1085#1077#1082#1086#1083#1086#1075#1072' ('#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1080#1083#1080' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 7
    end
    object PQualityProfInsOnko: TPanel
      Left = 8
      Top = 225
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1050#1072#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103' '#1087#1088#1086#1092'. '#1086#1082#1085#1086#1083#1086#1075#1080#1095#1077#1089#1082#1086#1075#1086' '#1086#1089#1084#1086#1090#1088#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 8
    end
    object PDispTimelines: TPanel
      Left = 8
      Top = 247
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1044#1080#1089#1087#1072#1085#1077#1089#1088#1080#1079#1072#1094#1080#1103' ('#1089#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100' '#1080' '#1082#1072#1095#1077#1089#1090#1074#1086')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 9
    end
    object PQualityCollectAnamsis: TPanel
      Left = 8
      Top = 270
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1050#1072#1095#1077#1089#1090#1074#1086' '#1089#1073#1086#1088#1072' '#1072#1085#1072#1084#1085#1072#1079#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 10
    end
    object PQualityCollectComplaint: TPanel
      Left = 8
      Top = 293
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1050#1072#1095#1077#1089#1090#1074#1086' '#1089#1073#1086#1088#1072' '#1078#1072#1083#1086#1073
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 11
    end
    object PVuluntarMedAgreementNo: TPanel
      Left = 472
      Top = 35
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 12
      OnClick = PVuluntarMedAgreementNoClick
    end
    object PVuluntarMedAgreementYes: TPanel
      Left = 505
      Top = 35
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 13
      OnClick = PVuluntarMedAgreementYesClick
    end
    object PAgreementPDNNo: TPanel
      Left = 472
      Top = 54
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 14
      OnClick = PAgreementPDNNoClick
    end
    object PComplitListDeseaseNo: TPanel
      Left = 472
      Top = 73
      Width = 33
      Height = 19
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 15
      OnClick = PComplitListDeseaseNoClick
    end
    object PCompitListProfAndStatusNo: TPanel
      Left = 472
      Top = 92
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 16
      OnClick = PCompitListProfAndStatusNoClick
    end
    object PIntegrityCard1: TPanel
      Left = 376
      Top = 111
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 17
      OnClick = PIntegrityCard1Click
    end
    object PAccuracyHandwriting1: TPanel
      Left = 376
      Top = 130
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 18
      OnClick = PAccuracyHandwriting1Click
    end
    object PIntegrityCard3: TPanel
      Left = 440
      Top = 111
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 19
      OnClick = PIntegrityCard3Click
    end
    object PIntegrityCard5: TPanel
      Left = 505
      Top = 111
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 20
      OnClick = PIntegrityCard5Click
    end
    object PAccuracyHandwriting4: TPanel
      Left = 472
      Top = 130
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 21
      OnClick = PAccuracyHandwriting4Click
    end
    object PExistenceFLGNo: TPanel
      Left = 472
      Top = 179
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 22
      OnClick = PExistenceFLGNoClick
    end
    object PExistenceInspGinNo: TPanel
      Left = 472
      Top = 202
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 23
      OnClick = PExistenceInspGinNoClick
    end
    object PQualityProfInsOnko1: TPanel
      Left = 376
      Top = 225
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 24
      OnClick = PQualityProfInsOnko1Click
    end
    object PAgreementPDNYes: TPanel
      Left = 505
      Top = 54
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 25
      OnClick = PAgreementPDNYesClick
    end
    object PComplitListDeseaseYes: TPanel
      Left = 505
      Top = 73
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 26
      OnClick = PComplitListDeseaseYesClick
    end
    object PCompitListProfAndStatusYes: TPanel
      Left = 505
      Top = 92
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 27
      OnClick = PCompitListProfAndStatusYesClick
    end
    object PIntegrityCard2: TPanel
      Left = 408
      Top = 111
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 28
      OnClick = PIntegrityCard2Click
    end
    object PAccuracyHandwriting2: TPanel
      Left = 408
      Top = 130
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 29
      OnClick = PAccuracyHandwriting2Click
    end
    object PIntegrityCard4: TPanel
      Left = 472
      Top = 111
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 30
      OnClick = PIntegrityCard4Click
    end
    object PAccuracyHandwriting3: TPanel
      Left = 440
      Top = 130
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 31
      OnClick = PAccuracyHandwriting3Click
    end
    object PAccuracyHandwriting5: TPanel
      Left = 505
      Top = 130
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 32
      OnClick = PAccuracyHandwriting5Click
    end
    object PExistenceFLGYes: TPanel
      Left = 505
      Top = 179
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 33
      OnClick = PExistenceFLGYesClick
    end
    object PExistenceInspGinYes: TPanel
      Left = 505
      Top = 202
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 34
      OnClick = PExistenceInspGinYesClick
    end
    object PQualityProfInsOnko2: TPanel
      Left = 408
      Top = 225
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 35
      OnClick = PQualityProfInsOnko2Click
    end
    object PDescriptObjectStatus: TPanel
      Left = 8
      Top = 316
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1086#1073#1098#1077#1082#1090#1080#1074#1085#1086#1075#1086' '#1089#1090#1072#1090#1091#1089#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 36
    end
    object PEvaluationResultsOfTreatment: TPanel
      Left = 8
      Top = 339
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1054#1094#1077#1085#1082#1072' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1083#1077#1095#1077#1085#1080#1103
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 37
    end
    object PObservStandartsOfDiagnostics: TPanel
      Left = 8
      Top = 362
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1057#1086#1073#1083#1102#1076#1077#1085#1080#1077' '#1089#1090#1072#1085#1076#1072#1088#1090#1086#1074' '#1074' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1077
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 38
    end
    object PObservStandartsOfTreatment: TPanel
      Left = 8
      Top = 385
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1057#1086#1073#1083#1102#1076#1077#1085#1080#1077' '#1089#1090#1072#1085#1076#1072#1088#1090#1086#1074' '#1074' '#1083#1077#1095#1077#1085#1080#1080
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 39
    end
    object PDispTimelines5: TPanel
      Left = 505
      Top = 247
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 40
      OnClick = PDispTimelines5Click
    end
    object PDispTimelines2: TPanel
      Left = 408
      Top = 247
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 41
      OnClick = PDispTimelines2Click
    end
    object PDispTimelines3: TPanel
      Left = 440
      Top = 247
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 42
      OnClick = PDispTimelines3Click
    end
    object PDispTimelines1: TPanel
      Left = 376
      Top = 247
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 43
      OnClick = PDispTimelines1Click
    end
    object PQualityProfInsOnko3: TPanel
      Left = 440
      Top = 225
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 44
      OnClick = PQualityProfInsOnko3Click
    end
    object PQualityProfInsOnko4: TPanel
      Left = 472
      Top = 225
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 45
      OnClick = PQualityProfInsOnko4Click
    end
    object PDispTimelines4: TPanel
      Left = 472
      Top = 247
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 46
      OnClick = PDispTimelines4Click
    end
    object PQualityProfInsOnko5: TPanel
      Left = 505
      Top = 225
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 47
      OnClick = PQualityProfInsOnko5Click
    end
    object PQualityCollectComplaint3: TPanel
      Left = 440
      Top = 293
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 48
      OnClick = PQualityCollectComplaint3Click
    end
    object PQualityCollectComplaint5: TPanel
      Left = 505
      Top = 293
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 49
      OnClick = PQualityCollectComplaint5Click
    end
    object PDescriptObjectStatus1: TPanel
      Left = 376
      Top = 316
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 50
      OnClick = PDescriptObjectStatus1Click
    end
    object PQualityCollectComplaint4: TPanel
      Left = 472
      Top = 293
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 51
      OnClick = PQualityCollectComplaint4Click
    end
    object PQualityCollectComplaint2: TPanel
      Left = 408
      Top = 293
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 52
      OnClick = PQualityCollectComplaint2Click
    end
    object PDescriptObjectStatus2: TPanel
      Left = 408
      Top = 316
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 53
      OnClick = PDescriptObjectStatus2Click
    end
    object PQualityCollectAnamsis1: TPanel
      Left = 376
      Top = 270
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 54
      OnClick = PQualityCollectAnamsis1Click
    end
    object PQualityCollectAnamsis2: TPanel
      Left = 408
      Top = 270
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 55
      OnClick = PQualityCollectAnamsis2Click
    end
    object PQualityCollectAnamsis3: TPanel
      Left = 440
      Top = 270
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 56
      OnClick = PQualityCollectAnamsis3Click
    end
    object PQualityCollectAnamsis4: TPanel
      Left = 472
      Top = 270
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 57
      OnClick = PQualityCollectAnamsis4Click
    end
    object PQualityCollectComplaint1: TPanel
      Left = 376
      Top = 293
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 58
      OnClick = PQualityCollectComplaint1Click
    end
    object PDescriptObjectStatus3: TPanel
      Left = 440
      Top = 316
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 59
      OnClick = PDescriptObjectStatus3Click
    end
    object PQualityCollectAnamsis5: TPanel
      Left = 505
      Top = 270
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 60
      OnClick = PQualityCollectAnamsis5Click
    end
    object PDescriptObjectStatus4: TPanel
      Left = 472
      Top = 316
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 61
      OnClick = PDescriptObjectStatus4Click
    end
    object PDescriptObjectStatus5: TPanel
      Left = 505
      Top = 316
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 62
      OnClick = PDescriptObjectStatus5Click
    end
    object PEvaluationResultsOfTreatment1: TPanel
      Left = 376
      Top = 339
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 63
      OnClick = PEvaluationResultsOfTreatment1Click
    end
    object PEvaluationResultsOfTreatment5: TPanel
      Left = 505
      Top = 339
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 64
      OnClick = PEvaluationResultsOfTreatment5Click
    end
    object PEvaluationResultsOfTreatment2: TPanel
      Left = 408
      Top = 339
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 65
      OnClick = PEvaluationResultsOfTreatment2Click
    end
    object PObservStandartsOfDiagnostics1: TPanel
      Left = 376
      Top = 362
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 66
      OnClick = PObservStandartsOfDiagnostics1Click
    end
    object PObservStandartsOfDiagnostics2: TPanel
      Left = 408
      Top = 362
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 67
      OnClick = PObservStandartsOfDiagnostics2Click
    end
    object PObservStandartsOfDiagnostics4: TPanel
      Left = 472
      Top = 362
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 68
      OnClick = PObservStandartsOfDiagnostics4Click
    end
    object PObservStandartsOfDiagnostics3: TPanel
      Left = 440
      Top = 362
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 69
      OnClick = PObservStandartsOfDiagnostics3Click
    end
    object PEvaluationResultsOfTreatment3: TPanel
      Left = 440
      Top = 339
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 70
      OnClick = PEvaluationResultsOfTreatment3Click
    end
    object PEvaluationResultsOfTreatment4: TPanel
      Left = 472
      Top = 339
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 71
      OnClick = PEvaluationResultsOfTreatment4Click
    end
    object PObservStandartsOfDiagnostics5: TPanel
      Left = 505
      Top = 362
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 72
      OnClick = PObservStandartsOfDiagnostics5Click
    end
    object PObservStandartsOfTreatment1: TPanel
      Left = 376
      Top = 385
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 73
      OnClick = PObservStandartsOfTreatment1Click
    end
    object PAbsenceComplaintsOfPatients: TPanel
      Left = 8
      Top = 431
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1054#1090#1089#1091#1090#1089#1090#1074#1080#1077' '#1078#1072#1083#1086#1073' '#1087#1072#1094#1080#1077#1085#1090#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 74
    end
    object PRationalUseOfResourcesNo: TPanel
      Left = 472
      Top = 408
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 75
      OnClick = PRationalUseOfResourcesNoClick
    end
    object PObservStandartsOfTreatment4: TPanel
      Left = 472
      Top = 385
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 76
      OnClick = PObservStandartsOfTreatment4Click
    end
    object PObservStandartsOfTreatment5: TPanel
      Left = 505
      Top = 385
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 77
      OnClick = PObservStandartsOfTreatment5Click
    end
    object PRationalUseOfResources: TPanel
      Left = 8
      Top = 408
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1056#1072#1094#1080#1086#1085#1072#1083#1100#1085#1086#1089#1090#1100' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1103' '#1088#1077#1089#1091#1088#1089#1086#1074
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 78
    end
    object PObservStandartsOfTreatment2: TPanel
      Left = 408
      Top = 385
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 79
      OnClick = PObservStandartsOfTreatment2Click
    end
    object PObservStandartsOfTreatment3: TPanel
      Left = 440
      Top = 385
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 80
      OnClick = PObservStandartsOfTreatment3Click
    end
    object PRationalUseOfResourcesYes: TPanel
      Left = 505
      Top = 408
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 81
      OnClick = PRationalUseOfResourcesYesClick
    end
    object PAbsenceComplaintsOfPatientsYes: TPanel
      Left = 505
      Top = 431
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 82
      OnClick = PAbsenceComplaintsOfPatientsYesClick
    end
    object PDeadlinesVN: TPanel
      Left = 8
      Top = 454
      Width = 369
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1057#1086#1073#1083#1102#1076#1077#1085#1080#1077' '#1089#1088#1086#1082#1086#1074' '#1042#1053' ('#1087#1088#1080' '#1085#1072#1083#1080#1095#1080#1080')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 83
    end
    object PAbsenceComplaintsOfPatientsNo: TPanel
      Left = 472
      Top = 431
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 84
      OnClick = PAbsenceComplaintsOfPatientsNoClick
    end
    object PDeadlinesVN3: TPanel
      Left = 440
      Top = 454
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '3'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 85
    end
    object PDeadlinesVN2: TPanel
      Left = 408
      Top = 454
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '2'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 86
    end
    object PDeadlinesVN1: TPanel
      Left = 376
      Top = 454
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '1'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 87
    end
    object PRefferalToVK: TPanel
      Left = 8
      Top = 500
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1057#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1085#1072' '#1042#1050' ('#1087#1088#1080' '#1085#1072#1083#1080#1095#1080#1080')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 88
    end
    object PTimelyRegistLN: TPanel
      Left = 8
      Top = 477
      Width = 465
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1057#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100' '#1086#1092#1086#1088#1084#1083#1077#1085#1080#1103' '#1051#1053' ('#1087#1088#1080' '#1085#1072#1083#1080#1095#1080#1080')'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 89
    end
    object PTimelyRegistLNNo: TPanel
      Left = 472
      Top = 477
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 90
    end
    object PDeadlinesVN5: TPanel
      Left = 505
      Top = 454
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '5'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 91
    end
    object PRefferalToVKNo: TPanel
      Left = 472
      Top = 500
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 92
    end
    object PTimelyRegistLNYes: TPanel
      Left = 505
      Top = 477
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 93
    end
    object PDeadlinesVN4: TPanel
      Left = 472
      Top = 454
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = '4'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 94
    end
    object PRefferalToVKYes: TPanel
      Left = 505
      Top = 500
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 95
    end
    object PKKMP: TPanel
      Left = 440
      Top = 577
      Width = 98
      Height = 20
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 96
    end
  end
  object Panel3: TPanel
    Left = 567
    Top = 74
    Width = 446
    Height = 611
    Align = alRight
    Alignment = taLeftJustify
    BorderStyle = bsSingle
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 4
      Width = 197
      Height = 17
      Caption = #1069#1082#1089#1087#1077#1088#1090#1080#1079#1072' '#1074#1088#1072#1095#1077#1073#1085#1099#1093' '#1086#1096#1080#1073#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 27
      Width = 407
      Height = 15
      Caption = 
        #1053#1077#1087#1086#1089#1088#1077#1076#1089#1090#1074#1077#1085#1085#1099#1077' '#1080#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103' ('#1080#1085#1092#1086#1088#1084#1072#1090#1080#1074#1085#1086#1089#1090#1100', '#1089#1086#1076#1077#1088#1078#1072#1090#1077#1083#1100#1085#1086#1089#1090#1100 +
        '):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 110
      Width = 234
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1083#1072#1073#1086#1088#1072#1090#1086#1088#1085#1086#1081' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 8
      Top = 191
      Width = 260
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1072#1083#1100#1085#1086#1081' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 8
      Top = 270
      Width = 246
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1082#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103#1084' '#1089#1087#1077#1094#1080#1072#1083#1080#1089#1090#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 8
      Top = 326
      Width = 134
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1076#1080#1072#1075#1085#1086#1079#1091':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 8
      Top = 400
      Width = 238
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1083#1077#1095#1077#1085#1080#1102' ('#1092#1072#1088#1084#1072#1082#1086#1090#1077#1088#1072#1087#1080#1080'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 8
      Top = 479
      Width = 101
      Height = 15
      Caption = #1055#1088#1077#1077#1084#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 8
      Top = 534
      Width = 216
      Height = 15
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1089#1090#1072#1085#1076#1072#1088#1090#1091' '#1086#1082#1072#1079#1072#1085#1080#1103' '#1052#1055':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14090240
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 8
      Top = 580
      Width = 137
      Height = 15
      Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1081' '#1073#1072#1083#1083' = 1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = [fsItalic, fsUnderline]
      ParentFont = False
    end
    object SpBAllNo: TSpeedButton
      Left = 400
      Top = 4
      Width = 33
      Height = 25
      Glyph.Data = {
        6A080000424D6A0800000000000036000000280000001C000000190000000100
        1800000000003408000000000000000000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFC9ECD858C386D4F0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4ECD60DAC4E009B33009A38DDF1
        E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFF7FDFA12B25400A6400DAC56009C3A1EA657D9F1E5FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF37C27000A43837BD71
        F5FBF828B26500912F38AC67EDF8F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF43C97E00AC3D25B760FAFEFCFFFFFFFFFFFF04A14A008B2A
        40AD6CF5FAF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF68D79A00B03D07
        B24CEBF8F2FFFFFFFFFFFFFFFFFFF2FAF614A25300862452B27AFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF78DDA500B64206B84FB7E9CDFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFCCEAD9149B4B0080217CC29AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFABEBC900B9
        4200B84899E2B9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB7E1C800
        872E00853292CDACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFB6EFD000C45100BC4984DFACFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4DFC8007A1E00812C9ED2B5FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEF5E0
        17CD6300BE406FDA9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF80C69F007D29007A2BAED6C1FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FCF927D47100C14046D483FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF66B78A00792800792CD3EADFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF1DD76F00C5443DD47AF3FCF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF44A56F0072202387
        49E1F0EAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3CDF8600CC4A2CD36FE3F9EEFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF249456006C1D398C55EFF7F4FFFFFFFFFF
        FFFFFFFF5CE79900D25324D770E2FAEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF1B894900671A4C9664FFFFFFFFFFFF90EEB800D75B00D6603BDC
        8293E7B47CE1A37BDFA37BDBA17BDAA17CD8A07CD6A07CD29E7CD19C7CCE9B7C
        CC9A7CC8997CC7987CC5977CC2957BBF947BBE927BBA928AC09C66AE83007530
        00621A77B291F9FEFC42E08200D24200D35300CB4800C33B00C14200C34E00BB
        4C00B53D00AA2F00A72E009E2B009B2900962700922300892100861F00811C00
        7F1F00873300822F00731E00660E00661400691E00621900611AFFFFFFE8FBEF
        AAF1C9A1F0C4A3EDC5BAF1D282E4AE09C85F00BD4E51D18BAEE7C7A3E4BFA4E2
        C0A4E0BEA4DFBDA2DDBDA4DCBCA3DABCADDDC176C49B007D24008A3D76BE97B7
        DBC6A2CFB6A3CDB596C5AAE9F3EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6FAEE
        2AD27100BE435ED794FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFF74C095007D27008239C9E5D6FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FDFB31D67800C14037D179FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF5CB282007826007B2FDEEFE7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF2EDA7A00C54434D274EFFBF4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFDFC3DA2690072202B8C
        50E6F3EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF53E39400CB491ED066D7F6E5FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0D8945006D1F499563F9FDFCFFFFFFFFFF
        FFFFFFFF64E89E00D2531CD56ADAF8E8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF0B803B006618569C6CFFFFFFFFFFFF97EFBD00D85C00D65F44DD
        88A9ECC390E5B18FE4B18FE1B08FE0AF8FDEAE90DBAE90D8AC90D7AB90D5AA90
        D3A990D0A890CFA790CDA78FCBA48FC8A58FC8A38EC5A29FCBAE74B58F00742E
        00601785BA9CF9FEFC44E08300D24300D45500CB4800C33B00BF3900BB3700B3
        3400B03100AA2F00A62D009D2A009A2800952600912200882000851D00811B00
        7B18007515007113006B1100650C006615006A2000631B00621CFFFFFFE2F9EC
        ACF1C9A5F1C6A7EEC7A7EDC6A8ECC5A7E9C5A7E9C4A7E7C4A7E6C2A7E5C2A7E2
        C1A7E2C1A7DFC0A7DEBFA7DDBFA7DCBDA7D9BDA6D9BCA6D6BCA6D5BBA6D4BAA6
        D2BAA6D1B8A7CEB89CC7AEDFECE5}
      OnClick = SpBAllNoClick
    end
    object PRemarkInfServ: TPanel
      Left = 8
      Top = 48
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1080#1085#1092#1086#1088#1084#1072#1090#1080#1074#1085#1086#1089#1090#1080' '#1089#1083#1091#1078#1073
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
    end
    object PRemarkInfServYes: TPanel
      Left = 368
      Top = 48
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
      OnClick = PRemarkInfServYesClick
    end
    object PRemarkInfServNo: TPanel
      Left = 400
      Top = 48
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
      OnClick = PRemarkInfServNoClick
    end
    object PRemarkAnam: TPanel
      Left = 8
      Top = 67
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1080#1085#1092#1086#1088#1084#1072#1090#1080#1074#1085#1086#1089#1090#1080' '#1072#1085#1072#1084#1085#1077#1079#1072' '#1073#1086#1083#1077#1079#1085#1080
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
    end
    object PRemarkAnamYes: TPanel
      Left = 368
      Top = 67
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 4
      OnClick = PRemarkAnamYesClick
    end
    object PRemarkAnamNo: TPanel
      Left = 400
      Top = 67
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 5
      OnClick = PRemarkAnamNoClick
    end
    object PRemarkFizRes: TPanel
      Left = 8
      Top = 86
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1092#1080#1079#1080#1082#1072#1083#1100#1085#1099#1084' '#1080#1089#1089#1076#1077#1076#1086#1074#1072#1085#1080#1103#1084
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 6
    end
    object PRemarkFizResYes: TPanel
      Left = 368
      Top = 86
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 7
      OnClick = PRemarkFizResYesClick
    end
    object PRemarkFizResNo: TPanel
      Left = 400
      Top = 86
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 8
      OnClick = PRemarkFizResNoClick
    end
    object PResearchNot: TPanel
      Left = 8
      Top = 128
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1085#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 9
    end
    object PResearchToMuch: TPanel
      Left = 8
      Top = 147
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086' '#1080#1079#1083#1080#1096#1085#1077
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 10
    end
    object PResearchToMuchNo: TPanel
      Left = 400
      Top = 147
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 11
      OnClick = PResearchToMuchNoClick
    end
    object PResearchNotNo: TPanel
      Left = 400
      Top = 128
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 12
      OnClick = PResearchNotNoClick
    end
    object PResearchNotYes: TPanel
      Left = 368
      Top = 128
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 13
      OnClick = PResearchNotYesClick
    end
    object PResearchToMuchYes: TPanel
      Left = 368
      Top = 147
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 14
      OnClick = PResearchToMuchYesClick
    end
    object PResearchLate: TPanel
      Left = 8
      Top = 166
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086' '#1085#1077#1089#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 15
    end
    object PResearchLateYes: TPanel
      Left = 368
      Top = 166
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 16
      OnClick = PResearchLateYesClick
    end
    object PResearchLateNo: TPanel
      Left = 400
      Top = 166
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 17
      OnClick = PResearchLateNoClick
    end
    object PResearchInstrNot: TPanel
      Left = 8
      Top = 208
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1085#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 18
    end
    object PResearchInstrNotYes: TPanel
      Left = 368
      Top = 208
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 19
      OnClick = PResearchInstrNotYesClick
    end
    object PResearchInstrNotNo: TPanel
      Left = 400
      Top = 208
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 20
      OnClick = PResearchInstrNotNoClick
    end
    object PResearchInstrToMuch: TPanel
      Left = 8
      Top = 227
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086' '#1080#1079#1083#1080#1096#1085#1077
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 21
    end
    object PResearchInstrLate: TPanel
      Left = 8
      Top = 246
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1086' '#1085#1077#1089#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 22
    end
    object PResearchInstrToMuchYes: TPanel
      Left = 368
      Top = 227
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 23
      OnClick = PResearchInstrToMuchYesClick
    end
    object PResearchInstrToMuchNo: TPanel
      Left = 400
      Top = 227
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 24
      OnClick = PResearchInstrToMuchNoClick
    end
    object PResearchInstrLateYes: TPanel
      Left = 368
      Top = 246
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 25
      OnClick = PResearchInstrLateYesClick
    end
    object PResearchInstrLateNo: TPanel
      Left = 400
      Top = 246
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 26
      OnClick = PResearchInstrLateNoClick
    end
    object PRemarkKonsultNot: TPanel
      Left = 8
      Top = 285
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1050#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103' '#1085#1077' '#1087#1088#1086#1074#1077#1076#1077#1085#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 27
    end
    object PRemarkKonsultLate: TPanel
      Left = 8
      Top = 304
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1050#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103' '#1087#1088#1086#1074#1077#1076#1077#1085#1072' '#1085#1077#1089#1074#1086#1077#1074#1088#1077#1084#1077#1085#1085#1086
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 28
    end
    object PRemarkKonsultNotYes: TPanel
      Left = 368
      Top = 285
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 29
      OnClick = PRemarkKonsultNotYesClick
    end
    object PRemarkKonsultLateYes: TPanel
      Left = 368
      Top = 304
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 30
      OnClick = PRemarkKonsultLateYesClick
    end
    object PRemarkKonsultNotNo: TPanel
      Left = 400
      Top = 285
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 31
      OnClick = PRemarkKonsultNotNoClick
    end
    object PRemarkKonsultLateNo: TPanel
      Left = 400
      Top = 304
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 32
      OnClick = PRemarkKonsultLateNoClick
    end
    object PRemarkDeseaseVerif: TPanel
      Left = 8
      Top = 342
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1055#1086' '#1074#1077#1088#1080#1092#1080#1082#1072#1094#1080#1080
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 33
    end
    object PRemarkDeseaseTime: TPanel
      Left = 8
      Top = 361
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1055#1086' '#1074#1088#1077#1084#1077#1085#1080' '#1087#1086#1089#1090#1072#1074#1085#1086#1074#1082#1080
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 34
    end
    object PRemarkDeseaseContent: TPanel
      Left = 8
      Top = 380
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1055#1086' '#1089#1086#1076#1077#1088#1078#1072#1085#1080#1102
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 35
    end
    object PRemarkDeseaseVerifYes: TPanel
      Left = 368
      Top = 342
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 36
      OnClick = PRemarkDeseaseVerifYesClick
    end
    object PRemarkDeseaseTimeYes: TPanel
      Left = 368
      Top = 361
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 37
      OnClick = PRemarkDeseaseTimeYesClick
    end
    object PRemarkDeseaseContentYes: TPanel
      Left = 368
      Top = 380
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 38
      OnClick = PRemarkDeseaseContentYesClick
    end
    object PRemarkDeseaseVerifNo: TPanel
      Left = 400
      Top = 342
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 39
      OnClick = PRemarkDeseaseVerifNoClick
    end
    object PRemarkDeseaseTimeNo: TPanel
      Left = 400
      Top = 361
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 40
      OnClick = PRemarkDeseaseTimeNoClick
    end
    object PRemarkDeseaseContentNo: TPanel
      Left = 400
      Top = 380
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 41
      OnClick = PRemarkDeseaseContentNoClick
    end
    object PRemarkTherapyPolypharmacyNo: TPanel
      Left = 400
      Top = 453
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 42
      OnClick = PRemarkTherapyPolypharmacyNoClick
    end
    object PRemarkTherapyTimeAppointmentNo: TPanel
      Left = 400
      Top = 434
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 43
      OnClick = PRemarkTherapyTimeAppointmentNoClick
    end
    object PRemarkTherapyChooseDrNo: TPanel
      Left = 400
      Top = 415
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 44
      OnClick = PRemarkTherapyChooseDrNoClick
    end
    object PRemarkTherapyPolypharmacyYes: TPanel
      Left = 368
      Top = 453
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 45
      OnClick = PRemarkTherapyPolypharmacyYesClick
    end
    object PRemarkTherapyTimeAppointmentYes: TPanel
      Left = 368
      Top = 434
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 46
      OnClick = PRemarkTherapyTimeAppointmentYesClick
    end
    object PRemarkTherapyChooseDrYes: TPanel
      Left = 368
      Top = 415
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 47
      OnClick = PRemarkTherapyChooseDrYesClick
    end
    object PRemarkTherapyPolypharmacy: TPanel
      Left = 8
      Top = 453
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1055#1086#1083#1080#1087#1088#1072#1075#1084#1072#1079#1080#1103
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 48
    end
    object PRemarkTherapyTimeAppointment: TPanel
      Left = 8
      Top = 434
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1074#1088#1077#1084#1077#1085#1080' '#1085#1072#1079#1085#1072#1095#1077#1085#1080#1103' '#1080' '#1086#1090#1084#1077#1085#1099
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 49
    end
    object PRemarkTherapyChooseDr: TPanel
      Left = 8
      Top = 415
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1074#1099#1073#1086#1088#1091' '#1087#1088#1077#1087#1072#1088#1072#1090#1086#1074
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 50
    end
    object PKvo: TPanel
      Left = 368
      Top = 577
      Width = 65
      Height = 20
      Caption = '0'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 51
    end
    object PContinuityChoosePlace: TPanel
      Left = 8
      Top = 493
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1074#1099#1073#1086#1088#1091' '#1084#1077#1089#1090#1072' '#1076#1072#1083#1100#1085#1077#1081#1096#1077#1081' '#1087#1086#1084#1086#1097#1080
      Color = clWhite
      ParentBackground = False
      TabOrder = 52
    end
    object PContinuityChoosePlaceNo: TPanel
      Left = 400
      Top = 493
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      ParentBackground = False
      TabOrder = 53
      OnClick = PContinuityChoosePlaceNoClick
    end
    object PContinuityChoosePlaceYes: TPanel
      Left = 368
      Top = 493
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      ParentBackground = False
      TabOrder = 54
      OnClick = PContinuityChoosePlaceYesClick
    end
    object PContinuityTimeTransferNo: TPanel
      Left = 400
      Top = 512
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      ParentBackground = False
      TabOrder = 55
      OnClick = PContinuityTimeTransferNoClick
    end
    object PContinuityTimeTransfer: TPanel
      Left = 8
      Top = 512
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1047#1072#1084#1077#1095#1072#1085#1080#1103' '#1087#1086' '#1074#1088#1077#1084#1077#1085#1080' '#1087#1077#1088#1077#1076#1072#1095#1080' '#1087#1072#1094#1080#1077#1085#1090#1072
      Color = clWhite
      ParentBackground = False
      TabOrder = 56
    end
    object PContinuityTimeTransferYes: TPanel
      Left = 368
      Top = 512
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      ParentBackground = False
      TabOrder = 57
      OnClick = PContinuityTimeTransferYesClick
    end
    object PRemarkStandartMH: TPanel
      Left = 8
      Top = 550
      Width = 361
      Height = 20
      Alignment = taLeftJustify
      BorderStyle = bsSingle
      Caption = #1053#1077#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1080#1077' '#1089#1090#1072#1085#1076#1072#1088#1090#1072#1084
      Color = clWhite
      ParentBackground = False
      TabOrder = 58
    end
    object PRemarkStandartMHYes: TPanel
      Left = 368
      Top = 550
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1044#1072
      Color = clWhite
      ParentBackground = False
      TabOrder = 59
      OnClick = PRemarkStandartMHYesClick
    end
    object PRemarkStandartMHNo: TPanel
      Left = 400
      Top = 550
      Width = 33
      Height = 20
      BorderStyle = bsSingle
      Caption = #1053#1077#1090
      Color = clWhite
      ParentBackground = False
      TabOrder = 60
      OnClick = PRemarkStandartMHNoClick
    end
  end
  object Panel4: TPanel
    Left = 553
    Top = 74
    Width = 10
    Height = 611
    Align = alLeft
    Color = clGradientActiveCaption
    ParentBackground = False
    TabOrder = 3
  end
  object Panel5: TPanel
    Left = 0
    Top = 685
    Width = 1013
    Height = 41
    Align = alBottom
    Color = clGradientActiveCaption
    ParentBackground = False
    TabOrder = 4
    object Button1: TButton
      Left = 7
      Top = 5
      Width = 997
      Height = 32
      Caption = #1057#1054#1061#1056#1040#1053#1048#1058#1068' '#1050#1040#1056#1058#1059
      TabOrder = 0
      OnClick = Button1Click
    end
  end
end
