/*
 * BetragBerechnen.cpp
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#include "BetragBerechnen.h"
#include <iostream>

BetragBerechnen *BetragBerechnen::pInstance = NULL;

BetragBerechnen::~BetragBerechnen() {
	// TODO Auto-generated destructor stub
}
BetragBerechnen::BetragBerechnen() {
	// TODO Auto-generated constructor stub

}

BetragBerechnen* BetragBerechnen::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new BetragBerechnen();
	}
	return pInstance;
}
