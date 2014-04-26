#ifndef _commitMsgEdit_commitMsgEdit_h
#define _commitMsgEdit_commitMsgEdit_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <commitMsgEdit/commitMsgEdit.lay>
#include <CtrlCore/lay.h>

class CommitMessageEditor : public WithCommitMessageEditorLayout<TopWindow> {
public:
	typedef CommitMessageEditor CLASSNAME;
	CommitMessageEditor();
};

#endif
