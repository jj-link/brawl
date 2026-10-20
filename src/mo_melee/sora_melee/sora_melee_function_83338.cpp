#pragma force_active on
struct Obj {
    char pad[4];
    int c;
    short d;
    short e;
};

extern signed char lbl_27_bss_1160;
extern Obj lbl_27_bss_1164;
extern char lbl_27_bss_E48[12];

extern "C" void fn_27_84258(void*, int);
extern "C" void* __register_global_object(void* object, void (*destructor)(void*, int), void* chain);

extern "C" void* fn_27_83338() {
    if (lbl_27_bss_1160 == 0) {
        lbl_27_bss_1164.c = -1;
        lbl_27_bss_1164.d = 0;
        lbl_27_bss_1164.e = -1;
        __register_global_object(&lbl_27_bss_1164, fn_27_84258, lbl_27_bss_E48);
        lbl_27_bss_1160 = 1;
    }
    return &lbl_27_bss_1164;
}
