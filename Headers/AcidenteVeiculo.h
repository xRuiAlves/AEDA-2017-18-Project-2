#ifndef ACIDENTEVEICULO_H_
#define ACIDENTEVEICULO_H_

#include <iostream>
#include <string>
#include "Marca.h"
#include "Date.h"


class AcidenteVeiculo {
private:
	const Marca marca;
	unsigned int numAcidentes;
	Date dataUltimoAcidente;
public:
	AcidenteVeiculo(const std::string & nomeMarca , unsigned int numAcidentes , const Date & dataUltimoAcidente);
	~AcidenteVeiculo();

	Marca getMarca() const;												
	unsigned int getNumAcidentes() const;								
	Date getDataUltimoAcidente() const;									

	void setNumAcidentes(unsigned int novoNumAcidentes);				
	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);
	void printSimplifiedInfo(std::ostream & os) const;
	void printCompleteInfo() const;

	bool operator < (const AcidenteVeiculo & other) const;
	bool operator ==(const AcidenteVeiculo & other) const;
};


#endif /* ACIDENTEVEICULO_H_ */
