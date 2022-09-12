#pragma once
#pragma comment(lib,"Strmiids.lib")
#include <dshow.h>
#include <iostream>
using namespace std;

bool ToucheEntrée(HRESULT, IGraphBuilder*, IMediaControl*, IMediaEvent*, IMediaSeeking*);

