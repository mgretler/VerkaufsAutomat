/*
 * ProduktAuswaehlen.cpp
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#include "ProduktAuswaehlen.h"
#include <iostream>

ProduktAuswaehlen *ProduktAuswaehlen::pInstance = NULL;

ProduktAuswaehlen::~ProduktAuswaehlen() {
	pInstance = NULL;
}

ProduktAuswaehlen::ProduktAuswaehlen() {
}

ProduktAuswaehlen* ProduktAuswaehlen::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new ProduktAuswaehlen();
	}
	return pInstance;
}
