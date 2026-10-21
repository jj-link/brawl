#pragma force_active on
extern char lbl_27_bss_8380[];
extern char lbl_27_bss_8374[];
extern char lbl_27_data_92F50[];

extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void* fn_27_372430(char*, int);
extern "C" void __register_global_object(void*, void* (*)(char*, int), void*);

extern "C" void fn_27_3723B4() {
    fn_27_1E82E8(lbl_27_bss_8380, 0);
    char* p = lbl_27_bss_8380;
    char* d = lbl_27_data_92F50;
    *(char**)(p + 8) = d;
    *(char**)p = d + 8;
    fn_27_1E847C(p, 0x4A, p);
    __register_global_object(p, fn_27_372430, lbl_27_bss_8374);
}

__declspec(section ".ctors") extern void* const fn_27_3723B4_ctor = (void*)fn_27_3723B4;
