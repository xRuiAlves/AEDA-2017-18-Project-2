#ifndef MARCA_H_
#define MARCA_H_

#include <string>


class Marca {
private:
	std::string nomeMarca;
public:
	Marca(const std::string & nomeMarca);
	~Marca();

	std::string getNomeMarca() const;
	bool operator==(const Marca &otherMarca) const;
	bool operator!=(const Marca &otherMarca) const;
};


#endif /* MARCA_H_ */
