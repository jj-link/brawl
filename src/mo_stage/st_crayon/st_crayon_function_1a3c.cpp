#pragma force_active on
#include <gf/gf_model.h>
#include <types.h>

extern "C" {
void fn_56_106C(void*, float);
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
nw4r::g3d::ResAnmClr fn_8018DAE8(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
extern const float lbl_56_rodata_50;
}
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
virtual void processDefault();
virtual void processBegin();
virtual void processAnim();
virtual void processUpdate();
virtual void processPreMapCorrection();
virtual void processMapCorrection();
virtual void processFixPosition();
virtual void processPreCollision();
virtual void processCollision();
virtual void processCatch();
virtual void processHit();
virtual void processCamera();
virtual void processFixCamera();
virtual void processEffect();
virtual void processGameProc();
virtual void processEnd();
virtual void renderPre();
virtual void renderOpa();
virtual void renderXlu();
virtual void processDebug();
virtual void renderDebug();
virtual void init();
virtual void fn_56_19E4();
virtual void fn_56_1A3C();
virtual void loadGroundData();
virtual void bindData();
virtual void setupMelee();
virtual void setVisibility();
virtual void setVisibilityByClipping();
virtual void setVisibilityAttachedEffect();
virtual void receiveCollMsg();
virtual void receiveCollMsg_Landing();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual u32 getModelCount();
};
inline nw4r::g3d::ResAnmChr nw4r::g3d::ResFile::GetResAnmChr(u32 i) { return ResAnmChr(fn_8018D6D8(this, i)); }
inline nw4r::g3d::ResAnmVis nw4r::g3d::ResFile::GetResAnmVis(u32 i) { return ResAnmVis(fn_8018D8E0(this, i)); }
inline nw4r::g3d::ResAnmTexPat nw4r::g3d::ResFile::GetResAnmTexPat(u32 i) { return ResAnmTexPat(fn_8018DCF0(this, i)); }
inline nw4r::g3d::ResAnmTexSrt nw4r::g3d::ResFile::GetResAnmTexSrt(u32 i) { return ResAnmTexSrt(fn_8018DEF8(this, i)); }
inline nw4r::g3d::ResAnmClr nw4r::g3d::ResFile::GetResAnmClr(u32 i) { return fn_8018DAE8(this, i); }

inline bool hasChr(gfModelAnimation* anim, u32 index) { return index < anim->m_resFile.GetResAnmChrNumEntries(); }
inline bool hasVis(gfModelAnimation* anim, u32 index) { return index < anim->m_resFile.GetResAnmVisNumEntries(); }
inline bool hasTexPat(gfModelAnimation* anim, u32 index) { return index < anim->m_resFile.GetResAnmTexPatNumEntries(); }
inline bool hasTexSrt(gfModelAnimation* anim, u32 index) { return index < anim->m_resFile.GetResAnmTexSrtNumEntries(); }
inline bool hasClr(gfModelAnimation* anim, u32 index) { return index < anim->m_resFile.GetResAnmClrNumEntries(); }
extern "C" void fn_56_1A3C(Ground* self, float rate) {
fn_56_106C(self, rate);
if (lbl_56_rodata_50 != *(float*)((char*)self + 0x160)) return;
nw4r::g3d::ScnMdl* model;
gfModelAnimation* anim;
u32 offset;
u32 i = 0;
u32 count = self->getModelCount();
offset = 0;
for (; i != count; offset += 4, i++) {
model = *(nw4r::g3d::ScnMdl**)(*(char**)((char*)self + 0x44) + offset);
if (!model) return;
anim = *(gfModelAnimation**)(*(char**)((char*)self + 0x48) + offset);
if (!anim) return;
nw4r::g3d::ResMdl resMdl = model->m_resMdl;
if (!resMdl.IsValid()) return;
gfModelAnimation::unbind(model);
{
bool has = hasChr(anim, *(u8*)((char*)self + 0x15c));
if (has) setChrAnim2(*(u8*)((char*)self + 0x15c), resMdl, anim, Heaps::StageInstance);
}
{
bool has = hasVis(anim, *(u8*)((char*)self + 0x15c));
if (has) setVisibilityAnim2(*(u8*)((char*)self + 0x15c), resMdl, anim, Heaps::StageInstance);
}
{
bool has = hasTexPat(anim, *(u8*)((char*)self + 0x15c));
if (has) setTexPatAnim2(*(u8*)((char*)self + 0x15c), resMdl, anim, Heaps::StageInstance);
}
{
bool has = hasTexSrt(anim, *(u8*)((char*)self + 0x15c));
if (has) setTexSortAnim2(*(u8*)((char*)self + 0x15c), resMdl, anim, Heaps::StageInstance);
}
{
bool has = hasClr(anim, *(u8*)((char*)self + 0x15c));
if (has) setColorAnim2(*(u8*)((char*)self + 0x15c), resMdl, anim, Heaps::StageInstance);
}
gfModelAnimation::bind(model, anim);
setFrame__16gfModelAnimationFd(anim, *(float*)((char*)self + 0x160));
anim->setUpdateRate(rate);
}
}
