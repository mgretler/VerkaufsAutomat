#pragma once

class CVerkaufsautomat;

class CTestVerkaufsautomat
{
    
    bool m_AnzeigeProduktWaehlen;
    bool m_AnzeigeGeldEinwerfen;
    bool m_AnzeigeProduktEntnehmen;
    bool m_AnzeigeGeldEntnehmen;

    bool m_MuenzeinwurfOffen;

    bool m_AufrufProduktAusgeben;
    bool m_AufrufGeldInKasseLegen;
    bool m_AufrufGeldZurueckgeben;

    CVerkaufsautomat *m_pDUT;

public:
    enum eErrorCodes
    {
        ERROR_SUCCESS = 0,
        ERROR_ANZEIGE_PRODUKT_WAEHLEN,
        ERROR_ANZEIGE_GELD_EINWERFEN,
        ERROR_ANZEIGE_PRODUKT_ENTNEHMEN,
        ERROR_ANZEIGE_GELD_ENTNEHMEN,
        ERROR_PRODUKT_AUSGEBEN_NICHT_AUFGERUFEN,
        ERROR_GELD_IN_KASSE_LEGEN_NICHT_AUFGERUFEN,
        ERROR_GELD_ZURUECKGEBEN_NICHT_AUFGERUFEN,
        ERROR_MUENZEINWURF_GESCHLOSSEN,
        ERROR_MUENZEINWURF_OFFEN,
        ERROR_NOT_IMPLEMENTED
    };

    enum eTestfaelle
    {
        VK_NORMALFALL = 0,
        VK_BETRAG_NICHT_KASSIERT,
        VK_STOERUNG_PRODUKT,
        KK_NORMALFALL,
        KK_TIMEOUT,
        KK_GELD_ZURUECKGEBEN,
        VA_NORMALFALL,
        VA_TIMEOUT_GELDEINWURF,
        VA_STOERUNG_PRODUKT
    };

    CTestVerkaufsautomat(void);
    ~CTestVerkaufsautomat(void);

    void setDUT(CVerkaufsautomat *pDUT);

    // Ereignisse Bedienperson
    void anzeigeProduktWaehlen(bool einschalten);
    void anzeigeGeldEinwerfen(bool einschalten);
    void anzeigeProduktEntnehmen(bool einschalten);
    void anzeigeGeldEntnehmen(bool einschalten);

    // Ereignis Münzeinwurf
    void muenzeinwurfOeffnen(bool oeffnen);
    
    // Ereignis Produktausgabe
    void produktAusgeben(void);

    // Ereignisse Kasse
    void geldInKasseLegen(void);
    void geldZurueckgeben(void);

    // Testfaelle
    eErrorCodes TestVerkaufskontroller(enum eTestfaelle testfall); // nur der Verkaufskontroller wird getestet
    eErrorCodes TestKassenkontroller(enum eTestfaelle testfall); // nur der Kassenkontroller wird getestet
    eErrorCodes TestVerkaufsautomat(enum eTestfaelle testfall); // Verkaufsautomat als ganzes testen
};
