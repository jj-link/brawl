#pragma force_active on
#include <types.h>
#include <ec/ec_mgr.h>
#include <mu/mu_msg.h>
#include <snd/snd_system.h>

extern "C" {
extern float lbl_27_rodata_61C8;
extern float lbl_27_rodata_61E8;
extern char lbl_27_data_7B420[];
void* fn_800607C8(void*, u32);
}

struct ModelIface {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void setOption(int, int);
};

struct Object {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 effectHandle;
    MuMsg* message;
    u32 messageIndex;
    s32 field18;
    s32 field1C;
    s32 field20;
    u32 field24;
};

extern "C" void fn_27_2D5AB4(Object* self, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    void* model;
    ecMgr* const mgr = g_ecMgr;
    model = fn_800607C8(mgr, self->effectHandle);
    if (model != NULL) {
        ((ModelIface*)model)->setOption(1, 0);
        ((ModelIface*)model)->setOption(6, 0);
        ((ModelIface*)model)->setOption(7, 0);
    }

    mgr->setMdlFrame(self->effectHandle, (arg2 >= 0) ? lbl_27_rodata_61C8 : lbl_27_rodata_61E8, 2);
    mgr->setMdlFrame(self->effectHandle, (arg4 == 1) ? lbl_27_rodata_61E8 : lbl_27_rodata_61C8, 0x10);
    mgr->setMdlAnmIdx(self->effectHandle, 0, 1);

    self->field18 = arg1;
    self->field1C = arg2;
    self->field20 = arg3;

    if (arg2 >= 0) {
        self->message->setFontColor(self->messageIndex, 0, 0, 0, 0xFF);
        self->message->printIndex(self->messageIndex, self->field18, NULL);
        self->message->printf(self->messageIndex + 3, lbl_27_data_7B420);
    } else {
        self->message->setFontColor(self->messageIndex + 3, 0, 0, 0, 0xFF);
        self->message->printIndex(self->messageIndex + 3, self->field18, NULL);
        self->message->printf(self->messageIndex, lbl_27_data_7B420);
    }

    s32* ptr = (s32*)&self->field04;
    for (s32 k = 1; k < 3; k++) {
        self->message->setFontColor(self->messageIndex + k, 0, 0, 0, 0xFF);
        s32 v = ptr[6];
        if (v < 0) {
            self->message->printf(self->messageIndex + k, lbl_27_data_7B420);
        } else {
            self->message->printIndex(self->messageIndex + k, v, NULL);
        }
        ptr++;
    }

    self->field00 = 1;
    self->field08 = arg4;
    self->field04 = 0;
    self->field24 = arg5 | 0x100;
    g_sndSystem->playSE((SndID)5, -1, 0, 0, -1);
}
