/*
 * KassenZustand.h
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#ifndef KASSENZUSTAND_H_
#define KASSENZUSTAND_H_

class KassenZustand {
public:
	KassenZustand();
	virtual ~KassenZustand();
	void Kassieren();
	void MuenzeEingeworfen();
	void BetragGroesserPreis();
	void GeldInKasseLegen();
};

#endif /* KASSENZUSTAND_H_ */
