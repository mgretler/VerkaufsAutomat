#include "StdAfx.h"
#include "KKWartenAufMuenze.h"
#include "KKBetragErhalten.h"
#include "Kassenkontroller.h"

#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CKKWartenAufMuenze *CKKWartenAufMuenze::m_pInstance = NULL;

CKKWartenAufMuenze::CKKWartenAufMuenze(void)
{
}

CKKWartenAufMuenze::~CKKWartenAufMuenze(void)
{
}

CKKWartenAufMuenze* CKKWartenAufMuenze::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CKKWartenAufMuenze;
	}
    return m_pInstance;
}

// Ereignisse
void CKKWartenAufMuenze::muenzeEingeworfen(CKassenkontroller *kk, unsigned wert)
{
    unsigned& Betrag = kk->GetBetragReferenz();
    Betrag += wert;

    if (Betrag >= kk->GetVerkaufsautomat()->GetPreis())
    {
        // Nur in diesem fall muss der Zustand gewechselt werden. 
        // Im Gegensatz zum Klassendiagramm wechselt der Zustand hier
        // direkt zu "Betrag erhalten"
 
        // Moore Ausgänge vom alten Zustand zurücksetzen
        kk->GetVerkaufsautomat()->GetTestUmgebung()->muenzeinwurfOeffnen(false);

        // Zustandswechsel
        kk->neuerZustand(CKKBetragErhalten::GetInstance());

        // Moore Ereignisse vom neuen Zustand setzen
        kk->GetVerkaufsautomat()->GetVerkaufskontroller()->ANS_BetragKassiert();
    }
}

void CKKWartenAufMuenze::timeout(CKassenkontroller *kk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    kk->GetVerkaufsautomat()->GetTestUmgebung()->muenzeinwurfOeffnen(false);

    // Zustandswechsel
    kk->neuerZustand(CKKBetragErhalten::GetInstance());
    kk->GetVerkaufsautomat()->GetVerkaufskontroller()->ANS_BetragNichtKassiert();

    // Moore Ereignisse vom neuen Zustand setzen
    kk->GetVerkaufsautomat()->GetTestUmgebung()->geldZurueckgeben();

}