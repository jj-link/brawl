#include <gr/ground.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void* gen, void* pos);

extern "C" void fn_77_20F8(char* self) {
    Vec3f sp;
    char* p = self + 0xd0;
    if (p != 0) {
        char* model = *(char**)(*(char**)(self + 0x44));
        if (model != 0) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(char**)(model + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(p + 0x4);
            }
            char* q = *(char**)(p + 0x4);
            *(float*)(q + 0x2c) = *(float*)(self + 0x164);
            *(float*)(q + 0x30) = *(float*)(self + 0x168);
            *(float*)(q + 0x34) = *(float*)(self + 0x16c);
            ((Ground*)self)->getNodePosition(&sp, 0, **(u32**)(p + 4));
            setPos__14snd3DGeneratorFP5Vec3f(self + 0x210, &sp);
        }
    }
}
