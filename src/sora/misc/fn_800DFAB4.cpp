#include <cstring>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8045A2D4[12];
extern char lbl_8045A2E0[12];
extern char lbl_8059E238[4];
extern const float lbl_805A23B0;
extern const float lbl_805A23B4;
extern MuObject* lbl_805A02D8;
extern nw4r::g3d::ScnMdl* lbl_805A02DC;
void fn_800B20B0(MuObject*, int);
void fn_800B21C4(MuObject*, int);
void fn_800B753C(MuObject*, float);
void* fn_8018D3F0(nw4r::g3d::ResFile*, const char*);
void fn_8002571C(void**);
void fn_800257A4(int, int);

void fn_800DFAB4(nw4r::g3d::ResFile* resFile, int frame) {
    char buf[64];
    u32 name = (u32)lbl_8045A2D4;
    lbl_805A02D8 = MuObject::create(resFile, (const char*)name, 1, 0, (HeapType)0x28);
    fn_800B20B0(lbl_805A02D8, 1);
    fn_800B21C4(lbl_805A02D8, 1);
    *(int*)((char*)lbl_805A02D8->m_sceneModel + 0x118) = 0;
    *(int*)((char*)lbl_805A02D8->m_sceneModel + 0x118) = 8;
    strcpy(buf, (const char*)name);
    strcat(buf, lbl_8059E238);
    lbl_805A02D8->changeAnimN(buf);
    lbl_805A02D8->m_modelAnim->setUpdateRate(lbl_805A23B0);
    float base;
    if ((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)
        base = lbl_805A23B4;
    else
        base = lbl_805A23B0;
    base += (float)frame;
    fn_800B753C(lbl_805A02D8, base);
    lbl_805A02DC = nw4r::g3d::ScnMdl::Construct(
        gfHeapManager::getMEMAllocator((HeapType)0x28), 0, 0x100, lbl_805A02D8->m_sceneModel);
    void* texture = fn_8018D3F0(resFile, lbl_8045A2E0);
    fn_8002571C(&texture);
    fn_800257A4(0x40, 0x40);
}
}
