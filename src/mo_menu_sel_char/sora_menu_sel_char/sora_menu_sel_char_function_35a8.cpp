#include <types.h>
#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#pragma force_active on

struct SelSelf {
    char pad0[0x150];
    MuObject* m_150;
    char pad1[0x3fc - 0x154];
    MuObject* m_3fc;
    char pad2[0x414 - 0x400];
    MuObject* m_414;
    char pad3[0x428 - 0x418];
    MuObject* m_428;
    char pad4[0x5c4 - 0x42c];
    MuMsg* m_5c4;
};

extern "C" {
int fn_10_C768(void* self);
void fn_800B9428(MuMsg* msg, u32 msgIndex, f32 f);
void fn_800B9488(MuMsg* msg, u32 msgIndex, u32 v);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32 a, Heaps::HeapType t, u32 b);
extern const float lbl_10_rodata_0[22];
}

extern "C" void fn_10_35A8(SelSelf& self, void* data) {
    MuMsg* msg;
    u32 var_r6;
    u8 st;
    int var_r0, var_r0_2, var_r0_3, var_r0_4, var_r0_5, var_r0_6, var_r0_7;
    int var_r0_8, var_r0_9, var_r0_10, var_r0_11, var_r0_12, var_r0_13, var_r0_14, var_r0_15, var_r0_16, var_r0_17;
    MuObject* temp_r28;
    u32 temp_r27;
    u32 var_r26;
    f32 temp_f31;
    u8 temp_r0;
    int r3_2;

    const float* ro = &lbl_10_rodata_0[18];
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, (Heaps::HeapType)0x2a, 0x2b);
    self.m_5c4 = msg;
    msg->allocMsgBuf(0x100, 8);
    msg->setMsgData(data);
    r3_2 = fn_10_C768(&self);
    switch (r3_2) {
    case 0: var_r6 = 0; break;
    case 1: var_r6 = 2; break;
    case 3: var_r6 = 1; break;
    default: var_r6 = 0; break;
    }
    msg->attachScnMdlSimple(0, (nw4r::g3d::ScnMdlSimple*)self.m_150->m_sceneModel, var_r6, ro[0]);

    st = ((u8*)g_GameGlobal->m_selCharData)[4];
    if ((s32)st >= 0 && (s32)st < 4) var_r0 = 1; else var_r0 = 0;
    if (var_r0 != 0) {
        var_r0 = 0;
    } else {
        if ((s32)st >= 4 && (s32)st < 0xC) var_r0 = 1; else var_r0 = 0;
        if (var_r0 != 0) {
            var_r0 = 1;
        } else {
            if ((s32)st >= 0xC && (s32)st < 0x10) var_r0_4 = 1; else var_r0_4 = 0;
            var_r0 = 3;
            if (var_r0_4 != 0) var_r0 = 2;
        }
    }
    if (var_r0 != 1) {
        if ((s32)st == 6 || (s32)st == 0xF) var_r0 = 1; else var_r0 = 0;
        if (var_r0 == 0) {
            if ((s32)st == 9 || (s32)st == 0xD) var_r0 = 1; else var_r0 = 0;
            if (var_r0 == 0) {
                if ((s32)st == 8 || (s32)st == 0xE) var_r0 = 1; else var_r0 = 0;
                if (var_r0 != 0) goto block_45;
            } else {
                goto block_45;
            }
        } else {
            goto block_45;
        }
    } else {
block_45:
        temp_r28 = self.m_3fc;
        var_r26 = 0;
        temp_f31 = ro[1];
        do {
            temp_r27 = var_r26 + 2;
            msg->attachScnMdlSimple(temp_r27, (nw4r::g3d::ScnMdlSimple*)temp_r28->m_sceneModel, var_r26, temp_f31);
            msg->setFontColor(temp_r27, 0x6A, 0x6A, 0x6A, 0xFF);
            msg->setAlignMode(temp_r27, MuMsg::Align_Right);
            fn_800B9428(msg, temp_r27, ro[2]);
            msg->setHSpace(temp_r27, ro[3]);
            fn_800B9488(msg, temp_r27, 0);
            var_r26 += 1;
        } while ((s32)var_r26 < 5);
        temp_r0 = ((u8*)g_GameGlobal->m_selCharData)[4];
        if ((s32)temp_r0 == 9 || (s32)temp_r0 == 0xD) var_r0_8 = 1; else var_r0_8 = 0;
        if (var_r0_8 != 0) {
            msg->attachScnMdlSimple(1, (nw4r::g3d::ScnMdlSimple*)self.m_414->m_sceneModel, 0, ro[0]);
        }
    }

    {
    int st = ((u8*)g_GameGlobal->m_selCharData)[4];
    if ((s32)st >= 0 && (s32)st < 4) var_r0_9 = 1; else var_r0_9 = 0;
    if (var_r0_9 != 0) {
        var_r0_10 = 0;
    } else {
        if ((s32)st >= 4 && (s32)st < 0xC) var_r0_11 = 1; else var_r0_11 = 0;
        if (var_r0_11 != 0) {
            var_r0_10 = 1;
        } else {
            if ((s32)st >= 0xC && (s32)st < 0x10) var_r0_12 = 1; else var_r0_12 = 0;
            var_r0_10 = 3;
            if (var_r0_12 != 0) var_r0_10 = 2;
        }
    }
    if (var_r0_10 != 0) {
        if ((s32)st >= 0 && (s32)st < 4) var_r0_13 = 1; else var_r0_13 = 0;
        if (var_r0_13 != 0) {
            var_r0_14 = 0;
        } else {
            if ((s32)st >= 4 && (s32)st < 0xC) var_r0_15 = 1; else var_r0_15 = 0;
            if (var_r0_15 != 0) {
                var_r0_14 = 1;
            } else {
                if ((s32)st >= 0xC && (s32)st < 0x10) var_r0_16 = 1; else var_r0_16 = 0;
                var_r0_14 = 3;
                if (var_r0_16 != 0) var_r0_14 = 2;
            }
        }
        if (var_r0_14 != 1) goto block_91;
    }
    var_r0_17 = 0;
    goto mode_checked;
block_91:
    var_r0_17 = 1;
mode_checked:
    if (var_r0_17 != 0) {
        msg->attachScnMdlSimple(7, (nw4r::g3d::ScnMdlSimple*)self.m_428->m_sceneModel, 0, ro[0]);
    }
    }
}
