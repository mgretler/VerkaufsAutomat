#include "StdAfx.h"
#include "VKProduktBezahlen.h"
#include "VKProduktAusgeben.h"
#include "VKGeldZurueckgeben.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CVKProduktBezahlen *CVKProduktBezahlen::m_pInstance = NULL;

CVKProduktBezahlen::CVKProduktBezahlen(void)
{
}

CVKProduktBezahlen::~CVKProduktBezahlen(void)
{
}

CVKProduktBezahlen* CVKProduktBezahlen::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CVKProduktBezahlen;
	}
    return m_pInstance;
}

void CVKProduktBezahlen::ANS_BetragKassiert(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEinwerfen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKProduktAusgeben::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktEntnehmen(true);
    vk->GetVerkaufsautomat()->GetTestUmgebung()->produktAusgeben();
}

void CVKProduktBezahlen::ANS_BetragNichtKassiert(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEinwerfen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKGeldZurueckgeben::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEntnehmen(true);
    vk->GetVerkaufsautomat()->GetKassenkontroller()->CMD_GeldZurueckgeben();
}
