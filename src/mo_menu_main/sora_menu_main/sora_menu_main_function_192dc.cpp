#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on

struct Class_728_base {
    char pad[0x3c];
};

class Class_728 : public Class_728_base {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(int, int, int);
};

struct MenuObject {
    char pad00[0x1c];
    int field1c;
};

struct MenuState {
    char pad000[0x42];
    unsigned short mode;
    char pad044[0x608];
    MenuObject** objects;
    char pad650[8];
    Class_728* task;
    char pad65c[0x10];
    int controllerType[8];
    unsigned short selected;
    unsigned short first;
    unsigned short row;
    char pad692[2];
    MuMsg* msg;
};

struct Entry {
    char pad[0xec];
    unsigned char enabled;
};

extern "C" {
extern void* g_GameGlobal;
extern const float lbl_2_rodata_660[];
extern char lbl_2_data_2328[];
extern char lbl_2_data_23A0[];

void fn_18_17B0(MenuState*, int, int, float);
Entry* fn_8004D138(void*, int);
int fn_8004D148(void*);
int fn_8004D6C4(void*, int, char*);
int fn_8004DA94(void*, int);
void fn_8004DAB0(void*, int, int);
void fn_800557A8();
void fn_800B330C(MenuObject*, void*, int);
}

extern "C" int fn_2_192DC(MenuState* self, int buttons)
{
    const float* ro = lbl_2_rodata_660;
    int result = 0;
    int change = 0;
    void* global = g_GameGlobal;
    char text[0x18];

    if (buttons & 4) {
        if (self->mode == 1)
            change = 1;
    } else if (buttons & 8) {
        if (self->mode == 0)
            change = 1;
    } else if (self->mode == 0) {
        for (unsigned int i = 0; i < 8; ++i) {
            gfPadStatus status;
            g_gfPadSystem->getSysPadStatus((unsigned short)i, &status);
            if ((status.m_buttonsPressedThisFrame.bits & 0x100) &&
                self->controllerType[(unsigned short)i] != 1) {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                fn_800557A8();
                if (fn_8004DA94(global, (unsigned short)i)) {
                    fn_8004DAB0(global, (unsigned short)i, 0);
                } else {
                    fn_8004DAB0(global, (unsigned short)i, 1);
                    g_gfPadSystem->startMotor((unsigned short)i, 0x14);
                    switch (self->controllerType[(unsigned short)i]) {
                    case 0:
                        fn_800B330C(self->objects[0x2c + (unsigned short)i % 4],
                                     lbl_2_data_23A0, 0);
                        break;
                    case 1:
                        fn_800B330C(self->objects[0x30 + (unsigned short)i % 4],
                                     lbl_2_data_23A0, 0);
                        break;
                    case 3:
                        fn_800B330C(self->objects[0x34 + (unsigned short)i % 4],
                                     lbl_2_data_23A0, 0);
                        break;
                    case 2:
                        fn_800B330C(self->objects[0x38 + (unsigned short)i % 4],
                                     lbl_2_data_23A0, 0);
                        break;
                    }
                }
            }
        }
    } else if (buttons & 1) {
        if (self->selected != 0) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            --self->selected;
            if (self->row != 0) {
                fn_18_17B0(self, self->row + 0x44, 0x10, ro[3]);
                self->msg->setFontColor(self->row, 0x80, 0x80, 0x80, 0xff);
                fn_8004D6C4(global, self->row + self->first, text);
                self->msg->printf(self->row, text);
                --self->row;
                fn_18_17B0(self, self->row + 0x44, 0x10, ro[2]);
                self->msg->setFontColor(self->row, 0x19, 0x19, 0x19, 0xff);
                fn_8004D6C4(global, self->row + self->first, text);
                self->msg->printf(self->row, text);
            } else {
                --self->first;
                if (self->first == 0)
                    fn_18_17B0(self, 0x2b, 2, ro[2]);
                else
                    fn_18_17B0(self, 0x2b, 2, ro[6]);

                for (int i = 0; i < 5; ++i) {
                    if (fn_8004D6C4(global, i + self->first, text)) {
                        if (fn_8004D138(global, i + self->first)->enabled == 1)
                            fn_18_17B0(self, i + 0x44, 4, ro[1]);
                        else
                            fn_18_17B0(self, i + 0x44, 4, ro[2]);
                        self->msg->printf(i, text);
                    } else {
                        fn_18_17B0(self, i + 0x44, 4, ro[3]);
                    }
                }
            }
        }
    } else if (buttons & 2) {
        if (self->selected < fn_8004D148(global) - 1) {
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
            ++self->selected;
            if (self->row < 4) {
                fn_18_17B0(self, self->row + 0x44, 0x10, ro[3]);
                self->msg->setFontColor(self->row, 0x80, 0x80, 0x80, 0xff);
                fn_8004D6C4(global, self->row + self->first, text);
                self->msg->printf(self->row, text);
                ++self->row;
                fn_18_17B0(self, self->row + 0x44, 0x10, ro[2]);
                self->msg->setFontColor(self->row, 0x19, 0x19, 0x19, 0xff);
                fn_8004D6C4(global, self->row + self->first, text);
                self->msg->printf(self->row, text);
            } else {
                ++self->first;
                if (self->first == fn_8004D148(global) - 5)
                    fn_18_17B0(self, 0x2b, 2, ro[1]);
                else
                    fn_18_17B0(self, 0x2b, 2, ro[6]);

                for (int i = 0; i < 5; ++i) {
                    if (fn_8004D6C4(global, i + self->first, text)) {
                        if (fn_8004D138(global, i + self->first)->enabled == 1)
                            fn_18_17B0(self, i + 0x44, 4, ro[1]);
                        else
                            fn_18_17B0(self, i + 0x44, 4, ro[2]);
                        self->msg->printf(i, text);
                    } else {
                        fn_18_17B0(self, i + 0x44, 4, ro[3]);
                    }
                }
            }
        }
    } else if (buttons & 0x200) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        fn_800557A8();
        for (int i = 0; i < 8; ++i) {
            gfPadStatus status;
            g_gfPadSystem->getSysPadStatus(i, &status);
            if (status.m_buttonsPressedThisFrame.bits & 0x100) {
                if (fn_8004D138(global, self->selected)->enabled == 1) {
                    fn_8004D138(global, self->selected)->enabled = 0;
                    fn_18_17B0(self, self->row + 0x44, 4, ro[2]);
                } else {
                    g_gfPadSystem->startMotor(i, 0x14);
                    fn_8004D138(global, self->selected)->enabled = 1;
                    fn_18_17B0(self, self->row + 0x44, 4, ro[1]);
                }
            }
        }
    }

    if (change && fn_8004D148(global) > 0) {
        self->mode ^= 1;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        self->task->slot23(self->mode + 0x40, 1, 0);
        int previous = self->mode ^ 1;
        result = 1;
        fn_800B330C(self->objects[previous + 0x2a],
                     lbl_2_data_2328 + 0x14, 1);
        self->objects[previous + 0x2a]->field1c = 0;
        fn_18_17B0(self, previous + 0x2a, 0x11, ro[5]);
        fn_800B330C(self->objects[self->mode + 0x2a],
                     lbl_2_data_2328 + 0x3c, 1);
        if (self->mode == 1) {
            fn_18_17B0(self, self->row + 0x44, 0x10, ro[2]);
            self->msg->setFontColor(self->row, 0x19, 0x19, 0x19, 0xff);
            fn_8004D6C4(global, self->row + self->first, text);
            self->msg->printf(self->row, text);
        } else {
            fn_18_17B0(self, self->row + 0x44, 0x10, ro[3]);
            self->msg->setFontColor(self->row, 0x80, 0x80, 0x80, 0xff);
            fn_8004D6C4(global, self->row + self->first, text);
            self->msg->printf(self->row, text);
        }
    }
    return result;
}
