#include <stdio.h>
#include <limits.h>


int shiftRBit(int counter, int r_bit){
    return (counter >> 1) | (r_bit << 7);
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
            if (pages[j].counter < pages[i].counter || (pages[j].counter == pages[i].counter && pages[j].id < pages[i].id)){
                struct Page temp = pages[i];
                pages[i] = pages[j];
                pages[j] = temp;
            }
        }
    }
}

void print(struct Page pages[], int n){
    for (int i = 0; i < n; i++){
        printf("\t#%d id=%d, counter=%d, r_bit=%d \n", i, pages[i].id, pages[i].counter, pages[i].r_bit);
    }
}


int main()
{
    int n, m, clock_number, page_number;
    scanf("%d %d", &n, &m);

    struct Page pages[n];
    int  filled = 0, current_clock = 1; //filled = 0, hit = 0,
    double miss = 0.0, hit = 0.0;

    for (int i = 0; i < n; i++){
        pages[i].counter = INT_MAX;
        pages[i].id = INT_MAX;
        pages[i].r_bit = 0;
    }

    for (int i = 0; i < m; i++){
        scanf("%d %d", &clock_number, &page_number);
        if (current_clock != clock_number){
            current_clock = clock_number;
            for (int j = 0; j < filled; j++){
                pages[j].counter = shiftRBit(pages[j].counter, pages[j].r_bit);
                pages[j].r_bit = 0;
            }
            sort(pages, n);
        }

//        printf("############## %d ############# filled: %d, input: clock=%d, id=%d\n", i+1, filled, clock_number, page_number);
//        print(pages, n);

        int index = isExist(pages, n, page_number);
        if (index != -1){
            pages[index].r_bit = 1;
            hit++;
            printf("1\n");
        } else{
            miss++;
            printf("0\n");
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



    }


    double ratio = hit/miss;
    printf("%.15f", ratio);


    return 0;
}