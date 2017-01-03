#pragma once
#include "struct.h"
class CNodeEEPar
{
public:
	CNodeEEPar();
	virtual ~CNodeEEPar();
	void Save(const CNodeEEParList& nodeEEParList, CString strFileName);
	void AutoSave(const CNodeEEParList& nodeEEParList);
	void Open(CNodeEEParList& nodeEEParList, CString strFileName);
	void AutoOpen(CNodeEEParList& nodeEEParList);
	CString GetExePath(void);
};

