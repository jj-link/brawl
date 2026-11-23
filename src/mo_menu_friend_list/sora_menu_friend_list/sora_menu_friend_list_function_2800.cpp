#include <types.h>
#include <mu/mu_msg.h>
#include <string.h>
#include <internal/printf.h>

#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

extern "C" {
void fn_800B7224(void* obj, u32 unk, const char* name, void* arg);
s32 fn_80034924(s32 a, u8 b, void* c);
void fn_800B70D0(void* obj, const char* name, void* c);

extern char lbl_14_data_0[];
extern unsigned char lbl_14_rodata_21C[0x70];
extern float lbl_14_rodata_218;
}

struct FriendEntry {
    u8 iconIndex;
    u8 iconTableIndex;
    char padding[2];
    s32 status;
    u8 frame;
    char name[0x15];
    char statusText[0x52];
    s32 count;
    char padding74[4];
    u64 friendCode;
};

struct FriendList {
    char padding00[0x48];
    MuObject* objects[0x9c];
    char padding2B8[0x2b8 - 0x48 - 0x9c * 4];
    FriendEntry entries[64];
    char padding22B8[0x24cc - 0x22b8];
    MuMsg* messages;
    char padding24D0[0x2a28 - 0x24d0];
    s32 mode;
    s32 iconContext;
    u8 flag;
    char padding2A31[8];
    u8 iconTextures[128];
};

extern "C" void fn_14_2800(FriendList* self, s32 arg1, u8 arg2) {
    char* base = lbl_14_data_0;
    s32 index;
    unsigned char rawR, rawG, rawB;
    u32 entryOffset = sizeof(FriendEntry) * arg2;
    char buf38[0x20];
    char buf18[0x20];
    char buf58[0x58];
    unsigned char colA[4], outA[4], colB[4], outB[4];

    MuObject* obj;
    if (*(u8*)((char*)&self->entries[0].iconTableIndex + entryOffset) != 0xff) {
        u8 b = *(u8*)((char*)&self->entries[0].iconTableIndex + entryOffset);
        u8 v;
        if (b < 0x80) {
            v = self->iconTextures[b];
        } else {
            v = 0;
        }
        sprintf(buf38, base + 0x80, v);
        obj = *(MuObject**)((u8*)self + (arg1 + 7) * 4 + 0x48);
        nw4r::g3d::ResMat mat =
            ((MuObject*)obj)->m_resMdl.GetResMat(base + 0x60);
        fn_800B7224(obj, mat.ref().m_id, buf38, 0);
    } else {
        s32 r6 = self->iconContext;
        u8 b8 = *(u8*)((char*)&self->entries[0].iconIndex + entryOffset);
        const char (*strings)[12];
        void* obj = *(MuObject**)((u8*)self + (arg1 + 7) * 4 + 0x48);
        strings = (const char (*)[12])(base + 0x60);
        s32 r3v;
        if (r6 == 0) {
            r3v = 0;
        } else {
            r3v = fn_80034924(r6, b8, buf18);
        }

        if (r3v != 0) {
            fn_800B70D0(obj, *strings, buf18);
            goto iconReady;
        }
        const char* materialName = *strings;
        strings = (const char (*)[12])(base + 0x6c);
        nw4r::g3d::ResMat mat = ((MuObject*)obj)->m_resMdl.GetResMat(materialName);
        fn_800B7224(obj, mat.ref().m_id, *strings, 0);
    }

iconReady:
    strcpy(buf58, ((char*)&self->entries[0].name + entryOffset));
    self->messages->printf(arg1 + 3, buf58);

    index = *(s32*)((char*)&self->entries[0].status + entryOffset);
    s32 r0v;
    if (index == 0 || index == 2) {
        r0v = 0;
    } else {
        r0v = 1;
    }

    u32 msgIndex;
    u8 c5, c6, c7, c24, c23, c22;
    if (r0v != 0) {
        s32 hit = 0;
        switch (self->mode) {
        case 1:
            if (index == 0x13 || index == 0x17) {
                hit = 1;
            }
            break;
        case 2:
            if (index == 0x14) {
                hit = 1;
            }
            break;
        case 3:
            if (index == 0x15 || index == 0x18) {
                hit = 1;
            }
            break;
        case 4:
            if (index == 0x16) {
                hit = 1;
            }
            break;
        default:
            if (index >= 0x13 && index < 0x19) {
                hit = 1;
            }
            break;
        }
        if (hit != 0) {
            c5 = 0xc8;
            c6 = 0;
            c7 = 0;
        } else {
            c5 = 0x6e;
            c6 = 0x8e;
            c7 = 0xbe;
        }
        c24 = 0x6e;
        c23 = 0x8e;
        c22 = 0xbe;
    } else {
        c5 = 0x96;
        c6 = 0x96;
        c7 = 0x96;
        c24 = 0x96;
        c23 = 0x96;
        c22 = 0x96;
    }

    msgIndex = arg1 + 7;
    self->messages->setFontColor(msgIndex, c5, c6, c7, 0xff);

    unsigned int k = ((unsigned int)index << 2) - index;
    rawR = lbl_14_rodata_21C[k];
    rawG = *(&lbl_14_rodata_21C[k] + 1);
    rawB = *(&lbl_14_rodata_21C[k] + 2);

    colA[0] = rawR;
    colA[1] = rawG;
    colA[2] = rawB;
    if (self->flag == 0 &&
        (index == 6 || index == 0x12 || index == 0x16 || index == 0x1c)) {
        colA[0] = 0x11;
        colA[2] = 6;
    }
    *(unsigned short*)outA = *(unsigned short*)colA;
    outA[2] = colA[2];
    self->messages->printIndex(msgIndex, outA[0], 0);

    msgIndex = arg1 + 0xb;
    self->messages->setFontColor(msgIndex, c24, c23, c22, 0xff);

    if (index != 0) {
        strcpy(buf58, ((char*)&self->entries[0].statusText + entryOffset));
        self->messages->printf(msgIndex, buf58);
    } else {
        u64 v = *(u64*)((char*)&self->entries[0].friendCode + entryOffset);
        if (v != 0) {
            u32 m1;
            u32 m0;
            u64 q1 = v / 10000;
            m0 = (u16)(v % 10000);
            m1 = (u16)(q1 % 10000);
            self->messages->printf(
                msgIndex, base + 0x3ec, (u16)((q1 / 10000) % 10000), m1, m0);
        } else {
            self->messages->printf(msgIndex, base + 0x410);
        }
    }

    f32 f31 = lbl_14_rodata_218 -
              (f32)(int)*(u8*)((char*)&self->entries[0].frame + entryOffset);
    obj = *(MuObject**)((u8*)self + (arg1 + 0xb) * 4 + 0x48);
    obj->setFrameMatCol(f31);
    obj->setFrameVisible(f31);

    u32 idx3 = arg1 + 0xf;
    colB[0] = rawR;
    colB[1] = rawG;
    colB[2] = rawB;
    if (self->flag == 0 &&
        (index == 6 || index == 0x12 || index == 0x16 || index == 0x1c)) {
        colB[0] = 0x11;
        colB[2] = 6;
    }
    *(unsigned short*)outB = *(unsigned short*)colB;
    outB[2] = colB[2];
    if ((int)outB[1] > 0) {
        self->messages->printf(
            idx3, base + 0x3fc,
            *(s32*)((char*)&self->entries[0].count + entryOffset), outB[1]);
    } else {
        self->messages->printf(idx3, base + 0x410);
    }
}
