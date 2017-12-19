#include "AcidenteVeiculo.h"

AcidenteVeiculo::AcidenteVeiculo(const Marca & marca , const Date & dataUltimoAcidente) :
	marca(marca) ,
	dataUltimoAcidente(dataUltimoAcidente)
{
	numAcidentes = 1;	// Primeiro acidente com esta marca!
}

AcidenteVeiculo::~AcidenteVeiculo() {}



Marca AcidenteVeiculo::getMarca() const{
	return marca;
}

unsigned int AcidenteVeiculo::getNumAcidentes() const{
	return numAcidentes;
}

Date AcidenteVeiculo::getDataUltimoAcidente() const{
	return dataUltimoAcidente;
}



void AcidenteVeiculo::setNumAcidentes(unsigned int novoNumAcidentes){
	numAcidentes = novoNumAcidentes;
}

void AcidenteVeiculo::setDataUltimoAcidente(const Date & novaDataUltimoAcidente){
	dataUltimoAcidente = novaDataUltimoAcidente;
}



bool AcidenteVeiculo::operator < (const AcidenteVeiculo & other){
	if (this->numAcidentes == other.numAcidentes){
		return (this->numAcidentes > other.numAcidentes);	// Ordem decrescente de numero de acidentes
	}
	else{	// Em caso de empate de numero de acidentes, ordem decrescente de data
		return (this->dataUltimoAcidente > other.dataUltimoAcidente);
	}
}

bool AcidenteVeiculo::operator ==(const AcidenteVeiculo & other){
	return (this->marca == other.marca);	// Dois AcidenteVeiculo são iguais quando possuem a mesma marca
}
