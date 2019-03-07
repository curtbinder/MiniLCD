/***************************************************************
 * Name:      MiniLCDApp.h
 * Purpose:   Defines Application Class
 * Author:    Curt Binder (binder@curtbinder.info)
 * Created:   2019-03-04
 * Copyright: Curt Binder (https://curtbinder.info/)
 * License:
 **************************************************************/

#ifndef MINILCDAPP_H
#define MINILCDAPP_H

#include <wx/app.h>

class MiniLCDApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // MINILCDAPP_H
