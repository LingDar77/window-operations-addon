#include <nan.h>
#include <Windows.h>
#include <iostream>
#include "helper/StringConverter.hpp"
#include <GdiPlus.h> // 保存图片用到了GDI+
#include <atlbase.h> // 字符串转换用到


#pragma comment(lib, "gdiplus.lib") // 保存图片需要

using namespace v8;
using namespace std;

namespace GdiplusUtil
{
	static int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
	{
		UINT  num = 0;          // number of image encoders
		UINT  size = 0;         // size of the image encoder array in bytes

		Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

		Gdiplus::GetImageEncodersSize(&num, &size);
		if (size == 0)
			return -1;  // Failure

		pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
		if (pImageCodecInfo == NULL)
			return -1;  // Failure

		Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

		for (UINT j = 0; j < num; ++j) {
			if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
				*pClsid = pImageCodecInfo[j].Clsid;
				free(pImageCodecInfo);
				return j;  // Success
			}
		}

		free(pImageCodecInfo);
		return -1;  // Failure
	}

	// 将bitmap对象保存为png图片
	static bool SaveBitmapAsPng(const std::shared_ptr<Gdiplus::Bitmap>& bitmap, const std::string& filename)
	{
		if (bitmap == nullptr) return false;
		CLSID png_clsid;
		GetEncoderClsid(L"image/png", &png_clsid);
		Gdiplus::Status ok = bitmap->Save(CA2W(filename.c_str(), CP_ACP), &png_clsid, nullptr);
		return ok == Gdiplus::Status::Ok;
	}
}

NAN_METHOD(Test)
{
	Nan::HandleScope scope;
	MessageBox(NULL, TEXT("test"), TEXT("titile"), MB_OK);
	Nan::JSON json;
	auto r = json.Parse(Nan::New<String>("{\"name\":123}").ToLocalChecked());

	info.GetReturnValue().Set(r.ToLocalChecked());
}

NAN_METHOD(GetAllProcesses)
{
	HWND hDesktopWnd = ::GetDesktopWindow();
	HWND hWindow = ::GetWindow(hDesktopWnd, GW_CHILD);
	auto ret = Nan::New<Array>();
	int i = 0;
	while (hWindow != NULL)
	{
		DWORD processID;
		GetWindowThreadProcessId(hWindow, &processID);

		int lTextLen = ::GetWindowTextLength(hWindow) + 1;
		LPSTR text = (LPSTR)malloc(sizeof(char) * lTextLen);
		if (text)
		{
			::GetWindowText(hWindow, text, lTextLen);
			auto item = Nan::New<Array>();
			Nan::Set(item, 0, Nan::New<String>(text).ToLocalChecked());
			Nan::Set(item, 1, Nan::New<Number>(long(hWindow)));
			Nan::Set(ret, i, item);
			++i;
		}

		hWindow = ::GetWindow(hWindow, GW_HWNDNEXT);
	}
	info.GetReturnValue().Set(ret);
}

NAN_METHOD(FindWindow)
{
	Nan::HandleScope scope;
	if (info.Length() == 1)
	{
		auto title = *String::Utf8Value(info.GetIsolate(), info[0]);
		auto handle = FindWindow(NULL, StrConverter::Utf8String2MString(title).c_str());
		MessageBox(NULL, TEXT(title), TEXT("titile"), MB_OK);
		if (handle != nullptr)
		{
			info.GetReturnValue().Set(Nan::New<Number>(long(handle)));
		}
		else
		{
			info.GetReturnValue().Set(Nan::New<Number>(0));
		}

	}
	if (info.Length() == 2)
	{
		auto titile = *String::Utf8Value(info.GetIsolate(), Nan::To<String>(info[0]).ToLocalChecked());
		auto className = *String::Utf8Value(info.GetIsolate(), Nan::To<String>(info[1]).ToLocalChecked());
		auto handle =
			FindWindow(StrConverter::Utf8String2MString(className).c_str(),
				StrConverter::Utf8String2MString(titile).c_str());
		if (handle != nullptr)
		{
			info.GetReturnValue().Set(Nan::New<Number>(long(handle)));
		}
		else
		{
			info.GetReturnValue().Set(Nan::New<Number>(0));
		}
	}

}

NAN_METHOD(GetForegroundWindow)
{
	info.GetReturnValue().Set(Nan::New<Number>(long(GetForegroundWindow())));
}

NAN_METHOD(GetWindowText)
{
	Nan::HandleScope scope;
	auto handle = Nan::To<int>(info[0]).FromJust();
	auto length = GetWindowTextLength(HWND(handle));
	LPSTR text = (LPSTR)malloc(sizeof(char) * (length + 1));
	if (text)
	{
		GetWindowText(HWND(handle), text, length + 1);
		info.GetReturnValue().Set(Nan::New<String>(StrConverter::MString2Utf8String(text)).ToLocalChecked());
	}
}

