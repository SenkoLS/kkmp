object FDictionaryMed: TFDictionaryMed
  Left = 0
  Top = 0
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1075#1086' '#1087#1077#1088#1089#1086#1085#1072#1083#1072
  ClientHeight = 517
  ClientWidth = 784
  Color = clBtnFace
  Constraints.MaxHeight = 556
  Constraints.MaxWidth = 800
  Constraints.MinHeight = 556
  Constraints.MinWidth = 800
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
  object Panel2: TPanel
    Left = 0
    Top = 373
    Width = 784
    Height = 144
    Align = alBottom
    TabOrder = 0
    object LSurname: TLabel
      Left = 5
      Top = 13
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
      Left = 270
      Top = 13
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
    object LPatronymic: TLabel
      Left = 483
      Top = 13
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
    object LLogin: TLabel
      Left = 5
      Top = 43
      Width = 40
      Height = 17
      Caption = #1051#1086#1075#1080#1085':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LPassword: TLabel
      Left = 270
      Top = 43
      Width = 49
      Height = 17
      Caption = #1055#1072#1088#1086#1083#1100':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object LOffice: TLabel
      Left = 452
      Top = 43
      Width = 71
      Height = 17
      Caption = #1054#1090#1076#1077#1083#1077#1085#1080#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object EOtch: TEdit
      Left = 553
      Top = 8
      Width = 224
      Height = 25
      Color = clBtnFace
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnExit = EOtchExit
    end
    object EName: TEdit
      Left = 320
      Top = 8
      Width = 157
      Height = 25
      Color = clBtnFace
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnExit = ENameExit
    end
    object ESurname: TEdit
      Left = 70
      Top = 8
      Width = 179
      Height = 25
      Color = clBtnFace
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnExit = ESurnameExit
    end
    object BAdd: TButton
      Left = 5
      Top = 70
      Width = 244
      Height = 30
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = BAddClick
    end
    object BEdit: TButton
      Left = 270
      Top = 71
      Width = 244
      Height = 30
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = BEditClick
    end
    object BDelete: TButton
      Left = 533
      Top = 70
      Width = 244
      Height = 30
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = BDeleteClick
    end
    object ELogin: TEdit
      Left = 70
      Top = 39
      Width = 179
      Height = 26
      Color = clBtnFace
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object EPassword: TEdit
      Left = 320
      Top = 39
      Width = 121
      Height = 26
      Color = clBtnFace
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object DBLookupComboBoxOffice: TDBLookupComboBox
      Left = 529
      Top = 42
      Width = 248
      Height = 22
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      KeyField = 'id_office'
      ListField = 'name_office'
      ListSource = DMAvtoriz.DSgetListOffice
      ParentFont = False
      TabOrder = 5
    end
    object BSafeMed: TButton
      Left = 5
      Top = 106
      Width = 388
      Height = 30
      Caption = #1057#1054#1061#1056#1040#1053#1048#1058#1068
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = BSafeMedClick
    end
    object BCancel: TButton
      Left = 399
      Top = 106
      Width = 378
      Height = 30
      Caption = #1054#1058#1052#1045#1053#1040
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = BCancelClick
    end
  end
  object DBGrCatalogMed: TDBGridEh
    Left = 0
    Top = 0
    Width = 784
    Height = 367
    Align = alTop
    DataSource = DMAvtoriz.DSCatalogMed
    DynProps = <>
    ImeMode = imDisable
    IndicatorOptions = [gioShowRowIndicatorEh]
    TabOrder = 1
    Columns = <
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'id_user'
        Footers = <>
        Visible = False
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'surname'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1060#1072#1084#1080#1083#1080#1103
        Width = 130
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1048#1084#1103
        Width = 120
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'patronymic'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
        Width = 145
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'login'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1051#1086#1075#1080#1085
        Width = 100
      end
      item
        DynProps = <>
        EditButtons = <>
        FieldName = 'name_office'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Footers = <>
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1086#1090#1076#1077#1083#1077#1085#1080#1103
        Width = 255
      end>
    object RowDetailData: TRowDetailPanelControlEh
    end
  end
end
