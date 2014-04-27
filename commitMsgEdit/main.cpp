#include <Core/Core.h>
#include "commitMsgEdit.h"

using namespace Upp;

CommitMessageEditor::CommitMessageEditor()
{
	CtrlLayoutOKCancel(*this, "Commit Message Editor");
	this->Sizeable(true);
	
	ok <<= THISBACK(Save);
	
	String commitMsg = LoadFile("/home/shawn/dev/commitMsgEdit/.git/COMMIT_EDITMSG");
	
	msg.SetData(commitMsg);
}

GUI_APP_MAIN
{
	CommitMessageEditor().Run();
}

void CommitMessageEditor::Save()
{
	if (msg.IsModified())
	{
		String newMsg = msg.GetData();
		
		if (!SaveFile("/home/shawn/dev/commitMsgEdit/.git/COMMIT_EDITMSG", newMsg))
		{
			Exclamation("Message was not saved");
		}
	}
	
	this->Close();
}
