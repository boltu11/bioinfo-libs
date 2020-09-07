#include "dp.hpp"



long double rabbit_fseq_no_death(int n, int k){
    long double result[n+1] = {};
 
    result[0] = 1;
    result[1] = 1;
    

    for(int i = 2; i<n+1;i++)
    {
        result[i] = k*result[i-2] + result[i-1];
    }

    return result[n-1];
}

unsigned long long int rabbit_fseq_death(int n, int k, int m){
  std::vector<unsigned long long int> result ;
  std::vector<unsigned long long int>::iterator it;

    result.push_back(1);
  for(int i = 0; i<m-1;i++){
      result.push_back(0);
  }
  

    for(int k = 0; k< n;k++){

        it = result.begin();
        unsigned long long int sum = 0;
        for( int i = 1; i<=m-1;i++){
            sum = sum + result.at(i);
        }
        result.insert(it, sum);
        result.pop_back();
    }

    unsigned long long int total_sum = 0;
    while(!result.empty())
    {
        total_sum += result.back();
        result.pop_back();
    }

   return total_sum;
}