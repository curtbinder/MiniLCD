/***************************************************************
 * Name:      MiniLCDApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Curt Binder (binder@curtbinder.info)
 * Created:   2019-03-04
 * Copyright: Curt Binder (https://curtbinder.info/)
 * License:
 **************************************************************/

#include "MiniLCDApp.h"

//(*AppHeaders
#include "MiniLCDMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MiniLCDApp);

bool MiniLCDApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MiniLCDFrame* Frame = new MiniLCDFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
