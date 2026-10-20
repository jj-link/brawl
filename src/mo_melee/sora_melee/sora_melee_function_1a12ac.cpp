#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void*, int);
}

extern "C" void* fn_27_1A12AC(void* p, int flag) {
    if (p) {
        __destroy_arr((char*)p + 0xC, __dt__25soCollisionAttackAbsoluteFv, 0x68, 2);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
