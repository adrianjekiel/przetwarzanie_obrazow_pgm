/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "Maski.hpp"
#include <math.h>
#include <map>

namespace prework
{
Maski::Maski()
{
  maski_.emplace("maska_usredniajaca",std::vector<int> {1,1,1,1,1,1,1,1,1});
  maski_.emplace("maska_usredniajaca_ze_wzmocnieniem",std::vector<int> {1,1,1,1,2,1,1,1,1});
  maski_.emplace("gradient_Robertsa",std::vector<int> {0,0,0,-1,0,0,0,1,0});
  maski_.emplace("maska_Prewitta",std::vector<int> {-1,-1,-1,0,0,0,1,1,1});
  maski_.emplace("maska_Sobela",std::vector<int> {-1,-2,-1,0,0,0,1,2,1});
  maski_.emplace("maska_wykrywajaca_narozniki",std::vector<int> {1,1,1,-1,-2,1,-1,-1,1});
  maski_.emplace("laplasjany",std::vector<int> {0,-1,0,-1,4,-1,0,-1,0});

}
std::vector<int> Maski::get_mask(std::string mask_name)
{
    if(maski_.count(mask_name)== 1)
    {
      return maski_[mask_name];
    }
    else
    {
     std::cout<<"nie ma takiej maski : "<<mask_name<<std::endl;
     return {};
    }
}


}  // namespace prework
