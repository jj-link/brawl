#include <gf/gf_model.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018D6D8(void*, u32);
extern "C" void setLoopNode__16gfModelAnimationFd(gfModelAnimation*, int);
extern "C" const float lbl_54_rodata_CC;
extern "C" const float lbl_54_rodata_E8;
struct StageObject {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad1[0x138];
    unsigned char currentAnimation;
};
inline void makeChrAnim(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    nw4r::g3d::ResAnmChr anim(fn_8018D6D8(&modelAnim->m_resFile, animId));
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    if (anim.IsValid()) {
        nw4r::g3d::AnmObjChrRes* anmObj = nw4r::g3d::AnmObjChrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != 0) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjChrRes != 0)
                modelAnim->m_anmObjChrRes->Destroy();
            modelAnim->m_anmObjChrRes = anmObj;
        }
    }
}
inline void changeChrAnim(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmChrNumEntries())
        makeChrAnim(animId, model, modelAnim, heap);
}
extern "C" void fn_54_BEA8(StageObject* self, u8 index, int loopNode, u32 force, float* frameCount) {
    if (self->currentAnimation != index || force != 0) {
        nw4r::g3d::ScnMdl* model = self->models[0];
        if (model != 0) {
            gfModelAnimation* animation = self->animations[0];
            if (animation != 0) {
                nw4r::g3d::ResMdl modelResource(*(void**)((char*)model + 0xE8));
                if (modelResource.IsValid()) {
                    animation->unbindNodeAnim(model);
                    self->currentAnimation = index;
                    if (index < 1) {
                        u32 entryCount = animation->m_resFile.GetResAnmChrNumEntries();
                        if (((entryCount << __cntlzw(entryCount ^ index)) >> 31) != 0) {
                            changeChrAnim(index, modelResource, animation, (Heaps::HeapType)15);
                        }
                        gfModelAnimation::bind(model, animation);
                        animation->m_anmObjChrRes->SetFrame(lbl_54_rodata_CC);
                        animation->m_anmObjChrRes->SetUpdateRate(lbl_54_rodata_E8);
                        setLoopNode__16gfModelAnimationFd(animation, loopNode);
                        if (frameCount != 0) {
                            nw4r::g3d::ResAnmChrData* data = *(nw4r::g3d::ResAnmChrData**)((char*)animation->m_anmObjChrRes + 0x2C);
                            *frameCount = (float)data->m_animLength;
                        }
                    }
                }
            }
        }
    }
}