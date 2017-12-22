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

void AcidenteVeiculo::printCompleteInfo() const{
	std::cout << "***  " << marca.getNomeMarca() << "  ***" << std::endl;
	std::cout << "Numero de Acidentes: " << numAcidentes << std::endl;
	std::cout << "Data do Ultimo Acidente: " << dataUltimoAcidente.getData() << std::endl;
}



bool AcidenteVeiculo::operator < (const AcidenteVeiculo & other) const{
	// Veiculos com marcas diferentes sao diferentes, mesmo que tenham numero de acidentes e datas com valores iguais!!!
	if ((this->numAcidentes == other.numAcidentes) && (this->dataUltimoAcidente == other.dataUltimoAcidente) && (this->marca != other.marca))
		return true;

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
