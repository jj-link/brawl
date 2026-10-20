#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soModelVirtualNodeFv(void*, int);
}

extern "C" void* fn_27_CC7EC(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, __dt__18soModelVirtualNodeFv, 0x14, 3);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
