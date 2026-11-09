#pragma force_active on

#include <gf/gf_pad_system.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <string.h>

extern "C" {
extern float lbl_6_rodata_7E0;
int fn_16_998(void*, gfPadStatus*, char*, int, int);
}

class ViewerTarget {
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
    virtual void setModel(nw4r::g3d::ScnMdl*);
};

extern "C" int fn_6_B514(unsigned char* self) {
    gfPadStatus pad;
    char text[0x30];
    int result = *(int*)(self + 0x128);
    int accepted = 0;

    g_gfPadSystem->getSysPadStatus(0xf0, &pad);
    pad.m_buttonsCurrentFrame2.bits = *(unsigned int*)(self + 0x88);
    pad.m_buttonsPressedThisFrame.bits = *(unsigned int*)(self + 0x8c);
    pad.m_buttonsPressedThisFrame2.bits = *(unsigned int*)(self + 0x90);

    switch (fn_16_998(self + 0x1a4, &pad, text, 1, 1)) {
    case 0:
        accepted = 1;
        result = 4;
        break;
    case 1:
        result = 4;
        break;
    case 2:
        if (self[0x261] != 0) {
            int value = *(int*)(self + 0x228);
            float frame;
            if (value < 10) {
                frame = (float)value;
            } else {
                frame = lbl_6_rodata_7E0;
            }
            (*(MuObject**)(self + 0x48))->setFrameNode(frame);
            (*(MuMsg**)(self + 0x78))->printf(1, (const char*)(self + 0x238));
        }
        break;
    case 0x7fffffff:
        break;
    default:
        break;
    }

    if (result != *(int*)(self + 0x128)) {
        if (accepted != 0) {
            if (self[0x261] != 0) {
                strcpy((char*)(self + 0x179), (const char*)(self + 0x238));
                (*(MuMsg**)(self + 0x78))->printf(1, (const char*)(self + 0x179));
            } else {
                strcpy((char*)(self + 0x164), text);
                (*(MuMsg**)(self + 0x78))->printf(0, (const char*)(self + 0x164));
            }
        } else if (self[0x261] != 0) {
            (*(MuMsg**)(self + 0x78))->printf(1, (const char*)(self + 0x179));
        }

        if (self[0x261] != 0) {
            (*(ViewerTarget**)(self + 0x70))->setModel(
                (*(MuObject**)(self + 0x48))->m_sceneModel);
        }
    }

    return result;
}
