#pragma force_active on
#include <snd/snd_system.h>
#include <gf/gf_file_io_handle.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
extern "C" {
void fn_8019D950(void*);
extern const float lbl_6_rodata_1C4;
extern const float lbl_6_rodata_1C8;
extern char lbl_6_data_0[];
}
struct ViewerData {
    char pad0[0x160];
    MuObject* object160;
    char pad164[0x1A0 - 0x164];
    int value;
    char pad1A4[0x1C0 - 0x1A4];
    int mode;
    char pad1C4[0x1B50 - 0x1C4];
    u32 input;
    char pad1B54[0x1BFC - 0x1B54];
    int state;
    int previousState;
    char pad1C04[0x1C14 - 0x1C04];
    bool blocked : 1;
    unsigned int timer : 16;
    unsigned int rest : 15;
    MuObject* object;
    MuMsg* currentMessage;
    u32 messageIndex;
    char pad1C24[0x1C7C - 0x1C24];
    MuMsg* message;
    char pad1C80[0x1CA8 - 0x1C80];
    gfFileIOHandle handle;
    char pad1CAC[0x1CC0 - 0x1CAC];
    gfFileIOHandle handle2;
    void show(u32 index, void* buffer) {
        MuMsg* msg = message;
        object->setFrameVisible(lbl_6_rodata_1C8);
        timer = 120;
        currentMessage = msg;
        messageIndex = 16;
        msg->printIndex(16, index, buffer);
    }
};
struct ViewerBase { char pad0[0x3C]; };
struct Viewer : ViewerBase {
    virtual void at8();
    virtual void atC();
    virtual void at10();
    virtual void at14();
    virtual void at18();
    virtual void at1C();
    virtual void at20();
    virtual void at24();
    virtual void at28();
    virtual void at2C();
    virtual void at30();
    virtual void at34();
    virtual void at38();
    virtual void at3C();
    virtual void at40();
    virtual void at44();
    virtual void at48();
    virtual void at4C();
    virtual void at50();
    virtual void at54();
    virtual void at58();
    virtual void at5C();
    virtual void at60();
    virtual void at64();
    virtual void at68();
    virtual void at6C();
    virtual void at70();
    virtual void at74();
    virtual void at78();
    virtual void at7C();
    virtual void at80();
    virtual void at84();
    virtual void at88();
    virtual void at8C();
    virtual void at90();
    virtual void at94();
    virtual void at98();
    virtual void at9C();
    virtual void atA0();
    virtual void atA4();
    virtual void atA8();
    virtual void atAC();
    virtual void atB0();
    virtual void atB4(void*);
    virtual void atB8();
    virtual void atBC();
    virtual void atC0();
    virtual void atC4();
    virtual void atC8();
    virtual void atCC();
    virtual void atD0();
    virtual void atD4();
    virtual void atD8();
    virtual void atDC();
    virtual void atE0();
    virtual void atE4();
    virtual void atE8(int, int);
    virtual void atEC();
    virtual void atF0();
    virtual void atF4();
    virtual void atF8();
    virtual void atFC();
    virtual void at100();
    virtual void at104();
    virtual void at108();
    virtual void at10C();
    virtual void at110();
    virtual void at114();
    virtual void at118();
    virtual void at11C();
    virtual void at120(int, int);
    virtual void at124();
    virtual void at128();
    virtual void at12C();
    virtual void at130();
    virtual void at134();
    virtual void at138();
    virtual void at13C();
    virtual void at140();
    virtual void at144();
    virtual void at148();
    virtual void at14C();
    virtual void at150();
    virtual void at154();
    virtual void at158();
    virtual void at15C();
    virtual void at160();
    virtual void at164();
    virtual void at168();
    virtual void at16C();
    virtual void at170();
    virtual void at174(int, int);

    char pad40[0x1A8 - 0x40];
    u32 flags;
    ViewerData* data;
};
extern "C" void fn_6_6AE8(Viewer* self) {
    if (self->flags & 2) {
        ViewerData* data = self->data;
        if (data->blocked) {
            g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
            ViewerData* d = self->data;
            if ((int)(d->value == 0) == 1) {
                if (d->mode == 3) {
                    MuMsg* msg;
                    void* buffer = d->handle2.getBuffer();
                    ViewerData* p = self->data;
                    msg = p->message;
                    p->object->setFrameVisible(lbl_6_rodata_1C8);
                    p->timer = 120;
                    p->currentMessage = msg;
                    p->messageIndex = 16;
                    msg->printIndex(16, 0x51, buffer);
                } else {
                    ViewerData* p;
                    MuMsg* msg;
                    void* buffer = d->handle.getBuffer();
                    p = self->data;
                    msg = p->message;
                    p->object->setFrameVisible(lbl_6_rodata_1C8);
                    p->timer = 120;
                    p->currentMessage = msg;
                    p->messageIndex = 16;
                    msg->printIndex(16, 7, buffer);
                }
            }
        } else {
            if (data->currentMessage) {
                data->timer = 0;
                data->object->setFrameVisible(lbl_6_rodata_1C4);
                data->currentMessage->printf(data->messageIndex, lbl_6_data_0);
                data->currentMessage = 0;
                if (!data->blocked) {
                    fn_8019D950(data->object->m_sceneModel);
                }
            }
            self->at174(1, self->data->value);
            self->data->state = 10;
            self->atB4(self->data->object160->m_sceneModel);
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        }
    } else if ((self->data->input & 8) || (self->flags & 4)) {
        self->data->previousState = self->data->state;
        self->data->state = 0;
        self->atE8(1, 1);
        g_sndSystem->playSE((SndID)((self->flags & 4) ? 2 : 0), -1, 0, 0, -1);
    } else if (self->data->input & 1) {
        self->data->state = 7;
        self->atE8(6, 1);
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    } else if (self->data->input & 2) {
        self->data->state = 30;
        self->atE8(8, 1);
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    } else {
        self->at120(0, 5);
    }
}
