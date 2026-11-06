#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

struct Modules {
    char pad[0x1c];
    Object_vptr_0* obj;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern char lbl_41_data_E778[];
extern float lbl_41_rodata_FB8;

extern "C" void fn_41_456F4(wnemSimple* wn, Accesser* acc) {
    char* strings = lbl_41_data_E778;
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(strings + 0x6c);
        wn->SetDeadMode();
        acc->modules->obj->slot4();
        wn->unk21B6 = true;
        wn->executeAnimCmd(1U);
        wn->executeAnimCmd(2U);
        if (data[7]) {
            wnemCommonProc::Report(strings + 0x8e);
            wn->executeAnimCmd(data[7], 4, 1);
        }
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_FB8;
        wn->setVisibilityWhole(0);
    }
    if (wn->getFrameCounter(1) >= (u32)data[5]) {
        wnemCommonProc::Report(strings + 0xd2);
        acc->modules->obj->slot4();
        wn->RequestDeactive();
    }
}
