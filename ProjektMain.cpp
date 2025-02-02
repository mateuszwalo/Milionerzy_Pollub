#include "ProjektMain.h"
#include <wx/msgdlg.h>
#include "ProjektApp.h"
#include <wx/choicdlg.h>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include "include/json.hpp"
#include <algorithm>

#undef _
#define _(s) wxString::FromUTF8(s)
#include <wx/dcclient.h>

using json = nlohmann::json;

//(*InternalHeaders(ProjektDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

struct Question {
    std::string tresc;
    std::vector<std::string> odpowiedzi;
    std::string poprawna_odpowiedz;
};

std::vector<Question> questions;
std::vector<bool> askedQuestions;
size_t currentQuestionIndex = 0;

bool fiftyFiftyUsed = false;
bool phoneAFriendUsed = false;
bool fiftyFiftyUsedGlobal = false;
bool phoneAFriendUsedGlobal = false;

int points = 0;

enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
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

//(*IdInit(ProjektDialog)
const long ProjektDialog::ID_STATICBITMAP1 = wxNewId();
const long ProjektDialog::ID_TEXTCTRL1 = wxNewId();
const long ProjektDialog::ID_BUTTON1 = wxNewId();
const long ProjektDialog::ID_BUTTON2 = wxNewId();
const long ProjektDialog::ID_BUTTON3 = wxNewId();
const long ProjektDialog::ID_BUTTON4 = wxNewId();
const long ProjektDialog::ID_BUTTON5 = wxNewId();
const long ProjektDialog::ID_BUTTON6 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProjektDialog, wxDialog)
//(*EventTable(ProjektDialog)
//*)
END_EVENT_TABLE()

void ProjektDialog::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    wxBitmap backgroundBitmap(wxT("resources/kosmos.jpg"), wxBITMAP_TYPE_JPEG);

    wxImage scaledImage = backgroundBitmap.ConvertToImage();
    scaledImage = scaledImage.Scale(GetSize().GetWidth(), GetSize().GetHeight());

    dc.DrawBitmap(wxBitmap(scaledImage), 0, 0, true);

    event.Skip();
}

