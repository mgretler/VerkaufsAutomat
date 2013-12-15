/*
 * WarteAufMuenze.cpp
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#include "WarteAufMuenze.h"
#include <iostream>

WarteAufMuenze *WarteAufMuenze::pInstance = NULL;

WarteAufMuenze::~WarteAufMuenze() {
	// TODO Auto-generated destructor stub
}
WarteAufMuenze::WarteAufMuenze() {
	// TODO Auto-generated constructor stub

}

WarteAufMuenze* WarteAufMuenze::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new WarteAufMuenze();
	}
	return pInstance;
}

