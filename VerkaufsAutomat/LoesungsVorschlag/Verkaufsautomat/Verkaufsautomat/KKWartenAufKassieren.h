#pragma once
#include "KKZustand.h"

class CKKWartenAufKassieren :
    public CKKZustand
{
private:
    static CKKWartenAufKassieren *m_pInstance;
    CKKWartenAufKassieren(void);

public:
    static CKKWartenAufKassieren* GetInstance(void);
    virtual ~CKKWartenAufKassieren(void);

    // Ereignisse
    void CMD_Kassieren(CKassenkontroller *kk);
};
