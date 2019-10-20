/***************************************************************
 * Name:      wxRarApp.cpp
 * Purpose:   Code for Application Class
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

#include "wxRarApp.h"
#include "wxRarMain.h"

IMPLEMENT_APP(wxRarApp);

bool wxRarApp::OnInit()
{
    wxRarFrame* frame = new wxRarFrame(0L);

    frame->Show();

    return true;
}
