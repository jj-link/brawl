#pragma force_active on
extern void fn_8027E360(void);
extern unsigned int lbl_80532438[4];
extern unsigned int lbl_805A0EC0[2];
extern unsigned int *lbl_805A0ED0;

void fn_8027E4E8(void) {
    unsigned int *prev = lbl_805A0ED0;
    lbl_80532438[0] = (unsigned int)fn_8027E360;
    lbl_80532438[2] = (unsigned int)lbl_805A0EC0;
    lbl_80532438[1] = (unsigned int)prev;
    lbl_805A0ED0 = lbl_80532438;
}

__declspec(section ".ctors") extern void* const fn_8027E4E8_ctor = (void*)fn_8027E4E8;
