#include <ec/ec_mgr.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_9A11C(void* p, u32 a, Vec3f* b) {
    g_ecMgr->setPos(a, b);
}
