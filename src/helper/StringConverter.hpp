#pragma once

#include <Windows.h>
#include "string"
using namespace std;

class StrConverter
{
public:
	
	inline static string WString2MString(const wchar_t *pwszText)
	{
		if (pwszText == NULL || wcslen(pwszText) == 0)
		{
			return string();
		}
		int iSizeInBytes = WideCharToMultiByte(CP_ACP, 0, pwszText, -1, NULL, 0, NULL, NULL);
		char *pMultiByte = new (std::nothrow) char[iSizeInBytes];
		if (pMultiByte == NULL)
		{
			return string();
		}

		memset(pMultiByte, 0, iSizeInBytes);
		WideCharToMultiByte(CP_ACP, 0, pwszText, -1, pMultiByte, iSizeInBytes, NULL, NULL);

		string strResult = string(pMultiByte);

		delete[] pMultiByte;
		pMultiByte = NULL;
		return strResult;
	}

	inline static wstring Utf8String2WString(const char *pszText)
	{
		if (pszText == NULL || strlen(pszText) == 0)
		{
			return std::wstring();
		}
		int iSizeInChars = MultiByteToWideChar(CP_UTF8, 0, pszText, -1, NULL, 0);
		wchar_t *pWideChar = new (nothrow) wchar_t[iSizeInChars];
		if (pWideChar == NULL)
		{
			return std::wstring();
		}

		wmemset(pWideChar, 0, iSizeInChars);
		MultiByteToWideChar(CP_UTF8, 0, pszText, -1, pWideChar, iSizeInChars);

		wstring strResult = wstring(pWideChar);
		delete[] pWideChar;
		pWideChar = NULL;
		return strResult;
	}

	inline static std::string Utf8String2MString(const char *pszText)
	{
		return WString2MString(Utf8String2WString(pszText).c_str());
	}

	inline static std::wstring MString2WString(const char *pszText)
	{
		if (pszText == NULL || strlen(pszText) == 0)
		{
			return wstring();
		}
		int iSizeInChars = MultiByteToWideChar(CP_ACP, 0, pszText, -1, NULL, 0);
		wchar_t *pWideChar = new (std::nothrow) wchar_t[iSizeInChars];
		if (pWideChar == NULL)
		{
			return wstring();
		}

		wmemset(pWideChar, 0, iSizeInChars);
		MultiByteToWideChar(CP_ACP, 0, pszText, -1, pWideChar, iSizeInChars);

		wstring strResult = wstring(pWideChar);
		delete[] pWideChar;
		pWideChar = NULL;
		return strResult;
	}

	inline static string WString2Utf8String(const wchar_t *pwszText)
	{
		if (pwszText == NULL || wcslen(pwszText) == 0)
		{
			return string();
		}
		int iSizeInBytes = WideCharToMultiByte(CP_UTF8, 0, pwszText, -1, NULL, 0, NULL, NULL);
		char *pUTF8 = new (std::nothrow) char[iSizeInBytes];
		if (pUTF8 == NULL)
		{
			return string();
		}

		memset(pUTF8, 0, iSizeInBytes);
		WideCharToMultiByte(CP_UTF8, 0, pwszText, -1, pUTF8, iSizeInBytes, NULL, NULL);

		string strResult = string(pUTF8);
		delete[] pUTF8;
		pUTF8 = NULL;
		return strResult;
	}

	inline static std::string MString2Utf8String(const char *pszText)
	{
		return WString2Utf8String(MString2WString(pszText).c_str());
	}
};