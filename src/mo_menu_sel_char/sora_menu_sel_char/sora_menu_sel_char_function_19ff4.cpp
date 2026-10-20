#include <types.h>
#pragma force_active on

struct RO {
    float a;
    float b;
    u8 pad[0x28];
    u8 tbl[16];
};
extern "C" const RO lbl_10_rodata_7D0;

struct VObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void f1c(float f);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void f48(int i, float f);
};

struct Inner { u8 pad[0x20]; int val; };

static inline bool chk(const RO* r, u8* self, int idx, int flag) {
    const u8* t;
    if (!(flag == 0 && (t = r->tbl, t[*(int*)(self + 0x80)] != 0) && t[idx] != 0)) {
        return false;
    }
    return true;
}

extern "C" {
void fn_10_19FF4(u8* self, int idx, int flag) {
    const RO* r = &lbl_10_rodata_7D0;
    if (!chk(r, self, idx, flag)) {
        for (int i = 0; i < 11; i++) {
            VObj* o = *(VObj**)(self + 0x7c);
            o->f48(i, i == idx ? r->a : r->b);
        }
    }
    u8* p = *(u8**)(self + idx * 4 + 0x50);
    if (((Inner*)*(u8**)(p + 0x2c))->val == 0) {
        ((VObj*)p)->f1c(r->b);
    }
    *(int*)(self + 0x80) = idx;
}
}