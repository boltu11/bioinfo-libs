#include <iostream>  
#include <fstream>  
#include <stdio.h>
#include <string.h>

using namespace std; 


int* DNA_nuc_count(string DNA_seq){

    //Initialize Vars
    int diff = 0;

    static int nuc_array[] = {0,0,0,0};

    for(int i = 0; i < DNA_seq.size();i++)
    {
                //XOR with A
                diff = ( DNA_seq[i] | 0x41) & ~( DNA_seq[i] & 0x41);

                //A
                if(diff == 0)
                {
                    nuc_array[0]++;
                }

                 //C
                if(diff == 2)
                {
                    nuc_array[1]++;
                }

                 //G
                if(diff == 6)
                {
                    nuc_array[2]++;
                }

                 //T
                if(diff == 21)
                {
                    nuc_array[3]++;
                }
    }

    return nuc_array;
}

  
// main function - 
// where the execution of program begins 
int main() 
{

    ifstream dna_text;
    string test_string;
    int* c; 
    
    dna_text.open("C:\\Users\\navi_\\Downloads\\rosalind_dna_1.txt");

    if(dna_text.is_open()){
        while(getline(dna_text,test_string))
        {
           c = DNA_nuc_count(test_string);
        }
    }

   int nuc_a = *c;
   int nuc_c = *c+1;
   int nuc_g = *c+2;
   int nuc_t = *c+3;

   cout << nuc_a <<' '<< nuc_c << " "<< nuc_g <<" "<< nuc_t;

    dna_text.close();


    return 0;
    
} 