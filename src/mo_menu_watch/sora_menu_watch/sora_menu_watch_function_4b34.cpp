#include <types.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" {
extern char lbl_15_data_288[];
extern const float lbl_15_rodata_0;
}

class Iface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void* arg);
};

struct Sub {
    u8 pad0[0x10];
    void* field10;
};

struct Self {
    u8 pad0[0x64];
    MuObject* obj64[4];
    u8 pad1[0x78 - 0x74];
    Sub* sub78;
    u8 pad2[0x194 - 0x7C];
    Iface* iface194;
    void* field198;
    u8 pad3[0x24C - 0x19C];
    MuMsg* msg24C;
    u8 pad4[0x4EC - 0x250];
    s32 state4EC;
    u8 pad5[0x504 - 0x4F0];
    s32 field504;
    u8 pad6[0xD54 - 0x508];
    s32 counter;
};

extern "C" s32 fn_15_4B34(Self* self) {
    s32 i;
    Self* p;
    s32 ret;
    s32 t = self->counter - 1;
    self->counter = t;
    if (t < 0) {
        self->msg24C->printf(0, lbl_15_data_288);
        switch (self->state4EC) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 5:
            ret = 0;
            break;
        case 4:
            ret = 9;
            break;
        }
        f32 f = lbl_15_rodata_0;
        p = self;
        for (i = 0; i < 4; i++) {
            p->obj64[0]->setFrameVisible(f);
            p = (Self*)((u8*)p + 4);
        }
        Iface* o = self->iface194;
        void* v = self->field198;
        o->slot13(self->sub78->field10);
        o->slot13(v);
    } else {
        if (t == 4) {
            g_sndSystem->playSE((SndID)0x1EFD, -1, 0, 0, -1);
        }
        ret = self->field504;
    }
    return ret;
}
