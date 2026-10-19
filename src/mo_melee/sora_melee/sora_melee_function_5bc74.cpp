#include <so/so_world.h>
#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const float lbl_27_rodata_7C0;

extern "C" void fn_27_5BC74() {
    soWorld* world = (soWorld*)__nw__FUlQ25Heaps8HeapType(0x10, 2);
    if (world) {
        world->m_gravityUp = lbl_27_rodata_7C0;
        world->m_gravityDown = lbl_27_rodata_7C0;
        world->m_8 = lbl_27_rodata_7C0;
        world->m_12 = 0;
        world->m_13 = 1;
    }
    g_soWorld = world;
}
