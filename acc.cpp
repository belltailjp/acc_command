#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

namespace acc = boost::accumulators;


template<class TValue, class TFeature>
double accumulate()
{
    acc::accumulator_set<TValue, acc::features<TFeature>> accumulator;

    double t;
    while(!std::cin.eof())
    {
        std::cin >> t;
        accumulator(t);
    }
    return static_cast<TValue>(acc::extract_result<TFeature>(accumulator));
}


int main(int argc, char* argv[])
{
    std::cout << accumulate<double, acc::tag::sum>() << std::endl;;
}

