#ifndef PROTECAOCIVIL_H_
#define PROTECAOCIVIL_H_
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "Posto.h"
#include "Policia.h"
#include "Inem.h"
#include "Bombeiros.h"
#include "Acidente.h"
#include "AcidenteViacao.h"
#include "Incendio.h"
#include "IncendioDomestico.h"
#include "IncendioFlorestal.h"
#include "Assalto.h"
#include "Local.h"
#include "Erro.h"

/********** Bibliotecas para parte 2 do projeto ***********/
#include "Marca.h"
#include "AcidenteVeiculo.h"
#include "Condutor.h"
#include "Oficina.h"
#include <set>				// Red-Black Binary Search Tree
#include <unordered_set>	// Hash Table
#include <queue>			// Priority Queue ( MAX heap )
/**********************************************************/


/**************************   Hash table para Condutores   **************************/
struct CondutorHash {
	// Funcao de Dispersão (Using Bob Jenkins' "One-At-A-Time" Hash function for Strings)
	int operator() (const Condutor& condutor) const
	{
		unsigned int hash_result = 0;
		std::string nome = condutor.getNome();

		for (unsigned int i=0 ; i<nome.size() ; i++){
			hash_result += nome.at(i);
			hash_result += hash_result << 10;
			hash_result ^= hash_result >> 6;
		}

		hash_result += hash_result << 3;
		hash_result ^= hash_result >> 11;
		hash_result += hash_result << 15;

		return hash_result;
	}

	// Operador de igualdade
	bool operator() (const Condutor& condutor1, const Condutor& condutor2) const
	{
		return (condutor1.getNome() == condutor2.getNome());
	}
};

typedef std::unordered_set<Condutor, CondutorHash, CondutorHash> HashTableCondutores;
/************************************************************************************/


/**************************   Arvore Binária de Pesquisa para Registos de Acidentes com Veiculos de um certa Marca   **************************/
typedef std::set<AcidenteVeiculo> ArvoreBinariaAcidenteVeiculo;
/**********************************************************************************************************************************************/


/**************************   Filas de Prioridade para Oficinas de Reparação de Veículos   ****************************/
typedef std::priority_queue<Oficina> FilaPrioridadeOficinas;
/**********************************************************************************************************************/




/**
 * Proteção Civil que gere todos os acidentes e aciona os devidos meios de socorro
 */
class ProtecaoCivil {
private:
	std::vector<Posto*> postos;				/**< Vetor de apontadores para todos os posto da Proteção Civil 							*/
	std::vector<Acidente*> acidentes;		/**< Vetor de apontadores para todos os acidentes em decurso declarados à Proteção Civil 	*/
	std::vector<Local> locais;				/**< Vetor de todos os locais ao abrigo da proteção da Proteção Civil						*/
	const std::string ficheiroPostos;		/**< Ficheiro de onde é lida informação sobre todos os posto da Proteção Civil				*/
	const std::string ficheiroAcidentes;	/**< Ficheiro de onde é lida/escrita informações sobre todos os acidentes 					*/
	const std::string ficheiroLocais;		/**< Ficheiro de onde é lida informação sobre todos os locais ao abrigo da Proteção Civil	*/

	/****** Membros-Dados para a segunda parte do projeto ******/
	ArvoreBinariaAcidenteVeiculo veiculosAcidentesViacao;	/**< Árvore Binária de pesquisa que contem informação sobre todos os veículos envolvidos em Acidentes de Viação					*/
	FilaPrioridadeOficinas oficinas;						/**< Fila de Prioridade quem contém todas as oficinas responsáveis pela reparação de veículos envolvidos em Acidentes de Viação	*/
	HashTableCondutores condutoresAcidentesViacao;			/**< Tabela de Dispersão que contem todos os condutores identificados em Acidentes de Viacao									*/
	const std::string ficheiroOficinas;						/**< Ficheiro de onde é lida informação sobre oficinas de reparação de Veículos				*/
	const std::string ficheiroVeiculos;						/**< Ficheiro de onde é lida informação sobre veículos envolvidos em Acidentes de Viação	*/
	const std::string ficheiroCondutores;					/**< Ficheiro de onde é lida informação sobre condutores envolvidos em Acidentes de Viação	*/
	/***********************************************************/


