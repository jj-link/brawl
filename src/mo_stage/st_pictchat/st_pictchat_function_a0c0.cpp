#pragma force_active on
extern "C" {
void* fn_73_A080(void* p, int flag);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_73_A0C0(void* p, int flag) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_73_A080, 8, 7);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
