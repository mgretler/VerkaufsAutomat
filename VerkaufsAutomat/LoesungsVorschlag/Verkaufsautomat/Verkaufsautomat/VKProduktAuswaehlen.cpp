#include "StdAfx.h"
#include "VKProduktAuswaehlen.h"
#include "VKProduktBezahlen.h"
#include "Verkaufskontroller.h"
#include "Kassenkontroller.h"
#include "Verkaufsautomat.h"
#include "TestVerkaufsautomat.h"

CVKProduktAuswaehlen *CVKProduktAuswaehlen::m_pInstance = NULL;

CVKProduktAuswaehlen::CVKProduktAuswaehlen(void)
{
}

CVKProduktAuswaehlen::~CVKProduktAuswaehlen(void)
{
}

CVKProduktAuswaehlen* CVKProduktAuswaehlen::GetInstance(void)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CVKProduktAuswaehlen;
	}
    return m_pInstance;
}

void CVKProduktAuswaehlen::produktGewaehlt(CVerkaufskontroller *vk)
{
    // Moore Ausgänge vom alten Zustand zurücksetzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeProduktWaehlen(false);
    
    // Zustandswechsel
    vk->neuerZustand(CVKProduktBezahlen::GetInstance());

    // Moore Ereignisse vom neuen Zustand setzen
    vk->GetVerkaufsautomat()->GetTestUmgebung()->anzeigeGeldEinwerfen(true);
    vk->GetVerkaufsautomat()->GetKassenkontroller()->CMD_Kassieren();    
}
