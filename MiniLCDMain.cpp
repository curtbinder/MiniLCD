/***************************************************************
 * Name:      MiniLCDMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Curt Binder (binder@curtbinder.info)
 * Created:   2019-03-04
 * Copyright: Curt Binder (https://curtbinder.info/)
 * License:
 **************************************************************/

#include "MiniLCDMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MiniLCDFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MiniLCDFrame)
const long MiniLCDFrame::ID_BUTTON_CLEAR_SCREEN = wxNewId();
const long MiniLCDFrame::ID_BUTTON_NEW_LINE = wxNewId();
const long MiniLCDFrame::ID_BUTTON_WRITE_TEXT = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_GPIO = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_SHOW_CURSOR = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_BLINK_CURSOR = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_BACKLIGHT = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_AUTO_SCROLL = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_LINE_WRAP = wxNewId();
const long MiniLCDFrame::ID_TEXTCTRL_BACKLIGHT_MINUTES = wxNewId();
const long MiniLCDFrame::ID_STATICTEXT1 = wxNewId();
const long MiniLCDFrame::ID_TEXTCTRL_MESSAGE = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_UPDATE = wxNewId();
const long MiniLCDFrame::ID_STATICBOX1 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_ENABLE_HORIZONTAL = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_HORIZONTAL_REVERSE = wxNewId();
const long MiniLCDFrame::ID_SLIDER_HORIZONTAL_1 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_HORIZONTAL_2 = wxNewId();
const long MiniLCDFrame::ID_STATICBOX2 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX_VERTICAL_ENABLE = wxNewId();
const long MiniLCDFrame::ID_TOGGLEBUTTON_VERTICAL_THIN = wxNewId();
const long MiniLCDFrame::ID_TOGGLEBUTTON_VERTICAL_THICK = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_1 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_2 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_3 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_4 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_5 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_6 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_7 = wxNewId();
const long MiniLCDFrame::ID_SLIDER_VERTICAL_8 = wxNewId();
const long MiniLCDFrame::idMenuQuit = wxNewId();
const long MiniLCDFrame::idMenuAbout = wxNewId();
const long MiniLCDFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MiniLCDFrame,wxFrame)
    //(*EventTable(MiniLCDFrame)
    //*)
END_EVENT_TABLE()

