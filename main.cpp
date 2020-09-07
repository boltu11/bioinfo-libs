#include <iostream>  
#include <fstream>  
#include <stdio.h>
#include <string.h>
#include "dp/dp.hpp"

using namespace std; 

  
// main function - 
// where the execution of program begins 
int main() 
{

    ifstream dna_text;
    string test_string;
    string result_string;
    int* c; 

    cout.precision(15);
    cout << rabbit_fseq_death(87,1,20);

    /*
    dna_text.open("C:\\Users\\navi_\\Downloads\\rosalind_revc.txt");

    dna_text.close();
*/
    return 0;
    
} 