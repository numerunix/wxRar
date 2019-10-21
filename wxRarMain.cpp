/***************************************************************
 * Name:      wxRarMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2015-11-16
 * Copyright: Giulio Sorrentino ()
 * License:   GPL V3
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxRarMain.h"

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
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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


wxRarFrame::wxRarFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    versione="0.1.1";
    paginaWeb="http://numerone.altervista.org";
    fileSelezionato=false;
    dirSelezionata=false;
    config=new wxConfig("wxRar");
    config->Read("terminal", &terminal, 1);
    config->Read("path", &path, wxT("./"));
    config->Read("processi", &numeroProcessi, 1);
    if (!config->Read("aggiornamentiAutomatici", &aggiornamenti))
        aggiornamenti=false;
 /* 	client.SetHeader("Content-type", "text/html; charset=utf-8");
    client.SetTimeout(10);
    if (aggiornamenti) {
        wxString s;
        try {
            if (Aggiornamenti(s)) {
                wxMessageBox(wxT("Sono presenti aggiornamenti, il programma aprira' la pagina per il download."), wxT("Informazioni"), wxICON_INFORMATION);
                wxLaunchDefaultBrowser(paginaWeb);
            }
        } catch (std::domain_error e) {
            wxMessageBox(wxString(e.what()), wxT("Errore"), wxOK|wxICON_ERROR);
        }
    }*/
}

wxRarFrame::~wxRarFrame()
{
    config->Write("terminal", terminal);
    config->Write("path", path);
    config->Write("processi", numeroProcessi);
    config->Write("aggiornamentiAutomatici", aggiornamenti);
    delete config;
}

void wxRarFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxRarFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxRarFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxAboutDialogInfo info;
    info.SetName("wxRar");
    info.SetVersion(versione);
    info.SetDescription(wxT("Batch GUI per il programma unrar. Permette di scompattare più rar per volta"));
    info.SetCopyright(_T("(C) 2019 Giulio Sorrentino <gsorre84@gmail.com>"));
    info.SetLicence(_T("GPL v3 o, a tua discrezione, qualsiasi versione successiva."));
    info.SetWebSite("http://numerone.altervista.org");
    wxAboutBox(info);
}


void wxRarFrame::OnSelezionaRar(wxCommandEvent &evt) {
    wxDirDialog *dirDialog=new wxDirDialog(this, wxT("Seleziona una directory"));
    if (dirDialog->ShowModal()==wxID_OK) {
        m_staticText2->SetLabel(dirDialog->GetPath());
    }
    fileSelezionato=true;
    m_button3->Enable(fileSelezionato && dirSelezionata);
}

void wxRarFrame::OnSelezionaDir(wxCommandEvent &evt) {
    wxDirDialog *dirDialog=new wxDirDialog(this, wxT("Seleziona una directory"));
    if (dirDialog->ShowModal()==wxID_OK) {
        m_staticText4->SetLabel(dirDialog->GetPath());
    }
    dirSelezionata=true;
    m_button3->Enable(fileSelezionato && dirSelezionata);
}

