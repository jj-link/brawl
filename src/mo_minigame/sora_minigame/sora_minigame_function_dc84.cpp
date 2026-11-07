#include <gf/gf_model.h>
#pragma force_active on
extern "C" {
void* fn_8018D174(void*, int);
void fn_801B0A28();
nw4r::g3d::ScnMdl* fn_801B0B40(MEMAllocator*, u32*, nw4r::g3d::ResMdl*, u32, int, void (*)());
gfModelAnimation* __ct__16gfModelAnimationFd(gfModelAnimation*, nw4r::g3d::ResFile*, nw4r::g3d::ResMdl*, bool, u32, Heaps::HeapType);
}
struct Object {
    char pad[0x38];
    nw4r::g3d::ScnMdl** scenes;
    gfModelAnimation** anims;
};
extern "C" void fn_20_DC84(Object* self, void* file, u32 index) {
    nw4r::g3d::ResMdl modelValue;
    gfModelAnimation* anim;
    nw4r::g3d::ScnMdl* scene;
    u32 size;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)42);
    nw4r::g3d::ResFile resFile(file);
    self->scenes = new ((Heaps::HeapType)42) nw4r::g3d::ScnMdl*;
    self->anims = new ((Heaps::HeapType)42) gfModelAnimation*;
    if (index >= 10) {
        modelValue = nw4r::g3d::ResMdl(fn_8018D174(&resFile, 3));
    } else if (index == 0) {
        modelValue = nw4r::g3d::ResMdl(fn_8018D174(&resFile, 0));
    } else {
        modelValue = nw4r::g3d::ResMdl(fn_8018D174(&resFile, 1));
    }
    nw4r::g3d::ResMdl model(modelValue);
    scene = fn_801B0B40(allocator, &size, &model, 0, 1, fn_801B0A28);
    anim = (gfModelAnimation*)operator new(0x20, (Heaps::HeapType)42);
    if (anim) {
        nw4r::g3d::ResMdl modelCopy(modelValue);
        nw4r::g3d::ResFile fileCopy = resFile;
        anim = __ct__16gfModelAnimationFd(anim, &fileCopy, &modelCopy, true, index % 10, (Heaps::HeapType)42);
    }
    anim->_spacer[0] = 0;
    gfModelAnimation::bind(scene, anim);
    self->scenes[0] = scene;
    self->anims[0] = anim;
}