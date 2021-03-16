#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// the top-level page table 
typedef struct{
    unsigned int frame; // if valid bit == 1, pysical frame holding vpage
    size_t swap_off; // offset in swap file of vpage, ifany
    unsigned long stamp;
    int ref;
} pgtbl_entry_t;

// void init_pagetable(){
//     int i;
//     pgtbl_entry_t* pgtbl;
    
//     // allocating aligned memory ensures the low bits in the pointer must
//     // be zero, so we can use them to store our status bits, like PG_VALID
    
// }