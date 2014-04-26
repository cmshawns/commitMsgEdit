#include "commitMsgEdit.h"

CommitMessageEditor::CommitMessageEditor()
{
	CtrlLayoutOKCancel(*this, "Commit Message Editor");
	this->Sizeable(true);
}

GUI_APP_MAIN
{
	CommitMessageEditor().Run();
}
