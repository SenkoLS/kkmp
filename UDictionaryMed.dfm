object FDictionaryMed: TFDictionaryMed
  Left = 0
  Top = 0
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1075#1086' '#1087#1077#1088#1089#1086#1085#1072#1083#1072
  ClientHeight = 331
  ClientWidth = 784
  Color = clBtnFace
  Constraints.MaxHeight = 370
  Constraints.MaxWidth = 800
  Constraints.MinHeight = 370
  Constraints.MinWidth = 800
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 769
    Height = 209
    TabOrder = 0
    object DBGridEh1: TDBGridEh
      Left = 1
      Top = 1
      Width = 767
      Height = 200
      Align = alTop
      DataSource = DMAvtoriz.DSCatalogMed
      DynProps = <>
      IndicatorOptions = [gioShowRowIndicatorEh]
      TabOrder = 0
      Columns = <
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'surname'
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103
          Width = 130
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'name'
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1048#1084#1103
          Width = 120
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'patronymic'
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
          Width = 145
        end
        item
          DynProps = <>
          EditButtons = <>
          FieldName = 'login'
          Footers = <>
          Title.Alignment = taCenter
          Title.Caption = #1051#1086#1075#1080#1085
          Width = 100
        end>
      object RowDetailData: TRowDetailPanelControlEh
      end
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 223
    Width = 769
    Height = 98
    TabOrder = 1
    object LSurname: TLabel
      Left = 5
      Top = 16
      Width = 59
      Height = 17
      Caption = #1060#1072#1084#1080#1083#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LName: TLabel
      Left = 283
      Top = 16
      Width = 31
      Height = 17
      Caption = #1048#1084#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LOtch: TLabel
      Left = 483
      Top = 16
      Width = 64
      Height = 17
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object ESurname: TEdit
      Left = 553
      Top = 15
      Width = 208
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnExit = ESurnameExit
    end
    object EName: TEdit
      Left = 320
      Top = 15
      Width = 157
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnExit = ENameExit
    end
    object EOtch: TEdit
      Left = 70
      Top = 15
      Width = 194
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnExit = EOtchExit
    end
    object BAdd: TButton
      Left = 5
      Top = 55
      Width = 244
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object BEdit: TButton
      Left = 260
      Top = 55
      Width = 244
      Height = 25
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object BDelete: TButton
      Left = 517
      Top = 55
      Width = 244
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
  end
end