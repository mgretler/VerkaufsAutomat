/*
 * ProduktBezahlen.h
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#ifndef PRODUKTBEZAHLEN_H_
#define PRODUKTBEZAHLEN_H_

#include "VerkaufsZustand.h"

class ProduktBezahlen: public VerkaufsZustand {
public:
	virtual ~ProduktBezahlen();
	static ProduktBezahlen* GetInstance();
	void ProduktBezahlt();

private:
	ProduktBezahlen();
	static ProduktBezahlen *pInstance;
};

#endif /* PRODUKTBEZAHLEN_H_ */
