#ifndef ACIDENTEVEICULO_H_
#define ACIDENTEVEICULO_H_

#include <iostream>
#include <string>
#include "Marca.h"
#include "Date.h"

/**
 * Classe AcidenteVeiculo utilizada para representar um registos de acidentes associados a uma Marca de Veículos.
 */
class AcidenteVeiculo {
private:
	const Marca marca;				/**< Marca dos Veículos. */
	unsigned int numAcidentes;		/**< Número de Acidentes com Veículos desta Marca. */
	Date dataUltimoAcidente;		/**< Data do último acidente em que um Veículo desta Marca esteve envolvildo. */
public:
	/**
	 * @brief Construtor da classe AcidenteVeiculo.
	 * @param nomeMarca - Marca dos Veículos.
	 * @param numAcidentes - Número de Acidentes com Veículos desta Marca.
	 * @param dataUltimoAcidente - Data do último acidente em que um Veículo desta Marca esteve envolvildo.
	 */
	AcidenteVeiculo(const std::string & nomeMarca , unsigned int numAcidentes , const Date & dataUltimoAcidente);

	/**
	 * @brief Destrutor da classe AcidenteVeiculo.
	 */
	~AcidenteVeiculo();

	/**
	 * @brief Permite obter a Marca dos Veículos.
	 * @return Retorna a Marca dos Veículos.
	 */
	Marca getMarca() const;

	/**
	 * @brief Permite obter o número de Acidentes com Veículos desta Marca.
	 * @return Retorna o número de Acidentes com Veículos desta Marca.
	 */
	unsigned int getNumAcidentes() const;

	/**
	 * @brief Permite obter a data do último acidente em que um Veículo desta Marca esteve envolvildo.
	 * @return Retorna a data do último acidente em que um Veículo desta Marca esteve envolvildo.
	 */
	Date getDataUltimoAcidente() const;									

	/**
	 * @brief Permite alterar o valor do número de Acidentes com Veículos desta Marca.
	 * @param novoNumAcidentes - novo valor do número de Acidentes com Veículos desta Marca.
	 */
	void setNumAcidentes(unsigned int novoNumAcidentes);

	/**
	 * @brief Permite alterar a data do último acidente em que um Veículo desta Marca esteve envolvildo.
	 * @param novaDataUltimoAcidente - nova data do último acidente em que um Veículo desta Marca esteve envolvildo.
	 */
	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);

	/**
	 * @brief Imprime numa stream o conteudo simplificado do AcidenteVeiculo.
	 * @param os - Stream para a qual o AcidenteVeiculo é impresso.
	 */
	void printSimplifiedInfo(std::ostream & os) const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre o AcidenteVeiculo.
	 */
	void printCompleteInfo() const;

	/**
	 * @brief Operador < para comparar AcidenteVeiculos.
	 * @param other - um outro AcidenteVeiculo para comparar ao AcidenteVeiculos em questão.
	 * @return Retorna true caso o AcidenteVeiculo tenha numAcidentes superior ao AcidenteVeiculo 'other', false caso contrário. Em caso de empate de numero de acidentes, ordem decrescente de data.
	 */
	bool operator < (const AcidenteVeiculo & other) const;

	/**
	 * @brief Operador de igualdade para comparar AcidenteVeiculos.
	 * @param other - um outro AcidenteVeiculo para comparar ao AcidenteVeiculos em questão.
	 * @return Retorna true se as marcas forem iguais, false caso contrário.
	 */
	bool operator ==(const AcidenteVeiculo & other) const;
};


#endif /* ACIDENTEVEICULO_H_ */
