#pragma once
#pragma comment(lib,"Strmiids.lib")
#define ONE_SECOND 10000000
#include <dshow.h>
#include <iostream>
using namespace std;

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
            break;
        case 'R':
            hr = pSeeking->SetRate(1.0);
            hr = pSeeking->SetPositions(&rtNow, AM_SEEKING_AbsolutePositioning, &rtEnd, AM_SEEKING_AbsolutePositioning);
            break;
        case 'Q':
            pControl->Release();
            pEvent->Release();
            pGraph->Release();
            CoUninitialize();
            break;
        default:
            break;
        }

    }






}