#pragma force_active on
extern "C" {
typedef int s32;
typedef void (*Dtor)(void*, int);
void __destroy_arr(void*, Dtor, unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_37D3C(void*, s32);
}

extern "C" void* fn_73_9F70(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0x0C, (Dtor)fn_27_37D3C, 0x78, 1);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
