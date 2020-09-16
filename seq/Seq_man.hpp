#ifndef SEQ_MAN
#define SEQ_MAN

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
 

int* DNA_nuc_count(std::string DNA_seq);
std::string RNA_transcribe(std::string DNA_seq);
std::string DNA_complement(std::string DNA_seq);
std::vector<std::tuple<std::string,double>> GC_content_FASTA(std::string file_location);
void enum_gene_order(std::string file_location, int n);
int hamm_dist(std::string s1, std::string s2);
void enum_k_mers(std::string file_location, std::string k_mers, int string_length);

#endif