#include "util.h"
#include "receiver.h" //interface, TODO: extract to separate header

extern "C"
{
#include <stdlib.h>
#include <string.h>
#include <math.h>
}

util::util()
{
}

uint8_t util::calc_checksum(const char *str, unsigned int strlen)
{
    unsigned int pos(0);
    unsigned int sum(0);
    while (pos != strlen)
    {
        if (str[pos] != '#'
                and str[pos] != '['
                and str[pos] != ']') {
            sum+=str[pos];
        }
        pos++;
    }
    return sum%100;
}

int8_t util::digit_to_num(char c)
{
    if (c >= '0' && c <= '9') return c-'0';
    return -1;
}

bool util::parse_numbers(const char *string, numbers_seq &seq)
{
    char* dot_ptr;
    unsigned int counter(0);
    dot_ptr = strchr((char*)string, MSG_SEPARATOR_DATA);
    if (dot_ptr != NULL) ++counter;
    while (dot_ptr != NULL)
    {
        dot_ptr = strchr(dot_ptr+1, MSG_SEPARATOR_DATA);
        counter++;
    }
    seq.size = counter;
    if (seq.numbers != NULL) free(seq.numbers);
    seq.numbers = (uint16_t*)calloc(seq.size, sizeof(uint16_t));
    char* prev_dot_ptr = (char*)string;
    dot_ptr = strchr((char*)string, MSG_SEPARATOR_DATA);
    uint16_t number;
    counter = 0;
    while (dot_ptr != NULL) {
        number = 0;
        for(; prev_dot_ptr != dot_ptr; ++prev_dot_ptr)
        {
            int8_t tmp = digit_to_num(*prev_dot_ptr);
            if (tmp<0) return false;
            number += tmp*(uint16_t)pow(10,dot_ptr-prev_dot_ptr-1);
        }
        seq.numbers[counter]=number;
        counter++;
        prev_dot_ptr = ++dot_ptr;
        dot_ptr = strchr((char*)prev_dot_ptr, MSG_SEPARATOR_DATA);
    }
    number = 0;
    char* eof((char*)string);
    while (*eof) ++eof;
    if (eof != string) {
        while(prev_dot_ptr != eof)
        {
            int8_t tmp = digit_to_num(*prev_dot_ptr);
            if (tmp<0) return false;
            number += (uint8_t)tmp*pow(10,eof-prev_dot_ptr-1);
            ++prev_dot_ptr;
        }
        seq.numbers[counter]=number;
    }
    return true;
}

numbers_seq::numbers_seq():numbers(NULL),size(0){}

numbers_seq::~numbers_seq()
{
    if (numbers != NULL) free(numbers);
}
