/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_OBRAZY_HPP_
#define PREWORK_OBRAZY_HPP_

#include <vector>
#include <string>

namespace prework
{

class Obrazy
{
public:
    Obrazy(const std::vector<std::vector<int>>& dane);
    void zad1();
    void zad2();
    void zad3();
    void zad4();
private:
    bool diff(const int x1, const int y1, const int x2, const int y2);
    std::vector<std::vector<int>> dane_;
};

}  // namespace prework

#endif  // PREWORK_OBRAZY_HPP_

