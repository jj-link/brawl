#include <gf/gf_model.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
};
struct Object { char pad[0x44]; nw4r::g3d::ScnMdl** models; gfModelAnimation** animations; char pad4c[0x148]; u8 current; };
extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_51_rodata_1A8;
extern const float lbl_51_rodata_1AC;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this,i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this,i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this,i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this,i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this,i); }
inline bool hasChr(gfModelAnimation* a,u32 i) { return i < a->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* a,u32 i) { return i < a->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasPat(gfModelAnimation* a,u32 i) { return i < a->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasSrt(gfModelAnimation* a,u32 i) { return i < a->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* a,u32 i) { return i < a->m_resFile.GetResAnmClrNumEntries(); }
extern "C" void fn_51_10AF8(Object* self, u8 index, bool loop, bool force, float* out) {
 if (self->current == index && !force) return;
 nw4r::g3d::ScnMdl* model = *self->models;
 if (!model) return;
 gfModelAnimation* a = *self->animations;
 if (!a) return;
 nw4r::g3d::ResMdl res = model->m_resMdl;
 if (!res.IsValid()) return;
 a->unbindNodeAnim(model);
 a->unbindVisibleAnim(model);
 a->unbindTexAnim(model);
 a->unbindTexSrtAnim(model);
 a->unbindMatColAnim(model);
 self->current = index;
 if (index >= 1u) return;
 if (hasChr(a,index)) setChrAnim2(index,res,a,Heaps::StageInstance);
 if (hasVis(a,index)) setVisibilityAnim2(index,res,a,Heaps::StageInstance);
 if (hasPat(a,index)) setTexPatAnim2(index,res,a,Heaps::StageInstance);
 if (hasSrt(a,index)) setTexSortAnim2(index,res,a,Heaps::StageInstance);
 if (hasClr(a,index)) setColorAnim2(index,res,a,Heaps::StageInstance);
 gfModelAnimation::bind(model,a);
 setFrame__16gfModelAnimationFd(a,lbl_51_rodata_1A8);
 a->setUpdateRate(lbl_51_rodata_1AC);
 setLoop__16gfModelAnimationFd(a,loop);
 if (out) *out = getFrameCount__16gfModelAnimationFd(a);
}