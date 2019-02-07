/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#include "DummyData.hpp"

namespace prework
{

DummyData::DummyData(const std::string name, const int age) :
    name_(name),
    age_(age)
{
    std::cout << "C-tor" << std::endl;
}

void DummyData::setName(const std::string name)
{
    name_ = name;
}

void DummyData::setAge(const int age)
{
    age_ = age;
}

std::string DummyData::name() const
{
    return name_;
}

int DummyData::age() const
{
    return age_;
}

}  // namespace prework
