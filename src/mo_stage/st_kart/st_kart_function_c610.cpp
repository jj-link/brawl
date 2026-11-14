#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on

extern "C" {
int __cntlzw(unsigned int);

void* fn_8018D6D8(void*, unsigned int);
void* fn_8018D8E0(void*, unsigned int);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, unsigned int);
void* fn_8018DCF0(void*, unsigned int);
void* fn_8018DEF8(void*, unsigned int);

void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);

extern const float lbl_49_rodata_138;
extern const float lbl_49_rodata_13C;
}

inline nw4r::g3d::ResAnmChr
nw4r::g3d::ResFile::GetResAnmChr(u32 i) {
    return ResAnmChr(fn_8018D6D8(this, i));
}

inline nw4r::g3d::ResAnmVis
nw4r::g3d::ResFile::GetResAnmVis(u32 i) {
    return ResAnmVis(fn_8018D8E0(this, i));
}

inline nw4r::g3d::ResAnmTexPat
nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) {
    return ResAnmTexPat(fn_8018DCF0(this, i));
}

inline nw4r::g3d::ResAnmTexSrt
nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) {
    return ResAnmTexSrt(fn_8018DEF8(this, i));
}

inline nw4r::g3d::ResAnmClr
nw4r::g3d::ResFile::GetResAnmClr(u32 i) {
    return fn_8018DAE8(this, i);
}

inline void makeChr(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmChrNumEntries())
        setChrAnim(i, model, a, heap);
}

inline void makeVis(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmVisNumEntries())
        setVisibilityAnim(i, model, a, heap);
}

inline void makeTexPat(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmTexPatNumEntries())
        setTexPatAnim(i, model, a, heap);
}

inline void makeTexSrt(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmTexSrtNumEntries())
        setTexSortAnim(i, model, a, heap);
}

inline void makeClr(u32 i, nw4r::g3d::ResMdl model, gfModelAnimation* a, Heaps::HeapType heap) {
    if (i < a->m_resFile.GetResAnmClrNumEntries())
        setColorAnim(i, model, a, heap);
}

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x168 - 0x4C];
    u8 current;
};

extern "C" void fn_49_C610(Object* self, u8 index, bool loop, bool force, f32* frameCount) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;

    nw4r::g3d::ResMdl modelRes = model->m_resMdl;
    if (!modelRes.IsValid())
        return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    animation->unbindTexAnim(model);
    animation->unbindTexSrtAnim(model);
    animation->unbindMatColAnim(model);
    self->current = index;

    if (index >= 1u)
        return;

    u32 count = animation->m_resFile.GetResAnmChrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        makeChr(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmVisNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        makeVis(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmTexPatNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        makeTexPat(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmTexSrtNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        makeTexSrt(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmClrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        makeClr(index, modelRes, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_49_rodata_138);
    animation->setUpdateRate(lbl_49_rodata_13C);
    setLoop__16gfModelAnimationFd(animation, loop);

    if (frameCount)
        *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}
