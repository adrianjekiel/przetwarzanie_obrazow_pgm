/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_FILE_MANAGER_HPP_
#define PREWORK_FILE_MANAGER_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Obraz.hpp"

namespace prework
{

class FileManager
{
public:
    Obraz loadData(const std::string& fileName);
    void wyswietl(const std::string& fileName);
    void saveData(const std::string& fileName, const Obraz& obraz_);
};


}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

