#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "FileManager.cpp"
#include "DummyData.cpp"

namespace prework
{
namespace tests
{

using namespace ::testing;

namespace
{
    const std::string FILENAME{"file.txt"};
}

struct DummyTestShould : Test
{
    DummyTestShould()
        : Test()
    {}

    virtual ~DummyTestShould() = default;

    FileManager manager_;
};

TEST_F(DummyTestShould, loadShouldReturnZero)
{
    auto data = manager_.loadData(FILENAME);
    ASSERT_EQ(data.size(), 0);
}

}  // namespace tests
}  // namespace prework
