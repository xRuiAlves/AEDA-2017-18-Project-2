#ifndef OFICINA_H_
#define OFICINA_H_

#include <vector>
#include <iostream>
#include "Marca.h"


/**
 * Classe Oficina utilizada para representar um Oficina de reparação de Veículos.
 */
class Oficina {
private:
	unsigned int id;							/**< Numero de Identificação da Oficina. */
	unsigned int disponibilidade;				/**< Disponibilidade da Oficina (numero de dias até a Oficina estar disponível). */
	std::vector<Marca> marcasRepresentadas;		/**< Conjunto de Marcas de Veículos às quais a Oficina realiza reparações. */
public:
	/**
	 * @brief Construtor da classe Oficina.
	 * @param id - Numero de Identificação da Oficina.
	 * @param disponibilidade - Disponibilidade da Oficina (numero de dias até a Oficina estar disponível).
	 * @param marcasRepresentadas - Vetor de Marcas de Veículos às quais a Oficina realiza reparações.
	 */
	Oficina(unsigned int id , unsigned int disponibilidade , const std::vector<Marca> & marcasRepresentadas);

	/**
	 * @brief Destrutor da classe Oficina.
	 */
	~Oficina();

	/**
	 * @brief Permite obter o número de identificação da Oficina.
	 * @return Retorna o número de identificação da Oficina.
	 */
	unsigned int getID() const;

	/**
	 * @brief Permite obter a disponibilidade da Oficina (numero de dias até a Oficina estar disponível).
	 * @return Retorna a disponibilidade da Oficina.
	 */
	unsigned int getDisponibilidade() const;

	/**
	 * @brief Permite obter o vetor de Marcas representadas pela Oficina.
	 * @return Retorna o vetor de Marcas representadas pela Oficina.
	 */
	std::vector<Marca> getMarcasRepresentadas() const;

	/**
	 * @brief Incrementa a disponibilidade da oficina (Adicionar um veículo -> mais um dia até a Oficina estar disponível)
	 */
	void adicionarVeiculo();

	/**
	 * @brief Imprime numa stream o conteudo simplificado da Oficina.
	 * @param os - Stream para a qual a Oficina é impressa.
	 */
	void printSimplifiedInfo(std::ostream & os) const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre a Oficina.
	 */
	void printCompleteInfo() const;

	/**
	 * @brief Verifica se a Oficina representa a marca passada por parâmetro.
	 * @param nomeMarca - Marca para a qual é feita a verificação.
	 * @return Retorna true se a Oficina representar a marca em questão, false caso contrário.
	 */
	bool representaMarca(const std::string & nomeMarca) const;

	/**
	 * @brief Operador < para comparar Oficinas.
	 * @param other - uma outra Oficina para comparar à Oficina em questão.
	 * @return Retorna true caso a Oficina tenha disponibilidade superior à Oficina 'other', false caso contrário.
	 */
	bool operator<(const Oficina & other) const;
};


#endif /* OFICINA_H_ */
