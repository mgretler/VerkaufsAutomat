/*
 * VerkaufsZustand.cpp
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#include "VerkaufsZustand.h"
#include "ProduktAusgeben.h"
#include "ProduktAuswaehlen.h"
#include "ProduktBezahlen.h"
#include <iostream>

VerkaufsZustand::VerkaufsZustand() {
	ProduktAusgeben* pAusgabe = ProduktAusgeben::GetInstance();
}

VerkaufsZustand::~VerkaufsZustand() {
	// TODO Auto-generated destructor stub
}

