#ifndef WXRAROPTIONS_H
#define WXRAROPTIONS_H

#include <wx/msgdlg.h>

#include "GUIFrame.h"
#include "wx/dirdlg.h"

class wxRarOptions : public MyDialog1
{
    public:
        wxRarOptions(wxWindow *parent, int id, wxString path, long numeroProcessi, bool aggiornamenti);
        virtual ~wxRarOptions();
        int GetTerminal();
        long getNumeroProcessi();
        wxString GetPath();
		bool getAggiornamenti();
    private:
        int terminal;
        wxString path, numeroProcessiStr;
        long numeroProcessi;
        bool aggiornamenti;
  		virtual void OnSelect( wxCommandEvent& event ) ;
		virtual void OnOK( wxCommandEvent& event );

};

#endif // WXXRAROPTIONS_H
