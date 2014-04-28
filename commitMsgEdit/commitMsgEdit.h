#ifndef _commitMsgEdit_commitMsgEdit_h
#define _commitMsgEdit_commitMsgEdit_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <commitMsgEdit/commitMsgEdit.lay>
#include <CtrlCore/lay.h>

#define COMMIT_EDIT_MSG_FILE ".git/COMMIT_EDITMSG"

class CommitMessageEditor : public WithCommitMessageEditorLayout<TopWindow> {
public:
	typedef CommitMessageEditor CLASSNAME;
	CommitMessageEditor();

private:
	String tempFile;
	void Save();
};

#endif
