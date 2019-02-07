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

// forward declaration of DummyData,
// thanks that we don't need to include here DummyData.hpp
// just include it in cpp file only,
// this increase speed time of compilation and represent good style of coding
class DummyData;

class FileManager
{
public:
    std::vector<DummyData> loadData(const std::string& fileName);
    bool saveData(const std::string& fileName, const std::vector<DummyData>& data);
};

}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

