// Results could be different from yours due to COUNTER_BITS
// and due to defining what page to remove while inserting
// This program implements the same algorithm as in Stepik, but
// with new requirements: reading from file and new page -> new clock cycle

#include <stdio.h>
#include <limits.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define COUNTER_BITS 16
#define BUFSIZE 80
char filename[BUFSIZE] = "input.txt";

int handle_args(int argc, char ** argv) {
    if (argc != 2) {
        printf("usage: %s <number of pageframes>\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        int num = atoi(argv[1]);
        if (num <= 0) {
            printf("error: number of page frames must be a positive integer number\n");
            exit(EXIT_FAILURE);
        }
        return num;
    }
}

int shiftRBit(int counter, int r_bit){
    return (counter >> 1) | (r_bit << (COUNTER_BITS-1));
}

struct Page{
    int id;
    int counter;
    int r_bit;
};

int isExist(struct Page pages[], int n, int page_number){
    for (int i = 0; i < n; i++){
        if (page_number == pages[i].id){
            return i;
        }

    }
    return -1;
}


void sort(struct Page pages[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (pages[j].counter < pages[i].counter  || (pages[j].counter == pages[i].counter && pages[j].id < pages[i].id)){
                struct Page temp = pages[i];
                pages[i] = pages[j];
                pages[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv){
    int n = handle_args(argc, argv);

    struct Page pages[n];
    int  filled = 0;
    double miss = 0.0, hit = 0.0;

    for (int i = 0; i < n; i++){
        pages[i].counter = INT_MAX;
        pages[i].id = INT_MAX;
        pages[i].r_bit = 0;
    }


    printf( "%d 1000\n", n);
    FILE * openfile;
    openfile = fopen(filename, "r");
    int page_number;
    int code;
    int i = 1;
    do {

        code = fscanf(openfile, "%d", &page_number);
        if(code == 1){
            printf( "%d %d\n", i,  page_number);
            i++;
            int index = isExist(pages, n, page_number);
            if (index != -1){
                pages[index].r_bit = 1;
                hit++;
                // printf("1\n");
            } else{
                miss++;
                // printf("0\n");
                if (filled != n){
                    pages[filled].r_bit = 1;
                    pages[filled].counter = 0;
                    pages[filled].id = page_number;
                    filled++;
                } else{
                    pages[0].r_bit = 1;
                    pages[0].counter = 0;
                    pages[0].id = page_number;
                }
                sort(pages, n);
            }

            for (int j = 0; j < filled; j++){
                pages[j].counter = shiftRBit(pages[j].counter, pages[j].r_bit);
                pages[j].r_bit = 0;
            }
            sort(pages, n);
        }
    } while(code != EOF);

    double ratio = hit/miss;


    printf("hit: %.15f\n", hit);
    printf("miss: %.15f\n", miss);
    printf("ratio: %.15f\n", ratio);
    return 0;
}