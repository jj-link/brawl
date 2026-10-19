#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" void fn_8005F794(ecMgr* mgr, int arg);

extern "C" void fn_27_98158() {
    u32 group;
    g_ecMgr->pushsetCurrentGroup(group);
    fn_8005F794(g_ecMgr, 1);
}
