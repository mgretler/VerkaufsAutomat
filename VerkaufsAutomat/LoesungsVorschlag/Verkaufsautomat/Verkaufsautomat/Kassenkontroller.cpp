#include "StdAfx.h"
#include "Kassenkontroller.h"
#include "KKWartenAufKassieren.h"


CKassenkontroller::CKassenkontroller(CVerkaufsautomat *pVKA):
    m_pVerkaufsautomat(pVKA),
    m_pZustand(CKKWartenAufKassieren::GetInstance()),
    m_Betrag(0)
{
}

CKassenkontroller::~CKassenkontroller(void)
{
}

// Ereignisse
void CKassenkontroller::muenzeEingeworfen(unsigned wert)
{
    m_pZustand->muenzeEingeworfen(this,wert);
}

void CKassenkontroller::geldZurueckgegeben(void)
{
    m_pZustand->geldZurueckgegeben(this);
}

void CKassenkontroller::CMD_Kassieren(void)
{
    m_pZustand->CMD_Kassieren(this);
}

void CKassenkontroller::CMD_GeldInKasseLegen(void)
{
    m_pZustand->CMD_GeldInKasseLegen(this);
}

void CKassenkontroller::CMD_GeldZurueckgeben(void)
{
    m_pZustand->CMD_GeldZurueckgeben(this);
}

void CKassenkontroller::timeout(void)
{
    m_pZustand->timeout(this);
}

CVerkaufsautomat* CKassenkontroller::GetVerkaufsautomat(void)
{
    return m_pVerkaufsautomat;
}

void CKassenkontroller::neuerZustand(CKKZustand *nz)
{
    m_pZustand = nz;
}

// Betrag Referenz zurückgeben

unsigned& CKassenkontroller::GetBetragReferenz(void)
{
    return m_Betrag;
}