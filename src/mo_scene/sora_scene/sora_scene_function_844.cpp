#include <types.h>
#include <sr/sr_common.h>
#include <gf/gf_archive.h>
#pragma force_active on

extern u32 lbl_1_data_128;
extern char lbl_1_data_12C[];
extern char lbl_1_data_670[];

struct Bss {
    u32 a, b, c, d;
    void* p10;
    void* p14;
    void* p18;
};
extern Bss lbl_1_bss_8;

struct Obj {
    void* v0;
    void* v4;
    u32 v8;
    u32 vC;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14a : 1;
    u8 b14b : 1;
    u8 b14c : 1;
    u8 b14d : 1;
    u8 b14e : 1;
    u8 b14f : 1;
    u8 b14g : 1;
    u8 b14h : 1;
    u8 b15;
    u8 b16;
    u8 pad17;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    void* f38;
};

struct L {
    u32 f0, f4, f8, fC, f10;
    u32 f14;
    u32 f18;
    u8 flag1 : 1;
    u8 flag2 : 1;
    u8 flag3 : 1;
    u8 rest : 5;
};

struct M {
    u32 f0, f4, f8, fC;
    u8 b10, b11, b12, b13;
    u32 f14, f18, f1C, f20, f24, f28, f2C;
    u8 b30;
    u32 f34;
};

extern "C" Obj* fn_1_844(Obj* self) {
    Bss* g = &lbl_1_bss_8;
    self->v0 = lbl_1_data_12C;
    self->v4 = lbl_1_data_670;
    self->v8 = lbl_1_data_128;
    self->vC = 0;
    self->f1C = lbl_1_data_128;
    self->f20 = 0;
    self->f18 = 0;
    self->b10 = 2;
    self->b11 = 2;
    self->b13 = (u8)((u32)self->b13 & 0xFFFFFF00);
    self->b14a = 0;
    self->b14b = 0;
    self->b14c = 0;
    self->b14d = 0;
    self->b14e = 0;
    self->b14f = 0;
    self->b14g = 0;
    self->b15 = 0;
    self->b16 = 0;
    self->b12 = 0;
    g->p10 = 0;
    g->p14 = 0;
    self->f38 = 0;

    L* l = (L*)operator new(0x20, (Heaps::HeapType)0x2e);
    if (l != 0) {
        l->f0 = 0;
        l->f4 = 0;
        l->f8 = 0;
        l->fC = 0;
        l->f10 = 0;
        l->flag1 = 0;
        l->flag2 = 0;
        l->f18 = 0;
        l->f14 = 0xFF;
        l->flag3 = 0;
    }
    g->p10 = l;

    gfArchive* a = new ((Heaps::HeapType)0x2e) gfArchive;
    g->p14 = a;

    M* m = (M*)operator new(0x38, (Heaps::HeapType)0x2e);
    if (m != 0) {
        m->f0 = lbl_1_data_128;
        m->f4 = 0;
        m->f8 = lbl_1_data_128;
        m->fC = 0;
        m->f1C = 0;
        m->f20 = 0;
        g->p18 = m;
        m->f0 = lbl_1_data_128;
        m->f4 = 0;
        m->b10 = 0;
        m->b11 = 0;
        m->b12 = 0;
        m->b13 = 0;
        m->f24 = 0;
        m->f28 = 0;
        m->f2C = 0;
        m->b30 = 0;
        m->f34 = 0;
    }
    self->f38 = m;
    self->f1C = lbl_1_data_128;
    self->f20 = 0;
    self->f28 = -1;
    self->f2C = -1;
    self->f30 = -1;
    self->f34 = -1;
    return self;
}
