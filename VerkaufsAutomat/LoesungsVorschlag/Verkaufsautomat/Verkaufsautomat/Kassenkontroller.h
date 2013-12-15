#pragma once

class CKKZustand;
class CVerkaufsautomat;

class CKassenkontroller
{
private:
    CKKZustand *m_pZustand;
    CVerkaufsautomat *m_pVerkaufsautomat;

    unsigned    m_Betrag;

public:
    CKassenkontroller(CVerkaufsautomat *pVKA);
    virtual ~CKassenkontroller(void);

    // Ereignisse
    void muenzeEingeworfen(unsigned wert);

    void geldZurueckgegeben(void);

    void CMD_Kassieren(void);
    void CMD_GeldInKasseLegen(void);
    void CMD_GeldZurueckgeben(void);

    void timeout(void);

    void neuerZustand(CKKZustand *nz);

    CVerkaufsautomat* GetVerkaufsautomat(void);
    
    // Referenz auf Betrag bilden
    unsigned& GetBetragReferenz(void);

};
