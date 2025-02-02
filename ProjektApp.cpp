/***************************************************************
 * Name:      ProjektApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Igor Kozak ()
 * Created:   2024-12-17
 * Copyright: Igor Kozak ()
 * License:
 **************************************************************/

#include "ProjektApp.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include "include/json.hpp"
using json = nlohmann::json;

//(*AppHeaders
#include "ProjektMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProjektApp);

bool ProjektApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    ProjektDialog Dlg(0);
    SetTopWindow(&Dlg);
    Dlg.ShowModal();
    wxsOK = false;
    }
    //*)
    return wxsOK;
}
