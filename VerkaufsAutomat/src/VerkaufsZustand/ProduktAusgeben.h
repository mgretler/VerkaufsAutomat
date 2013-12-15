/*
 * ProduktAusgeben.h
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#ifndef PRODUKTAUSGEBEN_H_
#define PRODUKTAUSGEBEN_H_

#include "VerkaufsZustand.h"

class ProduktAusgeben: public VerkaufsZustand {
public:
	virtual ~ProduktAusgeben();
	static ProduktAusgeben* GetInstance();
	void ProduktAusgegeben();
private:
	ProduktAusgeben();
	static ProduktAusgeben *pInstance;

};

#endif /* PRODUKTAUSGEBEN_H_ */
