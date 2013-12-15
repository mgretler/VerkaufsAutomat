/*
 * BetragErhalten.cpp
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#include "BetragErhalten.h"
#include <iostream>

BetragErhalten *BetragErhalten::pInstance = NULL;

BetragErhalten::~BetragErhalten() {
	// TODO Auto-generated destructor stub
}
BetragErhalten::BetragErhalten() {
	// TODO Auto-generated constructor stub

}

BetragErhalten* BetragErhalten::GetInstance() {
	if (pInstance == NULL) {
		pInstance = new BetragErhalten();
	}
	return pInstance;
}
