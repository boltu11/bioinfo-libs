
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

double GC_content(std::string DNA_seq){
    
    double g_or_c_count = 0;
    double seq_size = DNA_seq.size();
    
    for(int i = 0; i<seq_size;i++)
    {
            //C
        if(DNA_seq[i] == 0x43)
        {
            g_or_c_count++;
        }

            //G
        if(DNA_seq[i] == 0x47)
        {
            g_or_c_count++;
        }
    }

    double return_result = g_or_c_count / (seq_size);
    return return_result;
}

std::vector<std::tuple<std::string,double>> GC_content_FASTA(std::string file_location){
    ifstream text_file (file_location);
    std::string temp_string;
    std::string DNA_string;
    std::vector<std::tuple<std::string,double>> return_vector;
    int diff=0;

    if(text_file.is_open())
    {

        while(getline(text_file,temp_string)){

            if(temp_string[0] != 0x3E)
            {
                DNA_string += temp_string;
            }
            else
            {
                DNA_string += temp_string + ':';
            }
        }

        std::string temp_label;
        std::string temp_gc_content;
        std::string temp_content_string;
        std::string result_string;

        int i = 1;
        cout << DNA_string << "\n";

        while(i < DNA_string.size())
        {
            temp_label.clear();
            temp_content_string.clear();
            temp_gc_content.clear();


            while(DNA_string[i] != 0x3A)
            {
                temp_label += DNA_string[i];
                i++;
            }

            i++;

            while(DNA_string[i] != 0x3E && DNA_string[i] != '\0')
            {
                
                temp_content_string += DNA_string[i];
                i++;
            }

            cout << temp_content_string << "\n";

            double gc_percent = GC_content(temp_content_string);

            std::tuple<std::string,double>gc_tuple (temp_label,gc_percent);

            return_vector.push_back(gc_tuple);
        }

    }

    text_file.close();

    return return_vector;
}

int hamm_dist(std::string s1, std::string s2){
    int hamm_distance = 0;

    for(int i =0; i<s1.size();i++)
    {
        if(s1[i] != s2[i])
        {
            hamm_distance++;
        }
    }

    return hamm_distance;
}

void enum_gene_order(std::string file_location, int n){

    ofstream file;
    file.open(file_location);

    // zero vector of n size
    std::vector<int> gene_orders;
    int factorial = 1;


    for(int i =1;i<= n;i++)
    {
        gene_orders.push_back(i);
        factorial = factorial * i;
    }

    if(file.is_open())
    {
        file << to_string(factorial)+'\n';
    }

    do
    {
        if(file.is_open())
        {
            for (const auto &e : gene_orders) file << e << " ";

            file << "\n";
        }
    }while(std::next_permutation(gene_orders.begin(),gene_orders.end()));

    file.close();
}

void enum_k_mers(std::string file_location, std::string k_mers, int string_length)
{
    ofstream file;
    file.open(file_location);

    std::vector<std::vector<char>> order_collection;
    


    int s = k_mers.size() * string_length;

    for(int i = 1;i<=s;i++)
    {
        std::vector<char> orders;

        std::vector<int> inty;

        for(int j =0;j<string_length;j++)
        {
            if(j==0)
            { //Base
                inty.push_back(i % string_length);
            }
            else
            {
                inty.push_back(((i-(i%(string_length * j)))/(string_length * j) + 1)%(string_length * j));
            }
        }
                    for (const auto &e :inty) cout << e << " ";

            cout << "\n";

    }
       

    file.close();
}






