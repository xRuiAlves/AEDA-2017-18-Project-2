#include "AcidenteVeiculo.h"

AcidenteVeiculo::AcidenteVeiculo(const std::string & nomeMarca , unsigned int numAcidentes , const Date & dataUltimoAcidente) :
	marca(Marca(nomeMarca)) ,
	numAcidentes(numAcidentes) ,
	dataUltimoAcidente(dataUltimoAcidente) {}

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

void AcidenteVeiculo::printSimplifiedInfo(std::ostream & os) const{
	os << marca.getNomeMarca() << '/' << numAcidentes << '/' << dataUltimoAcidente.getData();
}



bool AcidenteVeiculo::operator < (const AcidenteVeiculo & other) const{
	if (this->numAcidentes == other.numAcidentes){
		return (this->dataUltimoAcidente > other.dataUltimoAcidente);	// Ordem decrescente de numero de acidentes
	}
	else{	// Em caso de empate de numero de acidentes, ordem decrescente de data
		return (this->numAcidentes > other.numAcidentes);
	}
}

bool AcidenteVeiculo::operator ==(const AcidenteVeiculo & other) const{
	return (this->marca == other.marca);	// Dois AcidenteVeiculo são iguais quando possuem a mesma marca
}
