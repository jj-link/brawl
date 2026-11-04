#include <types.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_80015DB4(void*, int, int, int, u16);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_8010CF44(void*, void*, void*, void*, void*);

struct Work {
    char pad0[0x10];
    void* resource;
    void* r14;
    void* r18;
    void* r1c;
    void* r20;
    void* r24;
    void* r28;
    void* r2c;
    void* r30;
    void* r34;
    char pad38[8];
    void* r40;
    char pad44[0x14];
    void* r58;
    void* r5c;
    char pad60[0x18];
    void* r78;
};

extern "C" void fn_80106A64(Work* self, void* a, void* b, void* c, void* d) {
    self->r14 = fn_80015DB4(self->resource, 0, 1, 0, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r14);
    self->r18 = fn_80015DB4(self->resource, 0, 1, 1, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r18);
    self->r34 = fn_80015DB4(self->resource, 0, 1, 2, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r34);
    self->r1c = fn_80015DB4(self->resource, 0, 1, 3, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r1c);
    self->r20 = fn_80015DB4(self->resource, 0, 1, 4, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r20);
    self->r24 = fn_80015DB4(self->resource, 0, 1, 5, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r24);
    self->r2c = fn_80015DB4(self->resource, 0, 1, 8, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r2c);
    self->r28 = fn_80015DB4(self->resource, 0, 1, 6, (u16)0xfffe);
    nw4r::g3d::ResFile::Init(&self->r28);
    self->r40 = fn_80015DB4(self->resource, 0, 1, 7, (u16)0xfffe);
    if ((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1) {
        self->r30 = fn_80015DB4(self->resource, 0, 1, 12, (u16)0xfffe);
    } else {
        self->r30 = fn_80015DB4(self->resource, 0, 1, 11, (u16)0xfffe);
    }
    nw4r::g3d::ResFile::Init(&self->r30);
    self->r58 = fn_80015DB4(self->resource, 0, 1, 9, (u16)0xfffe);
    self->r5c = fn_80015DB4(self->resource, 0, 1, 10, (u16)0xfffe);
    if (a && b && c && d) {
        void* p = __nw__FUlQ25Heaps8HeapType(8, 2);
        if (p) p = fn_8010CF44(p, a, b, c, d);
        if (self->r78 != p) {
            __dl__FPv(self->r78);
            self->r78 = p;
        }
    }
}