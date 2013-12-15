/*
 * WartenAufKassieren.h
 *
 *  Created on: 15.12.2013
 *      Author: Markus
 */

#ifndef WARTENAUFKASSIEREN_H_
#define WARTENAUFKASSIEREN_H_

#include "KassenZustand.h"

class WartenAufKassieren: public KassenZustand {
public:
	virtual ~WartenAufKassieren();
	static WartenAufKassieren* GetInstance();

private:
	WartenAufKassieren();
	static WartenAufKassieren* pInstance;
};

#endif /* WARTENAUFKASSIEREN_H_ */
