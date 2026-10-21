#include <types.h>
#pragma force_active on

class Sub {
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
    virtual void v12();
    virtual void call(void*);
};

struct Self {
    char pad0[0xAC];
    void* unkAC;
    char pad1[0x1BC - 0xB0];
    Sub* unk1BC;
    char pad2[0x1D4 - 0x1C0];
    void* unk1D4;
    char pad3[0x24C0 - 0x1D8];
    s32 unk24C0;
    char pad4[0x24CC - 0x24C4];
    void* unk24CC;
};

extern "C" {
void printf__5MuMsgFUlPCce(void* msg, u32 index, const char* fmt, ...);
void setFrameMatCol__8MuObjectFf(void* obj, float f);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

extern char lbl_14_data_3FC[];
extern char lbl_14_data_404[];
extern float lbl_14_rodata_0;
extern float lbl_14_rodata_200;

void fn_14_2D04(Self* self) {
    printf__5MuMsgFUlPCce(self->unk24CC, 0x13, lbl_14_data_3FC, self->unk24C0, 0x40);
    float f;
    if ((0x40 - self->unk24C0) <= 0) {
        f = lbl_14_rodata_200;
    } else {
        f = lbl_14_rodata_0;
    }
    setFrameMatCol__8MuObjectFf(self->unkAC, f);
    Sub* obj = self->unk1BC;
    void* arg = self->unk1D4;
    obj->call(arg);
    if (self->unk24C0 > 3) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, arg, lbl_14_data_404);
    }
}
}
