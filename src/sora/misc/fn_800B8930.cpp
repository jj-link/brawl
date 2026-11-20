#include <mu/mu_msg.h>
#include <sr/sr_common.h>
#pragma force_active on

struct MsgFlags { unsigned char first : 1; };

extern "C" u8 fn_800B8648(void*, int, int, int);
extern unsigned char lbl_8049E01C[0x14];

extern "C" MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32 fontSetting, HeapType heapType, u32 arg2) {
    MuMsg* msg = new (heapType) MuMsg;
    if (msg != 0) {
        ((MsgFlags*)msg)->first = 0;
        *(s32*)((char*)msg + 0x4) = 0;
        Message* message = new (heapType) Message(0, heapType);
        *(Message**)((char*)msg + 0x8) = message;
        if (fontSetting != 0) {
            *(u8*)((char*)msg + 0x1) = fn_800B8648(lbl_8049E01C, fontSetting, 0xFF, 0);
        } else {
            *(u8*)((char*)msg + 0x1) = 0xFF;
        }
        *(u32*)((char*)msg + 0xC) = 0;
        *(u32*)((char*)msg + 0x10) = 0;
        *(u32*)((char*)msg + 0x14) = heapType;
        *(u32*)((char*)msg + 0x18) = arg2;
    }
    return msg;
}
