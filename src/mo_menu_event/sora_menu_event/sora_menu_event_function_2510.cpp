#include <types.h>
#pragma force_active on

class Anim {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getFrame();
    virtual void v7();
    virtual void setFrame(float f);
};

class Holder {
public:
    char pad[0xC];
    Anim* anim;
};

class MuObject {
public:
    char pad[0x14];
    Holder* holder;
    void setFrameNode(float f);
};

class Self {
public:
    char pad0[0x44];
    MuObject* obj;
    char pad1[0x1A0 - 0x48];
    s32 val;
    char pad2[0x17E8 - 0x1A4];
    u8 flag;
};

extern "C" float lbl_9_rodata_0[];
extern "C" void* g_sndSystem;
extern "C" void fn_80074ECC(void* snd, u32 flags, float f1, float f2);

extern "C" s32 fn_9_2510(Self* self) {
    float* base = lbl_9_rodata_0;
    MuObject* obj = self->obj;
    Anim* a = obj->holder->anim;
    if (a->getFrame() >= base[0x2E]) {
        obj->setFrameNode(base[0x2E]);
        Anim* a2 = obj->holder->anim;
        a2->setFrame(base[0x25]);
        if (self->flag == 0) {
            fn_80074ECC(g_sndSystem, 0x1FF2, base[0x24], base[0x24]);
        }
        return 2;
    }
    return self->val;
}
