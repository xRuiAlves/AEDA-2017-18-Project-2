#ifndef ACIDENTEVEICULO_H_
#define ACIDENTEVEICULO_H_

#include "Marca.h"
#include "Date.h"

class AcidenteVeiculo {
private:
	const Marca marca;
	unsigned int numAcidentes;
	Date dataUltimoAcidente;
public:
	AcidenteVeiculo(const Marca & marca , const Date & dataUltimoAcidente);
	~AcidenteVeiculo();

	Marca getMarca() const;												
	unsigned int getNumAcidentes() const;								
	Date getDataUltimoAcidente() const;									

	void setNumAcidentes(unsigned int novoNumAcidentes);				
	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);
	void printSimplifiedInfo(std::ostream & os) const;

	bool operator < (const AcidenteVeiculo & other);					
	bool operator ==(const AcidenteVeiculo & other);					
};


#endif /* ACIDENTEVEICULO_H_ */
