#include "Oficina.h"

Oficina::Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas) :
	id(id),
	disponibilidade(disponibilidade) ,
	marcasRepresentadas(marcasRepresentadas) {}

Oficina::~Oficina() {}



unsigned int Oficina::getID() const{
	// TODO
}

unsigned int Oficina::getDisponibilidade() const{
	// TODO
}

std::vector<Marca> Oficina::getMarcasRepresentadas() const{
	// TODO
}



void Oficina::adicionarVeiculo(){
	// TODO
}
