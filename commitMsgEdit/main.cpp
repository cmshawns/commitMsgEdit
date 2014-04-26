#include "commitMsgEdit.h"

CommitMessageEditor::CommitMessageEditor()
{
	CtrlLayoutOKCancel(*this, "Window title");
}

GUI_APP_MAIN
{
	CommitMessageEditor().Run();
}
