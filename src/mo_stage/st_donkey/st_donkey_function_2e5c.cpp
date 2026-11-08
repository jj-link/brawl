#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>

#pragma force_active on

class Class_1DE0 {
public:
    virtual void fn_50_7C3C();
    virtual void fn_50_705C();
    virtual void fn_50_706C();
    virtual void fn_50_63A0();
    virtual void fn_50_6114();
    virtual void fn_50_5CA8();
    virtual void fn_50_7398();
    virtual void fn_50_7454();
    virtual void fn_50_7BF4();
    virtual void fn_50_707C();
    virtual void fn_50_5DF8();
};

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

extern const float lbl_50_rodata_68;
extern const float lbl_50_rodata_6C;
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

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x164 - 0x4C];
    u8 current;
};

extern "C" void fn_50_2E5C(
    Object* self, u8 index, bool loop, bool force, float* frameCount
) {
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

    if (index >= 5)
        return;

    u32 count = animation->m_resFile.GetResAnmChrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setChrAnim2(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmVisNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setVisibilityAnim2(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmTexPatNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setTexPatAnim2(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmTexSrtNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setTexSortAnim2(index, modelRes, animation, Heaps::StageInstance);

    count = animation->m_resFile.GetResAnmClrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setColorAnim2(index, modelRes, animation, Heaps::StageInstance);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_50_rodata_68);
    animation->setUpdateRate(lbl_50_rodata_6C);
    setLoop__16gfModelAnimationFd(animation, loop);

    if (frameCount)
        *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}
