#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

namespace acc = boost::accumulators;


template<class T>
double accumulate()
{
    acc::accumulator_set<double, acc::features<T>> accumulator;

    double t;
    while(!std::cin.eof())
    {
        std::cin >> t;
        accumulator(t);
    }
    return acc::extract_result<T>(accumulator);
}


int main(int argc, char* argv[])
{
    std::cout << accumulate<acc::tag::max>() << std::endl;;
}

