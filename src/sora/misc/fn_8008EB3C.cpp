#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct Entry {
    f32 f[12];
};

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Obj {
    char _0[0x34];
    Vec3 v34;
    Vec3 v40;
    char _4C[0xC];
    Vec3 v58;
    char _64[0x1C];
    f32 f80;
    char _84[0x58];
    Entry ent;
    char _10C[0x94];
    u32 m1A0;
};

struct Self {
    Obj** objs;
    u32 count;
    char _08[0x5];
    u8 flagD;
    char _0E[0x1];
    u8 flagF;
    char _10[0x14];
    void* f24;
    char _28[0x18];
    u8 b40;
    char _41[0x18];
    u8 b59;
    char _5A[0x1];
    u8 b5B;
};

struct Mgr {
    char _0[0x58];
    void* m58;
};

struct GlobalMgrRef {
    Mgr* ptr;
    char _4[0x1C];
};

struct ResNodeData {
    char _0[0x10];
    s32 n10;
};

extern GlobalMgrRef lbl_8049DEC8;
extern char lbl_8059DBFA;
extern char lbl_8059DBFC;
extern const f32 lbl_805A1C98;

extern "C" {
void* fn_8008653C(void* mgr, Self* self, char* name);
void fn_8008F084(Self* self, Entry* arr, u32* p);
void fn_80086694(void* mgr, Vec3* v, char* name, Obj* o, f32 a, f32 b);
s32 fn_800867E8(void* mgr, Obj* o, u8 b, f32* out, f32 a, f32 c);
s32 fn_80086AC0(void* mgr, Obj* o, u8 b);
ResNodeData* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const nw4r::g3d::ResMdl* mdl, u32 idx);
}

static inline void* getMgr() {
    void* m = lbl_8049DEC8.ptr->m58;
    return m ? m : 0;
}

static inline bool isNaNf(f32& x) {
    u32 b = *(u32*)&x;
    return ((b >> 23) & 0xFF) == 0xFF && (b & 0x7FFFFF) != 0;
}

extern "C" void fn_8008EB3C(Self* self, Entry* arr, nw4r::g3d::ResMdl* mdl) {
    self->b59 = 0;
    if (self->flagF == 0) {
        self->f24 = fn_8008653C(getMgr(), self, &lbl_8059DBFA);
        self->flagF = 1;
    }
    if (self->flagD == 0) {
        u32 mtmp = *(u32*)mdl;
        fn_8008F084(self, arr, &mtmp);
        self->flagD = 1;
    }
    s32 i = (s32)self->count - 1;
    void* mgr = getMgr();
    ResNodeData* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(mdl, self->objs[i]->m1A0);
    s32 n = node ? node->n10 : 0;
    Entry* e = arr + n;
    self->objs[i]->ent = *e;
    Entry tmp = *e;

    f32 t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    bool bad = false;
    if (!bad) bad = isNaNf(t0 = tmp.f[0]);
    if (!bad) bad = isNaNf(t1 = tmp.f[1]);
    if (!bad) bad = isNaNf(t2 = tmp.f[2]);
    if (!bad) bad = isNaNf(t3 = tmp.f[3]);
    if (!bad) bad = isNaNf(t4 = tmp.f[4]);
    if (!bad) bad = isNaNf(t5 = tmp.f[5]);
    if (!bad) bad = isNaNf(t6 = tmp.f[6]);
    if (!bad) bad = isNaNf(t7 = tmp.f[7]);
    if (!bad) bad = isNaNf(t8 = tmp.f[8]);
    if (!bad) bad = isNaNf(t9 = tmp.f[9]);
    if (!bad) bad = isNaNf(t10 = tmp.f[10]);
    if (!bad) bad = isNaNf(t11 = tmp.f[11]);

    if (!bad) {
        Vec3 p;
        f32 sp40[2];
        p.x = tmp.f[3];
        p.y = tmp.f[7];
        p.z = tmp.f[11];
        self->objs[i]->v34 = p;
        self->objs[i]->v40 = p;
        Obj* o2 = self->objs[i];
        o2->v58 = p;
        fn_80086694(mgr, &p, &lbl_8059DBFC, o2, tmp.f[7], tmp.f[3]);
        f32 s1 = self->objs[i]->f80;
        self->objs[i]->v34.x = self->objs[i]->v34.x + s1 * lbl_805A1C98;
        f32 s2 = self->objs[i]->f80;
        self->objs[i]->v40.x = self->objs[i]->v40.x - s2 * lbl_805A1C98;
        f32 s3 = self->objs[i]->f80;
        f32 q = s3 * lbl_805A1C98;
        self->objs[i]->v58.x = self->objs[i]->v58.x - q;
        Obj* o = self->objs[i];
        s32 r29 = fn_800867E8(mgr, o, self->b5B, sp40, q, lbl_805A1C98);
        s32 r3 = fn_80086AC0(mgr, o, self->b40);
        if (r29 != 0) r3 = 1;
        if (r29 != 0) {
            self->b59 = 2;
        } else if (r3 != 0) {
            self->b59 = 1;
        }
    }
}
