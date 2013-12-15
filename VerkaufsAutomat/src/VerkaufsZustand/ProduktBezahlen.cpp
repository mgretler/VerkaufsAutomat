/*
 * ProduktBezahlen.cpp
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#include "ProduktBezahlen.h"
#include <iostream>

ProduktBezahlen *ProduktBezahlen::pInstance = NULL;

ProduktBezahlen::~ProduktBezahlen() {
	pInstance = NULL;
}

ProduktBezahlen::ProduktBezahlen() {
}

ProduktBezahlen* ProduktBezahlen::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new ProduktBezahlen();
	}
	return pInstance;
}

