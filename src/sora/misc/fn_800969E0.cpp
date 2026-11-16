#include <types.h>
#pragma force_active on

struct Snap {
    int a;
    short b, c, d, e;
    float f0 __attribute__((aligned(16)));
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;
    Snap() {}
    Snap(const Snap& o) { *this = o; }
    Snap& operator=(const Snap& o) {
        a = o.a; b = o.b; c = o.c; d = o.d; e = o.e;
        f0 = o.f0; f1 = o.f1; f2 = o.f2; f3 = o.f3; f4 = o.f4; f5 = o.f5;
        f6 = o.f6; f7 = o.f7; f8 = o.f8; f9 = o.f9; f10 = o.f10; f11 = o.f11;
        f12 = o.f12; f13 = o.f13; f14 = o.f14; f15 = o.f15; f16 = o.f16;
        f17 = o.f17; f18 = o.f18; f19 = o.f19;
        return *this;
    }
};

struct Ent { u8 f0, f1, f2, f3; char pad[0xc]; Snap snap; };
struct Rec { s16 id; s16 pad; s32 idx; };
struct Arr { void* data; s32 size; s32 cap; };
struct Pool { char pad[0x10]; s32 count; void* data; };
struct Sub { char pad[0x30]; Pool* pool; };
struct Buf { Pool* pool; Arr a0; Arr a1; Arr a2; u8 b0, b1; };
struct Ctx {
    u8 active; char pad[3];
    Sub* sub;
    Ent** ents;
    s32 nEnts;
    s32 pad10;
    Rec* recs;
    s32 nRecs;
};
struct M12 { float a[12]; };

extern "C" {
void fn_800977F0(void* self, void* dst, void* buf);
void fn_800986A8(void* e, void* buf);
void fn_800986AC(void* e, void* buf);
void fn_800988EC(void* e, void* buf);
void fn_80098E14(void* e, void* buf);
void fn_80099838(void* e, void* buf);
s32 fn_800997D0(void* e, s16 id);
void fn_8027CD94(void* arr, s32 n, s32 elem);
void fn_8027EABC(s32 heap, void* p, s32 n, s32 tag);
void fn_80283D7C(float* dst, const float* src);
void fn_80284DB0(void* src, float* dst);
void* fn_8032EB2C(void* buf);
void fn_8032F030(void* buf);
}
extern s32 lbl_805A0EC8;

static inline s32 flags(const Arr& arr) {
    return arr.cap & 0x80000000;
}

static inline void initBuf(Buf& buf, Pool* pool) {
    buf.pool = pool;
    buf.a0.data = 0; buf.a0.size = 0; buf.a0.cap = (s32)0x80000000;
    buf.a1.data = 0; buf.a1.size = 0; buf.a1.cap = (s32)0x80000000;
    buf.a2.data = 0; buf.a2.size = 0; buf.a2.cap = (s32)0x80000000;
    buf.b0 = 0; buf.b1 = 0;

    s32 count = buf.pool->count;

    s32 cap = buf.a1.cap & 0x3FFFFFFF;
    if (cap < count) {
        s32 d = cap * 2;
        fn_8027CD94(&buf.a1, (count < d) ? d : count, 0x30);
    }
    buf.a1.size = count;

    s32 cap2 = buf.a0.cap & 0x3FFFFFFF;
    if (cap2 < count) {
        s32 d = cap2 * 2;
        fn_8027CD94(&buf.a0, (count < d) ? d : count, 0x30);
    }
    buf.a0.size = count;

    s32 cap3 = buf.a2.cap & 0x3FFFFFFF;
    if (cap3 < count) {
        s32 d = cap3 * 2;
        fn_8027CD94(&buf.a2, (count < d) ? d : count, 1);
    }
    buf.a2.size = count;

}

static inline Ent* findEnt(Ctx* self, s16 id) {
    for (s32 k = 0; k < self->nEnts; k++) {
        Ent* q = self->ents[k];
        if (q != 0 && fn_800997D0(q, id) != 0) return q;
    }
    return 0;
}

static inline bool contains(Ctx* self, s16 id) {
    Ent* q;
    for (s32 m = 0; m < self->nEnts; m++) {
        q = self->ents[m];
        Snap s = q->snap;
        if (s.b == id || s.c == id || s.d == id || s.e == id) return true;
    }
    return false;
}

extern "C" void fn_800969E0(Ctx* self, void* dst) {
    s32 idx;
    s16 id;
    s32 j;
    s32 i;
    Buf buf;
    float raw[16] __attribute__((aligned(16)));
    float mtx[16] __attribute__((aligned(16)));
    M12 out;
    float m44[16] __attribute__((aligned(16)));

    if (self->active == 0) return;

    initBuf(buf, self->sub->pool);

    fn_8032F030(&buf);
    fn_800977F0(self, dst, &buf);

    for (i = 0; i < self->nEnts; i++) {
        Ent* e = self->ents[i];
        if (e == 0) continue;
        if (e->f1 == 0) continue;
        if (e->f0 == 0) {
            fn_800986A8(e, &buf);
            e->f0 = 1;
        }
        if (e->f3 != 0) fn_80099838(e, &buf);
        if (e->f2 != 0) fn_800986AC(e, &buf);
        if (e->f3 != 0) {
            fn_800988EC(e, &buf);
            fn_80098E14(e, &buf);
        }

        float** base = (float**)fn_8032EB2C(&buf);

        for (j = 0; j < self->nRecs; j++) {
            Rec* rec = &self->recs[j];
            id = rec->id;
            idx = rec->idx;

            Ent* found = findEnt(self, id);

            if (contains(self, id) && found->f1 != 0) {
                fn_80284DB0((char*)*base + id * 0x30, raw);
                fn_80283D7C(mtx, raw);
                M12* d = (M12*)((char*)dst + idx * 0x30);
                m44[0] = mtx[0];   m44[1] = mtx[1];   m44[2] = mtx[2];   m44[3] = mtx[3];
                m44[4] = mtx[4];   m44[5] = mtx[5];   m44[6] = mtx[6];   m44[7] = mtx[7];
                m44[8] = mtx[8];   m44[9] = mtx[9];   m44[10] = mtx[10]; m44[11] = mtx[11];
                m44[12] = mtx[12]; m44[13] = mtx[13]; m44[14] = mtx[14]; m44[15] = mtx[15];
                out.a[0] = mtx[0];  out.a[1] = mtx[4];  out.a[2] = mtx[8];  out.a[3] = mtx[12];
                out.a[4] = mtx[1];  out.a[5] = mtx[5];  out.a[6] = mtx[9];  out.a[7] = mtx[13];
                out.a[8] = mtx[2];  out.a[9] = mtx[6];  out.a[10] = mtx[10]; out.a[11] = mtx[14];
                *d = out;
            }
        }
    }

    if (flags(buf.a2) == 0)
        fn_8027EABC(lbl_805A0EC8, buf.a2.data, buf.a2.cap & 0x3FFFFFFF, 0x15);
    if (flags(buf.a1) == 0)
        fn_8027EABC(lbl_805A0EC8, buf.a1.data, (buf.a1.cap & 0x3FFFFFFF) * 0x30, 0x15);
    if (flags(buf.a0) == 0)
        fn_8027EABC(lbl_805A0EC8, buf.a0.data, (buf.a0.cap & 0x3FFFFFFF) * 0x30, 0x15);
}
