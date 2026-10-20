#include <types.h>
#pragma force_active on

typedef struct lbl_27_bss_604_t
{
    unsigned char unk[0x10];
} lbl_27_bss_604_t;

extern lbl_27_bss_604_t lbl_27_bss_604;

extern "C" lbl_27_bss_604_t* fn_27_2814D8()
{
    return &lbl_27_bss_604;
}
