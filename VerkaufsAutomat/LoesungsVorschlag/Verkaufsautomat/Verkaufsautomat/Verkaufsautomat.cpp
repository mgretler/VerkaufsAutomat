#include "StdAfx.h"
#include "Verkaufsautomat.h"

CVerkaufsautomat::CVerkaufsautomat(CTestVerkaufsautomat *tva):
    m_pTestUmgebung(tva),
    m_Kassenkontroller(this),
    m_Verkaufskontroller(this)
{
}

CVerkaufsautomat::~CVerkaufsautomat(void)
{
}

// Ereignise Bedienperson
void CVerkaufsautomat::produktGewaehlt(void)
{
    m_Verkaufskontroller.produktGewaehlt();
}

// Ereignis Münzeinwurf
void CVerkaufsautomat::muenzeEingeworfen(unsigned wert)
{
    m_Kassenkontroller.muenzeEingeworfen(wert);
}

// Ereignis Produktausgabe
void CVerkaufsautomat::produktAusgegeben(void)
{
    m_Verkaufskontroller.produktAusgegeben();
}

void CVerkaufsautomat::stoerungProdukt(void)
{
    m_Verkaufskontroller.stoerungProdukt();
}

// Ereignis Kasse
void CVerkaufsautomat::geldZurueckgegeben(void)
{
     m_Kassenkontroller.geldZurueckgegeben();
}

CTestVerkaufsautomat* CVerkaufsautomat::GetTestUmgebung(void)
{
    return m_pTestUmgebung;
}

CKassenkontroller* CVerkaufsautomat::GetKassenkontroller(void)
{
    return &m_Kassenkontroller;
}

CVerkaufskontroller* CVerkaufsautomat::GetVerkaufskontroller(void)
{
    return &m_Verkaufskontroller;
}

// Ereignis Timer
void CVerkaufsautomat::timeout(void)
{
    m_Kassenkontroller.timeout();
}

// Preis der Produkte
unsigned CVerkaufsautomat::GetPreis(void)
{
    return 42;
}
