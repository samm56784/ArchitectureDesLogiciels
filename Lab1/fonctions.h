#pragma once
#pragma comment(lib,"Strmiids.lib")
#define ONE_SECOND 10000000
#include <dshow.h>
#include <iostream>
using namespace std;
REFERENCE_TIME rtNow = 0 * ONE_SECOND, rtEnd;
int code = 0;
char lettre = 'Z';
//BSTR Video = SysAllocString(L"D:\\rocket.avi");
FILTER_STATE state;
IGraphBuilder* pGraph = NULL;
IMediaControl* pControl = NULL;
IMediaEvent* pEvent = NULL;
IMediaSeeking* pSeeking = NULL;
HRESULT hr = CoInitialize(NULL);
bool ToucheEntrée();

bool ToucheEntrée()
{

    long evCode;
    hr = pSeeking->GetPositions(NULL, &rtEnd);
    while (lettre != 'Q')
    {
        cin >> lettre;
        lettre = toupper(lettre);
        switch (lettre)
        {
        case 'A':
            hr = pSeeking->SetRate(1.25);
            return true;
            break;
        case 'P':
            hr = pControl->GetState(0, (OAFilterState*)&state);
            if (state == State_Paused)
            {
                hr = pControl->Run();
            }
            else
            {
                hr = pControl->Pause();
            }
            return true;
            break;
        case 'R':
            hr = pSeeking->SetRate(1.0);
            hr = pSeeking->SetPositions(&rtNow, AM_SEEKING_AbsolutePositioning, &rtEnd, AM_SEEKING_AbsolutePositioning);
            return true;
            break;
        case 'Q':
            pControl->Release();
            pEvent->Release();
            pGraph->Release();
            CoUninitialize();
            return false;
            break;
        default:
            return true;
            break;
        }

    }






}