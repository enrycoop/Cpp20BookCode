#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <string>
#include <iomanip> //doveva essere format ma su debian non c'è ancora in questo gcc
/*
 * Parse digit char in input into int values
 */
void character_type(){
    using namespace std;

    int value{};
    bool have_value{false};
    char ch{};
    while (cin.get(ch))
    {
        if (ch >= '0' and ch <= '9') //se il carattere è un digit
        {
            value = ch - '0'; // estraggo il numero
            have_value = true;
            while (cin.get(ch) and ch >= '0' and ch <= '9') //estraggo anche gli altri decimali
                value = value * 10 + ch - '0';
        }

        if (ch == '\n') //se è una mandata a capo finisce il decimale
        {
            if (have_value)
            {
                cout << value << '\n';
                have_value = false;
            }
        }
        else if (ch != ' ' and ch != '\t')
        {
            cout << '\a';
            have_value = false;
            while (cin.get(ch) and ch != '\n')
                /*empty */;
        }
    }
}


void coordinates(){
    using intvec = std::vector<int>;

    intvec xs{}, ys{};

    char sep{};
    /*
     * Cicla finchè l'input stream ha un intero (x), un carattere (sep),
     * e un'altro intero (y); quindi testa che il separatore sia una virgola.
     */
    for (int x{}, y{}; std::cin >> x >> sep and sep == ',' and std::cin >>y;)
    {
        xs.emplace_back(x);
        ys.emplace_back(y);
    }

    for (auto x{xs.begin()}, y{ys.begin()}; x != xs.end(); ++x, ++y)
    {
        std::cout << *x << ',' << *y << '\n';
    }
}

void extract_from_string(){
    using count_map = std::map<std::string, int>;
    using str_size  = std::string::size_type;

    count_map counts{};
    std::string word{};

    /*
     * I caratteri che sono considerati ok per l'uso di queste parole
     * Splitto una stringa lung ain più parti e il compilatore le joina.
     */
    std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"
                     "0123456789-_"};
    /*
     * Legge parole dallo standard input e conta il numero di volte
     * in cui ogni parola occorre.
     */
    std::string input{"/Users/enrico/Documents/Cpp20BookCode/17.1_char_exploration/17.1_char_exploration/file.txt"};
    std::ifstream in{input};
    if (not in)
    {
        std::cerr << input << ": " << std::generic_category().message(errno) << '\n';
        return;
    }
    while (in >> word)
    {
        /*
         * Faccio una copia solo dei carattteri che appaiono okay.
         */
        std::string copy{};
        for (char ch : word)
        {
            if (okay.find(ch) != std::string::npos)
            {
                copy.push_back(ch);
            }
        }
        /*
         * La parola deve essere tutta punteggiatura per essere vuota.
         * non contiamo stringhe vuote
         */
        if (not copy.empty())
        {
            ++counts[copy];
        }
    }

    // determino la parola più lunga
    str_size longest{0};
    for (auto pair : counts)
    {
        if (pair.first.size() > longest)
        {
            longest = pair.first.size();
        }
    }
    // Per ofni pèarola/conto coppia
    constexpr int count_size{10}; //numero di posti per stampare la count
    for (auto pair : counts)
    {
        // stampo la parola, conto, nuovalinea. mantengo le colonne alllineate
        std::cout << std::setw(longest) << pair.first
                  << std::setw(count_size) << pair.second;
    }
}

int main() {

    //character_type();
    //coordinates();
    extract_from_string();

}


































