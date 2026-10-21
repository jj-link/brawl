// gf/gf_copyefb.cpp
// gfCopyEFBMgr::getInstance (void)

#include <gf/gf_copyefb.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0070;
}

gfCopyEFBMgr* gfCopyEFBMgr::getInstance() {
    return reinterpret_cast<gfCopyEFBMgr*>(lbl_805A0070);
}
