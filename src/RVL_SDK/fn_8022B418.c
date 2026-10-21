#pragma force_active on
extern void fn_801D81C4(void*, void*, int, int, void*, void*);
extern char lbl_804FC200[];
extern void fn_8022B358(void);

void fn_8022B418(void* a1, void* a2) {
    fn_801D81C4(a1, a2, 0, 0, fn_8022B358, &lbl_804FC200[0x1000]);
}