	/**
	 * @brief Permite gravar toda a informação sobre veiculos, oficinas, condutores, postos e acidetes atuais nos respetivos ficheiros
	 */
	void gravar();

	/**
	 * @brief Permite obter o maior numero de identificação dos acidentes no vetor de acidentes
	 * @return Retorna o número de identificação do acidente com o maior número de identificação
	 */
	unsigned int findAcidenteMaiorNum() const;

	/**
	 * @brief Permite obter o valor absoluto da distância entre dois locais que se encontrem na base de dados da proteção civil
	 * @param nomeLocal1 - Nome do primeiro local
	 * @param nomeLocal2 - Nome do segundo local
	 * @return Retorna o valor da distância entre os locais com nome 'nomeLocal1' e 'nomeLocal2', ou -1 em caso de insucesso (se não encontrar algum dos locais
	 */
	double getDistLocais(const std::string &nomeLocal1, const std::string &nomeLocal2);

public:
	/**
	 * @brief Construtor da ckasse ProtecaoCivil
	 * @param ficheiroPostos - ficheiro de onde são lidos os posto
	 * @param ficheiroAcidentes - ficheiro de onde são lidos os acidentes
	 * @param ficheiroLocais - ficheiro de onde são lidos os locais
	 */
	ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais, const std::string &ficheiroOficinas, const std::string &ficheiroVeiculos, const std::string &ficheiroCondutores);

	/**
	 * @brief Destrutor da classe ProtecaoCivil
	 */
	~ProtecaoCivil();

	/**
	 * @brief Adiciona um acidente ao vetor de acidentes da Proteção Civil, lançando as exceções MeiosInsuficientes ou MeiosInexistentes caso necessário.
	 * @param acidente - Apontador para o acidente a dar entrada na Proteção Civil
	 */
	void addAcidente(Acidente* acidente);

	/**
	 * @brief Adiciona um acidente de viação ao vetor de acidentes da Proteção Civil
	 * @param acidenteViacao - Apontador para o acidente de viação a dar entrada na Proteção Civil
	 * @return Retorna 0 se a inserção tiver sucesso (todos as necessidades foram supridas) , 1 se apenas parte das necessidades forem supridas ou 2 caso não haja quaisquer meios para suprir as necessidades do acidente
	 */
	unsigned short addAcidenteViacao(AcidenteViacao* acidenteViacao);

	/**
	 * @brief Adiciona um assalto ao vetor de acidentes da Proteção Civil
	 * @param assalto - Apontador para o assalto a dar entrada na Proteção Civil
	 * @return Retorna 0 se a inserção tiver sucesso (todos as necessidades foram supridas) , 1 se apenas parte das necessidades forem supridas ou 2 caso não haja quaisquer meios para suprir as necessidades do acidente
	 */
	unsigned short addAssalto(Assalto* assalto);

	/**
	 * @brief Adiciona um incêndio ao vetor de acidentes da Proteção Civil
	 * @param incendio - Apontador para o incêndio a dar entrada na Proteção Civil
	 * @return Retorna 0 se a inserção tiver sucesso (todos as necessidades foram supridas) , 1 se apenas parte das necessidades forem supridas ou 2 caso não haja quaisquer meios para suprir as necessidades do acidente
	 */
	unsigned short addIncendio(Incendio* incendio);

	/**
	 * @brief Remove um acidente do vetor de acidentes da Proteção Civil
	 * @param numOcorrencia - Número de identificação da ocorrência (acidente) a remover.
	 * @return Retorna true se a remoção tiver sucesso e false caso contrário
	 */
	bool rmAcidente(unsigned int numOcorrencia);

	/**
	 * @brief Lê o conteúdo dos ficheiros de postos, acidentes e locais, colocando o seu conteúdo nos respetivos vetores de postos, acidentes e locais, lançando um exceção (Erro) caso a leitura de algum dos ficheiros falhe
	 */
	void openFiles();

	/**
	 * @brief Ordena os postos da proteção civil com um critério a definir na função passada como parâmetro
	 * @param compareFunction - Função de comparação entre dois postos, funciona como critério de ordenação
	 */
	void ordenarPostos(bool compareFunction(Posto* p1, Posto*p2));

	/**
	 * @brief Imprime no ecrã todos os postos da Proteção Civil
	 */
	void printTodosPostos() const;

	/**
	 * @brief Imprime no ecrã todos os postos da Proteção Civil do tipo especificado pelo parâmetro, assumindo o vetor de postos já ordenado por tipo
	 * @param tipo - Tipo de postos a imprimir pela função ("Policia", "Inem" ou "Bombeiros")
	 */
	void printPostosTipo(const std::string &tipo) const;

	/**
	 * @brief Imprime no ecrã todos os postos da Proteção Civil que estejam no local especificado pelo parâmetro, assumindo o vetor de postos já ordenado por local
	 * @param local - Local dos postos a imprimir pela função
	 */
	void printPostosLocal(const std::string &local) const;

	/**
	 * @brief Imprime no ecrã o posto da proteção civil com o id passado por parâmetro
	 * @param id - Número de identificação do posto a imprimir
	 */
	void printPostosId(unsigned int id) const;

	/**
	 * @brief Ordena os acidentes ao encargo da proteção civil com um critério a definir na função passada como parâmetro
	 * @param compareFunction - Função de comparação entre dois acidentes, funciona como critério de ordenação
	 */
	void ordenarAcidentes(bool compareFunction(Acidente* p1, Acidente*p2));

	/**
	 * @brief Imprime no ecrã todos os acidentes ao encargo da Proteção Civil
	 */
	void printTodosAcidentes() const;

	/**
	 * @brief Imprime no ecrã todos os acidentes ao encargo da Proteção Civil do tipo especificado pelo parâmetro, assumindo o vetor de acidentes já ordenado por tipo
	 * @param tipo - Tipo de acidentes a imprimir pela função ("Assalto", "Acidente de Viacao", "Incendio Domestico" ou "Incendio Florestal")
	 */
	void printAcidentesTipo(const std::string &tipo) const;

	/**
	 * @brief Imprime no ecrã todos os acidentes ao encargo da Proteção Civil que estejam no local especificado pelo parâmetro, assumindo o vetor de acidentes já ordenado por local
	 * @param local - Local dos acidentes a imprimir pela função
	 */
	void printAcidentesLocal(const std::string &local) const;

	/**
	 * @brief Imprime no ecrã todos os acidentes ao encargo da Proteção Civil que tenham ocorrida na data especificada pelo parâmetro, assumindo o vetor de acidentes já ordenado por data
	 * @param data - Data dos acidentes a imprimir pela função
	 */
	void printAcidentesData(const std::string &data) const;

	/**
	 * @brief Imprime no ecrã o acidente declarado à proteção civil com o id passado por parâmetro
	 * @param id - Número de identificação do acidente a imprimir
	 */
	void printAcidentesId(unsigned int id) const;

	/**
	 * @brief Imprime no ecrã as atribuições do acidente declarado à proteção civil com o id passado por parâmetro
	 * @param id - Número de identificação do acidente a imprimir atribuições
	 */
	void printAtribuicoesAcidente(unsigned int id) const;

	/**
	 * @brief Encontra o índice de um certo local no vetor de locais da proteção civil
	 * @param nomeLocal - Nome do Local a procurar no vetor de locais
	 * @return Retorna o índice do local com nome 'nomeLocal' no vetor de locais caso este lá esteja, ou -1 caso contrário
	 */
	int findLocal(const std::string &nomeLocal) const;

	/**
	 * @brief Ordena os Postos por distância (ordem crescente) a um outro local
	 * @param nomeLocal - Nome do local que serve de referência para a ordenação do vetor
	 */
	void ordenarPostosDistLocal(const std::string &nomeLocal);

	/**
	 * @brief Procura um local no vetor de locais
	 * @param nomeLocal - Nome do local a procurar
	 * @return Retorna o apontador para o local a procurar ou NULL caso não encontre
	 */
	const Local * getLocal(const std::string &nomeLocal) const;

	/**
	 * @brief Permite obter o numero de ocorrência da ocorrência com maior número
	 * @return Retorna o número da ocorrência com maior número de ocorrência
	 */
	unsigned int getMaxNumOcorrencia() const;

	/**
	 * @brief Retorna os meios de uma atribuicao de volta ao seu posto
	 * @param atribuicao - Atribuicao em questão
	 */
	void retornarAtribuicao(const Atribuicao & atribuicao);



	/*****************************************************************************************************************/
	/***************************************        2a Parte do Projeto        ***************************************/
	/*****************************************************************************************************************/

	/**
	 * @brief Imprime no ecrã todas as oficinas existentes
	 */
	void printTodasOficinas() const;

	/**
	 * @brief Imprime no ecrã todos os condutores envolvidos em acidentes de viação
	 */
	void printTodosCondutores() const;

	/**
	 * @brief Imprime no ecrã informação sobre todas as marcas de veículos envolvidos em acidentes de viação
	 */
	void printTodosVeiculos() const;

	/**
	 * @brief Imprime no ecrã a informação relativa à oficina passada por parâmetro
	 * @param idOficina - Número de Identificação da Oficina a imprimir
	 */
	void printOficina(unsigned int idOficina) const;

	/**
	 * @brief Imprime no ecrã a informação relativa ao condutor por parâmetro
	 * @param nomeCondutor - Nome do Condutor a imprimir
	 */
	void printCondutor(const std::string & nomeCondutor) const;

	/**
	 * @brief Imprime no ecrã a informação relativa à marca do veículo passado por parâmetro
	 * @param nomeMarca - Nome da marca de veículos a imprimir
	 */
	void printVeiculo(const std::string & nomeMarca) const;

	/**
	 * @brief Imprime no ecrã a oficina com maior disponibilidade (topo da fila de prioridade)
	 */
	void printOficinaMaisDisponivel() const;

	/**
	 * @brief Imprime no ecrã a marca de veiculos envolvida no maior numero de acidentes (primeiro elemento)
	 */
	void printMarcaMaisAcidentes() const;

	/**
	 * @brief Adiciona um condutor à tabela de dispersão de condutor , ou atualiza a info. do condutor se esta já existir
	 * @param nomeCondutor - Nome do Condutor
	 * @param dataAcidente - Data em que ocorreu o acidente
	 */
	void addCondutor(const std::string & nomeCondutor , const Date & dataAcidente);

	/**
	 * @brief Adiciona uma marca de veículos à árvore binária de acidenteVeiculos , ou atualiza a info. da marca de veículos se esta já existir
	 * @param nomeMarcaVeiculo - Nome da Marca de Veículos
	 * @param dataAcidente - Data em que ocorreu o acidente
	 */
	void addVeiculo(const std::string & nomeMarcaVeiculo , const Date & dataAcidente);

	/**
	 * @brief Imprime no ecrã info de todos os condutores envolvidos em acidentes de viação entre as datas data1 e data2
	 * @param data1 - valor minimo a partir do qual são impressos condutores
	 * @param data2 - valor máximo até ao qual são impressos condutores
	 */
	void printCondutoresEntreDatas(const Date & data1 , const Date & data2) const;

	/**
	 * @brief Imprime no ecrã info de todas as marcas de veículos envolvidas em acidentes de viação entre as datas data1 e data2
	 * @param data1 - valor minimo a partir do qual são impressas marcas de veículos
	 * @param data2 - valor máximo até ao qual são impressas marcas de veículos
	 */
	void printVeiculosEntreDatas(const Date & data1 , const Date & data2) const;

	/**
	 * @brief Permite obter o numero de identificação da oficina com maior número
	 * @return Retorna o número de identificação da oficina com maior número de identificação
	 */
	unsigned int getMaxIdOficinas() const;

	/**
	 * @brief Adiciona uma oficina à fila de prioridade de oficinas
	 * @param oficina - Oficina a adiocionar
	 */
	void addOficina(const Oficina & oficina);
};

#endif /* PROTECAOCIVIL_H_ */
