#pragma once
#include "vkzustand.h"

class CVKGeldZurueckgeben :
    public CVKZustand
{
private:
    static CVKGeldZurueckgeben *m_pInstance;
    CVKGeldZurueckgeben(void);

public:
    static CVKGeldZurueckgeben* GetInstance(void);
    virtual ~CVKGeldZurueckgeben(void);

    //Ereignisse

    virtual void ANS_GeldZurueckgegeben(CVerkaufskontroller *vk);

};
