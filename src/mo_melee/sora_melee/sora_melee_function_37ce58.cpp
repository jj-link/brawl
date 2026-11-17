#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
extern signed char lbl_27_bss_5C68;
extern char lbl_27_bss_84FC[];
extern char lbl_27_data_12DD0[];
extern char lbl_27_data_3A068[];
extern char lbl_27_data_3A338[];
void fn_27_82C14(void);
void fn_27_A6948(void);
void fn_27_A6978(void);
void __register_global_object(void*, void*, void*);
void fn_27_A34D4(void*, void*, void*, void*, void*, void*, void*, void*, int);
void fn_27_A78C0(void*);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
}

struct GlobalObj {
    void* vt;
    GlobalObj() { vt = 0; vt = lbl_27_data_12DD0; }
};
extern "C" GlobalObj lbl_27_bss_5C6C;

struct ArrA {
    void* vt0;
    void* vt1;
    unsigned top : 4;
    unsigned last : 4;
    unsigned size : 4;
    unsigned full : 1;
    ArrA() {
        vt0 = lbl_27_data_3A068;
        vt1 = lbl_27_data_3A068 + 0x48;
        top = 0;
        last = 0;
        size = 0;
        full = 0;
    }
};

struct ArrB {
    void* vt0;
    void* vt1;
    unsigned top : 2;
    unsigned last : 2;
    unsigned size : 2;
    unsigned full : 1;
    ArrB() {
        vt0 = lbl_27_data_3A338;
        vt1 = lbl_27_data_3A338 + 0x48;
        top = 0;
        last = 0;
        size = 0;
        full = 0;
    }
};

extern "C" void* fn_27_37CE58(void* self, void* a1, void* a2, void* a3) {
    char* p = (char*)self;
    if (lbl_27_bss_5C68 == 0) {
        GlobalObj* g = new (&lbl_27_bss_5C6C) GlobalObj;
        __register_global_object(g, (void*)fn_27_82C14, lbl_27_bss_84FC);
        lbl_27_bss_5C68 = 1;
    }
    fn_27_A34D4(p + 4, a1, a2, p + 0xD8, p + 0x6C, p + 0x50, &lbl_27_bss_5C6C, a3, -1);
    fn_27_A78C0(p + 0x50);
    new (p + 0x6C) ArrA;
    new (p + 0xD8) ArrB;
    __construct_array(p + 0xE4, (void*)fn_27_A6948, (void*)fn_27_A6978, 0x24, 1);
    return self;
}