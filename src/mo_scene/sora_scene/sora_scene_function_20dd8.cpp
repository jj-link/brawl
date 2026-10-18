#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" void fn_1_20DD8(void* self) {
    s32* p = (s32*)self;
    getInstance__14gfSceneManagerFv();
    p[2] = 9;
    p[4] = -1;
    p[3] = -1;
}
