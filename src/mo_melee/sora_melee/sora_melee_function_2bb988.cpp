#pragma force_active on
extern "C" {
void* fn_27_C86F0(void* p, int size);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_2BB988(void* p, int doDelete) {
    if (p) {
        __destroy_arr((char*)p + 0x8, (void (*)(void*, int))fn_27_C86F0, 0x14, 0xb);
        if (doDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
