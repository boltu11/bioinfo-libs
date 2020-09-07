#ifndef SEQ_MAN
#define SEQ_MAN

#include <stdio.h>
#include <iostream>
#include <string.h>

int* DNA_nuc_count(std::string DNA_seq);
std::string RNA_transcribe(std::string DNA_seq);
std::string DNA_complement(std::string DNA_seq);

#endif