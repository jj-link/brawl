#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <types.h>
#pragma force_active on

extern char lbl_41_data_E8D8[];
extern float lbl_41_rodata_FD8;

#define VS(n) \
    virtual void v##n##a(); \
    virtual void v##n##b(); \
    virtual void v##n##c(); \
    virtual void v##n##d(); \
    virtual void v##n##e(); \
    virtual void v##n##f(); \
    virtual void v##n##g(); \
    virtual void v##n##h(); \
    virtual void v##n##i(); \
    virtual void v##n##j();

class Pad38 {
    char data[0x38];
};

class VMethod {
public:
    VS(0)
    VS(1)
    VS(2)
    VS(3)
    VS(4)
    VS(5)
    VS(6)
    VS(7)
    VS(8)
    VS(9)
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
    virtual void v10g();
    virtual void v10h();
};

class CObj : public Pad38, public VMethod {
public:
    virtual void m111(s32);
};

class Obj5 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

struct Holder {
    char pad[0x1c];
    Obj5* obj;
};

struct Accesser {
    char pad[0xd8];
    Holder* holder;
};

extern "C" void fn_41_45D84(wnemSimple* wn, Accesser* accesser) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E8D8);
        wn->SetDeadMode();
        wn->executeAnimCmd(0);
        wn->executeAnimCmd(3);
        if (data[11]) {
            wn->executeAnimCmd(data[11], 4, 1);
        }
        wn->unk21F8 = wn->unk21FC = wn->unk2200 = wn->unk2204 = lbl_41_rodata_FD8;
        CObj* obj = (CObj*)((char*)wn + 0xc);
        obj->m111(0);
    }

    if (wn->getFrameCounter(1) >= (u32)data[0]) {
        accesser->holder->obj->m4();
        wn->RequestDeactive();
    }
}