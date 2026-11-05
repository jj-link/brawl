#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(s32);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(s32, s32);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(s32);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(s32);
};

struct Mid {
    char pad0[0x20];
    Inner* p20;
    char pad1[0x1c];
    Inner* p40;
    char pad2[0x14];
    Inner* p58;
    char pad3[0x2c];
    Inner* p88;
};

struct Self {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_184554(void* unused, Self* self, s32 code) {
    switch (code) {
    case 0xd2:
        return;
    default:
        self->mid->p40->v10(1, 0);
        self->mid->p20->v26(0);
        self->mid->p58->v7(1);
        self->mid->p88->v33(1);
        break;
    }
}
