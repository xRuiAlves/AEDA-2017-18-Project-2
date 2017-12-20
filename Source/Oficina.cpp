#include "Oficina.h"

Oficina::Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas) :
	id(id),
	disponibilidade(disponibilidade) ,
	marcasRepresentadas(marcasRepresentadas) {}

Oficina::~Oficina() {}



unsigned int Oficina::getID() const{
	return id;
}

unsigned int Oficina::getDisponibilidade() const{
	return disponibilidade;
}

std::vector<Marca> Oficina::getMarcasRepresentadas() const{
	return marcasRepresentadas;
}



void Oficina::adicionarVeiculo(){
	disponibilidade++;
}

void Oficina::printSimplifiedInfo(std::ostream & os) const{
	os << id << '/' << disponibilidade << '/' << marcasRepresentadas.size();

	for (unsigned int i=0 ; i<marcasRepresentadas.size() ; i++){
		os << "\n\t" << marcasRepresentadas.at(i).getNomeMarca();
	}
}

void Oficina::printCompleteInfo() const{
	std::cout << "***  Oficina #" << id << "  ***" << std::endl;
	std::cout << "Disponibilidade: " << disponibilidade << std::endl;
	std::cout << "Marcas Representadas:" << std::endl;
	for (unsigned int i=0 ; i<marcasRepresentadas.size() ; i++){
		std::cout << "- " << marcasRepresentadas.at(i).getNomeMarca() << std::endl;
	}
}



bool Oficina::operator<(const Oficina & other) const{
	return (this->disponibilidade > other.disponibilidade);
}
