#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dt__21soCollisionAttackPartFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CD1F0(void* p, int flags) {
    if (p) {
        __destroy_arr((char*)p + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 5);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
