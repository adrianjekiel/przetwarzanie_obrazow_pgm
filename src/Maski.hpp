/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_MASKI_HPP_
#define PREWORK_MASKI_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Obraz.hpp>


namespace prework
{

class Maski
{
public:
    Maski();
    std::vector<int> get_mask(std::string mask_name);
private:
    std::map<std::string, std::vector<int>> maski_;
};



}  // namespace prework

#endif  // PREWORK_MASKI_HPP_
