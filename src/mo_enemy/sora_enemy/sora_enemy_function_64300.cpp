#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <types.h>

#pragma force_active on

extern char lbl_41_data_1C760[];
extern float lbl_41_rodata_1188;

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

struct S {
    s32 a;
    u8 b;
    s32 c;
};

extern "C" void fn_41_64300(wnemSimple* wn, int arg1) {
    s32* data = 0;
    if (wn->unk2234) data = wn->unk2234;

    bool enter = wn->unk2214;
    wn->unk2214 = false;
    if (enter) {
        wnemCommonProc::Report(lbl_41_data_1C760);
        wn->SetDeadMode();
        wn->setVisibilityWhole(0);

        if (data[1]) wn->executeAnimCmd(data[1], 4, 1);
        wn->executeAnimCmd(0);
        wn->executeAnimCmd(2);

        float f = lbl_41_rodata_1188;
        wn->unk2204 = f;
        wn->unk2200 = f;
        wn->unk21FC = f;
        wn->unk21F8 = f;

        S s;
        s.a = 0x13ff;
        s.b = 0;
        s.c = 3;

        char* q = (char*)(*(s32*)((char*)(arg1) + 0xd8));
        Class_6E20* obj3 = (Class_6E20*)(*(s32*)(q + 0x54));
        obj3->fn_41_350F8(3, &s.a);
    }

    if ((u32)wn->getFrameCounter(1) >= (u32)data[0]) {
        wn->RequestDeactive();
    }
}
