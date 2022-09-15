#pragma once
///////
// Auteurs: Samuel Harvey et Simon Dumas
// Date: 21 septembre 2022
// 
// Description: Programme servant � effectuer la lecture d'un fichier vid�o. Inclut aussi les fonctionnalit�s de play/pause (P), avance rapide (A), retour au d�but (R) et quitter pour fermer l'application (Q).
// 
////////


//main.cpp est tir� du fichier du m�me nom trouv� sur Moodle � la remise de ce projet, lui m�me tir� du code trouv� � l'adresse: https://docs.microsoft.com/fr-fr/windows/win32/directshow/how-to-play-a-file

#include "fonctions.h"
using namespace std;
void main(void)
{
    
    IGraphBuilder* pGraph = NULL;
    IMediaControl* pControl = NULL;
    IMediaEvent* pEvent = NULL;
    IMediaSeeking* pSeeking = NULL;
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

    hr = pGraph->RenderFile(L"C:\\Example.avi", NULL);
    if (SUCCEEDED(hr))
    {
        // Run the graph.
        hr = pControl->Run();
        if (SUCCEEDED(hr))
        {
            //cas video marche et est en cours de lecture
            ToucheEntr�e(hr, pGraph, pControl, pEvent, pSeeking);//passer en entr�e hr 
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