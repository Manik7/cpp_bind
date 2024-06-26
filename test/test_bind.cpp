#include <gtest/gtest.h>

#include <cmath>
#include <functional>
#include "../src/bind.hpp"

namespace {

TEST(bind_right, expicit_operator_example)
{    
    auto plusTwo     = bind::operator<<=(std::plus<>{}, 2);
    const int result = plusTwo(5);
    EXPECT_EQ(result, 7);
}

TEST(bind_right, plus)
{
    using namespace bind;
    
    auto plusTwo     = std::plus<>{} <<= 2;
    const int result = plusTwo(5);
    EXPECT_EQ(result, 7);
}

TEST(bind_right, minus)
{
    using namespace bind;
    
    auto minusTwo    = std::minus<>{} <<= 2;
    const int result = minusTwo(5);
    EXPECT_EQ(result, 3);
}

TEST(bind_right, lambda)
{
    // Since the function std::pow has many overloads, for float and double for example, it's not as easy to bind its
    // arguments, since the compiler needs to know _which_ overload we are trying to bind to, but overload resolution
    // of a function is only done when we actually call it.
    // For this example we create a lambda which refers explicitely to std::pow(float, float) to showcase that binding
    // works for non-generic lambdas.
    using namespace bind;

    auto pow = [](int l, int r){ return std::pow(static_cast<float>(l), static_cast<float>(r)); };
    auto square = pow <<= 2;
    const int result = square(5);
    EXPECT_EQ(result, 25);
}

TEST(bind_left, plus)
{
    using namespace bind;

    auto twoPlus     = 2 >>= std::plus<>{};
    const int result = twoPlus(5);
    EXPECT_EQ(result, 7);
}

TEST(bind_left, minus)
{
    using namespace bind;

    auto twoMinus    = 2 >>= std::minus<>{};
    const int result = twoMinus(5);
    EXPECT_EQ(result, -3);
}

}
