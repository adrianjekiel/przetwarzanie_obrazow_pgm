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
    std::vector<std::vector<int>> loadData(const std::string& fileName);
};

}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

