#ifndef CONDUTOR_H_
#define CONDUTOR_H_

#include <iostream>
#include <string>
#include "Date.h"

/**
 * Classe Condutor utilizada para representar um Condutor.
 */
class Condutor {
private:
	const std::string nome;		/**< Nome do Condutor. */
	Date dataUltimoAcidente;	/**< Data do último acidente em que o Condutor este envolvido. */
public:
	/**
	 * @brief Construtor da classe Condutor.
	 * @param nome - Nome do Condutor.
	 * @param dataUltimoAcidente - Data do último acidente em que o Condutor este envolvido.
	 */
	Condutor(const std::string & nome , const Date & dataUltimoAcidente);

	/**
	 * @brief Destrutor da classe Condutor.
	 */
	~Condutor();

	/**
	 * @brief Permite obter o nome do Condutor.
	 * @return Retorna o nome do Condutor.
	 */
	std::string getNome() const;

	/**
	 * @brief Permite obter a data do último acidente em que o Condutor este envolvido.
	 * @return Retorna a data do último acidente em que o Condutor este envolvido.
	 */
	Date getDataUltimoAcidente() const;									

	/**
	 * @brief Permite alterar a data do último acidente em que o Condutor este envolvido.
	 * @param novaDataUltimoAcidente - nova data do último acidente em que o Condutor este envolvido.
	 */
	void setDataUltimoAcidente(const Date & novaDataUltimoAcidente);	

	/**
	 * @brief Imprime numa stream o conteudo simplificado do Condutor.
	 * @param os - Stream para a qual o Condutor é impresso.
	 */
	void printSimplifiedInfo(std::ostream & os) const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre o Condutor.
	 */
	void printCompleteInfo() const;
};


#endif /* CONDUTOR_H_ */
