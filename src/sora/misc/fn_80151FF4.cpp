#include <revolution/OS/OSMutex.h>
#include <revolution/DWC/dwc_error.h>
#pragma force_active on

struct Callback {
    virtual void f1(s32 type, s32 error);
};

struct Self {
    unsigned char pad_00[0x40];
    s32 state40;
    s32 state44;
    u8 initialized48;
    unsigned char pad_49[7];
    Callback* callback50;
    unsigned char pad_54[8];
    u8 flag5c;
};

struct Guard {
    OSMutex* mutex;
    unsigned char flag : 8;
};

extern "C" {
extern OSMutex lbl_8049ED08;
extern s32 lbl_805A03EC;
extern s32 lbl_805A03F0;
extern s32 lbl_805A03F4;

s32 fn_80358E3C(s32 arg);
}

extern "C" s32 fn_80151FF4(Self* self, s32 arg) {
    if (self->initialized48 == 0)
        return 1;

    s32 busy = 0;
    if (self->state40 == 1 || self->state44 != 0)
        busy = 1;
    if (busy != 0)
        return 0;

    Guard guard;
    Guard* p = &guard;
    p->flag = 1;
    p->mutex = &lbl_8049ED08;
    if (p->flag != 0)
        OSLockMutex(p->mutex);

    if (fn_80358E3C(arg) != 0) {
        s32 errorType;
        s32 errorCode;
        s32 result = 0;

        if (self->flag5c != 0) {
            result = lbl_805A03EC;
            errorCode = -lbl_805A03F0;
            errorType = lbl_805A03F4;
        }

        if (result == 0)
            result = DWC_GetLastErrorEx(&errorCode, &errorType);

        if (result != 0) {
            if (self->callback50 != 0) {
                if (errorCode < 0)
                    errorCode = -errorCode;
                self->callback50->f1(errorCode, errorType);
            }
            if (self->flag5c == 0)
                DWC_ClearError();
        }

        if (p->flag != 0)
            OSUnlockMutex(p->mutex);
        return 0;
    }

    if (p->flag != 0)
        OSUnlockMutex(p->mutex);

    s32 busy2 = 0;
    if (self->state40 == 1 || self->state44 != 0)
        busy2 = 1;
    if (busy2 != 0)
        return 0;

    self->state44 = 4;
    self->state40 = 1;
    return 1;
}