void wxRarFrame::OnOk(wxCommandEvent & evt) {
    wxDir dir(m_staticText2->GetLabel());
    wxDir *dir1;
    wxString f, f1, console, password=wxEmptyString, errore=wxEmptyString, file;
    wxArrayString as;
    bool cont;
    size_t i;
    if (!dir.IsOpened()) {
        wxMessageBox(wxT("Directory non aperta"),wxT("Errore"), wxICON_ERROR);
        return;
    }
    cont=dir.HasSubDirs();
    if (!cont) {
        wxMessageBox(wxT("La directory non contiene altre directory. Selezionare la directory esatta."), wxT("Attenzione"), wxICON_INFORMATION);
        return;
    }
    if (!wxFileExists(path+wxFileName::GetPathSeparator()+wxT("unrar"))) {
        wxMessageBox(wxT("File unrar non trovato. Indicare la path nelle opzioni"), wxT("Errore"), wxICON_ERROR);
        return;
    }
    switch(terminal) {
       case 0: console="xterm -hold -e"; break;
       case 1: console="konsole --noclose -e"; break;
       case 2: console="gnome-terminal --profile=\"non chiudere\" -e";
    }
    dir.GetFirst(&f, wxEmptyString, wxDIR_DIRS);
    do {
        dir1=new wxDir(m_staticText2->GetLabel()+wxFileName::GetPathSeparator()+f);
        if (!dir1->IsOpened()) {
            wxMessageBox(wxT("Impossibile aprire la directory ")+dir1->GetName(), _T("Attenzione"), wxICON_INFORMATION);
            continue;
        }
        if (!dir1->GetFirst(&f1,"*.part01.rar")) {
            errore+=dir1->GetName()+"\n";
            delete dir1;
            continue;
        }
        if (!m_textCtrl2->GetValue().IsEmpty())
            password=" -p"+m_textCtrl2->GetValue();
        else 
            password=wxEmptyString;
            
        file=m_staticText2->GetLabel()+wxFileName::GetPathSeparator()+f+wxFileName::GetPathSeparator()+f1;
        as.Add(console+" \" \\\""+path+wxFileName::GetPathSeparator()+"unrar\\\" x \\\""+file+("\\\"")+password+"\"");
        delete dir1;
    } while (dir.GetNext(&f));
    wxString a;
    if (errore != wxEmptyString)
        wxMessageBox(wxT("Ignoro le directory ")+errore+wxT(" che non contengono file rar."), wxT("Attenzione"), wxICON_ASTERISK);
    for (i=0; i<as.GetCount(); i++) {
        SetStatusText(wxT("Estrazione del rar ")
                          +wxString::Format("%zd",i+1)
                          +wxT(" di ")
                          +wxString::Format("%zd",as.GetCount()));
      //  wxMessageBox(as.Item(i));
        wxSetWorkingDirectory(m_staticText4->GetLabel());
        wxExecute(as.Item(i), wxEXEC_ASYNC);
        if (((i+1) % numeroProcessi==0 || numeroProcessi==1) && i<as.GetCount()-1)
            wxMessageBox(wxT("Messaggio di blocco, premere ok per continuare."), wxT("Informazione"), wxICON_INFORMATION);
    }
    SetStatusText(wxT("Operazione completata"));
}

void wxRarFrame::OnOpzioni( wxCommandEvent& event ) {
    wxRarOptions *d = new wxRarOptions(this, terminal, path, numeroProcessi, aggiornamenti);
    d->ShowModal();
    if (d->getOk()) {
        terminal=d->GetTerminal();
        path=d->GetPath();
        numeroProcessi=d->getNumeroProcessi();
        aggiornamenti=d->getAggiornamenti();
    }
}

/*bool wxRarFrame::Aggiornamenti(wxString &nuovaVersione) throw (std::domain_error) {
    bool aggiornamenti=false;
    if (client.Connect(wxT("numerone.altervista.org"))) {
        if (client.GetError() == wxPROTO_NOERR)
        {
            wxInputStream *stream = client.GetInputStream(_T("/wxxrar.html"));
            if (stream==wxNullPtr)
                throw std::domain_error("Si e' verificato un errore nel recuperare le informazioni. Riprovare piu' tardi");
            else {
                wxStringOutputStream out_stream(&nuovaVersione);
                stream->Read(out_stream);
                nuovaVersione=nuovaVersione.RemoveLast();
                aggiornamenti=!nuovaVersione.IsSameAs(versione);
                delete stream;
            }
        }
        client.Close();
    } else {
        wxMessageBox(wxT("Impossibile connettersi. Riprovare piu' tardi."), wxT("Errore"), wxICON_ERROR);
    }
    return aggiornamenti;
}

void wxRarFrame::onAggiornamenti(wxCommandEvent& evt) {
    wxString versioneOttenuta;
    try {
        if (!Aggiornamenti(versioneOttenuta))
            wxMessageBox(wxT("Stai usando l'ultima versione di wxRar"), wxT("Complimenti"), wxICON_INFORMATION);
        else if (wxMessageBox(wxT("La versione che stai usando e' la ")+versione+wxT(". Sul sito e' presente la ")+versioneOttenuta+wxT(".\nVuoi aprire il browser per scaricarlo ora?"), wxT("Aggiornamento disponibile"), wxICON_INFORMATION | wxYES_NO)==wxYES)
                wxLaunchDefaultBrowser(paginaWeb);
    } catch (std::domain_error e) {
        wxMessageBox(wxString(e.what()), wxT("Errore"), wxOK|wxICON_ERROR);
    }
}*/

void wxRarFrame::onSitoWeb(wxCommandEvent &evt) {
    wxLaunchDefaultBrowser(wxT("http://numerone.altervista.org"));
}
