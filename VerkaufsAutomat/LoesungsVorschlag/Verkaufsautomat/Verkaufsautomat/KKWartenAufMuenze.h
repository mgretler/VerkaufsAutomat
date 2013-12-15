#pragma once
#include "KKZustand.h"

class CKKWartenAufMuenze :
    public CKKZustand
{
private:
    static CKKWartenAufMuenze *m_pInstance;
    CKKWartenAufMuenze(void);

public:
    static CKKWartenAufMuenze* GetInstance(void);
    virtual ~CKKWartenAufMuenze(void);

    // Ereignisse
    void muenzeEingeworfen(CKassenkontroller *kk,unsigned wert);
    void timeout(CKassenkontroller *kk);
};
