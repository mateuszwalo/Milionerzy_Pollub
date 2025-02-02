/***************************************************************
 * Name:      ProjektApp.h
 * Purpose:   Defines Application Class
 * Author:    Igor Kozak ()
 * Created:   2024-12-17
 * Copyright: Igor Kozak ()
 * License:
 **************************************************************/

#ifndef PROJEKTAPP_H
#define PROJEKTAPP_H
#include "include/json.hpp"
#include <string>
#include <vector>
#include <wx/app.h>

class ProjektApp : public wxApp
{
public:
    virtual bool OnInit();
};

#endif // PROJEKTAPP_H
