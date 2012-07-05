#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

namespace acc = boost::accumulators;

int main(int argc, char* argv[])
{
    acc::accumulator_set<double, acc::features<acc::tag::min>> accumulator;

    double t;
    while(!std::cin.eof())
    {
        std::cin >> t;
        accumulator(t);
    }
    std::cout << acc::extract::min(accumulator) << std::endl;
}

