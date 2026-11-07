#include <gf/gf_model.h>
#pragma force_active on

class Class_1DE0 {
public:
 virtual void fn_50_7C3C(); virtual void fn_50_705C(); virtual void fn_50_706C();
 virtual void fn_50_63A0(); virtual void fn_50_6114(); virtual void fn_50_5CA8();
 virtual void fn_50_7398(); virtual void fn_50_7454(); virtual void fn_50_7BF4();
 virtual void fn_50_707C(); virtual void fn_50_5DF8();
};
struct Object {
 char pad[0x44];
 nw4r::g3d::ScnMdl** models;
 gfModelAnimation** animations;
 char pad2[0x138];
 u8 current;
};
extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_50_rodata_100;
extern const float lbl_50_rodata_104;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
inline bool hasChr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* a, u32 i) { return i < a->m_resFile.GetResAnmClrNumEntries(); }
extern "C" void fn_50_96B0(Object* self, u8 index, bool loop, bool force, float* frameCount) {
 if (self->current == index && !force) return;
 nw4r::g3d::ScnMdl* model = *self->models;
 if (!model) return;
 gfModelAnimation* animation = *self->animations;
 if (!animation) return;
 nw4r::g3d::ResMdl resource = model->m_resMdl;
 if (!resource.IsValid()) return;
 animation->unbindNodeAnim(model);
 animation->unbindVisibleAnim(model);
 animation->unbindTexAnim(model);
 animation->unbindTexSrtAnim(model);
 animation->unbindMatColAnim(model);
 self->current = index;
 if (index >= 1u) return;
 if (hasChr(animation, index)) setChrAnim2(index, resource, animation, Heaps::StageInstance);
 if (hasVis(animation, index)) setVisibilityAnim2(index, resource, animation, Heaps::StageInstance);
 if (hasTexPat(animation, index)) setTexPatAnim2(index, resource, animation, Heaps::StageInstance);
 if (hasTexSrt(animation, index)) setTexSortAnim2(index, resource, animation, Heaps::StageInstance);
 if (hasClr(animation, index)) setColorAnim2(index, resource, animation, Heaps::StageInstance);
 gfModelAnimation::bind(model, animation);
 setFrame__16gfModelAnimationFd(animation, lbl_50_rodata_100);
 animation->setUpdateRate(lbl_50_rodata_104);
 setLoop__16gfModelAnimationFd(animation, loop);
 if (frameCount) *frameCount = getFrameCount__16gfModelAnimationFd(animation);
}