#pragma force_active on
typedef int s32;
typedef unsigned char u8;
extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void OSCancelAlarm(void*);
typedef void (*Callback)(void*, s32);
enum ZeroValue { ZERO_VALUE = 0 };
struct Obj {
    u8 unk0, unk1, unk2, unk3, unk4;
    u8 pad5[2];
    u8 unk7, unk8;
    u8 pad9[7];
    s32 unk10;
    u8 pad14[0x24];
    void* unk38;
    Callback unk3C;
    u8 alarm1[0x30];
    u8 alarm2[0x30];
};
extern "C" void fn_801C238C(Obj* arg0, Callback arg1) {
    s32 level;
    ZeroValue zero;
    level = OSDisableInterrupts();
    zero = ZERO_VALUE;
    arg0->unk1 = zero;
    arg0->unk2 = zero;
    OSCancelAlarm(arg0->alarm1);
    arg0->unk7 = zero;
    OSCancelAlarm(arg0->alarm2);
    Callback cb = arg0->unk3C;
    arg0->unk8 = zero;
    if (cb != 0) {
        cb(arg0->unk38, 0);
        arg0->unk4 = zero;
    }
    arg0->unk10 = 3;
    arg0->unk3C = arg1;
    arg0->unk0 = 0;
    OSRestoreInterrupts(level);
}