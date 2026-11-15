#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#pragma force_active on

extern f32 lbl_14_rodata_4D0;
extern f64 lbl_14_rodata_4C8;

extern "C" {
s32 fn_16_998(void* self, gfPadStatus* pad, char* text, s32 a, s32 b);
void fn_14_864(void* self, s64 v, char* text, s32 a, s32 b, s32 c, char* d, s32 e);
void fn_14_10C0(void* self);
void fn_14_2DD0(void* self, f32 x);
void fn_14_39B4(void* self, u32 v);
void fn_14_2DC8(void* self);
}

struct Node {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12(s32 n);
    virtual void f13();
    virtual void f14(s32 n);
    char _04[0xE0];
    s32 m_count;
};

struct Self {
    char _000[0x0B4];
    MuObject* m_obj;
    char _0B8[0x1FC - 0x0B8];
    Node* m_node;
    char _200[0x210 - 0x200];
    u32 m_210;
    u32 m_214;
    u32 m_218;
    char _21C[0x24C0 - 0x21C];
    s32 m_count;
    s32 m_state;
    char _24C8[0x24E4 - 0x24C8];
    s32 m_saved;
    char _24E8[0x2500 - 0x24E8];
    char m_digits[0x70];
    char m_sub[0x84];
    s32 m_25F4;
};

inline s32 runInput(Self* self, gfPadStatus pad, char* text, gfPadStatus& tmp) {
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
    tmp.m_buttonsCurrentFrame2.bits = self->m_210;
    tmp.m_buttonsPressedThisFrame.bits = self->m_214;
    tmp.m_buttonsPressedThisFrame2.bits = self->m_218;
    return fn_16_998(self->m_sub, &tmp, text, 1, 1);
}

inline s32 fetchInput(Self* self, char* text, gfPadStatus& tmp) {
    gfPadStatus pad;
    g_gfPadSystem->getSysPadStatus(0xF0, &pad);
    return runInput(self, pad, text, tmp);
}

extern "C" s32 fn_14_7EC4(Self* self) {
    s32 result = self->m_state;
    char flag = 0;
    char text[0x1C];
    gfPadStatus tmp;
    s32 r = fetchInput(self, text, tmp);
    switch (r) {
    case 0: {
        s64 v = 0;
        s32 i = 0;
        while (i < 0xC && self->m_digits[i] != 0) {
            v = v * 10 + (self->m_digits[i] - 0x30);
            i++;
        }
        fn_14_864(self, v, text, 0, 0, 0, &flag, 0);
        fn_14_10C0(self);
        s32 n = self->m_count - 3;
        if (n < 0) {
            n = 0;
        }
        self->m_saved = n;
        fn_14_2DD0(self, (f32)n);
        fn_14_39B4(self, (u32)(self->m_count - n - 1));
        fn_14_2DC8(self);
        result = 0x14;
        break;
    }
    case 1:
        result = 0x17;
        break;
    case 2:
        self->m_obj->setFrameNode((f32)self->m_25F4);
        break;
    case 0x7fffffff:
        break;
    default:
        break;
    }
    if (result != self->m_state) {
        self->m_obj->setFrameVisible(lbl_14_rodata_4D0);
        Node* node = self->m_node;
        while (node->m_count != 0) {
            if (node->m_count != 0) {
                node->f12(node->m_count - 1);
            }
        }
    }
    return result;
}