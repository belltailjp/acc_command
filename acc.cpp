#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/format.hpp>

#include "cmdline.h"

namespace acc = boost::accumulators;


template<class TFeature>
double accumulate()
{
    acc::accumulator_set<double, acc::features<TFeature>> accumulator;

    double t;
    while(std::cin >> t, !std::cin.eof())
        accumulator(t);

    return acc::extract_result<TFeature>(accumulator);
}


int main(int argc, char* argv[])
{
    gengetopt_args_info arg;
    if(cmdline_parser(argc, argv, &arg))
        return -1;

    double t;
    if(arg.sum_given)  t = accumulate<acc::tag::sum>();
    if(arg.min_given)  t = accumulate<acc::tag::min>();
    if(arg.max_given)  t = accumulate<acc::tag::max>();
    if(arg.mean_given) t = accumulate<acc::tag::mean>();
    if(arg.var_given)  t = accumulate<acc::tag::variance>();
    if(arg.med_given)  t = accumulate<acc::tag::median>();

    std::cout << boost::format(arg.format_arg) % t << std::endl;
}

