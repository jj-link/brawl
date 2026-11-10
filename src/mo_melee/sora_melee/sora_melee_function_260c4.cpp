#include <types.h>
#pragma force_active on
struct SrcEntry { char pad[12]; u16 value; char pad2[2]; };
struct Src { char pad[12]; SrcEntry* entries; };
struct DstEntry { char pad[14]; u16 value; char pad2[2]; };
struct Dst { char pad[4]; u16 count; char pad2[14]; DstEntry* entries; };
struct Obj { char pad[44]; Src* src; Dst* dst; };
static inline int getCount(Dst* p) { return p->count; }
extern "C" void fn_27_260C4(Obj* obj) {
    Src* src = obj->src;
    if (!src || !src->entries) return;
    Dst* d = obj->dst;
    if (!d) return;
    int n = getCount(d);
    DstEntry* a = d->entries;
    if (!n || !a) return;
    for (int i = 0; i < n; i++) {
        a[i].value = obj->src->entries[i].value | (a[i].value & ~15);
    }
}