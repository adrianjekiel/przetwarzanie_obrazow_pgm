/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_LICZBY_HPP_
#define PREWORK_LICZBY_HPP_

#include <vector>
#include <string>

namespace prework
{


class Liczby
{
public:
    Liczby(const std::vector<int>& vecLiczby);
    void zad1();
    void zad2();
private:
    int silnia(int);
    int oblicz_sume(int);
    std::vector<string> convertToString();
    std::vector<int> vecLiczby_;


};

}  // namespace prework

#endif  // PREWORK_SYGNALY_HPP_