ProjektDialog::ProjektDialog(wxWindow* parent, wxWindowID id)
    : points(0), fiftyFiftyUsed(false), phoneAFriendUsed(false), fiftyFiftyUsedGlobal(false), phoneAFriendUsedGlobal(false)
{
    //(*Initialize(ProjektDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("Milionerzy Pollub "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("resources\\logo-1.png")).Rescale(wxSize(461,149).GetWidth(), wxSize(461,149).GetHeight())), wxDefaultPosition, wxSize(461,149), 0, _T("ID_STATICBITMAP1"));
    BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxSize(463,149), wxTE_READONLY|wxTE_CENTRE|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    BoxSizer2->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1 = new wxFlexGridSizer(2, 2, 10, 10);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableRow(0);
    FlexGridSizer1->AddGrowableRow(1);
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxSize(215,55), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxDefaultPosition, wxSize(213,61), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    FlexGridSizer1->Add(Button2, 1, wxALL|wxEXPAND, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Label"), wxDefaultPosition, wxSize(227,58), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    FlexGridSizer1->Add(Button3, 1, wxALL|wxEXPAND, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Label"), wxDefaultPosition, wxSize(210,52), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    FlexGridSizer1->Add(Button4, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Button5 = new wxButton(this, ID_BUTTON5, _("50/50"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer3->Add(Button5, 1, wxALL|wxEXPAND, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Telefon do przyjaciela"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button6->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    BoxSizer3->Add(Button6, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    wxFont font(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    TextCtrl1->SetFont(font);
    Bind(wxEVT_PAINT, &ProjektDialog::OnPaint, this);

    // Choose difficulty level
    wxArrayString choices;
    choices.Add(_("Łatwy"));
    choices.Add(_("Średni"));
    choices.Add(_("Trudny"));
    wxSingleChoiceDialog difficultyDialog(this, _("Wybierz poziom trudności:"), _("Poziom trudności"), choices);
    if (difficultyDialog.ShowModal() == wxID_OK)
    {
        wxString selectedDifficulty = difficultyDialog.GetStringSelection();
        if (selectedDifficulty == _("Łatwy"))
        {
            LoadQuestionsFromFile("baza_pytan.json");
        }
        else if (selectedDifficulty == _("Średni"))
        {
            LoadQuestionsFromFile("baza_pytan_1.json");
        }
        else if (selectedDifficulty == _("Trudny"))
        {
            LoadQuestionsFromFile("baza_pytan_2.json");
        }
    }

    // Set up button event handlers
    Bind(wxEVT_BUTTON, &ProjektDialog::OnButtonClicked, this, ID_BUTTON1);
    Bind(wxEVT_BUTTON, &ProjektDialog::OnButtonClicked, this, ID_BUTTON2);
    Bind(wxEVT_BUTTON, &ProjektDialog::OnButtonClicked, this, ID_BUTTON3);
    Bind(wxEVT_BUTTON, &ProjektDialog::OnButtonClicked, this, ID_BUTTON4);
    Bind(wxEVT_BUTTON, &ProjektDialog::OnFiftyFifty, this, ID_BUTTON5);
    Bind(wxEVT_BUTTON, &ProjektDialog::OnPhoneAFriend, this, ID_BUTTON6);

    // Display the first question
    DisplayQuestion();
    //*)
}

ProjektDialog::~ProjektDialog()
{
}

void ProjektDialog::DisplayQuestion()
{
    if (questions.empty())
    {
        wxMessageBox(_("Brak pytań! :( "), _("Error"), wxOK | wxICON_ERROR);
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, questions.size() - 1);
    do {
        currentQuestionIndex = dis(gen);
    } while (askedQuestions[currentQuestionIndex]);

    askedQuestions[currentQuestionIndex] = true;
    Question& question = questions[currentQuestionIndex];

    std::vector<std::string> shuffledAnswers = question.odpowiedzi;

    std::shuffle(shuffledAnswers.begin(), shuffledAnswers.end(), gen);

    TextCtrl1->SetValue(wxString::FromUTF8(question.tresc));
    Button1->SetLabel(wxString::FromUTF8(shuffledAnswers[0]));
    Button2->SetLabel(wxString::FromUTF8(shuffledAnswers[1]));
    Button3->SetLabel(wxString::FromUTF8(shuffledAnswers[2]));
    Button4->SetLabel(wxString::FromUTF8(shuffledAnswers[3]));

    fiftyFiftyUsed = false;
    phoneAFriendUsed = false;
}

void ProjektDialog::LoadQuestionsFromFile(const wxString& fileName)
{
    std::ifstream file(fileName.ToStdString());
    if (file.is_open())
    {
        json jsonData;
        file >> jsonData;
        questions.clear();
        askedQuestions.clear();
        for (const auto& item : jsonData["pytania"])
        {
            Question q;
            q.tresc = item["tresc"];
            q.odpowiedzi = item["odpowiedzi"].get<std::vector<std::string>>();
            q.poprawna_odpowiedz = item["poprawna_odpowiedz"];
            questions.push_back(q);
            askedQuestions.push_back(false);
        }
        file.close();
    }
    else
    {
        wxMessageBox(_("Nie można wczytać bazy pytań"), _("Error"), wxOK | wxICON_ERROR);
    }
}

std::string trimString(const std::string& str)
{
    std::string trimmed = str;
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), trimmed.end());
    return trimmed;
}

void ProjektDialog::OnButtonClicked(wxCommandEvent& event)
{
    int buttonId = event.GetId();
    std::string correctAnswer = trimString(questions[currentQuestionIndex].poprawna_odpowiedz);

    wxButton* clickedButton = dynamic_cast<wxButton*>(event.GetEventObject());
    if (clickedButton)
    {
        std::string userAnswer = trimString(clickedButton->GetLabel().ToStdString());
        std::transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
        std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

        if (userAnswer == correctAnswer)
        {
            points += 100;
            wxMessageBox(wxString::Format(_("Brawo poprawna odpowiedź! Masz teraz %d punktów."), points), _("Info"), wxOK | wxICON_INFORMATION);
            if (points >= 1000)
            {
                wxMessageBox(_("🎉 Gratulacje! Wygrałeś grę! 🎉"), _("Info"), wxOK | wxICON_INFORMATION);
                points = 0;
                std::fill(askedQuestions.begin(), askedQuestions.end(), false);
            }
            DisplayQuestion();
        }
        else
        {
            points = 0;
            wxMessageBox(wxString::Format(_("Zła odpowiedź. Przegrywasz :( Zaczynamy od początku. Masz teraz %d punktów."), points), _("Info"), wxOK | wxICON_WARNING);
            std::fill(askedQuestions.begin(), askedQuestions.end(), false);
            fiftyFiftyUsedGlobal = false;
            phoneAFriendUsedGlobal = false;
            DisplayQuestion();
        }
    }
}

void ProjektDialog::OnFiftyFifty(wxCommandEvent& event)
{
    if (fiftyFiftyUsed || fiftyFiftyUsedGlobal || phoneAFriendUsed)
    {
        wxMessageBox(_("Użyłeś już kół ratunkowych! Graj dalej bez nich!"), _("Info"), wxOK | wxICON_INFORMATION);
        return;
    }

    fiftyFiftyUsed = true;
    fiftyFiftyUsedGlobal = true;

    std::string correctAnswer = questions[currentQuestionIndex].poprawna_odpowiedz;
    std::vector<wxButton*> buttons = {Button1, Button2, Button3, Button4};
    std::vector<wxButton*> incorrectButtons;

    for (auto button : buttons)
    {
        if (button->GetLabel().ToStdString() != correctAnswer)
        {
            incorrectButtons.push_back(button);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(incorrectButtons.begin(), incorrectButtons.end(), gen);
    incorrectButtons[0]->SetLabel("");
    incorrectButtons[1]->SetLabel("");
}

void ProjektDialog::OnPhoneAFriend(wxCommandEvent& event)
{
    if (phoneAFriendUsed || phoneAFriendUsedGlobal || fiftyFiftyUsed)
    {
        wxMessageBox(_("Użyłeś już kół ratunkowych! Graj dalej bez nich!"), _("Info"), wxOK | wxICON_INFORMATION);
        return;
    }

    phoneAFriendUsed = true;
    phoneAFriendUsedGlobal = true;

    std::string correctAnswer = questions[currentQuestionIndex].poprawna_odpowiedz;
    std::vector<wxButton*> buttons = {Button1, Button2, Button3, Button4};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(buttons.begin(), buttons.end(), gen);

    int hiddenCount = 0;
    for (auto button : buttons)
    {
        if (button->GetLabel().ToStdString() != correctAnswer && hiddenCount < 3)
        {
            button->SetLabel("");
            hiddenCount++;
        }
    }
}

void ProjektDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ProjektDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

int main()
{
    wxApp::SetInstance(new ProjektApp);
    return wxEntry();
}

void ProjektDialog::OnInit(wxInitDialogEvent& event)
{
}

void ProjektDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}
