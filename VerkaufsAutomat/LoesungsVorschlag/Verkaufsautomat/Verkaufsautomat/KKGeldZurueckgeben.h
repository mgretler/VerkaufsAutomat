#pragma once
#include "KKZustand.h"

class CKKGeldZurueckgeben :
    public CKKZustand
{
private:
    static CKKGeldZurueckgeben *m_pInstance;
    CKKGeldZurueckgeben(void);

public:
    static CKKGeldZurueckgeben* GetInstance(void);
    virtual ~CKKGeldZurueckgeben(void);

    // Ereignis
    void geldZurueckgegeben(CKassenkontroller *kk);

};
