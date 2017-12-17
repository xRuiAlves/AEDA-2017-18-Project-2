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

	Marca getMarca() const;												// TODO
	unsigned int getNumAcidentes() const;								// TODO
	Date getDataUltimoAcidente() const;									// TODO

	void setNumAcidentes(unsigned int numAcidentes);					// TODO
	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);	// TODO

	bool operator < (const AcidenteVeiculo & other);					// TODO
	bool operator ==(const AcidenteVeiculo & other);					// TODO
};


#endif /* ACIDENTEVEICULO_H_ */
