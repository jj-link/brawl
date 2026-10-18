#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_41_A2A4(void*, s32, u32, u32, soModuleAccesser*);

extern "C" const float lbl_41_rodata_11B0;
extern "C" const float lbl_41_rodata_11B4;

struct SoraLinkEvent : soLinkEventArgs {
    float a;
    float b;
    float c;

    SoraLinkEvent(int kind) : soLinkEventArgs(kind) {}
};

extern "C" void fn_41_67F74(void* self, s32 p1, u32 p2, u32 p3, soModuleAccesser* acc) {
    if (p1 == 0x2C) {
        if (acc->getLinkModule().isLinked(0) == true) {
            SoraLinkEvent ev(0x35);
            float f = lbl_41_rodata_11B0;
            ev.a = f;
            ev.b = f;
            ev.c = f;
            ev.a = soValueAccesser::getValueFloat(acc, 0xFAC, 0);
            ev.b = lbl_41_rodata_11B4;
            ev.c = soValueAccesser::getValueFloat(acc, 0xFAD, 0);
            acc->getLinkModule().sendEventNodes(0, ev, 0);
        }
    }
    fn_41_A2A4(self, p1, p2, p3, acc);
}
