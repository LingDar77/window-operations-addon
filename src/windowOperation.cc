#include <nan.h>
#include <Windows.h>
#include <iostream>
#include "helper/StringConverter.hpp"

using namespace v8;
using namespace std;



NAN_METHOD(Test)
{
	Nan::HandleScope scope;
	MessageBox(NULL, TEXT("test"), TEXT("titile"), MB_OK);
	Nan::JSON json;
	auto r = json.Parse(Nan::New<String>("{\"name\":123}").ToLocalChecked());
	
	info.GetReturnValue().Set(r.ToLocalChecked());
}


NAN_METHOD(FindWindow)
{
	Nan::HandleScope scope;
	if (info.Length() == 1)
	{
		auto title = *String::Utf8Value(info.GetIsolate(), Nan::To<String>(info[0]).ToLocalChecked());
		auto handle = FindWindow(NULL, StrConverter::Utf8String2MString(title).c_str());

		if(handle != nullptr)
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
	auto handle = Nan::To<int>(info[0]).FromJust();\
	LPSTR text = (LPSTR)malloc(sizeof(char) * 64);
	if(text != nullptr)
	{
		GetWindowText(HWND(handle), text, 100);
		info.GetReturnValue().Set(Nan::New<String>(text).ToLocalChecked());
	}
}


NAN_MODULE_INIT(Init)
{
	Nan::SetMethod(target, "test", Test);
	Nan::SetMethod(target, "findWindow", FindWindow);
	Nan::SetMethod(target, "getForegroundWindow", GetForegroundWindow);
	Nan::SetMethod(target, "getWindowText", GetWindowText);
}

NODE_MODULE(myaddon, Init)