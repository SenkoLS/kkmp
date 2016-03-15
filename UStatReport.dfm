object FStatReport: TFStatReport
  Left = 0
  Top = 0
  Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1090#1072#1090#1080#1089#1090#1080#1095#1077#1089#1082#1086#1075#1086' '#1086#1090#1095#1105#1090#1072
  ClientHeight = 290
  ClientWidth = 768
  Color = clBtnFace
  Constraints.MaxHeight = 329
  Constraints.MaxWidth = 784
  Constraints.MinHeight = 329
  Constraints.MinWidth = 784
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 768
    Height = 289
    Align = alTop
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 12
      Width = 113
      Height = 15
      Caption = #1054#1090#1095#1077#1090#1085#1099#1081' '#1087#1077#1088#1080#1086#1076':  '#1089
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 243
      Top = 12
      Width = 14
      Height = 15
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 223
      Width = 246
      Height = 15
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1086#1089#1077#1097#1077#1085#1080#1081' '#1079#1072' '#1086#1090#1095#1077#1090#1085#1099#1081' '#1087#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object DTPStartReportPer: TDateTimePicker
      Left = 127
      Top = 8
      Width = 110
      Height = 23
      Date = 42425.535124930550000000
      Time = 42425.535124930550000000
      TabOrder = 0
    end
    object DTPEndReportPer: TDateTimePicker
      Left = 263
      Top = 8
      Width = 110
      Height = 23
      Date = 42425.535190277780000000
      Time = 42425.535190277780000000
      TabOrder = 1
    end
    object ChBoxOffice: TCheckBox
      Left = 8
      Top = 37
      Width = 89
      Height = 17
      Caption = #1054#1090#1076#1077#1083#1077#1085#1080#1077
      TabOrder = 2
      OnClick = ChBoxOfficeClick
    end
    object ChBoxMed: TCheckBox
      Left = 8
      Top = 141
      Width = 58
      Height = 17
      Caption = #1042#1088#1072#1095
      TabOrder = 3
      OnClick = ChBoxMedClick
    end
    object ChBoxExpert: TCheckBox
      Left = 8
      Top = 89
      Width = 73
      Height = 17
      Caption = #1069#1082#1089#1087#1077#1088#1090
      TabOrder = 4
      OnClick = ChBoxExpertClick
    end
    object ChBoxGeneral: TCheckBox
      Left = 8
      Top = 197
      Width = 73
      Height = 17
      Caption = #1054#1073#1097#1080#1081
      Checked = True
      Enabled = False
      State = cbChecked
      TabOrder = 5
    end
    object DBLCbOffice: TDBLookupComboBox
      Left = 8
      Top = 60
      Width = 365
      Height = 23
      Enabled = False
      KeyField = 'id_office'
      ListField = 'name_office'
      ListSource = DMAvtoriz.DSgetListOffice
      TabOrder = 6
    end
    object DBLCbMed: TDBLookupComboBox
      Left = 8
      Top = 164
      Width = 365
      Height = 23
      Enabled = False
      KeyField = 'id_user'
      ListField = 'fio'
      ListSource = DMAvtoriz.DSGetListMedStat
      TabOrder = 7
    end
    object DBLCbExpert: TDBLookupComboBox
      Left = 8
      Top = 112
      Width = 365
      Height = 23
      Enabled = False
      KeyField = 'id_user'
      ListField = 'fio'
      ListSource = DMAvtoriz.DSGetListMed
      TabOrder = 8
    end
    object ECountOfVisits: TEdit
      Left = 260
      Top = 220
      Width = 113
      Height = 23
      TabOrder = 9
    end
    object DBGridReport: TDBGridEh
      Left = 393
      Top = 8
      Width = 375
      Height = 273
      DynProps = <>
      IndicatorOptions = [gioShowRowIndicatorEh]
      TabOrder = 10
      object RowDetailData: TRowDetailPanelControlEh
      end
    end
    object BGenerateReport: TButton
      Left = 198
      Top = 249
      Width = 175
      Height = 32
      Caption = #1042' EXCEL'
      TabOrder = 11
      OnClick = BGenerateReportClick
    end
    object BGenReport: TButton
      Left = 8
      Top = 249
      Width = 175
      Height = 32
      Caption = #1057#1054#1041#1056#1040#1058#1068' '#1054#1058#1063#1045#1058
      TabOrder = 12
      OnClick = BGenReportClick
    end
  end
end
