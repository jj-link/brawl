#include <types.h>
#pragma force_active on

class VirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getVal();
    virtual void v7();
    virtual void setVal(float f);
};

struct HolderB {
    char pad[0x18];
    VirtBase* sub;
};

struct HolderA {
    char pad[0x14];
    HolderB* b;
};

struct Self {
    char pad0[0xC0];
    void* obj;
    HolderA* a;
    char pad1[0x1F8 - 0xC8];
    u8 flag1f8;
    u8 flag1f9;
};

extern "C" {
int fn_800B5854(void* obj, int a, int b, int c, int d);
void setFrameMatCol__8MuObjectFf(void* obj, float f);
extern const float lbl_10_rodata_5C0[];

}

static inline void applyFrame(float frame, void* obj) {
    setFrameMatCol__8MuObjectFf(obj, frame);
}

extern "C" {
void fn_10_17C98(Self* self) {
    const float* ro = lbl_10_rodata_5C0;
    void* obj = self->obj;
    if (self->flag1f9 != 0) {
        VirtBase* sub = self->a->b->sub;
        if (sub->getVal() >= ro[0x180 / 4]) {
            fn_800B5854(obj, 0, 0x10, 0, 0);
            applyFrame(self->flag1f8 != 0 ? ro[0xF8 / 4] : ro[0xE8 / 4], obj);
            VirtBase* sub2 = self->a->b->sub;
            sub2->setVal(ro[0xE8 / 4]);
            self->flag1f9 = 0;
        }
    }
}
}
