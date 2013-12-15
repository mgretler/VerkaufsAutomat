#pragma once

#include "Verkaufskontroller.h"
#include "Kassenkontroller.h"
#include "TestVerkaufsautomat.h"

class CVerkaufsautomat
{
private:
    // Achtung: Die Testumbebung zuerst initialisieren der Verkaufskontroller
    //          der Kassenkontroller sind davon abhängig.
    // Hinweis: Die Initialisierungsreihenfolge wird bestimmt durch die Reihenfolge
    //          der Deklaration der Membervariablen.
    CTestVerkaufsautomat *m_pTestUmgebung;

    CVerkaufskontroller m_Verkaufskontroller;
    CKassenkontroller   m_Kassenkontroller;

public:
    CVerkaufsautomat(CTestVerkaufsautomat *tva);
    virtual ~CVerkaufsautomat(void);

    // Ereignise Bedienperson
    void produktGewaehlt(void);

    // Ereignis Münzeinwurf
    void muenzeEingeworfen(unsigned wert);

    // Ereignis Produktausgabe
    void produktAusgegeben(void);
    void stoerungProdukt(void);

    // Ereignis Kasse
    void geldZurueckgegeben(void);

    // Ereignis Timer
    void timeout(void);

    CTestVerkaufsautomat* GetTestUmgebung(void);
    CKassenkontroller* GetKassenkontroller(void);
    CVerkaufskontroller* GetVerkaufskontroller(void);
    
    unsigned GetPreis(void);

};
