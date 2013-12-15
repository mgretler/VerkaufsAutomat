#pragma once
#include "KKZustand.h"

class CKKBetragErhalten :
    public CKKZustand
{
private:
    static CKKBetragErhalten *m_pInstance;
    CKKBetragErhalten(void);

public:
    static CKKBetragErhalten* GetInstance(void);
    virtual ~CKKBetragErhalten(void);

    // Ereignisse
    void CMD_GeldInKasseLegen(CKassenkontroller *kk);
    void CMD_GeldZurueckgeben(CKassenkontroller *kk);

};
