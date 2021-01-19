#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Employee
{
public:
    Employee(std::string name, float salary, bool isMale)
    : name_(name), salary_(salary), isMale_(isMale) {}

    Employee() = default;

    auto name() const { return name_;}
    auto salary() const {return salary_;}
    auto isMale() const {return isMale_;}

private:
    std::string name_;
    float salary_;
    bool isMale_;
};

auto getEmployees()
{
    auto result = std::vector<Employee>();

    result.emplace_back("Jan Niezbędny", 20000, true); //2000
    result.emplace_back("Fryderyk Niekonieczny", 3200, true);
    result.emplace_back("Zofia Przydatna", 8400, false);
    result.emplace_back("Anna Pracowita", 12500, false);
    result.emplace_back("Krzysztof Leń", 1500, true);
    result.emplace_back("Zygmunt Koleżeński", 6100, true);
    result.emplace_back("Renata Solidna", 11600, false);

    return result;
}

template<typename CollectionType>
auto calculateMean(CollectionType collection)
{
    int result, sum, number;

    sum = std::accumulate(collection.begin(), collection.end(), 0,                              
    [](const auto& arg1, const auto& arg2){return arg1 + arg2.salary();} );

    number = collection.size();

    result = sum / number;

    return result;
}


int main()
{
    std::cout << "PROE lab14 - zadanie oceniane 3 \n";

    auto employees = getEmployees();

    std::cout << "Średnia zarobków wszystkich pracowników wynosi : " << calculateMean(employees) << "\n";
    // std::cout << "Średnia zarobków mężczyzn wynosi : " << calculateMaleMean(employees) << "\n";
    // std::cout << "Średnia zarobków kobiet wynosi : " << calculateFemaleMean(employees) << "\n";


    return 0;
}
