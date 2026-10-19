#include <types.h>
#pragma force_active on

extern "C" {
void sprintf(char* s, const char* fmt, ...);
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
extern const char lbl_31_data_28[];
extern const float lbl_31_rodata_34;
extern const float lbl_31_rodata_40;
}

struct VMdl {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void* a);
};

#define ELEM(i) (*(u8**)(self + ((i) << 2) + 0x1c4))

extern "C" void fn_31_23D0(u8* self, s32 idx) {
    char buf[8];
    *(s32*)buf = 0;
    *(s16*)(buf + 4) = 0;
    *(s32*)(self + 0x4c0) = idx + 0x90;
    VMdl* obj = *(VMdl**)(self + 0x48c);
    sprintf(buf, lbl_31_data_28, idx);

    if (idx != *(s32*)(self + 0x48)) {
        s32 old = *(s32*)(self + 0x48);
        obj->v13(*(void**)(ELEM(old + 0x90) + 0x10));
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(ELEM(*(s32*)(self + 0x4c0)) + 0x10), buf);
    }

    if (self[0x59] == 0) {
        obj->v13(*(void**)(ELEM(*(s32*)(self + 0x4c0)) + 0x10));
        self[0x58] = 1;
    }

    if (self[0x58] == 1 && self[0x59] == 1) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(ELEM(*(s32*)(self + 0x4c0)) + 0x10), buf);
        self[0x58] = 0;
    }

    u8* e = ELEM(*(s32*)(self + 0x4c0));
    if (self[0x59] != 0 && self[0x5e6] == 0) {
        setUpdateRate__16gfModelAnimationFf(*(void**)(e + 0x14), lbl_31_rodata_40);
    } else {
        setUpdateRate__16gfModelAnimationFf(*(void**)(e + 0x14), lbl_31_rodata_34);
    }
}
