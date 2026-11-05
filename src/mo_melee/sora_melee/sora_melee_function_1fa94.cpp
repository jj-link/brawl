#include <types.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_anmvis.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <nw4r/g3d/g3d_anmtexpat.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>
#include <nw4r/g3d/g3d_anmshp.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct AnimSlots {
    nw4r::g3d::AnmObjVisRes* vis;        /* 0x00 */
    nw4r::g3d::AnmObjMatClrRes* matClr;  /* 0x04 */
    nw4r::g3d::AnmObjTexPatRes* texPat;  /* 0x08 */
    nw4r::g3d::AnmObjTexSrtRes* texSrt;  /* 0x0C */
    nw4r::g3d::AnmObjShpRes* shp;        /* 0x10 */
    u8 pad[0x24 - 0x14];
    u8 flags;                            /* 0x24 */
};

extern "C" {
bool fn_8018E40C(nw4r::g3d::ResFile* res);
bool fn_8018E458(nw4r::g3d::ResFile* res);
bool fn_8018E4A4(nw4r::g3d::ResFile* res);
bool fn_8018E4F0(nw4r::g3d::ResFile* res);
bool fn_8018E53C(nw4r::g3d::ResFile* res);
nw4r::g3d::ResAnmVis fn_8018D7DC(nw4r::g3d::ResFile* res, const char* name);
nw4r::g3d::ResAnmClr fn_8018D9E4(nw4r::g3d::ResFile* res, const char* name);
nw4r::g3d::ResAnmTexPat fn_8018DBEC(nw4r::g3d::ResFile* res, const char* name);
nw4r::g3d::ResAnmTexSrt fn_8018DDF4(nw4r::g3d::ResFile* res, const char* name);
nw4r::g3d::ResAnmShp fn_8018E068(nw4r::g3d::ResFile* res, int index);
nw4r::g3d::ResAnmShp fn_8018DFFC(nw4r::g3d::ResFile* res, const char* name);
nw4r::g3d::AnmObjShpRes* fn_8019BC04(MEMAllocator* alloc, int* size, nw4r::g3d::ResAnmShp anim, nw4r::g3d::ResMdl mdl, bool hasCache);

void fn_27_1FA94(AnimSlots* self, nw4r::g3d::ResFile* res, nw4r::g3d::ResMdl mdl, Heaps::HeapType heap, const char* name) {
    int size;
    MEMAllocator* alloc = gfHeapManager::getMEMAllocator(heap);
    if (res->IsValid()) {
        if (fn_8018E40C(res) == true) {
            nw4r::g3d::ResAnmVis anim = (name == 0) ? res->GetResAnmVis(0) : fn_8018D7DC(res, name);
            if (anim.IsValid()) {
                nw4r::g3d::AnmObjVisRes* obj = nw4r::g3d::AnmObjVisRes::Construct(alloc, &size, anim, mdl);
                obj->Bind(mdl);
                self->vis = obj;
                self->flags &= ~0x20;
            }
        }
        if (fn_8018E458(res) == true) {
            nw4r::g3d::ResAnmClr anim = (name == 0) ? res->GetResAnmClr(0) : fn_8018D9E4(res, name);
            if (anim.IsValid()) {
                nw4r::g3d::AnmObjMatClrRes* obj = nw4r::g3d::AnmObjMatClrRes::Construct(alloc, &size, anim, mdl, false);
                obj->Bind(mdl);
                self->matClr = obj;
                self->flags &= ~0x20;
            }
        }
        if (fn_8018E4A4(res) == true) {
            nw4r::g3d::ResAnmTexPat anim = (name == 0) ? res->GetResAnmTexPat(0) : fn_8018DBEC(res, name);
            if (anim.IsValid()) {
                nw4r::g3d::AnmObjTexPatRes* obj = nw4r::g3d::AnmObjTexPatRes::Construct(alloc, &size, anim, mdl, false);
                obj->Bind(mdl);
                self->texPat = obj;
                self->flags &= ~0x20;
            }
        }
        if (fn_8018E4F0(res) == true) {
            nw4r::g3d::ResAnmTexSrt anim = (name == 0) ? res->GetResAnmTexSrt(0) : fn_8018DDF4(res, name);
            if (anim.IsValid()) {
                nw4r::g3d::AnmObjTexSrtRes* obj = nw4r::g3d::AnmObjTexSrtRes::Construct(alloc, &size, anim, mdl, false);
                obj->Bind(mdl);
                self->texSrt = obj;
                self->flags &= ~0x20;
            }
        }
        if (fn_8018E53C(res) == true) {
            nw4r::g3d::ResAnmShp anim = (name == 0) ? fn_8018E068(res, 0) : fn_8018DFFC(res, name);
            if (anim.IsValid()) {
                nw4r::g3d::AnmObjShpRes* obj = fn_8019BC04(alloc, &size, anim, mdl, false);
                obj->Bind(mdl);
                self->shp = obj;
                self->flags &= ~0x20;
            }
        }
    }
}
}
