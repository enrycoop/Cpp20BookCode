//============================================================================
// Name        : map_data_structure.cpp
// Author      : Enrycoop
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <system_error>
#include <vector>


int main() {
    std::string input{"/Users/enrico/Documents/Cpp20BookCode/15.1_map_data_Structure/15.1_map_data_Structure/words.txt"};
    std::string word{};
    std::map<std::string, int> counts{};
    std::ifstream in{input};
    if (not in)
        std::cerr << input << ": " << std::generic_category().message(errno) << '\n';
    else
    {
        /*
         * Prendo in input i dati dal file e li copio dentro map incrementando il valore corrispondente
         * alla word. Prima di inserire la word nella map la ripulisco da caratteri di punteggiatura.
         */
        while (in >> word)
        {
            std::replace(word.begin(),word.end(),'.',' ');
            std::replace(word.begin(),word.end(),',',' ');
            std::replace(word.begin(),word.end(),':',' ');
            ++counts[word];
        }


        // Stampo gli elementi della map accedendo a first (key) e second (value)
        for (auto element : counts)
            std::cout << element.second << '\t' << element.first << '\n';
        /*
         * Strovo l'elemento dentro map
         */

        auto the = counts.find("the");
        if (the == counts.end())
            std::cout << "\"the\": not found\n";
        else if (the->second == 1)
            std::cout << "\"end\": occurs " << the->second << " time\n";
        else
            std::cout << "\"end\": occurs " << the->second << " times\n";
    }

    return 0;
}
