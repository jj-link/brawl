#include <stddef.h>
#pragma force_active on

extern "C" {
void __register_global_object(void *object, void *destructor, void *chain);
void *fn_50_5768(void *p, int n);

extern char lbl_50_data_1858[];
extern char lbl_50_data_18B0[];

struct DonkeyObj {
    unsigned char c;
    void *p;
};
extern DonkeyObj lbl_50_bss_40;

extern char lbl_50_bss_3C;

struct DescChain {
    struct DescChain *next;
    void *destructor;
    void *object;
};
extern DescChain lbl_50_bss_18;
}

extern "C" void *fn_50_56A4(void) {
    if (lbl_50_bss_3C)
        goto done;
    lbl_50_bss_40.p = lbl_50_data_18B0;
    lbl_50_bss_40.c = 1;
    lbl_50_bss_40.p = lbl_50_data_1858;
    __register_global_object(&lbl_50_bss_40, fn_50_5768, &lbl_50_bss_18);
    lbl_50_bss_3C = 1;
done:
    return &lbl_50_bss_40;
}
