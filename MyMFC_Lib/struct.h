#pragma once
#ifndef _STRUCT_H
#define _STRUCT_H						/**/
#endif // !_STRUCT_H
#include <afxtempl.h>

typedef struct tagNodeEEPar
{
	CString strParName;
	CString strParAdr;
	CString strParValue;
	CString strDataType;
	CString strParProp;
	int iParLen;
}NodeEEPar;

typedef CList<NodeEEPar, NodeEEPar&> CNodeEEParList;