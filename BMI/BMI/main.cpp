//
//  main.cpp
//  BMI
//
//  Created by Sergio Enrico Coppolecchia on 27/02/23.
//

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

//********** MACROS ************************************************************ //

#define INPUT_FILE "/Users/enrico/Documents/Cpp20BookCode/BMI/BMI/input.txt"

//********** FUNCTIONS ********************************************************* //

void clear_buffer(std::istream& data_source);

void input_data(std::istream& data_source,
                std::ostream& log_stream,
                std::vector<std::string> names,
                std::vector<int> heights,
                std::vector<int> weights,
                std::vector<char> sexes,
                std::vector<double> bmis,
                double threshold);

double avg_bmi(std::ostream& log_stream,
               std::vector<double> bmis,
               std::vector<char> sexes,
               char sex);

int median_bmi(std::vector<double> bmis,
               std::vector<char> sexes,
               double avg,
               char sex);

void print_tables();


//********** MAIN ************************************************************** //

int main() {
    std::ifstream input{INPUT_FILE};
    double threshold{};
    std::cout << "This program computes Bogus Metabolic Indicator (BMI) values.\n"
    "Enter threshold BMI: ";
    input >> threshold;
    std::cout << threshold << '\n';
    if(threshold < 0 or threshold > 70 ) {
        std::cout << "The threshold must be in [0,70] interval.\n";
        return 1;
    }
    
    std::vector<std::string> names{};
    std::vector<int> heights{}, weights{};
    std::vector<char> sexes{};
    std::vector<double> bmis{};
    
    input_data(input, std::cout,names, heights, weights, sexes, bmis, threshold);

    return 0;
}


// *********** IMPLEMENTATIONS ************************************************* //

double avg_bmi(std::ostream& log_stream,
               std::vector<double> bmis,
               std::vector<char> sexes,
               char sex)
{
    if (bmis.size() != sexes.size())
    {
        log_stream << "BMI and SEX size mismatch!\n";
        exit(2);
    }
    int count{};
    double sum{};
    for (int i=0; i < bmis.size(); ++i)
    {
        if (sexes[i] == sex)
        {
            sum += bmis[i];
            count++;
        }
    }
    return sum/count;
}

int median_bmi(std::vector<double> bmis,
               std::vector<char> sexes,
               char sex)
{
    std::vector<double> filtered_values{};
    for (int i=0; i < bmis.size(); ++i)
    {
        if (sexes[i] == sex)
        {
            filtered_values.push_back(bmis[i]);
        }
    }
    std::sort(filtered_values.begin(), filtered_values.end());
    if (filtered_values.size() == 0)
        return 0;
    if (filtered_values.size() == 1)
        return filtered_values[0];
    if (filtered_values.size()%2 != 0)
        return filtered_values[(filtered_values.size()/2)+1];
    else
        return (filtered_values[(filtered_values.size()/2)+1] +
                filtered_values[(filtered_values.size()/2)]) / 2;
}

void skip_line(std::istream& data_source)
{
    data_source.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void input_data(std::istream& data_source,
                std::ostream& log_stream,
                std::vector<std::string> names,
                std::vector<int> heights,
                std::vector<int> weights,
                std::vector<char> sexes,
                std::vector<double> bmis,
                double threshold)
{
    log_stream << "Enter name, height (in cm), and weight (in kg) for each person:\n";
    while(true)
    {
        std::string name;
        log_stream << "name " << names.size()+1 << ": ";
        skip_line(data_source);
        if (not std::getline(data_source, name))
            return ;
        log_stream << name << '\n';
        names.push_back(name);
        
        int height{0};
        log_stream << "Height (cm): ";
        if ((not (data_source >> height)) or
            height < 10 or height > 250)
        {
            names.pop_back();
            log_stream << "Height value not valid.\n";
            return;
        }
        skip_line(data_source);
        log_stream << height << '\n';
        heights.push_back(height);
        
        int weight{0};
        log_stream << "Weight (kg): ";
        if ((not (data_source >> weight)) or
            weight < 0 or weight > 300)
        {
            names.pop_back();
            heights.pop_back();
            log_stream << "Weight value not valid.\n";
            return;
        }
        skip_line(data_source);
        log_stream << weight << '\n';
        weights.push_back(weight);
        
        char sex{'?'};
        log_stream << "Sex (m or f): ";
        if ((not (data_source >> sex)) or
            (sex != 'm' and sex != 'M' and sex != 'f' and sex != 'F'))
        {
            names.pop_back();
            heights.pop_back();
            weights.pop_back();
            log_stream << "Sex value not valid.\n";
            return;
        }
        log_stream << (char)std::toupper(sex) << '\n';
        sexes.push_back(std::toupper(sex));
        double height_cm = ((double)height)/100;
        double bmi = (double)weight/(height_cm*height_cm);
        log_stream << "BMI = " << bmi << "\n";
        bmis.push_back(bmi);
    }
}
