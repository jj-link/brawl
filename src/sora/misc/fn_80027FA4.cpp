#include <gf/gf_model.h>
#include <types.h>
#pragma force_active on
using namespace nw4r;

extern "C" {
void* fn_8018D5D4(void*, const char*);
void* fn_8018D7DC(void*, const char*);
void* fn_8018DBEC(void*, const char*);
void* fn_8018DDF4(void*, const char*);
void* fn_8018D9E4(void*, const char*);
void* fn_8018DFFC(void*, const char*);
g3d::AnmObjShpRes* fn_8019BC04(MEMAllocator*, int*, g3d::ResAnmShp, g3d::ResMdl, bool);
}

extern "C" gfModelAnimation* __ct1__16gfModelAnimationFd(gfModelAnimation* self, g3d::ResFile* file, g3d::ResMdl model, bool bind, const char* name, Heaps::HeapType heap)
{
    int size;
    *(u32*)self = 0;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    *(u32*)self = *(u32*)file;
    self->_spacer[0] = 1;
    self->m_anmObjChrRes = 0;
    self->m_anmObjVisRes = 0;
    self->m_anmObjTexPatRes = 0;
    self->m_anmObjTexSrtRes = 0;
    self->m_anmObjMatClrRes = 0;
    self->m_anmObjShpRes = 0;

    void* p = fn_8018D5D4(file, name);
    if (p) {
        self->m_anmObjChrRes = g3d::AnmObjChrRes::Construct(allocator, &size, g3d::ResAnmChr(p), model, false);
        if (bind)
            self->m_anmObjChrRes->Bind(model);
    }
    p = fn_8018D7DC(file, name);
    if (p) {
        self->m_anmObjVisRes = g3d::AnmObjVisRes::Construct(allocator, &size, g3d::ResAnmVis(p), model);
        if (bind)
            self->m_anmObjVisRes->Bind(model);
    }
    p = fn_8018DBEC(file, name);
    if (p) {
        self->m_anmObjTexPatRes = g3d::AnmObjTexPatRes::Construct(allocator, &size, g3d::ResAnmTexPat(p), model, false);
        if (bind)
            self->m_anmObjTexPatRes->Bind(model);
    }
    p = fn_8018DDF4(file, name);
    if (p) {
        self->m_anmObjTexSrtRes = g3d::AnmObjTexSrtRes::Construct(allocator, &size, g3d::ResAnmTexSrt(p), model, false);
        if (bind)
            self->m_anmObjTexSrtRes->Bind(model);
    }
    p = fn_8018D9E4(file, name);
    if (p) {
        self->m_anmObjMatClrRes = g3d::AnmObjMatClrRes::Construct(allocator, &size, g3d::ResAnmClr(p), model, false);
        if (bind)
            self->m_anmObjMatClrRes->Bind(model);
    }
    p = fn_8018DFFC(file, name);
    if (p) {
        self->m_anmObjShpRes = fn_8019BC04(allocator, &size, g3d::ResAnmShp(p), model, false);
        if (bind)
            self->m_anmObjShpRes->Bind(model);
    }
    return self;
}