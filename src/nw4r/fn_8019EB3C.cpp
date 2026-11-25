#pragma force_active on
typedef unsigned int u32;
struct Data { u32 flags; u32 m[3][12]; };
extern "C" void fn_8019DBBC(int, void*);
extern "C" void fn_8019EB3C(const Data* d) {
    if (d->flags & 1) fn_8019DBBC(0, (void*)d->m[0]);
    if (d->flags & 2) fn_8019DBBC(3, (void*)d->m[1]);
    if (d->flags & 4) fn_8019DBBC(6, (void*)d->m[2]);
}
