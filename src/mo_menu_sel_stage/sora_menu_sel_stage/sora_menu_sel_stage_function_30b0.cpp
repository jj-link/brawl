#include <mu/mu_object.h>
#include <gf/gf_task.h>
#include <snd/snd_system.h>
#include <ms/ms_message.h>
#include <string.h>
#include <stdio.h>

struct MenuView {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34(int, void*);
    virtual void f38();
    virtual void f3c(void*);
    char pad[0xe0];
    int e4;
};

struct StageResult {
    int kind;
    int stage;
    int extra;
};

struct GlobalState {
    char pad[0x388];
    int a;
    int b;
    int c;
    char pad394[4];
    unsigned char flag;
};

struct StageMenu {
    char p00[0x40];
    int mode;
    char p44[0xc];
    MenuView* view;
    char p54[8];
    MuObject* obj5c;
    char p60[0x19c];
    MuObject* obj1fc;
    MuObject* obj200;
    char p204[4];
    MuObject* obj208;
    char p20c[0x18];
    int state;
    char p228[0x1c];
    int flag244;
    char p248[0xc];
    int resultKind;
    int resultStage;
    char p25c[0x18];
    int busy;
    char p278[0x5df0];
    void* data6068;
    gfTask* task;
    void* message;
    char p6074[4];
    void* timerView;
    int timer;
    char p6080[4];
    unsigned char field6084;
    unsigned char field6085;
    char p6086[0xbe];
    unsigned char flag6144;
    char p6145[3];
    int status6148;
    char p614c[8];
    StageResult result;
    int flag6160;
};

extern "C" {
extern void* g_muWifiInterfaceTask;
extern GlobalState* lbl_11_bss_8;
extern const float lbl_11_rodata_0[];
extern const float lbl_11_rodata_114[];
extern char lbl_11_data_35C[];

int fn_800CBCB0(void*, int*);
int fn_800C9B00(int);
int fn_800C9B14(int);
int fn_800CCA9C(void*, int*, int*);
int fn_800D69C8(void*, int);
int fn_800D4EF0(void*, void*, void*, int*);
int fn_800CA18C(void*);
void fn_800DA6EC(void*, int, int);
gfTask* fn_800BEEB8(int, void*, int, void*, MenuView*, int, int, int,
                     int, int, int, int);
void fn_800BF928(gfTask*, char*);
void fn_11_4270(StageMenu*, void*);
void fn_11_6B6C(StageResult*, StageMenu*, int);
int exchangeMuStageKindToSrStageKind__6muMenuFiii(int);
}

#define CLOSE_TASK()                                                        \
    do {                                                                    \
        if (self->task) {                                                   \
            if (self->task) {                                               \
                self->task->exit();                                         \
                self->task = 0;                                             \
            }                                                               \
            g_sndSystem->playSE((SndID)6, -1, 0, 0, -1);                   \
            self->view->f34(self->view->e4, self->obj200->m_sceneModel);    \
        }                                                                   \
    } while (0)

inline void resetObj(MuObject* obj) {
    obj->setFrameMatCol(lbl_11_rodata_0[0]);
    obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_11_rodata_0[0]);
}
#define RESET_OBJECTS()                                                     \
    do {                                                                    \
        self->flag244 = 0;                                                  \
        resetObj(self->obj5c);                                              \
        resetObj(self->obj1fc);                                             \
    } while (0)

#define NEW_DIALOG(id)                                                      \
    do {                                                                    \
        self->view->f3c(self->obj200->m_sceneModel);                        \
        self->task = fn_800BEEB8(                                           \
            0, self->message, id, self->data6068, self->view,              \
            0x17, 0, 0x2a, 0x2a, 0, 0, 0xf0);                              \
    } while (0)

inline void recordStage(int value) {
    lbl_11_bss_8->flag = 1;
    GlobalState* bss = lbl_11_bss_8;
    if (bss->c == 0) {
        bss->c = 1;
        bss->a = 0;
        bss->b = value;
    }
}

#pragma force_active on
extern "C" void fn_11_30B0(StageMenu* self) {
    void* wifi = g_muWifiInterfaceTask;
    int id2;
    int error, number;
    unsigned long length;
    char* text;
    int extra;
    char response[12];
    char buffer[128];

    if (self->busy != 0)
        return;

    if (self->state != 8) {
        error = fn_800CBCB0(wifi, &number);
        if (error != 0) {
            CLOSE_TASK();
            int id = fn_800C9B00(error);
            RESET_OBJECTS();
            NEW_DIALOG(id);

            if (fn_800C9B14(error)) {
                Message::getPrintIndexData(self->message, 0x13, &text, &length);
                memcpy(buffer, text, length);
                length += sprintf(buffer + length, lbl_11_data_35C, number);
                fn_800BF928(self->task, buffer);
            }
            self->state = 8;
        }
    }

    if (self->state == 8)
        return;

    if (self->flag6144 && self->status6148 != 2) {
        id2 = -1;
        if (self->status6148 == 0) {
            switch (fn_800CCA9C(wifi, &error, &number)) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                self->status6148 = 1;
                break;
            case 6:
                id2 = 0x1b;
                break;
            case 7:
                id2 = 0x1c;
                break;
            }
        } else {
            switch (fn_800D69C8(wifi, 0)) {
            case 1:
                self->status6148 = 2;
                break;
            case 2:
                id2 = 0x1b;
                break;
            case 0:
                break;
            }
        }

        if (id2 >= 0) {
            CLOSE_TASK();
            RESET_OBJECTS();
            NEW_DIALOG(id2);
            self->state = 8;
            self->status6148 = 3;
            return;
        }
    }

    if ((self->state == 0 || self->state == 7) &&
        fn_800D4EF0(wifi, response, &self->field6084, &extra)) {
        self->field6085 = extra;
        CLOSE_TASK();
        fn_11_4270(self, response);
        self->state = 9;
    }

    int visibleFrame = fn_800CA18C(g_muWifiInterfaceTask);
    self->obj208->setFrameVisible((float)visibleFrame);

    bool allowed = false;
    if ((unsigned int)(self->mode - 1) <= 5 &&
        ((1U << (self->mode - 1)) & 0x29))
        allowed = true;

    bool active;
    if (!allowed) {
        active = false;
    } else {
        switch (self->state) {
        case 0:
        case 7:
        case 9:
            active = true;
            break;
        default:
            active = false;
            break;
        }
    }

    if (active && self->timer > 0) {
        int t = --self->timer;
        if (t <= 300 && t % 60 == 0)
            g_sndSystem->playSE((SndID)10, -1, 0, 0, -1);

        fn_800DA6EC(self->timerView, (self->timer + 59) / 60, 0);

        if (self->timer == 0) {
            CLOSE_TASK();
            RESET_OBJECTS();

            StageResult temp;
            fn_11_6B6C(&temp, self, 0);
            StageResult result = temp;
            if (result.kind != 2) {
                self->resultKind = 1;
                self->resultStage =
                    exchangeMuStageKindToSrStageKind__6muMenuFiii(
                        result.extra);
            } else {
                self->resultStage = result.stage;
                self->resultKind = 3;
            }

            if (result.kind == 2) {
                recordStage(result.stage);
                self->flag6160 = 1;
            }

            self->result = result;
            self->state = 4;
            self->obj200->setFrameVisible(lbl_11_rodata_114[0]);
        }
    }
}
