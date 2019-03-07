/***************************************************************
 * Name:      MiniLCDMain.h
 * Purpose:   Defines Application Frame
 * Author:    Curt Binder (binder@curtbinder.info)
 * Created:   2019-03-04
 * Copyright: Curt Binder (https://curtbinder.info/)
 * License:
 **************************************************************/

#ifndef MINILCDMAIN_H
#define MINILCDMAIN_H

//(*Headers(MiniLCDFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/slider.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class MiniLCDFrame: public wxFrame
{
    public:

        MiniLCDFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MiniLCDFrame();

    private:

        //(*Handlers(MiniLCDFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(MiniLCDFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX5;
        static const long ID_CHECKBOX6;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL2;
        static const long ID_CHECKBOX7;
        static const long ID_STATICBOX1;
        static const long ID_CHECKBOX8;
        static const long ID_CHECKBOX9;
        static const long ID_SLIDER1;
        static const long ID_SLIDER2;
        static const long ID_STATICBOX2;
        static const long ID_CHECKBOX10;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_TOGGLEBUTTON2;
        static const long ID_SLIDER3;
        static const long ID_SLIDER4;
        static const long ID_SLIDER5;
        static const long ID_SLIDER6;
        static const long ID_SLIDER7;
        static const long ID_SLIDER8;
        static const long ID_SLIDER9;
        static const long ID_SLIDER10;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(MiniLCDFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxCheckBox* CheckBox10;
        wxCheckBox* CheckBox1;
        wxCheckBox* CheckBox2;
        wxCheckBox* CheckBox3;
        wxCheckBox* CheckBox4;
        wxCheckBox* CheckBox5;
        wxCheckBox* CheckBox6;
        wxCheckBox* CheckBox7;
        wxCheckBox* CheckBox8;
        wxCheckBox* CheckBox9;
        wxSlider* Slider10;
        wxSlider* Slider1;
        wxSlider* Slider2;
        wxSlider* Slider3;
        wxSlider* Slider4;
        wxSlider* Slider5;
        wxSlider* Slider6;
        wxSlider* Slider7;
        wxSlider* Slider8;
        wxSlider* Slider9;
        wxStaticBox* StaticBox1;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxToggleButton* ToggleButton1;
        wxToggleButton* ToggleButton2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MINILCDMAIN_H
