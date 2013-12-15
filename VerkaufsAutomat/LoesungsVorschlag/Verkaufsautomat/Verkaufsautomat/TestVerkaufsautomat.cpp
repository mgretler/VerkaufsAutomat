#include "StdAfx.h"
#include "TestVerkaufsautomat.h"
#include "Verkaufsautomat.h"

CTestVerkaufsautomat::CTestVerkaufsautomat(void) :
    m_AnzeigeProduktWaehlen(false),
    m_AnzeigeGeldEinwerfen(false),
    m_AnzeigeProduktEntnehmen(false),
    m_AnzeigeGeldEntnehmen(false),
    m_MuenzeinwurfOffen(false),
    m_AufrufProduktAusgeben(false),
    m_AufrufGeldInKasseLegen(false),
    m_AufrufGeldZurueckgeben(false)
{
}

CTestVerkaufsautomat::~CTestVerkaufsautomat(void)
{
}

void CTestVerkaufsautomat::setDUT(CVerkaufsautomat *pDUT)
{
    m_pDUT = pDUT;
}

// Ereignisse Bedienperson
void CTestVerkaufsautomat::anzeigeProduktWaehlen (bool einschalten)
{
    m_AnzeigeProduktWaehlen = einschalten;
}
void CTestVerkaufsautomat::anzeigeGeldEinwerfen(bool einschalten)
{
    m_AnzeigeGeldEinwerfen = einschalten;
}

void CTestVerkaufsautomat::anzeigeProduktEntnehmen(bool einschalten)
{
    m_AnzeigeProduktEntnehmen = einschalten;
}

void CTestVerkaufsautomat::anzeigeGeldEntnehmen(bool einschalten)
{
    m_AnzeigeGeldEntnehmen = einschalten;
}


// Ereignis Münzeinwurf
void CTestVerkaufsautomat::muenzeinwurfOeffnen(bool oeffnen)
{
    m_MuenzeinwurfOffen = oeffnen;
}


// Ereignis Produktausgabe
void CTestVerkaufsautomat::produktAusgeben(void)
{
    m_AufrufProduktAusgeben = true;
}

// Ereignisse Kasse
void CTestVerkaufsautomat::geldInKasseLegen(void)
{
    m_AufrufGeldInKasseLegen =true;
}

void CTestVerkaufsautomat::geldZurueckgeben(void)
{
    m_AufrufGeldZurueckgeben = true;
}

// Testfaelle

