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
extern char lbl_41_data_D1BF[];
extern float lbl_41_rodata_F38;
extern "C" void fn_41_42268(wnemSimple* wn, Accesser* accesser) {
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_D1BF);
        wn->unk21B6 = true;
        wn->unk21B8 = false;
        wn->unk21BB = false;
        wn->unk21B9 = false;
        accesser->modules->obj->slot4();
        wn->executeAnimCmd(2);
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_F38;
        wn->setVisibilityWhole(0);
    }
    accesser->modules->obj->slot4();
    wn->RequestDeactive();
}