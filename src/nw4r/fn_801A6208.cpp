#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct DrawEntry { u16 unused[3]; u16 node; u16 material; u16 shape; };

extern "C" void* fn_8018F2EC(nw4r::g3d::ResMdl*, u32);
extern "C" u32 fn_8018F3C8(nw4r::g3d::ResMdl*, u32);
extern "C" u32 GetResNode__Q34nw4r3g3d6ResMdlCFi(const nw4r::g3d::ResMdl*, int);
extern "C" int fn_801A56F0(void**, u32*, u32*);
extern "C" void fn_801A1A48(void**, u32*, int, int, int, u32*, int);
extern "C" void fn_801A5C0C(u32*, void*, u32);

extern "C" void fn_801A6208(nw4r::g3d::ResMdl* model, DrawEntry* entries, u32 count, void* ctx, u32 flags) {
    u32 work[14];
    void* e;
    u32 d;
    void* c;
    u32 b, a;
    void* material;
    u32 flag;
    u32 *pa, *pb;
    void **pc;
    u32 *pd;
    DrawEntry* current;
    void* previous;
    u32 i;
    int mode;
    previous = 0;
    for (int k = 0; k < 14; k++) work[k] = 0;
    mode = 1;
    flag = (flags >> 2) & 1;
    if (flags & 8) mode |= 8;
    i = 0;
    if (count != 0) {
        current = entries;
        pa = &a; pb = &b; pc = &c; pd = &d;
        while (i < count) {
            material = fn_8018F2EC(model, current->material);
            u32 shape = fn_8018F3C8(model, current->shape);
            u32 node = GetResNode__Q34nw4r3g3d6ResMdlCFi(model, current->node);
            fn_801A5C0C(work, ctx, ((u32*)material)[3]);
            a = shape;
            b = node;
            c = material;
            d = shape;
            int skip = 0;
            if (flag || material == previous) skip = 1;
            if (skip) e = 0;
            else e = material;
            fn_801A1A48(&e, pd, 0, 0, mode, work, fn_801A56F0(pc, pb, pa));
            previous = material;
            ++current;
            ++i;
        }
    }
}
