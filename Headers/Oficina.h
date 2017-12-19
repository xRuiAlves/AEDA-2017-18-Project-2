#ifndef OFICINA_H_
#define OFICINA_H_

#include <vector>
#include <iostream>
#include "Marca.h"



class Oficina {
private:
	const unsigned int id;
	unsigned int disponibilidade;
	const std::vector<Marca> marcasRepresentadas;
public:
	Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas);
	~Oficina();

	unsigned int getID() const;								
	unsigned int getDisponibilidade() const;				
	std::vector<Marca> getMarcasRepresentadas() const;		

	void adicionarVeiculo();
	void printSimplifiedInfo(std::ostream & os) const;

	bool operator<(const Oficina & other) const;
};


#endif /* OFICINA_H_ */
