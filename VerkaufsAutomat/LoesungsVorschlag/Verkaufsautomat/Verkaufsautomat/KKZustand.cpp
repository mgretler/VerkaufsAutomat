#include "StdAfx.h"
#include "KKZustand.h"

CKKZustand::CKKZustand(void)
{
}
CKKZustand::CKKZustand(char *kkZustandsname)
{
    m_kkZustandsname = kkZustandsname;
}

CKKZustand::~CKKZustand(void)
{
}

void CKKZustand::muenzeEingeworfen(CKassenkontroller *kk,unsigned wert)
{
}

void CKKZustand::geldZurueckgegeben(CKassenkontroller *kk)
{
}

void CKKZustand::CMD_Kassieren(CKassenkontroller *kk)
{
}

void CKKZustand::CMD_GeldInKasseLegen(CKassenkontroller *kk)
{
}

void CKKZustand::CMD_GeldZurueckgeben(CKassenkontroller *kk)
{
}

void CKKZustand::timeout(CKassenkontroller *kk)
{
}
