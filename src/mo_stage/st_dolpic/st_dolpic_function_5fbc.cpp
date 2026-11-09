#include <gf/gf_model.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018DAE8(void*, u32);
extern "C" void setLoopMatCol__16gfModelAnimationFd(gfModelAnimation*, int);
extern "C" const float lbl_46_rodata_110;
extern "C" const float lbl_46_rodata_118;
extern "C" const double lbl_46_rodata_128;
struct StageObject {
    char pad0[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad1[0x134];
    unsigned char currentAnimation;
};
inline void makeMatColAnim(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    int instanceSize;
    void* animData = fn_8018DAE8(&modelAnim->m_resFile, animId);
    if (animData != 0) {
        nw4r::g3d::ResAnmClr anim(animData);
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
        nw4r::g3d::AnmObjMatClrRes* anmObj = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &instanceSize, anim, model, false);
        if (anmObj != 0) {
            anmObj->Bind(model);
            if (modelAnim->m_anmObjMatClrRes != 0)
                modelAnim->m_anmObjMatClrRes->Destroy();
            modelAnim->m_anmObjMatClrRes = anmObj;
        }
    }
}
inline void changeMatColAnim(u8 animId, nw4r::g3d::ResMdl model, gfModelAnimation* modelAnim, Heaps::HeapType heap) {
    if (animId < modelAnim->m_resFile.GetResAnmClrNumEntries())
        makeMatColAnim(animId, model, modelAnim, heap);
}
extern "C" void fn_46_5FBC(StageObject* self, u8 index, int loop, u32 force, float* frameCount) {
    if (self->currentAnimation != index || force != 0) {
        nw4r::g3d::ScnMdl* model = self->models[0];
        if (model != 0) {
            gfModelAnimation* animation = self->animations[0];
            if (animation != 0) {
                nw4r::g3d::ResMdl modelResource(*(void**)((char*)model + 0xE8));
                if (modelResource.IsValid()) {
                    animation->unbindMatColAnim(model);
                    self->currentAnimation = index;
                    if (index < 1) {
                        u32 entryCount = animation->m_resFile.GetResAnmClrNumEntries();
                        if (((entryCount << __cntlzw(entryCount ^ index)) >> 31) != 0) {
                            changeMatColAnim(index, modelResource, animation, (Heaps::HeapType)15);
                        }
                        gfModelAnimation::bind(model, animation);
                        animation->m_anmObjMatClrRes->SetFrame(lbl_46_rodata_110);
                        animation->m_anmObjMatClrRes->SetUpdateRate(lbl_46_rodata_118);
                        setLoopMatCol__16gfModelAnimationFd(animation, loop);
                        if (frameCount != 0) {
                            nw4r::g3d::ResAnmClrData* data = *(nw4r::g3d::ResAnmClrData**)((char*)animation->m_anmObjMatClrRes + 0x2C);
                            *frameCount = (float)data->m_animLength;
                        }
                    }
                }
            }
        }
    }
}
