#pragma force_active on
extern "C" {
void __dt__21soCollisionAttackPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_57_A6E0(void* p, int flags) {
    if (p != 0) {
        __destroy_arr((char*)p + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 2);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
