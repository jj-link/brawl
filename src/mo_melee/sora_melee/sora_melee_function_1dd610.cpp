#pragma force_active on
typedef unsigned char u8;

extern "C" void* __vt__10soNullable[];
extern "C" void* lbl_27_data_6E94[];
extern "C" void* lbl_27_data_45B30[];
extern "C" void* fn_27_1DD5D0(void* p, int n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

struct DtorChain {
    DtorChain* next;
    void* dtor;
    void* obj;
};

struct Obj {
    void** vt;
    u8 flag;
    void** p;
};

extern "C" DtorChain lbl_27_bss_50B8;
extern "C" Obj lbl_27_bss_50C4;

extern "C" void* fn_27_1DD610(void) {
    lbl_27_bss_50C4.vt = __vt__10soNullable;
    lbl_27_bss_50C4.p = lbl_27_data_6E94;
    lbl_27_bss_50C4.flag = 0;
    lbl_27_bss_50C4.vt = lbl_27_data_6E94 + 2;
    lbl_27_bss_50C4.p = lbl_27_data_45B30;
    lbl_27_bss_50C4.vt = lbl_27_data_45B30 + 2;
    return __register_global_object(&lbl_27_bss_50C4, (void*)fn_27_1DD5D0, &lbl_27_bss_50B8);
}

__declspec(section ".ctors") extern void* const fn_27_1DD610_ctor = (void*)fn_27_1DD610;
