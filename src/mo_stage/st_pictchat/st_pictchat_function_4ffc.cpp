#include <gf/gf_model.h>
#pragma force_active on
using namespace nw4r::g3d;
class Class_3E50 { public:
virtual void fn_73_C58C();
virtual void fn_73_B9AC();
virtual void fn_73_B9BC();
virtual void fn_73_A9C8();
virtual void fn_73_A784();
virtual void fn_73_9D10();
virtual void fn_73_BCE8();
virtual void fn_73_BDA4();
virtual void fn_73_C544();
virtual void fn_73_B9CC();
virtual void fn_73_A168();
};
class Class_3F48 { public:
virtual void fn_73_C58C();
virtual void fn_73_B9AC();
virtual void fn_73_B9BC();
virtual void fn_73_AA60();
virtual void fn_73_A784();
virtual void fn_73_9DA8();
virtual void fn_73_BCE8();
virtual void fn_73_BDA4();
virtual void fn_73_C544();
virtual void fn_73_B9CC();
virtual void fn_73_A168();
};
class Class_4040 { public:
virtual void fn_73_C58C();
virtual void fn_73_B9AC();
virtual void fn_73_B9BC();
virtual void fn_73_AAF8();
virtual void fn_73_A784();
virtual void fn_73_9E40();
virtual void fn_73_BCE8();
virtual void fn_73_BDA4();
virtual void fn_73_C544();
virtual void fn_73_B9CC();
virtual void fn_73_A168();
};
class Class_4138 { public:
virtual void fn_73_C58C();
virtual void fn_73_B9AC();
virtual void fn_73_B9BC();
virtual void fn_73_AB90();
virtual void fn_73_A784();
virtual void fn_73_9ED8();
virtual void fn_73_BCE8();
virtual void fn_73_BDA4();
virtual void fn_73_C544();
virtual void fn_73_B9CC();
virtual void fn_73_A168();
};
class Class_4400 { public:
virtual void fn_73_C58C();
virtual void fn_73_B9AC();
virtual void fn_73_B9BC();
virtual void fn_73_ACF0();
virtual void fn_73_A784();
virtual void fn_73_9FD8();
virtual void fn_73_BCE8();
virtual void fn_73_BDA4();
virtual void fn_73_C544();
virtual void fn_73_B9CC();
virtual void fn_73_A168();
};
struct Object { char pad[0x44]; ScnMdl** models; gfModelAnimation** animations; char pad2[0x23c]; u8 current; };
extern "C" {
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void* fn_8018DAE8(void*, u32);
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void setLoop__16gfModelAnimationFd(gfModelAnimation*, bool);
u32 getFrameCount__16gfModelAnimationFd(gfModelAnimation*);
extern const float lbl_73_rodata_78;
extern const float lbl_73_rodata_88;
}
inline void doChr(u32 index, ResMdl res, gfModelAnimation* anim) {
int size;
ResAnmChr resource(fn_8018D6D8(anim, index));
MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
if (resource.IsValid()) {

AnmObjChrRes* result = AnmObjChrRes::Construct(alloc, &size, resource, res, false);
if (result) { result->Bind(res); if (anim->m_anmObjChrRes) anim->m_anmObjChrRes->Destroy(); anim->m_anmObjChrRes = result; }
}
}
inline void applyChr(u32 index, ResMdl res, gfModelAnimation* anim) {
if (index < anim->m_resFile.GetResAnmChrNumEntries()) doChr(index, res, anim);
}
inline void doVis(u32 index, ResMdl res, gfModelAnimation* anim) {
int size;
ResAnmVis resource(fn_8018D8E0(anim, index));
MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
if (resource.IsValid()) {

AnmObjVisRes* result = AnmObjVisRes::Construct(alloc, &size, resource, res);
if (result) { result->Bind(res); if (anim->m_anmObjVisRes) anim->m_anmObjVisRes->Destroy(); anim->m_anmObjVisRes = result; }
}
}
inline void applyVis(u32 index, ResMdl res, gfModelAnimation* anim) {
if (index < anim->m_resFile.GetResAnmVisNumEntries()) doVis(index, res, anim);
}
inline void doTexPat(u32 index, ResMdl res, gfModelAnimation* anim) {
int size;
ResAnmTexPat resource(fn_8018DCF0(anim, index));

if (resource.IsValid()) {
MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
AnmObjTexPatRes* result = AnmObjTexPatRes::Construct(alloc, &size, resource, res, false);
if (result) { result->Bind(res); if (anim->m_anmObjTexPatRes) anim->m_anmObjTexPatRes->Destroy(); anim->m_anmObjTexPatRes = result; }
}
}
inline void applyTexPat(u32 index, ResMdl res, gfModelAnimation* anim) {
if (index < anim->m_resFile.GetResAnmTexPatNumEntries()) doTexPat(index, res, anim);
}
inline void doTexSrt(u32 index, ResMdl res, gfModelAnimation* anim) {
int size;
ResAnmTexSrt resource(fn_8018DEF8(anim, index));

if (resource.IsValid()) {
MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
AnmObjTexSrtRes* result = AnmObjTexSrtRes::Construct(alloc, &size, resource, res, false);
if (result) { result->Bind(res); if (anim->m_anmObjTexSrtRes) anim->m_anmObjTexSrtRes->Destroy(); anim->m_anmObjTexSrtRes = result; }
}
}
inline void applyTexSrt(u32 index, ResMdl res, gfModelAnimation* anim) {
if (index < anim->m_resFile.GetResAnmTexSrtNumEntries()) doTexSrt(index, res, anim);
}
inline void doClr(u32& index, ResMdl res, gfModelAnimation* anim) {
int size;
index = (u32)fn_8018DAE8(anim, index);
ResAnmClr resource((void*)index);

if (resource.IsValid()) {
MEMAllocator* alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)15);
AnmObjMatClrRes* result = AnmObjMatClrRes::Construct(alloc, &size, resource, res, false);
if (result) { result->Bind(res); if (anim->m_anmObjMatClrRes) anim->m_anmObjMatClrRes->Destroy(); anim->m_anmObjMatClrRes = result; }
}
}
inline void applyClr(u32& index, ResMdl res, gfModelAnimation* anim) {
if (index < anim->m_resFile.GetResAnmClrNumEntries()) doClr(index, res, anim);
}
extern "C" void fn_73_4FFC(Object* self, u32 index, bool loop, int force, float* frames) {
if (self->current != index || force) {
ScnMdl* mdl = *self->models;
if (mdl) {
gfModelAnimation* anim = *self->animations;
if (anim) {
ResMdl res = *(ResMdl*)((char*)mdl + 0xe8);
if (res.IsValid()) {
anim->unbindNodeAnim(mdl);
anim->unbindVisibleAnim(mdl);
anim->unbindTexAnim(mdl);
anim->unbindTexSrtAnim(mdl);
anim->unbindMatColAnim(mdl);
self->current = index;
if (index < 3) {
{ u32 count = anim->m_resFile.GetResAnmChrNumEntries(); if ((count << __cntlzw(count ^ index)) >> 31) { applyChr(index, res, anim); } }
{ u32 count = anim->m_resFile.GetResAnmVisNumEntries(); if ((count << __cntlzw(count ^ index)) >> 31) { applyVis(index, res, anim); } }
{ u32 count = anim->m_resFile.GetResAnmTexPatNumEntries(); if ((count << __cntlzw(count ^ index)) >> 31) { applyTexPat(index, res, anim); } }
{ u32 count = anim->m_resFile.GetResAnmTexSrtNumEntries(); if ((count << __cntlzw(count ^ index)) >> 31) { applyTexSrt(index, res, anim); } }
{ u32 count = anim->m_resFile.GetResAnmClrNumEntries(); if ((count << __cntlzw(count ^ index)) >> 31) { applyClr(index, res, anim); } }
gfModelAnimation::bind(mdl, anim);
setFrame__16gfModelAnimationFd(anim, lbl_73_rodata_78);
anim->setUpdateRate(lbl_73_rodata_88);
setLoop__16gfModelAnimationFd(anim, loop);
if (frames) *frames = getFrameCount__16gfModelAnimationFd(anim);
}
}
}
}
}
}