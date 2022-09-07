#pragma once
#pragma comment(lib,"Strmiids.lib")
#define ONE_SECOND 10000000
#include <dshow.h>
#include <iostream>
using namespace std;
//BSTR Video = SysAllocString(L"D:\\rocket.avi");

bool ToucheEntrée(HRESULT, IGraphBuilder*, IMediaControl*, IMediaEvent*, IMediaSeeking*);

