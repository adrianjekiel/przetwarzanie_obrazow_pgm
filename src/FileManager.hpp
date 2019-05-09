/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_FILE_MANAGER_HPP_
#define PREWORK_FILE_MANAGER_HPP_

#include <vector>
#include <string>

namespace prework
{

class FileManager
{
public:
    std::vector<std::string> loadData(const std::string& fileName);
    void saveData(const std::string& numer_zadania, const std::vector<std::string>& vec);
};

}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

