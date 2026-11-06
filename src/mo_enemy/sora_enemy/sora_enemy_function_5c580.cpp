#include <wn/wn_em_simple.h>
#include <types.h>
#pragma force_active on

#define VIRTUAL_SLOTS(n) \
    virtual void unused##n##a(); \
    virtual void unused##n##b(); \
    virtual void unused##n##c(); \
    virtual void unused##n##d(); \
    virtual void unused##n##e(); \
    virtual void unused##n##f(); \
    virtual void unused##n##g(); \
    virtual void unused##n##h(); \
    virtual void unused##n##i(); \
    virtual void unused##n##j();

class VirtualPart48 {
    char pad[0x3C];

public:
    VIRTUAL_SLOTS(0)
    VIRTUAL_SLOTS(1)
    VIRTUAL_SLOTS(2)
    VIRTUAL_SLOTS(3)
    VIRTUAL_SLOTS(4)
    VIRTUAL_SLOTS(5)
    VIRTUAL_SLOTS(6)
    VIRTUAL_SLOTS(7)
    VIRTUAL_SLOTS(8)
    VIRTUAL_SLOTS(9)
    VIRTUAL_SLOTS(10)
    virtual void callback(int);
};

#undef VIRTUAL_SLOTS

extern "C" {
extern const float lbl_41_rodata_1138;

void fn_41_5C580(wnemSimple* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        wn->SetDeadMode();
        reinterpret_cast<VirtualPart48*>((char*)wn + 0xC)->callback(0);
        if (data[1]) {
            wn->executeAnimCmd(data[1], 4, 1);
        }
        wn->executeAnimCmd(0U);
        wn->unk2204 = lbl_41_rodata_1138;
        wn->unk2200 = lbl_41_rodata_1138;
        wn->unk21FC = lbl_41_rodata_1138;
        wn->unk21F8 = lbl_41_rodata_1138;
    }
    if (wn->getFrameCounter(1) >= (u32)data[0]) {
        wn->RequestDeactive();
    }
}
}
