#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" void fn_27_260604(void*, unsigned int, int);

struct Obj {
    u8 pad[0x6c];
    u8 upper : 1;
    u8 active : 1;
    u8 lower : 6;
    u8 pad2[0xe7];
    u32 handle;
    u8 pad3[0xc];
    EfID effect;
};

extern "C" void fn_40_27F70(Obj* self, int flag) {
    fn_27_260604(self, flag, 0);
    if (flag != 0 && !self->active) {
        if (self->effect != 0) {
            self->handle = g_ecMgr->setEffect(self->effect);
        }
    } else if (flag == 0 && self->active) {
        if (self->handle != 0) {
            g_ecMgr->endEffect(self->handle);
        }
    }
    self->active = flag;
}