MiniLCDFrame::MiniLCDFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MiniLCDFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Mini LCD App"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(450,400));
    SetMinSize(wxSize(450,400));
    SetMaxSize(wxSize(450,400));
    btnClearScreen = new wxButton(this, ID_BUTTON_CLEAR_SCREEN, _("Clear Screen"), wxPoint(8,8), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON_CLEAR_SCREEN"));
    btnNewLine = new wxButton(this, ID_BUTTON_NEW_LINE, _("New Line"), wxPoint(8,48), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON_NEW_LINE"));
    btnWriteText = new wxButton(this, ID_BUTTON_WRITE_TEXT, _("Write Text"), wxPoint(8,88), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON_WRITE_TEXT"));
    ckGPIO = new wxCheckBox(this, ID_CHECKBOX_GPIO, _("GPIO"), wxPoint(120,8), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_GPIO"));
    ckGPIO->SetValue(false);
    ckShowCursor = new wxCheckBox(this, ID_CHECKBOX_SHOW_CURSOR, _("Show Cursor"), wxPoint(120,32), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_SHOW_CURSOR"));
    ckShowCursor->SetValue(false);
    ckBlinkCursor = new wxCheckBox(this, ID_CHECKBOX_BLINK_CURSOR, _("Blink Cursor"), wxPoint(120,56), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_BLINK_CURSOR"));
    ckBlinkCursor->SetValue(false);
    ckBacklight = new wxCheckBox(this, ID_CHECKBOX_BACKLIGHT, _("Backlight"), wxPoint(240,8), wxSize(88,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_BACKLIGHT"));
    ckBacklight->SetValue(false);
    ckAutoScroll = new wxCheckBox(this, ID_CHECKBOX_AUTO_SCROLL, _("Auto Scroll"), wxPoint(240,32), wxSize(104,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_AUTO_SCROLL"));
    ckAutoScroll->SetValue(false);
    ckLineWrap = new wxCheckBox(this, ID_CHECKBOX_LINE_WRAP, _("Line Wrap"), wxPoint(240,56), wxSize(104,18), 0, wxDefaultValidator, _T("ID_CHECKBOX_LINE_WRAP"));
    ckLineWrap->SetValue(false);
    editBacklightMinutes = new wxTextCtrl(this, ID_TEXTCTRL_BACKLIGHT_MINUTES, _("0"), wxPoint(336,8), wxSize(32,18), 0, wxDefaultValidator, _T("ID_TEXTCTRL_BACKLIGHT_MINUTES"));
    editBacklightMinutes->SetMaxLength(3);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("minutes"), wxPoint(376,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    editMessage = new wxTextCtrl(this, ID_TEXTCTRL_MESSAGE, _("Text"), wxPoint(120,88), wxSize(240,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL_MESSAGE"));
    ckUpdate = new wxCheckBox(this, ID_CHECKBOX_UPDATE, _("Update"), wxPoint(368,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_UPDATE"));
    ckUpdate->SetValue(false);
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Horizontal Bar Graph"), wxPoint(8,128), wxSize(432,104), 0, _T("ID_STATICBOX1"));
    ckHorizontalEnable = new wxCheckBox(this, ID_CHECKBOX_ENABLE_HORIZONTAL, _("Enable"), wxPoint(16,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_ENABLE_HORIZONTAL"));
    ckHorizontalEnable->SetValue(false);
    ckHorizontalReverse = new wxCheckBox(this, ID_CHECKBOX_HORIZONTAL_REVERSE, _("Reverse"), wxPoint(96,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_HORIZONTAL_REVERSE"));
    ckHorizontalReverse->SetValue(false);
    slideHorizontal1 = new wxSlider(this, ID_SLIDER_HORIZONTAL_1, 0, 0, 100, wxPoint(16,176), wxSize(416,24), 0, wxDefaultValidator, _T("ID_SLIDER_HORIZONTAL_1"));
    slideHorizontal2 = new wxSlider(this, ID_SLIDER_HORIZONTAL_2, 0, 0, 100, wxPoint(16,200), wxSize(416,24), 0, wxDefaultValidator, _T("ID_SLIDER_HORIZONTAL_2"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Vertical Bar Graph"), wxPoint(8,240), wxSize(432,104), 0, _T("ID_STATICBOX2"));
    ckVerticalEnable = new wxCheckBox(this, ID_CHECKBOX_VERTICAL_ENABLE, _("Enable"), wxPoint(16,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_VERTICAL_ENABLE"));
    ckVerticalEnable->SetValue(false);
    togglebtnVerticalThin = new wxToggleButton(this, ID_TOGGLEBUTTON_VERTICAL_THIN, _("Thin"), wxPoint(16,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON_VERTICAL_THIN"));
    togglebtnVerticalThick = new wxToggleButton(this, ID_TOGGLEBUTTON_VERTICAL_THICK, _("Thick"), wxPoint(16,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON_VERTICAL_THICK"));
    slideVertical1 = new wxSlider(this, ID_SLIDER_VERTICAL_1, 0, 0, 100, wxPoint(112,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_1"));
    slideVertical2 = new wxSlider(this, ID_SLIDER_VERTICAL_2, 0, 0, 100, wxPoint(144,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_2"));
    slideVertical3 = new wxSlider(this, ID_SLIDER_VERTICAL_3, 0, 0, 100, wxPoint(176,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_3"));
    slideVertical4 = new wxSlider(this, ID_SLIDER_VERTICAL_4, 0, 0, 100, wxPoint(208,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_4"));
    slideVertical5 = new wxSlider(this, ID_SLIDER_VERTICAL_5, 0, 0, 100, wxPoint(240,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_5"));
    slideVertical6 = new wxSlider(this, ID_SLIDER_VERTICAL_6, 0, 0, 100, wxPoint(272,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_6"));
    slideVertical7 = new wxSlider(this, ID_SLIDER_VERTICAL_7, 0, 0, 100, wxPoint(304,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_7"));
    slideVertical8 = new wxSlider(this, ID_SLIDER_VERTICAL_8, 0, 0, 100, wxPoint(336,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER_VERTICAL_8"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON_CLEAR_SCREEN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnbtnClearScreenClick);
    Connect(ID_BUTTON_NEW_LINE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnbtnNewLineClick);
    Connect(ID_BUTTON_WRITE_TEXT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnbtnWriteTextClick);
    Connect(ID_CHECKBOX_GPIO,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckGPIOClick);
    Connect(ID_CHECKBOX_SHOW_CURSOR,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckShowCursorClick);
    Connect(ID_CHECKBOX_BLINK_CURSOR,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckBlinkCursorClick);
    Connect(ID_CHECKBOX_BACKLIGHT,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckBacklightClick);
    Connect(ID_CHECKBOX_AUTO_SCROLL,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckAutoScrollClick);
    Connect(ID_CHECKBOX_LINE_WRAP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckLineWrapClick);
    Connect(ID_CHECKBOX_UPDATE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckUpdateClick);
    Connect(ID_CHECKBOX_ENABLE_HORIZONTAL,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckEnableHorizontalClick);
    Connect(ID_CHECKBOX_HORIZONTAL_REVERSE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckHorizontalReverseClick);
    Connect(ID_SLIDER_HORIZONTAL_1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideHorizontal1CmdSliderUpdated);
    Connect(ID_SLIDER_HORIZONTAL_2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideHorizontal2CmdSliderUpdated);
    Connect(ID_CHECKBOX_VERTICAL_ENABLE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OnckVerticalEnableClick);
    Connect(ID_TOGGLEBUTTON_VERTICAL_THIN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OntogglebtnVerticalThinToggle);
    Connect(ID_TOGGLEBUTTON_VERTICAL_THICK,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&MiniLCDFrame::OntogglebtnVerticalThickToggle);
    Connect(ID_SLIDER_VERTICAL_1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical1CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical2CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical3CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical4CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_5,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical5CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_6,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical6CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_7,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical7CmdSliderUpdated);
    Connect(ID_SLIDER_VERTICAL_8,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MiniLCDFrame::OnslideVertical8CmdSliderUpdated);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MiniLCDFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MiniLCDFrame::OnAbout);
    //*)

    ToggleHorizontalGraph(m_LCD.getHorizontalGraphEnabled());
    ToggleVerticalGraph(m_LCD.getVerticalGraphEnabled());
}

MiniLCDFrame::~MiniLCDFrame()
{
    //(*Destroy(MiniLCDFrame)
    //*)
}

void MiniLCDFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MiniLCDFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void MiniLCDFrame::ToggleVerticalGraph(bool fEnable)
{
    ckVerticalEnable->SetValue(fEnable);
    slideVertical1->Enable(fEnable);
    slideVertical2->Enable(fEnable);
    slideVertical3->Enable(fEnable);
    slideVertical4->Enable(fEnable);
    slideVertical5->Enable(fEnable);
    slideVertical6->Enable(fEnable);
    slideVertical7->Enable(fEnable);
    slideVertical8->Enable(fEnable);
    togglebtnVerticalThick->Enable(fEnable);
    togglebtnVerticalThin->Enable(fEnable);
}

void MiniLCDFrame::ToggleHorizontalGraph(bool fEnable)
{
    ckHorizontalEnable->SetValue(fEnable);
    slideHorizontal1->Enable(fEnable);
    slideHorizontal2->Enable(fEnable);
    ckHorizontalReverse->Enable(fEnable);
}

void MiniLCDFrame::OnbtnClearScreenClick(wxCommandEvent& event)
{
    m_LCD.ClearScreen();
}

void MiniLCDFrame::OnbtnNewLineClick(wxCommandEvent& event)
{
    m_LCD.NewLine();
}

void MiniLCDFrame::OnbtnWriteTextClick(wxCommandEvent& event)
{
    m_LCD.SendMessage(editMessage->GetValue());
}

void MiniLCDFrame::OnckGPIOClick(wxCommandEvent& event)
{
    printf("GPIO: %s\n", (event.IsChecked())?"Checked":"Unchecked");
    m_LCD.setGPIO(event.IsChecked());
}

void MiniLCDFrame::OnckShowCursorClick(wxCommandEvent& event)
{
    printf("Show Cursor: %s\n", (event.IsChecked())?"Checked":"Unchecked");
    m_LCD.setShowCursor(event.IsChecked());
}

void MiniLCDFrame::OnckBlinkCursorClick(wxCommandEvent& event)
{
    printf("Blink Cursor: %s\n", (event.IsChecked())?"Checked":"Unchecked");
    m_LCD.setBlinkCursor(event.IsChecked());
}

void MiniLCDFrame::OnckBacklightClick(wxCommandEvent& event)
{
    printf("Backlight: %s\n", (event.IsChecked())?"Checked":"Unchecked");
}

void MiniLCDFrame::OnckAutoScrollClick(wxCommandEvent& event)
{
    printf("Auto Scroll: %s\n", (event.IsChecked())?"Checked":"Unchecked");
    m_LCD.setAutoScroll(event.IsChecked());
}

void MiniLCDFrame::OnckLineWrapClick(wxCommandEvent& event)
{
    printf("Line Wrap: %s\n", (event.IsChecked())?"Checked":"Unchecked");
    m_LCD.setLineWrap(event.IsChecked());
}

void MiniLCDFrame::OnckUpdateClick(wxCommandEvent& event)
{
    printf("Update: %s\n", (event.IsChecked())?"Checked":"Unchecked");
}

void MiniLCDFrame::OnckEnableHorizontalClick(wxCommandEvent& event)
{
    // Enable horizontal box, disable vertical box
    bool fEnable = m_LCD.getHorizontalGraphEnabled();
    m_LCD.setHorizontalGraphEnabled(!fEnable);
    ToggleHorizontalGraph(!fEnable);

    // if we are enabling the horizontal box, disable the vertical box if it's enabled
    if(!fEnable && m_LCD.getVerticalGraphEnabled()) {
        m_LCD.setVerticalGraphEnabled(false);
        ToggleVerticalGraph(false);
    }
}

void MiniLCDFrame::OnckHorizontalReverseClick(wxCommandEvent& event)
{
}

void MiniLCDFrame::OnslideHorizontal1CmdSliderUpdated(wxScrollEvent& event)
{
    printf("Slider1 Updated: %d\n", event.GetPosition());
}

void MiniLCDFrame::OnslideHorizontal2CmdSliderUpdated(wxScrollEvent& event)
{
    printf("Slider2 Updated: %d\n", event.GetPosition());
}

void MiniLCDFrame::OnckVerticalEnableClick(wxCommandEvent& event)
{
    bool fEnable = m_LCD.getVerticalGraphEnabled();
    m_LCD.setVerticalGraphEnabled(!fEnable);
    ToggleVerticalGraph(!fEnable);

    // if we are enabling the vertical box, disable horizontal box if it's enabled
    if(!fEnable && m_LCD.getHorizontalGraphEnabled()) {
        m_LCD.setHorizontalGraphEnabled(false);
        ToggleHorizontalGraph(false);
    }
}

void MiniLCDFrame::OntogglebtnVerticalThinToggle(wxCommandEvent& event)
{
}

void MiniLCDFrame::OntogglebtnVerticalThickToggle(wxCommandEvent& event)
{
}

void MiniLCDFrame::OnslideVertical1CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical2CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical3CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical4CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical5CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical6CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical7CmdSliderUpdated(wxScrollEvent& event)
{
}

void MiniLCDFrame::OnslideVertical8CmdSliderUpdated(wxScrollEvent& event)
{
}
