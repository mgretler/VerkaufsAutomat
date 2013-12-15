#include "StdAfx.h"
#include "KKGeldZurueckgeben.h"
#include "KKWartenAufKassieren.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"


CKKGeldZurueckgeben *CKKGeldZurueckgeben::m_pInstance = NULL;

CKKGeldZurueckgeben::CKKGeldZurueckgeben(void)
{
}

CKKGeldZurueckgeben::~CKKGeldZurueckgeben(void)
{
}

CKKGeldZurueckgeben* CKKGeldZurueckgeben::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CKKGeldZurueckgeben;
	}
    return m_pInstance;
}

void CKKGeldZurueckgeben::geldZurueckgegeben(CKassenkontroller *kk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    // kein

    // Zustandswechsel
    kk->GetVerkaufsautomat()->GetVerkaufskontroller()->ANS_GeldZurueckgegeben();
    kk->neuerZustand(CKKWartenAufKassieren::GetInstance());
    kk->GetBetragReferenz()=0;  // kein Geld mehr für Kauf vorhanden
    // Moore Ereignisse vom neuen Zustand setzen
    // keine
}
