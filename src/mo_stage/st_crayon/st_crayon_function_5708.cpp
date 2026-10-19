#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__19soCollisionHitGroupFv(void*, int);
}

extern "C" void* fn_56_5708(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xc, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
