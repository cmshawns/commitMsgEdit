/*
Copyright 2014 Shawn South <shawn@codemastershawn.com>

This file is part of the Commit Message Editor (commitMsgEdit)

commitMsgEdit is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

commitMsgEdit is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with commitMsgEdit. If not, see <http://www.gnu.org/licenses/>.
*/
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
