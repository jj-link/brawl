#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* __dt__21soCollisionAttackPartFv(void*, short);
void* fn_27_37D3C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_37A6D4(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__27soCollisionAttackModuleImplFv((char*)arg0 + 0x754, -1);
        if ((unsigned long)((char*)arg0 + 0x3FC) != 0) {
            __destroy_arr((char*)arg0 + 0x408, (void (*)(void*, int))fn_27_37D3C, 0x78, 7);
        }
        if (arg0 != 0) {
            __destroy_arr((char*)arg0 + 0xC, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 7);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
