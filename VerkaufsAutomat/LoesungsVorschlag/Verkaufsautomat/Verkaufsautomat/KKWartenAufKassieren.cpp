#include "StdAfx.h"

#include "KKWartenAufKassieren.h"
#include "KKWartenAufMuenze.h"
#include "Kassenkontroller.h"

#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CKKWartenAufKassieren *CKKWartenAufKassieren::m_pInstance = NULL;

CKKWartenAufKassieren::CKKWartenAufKassieren(void)
{
}

CKKWartenAufKassieren::~CKKWartenAufKassieren(void)
{
}

CKKWartenAufKassieren* CKKWartenAufKassieren::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CKKWartenAufKassieren;
	}
    return m_pInstance;
}

// Ereignisse
void CKKWartenAufKassieren::CMD_Kassieren(CKassenkontroller *kk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    // keine

    // Zustandswechsel
    kk->neuerZustand(CKKWartenAufMuenze::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    kk->GetVerkaufsautomat()->GetTestUmgebung()->muenzeinwurfOeffnen(true);
}
