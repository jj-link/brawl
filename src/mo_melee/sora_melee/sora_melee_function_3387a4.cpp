#include <types.h>
#pragma force_active on

struct fn27Obj {
    char pad[0x18];
    s32 m_18;
};

extern "C" void* fn_27_3387A4(fn27Obj* p1, u32 p2, s32 p3) {
    return *(void**)((char*)p1 + ((p3 - p1->m_18) << 2) + 0x30);
}
