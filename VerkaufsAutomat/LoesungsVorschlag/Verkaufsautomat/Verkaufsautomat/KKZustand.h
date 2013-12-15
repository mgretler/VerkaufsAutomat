#pragma once

class CKassenkontroller;

class CKKZustand
{
protected:
    CKKZustand(void);
    CKKZustand(char *kkZustandsname);
public:
    virtual ~CKKZustand(void);

    // Ereignisse
    virtual void muenzeEingeworfen(CKassenkontroller *kk,unsigned wert);

    virtual void geldZurueckgegeben(CKassenkontroller *kk);

    virtual void CMD_Kassieren(CKassenkontroller *kk);
    virtual void CMD_GeldInKasseLegen(CKassenkontroller *kk);
    virtual void CMD_GeldZurueckgeben(CKassenkontroller *kk);
    virtual void timeout(CKassenkontroller *kk);

    //Debug
    char *m_kkZustandsname;
};
