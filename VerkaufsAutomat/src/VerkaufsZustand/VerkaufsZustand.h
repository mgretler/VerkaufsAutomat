/*
 * VerkaufsZustand.h
 *
 *  Created on: 14.12.2013
 *      Author: Markus
 */

#ifndef VERKAUFSZUSTAND_H_
#define VERKAUFSZUSTAND_H_

class VerkaufsZustand {
public:
	VerkaufsZustand();
	virtual ~VerkaufsZustand();
	void ProduktGewaehlt();
	void ProduktBezahlt();
	void ProduktAusgegeben();
};

#endif /* VERKAUFSZUSTAND_H_ */
