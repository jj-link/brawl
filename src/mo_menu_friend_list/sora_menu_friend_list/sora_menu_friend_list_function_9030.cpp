#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <string.h>

#pragma force_active on

extern "C" {
extern f32 lbl_14_rodata_4D8;
extern f64 lbl_14_rodata_4E0;
extern f32 lbl_14_rodata_4E8;
extern char lbl_14_data_584[];

s32 fn_16_998(void*, gfPadStatus*, char*, s32, s32);
f32 fn_16_AF8(void*);
int __cntlzw(unsigned int);
void fn_14_261C(void*);
void fn_14_F38(void*, char*);
void fn_14_F40(void*, char*, s32);
void fn_14_F58(void*, char*, s32);
void fn_14_F78(void*, char*);
void fn_8006BAB0(char*, char*, s32, s32);
s32 fn_8006CEEC(char*, s32);
void fn_800B5854(void*, s32, s32, s32, s32);
s32 printf__5MuMsgFUlPCce(void*, u32, const char*, ...);
}

class Slot9 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(f32);
};

class Slot13 {
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
    virtual void slot13(void*);
};

inline s32 runInput(char* self, gfPadStatus pad, char* text, gfPadStatus& tmp) {
    tmp.m_buttonsCurrentFrame = pad.m_buttonsCurrentFrame;
    tmp.m_buttonsCurrentFrame2 = pad.m_buttonsCurrentFrame2;
    tmp.m_buttonsHeld = pad.m_buttonsHeld;
    tmp.m_buttonsPressedThisFrame = pad.m_buttonsPressedThisFrame;
    tmp.m_buttonsReleasedThisFrame = pad.m_buttonsReleasedThisFrame;
    tmp.m_buttonsPressedThisFrame2 = pad.m_buttonsPressedThisFrame2;
    tmp._0x18 = pad._0x18;
    tmp._0x1c = pad._0x1c;
    tmp._0x20 = pad._0x20;
    tmp._0x24 = pad._0x24;
    tmp._0x28 = pad._0x28;
    tmp._0x2c = pad._0x2c;
    tmp.m_stickX = pad.m_stickX;
    tmp.m_stickY = pad.m_stickY;
    tmp.m_subStickX = pad.m_subStickX;
    tmp.m_subStickY = pad.m_subStickY;
    tmp.m_lTriggerAnalog = pad.m_lTriggerAnalog;
    tmp.m_rTriggerAnalog = pad.m_rTriggerAnalog;
    tmp._0x36 = pad._0x36;
    tmp._0x37 = pad._0x37;
    tmp.m_error = pad.m_error;
    tmp.m_controllerType = pad.m_controllerType;
    tmp.m_buttonsCurrentFrame2.bits = *(u32*)(self + 0x210);
    tmp.m_buttonsPressedThisFrame.bits = *(u32*)(self + 0x214);
    tmp.m_buttonsPressedThisFrame2.bits = *(u32*)(self + 0x218);
    return fn_16_998(self + 0x2570, &tmp, text, 1, 1);
}

inline s32 fetchInput(char* self, char* text, gfPadStatus& tmp) {
    gfPadStatus pad;
    g_gfPadSystem->getSysPadStatus(0xF0, &pad);
    return runInput(self, pad, text, tmp);
}

inline f32 calcFrame(s32 value, unsigned int add) {
    f32 frame = (f32)value;
    return add ? frame + lbl_14_rodata_4D8 : frame;
}

extern "C" s32 fn_14_9030(char* self) {
    s32 result;
    s32 accepted;
    gfPadStatus padCopy;
    char text[0x54];
    char buf2[0x54];
    char buf1[0x54];
    char buf3[0x54];

    result = *(s32*)(self + 0x24C4);
    accepted = 0;

    s32 input = fetchInput(self, text, padCopy);
    switch (input) {
    case 0:
        accepted = 1;
        result = 0x19;
        break;
    case 1:
        result = 0x19;
        break;
    case 2: {
        s32 mode = *(s32*)(self + 0x2510);
        if (mode != 0) {
            f32 frame = calcFrame(*(s32*)(self + 0x25F4), (unsigned int)__cntlzw((unsigned int)mode - 1) >> 5);
            ((MuObject*)*(void**)(self + 0xB4))->setFrameNode(frame);
            if (*(s32*)(self + 0x2510) == 1) {
                s32 index = *(s32*)(self + 0x2518);
                if (fn_8006CEEC(self + 0x251C, 0x7FFF) > 0xA) {
                    buf1[0] = 0;
                    fn_8006BAB0(buf1, self + 0x251C, 0, 0xA);
                    s32 len = strlen(buf1);
                    buf1[len] = 0xA;
                    strcpy(buf1 + len + 1, self + 0x251C + len);
                } else {
                    strcpy(buf1, self + 0x251C);
                }
                printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), index + 0x26, buf1);
            }
        }
        break;
    }
    case 0x7fffffff:
        break;
    default:
        break;
    }

    if (result != *(s32*)(self + 0x24C4)) {
        if (accepted != 0) {
            switch (*(s32*)(self + 0x2510)) {
            case 0:
                fn_14_F38(self, text);
                break;
            case 1:
                fn_14_F58(self, text, *(s32*)(self + 0x2518));
                break;
            case 2:
                fn_14_F78(self, text);
                break;
            }
        }

        switch (*(s32*)(self + 0x2510)) {
        case 0:
        case 2:
            fn_14_261C(self);
            break;
        case 1: {
            fn_14_F40(self, buf2, *(s32*)(self + 0x2518));
            s32 index = *(s32*)(self + 0x2518);
            if (fn_8006CEEC(buf2, 0x7FFF) > 0xA) {
                buf3[0] = 0;
                fn_8006BAB0(buf3, buf2, 0, 0xA);
                s32 len = strlen(buf3);
                buf3[len] = 0xA;
                strcpy(buf3 + len + 1, buf2 + len);
            } else {
                strcpy(buf3, buf2);
            }
            printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), index + 0x26, buf3);
            break;
        }
        }

        fn_16_AF8(self + 0x2570);
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), 0x2B, lbl_14_data_584);
        void* obj = *(void**)(self + 0xC0);
        ((MuObject*)obj)->setFrameNode(lbl_14_rodata_4E8);
        Slot9* target = *(Slot9**)(*(char**)((char*)obj + 0x14) + 0xC);
        target->slot8(lbl_14_rodata_4E8);
        fn_800B5854(obj, 8, 0x10, 1, 0);
        Slot13* action = *(Slot13**)(self + 0x1FC);
        action->slot13(*(void**)((char*)*(void**)(self + 0xB4) + 0x10));
    }

    return result;
}
