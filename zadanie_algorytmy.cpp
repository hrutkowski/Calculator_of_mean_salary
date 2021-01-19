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

    result.emplace_back("Jan Niezbędny", 20000, true); 
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
    float result, sum, number;

    sum = std::accumulate(collection.begin(), collection.end(), 0,                              
    [](const auto& arg1, const auto& arg2){return arg1 + arg2.salary();} );

    number = collection.size();

    result = sum / number;

    return result;
}



template<typename CollectionType>
auto calculateMaleMean(CollectionType collection)
{
    float result_mean;

    std::sort(collection.begin(), collection.end(), 
        [](auto& lhs, auto& rhs) { return lhs.isMale() < rhs.isMale();}); 

    auto it = std::find_if(collection.begin(), collection.end(),    
        [](auto& arg) {return arg.isMale();}); 

    collection.erase(collection.begin(), it);

    result_mean = calculateMean(collection);
    
    return result_mean;
}

template<typename CollectionType>
auto calculateFemaleMean(CollectionType collection)
{
    float result_mean;

    std::sort(collection.begin(), collection.end(), 
        [](auto& lhs, auto& rhs) { return lhs.isMale() < rhs.isMale();}); 

    auto it = std::find_if(collection.begin(), collection.end(),    
        [](auto& arg) {return arg.isMale();}); 

    collection.erase(it, collection.end());

    result_mean = calculateMean(collection);
    
    return result_mean;
}

int main()
{
    std::cout << "PROE lab14 - zadanie oceniane 3 \n";

    auto employees = getEmployees();
    
    std::cout << "Średnia zarobków wszystkich pracowników wynosi : " << calculateMean(employees) << "\n";
    std::cout << "Średnia zarobków mężczyzn wynosi : " << calculateMaleMean(employees) << "\n";
    std::cout << "Średnia zarobków kobiet wynosi : " << calculateFemaleMean(employees) << "\n";

    return 0;
}
