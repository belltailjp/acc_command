#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

#include "cmdline.h"

namespace acc = boost::accumulators;


template<class TValue, class TFeature>
double accumulate()
{
    acc::accumulator_set<TValue, acc::features<TFeature>> accumulator;

    double t;
    while(std::cin >> t, !std::cin.eof())
    {
        accumulator(t);
    }
    return static_cast<TValue>(acc::extract_result<TFeature>(accumulator));
}


int main(int argc, char* argv[])
{
    gengetopt_args_info arg;
    if(cmdline_parser(argc, argv, &arg))
        return -1;

    std::cout << accumulate<double, acc::tag::sum>() << std::endl;;
}

