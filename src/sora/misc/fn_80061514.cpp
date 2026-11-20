#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on

class ScnStub {
public:
    virtual void s0();
    virtual void G3dProc(u32 task, u32 param, void* pInfo);
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual bool SetScnObjOption(u32 option, u32 value);
};

struct Table {
    u8 pad0[0xC];
    u8* data;
};

struct Entry {
    u8 pad0[0x14];
    s32 w14;
    s32 w18;
    u8 b1C;
};

struct Word0C {
    u32 kind : 8;
    u32 rest : 24;
};

struct Node {
    u8 pad0[0xC];
    Word0C w0C;
    u8 pad10[0x14];
    Vec3f v24;
    Vec3f v30;
    Vec3f v3C;
};

struct Obj {
    Vec3f v00;
    Vec3f v0C;
    Vec3f v18;
    s32 w24;
    s32 w28;
    s32 w2C;
    Table* p30;
    void** p34;
    s32 w38;
    s32 w3C;
    s32 w40;
    ScnStub* p44;
    s32 w48;
    s32 w4C;
    s32 w50;
    u8 pad54[2];
    u16 u56;
    u8 b58;
    u8 b59;
    u8 b5A;
    u8 b5B;
    s32 w5C;
    u16 u60;
    u8 pad62[2];
    s32 w64;
    s32 w68;
    u8 pad6C[4];
    s32 w70;
    s32 w74;
    s32 w78;
    s32 w7C;
    u8 b80;
};

extern f32 lbl_805A1958;
extern f32 lbl_805A195C;

extern "C" void* __nwa__FUlQ25Heaps8HeapType(u32, int);
extern "C" void gfMemFill__FPvUcUl(void*, u8, u32);
extern "C" void* fn_8005C650(void*, u8);
extern "C" void fn_801AAF04(ScnStub*, int, Matrix*);
extern "C" void nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(ScnStub*, bool);

#define NODE_CUR(self) ((Node*)((self)->p34 + (self)->w38)[-1])

extern "C" void fn_80061514(Obj* self, s32 a1, s32 a2, Table* a3, s32 a4, Vec3f* a5, Vec3f* a6, Vec3f* a7, s32 a9, ScnStub* a10, s32 a11, s32 a12, s32 a13, u8 a14, u8 a15, u8 a16) {
    Entry* e = (Entry*)(a3->data + a4 * 16);
    nw4r::math::MTX34 mtx;
    s32 flags;

    self->w7C = a1;
    self->w78 = a2;
    self->b80 = 0;
    self->p30 = a3;
    self->w2C = a4;
    self->w24 = 0;
    self->w28 = 0;
    self->p34 = NULL;
    self->w38 = 0;
    self->w40 = a9;
    self->p44 = a10;
    self->w48 = a11;
    self->w4C = a12;
    self->w3C = a13;
    self->b58 = 0;
    self->b59 = 0;
    self->b5B = 1;
    self->b5A = 1;

    if (a5 != NULL) {
        self->v00 = *a5;
    } else {
        self->v00 = Vec3f(lbl_805A1958, lbl_805A1958, lbl_805A1958);
    }
    if (a6 != NULL) {
        self->v0C = *a6;
    } else {
        self->v0C = Vec3f(lbl_805A1958, lbl_805A1958, lbl_805A1958);
    }
    if (a7 != NULL) {
        self->v18 = *a7;
    } else {
        self->v18 = Vec3f(lbl_805A195C, lbl_805A195C, lbl_805A195C);
    }
    self->w50 = 0;
    if (a14 != 0) {
        flags = 0x100;
    } else {
        flags = (a15 != 0) ? 0x200 : 0;
    }
    self->u56 = flags;
    if (a16 != 0) {
        self->u56 = (u16)flags | 0x400;
    }
    if (e->b1C & 0x80) {
        self->u56 |= 0x4000;
    }
    self->w5C = 0;
    self->u60 = 0xFFFF;
    self->w64 = 0;
    self->w68 = 0;
    self->w70 = 0;
    self->w74 = 0;

    if (self->p44 != NULL) {
        ((Matrix*)&mtx)->setSRT(self->v18, self->v0C, self->v00);
        fn_801AAF04(self->p44, 0, (Matrix*)&mtx);
        self->p44->SetScnObjOption(2, 0);
        self->p44->G3dProc(1, 0, NULL);
        nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(self->p44, false);
        if (e->w18 != 0) {
            self->w38 += (self->p30->data + e->w18)[4];
        }
    }
    if (e->w14 != 0) {
        self->w38 += 1;
    }
    if (self->w38 != 0) {
        void** p = (void**)__nwa__FUlQ25Heaps8HeapType(self->w38 * 4, 3);
        self->p34 = p;
        if (p != NULL) {
            gfMemFill__FPvUcUl(p, 0, self->w38 * 4);
        }
    }
    if (e->w14 != 0 && self->p34 != NULL) {
        (self->p34 + self->w38)[-1] = fn_8005C650(self->p30->data + e->w14, (self->u56 & 0x100) ? 2 : (((self->u56 & 0x200) != 0) ^ 1));
        if (NODE_CUR(self) != NULL) {
            if (self->u56 & 0x400) {
                ((u8*)NODE_CUR(self))[0xD] |= 0x20;
            }
            NODE_CUR(self)->w0C.kind = 3;
            if (a5 != NULL) {
                NODE_CUR(self)->v24 = self->v00;
            }
            if (a6 != NULL) {
                NODE_CUR(self)->v30 = self->v0C;
            }
            if (a7 != NULL) {
                NODE_CUR(self)->v3C = self->v18;
            }
        }
    }
}
