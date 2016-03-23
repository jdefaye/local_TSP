#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>


class Solution {

  private:
    std::pair<float, float> eval;
    std::vector<int> configuration;
    
  public:
    
    /* CONSTRUCTEUR */
    Solution();
    Solution(const std::pair<float, float> & evaluation, const std::vector<int> & conf);
    
    /* GETTERS ET SETTERS */
    
    std::pair<float, float> get_eval() const;
    void set_eval(const std::pair<float, float > & evaluation);
    
    std::vector<int> get_configuration() const;
    void set_configuration(const std::vector<int> & conf);
  
};

#endif