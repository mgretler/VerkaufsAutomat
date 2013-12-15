#include "StdAfx.h"
#include "VKGeldZurueckgeben.h"
#include "VKProduktAuswaehlen.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CVKGeldZurueckgeben *CVKGeldZurueckgeben::m_pInstance = NULL;

CVKGeldZurueckgeben::CVKGeldZurueckgeben(void)
{
}

CVKGeldZurueckgeben::~CVKGeldZurueckgeben(void)
{
}

CVKGeldZurueckgeben* CVKGeldZurueckgeben::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CVKGeldZurueckgeben;
	}
    return m_pInstance;
}

void CVKGeldZurueckgeben::ANS_GeldZurueckgegeben(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEntnehmen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKProduktAuswaehlen::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktWaehlen(true);
}

