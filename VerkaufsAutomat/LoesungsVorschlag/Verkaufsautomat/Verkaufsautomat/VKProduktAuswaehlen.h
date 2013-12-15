#pragma once
#include "vkzustand.h"

class CVKProduktAuswaehlen :
    public CVKZustand
{
private:
    static CVKProduktAuswaehlen *m_pInstance;
    CVKProduktAuswaehlen(void);

public:
    static CVKProduktAuswaehlen* GetInstance(void);
    virtual ~CVKProduktAuswaehlen(void);

    virtual void produktGewaehlt(CVerkaufskontroller *vk);
};
