#include <gf/gf_model.h>
#pragma force_active on

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x118];
    u8 current;
};

extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018D6D8(void*, u32);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
extern "C" void setLoopTexSrt__16gfModelAnimationFd(gfModelAnimation*, bool);
extern "C" u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern "C" const float lbl_46_rodata_E0;
extern "C" const float lbl_46_rodata_E8;

extern "C" void fn_46_5178(Object* self, u32 index, bool loop, bool force, float* frames) {
    if (self->current != index || force) {
        nw4r::g3d::ScnMdl* mdl = *self->models;
        if (mdl) {
            gfModelAnimation* anim = *self->animations;
            if (anim) {
                nw4r::g3d::ResMdl res = *(nw4r::g3d::ResMdl*)((char*)mdl + 0xe8);
                if (res.IsValid()) {
                    anim->unbindNodeAnim(mdl);
                    self->current = index;
                    if (index < 16) {
                        u32 count = anim->m_resFile.GetResAnmChrNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31) {
                            if (index < anim->m_resFile.GetResAnmChrNumEntries()) {
                                nw4r::g3d::ResAnmChr chr(fn_8018D6D8(&anim->m_resFile, index));
                                MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
                                if (chr.IsValid()) {
                                    int size;
                                    nw4r::g3d::AnmObjChrRes* obj = nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, chr, res, false);
                                    if (obj) {
                                        obj->Bind(res);
                                        if (anim->m_anmObjChrRes)
                                            anim->m_anmObjChrRes->Destroy();
                                        anim->m_anmObjChrRes = obj;
                                    }
                                }
                            }
                        }
                        gfModelAnimation::bind(mdl, anim);
                        anim->m_anmObjChrRes->SetFrame(lbl_46_rodata_E0);
                        anim->setUpdateRate(lbl_46_rodata_E8);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        setLoopTexSrt__16gfModelAnimationFd(anim, true);
                        if (frames)
                            *frames = getFrameCount__16gfModelAnimationFd(anim);
                    }
                }
            }
        }
    }
}