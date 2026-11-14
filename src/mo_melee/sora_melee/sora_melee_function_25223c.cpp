#pragma force_active on
#include <types.h>
#include <st/st_trigger.h>
#include <snd/snd_system.h>

extern "C" {
extern void* g_GameGlobal;
extern f32 lbl_27_rodata_40C8;
void fn_27_252508(u8*, s32);
void* fn_27_232304(const void*, int, u32);
}

inline bool checkTrigger(u8* obj) {
    if (g_stTriggerMng != NULL) {
        u8* node = (u8*)fn_27_232304(g_stTriggerMng, 0x3e8, 0);
        if (node != NULL && node[0x2c] != 0) {
            obj[0x605] = 1;
            return true;
        }
    }
    return false;
}

inline bool setTrigger(u8* obj) {
    u8 flags = obj[0x607];
    if (((flags >> 5) & 1) && ((flags >> 4) & 1)) {
        stTriggerData data;
        *(u16*)&data = 0x3e8;
        *((u8*)&data + 2) = 1;
        *((u8*)&data + 3) = 0;
        g_stTriggerMng->setTriggerFlag(&data);
        obj[0x605] = 1;
        return true;
    }
    return false;
}

extern "C" s32 fn_27_25223C(u8* arg0) {
    u8* obj = *(u8**)((u8*)g_GameGlobal + 0x30);
    switch (obj[0x604]) {
    case 0:
    case 4:
        if (obj[0x603] == 8) {
            fn_27_252508(arg0, 0);
            *(f32*)(arg0 + 0xcc) = lbl_27_rodata_40C8;
            return 1;
        }
        break;
    case 1:
        if (checkTrigger(obj)) {
            g_sndSystem->playSE((SndID)0x1a, -1, 0, 0, -1);
            fn_27_252508(arg0, 2);
            *(f32*)(arg0 + 0xcc) = lbl_27_rodata_40C8;
            return 1;
        }
        break;
    case 2:
        if (checkTrigger(obj)) {
            fn_27_252508(arg0, 0);
            *(f32*)(arg0 + 0xcc) = lbl_27_rodata_40C8;
            return 1;
        }
        break;
    case 3:
        if (setTrigger(obj)) {
            g_sndSystem->playSE((SndID)0x1a, -1, 0, 0, -1);
            fn_27_252508(arg0, 2);
            *(f32*)(arg0 + 0xcc) = lbl_27_rodata_40C8;
            return 1;
        }
        break;
    }
    return 0;
}