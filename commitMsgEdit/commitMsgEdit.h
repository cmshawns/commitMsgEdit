#ifndef _commitMsgEdit_commitMsgEdit_h
#define _commitMsgEdit_commitMsgEdit_h
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
