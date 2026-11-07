#include <gf/gf_error_manager.h>
#include <gf/gf_shutdown_manager.h>
#pragma force_active on

struct Lbl804953A0 { int unk0; int unk4; char unk8; };
extern Lbl804953A0 lbl_804953A0;
struct Self { char pad[0xf0]; int state; };
extern "C" void fn_80030FA4(Self*);
extern "C" void fn_8003186C(Self*);
extern "C" void fn_80032908(Self*);
extern "C" void fn_80032B64(Self*);

extern "C" void fn_80030808(Self* self) {
    bool shutdown = false;
    if (g_gfShutdownManager.m_reset || g_gfShutdownManager.m_powerOff || g_gfShutdownManager.m_returnToWiiMenu)
        shutdown = true;
    if (shutdown && gfErrorManager::getInstance() && gfErrorManager::getInstance()->m_isSuspended && !gfErrorManager::getInstance()->m_isFatal) {
        lbl_804953A0.unk8 = 1;
        g_gfShutdownManager.unkC = 1;
        return;
    }
    switch (self->state) {
    case 1:
        fn_80030FA4(self);
        break;
    case 2:
        fn_8003186C(self);
        if (self->state == 0) {
            lbl_804953A0.unk8 = 1;
            g_gfShutdownManager.unkC = 1;
        }
        break;
    case 3:
        fn_80032908(self);
        if (self->state == 0) {
            lbl_804953A0.unk8 = 1;
            g_gfShutdownManager.unkC = 1;
        }
        break;
    case 4:
        fn_80032B64(self);
        break;
    }
}