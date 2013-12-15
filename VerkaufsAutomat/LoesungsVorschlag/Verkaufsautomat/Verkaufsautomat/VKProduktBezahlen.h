#pragma once
#include "vkzustand.h"

class CVKProduktBezahlen :
    public CVKZustand
{
private:
    static CVKProduktBezahlen *m_pInstance;
    CVKProduktBezahlen(void);

public:
    static CVKProduktBezahlen* GetInstance(void);
    virtual ~CVKProduktBezahlen(void);

    // Ereignisse
    virtual void ANS_BetragKassiert(CVerkaufskontroller *vk);
    virtual void ANS_BetragNichtKassiert(CVerkaufskontroller *vk);

};
