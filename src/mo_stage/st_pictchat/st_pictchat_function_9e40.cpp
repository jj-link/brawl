#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);
}

extern "C" void* fn_73_9E40(void* p, int flags) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
