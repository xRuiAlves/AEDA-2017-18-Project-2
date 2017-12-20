#ifndef CONDUTOR_H_
#define CONDUTOR_H_

#include <iostream>
#include <string>
#include "Date.h"


class Condutor {
private:
	const std::string nome;
	Date dataUltimoAcidente;
public:
	Condutor(const std::string & nome , const Date & dataUltimoAcidente);
	~Condutor();

	std::string getNome() const;										
	Date getDataUltimoAcidente() const;									

	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);	
	void printSimplifiedInfo(std::ostream & os) const;
	void printCompleteInfo() const;
};


#endif /* CONDUTOR_H_ */
