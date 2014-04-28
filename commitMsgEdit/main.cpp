#include <Core/Core.h>
#include "commitMsgEdit.h"

using namespace Upp;

CommitMessageEditor::CommitMessageEditor()
{
	CtrlLayoutOKCancel(*this, "Commit Message Editor");
	this->Sizeable(true);
	
	// event handlers	
	ok <<= THISBACK(Save);

	// find and load temp file
	tempFile = AppendFileName(GetCurrentDirectory(), COMMIT_EDIT_MSG_FILE);
	String commitMsg = LoadFile(tempFile);
	
	if (commitMsg.IsEmpty())
	{
		ok.Disable();

		Exclamation("Failed to load commit message from '" + tempFile + "'");
	}
	else
	{
		msg.SetData(commitMsg);
	}
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
		
		if (!SaveFile(tempFile, newMsg))
		{
			Exclamation("Message was not saved to '" + tempFile + "'");
		}
		else
		{
			this->Close();
		}
	}
}
