#include <types.h>
#pragma force_active on

extern const float lbl_805A1AC8;

class FaderClass {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(s32);
};

class ScaleClass {
public:
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
    virtual void v12(s32, f32);
};

extern "C" void fn_80076714(char* self, s32 arg1, s32 arg2) {
    if (*(u8*)(self + 0x6EF) == 0) {
        return;
    }
    if (*(u8*)(self + 0x6ED) != 0) {
        char* p = self;
        u32 i = 0;
        do {
            if (*(s32*)(p + 0x2DC) != 0x10000) {
                FaderClass* obj = *(FaderClass**)(p + 0x2D4);
                if (obj != 0) {
                    obj->v4(arg1);
                }
                *(s32*)(p + 0x2D8) = -1;
                *(s32*)(p + 0x2DC) = -1;
                *(s32*)(p + 0x2E0) = -1;
                *(s32*)(p + 0x2E4) = 0;
                *(s32*)(p + 0x2E8) = 0x40;
                *(s32*)(p + 0x2EC) = 0;
                *(u16*)(p + 0x2F0) = 0;
            }
            i += 1;
            p += 0x20;
        } while (i < 0x20);
        *(s32*)(self + 0xBAC) = 0;
        *(s32*)(self + 0xBB0) = -1;
        *(s32*)(self + 0xBB4) = -1;
        *(s32*)(self + 0xBB8) = -1;
        *(s32*)(self + 0xBBC) = -1;
        *(s32*)(self + 0xBC0) = -1;
        *(s32*)(self + 0xBC4) = -1;
        *(s32*)(self + 0xBC8) = -1;
    }
    if (arg2 != 0) {
        if (*(u8*)(self + 0x6EF) != 0) {
            ScaleClass* obj = *(ScaleClass**)(self + 0x6E0);
            *(f32*)(self + 0x704) = lbl_805A1AC8;
            if (obj != 0) {
                f32 f = *(f32*)(self + 0x714) * (lbl_805A1AC8 * (*(f32*)(self + 0x700) * *(f32*)(self + 0x708)));
                if (obj != 0) {
                    obj->v12(arg1, f);
                }
            }
        }
    } else {
        *(f32*)(self + 0x704) = lbl_805A1AC8;
    }
}
