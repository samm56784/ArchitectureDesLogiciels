#pragma once
#include "fonctions.h"
using namespace std;
void main(void)
{

    // Initialize the COM library.
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
        return;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        return;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);
    // Build the graph. IMPORTANT: Change this string to a file on your system.

    hr = pGraph->RenderFile(L"D:\\rocket.avi", NULL);//****exe path change(choix fichier?)
    if (SUCCEEDED(hr))
    {
        //pControl.
        // Run the graph.
        hr = pControl->Run();
        if (SUCCEEDED(hr))
        {
            //cas video marche et est en cours de lecture
            // Wait for completion.
            while (ToucheEntrée())//passer en entrée hr 
            {
            }
            // Note: Do not use INFINITE in a real application, because it
            // can block indefinitely.
        }
    }
    else
    {
        cout << "Erreur d'ouverture du fichier video..." << endl;
        pControl->Release();
        pEvent->Release();
        pGraph->Release();
        CoUninitialize();


    }

}