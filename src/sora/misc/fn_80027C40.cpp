#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" {
bool fn_8018E3C0(nw4r::g3d::ResFile* self, u32 value);
bool fn_8018E40C(nw4r::g3d::ResFile* self);
bool fn_8018E458(nw4r::g3d::ResFile* self);
bool fn_8018E4A4(nw4r::g3d::ResFile* self);
bool fn_8018E4F0(nw4r::g3d::ResFile* self);
bool fn_8018E53C(nw4r::g3d::ResFile* self);
void* fn_8018D6D8(nw4r::g3d::ResFile* res, u32 index);
void* fn_8018D8E0(nw4r::g3d::ResFile* res, u32 index);
void* fn_8018DCF0(nw4r::g3d::ResFile* res, u32 index);
void* fn_8018DEF8(nw4r::g3d::ResFile* res, u32 index);
void* fn_8018DAE8(nw4r::g3d::ResFile* res, u32 index);
void* fn_8018E100(nw4r::g3d::ResFile* res, u32 index);
nw4r::g3d::AnmObjShpRes* fn_8019BC04(MEMAllocator* allocator, int* size, nw4r::g3d::ResAnmShp anim, nw4r::g3d::ResMdl mdl, bool hasCache);

gfModelAnimation* __ct__16gfModelAnimationFd(gfModelAnimation* self, nw4r::g3d::ResFile* resFile, nw4r::g3d::ResMdl* resMdl, bool doBind, u32 animIndex, HeapType heapType)
{
    int size;
    *(u32*)self = 0;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heapType);
    u32 value = *(u32*)resFile;
    *(u32*)self = value;
    self->_spacer[0] = 1;
    self->m_anmObjChrRes = NULL;
    self->m_anmObjVisRes = NULL;
    self->m_anmObjTexPatRes = NULL;
    self->m_anmObjTexSrtRes = NULL;
    self->m_anmObjMatClrRes = NULL;
    self->m_anmObjShpRes = NULL;

    if (fn_8018E3C0(&self->m_resFile, value) && animIndex < self->m_resFile.GetResAnmChrNumEntries()) {
        self->m_anmObjChrRes = nw4r::g3d::AnmObjChrRes::Construct(allocator, &size, nw4r::g3d::ResAnmChr(fn_8018D6D8(resFile, animIndex)), *resMdl, false);
        if (doBind) {
            self->m_anmObjChrRes->Bind(*resMdl);
        }
    }
    if (fn_8018E40C(&self->m_resFile) && animIndex < self->m_resFile.GetResAnmVisNumEntries()) {
        self->m_anmObjVisRes = nw4r::g3d::AnmObjVisRes::Construct(allocator, &size, nw4r::g3d::ResAnmVis(fn_8018D8E0(resFile, animIndex)), *resMdl);
        if (doBind) {
            self->m_anmObjVisRes->Bind(*resMdl);
        }
    }
    if (fn_8018E4A4(&self->m_resFile) && animIndex < self->m_resFile.GetResAnmTexPatNumEntries()) {
        self->m_anmObjTexPatRes = nw4r::g3d::AnmObjTexPatRes::Construct(allocator, &size, nw4r::g3d::ResAnmTexPat(fn_8018DCF0(resFile, animIndex)), *resMdl, false);
        if (doBind) {
            self->m_anmObjTexPatRes->Bind(*resMdl);
        }
    }
    if (fn_8018E4F0(&self->m_resFile) && animIndex < self->m_resFile.GetResAnmTexSrtNumEntries()) {
        self->m_anmObjTexSrtRes = nw4r::g3d::AnmObjTexSrtRes::Construct(allocator, &size, nw4r::g3d::ResAnmTexSrt(fn_8018DEF8(resFile, animIndex)), *resMdl, false);
        if (doBind) {
            self->m_anmObjTexSrtRes->Bind(*resMdl);
        }
    }
    if (fn_8018E458(&self->m_resFile) && animIndex < self->m_resFile.GetResAnmClrNumEntries()) {
        self->m_anmObjMatClrRes = nw4r::g3d::AnmObjMatClrRes::Construct(allocator, &size, nw4r::g3d::ResAnmClr(fn_8018DAE8(resFile, animIndex)), *resMdl, false);
        if (doBind) {
            self->m_anmObjMatClrRes->Bind(*resMdl);
        }
    }
    if (fn_8018E53C(&self->m_resFile) && animIndex < self->m_resFile.GetResAnmShpNumEntries()) {
        self->m_anmObjShpRes = fn_8019BC04(allocator, &size, nw4r::g3d::ResAnmShp(fn_8018E100(resFile, animIndex)), *resMdl, false);
        if (doBind) {
            self->m_anmObjShpRes->Bind(*resMdl);
        }
    }
    return self;
}
}
