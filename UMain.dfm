object FMain: TFMain
  Left = 0
  Top = 0
  Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1082#1072#1095#1077#1089#1090#1074#1086#1084' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1081' '#1087#1086#1084#1086#1097#1080
  ClientHeight = 616
  ClientWidth = 1046
  Color = clBtnFace
  Constraints.MaxHeight = 675
  Constraints.MaxWidth = 1062
  Constraints.MinHeight = 675
  Constraints.MinWidth = 1062
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 798
    Height = 608
    TabOrder = 0
    object DBGridEh1: TDBGridEh
      Left = 8
      Top = 8
      Width = 785
      Height = 552
      DataSource = DMAvtoriz.DSInspection
      DynProps = <>
      IndicatorOptions = [gioShowRowIndicatorEh]
      TabOrder = 0
      Columns = <
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'type_med_help'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1087#1086#1084#1086#1097#1080
          Width = 75
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'date_start'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1085#1072#1095#1072#1083#1072
          Width = 76
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'date_end'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1086#1082#1086#1085#1095#1072#1085#1080#1103
          Width = 85
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'fio'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1060#1048#1054
          Width = 205
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'date_birthday'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1044#1056
          Width = 80
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'number_card'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1053#1086#1084#1077#1088' '#1072#1084#1073'. '#1082#1072#1088#1090#1099
          Width = 95
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'kkmp'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1050#1050#1052#1055
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'kvo'
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1050#1042#1054
        end>
      object RowDetailData: TRowDetailPanelControlEh
      end
    end
  end
  object BShowCard: TButton
    Left = 804
    Top = 8
    Width = 234
    Height = 33
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1082#1072#1088#1090#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Panel2: TPanel
    Left = 804
    Top = 47
    Width = 234
    Height = 194
    TabOrder = 2
    object LSortList: TLabel
      Left = 56
      Top = 8
      Width = 122
      Height = 17
      Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1089#1087#1080#1089#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14745600
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object BSortFio: TButton
      Left = 8
      Top = 31
      Width = 217
      Height = 34
      Caption = #1087#1086' '#1060#1048#1054' '#1087#1072#1094#1080#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object BSortDateEnd: TButton
      Left = 8
      Top = 71
      Width = 217
      Height = 34
      Caption = #1087#1086' '#1086#1082#1086#1085#1095#1072#1085#1080#1102' '#1085#1072#1073#1083#1102#1076#1077#1085#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object BSortDuration: TButton
      Left = 8
      Top = 111
      Width = 217
      Height = 34
      Caption = #1087#1086' '#1087#1077#1088#1080#1086#1076#1091' '#1074#1088#1077#1084#1077#1085#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object BShowAll: TButton
      Left = 8
      Top = 151
      Width = 65
      Height = 34
      Caption = #1042#1089#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object BShowAm: TButton
      Left = 79
      Top = 151
      Width = 75
      Height = 34
      Caption = #1040#1084#1073#1091#1083#1072#1090'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object BShowSDP: TButton
      Left = 160
      Top = 151
      Width = 66
      Height = 34
      Caption = #1057#1044#1055
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
  end
  object Panel3: TPanel
    Left = 804
    Top = 247
    Width = 234
    Height = 186
    TabOrder = 3
    object LFindInList: TLabel
      Left = 52
      Top = 8
      Width = 117
      Height = 17
      Caption = #1055#1086#1080#1089#1082' '#1074' '#1089#1087#1080#1089#1082#1077' '#1087#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 14745600
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 12
      Top = 31
      Width = 93
      Height = 17
      Caption = #1060#1048#1054' '#1087#1072#1094#1080#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 12
      Top = 81
      Width = 146
      Height = 17
      Caption = #8470' '#1072#1084#1073#1091#1083#1072#1090#1086#1088#1085#1086#1081' '#1082#1072#1088#1090#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 12
      Top = 131
      Width = 72
      Height = 17
      Caption = #1060#1048#1054' '#1074#1088#1072#1095#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object EFindFio: TEdit
      Left = 8
      Top = 54
      Width = 217
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object EFindNumCard: TEdit
      Left = 8
      Top = 104
      Width = 217
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object EFindMed: TEdit
      Left = 8
      Top = 154
      Width = 217
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object Panel4: TPanel
    Left = 804
    Top = 439
    Width = 234
    Height = 170
    TabOrder = 4
    object BExportProtocol: TButton
      Left = 8
      Top = 8
      Width = 217
      Height = 33
      Caption = #1069#1082#1089#1087#1086#1088#1090' '#1089#1087#1080#1089#1082#1072' '#1087#1088#1086#1090#1086#1082#1086#1083#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object BPrintProtocol: TButton
      Left = 8
      Top = 47
      Width = 217
      Height = 34
      Caption = #1055#1077#1095#1072#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object BPrintList: TButton
      Left = 8
      Top = 87
      Width = 217
      Height = 34
      Caption = #1055#1077#1095#1072#1090#1100' '#1074#1099#1074#1077#1076#1077#1085#1085#1086#1075#1086' '#1089#1087#1080#1089#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object BDeleteCard: TButton
      Left = 8
      Top = 127
      Width = 217
      Height = 34
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1091#1102' '#1082#1072#1088#1090#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
  object MainMenu1: TMainMenu
    Left = 168
    Top = 16
    object NewCard: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1082#1072#1088#1090#1086#1095#1082#1072' (F2)'
      OnClick = NewCardClick
    end
    object N1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
      object N4: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1075#1086' '#1087#1077#1088#1089#1086#1085#1072#1083#1072
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
      end
    end
    object N2: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099
    end
    object N3: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N3Click
    end
  end
end