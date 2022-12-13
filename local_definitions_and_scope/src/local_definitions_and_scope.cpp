#include <cassert>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
	std::vector<int> data{};
	data.insert(data.begin(), std::istream_iterator<int>(std::cin),
				std::istream_iterator<int>());
	/*
	 * Modo stupido per ordinare un vettore. Assume che la porzione iniziale
	 * del vettore è già stata ordinata fino all'iteratore iter.
	 * Trova dove *iter appartiene nella porzione già ordinata del vettore.
	 * Cancella *iter dal vettore e lo reinserisce nella sua posizione
	 * ordinata. Usa la ricerca binaria (binary-search) per velocizzare la
	 * ricerca della posizione corretta.
	 * Invariante: gli elementi nel range [begin(), iter] sono gia ordinati.
	 */
	for (auto iter{data.begin()}, end{data.end()}; iter != end; /*empty*/ )
	{
		/*
		 * Trova dove *iter appartiene chiamando l'algoritmo standard
		 * lower_bound, il quale esegue una ricerca binaria e restituisce
		 * un iteratore (se non trova l'elemento) che punta alla posizione
		 * in cui dovrebbe essere l'elemento.
		 */
		int value{*iter};
		auto here{std::lower_bound(data.begin(), iter, value)};
		if (iter == here)
			++iter; // vuol dire che è già nella posizione ordinata.
		else
		{
			iter = data.erase(iter);
			// reinserisci il valore nella posizione corretta.
			data.insert(here, value);
		}
	}

	/*
	 * Debugging Code: controlla che il vettore è attualmente ordinato.
	 * Fa questo confrontanto ogni elemento con il suo predecessore.
	 */
	for (auto iter{data.begin()}, prev{data.end()}, end{data.end()};
		iter != end;
		++iter)
	{
		if (prev != data.end())
			assert(not (*iter < *prev));
		prev = iter;
	}

	/*
	 * Stampa il vettore ordinato in una riga. Comincia con "{" e finisce
	 * con "}". Separa gli elementi con virgole. Un vettore vuoto viene
	 * stampato con "{ }".
	 */
	std::cout << '{';
	std::string separator{" "};
	for (int element : data)
	{
		std::cout << separator << element;
		separator = ", ";
	}
	std::cout << " }\n";
}
