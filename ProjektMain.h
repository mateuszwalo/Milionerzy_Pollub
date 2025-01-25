/***************************************************************
 * Name:      ProjektMain.h
 * Purpose:   Defines Application Frame
 * Author:    Igor Kozak ()
 * Created:   2024-12-17
 * Copyright: Igor Kozak ()
 * License:
 **************************************************************/

#ifndef PROJEKTMAIN_H
#define PROJEKTMAIN_H

//(*Headers(ProjektDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
//*)
#include <chrono>

class ProjektDialog : public wxDialog
{
public:
    ProjektDialog(wxWindow* parent, wxWindowID id = -1);
    virtual ~ProjektDialog();

private:
    void DisplayQuestion();
    void OnButtonClicked(wxCommandEvent& event);
    void OnFiftyFifty(wxCommandEvent& event);
    void OnPhoneAFriend(wxCommandEvent& event);
    void LoadQuestionsFromFile(const wxString& fileName);

    bool fiftyFiftyUsed;
    bool phoneAFriendUsed;
    bool fiftyFiftyUsedGlobal;
    bool phoneAFriendUsedGlobal;

    int points;


    //(*Handlers(ProjektDialog)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnTextCtrl1Text(wxCommandEvent& event);
    void OnTextCtrl1Text1(wxCommandEvent& event);
    //*)

    //(*Identifiers(ProjektDialog)
    static const long ID_STATICBITMAP1;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    //*)

    //(*Declarations(ProjektDialog)
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxButton* Button4;
    wxButton* Button5;
    wxButton* Button6;
    wxStaticBitmap* StaticBitmap1;
    wxTextCtrl* TextCtrl1;
    //*)

    DECLARE_EVENT_TABLE()
    void OnPaint(wxPaintEvent& event);
};

#endif // PROJEKTMAIN_H
