#include "StdAfx.h"
#include "VKProduktAusgeben.h"
#include "VKProduktAuswaehlen.h"
#include "VKGeldZurueckgeben.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CVKProduktAusgeben *CVKProduktAusgeben::m_pInstance = NULL;

CVKProduktAusgeben::CVKProduktAusgeben(void)
{
}

CVKProduktAusgeben::~CVKProduktAusgeben(void)
{
}

CVKProduktAusgeben* CVKProduktAusgeben::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CVKProduktAusgeben;
	}
    return m_pInstance;
}

void CVKProduktAusgeben::produktAusgegeben(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktEntnehmen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKProduktAuswaehlen::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktWaehlen(true);
    vk->GetVerkaufsautomat()->GetKassenkontroller()->CMD_GeldInKasseLegen();
}

void CVKProduktAusgeben::stoerungProdukt(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktEntnehmen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKGeldZurueckgeben::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEntnehmen(true);
    vk->GetVerkaufsautomat()->GetKassenkontroller()->CMD_GeldZurueckgeben();
}
