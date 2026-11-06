#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <so/ground/so_ground_module_impl.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, s32*);
};

struct Modules {
    char pad0[0x10];
    soGroundModule* ground;
    Object_vptr_0* situation;
    char pad18[4];
    Object_vptr_0* collision;
    char pad20[0x34];
    Object_vptr_0* link;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Args {
    s32 a;
    u8 b;
    s32 c;
};

extern char lbl_41_data_ED0D[];

extern "C" void fn_41_48204(wnemSimple* wn, Accesser* accesser) {
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_ED0D);
        accesser->modules->collision->slot4();
        accesser->modules->situation->slot6(2, 1);

        u8* data = 0;
        if (wn->unk2234) {
            data = (u8*)wn->unk2234;
        }

        if ((u8)accesser->modules->ground->getCorrect(0) != 0 && data[0] == 1) {
            accesser->modules->ground->setCorrect(soGroundShapeImpl::Correct_Air_Passable, 0);
        }

        wn->setProcFnc_TouchGround(-1);

        Args args;
        args.a = 0x1403;
        args.b = 0;
        args.c = 3;
        accesser->modules->link->slot15(3, &args.a);
    }
}
