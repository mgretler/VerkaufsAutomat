#pragma once
#include "vkzustand.h"

class CVKProduktAusgeben :
    public CVKZustand
{
private:
    static CVKProduktAusgeben *m_pInstance;
    CVKProduktAusgeben(void);

public:
    static CVKProduktAusgeben* GetInstance(void);
    virtual ~CVKProduktAusgeben(void);

    //Ereignisse
    virtual void produktAusgegeben(CVerkaufskontroller *vk);
    virtual void stoerungProdukt(CVerkaufskontroller *vk);

};
