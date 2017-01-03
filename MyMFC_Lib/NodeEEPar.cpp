#include "stdafx.h"
#include "NodeEEPar.h"


CNodeEEPar::CNodeEEPar()
{
}


CNodeEEPar::~CNodeEEPar()
{
}

void CNodeEEPar::Save(const CNodeEEParList & nodeEEParList, CString strFileName)
{
	CString strSection = _T("NodeEEParam"), strKey = _T("ParamNum"), strValue;
	int iCount = (int)nodeEEParList.GetCount();
	strValue.Format(_T("%d"), iCount);
	/*Copies a string into the specified section of an initialization file.*/
	::WritePrivateProfileString(strSection, strKey, strValue, strFileName);
	POSITION pos = nodeEEParList.GetHeadPosition();
	while (pos != NULL)
	{
		const NodeEEPar& nodeEEPar = nodeEEParList.GetAt(pos);

		strSection.Format(_T("Param%d"),index);
		strKey = _T("ParamName");
		::WritePrivateProfileString(strSection, strKey, nodeEEPar.strParName, strFileName);

		strKey = _T("ParamAddress");
		::WritePrivateProfileString(strSection, strKey, nodeEEPar.strParAdr, strFileName);
	
		strKey = _T("ParamValue");
		::WritePrivateProfileString(strSection, strKey, nodeEEPar.strParValue, strFileName);

		strKey = _T("ParamLen");
		strValue.Format(_T("%d"),nodeEEPar.iParLen);
		::WritePrivateProfileString(strSection,strKey,strValue,strFileName);

		strKey = _T("DataType");
		::WritePrivateProfileString(strSection, strKey, nodeEEPar.strDataType, strFileName);

		strKey = _T("ParamProp");
		::WritePrivateProfileString(strSection,strKey,nodeEEPar.strParProp,strFileName);

		index++;d
		nodeEEParList.GetNext(pos);
	}
}

void CNodeEEPar::AutoSave(const CNodeEEParList & nodeEEParList)
{
	CString strExePath = GetExePath();
	CString strFileName = strExePath + _T("DefEEParam.eppr");
	Save(nodeEEParList, strFileName);
}

void CNodeEEPar::Open(CNodeEEParList & nodeEEParList, CString strFileName)
{
	nodeEEParList.RemoveAll();

	TCHAR cBuf[200];
	CString strSection = _T("NodeEEParam"), strKey = _T("ParanNum");
	UINT uiCount = ::GetPrivateProfileInt(strSection, strKey, 0, strFileName);

	for (UINT i = 0 ; i<uiCount;i++)
	{
		NodeEEPar nodeEEPar;
		strSection.Format(_T("Param%d"), i + 1);
		strKey = _T("ParamAddress");
		::GetPrivateProfileString(strSection, strKey, _T(""), cBuf, 200, strFileName);
		nodeEEPar.strParName.Format(_T("%s"),cBuf);

		strKey = _T("ParamAddress");
		::GetPrivateProfileString(strSection, strKey, _T(""), cBuf, 200, strFileName);
		nodeEEPar.strParAdr.Format(_T("%s"), cBuf);

		strKey = _T("ParamValue");
		::GetPrivateProfileString(strSection, strKey, _T(""), cBuf, 200, strFileName);
		nodeEEPar.strParValue.Format(_T("%s"), cBuf);

		strKey = _T("ParamLen");
		nodeEEPar.iParLen = ::GetPrivateProfileInt(strSection, strKey, 0, strFileName);

		strKey = _T("DataType");
		::GetPrivateProfileString(strSection, strKey, _T(""), cBuf, 200, strFileName);
		nodeEEPar.strDataType.Format(_T("%s"), cBuf);

		strKey = _T("ParamProp");
		::GetPrivateProfileString(strSection, strKey, _T(""), cBuf, 200, strFileName);
		nodeEEPar.strParProp.Format(_T("%s"), cBuf);

		nodeEEParList.AddTail(nodeEEPar);
	}
}

void CNodeEEPar::AutoOpen(CNodeEEParList & nodeEEParList)
{
	CString strExePath = GetExePath();
	CString strFileName = strExePath + _T("DefEEParam.eppr");
	Open(nodeEEParList, strFileName);
}

CString CNodeEEPar::GetExePath(void)
{
	TCHAR cFileName[_MAX_PATH];
	GetModuleFileName(NULL, cFileName, _MAX_PATH);
	CString strFileDir;
	strFileDir.Format(_T("%s"), cFileName);
	int iPos = strFileDir.ReverseFind('\\');
	strFileDir = strFileDir.Left(iPos + 1);
	return strFileDir;
}
