#include <gf/gf_copyefb.h>
#pragma force_active on

GXTexObj* gfCopyEFBMgr::getCopyEFBTex(int index) {
    return &m_copyEFBs[index].m_gxTexObj;
}
