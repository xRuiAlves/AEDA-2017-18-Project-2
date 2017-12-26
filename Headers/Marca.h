#ifndef MARCA_H_
#define MARCA_H_

#include <string>

/**
 * Classe Marca utilizada para representar a Marca de um Veículo.
 */
class Marca {
private:
	std::string nomeMarca;	/**< Nome da Marca. */
public:
	/**
	 * @brief Construtor da classe Marca.
	 * @param nomeMarca - Nome da Marca.
	 */
	Marca(const std::string & nomeMarca);

	/**
	 * @brief Destrutor da classe Marca.
	 */
	~Marca();

	/**
	 * @brief Permite obter o nome da Marca.
	 * @return Retorna o nome da Marca.
	 */
	std::string getNomeMarca() const;

	/**
	 * @brief Operador de igualdade para comparar Marcas.
	 * @param otherMarca - A marca à qual comparar a Marca em questão.
	 * @return Retorna true se as marcas tiverem o mesmo nome, falso caso contrário.
	 */
	bool operator==(const Marca &otherMarca) const;

	/**
	 * @brief Operador de diferença para comparar Marcas.
	 * @param otherMarca - A marca à qual comparar a Marca em questão.
	 * @return Retorna true se as marcas tiverem nomes diferentes, falso caso contrário.
	 */
	bool operator!=(const Marca &otherMarca) const;
};


#endif /* MARCA_H_ */
