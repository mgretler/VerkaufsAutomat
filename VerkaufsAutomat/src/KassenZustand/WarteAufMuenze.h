/*
 * WarteAufMuenze.h
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#ifndef WARTEAUFMUENZE_H_
#define WARTEAUFMUENZE_H_

#include "KassenZustand.h"

class WarteAufMuenze: public KassenZustand {
public:
	virtual ~WarteAufMuenze();
	static WarteAufMuenze* GetInstance();

private:
	WarteAufMuenze();
	static WarteAufMuenze* pInstance;
};

#endif /* WARTEAUFMUENZE_H_ */
