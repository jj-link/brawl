#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on
struct NodeData { char pad[12]; u32 id; u32 pad2; u32 flags; };
struct MaterialData { char pad[12]; u32 id; };
struct Context { u32 pad; u8* visibility; };
struct Entry { u8 kind, mhi, mlo, shi, slo, nhi, nlo, pad; };
struct Work { u32 v[14]; };
extern "C" NodeData* GetResNode__Q34nw4r3g3d6ResMdlCFi(const nw4r::g3d::ResMdl*, int);
extern "C" MaterialData* fn_8018F2EC(nw4r::g3d::ResMdl*, u32);
extern "C" u32 fn_8018F3C8(nw4r::g3d::ResMdl*, u32);
extern "C" void fn_801A5C0C(Work*, Context*, u32);
extern "C" int fn_801A56F0(MaterialData**, NodeData**, u32*);
extern "C" void fn_801A1A48(MaterialData**, u32*, int, int, int, Work*, int);
extern "C" void fn_801A5F1C(nw4r::g3d::ResMdl* model, Entry* current, Context* ctx, u32 flags) {
    MaterialData *e;
    u32 d;
    MaterialData *c;
    NodeData *b;
    u32 a;
    u32 flag;
    u32 *pa;
    NodeData **pb;
    MaterialData **pc;
    u32 *pd;
    MaterialData* previous = 0;
    Work work = {0};
    int mode = 1;
    flag = (flags >> 2) & 1;
    if (flags & 8) mode |= 8;
    pa = &a; pb = &b; pc = &c; pd = &d;
    while (current->kind != 1) {
        NodeData* node = GetResNode__Q34nw4r3g3d6ResMdlCFi(model, (current->nhi << 8) | current->nlo);
        int visible;
        if (ctx->visibility) {
            u32 id = node ? node->id : 0;
            visible = ctx->visibility[id] != 0;
        } else if (node) {
            visible = (node->flags >> 8) & 1;
        } else {
            visible = 0;
        }
        if (visible) {
            MaterialData* material = fn_8018F2EC(model, (current->mhi << 8) | current->mlo);
            u32 shape = fn_8018F3C8(model, (current->shi << 8) | current->slo);
            fn_801A5C0C(&work, ctx, material->id);
            a = shape;
            b = node;
            c = material;
            d = shape;
            int skip = 0;
            if (flag || material == previous) skip = 1;
            if (skip) e = 0;
            else e = material;
            fn_801A1A48(&e, pd, 0, 0, mode, &work, fn_801A56F0(pc, pb, pa));
            previous = material;
        }
        ++current;
    }
}