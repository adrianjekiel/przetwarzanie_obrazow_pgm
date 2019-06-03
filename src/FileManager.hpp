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
    void wyswietl(const Obraz& obraz);
    void saveData(const Obraz& obraz);
};


}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

