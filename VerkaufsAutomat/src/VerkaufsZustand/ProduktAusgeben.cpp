/*
 * ProduktAusgeben.cpp
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#include "ProduktAusgeben.h"
#include <iostream>

ProduktAusgeben *ProduktAusgeben::pInstance = NULL;

ProduktAusgeben::~ProduktAusgeben() {
	pInstance = NULL;
}

ProduktAusgeben::ProduktAusgeben() {
}

ProduktAusgeben* ProduktAusgeben::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new ProduktAusgeben();
	}
	return pInstance;
}

