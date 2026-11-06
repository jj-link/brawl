#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual bool slot10(int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(s32, soLinkEventArgs&, u32);
};

extern "C" void fn_41_A2A4(void*, s32, u32, u32, soModuleAccesser*);
extern "C" const float lbl_41_rodata_11C0;
extern "C" const float lbl_41_rodata_11C4;

struct SoraLinkEvent : soLinkEventArgs {
    float a;
    float b;
    float c;

    SoraLinkEvent(int kind) : soLinkEventArgs(kind) {}
};

extern "C" void fn_41_6A3B4(void* self, s32 p1, u32 p2, u32 p3, soModuleAccesser* acc) {
    if (p1 == 0x28) {
        if (acc->getLinkModule().isLinked(0) == true) {
            SoraLinkEvent ev(0x35);
            float f = lbl_41_rodata_11C0;
            ev.a = f;
            ev.b = f;
            ev.c = f;
            ev.a = soValueAccesser::getValueFloat(acc, 0xFAB, 0);
            ev.b = lbl_41_rodata_11C4;
            ev.c = soValueAccesser::getValueFloat(acc, 0xFAC, 0);
            acc->getLinkModule().sendEventNodes(0, ev, 0);
        }
    }
    fn_41_A2A4(self, p1, p2, p3, acc);
}
