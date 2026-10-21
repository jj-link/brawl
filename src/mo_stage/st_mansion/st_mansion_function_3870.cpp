#include <stddef.h>
#pragma force_active on

extern "C" {
void __register_global_object(void *object, void *destructor, void *chain);
void *fn_47_3934(void *p, int n);

extern char lbl_47_data_FC0[];
extern char lbl_47_data_F68[];

struct Obj {
    signed char c;
    void *p;
};
extern Obj lbl_47_bss_50;

extern char lbl_47_bss_18;
extern char lbl_47_bss_48;
}

extern "C" void *fn_47_3870(void) {
    if (lbl_47_bss_48)
        goto done;
    lbl_47_bss_50.p = lbl_47_data_FC0;
    lbl_47_bss_50.c = 1;
    lbl_47_bss_50.p = lbl_47_data_F68;
    __register_global_object(&lbl_47_bss_50, fn_47_3934, &lbl_47_bss_18);
    lbl_47_bss_48 = 1;
done:
    return &lbl_47_bss_50;
}
