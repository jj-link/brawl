#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#pragma force_active on

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
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8(s32, s32*);
};

struct Holder {
    char pad[0x54];
    Class_6E20* obj;
};

struct Accesser {
    char pad[0xd8];
    Holder* holder;
};

struct Args {
    s32 a;
    u8 b;
    s32 c;
};

extern char lbl_41_data_1C78E[];
extern float lbl_41_rodata_1188;

extern "C" void fn_41_64430(wnemSimple* wn, Accesser* accesser) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_1C78E);
        wn->SetDeadMode();
        wn->setVisibilityWhole(0);

        if (data[1]) {
            wn->executeAnimCmd(data[1], 4, 1);
        }
        wn->executeAnimCmd(7);
        wn->executeAnimCmd(2);
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_1188;

        Args args;
        args.a = 0x13ff;
        args.b = 0;
        args.c = 3;
        accesser->holder->obj->fn_41_350F8(3, (s32*)&args);
    }

    if (wn->getFrameCounter(1) >= (u32)data[0]) {
        wn->RequestDeactive();
    }
}