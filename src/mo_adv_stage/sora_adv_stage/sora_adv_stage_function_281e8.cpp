#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);
void* fn_40_281E8(char* p, int flag);
}

void* fn_40_281E8(char* p, int flag) {
    if (p) {
        __destroy_arr(p + 0xc, __dt__21soCollisionAttackPartFv, 0x90, 1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
