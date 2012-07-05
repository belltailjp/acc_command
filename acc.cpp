#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

#include "cmdline.h"

namespace acc = boost::accumulators;


template<class TValue, class TFeature>
void accumulate()
{
    acc::accumulator_set<TValue, acc::features<TFeature>> accumulator;

    double t;
    while(std::cin >> t, !std::cin.eof())
    {
        accumulator(t);
    }
    std::cout << static_cast<TValue>(acc::extract_result<TFeature>(accumulator)) << std::endl;
}


int main(int argc, char* argv[])
{
    gengetopt_args_info arg;
    if(cmdline_parser(argc, argv, &arg))
        return -1;

    if(!arg.integer_given)
    {
        if(arg.sum_given)  accumulate<double, acc::tag::sum>();
        if(arg.min_given)  accumulate<double, acc::tag::min>();
        if(arg.max_given)  accumulate<double, acc::tag::max>();
        if(arg.sum_given)  accumulate<double, acc::tag::sum>();
        if(arg.mean_given) accumulate<double, acc::tag::mean>();
        if(arg.var_given)  accumulate<double, acc::tag::variance>();
        if(arg.med_given)  accumulate<double, acc::tag::median>();
    }else{
        if(arg.sum_given)  accumulate<int, acc::tag::sum>();
        if(arg.min_given)  accumulate<int, acc::tag::min>();
        if(arg.max_given)  accumulate<int, acc::tag::max>();
        if(arg.sum_given)  accumulate<int, acc::tag::sum>();
        if(arg.mean_given) accumulate<int, acc::tag::mean>();
        if(arg.var_given)  accumulate<int, acc::tag::variance>();
        if(arg.med_given)  accumulate<int, acc::tag::median>();
    }
}

