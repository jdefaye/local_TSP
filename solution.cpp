#include "solution.h"

Solution::Solution() {}


Solution::Solution(const std::pair< float, float >& evaluation, const std::vector< int >& conf): eval(evaluation), configuration(conf)
{}



std::pair< float, float > Solution::get_eval() const
{
  return eval;
}


void Solution::set_eval(const std::pair< float, float >& evaluation)
{
  eval = evaluation;
}



std::vector< int > Solution::get_configuration() const
{
  return configuration;
}


void Solution::set_configuration(const std::vector< int >& conf)
{
  configuration = conf;
}




