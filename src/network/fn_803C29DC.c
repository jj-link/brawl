#pragma force_active on
extern void* fn_803A9BB4(void*, void*, int);
extern void fn_803B1F80(void*);
extern void fn_803C290C(void);
extern char lbl_8053B248[];

void fn_803C29DC(void* arg0) {
    int sp8[6];
    void* result;
    if ((result = fn_803A9BB4(sp8, arg0, 1)) == 0) {
        fn_803B1F80(sp8);
    } else {
        *(void**)(lbl_8053B248 + 0x1C) = result;
    }
    fn_803C290C();
}
