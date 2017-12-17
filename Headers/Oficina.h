#ifndef OFICINA_H_
#define OFICINA_H_

#include <vector>
#include "Marca.h"


class Oficina {
private:
	const unsigned int id;
	unsigned int disponibilidade;
	const std::vector<Marca> marcasRepresentadas;
public:
	Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas);
	~Oficina();

	unsigned int getID() const;								// TODO
	unsigned int getDisponibilidade() const;				// TODO
	std::vector<Marca> getMarcasRepresentadas() const;		// TODO

	void adicionarVeiculo();								// TODO
};


#endif /* OFICINA_H_ */
