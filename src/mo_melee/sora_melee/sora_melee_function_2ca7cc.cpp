#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" {
void fn_27_2CBEF0(void* self, int a, int b);
void fn_27_2CEF48(void* self, u32 a, int b, int c);
void* fn_800607C8(ecMgr* mgr, u32 key);
}

extern u8* lbl_27_bss_7328;

class NullableVtbl {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
};

struct Self {
    u8 pad0[0x6A6];
    u8 unk6A6;
    u8 pad6A7[0x6D8 - 0x6A7];
    u8 unk6D8[0x42E1 - 0x6D8];
    u8 unk42E1;
    u8 pad42E2[0x439C - 0x42E2];
    u32 unk439C;
    u8 pad43A0[0x447C - 0x43A0];
    u8 unk447C[0x4488 - 0x447C];
    u32 unk4488;
    u8 pad448C[0x1ADB8 - 0x448C];
    u8 unk1ADB8;
    u8 pad1ADB9[0x1ADBC - 0x1ADB9];
    u32 unk1ADBC;
    u8 pad1ADC0[0x1AF28 - 0x1ADC0];
    u8 unk1AF28;
    u8 pad1AF29[0x1AF2B - 0x1AF29];
    u8 unk1AF2B;
    u8 pad1AF2C[0x1AFA4 - 0x1AF2C];
    u32 unk1AFA4;
    u8 pad1AFA8[0x1AFDC - 0x1AFA8];
    u32 unk1AFDC;
    u8 pad1AFE0[0x1B000 - 0x1AFE0];
    u32 unk1B000;
    u8 pad1B004[0x1B00C - 0x1B004];
    u32 unk1B00C;
    u32 unk1B010;
};

extern "C" void fn_27_2CA7CC(Self* self) {
    ecMgr* mgr = g_ecMgr;
    s8 state = (s8)self->unk1AF28;

    switch (state) {
    case 3: {
        NullableVtbl* model = (NullableVtbl*)fn_800607C8(mgr, self->unk1ADBC);
        if (model != NULL) {
            model->slot6(1, 0);
            model->slot6(6, 0);
            model->slot6(7, 0);
        }
        goto finish;
    }
    }

    switch (state) {
    case 2:
        self->unk1B000 = 4;
        mgr->setMdlAnmIdx(*(u32*)(lbl_27_bss_7328 + 0x1AF94), 4, 1);
        mgr->setMdlAnmIdx(self->unk1AFA4, 1, 1);
        fn_27_2CBEF0(self->unk6D8, self->unk1B00C, self->unk1B010);
        break;
    case 1:
        mgr->setMdlAnmIdx(self->unk1AFDC, 1, 1);
        break;
    }

    self->unk439C = 0;
    self->unk42E1 = (u8)(self->unk42E1 | 0xC);
    if (self->unk6A6 != 0) {
        if (self->unk1ADB8 == 0) {
            fn_27_2CEF48(self->unk447C, self->unk4488, 0, 1);
        }
    }

finish:
    self->unk1AF28 = 0;
    self->unk1AF2B = 0x14;
}
