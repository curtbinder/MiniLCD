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
const long MiniLCDFrame::ID_BUTTON1 = wxNewId();
const long MiniLCDFrame::ID_BUTTON2 = wxNewId();
const long MiniLCDFrame::ID_BUTTON3 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX1 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX2 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX3 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX4 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX5 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX6 = wxNewId();
const long MiniLCDFrame::ID_TEXTCTRL1 = wxNewId();
const long MiniLCDFrame::ID_STATICTEXT1 = wxNewId();
const long MiniLCDFrame::ID_TEXTCTRL2 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX7 = wxNewId();
const long MiniLCDFrame::ID_STATICBOX1 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX8 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX9 = wxNewId();
const long MiniLCDFrame::ID_SLIDER1 = wxNewId();
const long MiniLCDFrame::ID_SLIDER2 = wxNewId();
const long MiniLCDFrame::ID_STATICBOX2 = wxNewId();
const long MiniLCDFrame::ID_CHECKBOX10 = wxNewId();
const long MiniLCDFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long MiniLCDFrame::ID_TOGGLEBUTTON2 = wxNewId();
const long MiniLCDFrame::ID_SLIDER3 = wxNewId();
const long MiniLCDFrame::ID_SLIDER4 = wxNewId();
const long MiniLCDFrame::ID_SLIDER5 = wxNewId();
const long MiniLCDFrame::ID_SLIDER6 = wxNewId();
const long MiniLCDFrame::ID_SLIDER7 = wxNewId();
const long MiniLCDFrame::ID_SLIDER8 = wxNewId();
const long MiniLCDFrame::ID_SLIDER9 = wxNewId();
const long MiniLCDFrame::ID_SLIDER10 = wxNewId();
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
    Button1 = new wxButton(this, ID_BUTTON1, _("Clear Screen"), wxPoint(8,8), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("New Line"), wxPoint(8,48), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Write Text"), wxPoint(8,88), wxSize(104,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("GPO"), wxPoint(120,8), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Show Cursor"), wxPoint(120,32), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("Blink Cursor"), wxPoint(120,56), wxSize(112,18), 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    CheckBox4 = new wxCheckBox(this, ID_CHECKBOX4, _("Backlight"), wxPoint(240,8), wxSize(88,18), 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    CheckBox4->SetValue(false);
    CheckBox5 = new wxCheckBox(this, ID_CHECKBOX5, _("Auto Scroll"), wxPoint(240,32), wxSize(104,18), 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    CheckBox5->SetValue(false);
    CheckBox6 = new wxCheckBox(this, ID_CHECKBOX6, _("Line Wrap"), wxPoint(240,56), wxSize(104,18), 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    CheckBox6->SetValue(false);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(336,8), wxSize(32,18), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("minutes"), wxPoint(376,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(120,88), wxSize(240,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    CheckBox7 = new wxCheckBox(this, ID_CHECKBOX7, _("Update"), wxPoint(368,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    CheckBox7->SetValue(false);
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Horizontal Bar Graph"), wxPoint(8,128), wxSize(432,104), 0, _T("ID_STATICBOX1"));
    CheckBox8 = new wxCheckBox(this, ID_CHECKBOX8, _("Enable"), wxPoint(16,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    CheckBox8->SetValue(false);
    CheckBox9 = new wxCheckBox(this, ID_CHECKBOX9, _("Reverse"), wxPoint(96,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    CheckBox9->SetValue(false);
    Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxPoint(16,176), wxSize(416,24), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    Slider2 = new wxSlider(this, ID_SLIDER2, 0, 0, 100, wxPoint(16,200), wxSize(416,24), 0, wxDefaultValidator, _T("ID_SLIDER2"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Vertical Bar Graph"), wxPoint(8,240), wxSize(432,104), 0, _T("ID_STATICBOX2"));
    CheckBox10 = new wxCheckBox(this, ID_CHECKBOX10, _("Enable"), wxPoint(16,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
    CheckBox10->SetValue(false);
    ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("Thin"), wxPoint(16,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("Thick"), wxPoint(16,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
    Slider3 = new wxSlider(this, ID_SLIDER3, 0, 0, 100, wxPoint(112,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER3"));
    Slider4 = new wxSlider(this, ID_SLIDER4, 0, 0, 100, wxPoint(144,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER4"));
    Slider5 = new wxSlider(this, ID_SLIDER5, 0, 0, 100, wxPoint(176,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER5"));
    Slider6 = new wxSlider(this, ID_SLIDER6, 0, 0, 100, wxPoint(208,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER6"));
    Slider7 = new wxSlider(this, ID_SLIDER7, 0, 0, 100, wxPoint(240,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER7"));
    Slider8 = new wxSlider(this, ID_SLIDER8, 0, 0, 100, wxPoint(272,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER8"));
    Slider9 = new wxSlider(this, ID_SLIDER9, 0, 0, 100, wxPoint(304,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER9"));
    Slider10 = new wxSlider(this, ID_SLIDER10, 0, 0, 100, wxPoint(336,264), wxSize(32,72), wxSL_VERTICAL, wxDefaultValidator, _T("ID_SLIDER10"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MiniLCDFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MiniLCDFrame::OnAbout);
    //*)
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
