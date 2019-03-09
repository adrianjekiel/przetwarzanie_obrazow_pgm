/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_SYGNALY_HPP_
#define PREWORK_SYGNALY_HPP_

#include <vector>
#include <string>

namespace prework
{


class Sygnaly
{
public:
    Sygnaly(const std::vector<std::string>& vecSygnaly);
    void zad1();
    void zad2();
    void zad3();
private:
    bool diff_less_then_ten(const std::string& sygnal);
    std::vector<std::string> vecSygnaly_;


};

}  // namespace prework

#endif  // PREWORK_SYGNALY_HPP_

