/**
 * Made by Adrian Jekiel
 * Year 2019
 **/

#ifndef PREWORK_DUMMY_DATA_HPP_
#define PREWORK_DUMMY_DATA_HPP_

#include <iostream>
#include <string>

namespace prework
{

struct DummyData
{
    DummyData(const std::string name, const int age);
    void setName(const std::string name);
    void setAge(const int age);
    std::string name() const;
    int age() const;

private:
    std::string name_;
    int age_;
};

// implementation of overload ostream operator should be inlined just to have compilet this piece of code only once
// delete inline and see what will compilator tell you

inline std::ostream& operator<<(std::ostream& os, const DummyData& data)
{
    os << "Name: " << data.name() << ", age: " << data.age() << std::endl;
    return os;
}

}  // namespace prework

#endif  // PREWORK_DUMMY_DATA_HPP_
