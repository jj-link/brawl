#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSError.h>
#include <revolution/DWC/dwc_error.h>
#pragma force_active on

struct Callback {
    virtual void f1(s32 type, s32 error);
};

struct Self {
    unsigned char pad_00[0x40];
    s32 state40;
    s32 state44;
    u8 flag48;
    unsigned char pad_49[3];
    Callback* cb4C;
    Callback* cb50;
    s32 field54;
    s32 field58;
    u8 flag5c;
};

struct Guard {
    OSMutex* mutex;
    unsigned char flag : 8;
};

extern "C" {
extern OSMutex lbl_8049EC30;
extern OSMutex lbl_8049ED08;
extern s32 lbl_805A03EC;
extern s32 lbl_805A03F0;
extern s32 lbl_805A03F4;
extern char lbl_80461390[];
s32 fn_801DEDC4(OSMutex* m);
s32 fn_80358CD4(void);
void fn_803359CC(void);
}

extern "C" void fn_80152338(Self* self) {
    char* base = lbl_80461390;
    s32 errorType;
    s32 errorCode;
    if (self->state40 == 1) {
        s32 r28 = 0;
        if (fn_801DEDC4(&lbl_8049EC30) != 0) {
            Guard guard;
            Guard* p = &guard;
            p->flag = 1;
            p->mutex = &lbl_8049ED08;
            if (p->flag != 0) OSLockMutex(p->mutex);
            s32 r30 = fn_80358CD4();
            if (p->flag != 0) OSUnlockMutex(p->mutex);
            OSUnlockMutex(&lbl_8049EC30);

            switch (self->state44) {
            case 3:
                if (r30 == 4) {
                    OSReport(base + 0x16C);
                    OSReport(base + 0x1B4);
                    fn_803359CC();
                    self->flag48 = 0;
                    OSReport(base + 0x1E8);
                    break;
                }
                return;
            case 1:
            case 2:
            case 4:
                switch (r30) {
                case 0:
                case 4: break;
                case 2: return;
                case 3: r28 = 2; break;
                case 9: r28 = 4; break;
                case 10: r28 = 5; break;
                case 11: r28 = 6; break;
                case 5: r28 = 7; break;
                case 6: r28 = 8; break;
                case 7: r28 = 9; break;
                case 8: r28 = 10; break;
                default: r28 = 3; break;
                }
                break;
            default:
                break;
            }

            self->field54 = self->state44;
            if (r28 != 0) {
                OSReport(base + 0x220, r28);
                self->field58 = r28;
            }
            OSReport(base + 0x22C);
            self->state44 = 0;
            self->state40 = 0;
            if (r28 == 2) {
                s32 r3v = 0;
                if (self->flag5c != 0) {
                    r3v = lbl_805A03EC;
                    errorCode = -lbl_805A03F0;
                    errorType = lbl_805A03F4;
                }
                if (r3v == 0) r3v = DWC_GetLastErrorEx(&errorCode, &errorType);
                if (r3v != 0) {
                    if (self->cb50 != 0) {
                        if (errorCode < 0) errorCode = -errorCode;
                        self->cb50->f1(errorCode, errorType);
                    }
                    if (self->flag5c == 0) DWC_ClearError();
                }
            }
            if (self->cb4C != 0) self->cb4C->f1(self->field54, self->field58);
        }
    }
}
