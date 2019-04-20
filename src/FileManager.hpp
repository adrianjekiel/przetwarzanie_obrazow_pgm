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

class slowo_klucz
{
  public:
  int klucz;
  std::string slowo;
};

class slowo_szyfrogram
{
  public:
  std::string slowo;
  std::string szyfrogram;
};

class DummyData;

class FileManager
{
public:
    std::vector<std::string> loadData(const std::string& fileName);
    std::vector<slowo_klucz> loadData2(const std::string& fileName);
    std::vector<slowo_szyfrogram> loadData3(const std::string& fileName);
    void saveData(const std::string &numer_zadania, const std::vector<std::string>& vec);


};

}  // namespace prework

#endif  // PREWORK_FILE_MANAGER_HPP_

