#include <types.h>
#include <mu/mu_msg.h>
#include <mu/menu.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
s32 fn_2_25B90(s32);
u32 fn_2_25BA8(s32);
u32 fn_2_25BC0(s32);
s32 fn_2_25BD8(u8*, s32*, s32, u32, s32);
void* getMsgData__5MuMsgFUlPPv(void*, u32, void**);
void* memcpy(void*, const void*, u32);
s32 exchangeMuCharKindToMuStockchkind__6muMenuFiii(s32);
u64 fn_800B92D8(MuMsg*, u32, u8*, s32);
}
extern "C" void fn_2_28AEC(u8* self, s32 arg1) {
    s32 i;
    s32 r30;
    u8* ent;
    s32 r24;
    u8 buf[0x80];
    s32 spC;
    u32 sz;
    ((MuMsg*)*(void**)(self + 0x674))->printIndex(*(u32*)(self + 0x66C), fn_2_25BA8(*(s32*)(self + 0x67C)), 0);
    ((MuMsg*)*(void**)(self + 0x674))->printIndex(*(u32*)(self + 0x66C) + 1, fn_2_25BC0(*(s32*)(self + 0x67C)), 0);
    switch (fn_2_25B90(*(s32*)(self + 0x67C))) {
    case 2: r30 = 0x05F5E0FF; break;
    case 6: r30 = 0x5B8D7F; break;
    default: r30 = 0x05F5E0FF; break;
    }
    ent = *(u8**)(self + 0x680) + *(s32*)(self + 0x67C) * 0x28;
    for (i = 0; i < 5; i++, ent += 8) {
        s32 tex = muMenu::exchangeGmCharacterKind2Something(exchangeMuCharKindToMuStockchkind__6muMenuFiii(*(s32*)ent));
        (*(MuObject**)(*(u8**)(self + 0x64C) + i * 4 + 0x268))->setFrameTex((f32)(tex * 10 + 1));
        r24 = fn_2_25BD8(buf, &spC, *(s32*)(self + 0x67C), *(u32*)(ent + 4), r30);
        if (spC != -1) {
            void* src = getMsgData__5MuMsgFUlPPv(*(void**)(self + 0x674), (u32)spC, (void**)&sz);
            memcpy(buf + r24, src, sz);
            r24 += sz;
        }
        fn_800B92D8(*(MuMsg**)(self + 0x674), i + *(u32*)(self + 0x66C) + 2, buf, r24);
    }
    s32 flags = 0;
    if (arg1 != 0) {
        s32 index = *(s32*)(self + 0x67C);
        if (index > 0) flags |= 2;
        if (index < 0x17) flags |= 1;
    }
    (*(MuObject**)(*(u8**)(self + 0x64C) + 0x264))->setFrameVisible((f32)flags);
}