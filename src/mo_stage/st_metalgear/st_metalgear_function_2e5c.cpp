#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on
extern "C" {
int __cntlzw(unsigned int);
void* fn_8018D6D8(void*, u32);
nw4r::g3d::ResAnmVis fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_71_rodata_58;
extern const float lbl_71_rodata_5C;
extern const f64 lbl_71_rodata_60;
}
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }
struct StModelAnim { char pad0[0x44]; nw4r::g3d::ScnMdl** models; gfModelAnimation** anims; char pad1[0x187-0x4C]; u8 animIndex; char pad2[0x191-0x188]; bool loop; };
extern "C" void fn_71_2E5C(StModelAnim* self, u8 index, bool loop, bool force, float* frameOut) {
 nw4r::g3d::ScnMdl* model; gfModelAnimation* anim; nw4r::g3d::ResMdl modelRes;
 if(self->animIndex==index&&force==0)return;
 model=*self->models;if(!model)return; anim=*self->anims;if(!anim)return;
 modelRes=model->m_resMdl;if(!modelRes.IsValid())return;
 anim->unbindNodeAnim(model);anim->unbindVisibleAnim(model);anim->unbindTexAnim(model);anim->unbindTexSrtAnim(model);anim->unbindMatColAnim(model);
 self->animIndex=index;if(index>=0x80)return;
 {u32 c=anim->m_resFile.GetResAnmChrNumEntries();if((c<<__cntlzw(c^index))>>31)setChrAnim2(index,modelRes,anim,Heaps::StageInstance);}
 {u32 c=anim->m_resFile.GetResAnmTexPatNumEntries();if((c<<__cntlzw(c^index))>>31)setTexPatAnim2(index,modelRes,anim,Heaps::StageInstance);}
 {u32 c=anim->m_resFile.GetResAnmTexSrtNumEntries();if((c<<__cntlzw(c^index))>>31)setTexSortAnim2(index,modelRes,anim,Heaps::StageInstance);}
 {u32 c=anim->m_resFile.GetResAnmClrNumEntries();if((c<<__cntlzw(c^index))>>31)setColorAnim2(index,modelRes,anim,Heaps::StageInstance);}
 {u32 c=anim->m_resFile.GetResAnmVisNumEntries();if((c<<__cntlzw(c^index))>>31)setVisibilityAnim2(index,modelRes,anim,Heaps::StageInstance);}
 gfModelAnimation::bind(model,anim);setFrame__16gfModelAnimationFd(anim,lbl_71_rodata_58);anim->setUpdateRate(lbl_71_rodata_5C);setLoop__16gfModelAnimationFd(anim,loop);self->loop=loop;
 if(frameOut)*frameOut=getFrameCount__16gfModelAnimationFd(anim);
}