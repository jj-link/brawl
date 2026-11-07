#include <cstring>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>

#pragma force_active on

extern "C" {
extern char lbl_8045C750[12];
extern char lbl_8059E500[4];
extern const float lbl_805A2728;
extern const float lbl_805A272C;
extern const float lbl_805A2730;
extern MuObject* lbl_805A0308;
extern nw4r::g3d::ScnMdl* lbl_805A030C;

void fn_800B753C(MuObject*, float);

void fn_800FD510(nw4r::g3d::ResFile* resFile) {
    char buf[64];
    u32 name = (u32)lbl_8045C750;

    lbl_805A0308 = MuObject::create(resFile, (const char*)name, 1, 0, Heaps::InfoInstance);
    strcpy(buf, (const char*)name);
    strcat(buf, lbl_8059E500);
    lbl_805A0308->changeAnimN(buf);
    lbl_805A0308->m_modelAnim->setUpdateRate(lbl_805A2728);

    float frame;
    if ((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1) {
        frame = lbl_805A272C;
    } else {
        frame = lbl_805A2730;
    }

    fn_800B753C(lbl_805A0308, frame);
    lbl_805A030C = nw4r::g3d::ScnMdl::Construct(
        gfHeapManager::getMEMAllocator(Heaps::InfoInstance), 0, 4,
        lbl_805A0308->m_sceneModel);
}
}
