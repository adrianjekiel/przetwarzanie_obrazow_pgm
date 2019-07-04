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

}
std::vector<int> Maski::get_mask(std::string mask_name)
{
    return maski[mask_name];
}


}  // namespace prework
