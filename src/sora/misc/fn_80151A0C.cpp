#include <types.h>
#include <revolution/DWC/dwc_error.h>
#pragma force_active on

struct Callback {
    virtual void f0(s32, s32);
};

struct Self {
    unsigned char pad_00[0x344];
    s32 a344;
    s32 a348;
    unsigned char pad_34c[8];
    Callback* callback354;
    u8 flag358;
};

extern "C" {
extern char lbl_8046134C[0x1C];
extern s32 lbl_805A03EC;
extern s32 lbl_805A03F0;
extern s32 lbl_805A03F4;
extern u8 lbl_805A03F8;
void netReport__FPCce(const char*, ...);
}

extern "C" s32 fn_80151A0C(Self* self) {
    s32 errCode;
    s32 errType;
    s32 result = 0;

    if (self->flag358 != 0) {
        result = lbl_805A03EC;
        errCode = -lbl_805A03F0;
        errType = lbl_805A03F4;
        if (lbl_805A03F8 != 0) {
            lbl_805A03F8 = 0;
            self->a344 = 0;
            self->a348 = 0;
            netReport__FPCce(lbl_8046134C);
            return 1;
        }
    }
    if (result == 0)
        result = DWC_GetLastErrorEx(&errCode, &errType);
    if (result == 0)
        return 1;
    if (errCode == -0x7940) {
        self->a344 = 0;
        self->a348 = 0;
        netReport__FPCce(lbl_8046134C);
        DWC_ClearError();
        return 1;
    }
    if (self->callback354 != 0) {
        if (errCode < 0)
            errCode = -errCode;
        self->callback354->f0(errCode, errType);
    }
    if (self->flag358 == 0)
        DWC_ClearError();
    return 0;
}