CTestVerkaufsautomat::eErrorCodes CTestVerkaufsautomat::TestVerkaufskontroller(enum eTestfaelle testfall)
{
    // Initialzustand: "Produkt auswählen"
    if (!m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

    // Ereignis "Produkt gewaehlt":
    m_pDUT->produktGewaehlt();
    
    // Zustand "Produkt Bezahlen": Anzeigen überprüfen
    if (m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;
    if (!m_AnzeigeGeldEinwerfen)
        return ERROR_ANZEIGE_GELD_EINWERFEN;
    
    if (testfall == VK_BETRAG_NICHT_KASSIERT)
    {
        // Simulation Kassenkontroller:
        // Ereignis "ANS_BetragKassiert" an Verkaufskontroller:
        m_pDUT->GetVerkaufskontroller()->ANS_BetragNichtKassiert();
    
        // Zustand "Geld zurueckgeben": Anzeigen überprüfen
        if (m_AnzeigeGeldEinwerfen)
            return ERROR_ANZEIGE_GELD_EINWERFEN;
        if (!m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
     
        // Simulation Kassenkontroller:
        // Ereignis "ANS_Geld zurückgegeben":
        m_pDUT->GetVerkaufskontroller()->ANS_GeldZurueckgegeben();

        // Zustand "Produkt auswaehlen": Anzeigen überprüfen
        if (m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
        if (!m_AnzeigeProduktWaehlen)
            return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

        return ERROR_SUCCESS;
    }

    // Simulation Kassenkontroller:
    // Ereignis "ANS_BetragKassiert" an Verkaufskontroller:
    m_pDUT->GetVerkaufskontroller()->ANS_BetragKassiert();

    // Zustand "Produkt ausgeben": Anzeigen überprüfen
    if (m_AnzeigeGeldEinwerfen)
        return ERROR_ANZEIGE_GELD_EINWERFEN;
    if (!m_AnzeigeProduktEntnehmen)
        return ERROR_ANZEIGE_PRODUKT_ENTNEHMEN;
 
    if (testfall == VK_STOERUNG_PRODUKT)
    {
         // Ereignis "Stlerung Produkt"
        m_pDUT->stoerungProdukt();
    
        // Zustand "Geld zurueckgeben": Anzeigen überprüfen
        if (m_AnzeigeGeldEinwerfen)
            return ERROR_ANZEIGE_GELD_EINWERFEN;
        if (!m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
     
        // Simulation Kassenkontroller:
        // Ereignis "ANS_Geld zurückgegeben":
        m_pDUT->GetVerkaufskontroller()->ANS_GeldZurueckgegeben();

        // Zustand "Produkt auswaehlen": Anzeigen überprüfen
        if (m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
        if (!m_AnzeigeProduktWaehlen)
            return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

        return ERROR_SUCCESS;
    }

    // Ereignis "Produkt ausgegeben":
    m_pDUT->produktAusgegeben();

    // Zustand "Produkt auswaehlen": Anzeigen überprüfen
    if (m_AnzeigeProduktEntnehmen)
        return ERROR_ANZEIGE_PRODUKT_ENTNEHMEN;
    if (!m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;
    // Meldung an Produktausgabe überprüfen
    if (!m_AufrufProduktAusgeben)
        return ERROR_PRODUKT_AUSGEBEN_NICHT_AUFGERUFEN;
    else
        m_AufrufProduktAusgeben = false;

    return ERROR_SUCCESS;
}

CTestVerkaufsautomat::eErrorCodes CTestVerkaufsautomat::TestKassenkontroller(enum eTestfaelle testfall)
{
    return ERROR_NOT_IMPLEMENTED;
}

CTestVerkaufsautomat::eErrorCodes CTestVerkaufsautomat::TestVerkaufsautomat(enum eTestfaelle testfall)
{
    // Initialzustand: "Produkt auswählen"
    if (!m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

    // Münzeinwurf prüfen
    if (m_MuenzeinwurfOffen)
        return ERROR_MUENZEINWURF_OFFEN;

    // Ereignis "Produkt gewaehlt":
    m_pDUT->produktGewaehlt();
    
    // Zustand "Produkt Bezahlen": Anzeigen überprüfen
    if (m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;
    if (!m_AnzeigeGeldEinwerfen)
        return ERROR_ANZEIGE_GELD_EINWERFEN;
 
    // Münzeinwurf prüfen
    if (!m_MuenzeinwurfOffen)
        return ERROR_MUENZEINWURF_GESCHLOSSEN;
    
    if (testfall == VA_TIMEOUT_GELDEINWURF)
    {
        // Ereignis "Timeout" an Verkaufskontroller:
        m_pDUT->timeout();
    
        // Zustand "Geld zurueckgeben": Anzeigen überprüfen
        if (m_AnzeigeGeldEinwerfen)
            return ERROR_ANZEIGE_GELD_EINWERFEN;
        if (!m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
     
        // Ereignis "Geld zurückgegeben" der Kasse:
        m_pDUT->geldZurueckgegeben();

        // Zustand "Produkt auswaehlen": Anzeigen überprüfen
        if (m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
        if (!m_AnzeigeProduktWaehlen)
            return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

        // Meldung "Geld zurueckgeben" an Kasse überprüfen
        if (!m_AufrufGeldZurueckgeben)
            return ERROR_GELD_ZURUECKGEBEN_NICHT_AUFGERUFEN;
        else
            m_AufrufGeldZurueckgeben = false;

        return ERROR_SUCCESS;
    }

    
    // Ereignis "Münze eingeworfen", Betrag zu klein
    m_pDUT->muenzeEingeworfen(9);

    // Zustand "Produkt Bezahlen": Anzeigen überprüfen
    if (m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;
    if (!m_AnzeigeGeldEinwerfen)
        return ERROR_ANZEIGE_GELD_EINWERFEN;
    // Münzeinwurf prüfen
    if (!m_MuenzeinwurfOffen)
        return ERROR_MUENZEINWURF_GESCHLOSSEN;

    // Ereignis "Münze eingeworfen", Betrag zu ok (Summe)
    m_pDUT->muenzeEingeworfen(34);

    // Zustand "Produkt ausgeben": Anzeigen überprüfen
    if (m_AnzeigeGeldEinwerfen)
        return ERROR_ANZEIGE_GELD_EINWERFEN;
    if (!m_AnzeigeProduktEntnehmen)
        return ERROR_ANZEIGE_PRODUKT_ENTNEHMEN;
    // Münzeinwurf prüfen
    if (m_MuenzeinwurfOffen)
        return ERROR_MUENZEINWURF_OFFEN;
 
    if (testfall == VA_STOERUNG_PRODUKT)
    {
         // Ereignis "Stlerung Produkt"
        m_pDUT->stoerungProdukt();
    
        // Zustand "Geld zurueckgeben": Anzeigen überprüfen
        if (m_AnzeigeGeldEinwerfen)
            return ERROR_ANZEIGE_GELD_EINWERFEN;
        if (!m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
     
        // Ereignis "Geld zurückgegeben" der Kasse:
        m_pDUT->geldZurueckgegeben();

        // Zustand "Produkt auswaehlen": Anzeigen überprüfen
        if (m_AnzeigeGeldEntnehmen)
            return ERROR_ANZEIGE_GELD_ENTNEHMEN;
        if (!m_AnzeigeProduktWaehlen)
            return ERROR_ANZEIGE_PRODUKT_WAEHLEN;
                
        // Meldung "Geld zurueckgeben" an Kasse überprüfen
        if (!m_AufrufGeldZurueckgeben)
            return ERROR_GELD_ZURUECKGEBEN_NICHT_AUFGERUFEN;
        else
            m_AufrufGeldZurueckgeben = false;

        return ERROR_SUCCESS;
    }

    
    // Ereignis "Produkt ausgegeben":
    m_pDUT->produktAusgegeben();

    // Zustand "Produkt auswaehlen": Anzeigen überprüfen
    if (m_AnzeigeProduktEntnehmen)
        return ERROR_ANZEIGE_PRODUKT_ENTNEHMEN;
    if (!m_AnzeigeProduktWaehlen)
        return ERROR_ANZEIGE_PRODUKT_WAEHLEN;

    // Meldung an Produktausgabe überprüfen
    if (!m_AufrufProduktAusgeben)
        return ERROR_PRODUKT_AUSGEBEN_NICHT_AUFGERUFEN;
    else
        m_AufrufProduktAusgeben = false;

    // Meldung an Kasse überprüfen
    if (!m_AufrufGeldInKasseLegen)
        return ERROR_GELD_IN_KASSE_LEGEN_NICHT_AUFGERUFEN;
    else
        m_AufrufGeldInKasseLegen = false;

    return ERROR_SUCCESS;
}
