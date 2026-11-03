#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);
extern "C" void* fn_8018D6D8(void*, u32);
extern "C" void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern "C" const float lbl_56_rodata_40;

struct Object {
    char pad[0x164];
    nw4r::g3d::ScnMdl* scene;
    nw4r::g3d::ResMdl model;
    gfModelAnimation* animation;
};

extern "C" void fn_56_11CC(Object* self, u32 index) {
    if (self->animation) {
        gfModelAnimation::unbind(self->scene);
        u32 count = self->animation->m_resFile.GetResAnmChrNumEntries();
        if ((count << __cntlzw(count ^ index)) >> 31) {
            gfModelAnimation* animation = self->animation;
            nw4r::g3d::ResMdl model = self->model;
            if (index < animation->m_resFile.GetResAnmChrNumEntries()) {
                int size;
                nw4r::g3d::ResAnmChr anim(fn_8018D6D8(&animation->m_resFile, index));
                MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
                if (anim.IsValid()) {
                    nw4r::g3d::AnmObjChrRes* obj = nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, anim, model, false);
                    if (obj) {
                        obj->Bind(model);
                        if (animation->m_anmObjChrRes)
                            animation->m_anmObjChrRes->Destroy();
                        animation->m_anmObjChrRes = obj;
                    }
                }
            }
            gfModelAnimation::bind(self->scene, self->animation);
            setFrame__16gfModelAnimationFd(self->animation, lbl_56_rodata_40);
        }
    }
}