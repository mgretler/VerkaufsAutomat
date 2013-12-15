/*
 * ProduktAuswaehlen.h
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#ifndef PRODUKTAUSWAEHLEN_H_
#define PRODUKTAUSWAEHLEN_H_

#include "VerkaufsZustand.h"

class ProduktAuswaehlen: public VerkaufsZustand {
public:
	virtual ~ProduktAuswaehlen();
	static ProduktAuswaehlen* GetInstance();
	void ProduktGewaehlt();

private:
	ProduktAuswaehlen();
	static ProduktAuswaehlen *pInstance;
};

#endif /* PRODUKTAUSWAEHLEN_H_ */
