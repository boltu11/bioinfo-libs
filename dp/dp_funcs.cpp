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

    //Var init    
    std::vector<unsigned long long int> result ;
    std::vector<unsigned long long int>::iterator it;
    unsigned long long int total_sum = 0;

    //Create initial vector size of in form of 1,0,0...m.
    result.push_back(1);
    for(int i = 0; i<m-1;i++){
        result.push_back(0);
    }
  
    //Get sum of vector using index 1 to m-1 and insert it at start of array and pop the last element. i.e. [sum,1,0...0];

    for(int k = 0; k< n;k++){

        //Take 
        it = result.begin();
        unsigned long long int sum = 0;
        for( int i = 1; i<=m-1;i++){
            sum = sum + result.at(i);
        }
        result.insert(it, sum);
        result.pop_back();
    }

    //Sum the final array to find total pop
    while(!result.empty())
    {
        total_sum += result.back();
        result.pop_back();
    }

   return total_sum;
}