#include <gf/gf_model.h>
#include <types.h>
#pragma force_active on

class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual void fn_70_AB0C();
    virtual void fn_70_AB1C();
    virtual void fn_70_9164();
    virtual void fn_70_8EEC();
    virtual void fn_70_8A50();
    virtual void fn_70_AE10();
    virtual void fn_70_AECC();
    virtual void fn_70_B5FC();
    virtual void fn_70_AB2C();
    virtual void fn_70_8C08();
};

struct Object {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x1BC - 0x4C];
    u8 current;
    char pad3[7];
    u8 flag;
};

extern "C" int __cntlzw(unsigned int);

extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, int);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_70_rodata_48;
extern const float lbl_70_rodata_B4;
extern const double lbl_70_rodata_B8;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

extern "C" void fn_70_3F00(Object* self, u8 index, int loop, int force, float* endFrame) {
    if (self->current == index && !force)
        return;

    nw4r::g3d::ScnMdl* model = *self->models;
    if (!model)
        return;

    gfModelAnimation* animation = *self->animations;
    if (!animation)
        return;

    nw4r::g3d::ResMdl resource = model->m_resMdl;
    if (!resource.IsValid())
        return;

    animation->unbindNodeAnim(model);
    animation->unbindVisibleAnim(model);
    animation->unbindTexAnim(model);
    animation->unbindTexSrtAnim(model);
    animation->unbindMatColAnim(model);
    self->current = index;
    if (index >= 5u)
        return;

    u32 count;
    count = animation->m_resFile.GetResAnmVisNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setVisibilityAnim2(index, resource, animation, (Heaps::HeapType)15);

    count = animation->m_resFile.GetResAnmChrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setChrAnim2(index, resource, animation, (Heaps::HeapType)15);

    count = animation->m_resFile.GetResAnmTexPatNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setTexPatAnim2(index, resource, animation, (Heaps::HeapType)15);

    count = animation->m_resFile.GetResAnmTexSrtNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setTexSortAnim2(index, resource, animation, (Heaps::HeapType)15);

    count = animation->m_resFile.GetResAnmClrNumEntries();
    if ((count << __cntlzw(count ^ index)) >> 31)
        setColorAnim2(index, resource, animation, (Heaps::HeapType)15);

    gfModelAnimation::bind(model, animation);
    setFrame__16gfModelAnimationFd(animation, lbl_70_rodata_48);
    animation->setUpdateRate(lbl_70_rodata_B4);
    setLoop__16gfModelAnimationFd(animation, loop);
    if (endFrame) {
        *endFrame = getFrameCount__16gfModelAnimationFd(animation);
    }
    self->flag = 0;
}