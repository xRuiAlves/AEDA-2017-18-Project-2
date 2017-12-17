#include "AcidenteVeiculo.h"

AcidenteVeiculo::AcidenteVeiculo(const Marca & marca , const Date & dataUltimoAcidente) :
	marca(marca) ,
	dataUltimoAcidente(dataUltimoAcidente)
{
	numAcidentes = 1;	// Primeiro acidente com esta marca!
}

AcidenteVeiculo::~AcidenteVeiculo() {}



Marca AcidenteVeiculo::getMarca() const{
	// TODO
}

unsigned int AcidenteVeiculo::getNumAcidentes() const{
	// TODO
}

Date AcidenteVeiculo::getDataUltimoAcidente() const{
	// TODO
}



void AcidenteVeiculo::setNumAcidentes(unsigned int numAcidentes){
	// TODO
}

void AcidenteVeiculo::setDataUltimoAcidente(const Date & novaDataUltimoAcidente){
	// TODO
}



bool AcidenteVeiculo::operator < (const AcidenteVeiculo & other){
	// TODO
}

bool AcidenteVeiculo::operator ==(const AcidenteVeiculo & other){
	// TODO
}
