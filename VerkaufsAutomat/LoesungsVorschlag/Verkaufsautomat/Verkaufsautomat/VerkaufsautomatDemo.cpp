// VerkaufsautomatDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"


int _tmain(int argc, _TCHAR* argv[])
{
    CTestVerkaufsautomat TVATest;
    CVerkaufsautomat TeddybaerVerkaufsautomat(&TVATest);

    enum CTestVerkaufsautomat::eErrorCodes errorCode = CTestVerkaufsautomat::ERROR_NOT_IMPLEMENTED;
 
    TVATest.setDUT(&TeddybaerVerkaufsautomat);
    
    // Verkaufskontroller testen
    // Können nicht mehr verwendet werden, seit der Verkaufsautomat voll implementiert ist.
    // TVATest.TestVerkaufskontroller(CTestVerkaufsautomat::VK_NORMALFALL);
    // TVATest.TestVerkaufskontroller(CTestVerkaufsautomat::VK_BETRAG_NICHT_KASSIERT);
    // TVATest.TestVerkaufskontroller(CTestVerkaufsautomat::VK_STOERUNG_PRODUKT);
   
    // Kassenkontroller testen
    // nicht implementiert

    // Verkaufsautomat testen
    errorCode = TVATest.TestVerkaufsautomat(CTestVerkaufsautomat::VA_NORMALFALL);
    errorCode = TVATest.TestVerkaufsautomat(CTestVerkaufsautomat::VA_TIMEOUT_GELDEINWURF);
    errorCode = TVATest.TestVerkaufsautomat(CTestVerkaufsautomat::VA_STOERUNG_PRODUKT);
    
	return 0;
}

