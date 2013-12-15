#include "StdAfx.h"
#include "VKZustand.h"

CVKZustand::CVKZustand(void)
{
}
CVKZustand::CVKZustand(char *vkZustandsname)
{
    m_vkZustandsname = vkZustandsname;
}

CVKZustand::~CVKZustand(void)
{
}

void CVKZustand::produktGewaehlt(CVerkaufskontroller *vk)
{
}

void CVKZustand::produktAusgegeben(CVerkaufskontroller *vk)
{
}

void CVKZustand::stoerungProdukt(CVerkaufskontroller *vk)
{
}

void CVKZustand::ANS_BetragKassiert(CVerkaufskontroller *vk)
{
}

void CVKZustand::ANS_BetragNichtKassiert(CVerkaufskontroller *vk)
{
}

void CVKZustand::ANS_GeldZurueckgegeben(CVerkaufskontroller *vk)
{
}