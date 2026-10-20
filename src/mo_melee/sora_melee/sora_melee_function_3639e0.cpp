#pragma force_active on
extern "C" {
extern char lbl_27_data_90ED8[];
extern char lbl_27_bss_54EC[];
extern void fn_27_1E847C(void*, int, char*);
extern void __dl__FPv(void*);

void* fn_27_3639E0(void* ptr, int flag) {
    if (ptr) {
        *(int**)((char*)ptr + 8) = (int*)&lbl_27_data_90ED8;
        *(int**)ptr = (int*)&lbl_27_data_90ED8 + 2;
        fn_27_1E847C(ptr, 0x4d, lbl_27_bss_54EC);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}
