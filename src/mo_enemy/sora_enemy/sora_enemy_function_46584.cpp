#include <em/wnem/wnem_proc_common.h>
#include <types.h>
#include <wn/wn_em_simple.h>
#pragma force_active on

#define VU(n) \
    virtual void u##n##a(); \
    virtual void u##n##b(); \
    virtual void u##n##c(); \
    virtual void u##n##d(); \
    virtual void u##n##e(); \
    virtual void u##n##f(); \
    virtual void u##n##g(); \
    virtual void u##n##h(); \
    virtual void u##n##i(); \
    virtual void u##n##j();

class VPart48 {
    char pad[0x3C];
    VU(0)
    VU(1)
    VU(2)
    VU(3)
    VU(4)
    VU(5)
    VU(6)
    VU(7)
    VU(8)
    VU(9)
public:
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void callback(s32 a, s32 b);
};
#undef VU

extern "C" {
extern char lbl_41_data_E944[];

void fn_41_46584(wnemSimple* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }
    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        wnemCommonProc::Report(lbl_41_data_E944);
        wn->setProcFnc_LifeZero(0x18);
        wn->setProcFnc_HitShell(0x18);
        reinterpret_cast<VPart48*>((char*)wn + 0xC)->callback(0, 1);
    }
    if (data[13] != 0) {
        wn->executeAnimCmd(data[13], 2, 1);
    }
    if (wn->getFrameCounter(1) >= (u32)data[9]) {
        wn->changeProcFnc(0x17, 1);
    }
}
}
