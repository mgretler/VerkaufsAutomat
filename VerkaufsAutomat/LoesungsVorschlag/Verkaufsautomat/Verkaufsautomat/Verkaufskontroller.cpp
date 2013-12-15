#include "StdAfx.h"
#include "Verkaufskontroller.h"
#include "VKProduktAuswaehlen.h"
#include "TestVerkaufsautomat.h"
#include "Verkaufsautomat.h"

CVerkaufskontroller::CVerkaufskontroller(CVerkaufsautomat *pVKA):
    m_pVerkaufsautomat(pVKA),
    m_pZustand(CVKProduktAuswaehlen::GetInstance())
{
    // Moore Ausgang des Initialzustandes setzen
    m_pVerkaufsautomat->GetTestUmgebung()->anzeigeProduktWaehlen(true);
}

CVerkaufskontroller::~CVerkaufskontroller(void)
{
}

void CVerkaufskontroller::produktGewaehlt(void)
{
    m_pZustand->produktGewaehlt(this);
}

void CVerkaufskontroller::produktAusgegeben(void)
{
    m_pZustand->produktAusgegeben(this);
}

void CVerkaufskontroller::stoerungProdukt(void)
{
    m_pZustand->stoerungProdukt(this);
}

void CVerkaufskontroller::ANS_BetragKassiert(void)
{
    m_pZustand->ANS_BetragKassiert(this);
}

void CVerkaufskontroller::ANS_BetragNichtKassiert(void)
{
    m_pZustand->ANS_BetragNichtKassiert(this);
}

void CVerkaufskontroller::ANS_GeldZurueckgegeben(void)
{
    m_pZustand->ANS_GeldZurueckgegeben(this);
}

CVerkaufsautomat* CVerkaufskontroller::GetVerkaufsautomat(void)
{
    return m_pVerkaufsautomat;
}

void CVerkaufskontroller::neuerZustand(CVKZustand *nz)
{
    m_pZustand = nz;
}
