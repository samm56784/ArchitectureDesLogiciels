#pragma once
#include "fonctions.h"

bool ToucheEntrée(HRESULT hr, IGraphBuilder* pGraph, IMediaControl* pControl, IMediaEvent* pEvent, IMediaSeeking* pSeeking)
{
    REFERENCE_TIME rtNow = 0 * ONE_SECOND, rtEnd;
    char lettre = 'Z';
    FILTER_STATE state;
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
            hr = pControl->GetState(0, (OAFilterState*)&state);
            hr = pSeeking->SetPositions(&rtNow, AM_SEEKING_AbsolutePositioning, &rtEnd, AM_SEEKING_AbsolutePositioning);
            hr = pControl->Run();
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