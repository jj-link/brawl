#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
void fn_801BBC1C(void*, s32*, s32*);
void fn_801BBC68(void*, s32, s32);
s32 fn_80203640(void*);
s32 fn_8020385C(void*);
extern const float lbl_805A3518;
}

struct Src {
    float x;
    float y;
    float z;
};

struct Self {
    char pad0[0xC];
    unsigned char flag;      // 0xC
    char pad0d[3];
    char* heap;              // 0x10
    char pad14[4];
    float vx;                // 0x18
    float vy;                // 0x1C
    float vz;                // 0x20
    char obj[0x64 - 0x24];   // 0x24
    u32 r64;
    u32 r68;
    u32 r6C;
    u32 r70;
    u32 r74;
    u32 r78;
    u32 r7C;
    u32 r80;
    u32 r84;
};

extern "C" s32 fn_801C0234(Self* self, const Src* src) {
    s32 spC;
    s32 sp8;
    s32 r;
    u32 size;
    u32 avail;
    u32 t;
    u32 v;
    char* p;

    self->vx = src->x;
    self->vy = src->y;
    self->vz = src->z;

    t = (u32)src->x;
    if (t > 0x1388) {
        v = 0x1388;
    } else {
        v = 1;
        if (t >= 1) {
            v = t;
        }
    }
    self->r6C = v;
    self->r68 = v;
    self->r64 = v;

    t = (u32)(lbl_805A3518 * src->y);
    v = 0x63;
    if (t <= 0x63) {
        v = t;
    }
    self->r78 = v;
    self->r74 = v;
    self->r70 = v;

    t = (u32)(lbl_805A3518 * src->z);
    v = 0x64;
    if (t <= 0x64) {
        v = t;
    }
    self->r84 = v;
    self->r80 = v;
    self->r7C = v;

    if (self->flag == 0) {
        return 1;
    }

    size = ((u32)fn_80203640(self->obj) + 0x87) & 0xFFFFFFE0;
    p = self->heap;
    if (p == 0) {
        avail = 0;
    } else {
        avail = *(u32*)(p + 0x1C) - (u32)p;
    }
    if (size > avail) {
        return 0;
    }

    fn_801BBC1C(&self->flag, &spC, &sp8);
    r = fn_8020385C(self->obj);
    fn_801BBC68(&self->flag, spC, sp8);
    return r != 0;
}
