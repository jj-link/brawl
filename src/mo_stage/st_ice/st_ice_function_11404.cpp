#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on

struct IceObject {
    char pad[0x44];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad2[0x13e];
    u8 current;
};

extern "C" {
int __cntlzw(unsigned int);

void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);

void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, int);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_62_rodata_1F0;
extern const float lbl_62_rodata_200;
extern const double lbl_62_rodata_270;
}

inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return nw4r::g3d::ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return nw4r::g3d::ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return nw4r::g3d::ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return nw4r::g3d::ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

extern "C" void fn_62_11404(IceObject* self, u8 index, int loop, int force, float* frameCount) {
    if (self->current != index || force) {
        nw4r::g3d::ScnMdl* mdl = *self->models;
        if (mdl) {
            gfModelAnimation* anim = *self->animations;
            if (anim) {
                nw4r::g3d::ResMdl model = *(nw4r::g3d::ResMdl*)((char*)mdl + 0xe8);
                if (model.IsValid()) {
                    anim->unbindNodeAnim(mdl);
                    anim->unbindVisibleAnim(mdl);
                    anim->unbindTexAnim(mdl);
                    anim->unbindTexSrtAnim(mdl);
                    anim->unbindMatColAnim(mdl);
                    self->current = index;
                    if (index < 5) {
                        u32 count;
                        count = anim->m_resFile.GetResAnmVisNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            setVisibilityAnim2(index, model, anim, Heaps::StageInstance);
                        count = anim->m_resFile.GetResAnmChrNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            setChrAnim2(index, model, anim, Heaps::StageInstance);
                        count = anim->m_resFile.GetResAnmTexPatNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            setTexPatAnim2(index, model, anim, Heaps::StageInstance);
                        count = anim->m_resFile.GetResAnmTexSrtNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            setTexSortAnim2(index, model, anim, Heaps::StageInstance);
                        count = anim->m_resFile.GetResAnmClrNumEntries();
                        if ((count << __cntlzw(count ^ index)) >> 31)
                            setColorAnim2(index, model, anim, Heaps::StageInstance);
                        gfModelAnimation::bind(mdl, anim);
                        setFrame__16gfModelAnimationFd(anim, lbl_62_rodata_1F0);
                        anim->setUpdateRate(lbl_62_rodata_200);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        if (frameCount)
                            *frameCount = getFrameCount__16gfModelAnimationFd(anim);
                    }
                }
            }
        }
    }
}