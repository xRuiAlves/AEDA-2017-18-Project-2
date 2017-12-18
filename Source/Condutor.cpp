#include "Condutor.h"

Condutor::Condutor(const std::string & nome , const Date & dataUltimoAcidente) :
	nome(nome) ,
	dataUltimoAcidente(dataUltimoAcidente) {}

Condutor::~Condutor() {}



std::string Condutor::getNome() const{
	return nome;
}

Date Condutor::getDataUltimoAcidente() const{
	return dataUltimoAcidente;
}



void Condutor::setDataUltimoAcidente(const Date & novaDataUltimoAcidente){
	dataUltimoAcidente = novaDataUltimoAcidente;
}
