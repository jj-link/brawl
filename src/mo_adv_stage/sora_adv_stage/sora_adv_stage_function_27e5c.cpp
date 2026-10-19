#include <ec/ec_mgr.h>
#pragma force_active on

struct FinalEffObj {
    u8 pad0[0x154];
    u32 effHandle;
    u8 pad1[0x0C];
    EfID effId;
};

extern "C" void fn_40_27E5C(FinalEffObj* self, EfID effId) {
    self->effId = effId;
    self->effHandle = g_ecMgr->setEffect(effId);
}
