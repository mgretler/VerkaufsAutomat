/*
 * WartenAufKassieren.cpp
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#include "WartenAufKassieren.h"
#include <iostream>

WartenAufKassieren *WartenAufKassieren::pInstance = NULL;

WartenAufKassieren::~WartenAufKassieren() {
	// TODO Auto-generated destructor stub
}
WartenAufKassieren::WartenAufKassieren() {
	// TODO Auto-generated constructor stub

}
WartenAufKassieren* WartenAufKassieren::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new WartenAufKassieren();
	}
	return pInstance;
}
