#pragma force_active on
extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* __dt__21soCollisionAttackPartFv(void*, short);
void* fn_27_37D3C(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_314010(void* arg0, int arg1) {
    if (arg0 != 0) {
        __dt__27soCollisionAttackModuleImplFv((char*)arg0 + 0x2D4, -1);
        if ((unsigned long)((char*)arg0 + 0x24C) != 0) {
            __destroy_arr((char*)arg0 + 0x258, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        }
        if (arg0 != 0) {
            __destroy_arr((char*)arg0 + 0xC, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 4);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}