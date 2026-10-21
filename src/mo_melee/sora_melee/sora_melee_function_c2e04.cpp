#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;

extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void* fn_27_C2DC4(void* p, int n);

struct DtorChain {
    DtorChain* next;
    void* destructor;
    void* object;
};

struct Obj {
    u32 a;
    s32 b;
    u16 c;
    s16 d;
    u32 e;
    u32 f;
};

extern "C" {
extern Obj lbl_27_bss_2BEC;
extern DtorChain lbl_27_bss_2BE0;
}

extern "C" void fn_27_C2E04() {
    lbl_27_bss_2BEC.a = 0;
    lbl_27_bss_2BEC.b = 0;
    lbl_27_bss_2BEC.c = 0;
    lbl_27_bss_2BEC.d = -1;
    __register_global_object(&lbl_27_bss_2BEC, (void*)fn_27_C2DC4, &lbl_27_bss_2BE0);
}

__declspec(section ".ctors") extern void* const fn_27_C2E04_ctor = (void*)fn_27_C2E04;
