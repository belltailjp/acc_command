#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

#include "cmdline.h"

namespace acc = boost::accumulators;

template<class TFeature>
double accumulate()
{
    acc::accumulator_set<double, acc::features<TFeature>> accumulator;

    std::string t;
    try
    {
        while(std::cin >> t, !std::cin.eof())
            accumulator(boost::lexical_cast<double>(t));
    }catch(boost::bad_lexical_cast e)
    {
        throw t;
    }

    return acc::extract_result<TFeature>(accumulator);
}


int main(int argc, char* argv[])
{
    gengetopt_args_info arg;
    if(cmdline_parser(argc, argv, &arg))
        return -1;

    double t;
    try
    {
        if(arg.sum_given)  t = accumulate<acc::tag::sum>();
        if(arg.min_given)  t = accumulate<acc::tag::min>();
        if(arg.max_given)  t = accumulate<acc::tag::max>();
        if(arg.mean_given) t = accumulate<acc::tag::mean>();
        if(arg.var_given)  t = accumulate<acc::tag::variance>();
        if(arg.med_given)  t = accumulate<acc::tag::median>();
    }
    catch(const std::string& e)
    {
        std::cerr << argv[0] << ": \"" << e << "\" couldn't be converted into a number" << std::endl;
        return -1;
    }
    catch(...)
    {
        std::cerr << argv[0] << ": unknown error" << std::endl;
        return -1;
    }

    std::cout << boost::format(arg.format_arg) % t << std::endl;
}

