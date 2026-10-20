#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
    extern char lbl_27_data_3C358[];
    void fn_27_D2A0C(void* p);
    void* fn_27_AB510(void* p, s32 n);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct fnS27Arr {
    char* m0;
    char* m4;
    u32 m8;
};

extern "C" {
fnS27Arr* fn_27_1A1C90(fnS27Arr* p) {
    p->m0 = lbl_27_data_3C358;
    p->m4 = lbl_27_data_3C358 + 0x48;
    p->m8 &= 0x1FFF;
    __construct_array((char*)p + 0xC, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 0x19);
    return p;
}
}
