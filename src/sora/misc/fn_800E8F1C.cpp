#include <ms/ms_message.h>
#include <gf/gf_camera.h>
#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#include <stdio.h>
#include <string.h>
#pragma force_active on

extern "C" {
void fn_80018610(void*);
void fn_80069D08(Message*, unsigned char);
void fn_8006B0C8(Message*, void*, unsigned int);
void fn_8007270C(void*, void*, int, int, float, float, float, float);
void fn_800E975C(void*, Message*, const void*, unsigned int, const float*, int, float);
void fn_801F0530();
void fn_801F0A30();
const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
extern const char lbl_8059E2A0[3];
extern const float lbl_805A2484, lbl_805A24C4, lbl_805A24C8, lbl_805A24CC;
extern const float lbl_805A24D0, lbl_805A24D4, lbl_805A24D8, lbl_805A24DC;
extern const float lbl_805A24E0, lbl_805A24E4;
}

struct OutputEntry {
    unsigned char bytes[0x44];
};

struct OutputView {
    char prefix[0x698];
    OutputEntry entries[4][58];
};

struct IndexTable {
    int index[29];
};

extern const IndexTable lbl_8040898C;

#define PRINT_LABEL(indexValue) \
    void* data = *(void**)((char*)*(MuMsg**)(self + 0x650) + 4); \
    msg.changeMsgBuf(-1); \
    msg.clearMsgBuf(); \
    msg.setCallProjection(0); \
    msg.setWindow(pos[0], pos[1] - lbl_805A24C4, lbl_805A24C8 + pos[0], lbl_805A24C4 + pos[1]); \
    msg.setFixedWidth(lbl_805A24CC); \
    msg.setDrawFlag(0, 3); \
    fn_80069D08(&msg, 1); \
    msg.setScale(lbl_805A24D0); \
    msg.setColor(-1); \
    fn_8006B0C8(&msg, data, indexValue); \
    msg.printMsgBuf((FontData::FONT_RESOURCE)9)

extern "C" unsigned int fn_800E8F1C(unsigned char* self, int player, int draw) {
    gmResultInfo* result = g_GameGlobal->m_resultInfo;
    OutputEntry* output;
    gmPlayerResultInfo* playerInfo = &result->m_playersResultInfo[player];
    unsigned char* info = (unsigned char*)playerInfo;
    Message msg(0x80, (HeapType)0x2a);
    char buf[128];
    IndexTable table = lbl_8040898C;
    float pos[2];
    pos[1] = lbl_805A2484;
    pos[0] = lbl_805A2484;
    unsigned int count = 50;
    if (*((unsigned char*)result + 1) == 2) count = 56;
    if (*((unsigned char*)result + 2) == 1) count += 2;
    output = &((OutputView*)self)->entries[player][0];

    for (int i = 0; (unsigned int)i < count; ++output, ++i) {
        if (i % 2 == 0) {
            if (i >= 50 && *((unsigned char*)result + 2) != 1) {
                PRINT_LABEL((i - 50) / 2 + 35);
            } else if (self[0xd4]) {
                if (i == 0) {
                    PRINT_LABEL(50);
                } else if (i == 2) {
                    PRINT_LABEL(51);
                } else {
                    PRINT_LABEL(i / 2 + 9);
                }
            } else {
                PRINT_LABEL(i / 2 + 9);
            }
        } else {
            int slot = (i - 1) / 2;
            unsigned int value = 0;
            if (slot == 0) value = *(unsigned int*)(info + 0x1c4);
            else if (slot == 1) value = *(unsigned int*)(info + 0x1c8);
            else if (slot == 2) value = *(unsigned short*)(info + 0x18);
            else if (slot < 11) value = *(unsigned int*)(info + slot * 4 + 0x1c0);
            else if (slot == 11) value = info[0x1ec];
            else if (slot == 12) value = *(unsigned int*)(info + 0x1f0);
            else if (slot == 13) value = *(unsigned int*)(info + 0x1f4);
            else if (slot < 25) value = *(unsigned int*)(info + slot * 4 + 0x1c0);
            else {
                int adjusted = slot;
                if (*((unsigned char*)result + 2) == 1) {
                    if (slot == 25) value = *(unsigned int*)(info + 0x224);
                    adjusted = slot - 1;
                }
                switch (adjusted) {
                    case 25: value = *(unsigned int*)(info + 0x2c); break;
                    case 26: value = *(unsigned int*)(info + 0x228); break;
                    case 27: value = *(unsigned int*)(info + 0x30); break;
                }
            }

            void* size;
            unsigned int len;
            int id = table.index[slot];
            switch (id) {
                case -1:
                    len = sprintf(buf, lbl_8059E2A0, value);
                    break;
                case 38:
                    if (slot < 7 && self[0xd4]) {
                        len = sprintf(buf, lbl_8059E2A0, value);
                    } else {
                        int prefix = sprintf(buf, lbl_8059E2A0, value);
                        const char* data = getMsgData__5MuMsgFUlPPv(
                            *(MuMsg**)(self + 0x650), id, &size);
                        memcpy(buf + prefix, data, (unsigned int)size);
                        len = prefix + (unsigned int)size;
                    }
                    break;
                case 42: {
                    int prefix = sprintf(buf, lbl_8059E2A0, value);
                    const char* data = getMsgData__5MuMsgFUlPPv(
                        *(MuMsg**)(self + 0x650), id, &size);
                    memcpy(buf + prefix, data, (unsigned int)size);
                    len = prefix + (unsigned int)size;
                    break;
                }
                default: {
                    int prefix = sprintf(buf, lbl_8059E2A0, value);
                    const char* data = getMsgData__5MuMsgFUlPPv(
                        *(MuMsg**)(self + 0x650), id, &size);
                    memcpy(buf + prefix, data, (unsigned int)size);
                    len = prefix + (unsigned int)size;
                    break;
                }
            }
            fn_800E975C(self, &msg, buf, len, pos, 1, lbl_805A24D4);
        }

        if (draw) {
            fn_8007270C(output, 0, 0x2a, 1, pos[0], pos[1],
                        lbl_805A24C8 + pos[0], lbl_805A24D8 + pos[1]);
        }
        pos[1] += lbl_805A24D8;
        if (pos[1] >= lbl_805A24DC) {
            pos[0] += lbl_805A24C8;
            if (pos[0] >= lbl_805A24E0) {
                pos[0] = lbl_805A2484;
                gfCamera camera;
                fn_80018610(&camera);
                camera.m_projectionType = gfCamera::Projection_Orthogonal;
                *(float*)((char*)&camera + 0x114) = lbl_805A2484;
                *(float*)((char*)&camera + 0x118) = lbl_805A2484;
                *(float*)((char*)&camera + 0x11c) = lbl_805A24E0;
                *(float*)((char*)&camera + 0x120) = lbl_805A24DC;
                *(float*)((char*)&camera + 0x124) = lbl_805A2484;
                *(float*)((char*)&camera + 0x128) = lbl_805A24E4;
                *(short*)((char*)&camera + 0x12c) = 0;
                *(short*)((char*)&camera + 0x12e) = 0;
                *(short*)((char*)&camera + 0x130) = 640;
                *(short*)((char*)&camera + 0x132) = 480;
                camera.setGX();
                Message::drawBoxLine(255, 0, 0, lbl_805A2484, lbl_805A2484,
                                     lbl_805A24E0, lbl_805A24DC, lbl_805A2484);
                fn_801F0530();
                fn_801F0A30();
            }
            pos[1] = lbl_805A2484;
        }
    }
    return count;
}
