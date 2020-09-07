
#include "Seq_man.hpp"

/**
 * Counts nucleotides from a string
 * @input String DNA_seq
 * @output ptr to array[] = {A,C,G,T}
*/

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

string RNA_transcribe(string DNA_seq){

    //Initialize Vars
    int diff = 0;
    const char u_nuc = 'U';
    string RNA_seq;

    for(int i = 0; i < DNA_seq.size();i++)
    {
        //XOR with A
        diff = ( DNA_seq[i] | 0x54) & ~( DNA_seq[i] & 0x54);

        if(diff == 0)
        {
            RNA_seq = RNA_seq + u_nuc;
        }
        else
        {
            RNA_seq = RNA_seq + DNA_seq[i];
        }
    
    }

    return RNA_seq;
}

string DNA_complement(string DNA_seq){

    int diff = 0;
    string DNA_comp;

    for(int i = 0; i<DNA_seq.size();i++)
    {
         //XOR with A
        diff = ( DNA_seq[i] | 0x41) & ~( DNA_seq[i] & 0x41);

        //A
        if(diff == 0)
        {
            DNA_comp = 'T' + DNA_comp;
        }

            //C
        if(diff == 2)
        {
            DNA_comp = 'G' + DNA_comp;
        }

            //G
        if(diff == 6)
        {
            DNA_comp = 'C' + DNA_comp;
        }

            //T
        if(diff == 21)
        {
            DNA_comp = 'A' + DNA_comp;
        }
    }

    return DNA_comp;
}


