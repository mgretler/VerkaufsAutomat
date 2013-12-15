/*
 * BetragBerechnen.h
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#ifndef BETRAGBERECHNEN_H_
#define BETRAGBERECHNEN_H_

#include "KassenZustand.h"

class BetragBerechnen: public KassenZustand {
public:
	virtual ~BetragBerechnen();
	static BetragBerechnen* GetInstance();
private:
	BetragBerechnen();
	static BetragBerechnen* pInstance;
};

#endif /* BETRAGBERECHNEN_H_ */
