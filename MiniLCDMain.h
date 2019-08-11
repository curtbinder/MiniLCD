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

#include "LCD.h"

class MiniLCDFrame: public wxFrame
{
    public:

        MiniLCDFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MiniLCDFrame();

    private:

        //(*Handlers(MiniLCDFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnClearScreenClick(wxCommandEvent& event);
        void OnbtnNewLineClick(wxCommandEvent& event);
        void OnbtnWriteTextClick(wxCommandEvent& event);
        void OnckGPIOClick(wxCommandEvent& event);
        void OnckShowCursorClick(wxCommandEvent& event);
        void OnckBlinkCursorClick(wxCommandEvent& event);
        void OnckBacklightClick(wxCommandEvent& event);
        void OnckAutoScrollClick(wxCommandEvent& event);
        void OnckLineWrapClick(wxCommandEvent& event);
        void OnckUpdateClick(wxCommandEvent& event);
        void OnckEnableHorizontalClick(wxCommandEvent& event);
        void OnckHorizontalReverseClick(wxCommandEvent& event);
        void OnslideHorizontal1CmdSliderUpdated(wxScrollEvent& event);
        void OnslideHorizontal2CmdSliderUpdated(wxScrollEvent& event);
        void OnckVerticalEnableClick(wxCommandEvent& event);
        void OntogglebtnVerticalThinToggle(wxCommandEvent& event);
        void OntogglebtnVerticalThickToggle(wxCommandEvent& event);
        void OnslideVertical1CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical2CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical3CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical4CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical5CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical6CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical7CmdSliderUpdated(wxScrollEvent& event);
        void OnslideVertical8CmdSliderUpdated(wxScrollEvent& event);
        //*)

        //(*Identifiers(MiniLCDFrame)
        static const long ID_BUTTON_CLEAR_SCREEN;
        static const long ID_BUTTON_NEW_LINE;
        static const long ID_BUTTON_WRITE_TEXT;
        static const long ID_CHECKBOX_GPIO;
        static const long ID_CHECKBOX_SHOW_CURSOR;
        static const long ID_CHECKBOX_BLINK_CURSOR;
        static const long ID_CHECKBOX_BACKLIGHT;
        static const long ID_CHECKBOX_AUTO_SCROLL;
        static const long ID_CHECKBOX_LINE_WRAP;
        static const long ID_TEXTCTRL_BACKLIGHT_MINUTES;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL_MESSAGE;
        static const long ID_CHECKBOX_UPDATE;
        static const long ID_STATICBOX1;
        static const long ID_CHECKBOX_ENABLE_HORIZONTAL;
        static const long ID_CHECKBOX_HORIZONTAL_REVERSE;
        static const long ID_SLIDER_HORIZONTAL_1;
        static const long ID_SLIDER_HORIZONTAL_2;
        static const long ID_STATICBOX2;
        static const long ID_CHECKBOX_VERTICAL_ENABLE;
        static const long ID_TOGGLEBUTTON_VERTICAL_THIN;
        static const long ID_TOGGLEBUTTON_VERTICAL_THICK;
        static const long ID_SLIDER_VERTICAL_1;
        static const long ID_SLIDER_VERTICAL_2;
        static const long ID_SLIDER_VERTICAL_3;
        static const long ID_SLIDER_VERTICAL_4;
        static const long ID_SLIDER_VERTICAL_5;
        static const long ID_SLIDER_VERTICAL_6;
        static const long ID_SLIDER_VERTICAL_7;
        static const long ID_SLIDER_VERTICAL_8;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(MiniLCDFrame)
        wxButton* btnClearScreen;
        wxButton* btnNewLine;
        wxButton* btnWriteText;
        wxCheckBox* ckAutoScroll;
        wxCheckBox* ckBacklight;
        wxCheckBox* ckBlinkCursor;
        wxCheckBox* ckGPIO;
        wxCheckBox* ckHorizontalEnable;
        wxCheckBox* ckHorizontalReverse;
        wxCheckBox* ckLineWrap;
        wxCheckBox* ckShowCursor;
        wxCheckBox* ckUpdate;
        wxCheckBox* ckVerticalEnable;
        wxSlider* slideHorizontal1;
        wxSlider* slideHorizontal2;
        wxSlider* slideVertical1;
        wxSlider* slideVertical2;
        wxSlider* slideVertical3;
        wxSlider* slideVertical4;
        wxSlider* slideVertical5;
        wxSlider* slideVertical6;
        wxSlider* slideVertical7;
        wxSlider* slideVertical8;
        wxStaticBox* StaticBox1;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* editBacklightMinutes;
        wxTextCtrl* editMessage;
        wxToggleButton* togglebtnVerticalThick;
        wxToggleButton* togglebtnVerticalThin;
        //*)

        DECLARE_EVENT_TABLE()

        LCD m_LCD;
        void ToggleVerticalGraph(bool fEnable);
        void ToggleHorizontalGraph(bool fEnable);
};

#endif // MINILCDMAIN_H
