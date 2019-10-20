///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("Opzioni") ) + "\tALT + O\n", wxT("Imposta le opzioni"), wxITEM_NORMAL );
	fileMenu->Append( m_menuItem3 );

	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Esci") ) + "\tAlt+F4", wxT("Esci dall'applicazione"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );

	mbar->Append( fileMenu, wxT("&File") );

	helpMenu = new wxMenu();

	wxMenuItem* menuHelpSitoWeb;
	menuHelpSitoWeb = new wxMenuItem(helpMenu, idMenuSitoWeb, wxString(wxT("Sito web ufficiale")) + "\tAlt+F3", wxT("Apre il browser col sito web"), wxITEM_NORMAL);
	helpMenu->Append(menuHelpSitoWeb);

	/*wxMenuItem* menuHelpAggiornamenti;
	menuHelpAggiornamenti = new wxMenuItem(helpMenu, idMenuAggiornamenti, wxT("Verifica aggiornamenti\tF2"), wxT("Ricerca aggiornamenti"), wxITEM_NORMAL);
    helpMenu->Append(menuHelpAggiornamenti);*/


	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&Informazioni") ) + "\tF1", wxT("Mostra le informazioni relative l'applicazione"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );


	mbar->Append( helpMenu, wxT("&Aiuto") );

	this->SetMenuBar( mbar );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Seleziona la cartella dei files:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Non Selezionato"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Seleziona"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button1, 0, wxALL, 5 );


	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Seleziona la cartella di estrazione"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALL, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Non selezionato"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer3->Add( m_staticText4, 0, wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Seleziona"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button2, 0, wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer(wxVERTICAL);
    m_staticText9 = new wxStaticText(this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText9->Wrap(-1);
    bSizer7->Add(m_staticText9, 0, wxALL, 5);
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition,wxSize(250,30), 0 );
	m_textCtrl2->SetMaxLength( 0 );
	bSizer7->Add( m_textCtrl2, 0, wxALL, 5 );



	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );


	m_button3 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->Enable( false );

	bSizer6->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_CANCEL, wxT("Esci"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button4, 0, wxALL, 5 );


	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );

	bSizer1->Add(bSizer7, 1, wxEXPAND, 5);

	bSizer1->Add( bSizer6, 1, wxEXPAND, 5 );



	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnOpzioni ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
//	this->Connect(menuHelpAggiornamenti->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUIFrame::onAggiornamenti));
	this->Connect(menuHelpSitoWeb->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUIFrame::onSitoWeb));
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSelezionaRar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSelezionaDir ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnOk ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnQuit ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnOpzioni ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Disconnect(idMenuAggiornamenti, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUIFrame::onAggiornamenti));
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSelezionaRar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnSelezionaDir ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnOk ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnQuit ), NULL, this );

}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Terminale: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer8->Add( m_staticText5, 0, wxALL, 5 );

	wxString m_choice1Choices[] = { "xTerm", "Konsole" , "gnome-terminal"};
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer8->Add( m_choice1, 0, wxALL, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Path del file:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer9->Add( m_staticText7, 0, wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->SetMaxLength( 0 );
	bSizer9->Add( m_textCtrl1, 0, wxALL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("Sfoglia"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button5, 0, wxALL, 5 );


	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Numero di processi da aprire:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer11->Add( m_staticText8, 0, wxALL, 5 );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_textCtrl3, 0, wxALL, 5 );


	bSizer7->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Controlla aggiornamenti all'avvio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_checkBox1, 0, wxALL, 5 );
	m_checkBox1->Enable(false);


	bSizer7->Add( bSizer12, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_button6 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( this, wxID_CANCEL, wxT("Annulla"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button7, 0, wxALL, 5 );


	bSizer7->Add( bSizer14, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );

	// Connect Events
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::OnSelect ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::OnOK ), NULL, this );
	ok=false;
}

MyDialog1::~MyDialog1()
{
	// Disconnect Events
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::OnSelect ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::OnOK ), NULL, this );
}