NAN_METHOD(CaptureWindow)
{
	auto handle = HWND(Nan::To<int>(info[0]).FromJust());
	HDC windowDC = GetWindowDC(handle);
	RECT rect;
	GetWindowRect(handle, &rect);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	HDC memoryDC = CreateCompatibleDC(windowDC);
	HBITMAP hBitmap = CreateCompatibleBitmap(windowDC, width, height);
	SelectObject(memoryDC, hBitmap);

	Gdiplus::Bitmap* bitmap;
	if (BitBlt(memoryDC, 0, 0, width, height, windowDC, 0, 0, SRCCOPY))
	{
		bitmap = new Gdiplus::Bitmap(hBitmap, nullptr);

		auto result = Nan::New<Array>();
		for (auto i = 0; i != width; ++i)
		{
			auto item = Nan::New<Array>();

			for (auto j = 0; j != height; ++j)
			{

				Gdiplus::Color color;
				bitmap->GetPixel(i, j, &color);

				auto c = Nan::New<Array>();
				Nan::Set(c, 0, Nan::New<Number>(color.GetR()));
				Nan::Set(c, 1, Nan::New<Number>(color.GetG()));
				Nan::Set(c, 2, Nan::New<Number>(color.GetB()));
				Nan::Set(item, j, c);
			}

			Nan::Set(result, i, item);
		}

		info.GetReturnValue().Set(result);

	}
	//info.GetReturnValue().Set(Nan::New<String>("???").ToLocalChecked());
	DeleteDC(windowDC);
	DeleteDC(memoryDC);
	DeleteObject(hBitmap);
	return;
}

NAN_METHOD(SaveAsPng)
{
	auto widths = Local<Array>::Cast(info[0]);
	auto heights = Local<Array>::Cast(Nan::Get(widths, 0).ToLocalChecked());
	auto bitmap = new Gdiplus::Bitmap(widths->Length(), heights->Length());

	for (unsigned int i = 0; i < widths->Length(); i++) {

		if (Nan::Has(widths, i).FromJust()) {

			auto heights = Local<Array>::Cast(Nan::Get(widths, i).ToLocalChecked());
			for (unsigned int j = 0; j < widths->Length(); j++) {

				if (Nan::Has(heights, j).FromJust()) {
					auto color = Local<Array>::Cast(Nan::Get(heights, j).ToLocalChecked());
					auto r = Nan::To<int>(Nan::Get(color, 0).ToLocalChecked()).FromJust();
					auto g = Nan::To<int>(Nan::Get(color, 1).ToLocalChecked()).FromJust();
					auto b = Nan::To<int>(Nan::Get(color, 2).ToLocalChecked()).FromJust();
					bitmap->SetPixel(i, j, Gdiplus::Color(byte(r), byte(g), byte(b)));
				}
			}
		}
	}

	auto path = *String::Utf8Value(info.GetIsolate(), info[1]);
	CLSID png_clsid;
	GdiplusUtil::GetEncoderClsid(L"image/png", &png_clsid);
	bitmap->Save(CA2W(path, CP_ACP), &png_clsid, nullptr);
}

NAN_METHOD(SetCursorPos)
{
	auto x = Nan::To<int>(info[0]).FromJust();
	auto y = Nan::To<int>(info[1]).FromJust();

	SetCursorPos(x, y);
}

NAN_METHOD(MouseEvent)
{
	auto e = Nan::To<int>(info[0]).FromJust();
	auto x = Nan::To<int>(info[1]).FromJust();
	auto y = Nan::To<int>(info[2]).FromJust();
	if (info.Length() == 2)
		mouse_event(e, 0, 0, x, 0);
	else
		mouse_event(e, x, y, 0, 0);


}

NAN_METHOD(KeyBoardEvent)
{
	auto e = Nan::To<int>(info[0]).FromJust();
	auto x = Nan::To<int>(info[1]).FromJust();
	keybd_event(e, 0, x, 0);
}

Gdiplus::GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR token;

void clearnup(void* arg, void (*cb)(void*), void* cbarg)
{
	Gdiplus::GdiplusShutdown(token); // 关闭GDI
	exit(0);
}

NAN_MODULE_INIT(Init)
{

	Gdiplus::GdiplusStartup(&token, &gdiplusStartupInput, NULL);
	Nan::SetMethod(target, "test", Test);
	Nan::SetMethod(target, "findWindow", FindWindow);
	Nan::SetMethod(target, "getForegroundWindow", GetForegroundWindow);
	Nan::SetMethod(target, "getWindowText", GetWindowText);
	Nan::SetMethod(target, "getAllProcesses", GetAllProcesses);
	Nan::SetMethod(target, "captureWindow", CaptureWindow);
	Nan::SetMethod(target, "saveAsPng", SaveAsPng);
	Nan::SetMethod(target, "setCursorPos", SetCursorPos);
	Nan::SetMethod(target, "mouseEvent", MouseEvent);
	Nan::SetMethod(target, "keyBoardEvent", KeyBoardEvent);



	node::AddEnvironmentCleanupHook(v8::Isolate::GetCurrent(), clearnup, nullptr);
}


NODE_MODULE(myaddon, Init)
