#pragma once

class CVerkaufskontroller;

class CVKZustand
{
protected:
    CVKZustand(void);
    CVKZustand(char *vkZustandsname);
public:
    virtual ~CVKZustand(void);

    // Ereignisse
    virtual void produktGewaehlt(CVerkaufskontroller *vk);

    virtual void produktAusgegeben(CVerkaufskontroller *vk);
    virtual void stoerungProdukt(CVerkaufskontroller *vk);

    virtual void ANS_BetragKassiert(CVerkaufskontroller *vk);
    virtual void ANS_BetragNichtKassiert(CVerkaufskontroller *vk);
    virtual void ANS_GeldZurueckgegeben(CVerkaufskontroller *vk);

    //Debug
    char *m_vkZustandsname;
};
