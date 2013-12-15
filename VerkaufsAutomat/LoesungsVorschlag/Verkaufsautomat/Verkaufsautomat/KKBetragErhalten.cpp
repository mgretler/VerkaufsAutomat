#include "StdAfx.h"
#include "KKBetragErhalten.h"
#include "KKWartenAufKassieren.h"
#include "KKGeldZurueckgeben.h"
#include "Kassenkontroller.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CKKBetragErhalten *CKKBetragErhalten::m_pInstance = NULL;

CKKBetragErhalten::CKKBetragErhalten(void)
{
}

CKKBetragErhalten::~CKKBetragErhalten(void)
{
}

CKKBetragErhalten* CKKBetragErhalten::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CKKBetragErhalten;
	}
    return m_pInstance;
}

// Ereignisse

void CKKBetragErhalten::CMD_GeldInKasseLegen(CKassenkontroller *kk)
{
    // Moore Ausg�nge vom alten Zustand zur�cksetzen
    // kein

    // Zustandswechsel
    kk->neuerZustand(CKKWartenAufKassieren::GetInstance());
    kk->GetVerkaufsautomat()->GetTestUmgebung()->geldInKasseLegen();
    kk->GetBetragReferenz()=0;  // kein Geld mehr f�r Kauf vorhanden
    // Moore Ereignisse vom neuen Zustand setzen
    // keine
}

void CKKBetragErhalten::CMD_GeldZurueckgeben(CKassenkontroller *kk)
{
    // Moore Ausg�nge vom alten Zustand zur�cksetzen
    // kein

    // Zustandswechsel
    kk->neuerZustand(CKKGeldZurueckgeben::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    kk->GetVerkaufsautomat()->GetTestUmgebung()->geldZurueckgeben();
}
