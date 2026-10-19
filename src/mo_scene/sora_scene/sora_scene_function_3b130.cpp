#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();

struct Obj {
    u8 data[0x11];
};

extern "C" void fn_1_3B130(Obj* self) {
    u32 value = *(u32*)((char*)getInstance__14gfSceneManagerFv() + 0x31c);
    *(u8*)((char*)self + 0x11) = (u8)value;
    *(u32*)((char*)self + 8) = 0;
}
