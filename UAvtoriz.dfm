object FAvtoriz: TFAvtoriz
  Left = 0
  Top = 0
  BorderIcons = []
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1080#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
  ClientHeight = 156
  ClientWidth = 264
  Color = clBtnFace
  Constraints.MaxHeight = 195
  Constraints.MaxWidth = 280
  Constraints.MinHeight = 195
  Constraints.MinWidth = 280
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 15
  object LLogin: TLabel
    Left = 16
    Top = 24
    Width = 46
    Height = 19
    Caption = #1051#1086#1075#1080#1085':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object LPassword: TLabel
    Left = 16
    Top = 72
    Width = 52
    Height = 19
    Caption = #1055#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object BEnter: TButton
    Left = 16
    Top = 116
    Width = 113
    Height = 25
    Caption = #1042#1061#1054#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BEnterClick
  end
  object ELogin: TEdit
    Left = 80
    Top = 24
    Width = 169
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnKeyDown = ELoginKeyDown
  end
  object EPassword: TEdit
    Left = 80
    Top = 69
    Width = 169
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnKeyDown = EPasswordKeyDown
  end
  object BExit: TButton
    Left = 135
    Top = 116
    Width = 113
    Height = 25
    Caption = #1042#1067#1061#1054#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = BExitClick
  end
end
