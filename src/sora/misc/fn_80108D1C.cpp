#include <cstring>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8045D1EC[0xF];
extern char lbl_8059E618[4];
extern const float lbl_805A2820;
extern const float lbl_805A2824;
extern MuObject* lbl_805A0330;
extern nw4r::g3d::ScnMdl* lbl_805A0334;

void fn_80108D1C(nw4r::g3d::ResFile* resFile) {
    char buf[64];
    u32 name = (u32)lbl_8045D1EC;

    lbl_805A0330 = MuObject::create(resFile, (const char*)name, 0x10, 0, Heaps::InfoInstance);
    strcpy(buf, (const char*)name);
    strcat(buf, lbl_8059E618);
    lbl_805A0330->changeAnimN(buf);
    lbl_805A0330->m_modelAnim->setUpdateRate(lbl_805A2820);
    if (!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
        lbl_805A0330->setFrameNode(lbl_805A2820);
    } else {
        lbl_805A0330->setFrameNode(lbl_805A2824);
    }
    lbl_805A0334 = nw4r::g3d::ScnMdl::Construct(
        gfHeapManager::getMEMAllocator(Heaps::InfoInstance), 0, 0x20, lbl_805A0330->m_sceneModel);
}
}
