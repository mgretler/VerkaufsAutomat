/*
 * BetragErhalten.h
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#ifndef BETRAGERHALTEN_H_
#define BETRAGERHALTEN_H_

#include "KassenZustand.h"

class BetragErhalten: public KassenZustand {
public:
	virtual ~BetragErhalten();
	static BetragErhalten* GetInstance();
private:
	BetragErhalten();
	static BetragErhalten* pInstance;
};

#endif /* BETRAGERHALTEN_H_ */
