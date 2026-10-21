#pragma force_active on
extern void fn_8027BDFC(void);
extern void *lbl_80532368[4];
extern void *lbl_805A0ED0;
extern void *lbl_805A0EA8;

void fn_8027C7DC(void) {
    void *a = fn_8027BDFC;
    void *c = lbl_805A0ED0;
    void *d = &lbl_805A0EA8;
    lbl_80532368[0] = a;
    lbl_80532368[2] = d;
    lbl_80532368[1] = c;
    lbl_805A0ED0 = (void *)lbl_80532368;
}

__declspec(section ".ctors") extern void* const fn_8027C7DC_ctor = (void*)fn_8027C7DC;
