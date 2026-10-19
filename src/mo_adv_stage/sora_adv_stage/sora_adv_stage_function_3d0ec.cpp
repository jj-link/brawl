#pragma force_active on
typedef unsigned long u32;

extern "C" int isEnableAttackPersonAttacked__10grYakumonoFUlUlUl(void* self, u32, u32, u32);
extern "C" void fn_40_3D138(void* self);

extern "C" void fn_40_3D0EC(void* self, u32 a, u32 b, u32 c) {
    u32 v = *(u32*)((char*)self + 0x1a0);
    if (isEnableAttackPersonAttacked__10grYakumonoFUlUlUl(self, b, c, v + 8)) {
        fn_40_3D138(self);
    }
}
