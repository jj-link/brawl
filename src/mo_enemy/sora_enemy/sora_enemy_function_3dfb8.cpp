#pragma force_active on
#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <so/ground/so_ground_module_impl.h>

namespace matching {
struct Task { char pad[0x2c]; unsigned int flags; };
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
    virtual void fn_41_135B0();
    virtual void fn_41_135A4();
    virtual void fn_41_135A0();
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual Task* slot12(int);
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
};
struct Modules {
    char pad0[0x10];
    soGroundModule* ground;
    char pad14[8];
    soAnimCmdEventObserver* attack;
    char pad20[0x34];
    void* link;
    char pad58[0xc];
    soNullable* work;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
}
extern "C" {
extern const float lbl_41_rodata_F10[];
extern char lbl_41_data_B481[];
extern char lbl_41_data_B4A9[];
extern char lbl_41_data_730[];
extern char lbl_41_data_14B8[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_41_5BB0(void*);
void fn_41_320F8(wnemSimple*, int, int, void*);
}
extern "C" void fn_41_3DFB8(wnemSimple* wn, matching::Accesser* acc) {
    const float* values = lbl_41_rodata_F10;
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_B481);
        wn->unk2200 = values[0];
        wn->unk2204 = values[1];
        wn->unk21F8 = values[0];
        wn->unk21FC = values[2];
        acc->modules->attack->slot4();
        wn->unk21B8 = false;
        wn->unk21BB = false;
        wn->unk21B6 = true;
        wn->setVisibilityWhole(0);
        int life = 8;
        s32* data = 0;
        if (wn->unk2234) data = wn->unk2234;
        if (data) {
            matching::Accesser* own = *(matching::Accesser**)((char*)wn + 0x6c);
            life = own->modules->work->slot4(0x10000005);
            matching::soNullable* link = (matching::soNullable*)__dynamic_cast(
                acc->modules->link, 0, lbl_41_data_730, lbl_41_data_14B8, 1);
            matching::Task* task = link->slot12(life);
            void* enemy = 0;
            if (task && ((int)((task->flags << 17) & 0xff800000) >> 24) == 2) {
                enemy = __dynamic_cast(task, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 0);
            }
            if (enemy && fn_41_5BB0(enemy)) {
                fn_41_320F8(wn, data[0], 0, data + 1);
            }
            life = data[11];
        }
        wn->SetLifeLimit(life);
        wnemCommonProc::Report(lbl_41_data_B4A9, life);
        wn->executeAnimCmd(0U);
        wn->executeAnimCmd(1U);
    }
    if (wn->getFrameCounter(1) >= 4U) {
        if (acc->modules->ground->isTouch((grCollStatus::TouchMask)0xff, 0)) {
            wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = values[0];
        }
    }
}
