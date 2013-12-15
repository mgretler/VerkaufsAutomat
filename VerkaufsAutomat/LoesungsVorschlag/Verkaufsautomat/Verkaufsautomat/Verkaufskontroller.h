#pragma once

class CVKZustand;
class CVerkaufsautomat;

class CVerkaufskontroller
{
private:
    CVKZustand *m_pZustand;
    CVerkaufsautomat *m_pVerkaufsautomat;

public:
    CVerkaufskontroller(CVerkaufsautomat *pVKA);
    virtual ~CVerkaufskontroller(void);

    void produktGewaehlt(void);

    void produktAusgegeben(void);
    void stoerungProdukt(void);

    void ANS_BetragKassiert(void);
    void ANS_BetragNichtKassiert(void);
    void ANS_GeldZurueckgegeben(void);

    CVerkaufsautomat* GetVerkaufsautomat(void);
    void neuerZustand(CVKZustand *nz);
};
