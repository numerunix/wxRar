///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFRAME_H__
#define __GUIFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001
#define idMenuAggiornamenti 1002
#define idMenuSitoWeb 1003

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxButton* m_button1;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxStatusBar* m_statusBar1;
		wxStaticText* m_staticText9;
		wxTextCtrl *m_textCtrl2;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnOpzioni( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelezionaRar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelezionaDir( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOk( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAggiornamenti(wxCommandEvent& evt) {evt.Skip();}
		virtual void onSitoWeb(wxCommandEvent& evt) {evt.Skip();}


	public:

		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxRar"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL );

		~GUIFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog
{
	private:
	protected:
	    bool ok;
		wxStaticText* m_staticText5;
		wxChoice* m_choice1;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button5;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textCtrl3;
		wxCheckBox* m_checkBox1;
		wxButton* m_button6;
		wxButton* m_button7;

		// Virtual event handlers, overide them in your derived class
		virtual void OnSelect( wxCommandEvent& event )=0;
		virtual void OnOK(wxCommandEvent& event) =0;


	public:

		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Opzioni"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		bool getOk() {return ok;}
		~MyDialog1();

};

#endif //__GUIFRAME_H__
